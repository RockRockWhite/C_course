#include <iostream>
#include <list>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    list<unsigned> queue;

    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        unsigned pos;
        cin >> pos;
        if (pos == 0)
        {
            queue.push_front(cnt);
        } else
        {
            for (auto it = queue.begin(); it != queue.end(); ++it)
            {
                if (*it == pos)
                {
                    queue.insert(++it, cnt);
                    break;
                }
            }
        }
    }
    for (auto &person:queue)
    {
        cout << person;
        if (person != *(--queue.end()))
        {
            cout << " ";
        }
    }
    return 0;
}