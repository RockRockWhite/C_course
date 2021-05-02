#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

set<unsigned> calculate(list<vector<unsigned>> _dices)
{
    set<unsigned> num_set;

    if (_dices.size() == 1)
    {
        num_set.insert(_dices.begin()->begin(), _dices.begin()->end());
        return num_set;
    }
    for (auto i = _dices.begin(); i != _dices.cend(); ++i)
    {
        list<vector<unsigned>> new_dices = _dices;
        for (auto it = new_dices.begin(); it != new_dices.cend(); ++it)
        {
            if (*it == *i)
            {
                new_dices.erase(it);
                break;
            }
        }
        set<unsigned> sub_set = calculate(new_dices);
        for (auto &rear:*i)
        {
            for (auto &head:sub_set)
            {
                num_set.insert(head * 10 + rear);
            }
        }
        num_set.insert(sub_set.begin(), sub_set.end());
    }
    return num_set;
};

int main()
{
    unsigned n;
    cin >> n;
    list<vector<unsigned>> dices;
    for (unsigned cnt = 0; cnt != n; ++cnt)
    {
        vector<unsigned> dice;
        for (unsigned plain = 0; plain != 6; ++plain)
        {
            unsigned curr_plain;
            cin >> curr_plain;
            dice.push_back(curr_plain);
        }
        dices.push_back(dice);
    }

    set<unsigned> num_set = calculate(dices);
    num_set;
    num_set.erase(0);
    vector<unsigned> num_vector;
    num_vector.insert(num_vector.begin(), num_set.begin(), num_set.end());


    if (num_vector.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    for (unsigned cnt = 1; cnt <= num_vector.size(); ++cnt)
    {

        if (num_vector.at(cnt - 1) != cnt)
        {
            cout << cnt - 1 << endl;
            return 0;
        }
    }

    return 0;
}
