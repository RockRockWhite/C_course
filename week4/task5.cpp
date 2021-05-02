#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> signs;
    char curr_input;
    while (cin >> curr_input)
    {
        if (curr_input == '.')
        {
            break;
        }
        if (curr_input == '(')
        {
            signs.push('(');
            continue;
        }
        if (curr_input == ')')
        {
            while (!signs.empty())
            {
                if (signs.top() == '(')
                {
                    signs.pop();
                    break;
                }
                cout << signs.top();
                signs.pop();

            }
            continue;
        }
        if (curr_input == '*' || curr_input == '/')
        {
            while (!signs.empty())
            {
                if (signs.top() != '*' && signs.top() != '/')
                {
                    break;
                }
                cout << signs.top();
                signs.pop();

            }
            signs.push(curr_input);
            continue;
        }
        if (curr_input == '+' || curr_input == '-')
        {

            while (!signs.empty())
            {
                if (signs.top() == '(')
                {
                    break;
                }
                cout << signs.top();
                signs.pop();
            }
            signs.push(curr_input);
            continue;
        }
        cout << curr_input;
    }
    while (!signs.empty())
    {
        cout << signs.top();
        signs.pop();
    }

    return 0;
}