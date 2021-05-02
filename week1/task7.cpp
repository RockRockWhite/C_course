#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task
{
public:
    unsigned begin_time = 0;
    unsigned end_time = 0;
};


int main()
{
    int N;
    cin >> N;
    vector<Task> tasks;

    for (int cnt = 1; cnt <= N; ++cnt)
    {
        Task curr_task;
        cin >> curr_task.begin_time >> curr_task.end_time;
        tasks.push_back(curr_task);
    }

    sort(tasks.begin(), tasks.end(), [](Task a, Task b) -> bool
    { return a.end_time < b.end_time; });

    unsigned end_time = 0;
    unsigned cnt = 0;
    for (auto &task:tasks)
    {
        if (task.begin_time >= end_time)
        {
            ++cnt;
            end_time = task.end_time;
        }
    }

    cout << cnt << endl;

    return 0;
}