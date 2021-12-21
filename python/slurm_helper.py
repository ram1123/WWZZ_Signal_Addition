"""Helper functions to get the slurm job script

This script contains several functions which helps in creating the
main slurm job sh script. As well as it has some functions that
will help us in submitted the slurm jobs.
"""
import os

"""This variable contain full slurm job sh file having five input
arguments. The input arguments are provided using %s"""
condorSHFile = """#! /bin/bash

######## Part 1 #########
# Script parameters     #
#########################

# Specify the partition name from which resources will be allocated, mandatory option
#SBATCH --partition=gpu

# Specify the QOS, mandatory option
#SBATCH --qos=normal

# Specify which group you belong to, mandatory option
# This is for the accounting, so if you belong to many group,
# write the experiment which will pay for your resource consumption
#SBATCH --account=mlgpu

# Specify your job name, optional option, but strongly recommand to specify some name
#SBATCH --job-name=%s

# Specify how many cores you will need, default is one if not specified
#SBATCH --ntasks=1

# Specify the output file path of your job
# Attention!! Your afs account must have write access to the path
# Or the job will be FAILED!
#SBATCH --output=%s/logSlurm_%%u_%%x_%%j.out

# Specify memory to use, or slurm will allocate all available memory in MB
#SBATCH --mem-per-cpu=30000

# Specify how many GPU cards to use
#SBATCH --gres=gpu:v100:1

######## Part 2 ######
# Script workload    #
######################

# Replace the following lines with your real workload
########################################
echo "Starting job on " `date`
echo "Running on: `uname -a`"
echo "System software: `cat /etc/redhat-release`"
CONFIGFILE=%s
OUTPUTPATH=%s

echo "CONFIGFILE: ${CONFIGFILE}"
echo "OUTPUTPATH: ${OUTPUTPATH}"

eval `scram runtime -sh`
Evaluate_WWggDNN ${CONFIGFILE}

echo "End job on " `date`

ROOTFILENAME=%s

RawRootFileName=$(basename "${ROOTFILENAME}" .root)

echo "======"
echo "Size of root file: ${RawRootFileName}.root"
ls -ltrh ${RawRootFileName}.root
echo " "
echo "hadd -f ${RawRootFileName}_hadd.root ${RawRootFileName}.root"
hadd -f ${RawRootFileName}_hadd.root ${RawRootFileName}.root
echo " "
echo "======"
echo "Size of root file: ${RawRootFileName}_hadd.root"
ls -ltrh ${RawRootFileName}_hadd.root
echo " "
echo "hadd -f ${RawRootFileName}_hadd2.root ${RawRootFileName}_hadd.root"
hadd -f ${RawRootFileName}_hadd2.root ${RawRootFileName}_hadd.root

echo "Size of root file: ${RawRootFileName}_hadd2.root"
ls -ltrh ${RawRootFileName}_hadd2.root

echo "======"
# Move both files raw and hadded to the output path
echo "mv ${RawRootFileName}.root ${OUTPUTPATH}/"
# mv ${RawRootFileName}.root ${OUTPUTPATH}/
echo "mv ${RawRootFileName}_hadd2.root ${OUTPUTPATH}/"
mv ${RawRootFileName}_hadd2.root ${OUTPUTPATH}/${RawRootFileName}.root
rm ${RawRootFileName}_hadd.root
# rm ${RawRootFileName}_hadd2.root
rm core.*
rm ${CONFIGFILE}

echo -e "DONE";
echo "End hadd on " `date`
echo ""
date
##########################################
# Work load end

# Do not remove below this line

# list the allocated hosts
srun -l hostname

# list the GPU cards of the host
/usr/bin/nvidia-smi -L
echo "Allocate GPU cards : ${CUDA_VISIBLE_DEVICES}"
"""



SlurmSHFile_CommonPart = """#! /bin/bash

######## Part 1 #########
# Script parameters     #
#########################

# Specify the partition name from which resources will be allocated, mandatory option
#SBATCH --partition=gpu

# Specify the QOS, mandatory option
#SBATCH --qos=normal

# Specify which group you belong to, mandatory option
# This is for the accounting, so if you belong to many group,
# write the experiment which will pay for your resource consumption
#SBATCH --account=mlgpu

# Specify your job name, optional option, but strongly recommand to specify some name
#SBATCH --job-name=%s

# Specify how many cores you will need, default is one if not specified
#SBATCH --ntasks=1

# Specify the output file path of your job
# Attention!! Your afs account must have write access to the path
# Or the job will be FAILED!
#SBATCH --output=%s/logSlurm_%%u_%%x_%%j.out

# Specify memory to use, or slurm will allocate all available memory in MB
#SBATCH --mem-per-cpu=30000

# Specify how many GPU cards to use
#SBATCH --gres=gpu:v100:1
"""


SlurmSHFile_JobDependent_DNNScoreAdd="""

######## Part 2 ######
# Script workload    #
######################

# Replace the following lines with your real workload
########################################
echo "Starting job on " `date`
echo "Running on: `uname -a`"
echo "System software: `cat /etc/redhat-release`"
CONFIGFILE=%s
OUTPUTPATH=%s

echo "CONFIGFILE: ${CONFIGFILE}"
echo "OUTPUTPATH: ${OUTPUTPATH}"

eval `scram runtime -sh`
Evaluate_WWggDNN ${CONFIGFILE}

echo "End job on " `date`

ROOTFILENAME=%s

RawRootFileName=$(basename "${ROOTFILENAME}" .root)

echo "======"
echo "Size of root file: ${RawRootFileName}.root"
ls -ltrh ${RawRootFileName}.root
echo " "
echo "hadd -f ${RawRootFileName}_hadd.root ${RawRootFileName}.root"
hadd -f ${RawRootFileName}_hadd.root ${RawRootFileName}.root
echo " "
echo "======"
echo "Size of root file: ${RawRootFileName}_hadd.root"
ls -ltrh ${RawRootFileName}_hadd.root
echo " "
echo "hadd -f ${RawRootFileName}_hadd2.root ${RawRootFileName}_hadd.root"
hadd -f ${RawRootFileName}_hadd2.root ${RawRootFileName}_hadd.root

echo "Size of root file: ${RawRootFileName}_hadd2.root"
ls -ltrh ${RawRootFileName}_hadd2.root

echo "======"
# Move both files raw and hadded to the output path
echo "mv ${RawRootFileName}.root ${OUTPUTPATH}/"
# mv ${RawRootFileName}.root ${OUTPUTPATH}/
echo "mv ${RawRootFileName}_hadd2.root ${OUTPUTPATH}/"
mv ${RawRootFileName}_hadd2.root ${OUTPUTPATH}/${RawRootFileName}.root
rm ${RawRootFileName}_hadd.root
# rm ${RawRootFileName}_hadd2.root
rm core.*
rm ${CONFIGFILE}

echo -e "DONE";
echo "End hadd on " `date`
echo ""
date
##########################################
# Work load end

# Do not remove below this line

# list the allocated hosts
srun -l hostname

# list the GPU cards of the host
/usr/bin/nvidia-smi -L
echo "Allocate GPU cards : ${CUDA_VISIBLE_DEVICES}"
"""

def SubmitJobs(CreatedFiles):
    print("Generated files:")
    for count, file in enumerate(CreatedFiles):
        print("{0:2}: {1:50}".format(count, file))
        JobSubmitCommand = "sbatch {}".format(file)
        print("\tJob submission: {}".format(JobSubmitCommand))
        os.system(JobSubmitCommand)
