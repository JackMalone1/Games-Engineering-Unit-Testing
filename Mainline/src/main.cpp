#include "LotteryProduction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


void createLottery(LotteryProduction lottery)
{
    bool createAnotherLottery = true;
    int numberOfLotteryNumbers = 6;
    std::set<int> numbers;
    while(createAnotherLottery)
    {
        lottery.generateLotteryFromInput(std::cin);
        if(lottery.validateLottery().first)
        {
            std::cout << "valid lottery" << std::endl;
        }
        else
        {
            std::cout << "not valid lottery" << std::endl;
        }
        std::cout << "Input another lottery? (Y)es or (N)o" << std::endl;
        std::string answer;
        std::cin >> answer;
        if(answer == "Y" || answer == "Yes"|| answer == "y")
        {
            createAnotherLottery = true;
            numberOfLotteryNumbers = 6;
            numbers.clear();
            system("CLS");
        }
        else
        {
            createAnotherLottery = false;
        }
    }
}

int main()
{
    srand(time(NULL));
    LotteryProduction lottery(6);
    auto const& lotteryNumbers = lottery.generateLottery();
    for(std::set<int>::iterator begin = lotteryNumbers.begin(); begin != lotteryNumbers.end(); ++begin)
    {
        std::cout << *begin << std::endl;
    }
    createLottery(lottery);
    std::cin.get();
    return 0;
}