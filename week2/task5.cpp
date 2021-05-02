#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    list<int> numbers;
    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        int curr_num;
        cin >> curr_num;
        numbers.push_back(curr_num);
    }

    numbers.sort();
    for (auto it = numbers.begin(); it != numbers.cend(); ++it)
    {
        if (next(it) != numbers.cend())
        {
            if (*next(it) == *it + 1)
            {
                cout << 2 << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;

    return 0;
}