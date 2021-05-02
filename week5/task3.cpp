#include <iostream>
#include <stack>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    getchar();
    unsigned change = 0;
    stack<char> brackets;
    for (unsigned cnt = 0; cnt != N; ++cnt)
    {
        char bracket;
        cin >> bracket;
        switch (bracket)
        {
        case '(':
            if (!brackets.empty())
            {
                if (brackets.top() == ')')
                {
                    change += 2;
                    brackets.pop();
                }
                else
                {
                    brackets.push(bracket);
                }
            }
            else
            {
                brackets.push(bracket);
            }
            break;

        case ')':
            if (!brackets.empty())
            {
                if (brackets.top() == '(')
                {
                    brackets.pop();
                }
                else
                {
                    brackets.push(bracket);
                }
            }
            else
            {
                brackets.push(bracket);
            }

            break;
        }
    }

    if (brackets.empty())
    {
        cout << change << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}