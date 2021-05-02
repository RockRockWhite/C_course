#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    vector<unsigned> numbers;
    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        unsigned number;
        cin >> number;
        numbers.push_back(number);
    }
    unsigned raise_index;
    for (unsigned cnt = 1; cnt <= numbers.size(); ++cnt)
    {
        if (numbers.at(cnt - 1) < cnt)
        {
            break;
        }
        raise_index = cnt - 1;
    }

    unsigned down_index;
    for (unsigned cnt = 1; cnt <= numbers.size(); ++cnt)
    {

        if (numbers.at(numbers.size() - cnt) < cnt)
        {
            break;
        }
        down_index = numbers.size() - cnt;
    }

    if (raise_index >= down_index - 1)
    {
        cout << "Yes" << endl;
    } else
    {
        cout << "No" << endl;
    }
    return 0;
}