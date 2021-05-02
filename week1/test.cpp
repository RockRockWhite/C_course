#include <iostream>

using namespace std;

int main()
{
    string a = "alice";
    string b = "aliae";
    cout << (static_cast<string>("alice") <"blic") << endl;
    return 0;
}