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
    std::cin.get();
    return 0;
}