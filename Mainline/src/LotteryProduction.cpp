#include "LotteryProduction.h"

LotteryProduction::LotteryProduction(int num) : amountOfRandomNumbers{num}
{

}

std::set<int> LotteryProduction::generateLottery()
{
    std::set<int> lotteryNumbers;
    while(lotteryNumbers.size() < amountOfRandomNumbers)
    {
        int randomNumber = rand() % 47 + 1;
        if(lotteryNumbers.find(randomNumber) == lotteryNumbers.end())
        {
            lotteryNumbers.insert(randomNumber);
        }
    }
    return lotteryNumbers;
}