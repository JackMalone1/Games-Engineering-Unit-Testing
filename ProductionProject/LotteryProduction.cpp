#include "LotteryProduction.h"

LotteryProduction::LotteryProduction(int amountOfNumbers)
{
	this->amountOfRandomNumbers = amountOfNumbers;
}

std::set<int> LotteryProduction::generateLottery()
{
    std::set<int> lottery;
    while (lottery.size() < amountOfRandomNumbers)
    {
        int randomNumber = (rand() % 47) + 1;
        if (lottery.count(randomNumber))
        {
            continue;
        }
        lottery.insert(randomNumber);
    }
    return lottery;
}
