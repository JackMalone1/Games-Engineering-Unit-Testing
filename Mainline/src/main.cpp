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
        int amount = numberOfLotteryNumbers;
        numbers.clear();
        while(amount > 0)
        {
            std::cout << "Input 1 number between 1 and 46 inclusive." << std::endl;
            int lotteryNumber = 0;
            std::cin >> lotteryNumber;
            if(lotteryNumber < 1 || lotteryNumber > 46)
            {
                std::cout << "Please input a number from 1 to 46" << std::endl;
            }
            else if(numbers.find(lotteryNumber) != numbers.end())
            {
                std::cout << "Number is already in the lottery, please input a new number tht is not in the lottery";
            }
            else
            {
                numbers.insert(lotteryNumber);
                amount--;
            }           
        }
        lottery.setLottery(numbers);
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
    createLottery(lottery);
    std::cin.get();
    return 0;
}