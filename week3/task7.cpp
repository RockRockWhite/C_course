#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class Number
{
public:
    Number()
    {
    }
    Number(string data)
    {
    }
    ~Number()
    {
    }
    Number operator+(Number &b);
    Number operator-(Number &b);
    Number operator*(Number &b);
    Number operator/(Number &b);
    bool operator==(Number &b);
    bool operator>(Number &b);
    bool operator<(Number &b);

private:
    string data;
};

list<int> sum(const list<int> &a, const list<int> &b)
{

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
        }
        else
        {
            result.push_back(*it_l);
        }
    }

    return result;
}

list<int> decrease(const list<int> &_a, const list<int> &_b)
{
    list<int> a, b;
    for (auto &c : _a)
    {
        stringstream sstream;
        sstream << c;
        int byte;
        sstream >> byte;
        a.push_front(byte);
    }

    for (auto &c : _b)
    {
        stringstream sstream;
        sstream << c;
        int byte;
        sstream >> byte;
        b.push_front(byte);
    }

    auto is_lager = [&a, &b]() {
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
        }
        else
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

list<int> devide(string _a, string _b)
{
    list<int> a, b;
    for (auto &c : _a)
    {
        stringstream sstream;
        sstream << c;
        int byte;
        sstream >> byte;
        a.push_back(byte);
    }

    for (auto &c : _b)
    {
        stringstream sstream;
        sstream << c;
        int byte;
        sstream >> byte;
        b.push_back(byte);
    }

    auto is_lager = [](list<int> a, list<int> b) -> int {
        /*1:a大 -1:b大 0:相等*/
        if (a.size() > b.size())
        {
            return 1;
        }
        if (a.size() < b.size())
        {
            return -1;
        }
        if (a.size() == b.size())
        {
            auto it_b = b.begin();
            for (auto it_a = a.begin(); it_a != a.cend(); ++it_a)
            {
                if (*it_a > *it_b)
                {
                    return 1;
                }
                if (*it_a < *it_b)
                {
                    return -1;
                }
                ++it_b;
            }
            return 0;
        }
    };

    list<int> result;

    if (_a == "0")
    {
        result.push_back(0);
        return result;
    }

    if (is_lager(a, b) == 0)
    {
        result.push_back(1);
        return result;
    }
    if (is_lager(a, b) == -1)
    {
        result.push_back(0);
        return result;
    }
    list<int> temp_a;
    while (!a.empty())
    {
        for (auto it_a = a.begin(); it_a != a.cend();)
        {

            if (it_a != a.cend())
            {

                auto it_a_curr = it_a;
                ++it_a;
                if (*it_a_curr == 0 && temp_a.empty())
                {
                }
                else
                {
                    temp_a.push_back(*it_a_curr);
                }
                a.erase(it_a_curr);
            }
            if (is_lager(temp_a, b) != -1)
            {
                break;
            }
            else
            {
                result.push_back(0);
            }
        }

        if (is_lager(temp_a, b) == -1)
        {
            break;
        }
        for (int i = 1; i <= 10; ++i)
        {
            temp_a = decrease(temp_a, b);

            if (is_lager(temp_a, b) == -1)
            {
                result.push_back(i);
                if (!temp_a.empty())
                {
                    if (*temp_a.begin() == 0)
                    {
                        temp_a.clear();
                    }
                }
                break;
            }
        }
    }

    list<int> _result;
    bool begin = false;
    for (auto it = result.begin(); it != result.cend(); ++it)
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
    auto result = devide(a, b);

    for (auto &num : result)
    {
        cout << num;
    }
    return 0;
}