#include <iostream>
#include <array>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;
    array<unsigned, 100000> nums{};

    for (unsigned cnt = 0; cnt != n; ++cnt)
    {
        int curr_num;
        cin >> nums.at(cnt);
    }

    for (unsigned begin = 0; begin != n; ++begin)
    {
        unsigned curr_num = nums.at(begin);
        bool found = false;
        for (unsigned index = begin; index != n; ++index)
        {
            if (curr_num < nums.at(index))
            {
                cout << index + 1 << " ";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "0 ";
        }
    }

    return 0;
}