#include <iostream>
#include <string>

using namespace std;

class Point
{
public:
    int x = 0;
    int y = 0;
};

int main()
{
    unsigned N;
    cin >> N;
    Point begin, end;
    cin >> begin.x >> begin.y;
    cin >> end.x >> end.y;
    Point dis;
    dis.x = end.x - begin.x;
    dis.y = end.y - begin.y;
    int time = 0;

    for (int cnt = 1; cnt <= N; ++cnt)
    {
        string command;
        cin >> command;
        if (command == "east" && dis.x > 0)
        {
            dis.x--;
            time++;
        }
        if (command == "west" && dis.x < 0)
        {
            dis.x++;
            time++;
        }
        if (command == "north" && dis.y > 0)
        {
            dis.y--;
            time++;
        }
        if (command == "south" && dis.y < 0)
        {
            dis.y++;
            time++;
        }
        if (dis.x == 0 && dis.y == 0)
        {
            cout << time;
            return 0;
        }
    }

    cout << -1;

    return 0;
}