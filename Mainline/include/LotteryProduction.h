#pragma once
#include <set>
#include <stdio.h>
#include <stdlib.h>

class LotteryProduction
{
public:
    LotteryProduction(int num);
    std::set<int> generateLottery();
    std::pair<bool, std::set<int>> validateLotteryFromInput(std::set<int> lottery);
private:
    int amountOfRandomNumbers;
};