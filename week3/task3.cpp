#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

inline string sum(string _a, string _b)
{
    list<int> a, b;
    for (auto &c:_a)
    {
        stringstream sstream;
        sstream << c;
        int byte;
        sstream >> byte;
        a.push_front(byte);
    }

    for (auto &c:_b)
    {
        stringstream sstream;
        sstream << c;
        int byte;
        sstream >> byte;
        b.push_front(byte);
    }

    auto lager = a.size() >= b.size() ? a : b;
    auto smaller = a.size() < b.size() ? a : b;

    auto it_s = smaller.begin();

    list<int> result;
    for (auto it_l = lager.begin(); it_l != lager.cend(); ++it_l)
    {
        if (it_s != smaller.cend())
        {
            result.push_back(*it_l + *it_s);
            ++it_s;
        } else
        {
            result.push_back(*it_l);
        }
    }

    for (auto it = result.begin(); it != result.cend(); ++it)
    {
        if (it != prev(result.cend()))
        {
            if (*it >= 10)
            {
                *next(it) += *it / 10;
                *it %= 10;
            }
        } else
        {
            if (*it >= 10)
            {
                result.push_back(*it / 10);
                *it %= 10;
            }

        }
    }
    string _result;

    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        char num;
        stringstream sstream;
        sstream << *it;
        sstream >> num;
        _result.push_back(num);
    }
    return _result;
}

inline string calculate(int n)
{
    if (n == 1)
    {
        return "1";
    }
    string last_2 = "1", last_1 = "1";
    for (int i = 2; i <= n; ++i)
    {
        string curr = sum(last_1, last_2);
        last_2 = last_1;
        last_1 = curr;
    }
    return last_1;
}

int main()
{

    int N;
    cin>>N;
    cout << calculate(N) << endl;
}