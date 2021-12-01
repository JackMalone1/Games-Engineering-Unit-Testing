#include "../include/LotteryProduction.h"

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

void LotteryProduction::generateLotteryFromInput(std::istream& istream)
{
    int amount = amountOfRandomNumbers;
    lottery.clear();
    while(amount > 0)
    {
        std::cout << "Input 1 number between 1 and 46 inclusive." << std::endl;
        int lotteryNumber = 0;
        std::cin >> lotteryNumber;
        if(lotteryNumber < 1 || lotteryNumber > 46)
        {
            std::cout << "Please input a number from 1 to 46" << std::endl;
        }
        else if(lottery.find(lotteryNumber) != lottery.end())
        {
            std::cout << "Number is already in the lottery, please input a new number tht is not in the lottery";
        }
        else
        {
            lottery.insert(lotteryNumber);
            amount--;
        }           
    }
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