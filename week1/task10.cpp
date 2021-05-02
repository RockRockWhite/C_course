#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;

    string expr;
    for (int cnt = N; cnt >= 0; --cnt)
    {
        int curr;
        cin >> curr;
        string to_add;
        if (curr > 0 && cnt != N)
        {
            to_add += "+";
        }
        if (curr != 1 && curr != -1)
        {
            to_add += to_string(curr);
        }
        if (curr == 1 && cnt == 0)
        {
            to_add += "1";
        }
        if (curr == -1)
        {
            to_add += "-";
        }
        if (cnt > 1)
        {
            to_add += "x^" + to_string(cnt);
        }
        if (cnt == 1)
        {
            to_add += "x";
        }

        if (curr != 0)
        {
            expr += to_add;
        }
    }
    cout << expr << endl;
    return 0;
}