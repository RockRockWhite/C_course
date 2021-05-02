#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point
{
public:
    int x = 0;
    int y = 0;
};

bool cmp(Point a, Point b)
{
    if (a.x < b.x)
    {
        return true;
    } else if (a.x == b.x)
    {
        return a.y < b.y;
    } else
    {
        return false;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<Point> points;
    for (int cnt = 1; cnt <= N; ++cnt)
    {
        Point curr_point;
        cin >> curr_point.x >> curr_point.y;
        points.push_back(curr_point);
    }
    sort(points.begin(), points.end(), cmp);
    for (auto point:points)
    {
        cout << point.x << " " << point.y << endl;
    }

    return 0;
}