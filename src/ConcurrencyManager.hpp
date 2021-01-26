#pragma once

#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>

class ConcurrencyManager
{
    private:
        std::vector<std::thread> m_threads;
        std::queue<std::function<void(void)>> m_queue;
        std::condition_variable m_notifyer;
        mutable std::mutex m_common;
        mutable std::atomic_size_t m_freeThreads;
        std::atomic_bool m_working;

    public:
        ConcurrencyManager(size_t thread_count = std::thread::hardware_concurrency() - 1);
        ~ConcurrencyManager();

        void addTaskToQueue(std::function<void(void)> task);
        void wait();

    private:
        size_t tasksLeft() const;
        std::function<void(void)> peakTask();


        friend void ThreadWorker(ConcurrencyManager& cm);
};
