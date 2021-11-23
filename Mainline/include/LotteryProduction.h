#pragma once
#include <set>
#include <stdio.h>
#include <stdlib.h>

class LotteryProduction
{
public:
    LotteryProduction(int num);
    std::set<int> generateLottery();
private:
    int amountOfRandomNumbers;
};