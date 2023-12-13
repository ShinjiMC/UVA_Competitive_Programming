#include <iostream>
#include <stack>
#include <queue>

int code()
{
    int numberOfTasks, maxStackSize, maxQueueLength;
    std::cin >> numberOfTasks;
    while (std::cin >> numberOfTasks >> maxStackSize >> maxQueueLength)
    {
        int currentTask = 0, totalTime = 0, totalTasks = 0, taskCount, taskIndex;
        std::stack<int> stackTasks;
        std::queue<int> queueTasks[numberOfTasks];
        for (auto &taskQueue : queueTasks)
        {
            std::cin >> taskCount;
            totalTasks += taskCount;
            while (taskCount--)
            {
                std::cin >> taskIndex;
                taskQueue.push(taskIndex - 1);
            }
        }
        while (true)
        {
            while (stackTasks.size() && (stackTasks.top() == currentTask || queueTasks[currentTask].size() < maxQueueLength))
            {
                if (stackTasks.top() != currentTask)
                {
                    queueTasks[currentTask].push(stackTasks.top());
                    totalTasks++;
                }
                stackTasks.pop();
                totalTime++;
                totalTasks--;
            }

            while (stackTasks.size() < maxStackSize && queueTasks[currentTask].size())
            {
                stackTasks.push(queueTasks[currentTask].front());
                queueTasks[currentTask].pop();
                totalTime++;
            }

            if (totalTasks)
            {
                currentTask++;
                currentTask %= numberOfTasks;
                totalTime += 2;
            }
            else
                break;
        }
        std::cout << totalTime << "\n";
    }
    return 0;
}
