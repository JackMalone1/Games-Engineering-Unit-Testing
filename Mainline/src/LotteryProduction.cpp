#include "../include/LotteryProduction.h"

LotteryProduction::LotteryProduction(int num) : amountOfRandomNumbers{num}
{

}

std::pair<bool, std::set<int>> LotteryProduction::validateLottery()
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