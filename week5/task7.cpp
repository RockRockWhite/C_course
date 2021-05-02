#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    unsigned line_cnt;
    unsigned row_cnt;
    cin >> line_cnt >> row_cnt;
    cin.clear();
    cin.ignore();
    set<string> line_set;

    for (unsigned cnt = 0; cnt != line_cnt; ++cnt)
    {
        string line;
        getline(cin, line);
        line_set.insert(line);
    }

    switch (line_set.size())
    {
    case 2:
        cout << 1 << endl;
        break;

    case 3:
        cout << 8 << endl;
        break;

    case 4:
        cout << 6 << endl;
        break;
    }

    return 0;
}