#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Number
{
public:
    unsigned val = 0;
    unsigned cost = 0;
};

int main()
{

    unsigned total;
    cin >> total;
    vector<Number> numbers;

    for (unsigned cnt = 0; cnt != 9; ++cnt)
    {
        Number curr_number;
        cin >> curr_number.cost;
        curr_number.val = cnt + 1;
        numbers.push_back(curr_number);
    }

    sort(numbers.begin(), numbers.end(), [](Number &a, Number &b) {
        if (a.cost == b.cost)
        {
            return a.val > b.val;
        }
        else
        {
            return a.cost < b.cost;
        }
    });

    if (total < numbers.at(0).cost)
    {
        cout << -1 << endl;
        return 0;
    }

    stack<unsigned> lager;

    while (total >= numbers.at(0).cost)
    {
        lager.push(numbers.at(0).val);
        total -= numbers.at(0).cost;
    }
    unsigned lowest_cost = numbers.at(0).cost;

    sort(numbers.begin(), numbers.end(), [](Number &a, Number &b) { return a.val > b.val; });

    while (!lager.empty())
    {
        unsigned curr_byte = lager.top();
        lager.pop();
        for (auto it = numbers.begin(); it != numbers.cend(); ++it)
        {
            if (lowest_cost + total >= it->cost)
            {
                curr_byte = it->val;
                total += lowest_cost;
                total -= it->cost;
                break;
            }
        }
        cout << curr_byte;
    }
    return 0;
}