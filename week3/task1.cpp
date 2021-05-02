#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    vector<char> fruits;
    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        char curr_fruit;
        cin >> curr_fruit;
        fruits.push_back(curr_fruit);
    }

    unsigned straw_string_cnt = 0;
    unsigned curr_straw_cnt = 0;
    vector<unsigned> straw_string;
    for (auto &fruit:fruits)
    {
        if (fruit == 'B')
        {
            ++curr_straw_cnt;
        } else
        {
            if (curr_straw_cnt != 0)
            {
                straw_string.push_back(curr_straw_cnt);
                ++straw_string_cnt;
            }
            curr_straw_cnt = 0;
        }

    }
    if (curr_straw_cnt != 0)
    {
        straw_string.push_back(curr_straw_cnt);
        ++straw_string_cnt;
    }

    cout << straw_string_cnt << endl;

    for (auto it = straw_string.begin(); it != straw_string.cend(); ++it)
    {
        cout << *it;
        if (it != prev(straw_string.end()))
        {
            cout << " ";
        }
    }
    cout << " ";
    return 0;
}