#include <iostream>
#include <stack>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;

    stack<unsigned> stack_r;

    for (unsigned cnt = 0; cnt != N; ++cnt)
    {
        unsigned curr_r;
        cin >> curr_r;
        while (!stack_r.empty())
        {
            if (stack_r.top() >= curr_r)
            {
                break;
            }
            stack_r.pop();
        }
        stack_r.push(curr_r);
    }

    stack<unsigned> result;
    while (!stack_r.empty())
    {
        result.push(stack_r.top());
        stack_r.pop();
    }

    while (!result.empty())
    {
        cout << result.top() << endl;
        result.pop();
    }
    return 0;
}