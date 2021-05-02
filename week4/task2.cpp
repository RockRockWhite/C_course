#include <iostream>
#include <queue>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    queue<unsigned> code;
    for (unsigned cnt = 0; cnt != N; ++cnt)
    {
        unsigned curr_byte;
        cin >> curr_byte;

        code.push(curr_byte);
    }
    queue<unsigned> decode;
    while (!code.empty())
    {
        if (code.size() == 1)
        {
            decode.push(code.front());
            break;
        }
        decode.push(code.front());
        code.pop();
        code.push(code.front());
        code.pop();
    }

    while (!decode.empty())
    {
        cout << decode.front();
        decode.pop();
        cout << " ";
    }
    return 0;
}