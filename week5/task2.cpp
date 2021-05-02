#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Row
{
public:
    unsigned wide = 0;
    unsigned left = 2;
    unsigned num = 0;
};

int main()
{
    unsigned N;
    cin >> N;
    vector<Row> rows;
    for (unsigned cnt = 0; cnt != N; ++cnt)
    {
        Row curr_row;
        cin >> curr_row.wide;
        curr_row.num = cnt + 1;
        rows.push_back(curr_row);
    }
    sort(rows.begin(), rows.end(), [](Row &a, Row &b) { return a.wide > b.wide; });

    for (unsigned cnt = 0; cnt != 2 * N; ++cnt)
    {
        char passager;
        cin >> passager;
        if (passager == '1')
        {
            for (auto it = rows.begin(); it != rows.cend(); ++it)
            {
                if (it->left == 1)
                {
                    --it->left;
                    cout << it->num << " ";
                    break;
                }
            }
        }
        else
        {
            for (auto it = rows.rbegin(); it != rows.crend(); it++)
            {
                if (it->left == 2)
                {
                    --it->left;
                    cout << it->num << " ";
                    break;
                }
            }
        }
    }
    return 0;
}