#include <iostream>
#include <stack>
#include <queue>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    string expr;
    getline(cin, expr);
    regex re(R"(-*[0-9]+|\+|\-|\*|\/)");

    queue<string> expr_blocks;

    for (auto it = sregex_iterator(expr.begin(), expr.end(), re); it != sregex_iterator(); ++it)
    {
        expr_blocks.push(it->str());
    }

    auto str_to_longlong = [](const string &str)
    {
        stringstream sstream;
        sstream << str;
        long long result;
        sstream >> result;
        return result;
    };

    stack<long long> result;
    while (!expr_blocks.empty())
    {
        string curr_block = expr_blocks.front();
        expr_blocks.pop();

        long long a = 0, b = 0;

        auto get_a_b = [&result, &a, &b]()
        {
            b = result.top();
            result.pop();
            a = result.top();
            result.pop();
        };
        if (curr_block == "+")
        {
            get_a_b();
            result.push(a + b);
            continue;
        }
        if (curr_block == "-")
        {
            get_a_b();
            result.push(a - b);
            continue;
        }
        if (curr_block == "*")
        {
            get_a_b();
            result.push(a * b);
            continue;
        }
        if (curr_block == "/")
        {
            get_a_b();
            result.push(a / b);
            continue;
        }
        result.push(str_to_longlong(curr_block));
    }

    cout << result.top() << endl;
    return 0;
}