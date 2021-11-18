#pragma once

#include <set>

class LotteryProduction
{
public:
	LotteryProduction(int amountOfNumbers);
	std::set<int> generateLottery();
private:
	int amountOfRandomNumbers;
};

