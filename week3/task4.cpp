#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

list<int> decrease(string &_a, string &_b)
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

    auto is_lager = [&a, &b]()
    {
        if (a.size() > b.size())
        {
            return true;
        }
        if (a.size() == b.size())
        {
            auto it_b = b.rbegin();
            for (auto it_a = a.rbegin(); it_a != a.crend(); ++it_a)
            {

                if (*it_a > *it_b)
                {
                    return true;
                }
                if (*it_a < *it_b)
                {
                    return false;
                }
                ++it_b;
            }
        }
        if (a.size() < b.size())
        {
            return false;
        }
        return true;

    };

    auto lager = is_lager() ? a : b;
    auto smaller = !is_lager() ? a : b;

    list<int> result;

    auto it_s = smaller.begin();

    for (auto it_l = lager.begin(); it_l != lager.cend(); ++it_l)
    {
        if (it_s != smaller.cend())
        {
            result.push_back(*it_l - *it_s);
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
            if (*it < 0)
            {
                *next(it) -= 1;
                *it = 10 + *it;
            }
        }
    }

    bool is_zero = true;
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        if (*it != 0)
        {
            is_zero = false;
            break;
        }
    }

    list<int> _result;

    if (is_zero)
    {
        _result.push_back(0);
        return _result;
    }

    if (!is_lager())
    {
        _result.push_back(-1);
    }
    bool begin = false;
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        if (*it != 0)
        {
            begin = true;
        }
        if (begin)
        {
            _result.push_back(*it);
        }
    }

    return _result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    auto result = decrease(a, b);
    for (auto &num:result)
    {
        if (num == -1)
        {
            cout << "-";
        } else
        {
            cout << num;
        }
    }

    return 0;
}