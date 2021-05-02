#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    vector<list<unsigned>> groups;

    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        unsigned total;
        cin >> total;
        list<unsigned> curr_group;
        for (unsigned num = 1; num <= total; ++num)
        {
            curr_group.push_back(num);
        }
        groups.push_back(curr_group);
    }

    for (auto &group:groups)
    {
        unsigned soldier_cnt;
        while (group.size() > 3)
        {
            soldier_cnt = 0;
            for (auto it = group.begin(); it != group.cend();)
            {
                auto curr_it = it;
                ++it;

                ++soldier_cnt;
                if (soldier_cnt == 2)
                {
                    soldier_cnt = 0;
                    group.erase(curr_it);
                }
            }

            if (group.size() <= 3)
            {
                break;
            }

            soldier_cnt = 0;
            for (auto it = group.begin(); it != group.cend();)
            {
                auto curr_it = it;
                ++it;

                ++soldier_cnt;
                if (soldier_cnt == 3)
                {
                    soldier_cnt = 0;
                    group.erase(curr_it);
                }
            }
        }
    }

    for (auto &group:groups)
    {
        for (auto &num:group)
        {
            cout << num;
            if (num != *(--group.end()))
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
