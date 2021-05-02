#include <iostream>
#include <array>
#include <regex>

using namespace std;

int main()
{
    array<array<char, 4>, 4> matrix;
    for (unsigned i = 0; i != 4; ++i)
    {
        for (unsigned j = 0; j != 4; ++j)
        {
            cin >> matrix.at(i).at(j);
        }
    }

    auto is_win = [&matrix](unsigned _i, unsigned _j) {
        string line;
        regex re(R"(.*xxx.*)");

        line = "";
        for (unsigned j = 0; j != 4; ++j)
        {
            line += matrix.at(_i).at(j);
        }
        if (regex_match(line, re))
        {
            return true;
        }

        line = "";
        for (unsigned i = 0; i != 4; ++i)
        {
            line += matrix.at(i).at(_j);
        }
        if (regex_match(line, re))
        {
            return true;
        }

        unsigned begin_i = _i;
        unsigned begin_j = _j;
        line = "";

        while (true)
        {
            if (begin_i == 0 || begin_j == 0)
            {
                break;
            }
            --begin_i;
            --begin_j;
        }

        for (unsigned i = begin_i, j = begin_j; i < 4 && j < 4; ++i, ++j)
        {
            line += matrix.at(i).at(j);
        }
        if (regex_match(line, re))
        {
            return true;
        }

        begin_i = _i;
        begin_j = _j;
        line = "";

        while (true)
        {
            if (begin_i == 0 || begin_j == 3)
            {
                break;
            }
            --begin_i;
            ++begin_j;
        }

        for (int i = begin_i, j = begin_j; i < 4 && j >= 0; ++i, --j)
        {
            line += matrix.at(i).at(j);
        }
        if (regex_match(line, re))
        {
            return true;
        }

        return false;
    };

    for (unsigned i = 0; i != 4; ++i)
    {
        for (unsigned j = 0; j != 4; ++j)
        {
            if (matrix.at(i).at(j) == '.')
            {
                matrix.at(i).at(j) = 'x';
                if (is_win(i, j))
                {
                    cout << "YES" << endl;
                    return 0;
                }
                matrix.at(i).at(j) = '.';
            }
            else
            {
                continue;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}