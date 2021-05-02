#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <array>

using namespace std;

class Player
{
public:
    array<unsigned, 5> cards{};
    string name;
    unsigned grade_a = 0;
    unsigned grade_b = 0;
    unsigned grade_c = 0;
    /* 皇家同花顺 8
     * 顺子 7
     * 四条 6
     * 满堂红 6
     * 三条 3
     * 双对 3
     * 对子 2
     * 高牌 1
     * */
    unsigned level = 0;
};

int main()
{
    // 关闭流传递
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 获得N
    unsigned N;
    cin >> N;

    // 保存玩家手牌的vector
    vector<Player> players;
    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        Player curr_player;
        cin >> curr_player.name;
        for (unsigned cards_cnt = 1; cards_cnt <= 5;)
        {
            // 获得手牌
            char curr_card;
            cin >> curr_card;
            // 处理成点数
            if (curr_card == 'A')
            {
                curr_player.cards.at(cards_cnt - 1) = 1;
                ++cards_cnt;
                continue;
            }
            if (curr_card == 'J')
            {
                curr_player.cards.at(cards_cnt - 1) = 11;
                ++cards_cnt;
                continue;
            }
            if (curr_card == 'Q')
            {
                curr_player.cards.at(cards_cnt - 1) = 12;
                ++cards_cnt;
                continue;
            }
            if (curr_card == 'K')
            {
                curr_player.cards.at(cards_cnt - 1) = 13;
                ++cards_cnt;
                continue;
            }
            if (curr_card == '1')
            {
                continue;
            }
            if (curr_card == '0')
            {
                curr_player.cards.at(cards_cnt - 1) = 10;
                ++cards_cnt;
                continue;
            }
            stringstream sstream;
            sstream << curr_card;
            sstream >> curr_player.cards.at(cards_cnt - 1);
            ++cards_cnt;
        }
        // 将手牌按照点数升序
        sort(curr_player.cards.begin(), curr_player.cards.end());
        // 存入vector
        players.push_back(curr_player);
    }

    // 给各玩家分级
    for (auto &player:players)
    {
        // ************
        // 皇家同花顺 8
        // ************
        auto is_card = [&player](unsigned cnt, unsigned num)
        {
            return player.cards.at(cnt) == num;
        };
        if (is_card(0, 1)
            && is_card(1, 10)
            && is_card(2, 11)
            && is_card(3, 12)
            && is_card(4, 13))
        {
            player.level = 8;
            continue;
        }
        // ************
        // 顺子 7
        // ************
        bool satisfied = true;
        for (unsigned cnt = 1; cnt <= 4; ++cnt)
        {
            // 只有都等于下一个+1才是顺子
            if (player.cards.at(cnt) != player.cards.at(cnt - 1) + 1)
            {
                satisfied = false;
                break;
            }
        }
        if (satisfied)
        {
            // 设置等级
            player.level = 7;
            player.grade_a = player.cards.at(4);
            continue;
        }
        // ************
        // 四条 6
        // ************
        auto equal = [&player](unsigned a, unsigned b)
        {
            return player.cards.at(a) == player.cards.at(b);
        };
        if (equal(0, 1) && equal(1, 2) && equal(2, 3))
        {
            // 设置主 副排序值
            player.grade_a = player.cards.at(0);
            player.grade_b = player.cards.at(4);
            // 分级
            player.level = 6;
            continue;
        }
        if (equal(1, 2) && equal(2, 3) && equal(3, 4))
        {
            // 设置主 副排序值
            player.grade_a = player.cards.at(1);
            player.grade_b = player.cards.at(0);
            // 分级
            player.level = 6;
            continue;
        }
        // ************
        // 满堂红 5
        // ************
        if (equal(0, 1) && equal(1, 2) && equal(3, 4))
        {
            // 设置主 副排序值
            player.grade_a = player.cards.at(0);
            player.grade_b = player.cards.at(3);
            // 分级
            player.level = 5;
            continue;
        }
        if (equal(0, 1) && equal(2, 3) && equal(3, 4))
        {
            // 设置主 副排序值
            player.grade_a = player.cards.at(2);
            player.grade_b = player.cards.at(0);
            // 分级
            player.level = 5;
            continue;
        }
        // ************
        // 三条 4
        // ************
        if (equal(0, 1) && equal(1, 2))
        {
            player.grade_a = player.cards.at(0);
            player.grade_b = player.cards.at(3) + player.cards.at(4);
            // 分级
            player.level = 4;
            continue;
        }
        if (equal(1, 2) && equal(2, 3))
        {
            player.grade_a = player.cards.at(1);
            player.grade_b = player.cards.at(0) + player.cards.at(4);
            // 分级
            player.level = 4;
            continue;
        }
        if (equal(2, 3) && equal(3, 4))
        {
            player.grade_a = player.cards.at(2);
            player.grade_b = player.cards.at(0) + player.cards.at(1);
            // 分级
            player.level = 4;
            continue;
        }
        // *******************************
        // 统计对子个数
        // *******************************

        unsigned pairs = 0;
        vector<unsigned> grade_ab;

        for (unsigned cnt = 1; cnt <= 4; ++cnt)
        {
            if (equal(cnt, cnt - 1))
            {
                grade_ab.push_back(player.cards.at(cnt - 1));
                ++pairs;
            }
        }
        // ************
        // 两对 3
        // ************
        //坑爹的两对啊
        if (pairs == 2)
        {
            player.grade_a = grade_ab.at(0) > grade_ab.at(1) ? grade_ab.at(0) : grade_ab.at(1);
            player.grade_b = grade_ab.at(0) < grade_ab.at(1) ? grade_ab.at(0) : grade_ab.at(1);
            player.grade_c = accumulate(player.cards.begin(), player.cards.end(), static_cast<unsigned>(0)) -
                             2 * (player.grade_a + player.grade_b);
            // 分级
            player.level = 3;
            continue;
        }
        // ************
        // 对子 2
        // ************
        if (pairs == 1)
        {
            player.grade_a += grade_ab.at(0);
            player.grade_b =
                    accumulate(player.cards.begin(), player.cards.end(), static_cast<unsigned>(0)) - 2 * player.grade_a;
            // 分级
            player.level = 2;
            continue;
        }
        // ************
        // 高牌 1
        // ************
        player.grade_a = accumulate(player.cards.begin(), player.cards.end(), static_cast<unsigned>(0));
        player.level = 1;
    }
    // 按照规则排序
    sort(players.begin(), players.end(), [](const Player &a, const Player &b) -> bool
    {
        // 先比较等级
        if (a.level != b.level)
        {
            return a.level > b.level;
        }
            // 再比主成绩
        else if (a.grade_a != b.grade_a)
        {
            return a.grade_a > b.grade_a;
        }
            // 再比副成绩
        else if (a.grade_b != b.grade_b)
        {
            return a.grade_b > b.grade_b;
        }
            // 再比第三成绩
        else if (a.grade_c != b.grade_c)
        {
            return a.grade_c > b.grade_c;
        }
            // 最后按字典顺序比
        else
        {
            return a.name < b.name;
        }
    });
    // 输出结果
    for (auto &player:players)
    {
        cout << player.name << endl;
    }

    return 0;
}