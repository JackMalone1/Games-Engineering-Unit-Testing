#pragma once
#include <set>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
class LotteryProduction
{
public:
    LotteryProduction(int num);
    std::set<int> generateLottery();
    std::pair<bool, std::set<int>> validateLotteryFromInput(std::set<int> lottery);
    std::pair<bool, std::set<int>> validateLottery();
    void generateLotteryFromInput(std::istream& istream);
private:
    int amountOfRandomNumbers;
    std::set<int> lottery;
};