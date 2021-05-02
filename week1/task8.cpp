#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_simple(unsigned a, unsigned b)
{
    unsigned lower = (a < b) ? a : b;
    for (unsigned cnt = 2; cnt <= lower; ++cnt)
    {
        if ((a % cnt == 0) && (b % cnt == 0))
        {
            return false;
        }
    }
    return true;
}

class Number
{
public:
    unsigned a = 0;
    unsigned b = 0;
    double value = 0;
};

bool cmp(Number a, Number b)
{
    return a.value < b.value;
}

int main()
{
    unsigned N;
    cin >> N;
    vector<Number> numbers;


    auto add = [&numbers](unsigned a, unsigned b)
    {
        Number curr_num;
        curr_num.a = a;
        curr_num.b = b;
        curr_num.value = static_cast<double>(a) / static_cast<double>(b);
        numbers.push_back(curr_num);

    };
    add(0, 1);
    add(1, 1);
    for (unsigned cnt_b = 1; cnt_b <= N; ++cnt_b)
    {
        for (unsigned cnt_a = 1; cnt_a < cnt_b; ++cnt_a)
        {
            if (is_simple(cnt_a, cnt_b))
            {
                add(cnt_a, cnt_b);
            }
        }
    }

    sort(numbers.begin(), numbers.end(), cmp);


    for (auto &number:numbers)
    {
        cout << number.a << "/" << number.b << endl;
    }

    return 0;
}