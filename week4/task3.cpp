#include <iostream>
#include <queue>

using namespace std;

class Child
{
public:
    unsigned candy_cnt = 0;
    unsigned candy_need = 0;
    unsigned num = 0;
};

int main()
{
    unsigned n, m;
    cin >> n >> m;

    queue<Child> childs;
    for (unsigned cnt = 1; cnt <= n; ++cnt)
    {
        Child curr_child;
        curr_child.num = cnt;
        unsigned curr_candy_need;
        cin >> curr_candy_need;
        curr_child.candy_need = curr_candy_need;

        childs.push(curr_child);
    }

    while (!childs.empty())
    {
        if (childs.size() == 1)
        {
            cout << childs.front().num << endl;
            break;
        }
        childs.front().candy_cnt += m;
        if (childs.front().candy_need <= childs.front().candy_cnt)
        {
            childs.pop();
        } else
        {
            childs.push(childs.front());
            childs.pop();
        }
    }
    return 0;
}