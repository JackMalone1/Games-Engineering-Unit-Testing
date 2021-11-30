#include "LotteryProduction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
int main()
{
    srand(time(NULL));
    LotteryProduction lottery(6);
    auto const& lotteryNumbers = lottery.generateLottery();
    for(std::set<int>::iterator begin = lotteryNumbers.begin(); begin != lotteryNumbers.end(); ++begin)
    {
        std::cout << *begin << std::endl;
    }

    bool createAnotherLottery = true;
    int numberOfLotteryNumbers = 6;
    std::set<int> numbers;
    while(createAnotherLottery)
    {
        while(numberOfLotteryNumbers > 0)
        {
            std::cout << "Input 1 number between 1 and 46 inclusive." << std::endl;
            int lotteryNumber = 0;
            std::cin >> lotteryNumber;
            numbers.insert(lotteryNumber);
            numberOfLotteryNumbers--;
        }
        if(lottery.validateLotteryFromInput(numbers).first)
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
        if(answer == "Y" || "Yes")
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
    std::cin.get();
    return 0;
}