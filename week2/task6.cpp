#include <iostream>
#include <array>

using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;

    unsigned operator-(Date &b)
    {
        auto is_leap = [](int _year)
        {
            if (_year % 100 != 0)
            {
                return _year % 4 == 0;
            } else
            {
                return _year % 400 == 0;
            }
        };

        unsigned day_cnt = 0;
        if (this->year == b.year)
        {
            if (is_leap(this->year))
            {
                months_data.at(1) = 29;
            } else
            {
                months_data.at(1) = 28;
            }
            for (int m = b.month; m <= this->month - 1; ++m)
            {
                day_cnt += months_data.at(m - 1);
            }
            day_cnt += this->day - b.day;
            return day_cnt;
        }
        if (is_leap(b.year))
        {
            months_data.at(1) = 29;
        } else
        {
            months_data.at(1) = 28;
        }
        day_cnt += months_data.at(b.month - 1) - b.day;
        for (int m = b.month + 1; m <= 12; ++m)
        {
            day_cnt += months_data.at(m - 1);
        }

        for (int y = b.year + 1; y < this->year; ++y)
        {
            day_cnt += 365;
            if (is_leap(y))
            {
                ++day_cnt;
            }
        }

        if (is_leap(this->year))
        {
            months_data.at(1) = 29;
        } else
        {
            months_data.at(1) = 28;
        }

        for (int m = 1; m < this->month; ++m)
        {
            day_cnt += months_data.at(m - 1);
        }
        day_cnt += this->day;
        return day_cnt;
    }

    bool operator==(Date &b)
    {
        if (year == b.year && month == b.month && day == b.day)
        {
            return true;
        } else
        {
            return false;
        }
    }

private:
    array<unsigned, 12> months_data = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


};

int main()
{
    Date a, b;
    while (cin >> a.year >> a.month >> a.day >> b.year >> b.month >> b.day)
    {
        Date begin, end;
        if (a == b)
        {
            cout << 0 << endl;
            return 0;
        }
        if (a.year == b.year)
        {
            if (a.month == b.month)
            {
                end = a.day > b.day ? a : b;
                begin = a.day < b.day ? a : b;
            } else
            {
                end = a.month > b.month ? a : b;
                begin = a.month < b.month ? a : b;
            }
        } else
        {
            end = a.year > b.year ? a : b;
            begin = a.year < b.year ? a : b;
        }

        if (end == b)
        {
            cout << "-";
        }
        if (begin.year < 0)
        {
            Date zero;
            zero.year = 0;
            zero.month = 1;
            zero.day = 1;
            begin.year = -begin.year;
            cout << (begin - zero) + (end - zero) << endl;
            return 0;

        }
        cout << end - begin << endl;
    }

}