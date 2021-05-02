#include <iostream>
#include <list>
#include <sstream>

using namespace std;

list<int> sum(list<int> _a, list<int> _b, int system)
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
            if (*it >= system)
            {
                *next(it) += *it / system;
                *it %= system;
            }
        } else
        {
            if (*it >= system)
            {
                result.push_back(*it / system);
                *it %= system;
            }

        }
    }
    list<int> _result;

    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        _result.push_back(*it);
    }
    return _result;
}

list<int> recall(list<int> n)
{
    list<int> _result;
    for (auto it = n.rbegin(); it != n.crend(); ++it)
    {
        _result.push_back(*it);
    }
    return _result;
}

bool is_equal(list<int> a, list<int> b)
{
    auto it_a = a.begin();
    auto it_b = b.begin();
    while (it_a != a.cend())
    {
        if (*it_a != *it_b)
        {
            return false;
        }
        ++it_a;
        ++it_b;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    string _M;
    cin >> _M;
    list<int> M;

    for (auto &each:_M)
    {
        if(each=='A')
        {
            M.push_back(10);
            continue;
        }
        if(each=='B')
        {
            M.push_back(11);
            continue;
        }
        if(each=='C')
        {
            M.push_back(12);
            continue;
        }
        if(each=='D')
        {
            M.push_back(13);
            continue;
        }
        if(each=='E')
        {
            M.push_back(14);
            continue;
        }
        if(each=='F')
        {
            M.push_back(15);
            continue;
        }
        stringstream sstream;
        sstream << each;
        int num;
        sstream >> num;
        M.push_back(num);
    }

    list<int> M_r;
    for (unsigned cnt = 0; cnt <= 30; ++cnt)
    {
        M_r = recall(M);
        if (is_equal(M, M_r))
        {
            cout << "STEP=" << cnt << endl;
            return 0;
        }
        M = sum(M, M_r, N);
    }
    cout << "NO" << endl;
    return 0;
}