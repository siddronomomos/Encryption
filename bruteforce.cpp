#include "monopoly.hpp"
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>

std::mutex mtx;

void simulateRolls(MonopolyBoard &board, int &flag, int &current)
{
    while (flag)
    {
        int roll = board.diceRoll() + board.diceRoll();
        std::lock_guard<std::mutex> lock(mtx);
        current = (current + roll) % 40;
        board.incrementLandedCount(current);
        current = (current == 30) ? 10 : current;
        if (board.getLandedCount(current) == 100000000)
        {
            flag = 0;
        }
    }
}

int main()
{
    MonopolyBoard board;
    int flag = 1;
    int current = 0;

    std::vector<std::thread> threads;
    for (int i = 0; i < std::thread::hardware_concurrency(); ++i)
    {
        threads.emplace_back(simulateRolls, std::ref(board), std::ref(flag), std::ref(current));
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::vector<std::pair<int, int>> landedCounts;
    for (int i = 0; i < board.size(); ++i)
    {
        landedCounts.emplace_back(board.getLandedCount(i), i);
    }

    std::sort(landedCounts.begin(), landedCounts.end(), std::greater<std::pair<int, int>>());

    std::ofstream outFile("results.txt");
    if (!outFile)
    {
        std::cerr << "Error opening file for writing" << std::endl;
        return 1;
    }

    for (const auto &pair : landedCounts)
    {
        int index = pair.second;
        outFile << board.getLandedCount(index) << " " << board.getProperty(index).name << " " << board.getProperty(index).id + 5 << std::endl;
    }

    outFile.close();
    return 0;
}