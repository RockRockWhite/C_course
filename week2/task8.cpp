#include <iostream>

using namespace std;

int main()
{
    unsigned k;
    cin >> k;
    string str_a, str_b;
    cin >> str_a >> str_b;
    unsigned length = 0;

    for (unsigned i = 0; i != str_a.size(); ++i)
    {

        for (unsigned j = 0; j != str_b.size(); ++j)
        {
            unsigned k_left = k;
            unsigned curr_len = 0;
            unsigned curr_i = i, curr_j = j;

            while (curr_i != str_a.size() && curr_j != str_b.size())
            {
                if (str_a.at(curr_i) != str_b.at(curr_j))
                {
                    if (k_left != 0)
                    {
                        --k_left;
                    } else
                    {
                        break;
                    }
                }
                ++curr_len;
                ++curr_i;
                ++curr_j;
            }
            length = curr_len > length ? curr_len : length;
        }
    }
    cout << length << endl;
    return 0;
}