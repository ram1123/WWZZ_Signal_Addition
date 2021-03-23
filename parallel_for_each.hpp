#pragma once

#include <future>
#include <algorithm>

#include "join_thread.hpp"

template<typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func func)
{
  const auto length = std::distance(first, last);
  if (0 == length) return;

  const auto min_per_thread = 25u;
  const unsigned max_threads = (length + min_per_thread - 1) / min_per_thread;

  const auto hardware_threads = std::thread::hardware_concurrency();

  const auto num_threads= std::min(hardware_threads != 0 ?
        hardware_threads : 2u, max_threads);

  const auto block_size = length / num_threads;

  std::vector<std::future<void>> futures(num_threads - 1);
  std::vector<std::thread> threads(num_threads-1);
  join_threads joiner(threads);

  auto block_start = first;
  for (unsigned i = 0; i < num_threads - 1; ++i)
  {
    auto block_end = block_start;
    std::advance(block_end, block_size);
    std::packaged_task<void (void)> task([block_start, block_end, func]()
    {
      std::for_each(block_start, block_end, func);
    });
    futures[i] = task.get_future();
    threads[i] = std::thread(std::move(task));
    block_start = block_end;
  }

  std::for_each(block_start, last, func);

  for (size_t i = 0; i < num_threads - 1; ++i)
  {
    futures[i].get();
  }
}