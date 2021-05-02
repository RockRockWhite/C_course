#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class User
{
public:
    string name;
    int id = 0;
};

bool cmp(User a, User b)
{
    return a.id < b.id;

}

int main()
{
    int N;
    cin >> N;
    vector<User> users;
    for (int cnt = 1; cnt <= N; ++cnt)
    {
        User curr_user;
        cin >> curr_user.name >> curr_user.id;
        users.push_back(curr_user);
    }
    sort(users.begin(), users.end(), cmp);
    for (auto &user:users)
    {
        cout << user.name << endl;
    }
    return 0;
}