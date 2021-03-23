#pragma once

#include <vector>
#include <thread>

class join_threads
{
public:
  explicit join_threads(std::vector<std::thread>& threads)
    : threads_(threads) {}

  ~join_threads()
  {
    for (size_t i = 0; i < threads_.size(); ++i)
    {
      if(threads_[i].joinable())
      {
        threads_[i].join();
      }
    }
  }

private:
  std::vector<std::thread>& threads_;
};