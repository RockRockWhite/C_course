#include <regex>
#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    //regex_search()

    string ptr = R"(^[\+\-\*\/]+[0-9]+\.?[0-9]*|\({1}[\+\-\*\/]+[0-9]+\.?[0-9]*|[0-9]+\.?[0-9]*|[\+\-\*\/]|[\(\)])";

    regex re(ptr);

    for (auto it = sregex_iterator(a.begin(), a.end(), re); it != sregex_iterator(); ++it)
    {
        string curr_token = it->str();
        if (curr_token.size() != 1 && curr_token.at(0) == '(')
        {
            cout << "(" << endl;
            curr_token.erase(curr_token.begin());
        }
        cout << curr_token << endl;
    }

    return 0;
}