#include <TestFixture.h>
#include <TestAssert.h>
#include <TestCase.h>
#include <TestSuite.h>
#include <TestCaller.h>
#include "../../Mainline/include/LotteryProduction.h"
#include <queue>

class LotteryProductionTest : public CppUnit::TestFixture
{
private:
    LotteryProduction* lottery;
    std::set<int> lotteryNumbers;
    const int LOTTERY_SIZE = 6;
public:
    static CppUnit::Test* suite();
    void setUp();
    void tearDown();
    void has6Numbers();
    void notHaving6NumbersInvalid();
    void allNumbersInRange();
    void allNumbersNotInRange();
    void allNumbersAreUnique();
    void allNumbersAreNotUnique();
};