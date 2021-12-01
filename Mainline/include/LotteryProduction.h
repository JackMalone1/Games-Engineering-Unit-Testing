#pragma once
#include <set>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
class LotteryProduction
{
public:
    LotteryProduction(int num);
    std::pair<bool, std::set<int>> validateLottery();
    void setLottery(std::set<int> t_lottery)
    {
        lottery = t_lottery;
    }
private:
    int amountOfRandomNumbers;
    std::set<int> lottery;
};