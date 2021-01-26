#include "ConcurrencyManager.hpp"
#include <cassert>
#include <iostream>

ConcurrencyManager::ConcurrencyManager(size_t thread_count)
{
    m_working = true;
    m_freeThreads = 0;
    m_threads.resize(thread_count);
    for (size_t i = 0; i < thread_count; ++i)
        m_threads[i] = std::thread(ThreadWorker, std::reference_wrapper(*this));
}

ConcurrencyManager::~ConcurrencyManager()
{
    m_working = false;
    m_notifyer.notify_all();
    for (size_t i = 0; i < m_threads.size(); ++i)
        m_threads[i].join();
}

void ConcurrencyManager::addTaskToQueue(std::function<void(void)> task)
{
    std::lock_guard<std::mutex> lk(m_common);
    m_queue.push(task);
    m_notifyer.notify_one();
}


std::function<void(void)> ConcurrencyManager::peakTask()
{
    std::lock_guard<std::mutex> lk(m_common);
    if (m_queue.size())
    {
        auto task = m_queue.front();
        m_queue.pop();
        return task;
    }
    else
    {
        return [](){};
    }
}

void ConcurrencyManager::wait()
{
    while (m_freeThreads != m_threads.size()) std::this_thread::sleep_for(std::chrono::microseconds(100));
}

size_t ConcurrencyManager::tasksLeft() const 
{
    std::lock_guard<std::mutex> lk(m_common); 
    return m_queue.size(); 
}

void ThreadWorker(ConcurrencyManager& cm)
{
    std::mutex mtx;
    std::unique_lock<std::mutex> ulock(mtx);
    while (cm.m_working)
    {
        if (cm.tasksLeft() == 0) 
        {
            cm.m_freeThreads++;
            cm.m_notifyer.wait(ulock);
            cm.m_freeThreads--;
        }
        auto task = cm.peakTask();
        task();
    }
}