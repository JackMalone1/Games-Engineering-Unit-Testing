#include "LotteryProduction.h"

LotteryProduction::LotteryProduction(int num) : amountOfRandomNumbers{num}
{

}

std::set<int> LotteryProduction::generateLottery()
{
    std::set<int> lotteryNumbers;
    while(lotteryNumbers.size() < amountOfRandomNumbers)
    {
        int randomNumber = rand() % 46 + 1;
        if(lotteryNumbers.find(randomNumber) == lotteryNumbers.end())
        {
            lotteryNumbers.insert(randomNumber);
        }
    }
    return lotteryNumbers;
}

std::pair<bool, std::set<int>> LotteryProduction::validateLotteryFromInput(std::set<int> lottery)
{
    if(lottery.size() == amountOfRandomNumbers)
    {
        std::set<int>::iterator begin = lottery.begin();
        while(begin != lottery.end())
        {
            if(*begin < 1 || *begin > 46)
            {
                return std::make_pair(false, lottery);
            }
            begin++;
        }
    }
    else
    {
        return std::make_pair(false, lottery);
    }
    return std::make_pair(true, lottery);
}