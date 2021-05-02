#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> brackets;
    char bracket;
    while (cin >> bracket)
    {
        if (bracket == '.')
        {
            break;
        }

        switch (bracket)
        {
        case '(':
            brackets.push(bracket);
            break;

        case '[':
            brackets.push(bracket);
            break;

        case ')':
            if (!brackets.empty())
            {
                if (brackets.top() != '(')
                {
                    cout << "No" << endl;
                    return 0;
                }
                else
                {
                    brackets.pop();
                }
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
            break;

        case ']':
            if (!brackets.empty())
            {
                if (brackets.top() != '[')
                {
                    cout << "No" << endl;
                    return 0;
                }
                else
                {
                    brackets.pop();
                }
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
            break;
        }
    }

    if (brackets.empty())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}