#include "monopoly.hpp"
#include <vector>
#include <algorithm>

int main()
{
    MonopolyBoard board;
    int flag = 1;
    int current = 0;
    while (flag)
    {
        int roll = board.diceRoll() + board.diceRoll();
        current = (current + roll) % 40;
        board.incrementLandedCount(current);
        if (current == 30)
        {
            current = 10;
            board.incrementLandedCount(current);
        }
        if (board.getLandedCount(current) == 10000000)
        {
            flag = 0;
        }
    }

    std::vector<std::pair<int, int>> landedCounts;
    for (int i = 0; i < board.size(); ++i)
    {
        landedCounts.emplace_back(board.getLandedCount(i), i);
    }

    std::sort(landedCounts.begin(), landedCounts.end(), std::greater<>());

    for (const auto &pair : landedCounts)
    {
        int index = pair.second;
        std::cout << board.getLandedCount(index) << " " << board.getProperty(index).name << " " << board.getProperty(index).id + 5 << std::endl;
    }
}