#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    unsigned N;
    cin >> N;
    vector<unsigned> piles;
    for (unsigned cnt = 0; cnt != N; ++cnt)
    {
        unsigned curr_pile;
        cin >> curr_pile;
        piles.push_back(curr_pile);
    }

    unsigned averange = accumulate(piles.begin(), piles.end(), 0) / N;
    unsigned move = 0;

    for (auto it = piles.begin(); it != prev(piles.cend()); ++it)
    {
        if (*it == averange)
        {
            continue;
        }
        *next(it) += *it - averange;
        ++move;
    }
    cout << move << endl;

    return 0;
}