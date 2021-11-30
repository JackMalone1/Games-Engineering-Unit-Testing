#include "LotteryProductionTest.h"

void LotteryProductionTest::setUp()
{
    lottery = new LotteryProduction(LOTTERY_SIZE);
}

void LotteryProductionTest::tearDown()
{
    delete lottery;
}

void LotteryProductionTest::has6Numbers()
{
    lotteryNumbers = {1, 2, 3, 5, 7, 24};
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLotteryFromInput(lotteryNumbers);
    bool lotteryIsValid = lotteryPair.first;
    lotteryNumbers = lotteryPair.second;


    CPPUNIT_ASSERT(lotteryNumbers.size() == LOTTERY_SIZE);
    CPPUNIT_ASSERT(lotteryIsValid == true);

    std::cout  << "LOTTERY HAS 6 NUMBERS TEST PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

CppUnit::Test* LotteryProductionTest::suite()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "LotteryProductionTest" );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "has6Numbers", 
    &LotteryProductionTest::has6Numbers ) );

    return suiteOfTests;
}