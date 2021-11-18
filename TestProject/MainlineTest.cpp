#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"
#include "../ProductionProject/LotteryProduction.h"
#include <set>
using namespace std;

int main()
{
	Production p;
	int lotteryNumberAmounts = 6;
	LotteryProduction lottery(lotteryNumberAmounts);
	int a = 10;
	cout << p.someMethod(a) << endl;
	assert(p.someMethod(a) == 0);
	std::set<int> lotteryNumbers = lottery.generateLottery();
	assert(lotteryNumbers.size() == 6);
	cin.get();
}