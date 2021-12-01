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
    lottery->setLottery(lotteryNumbers);
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLottery();
    bool lotteryIsValid = lotteryPair.first;
    lotteryNumbers = lotteryPair.second;


    CPPUNIT_ASSERT(lotteryNumbers.size() == LOTTERY_SIZE);
    CPPUNIT_ASSERT(lotteryIsValid == true);

    std::cout  << "LOTTERY HAS 6 NUMBERS TEST PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryProductionTest::notHaving6NumbersInvalid()
{
    lotteryNumbers = {1, 2, 3, 5, 7};
    lottery->setLottery(lotteryNumbers);
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLottery();
    bool lotteryIsValid = lotteryPair.first;
    lotteryNumbers = lotteryPair.second;


    CPPUNIT_ASSERT(lotteryNumbers.size() != LOTTERY_SIZE);
    CPPUNIT_ASSERT(lotteryIsValid == false);

    std::cout  << "INVALID LOTTERY TEST PASSED  " << std::endl; 
    std::cout << std::endl << std::endl;
}


void LotteryProductionTest::allNumbersInRange()
{
    lotteryNumbers = {1, 2, 3, 5, 7, 24};
    lottery->setLottery(lotteryNumbers);
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLottery();
    lotteryNumbers = lotteryPair.second;
    bool valid = lotteryPair.first;

    for(auto& i : lotteryNumbers)
    {
        CPPUNIT_ASSERT(i >= 1 && i <= 46);
    }
    CPPUNIT_ASSERT(valid == true);
    std::cout <<  "LOTTERY NUMBERS IN RANGE TEST PASSED" << std::endl << std::endl<< std::endl;

}

void LotteryProductionTest::allNumbersNotInRange()
{
    lotteryNumbers = {111, 222, 333, 555, 777, 244};
    lottery->setLottery(lotteryNumbers);
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLottery();
    lotteryNumbers = lotteryPair.second;
    bool valid = lotteryPair.first;

    for(auto& i : lotteryNumbers)
    {
        CPPUNIT_ASSERT(!(i >= 1 && i <= 46));
    }
    CPPUNIT_ASSERT(valid == false);
    std::cout <<  "LOTTERY NUMBERS NOT IN RANGE TEST PASSED" << std::endl << std::endl<< std::endl;
}

void LotteryProductionTest::allNumbersAreUnique()
{
    lotteryNumbers = {1, 2, 3, 5, 7, 24};
    lottery->setLottery(lotteryNumbers);
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLottery();
    lotteryNumbers = lotteryPair.second;
    bool valid = lotteryPair.first;
    CPPUNIT_ASSERT(valid == true);
    for(std::set<int>::iterator it = lotteryNumbers.begin(); it != lotteryNumbers.end(); it++)
    {
        for(std::set<int>::iterator itt = lotteryNumbers.begin(); itt != lotteryNumbers.end(); itt++)
        {
            if(it != itt)
            {
                CPPUNIT_ASSERT(*it != *itt);
            }
        }
    }
    std::cout <<  "LOTTERY NUMBERS ARE UNIQUE TEST PASSED" << std::endl << std::endl<< std::endl;
}

void LotteryProductionTest::allNumbersAreNotUnique()
{
    lotteryNumbers = {1, 2, 3, 5, 7, 7};
    lottery->setLottery(lotteryNumbers);
    std::pair<bool, std::set<int>> lotteryPair = lottery->validateLottery();
    lotteryNumbers = lotteryPair.second;
    bool valid = lotteryPair.first;
    CPPUNIT_ASSERT(valid == false);
    CPPUNIT_ASSERT(lotteryNumbers.size() != LOTTERY_SIZE);
    std::cout <<  "LOTTERY NUMBERS ARE UNIQUE TEST PASSED" << std::endl << std::endl<< std::endl;
}

CppUnit::Test* LotteryProductionTest::suite()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "LotteryProductionTest" );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "has6Numbers", 
    &LotteryProductionTest::has6Numbers ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "notHaving6NumbersInvalid", 
    &LotteryProductionTest::notHaving6NumbersInvalid ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "allNumbersInRange", 
    &LotteryProductionTest::allNumbersInRange ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "allNumbersNotInRange", 
    &LotteryProductionTest::allNumbersNotInRange ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "has6Numbers", 
    &LotteryProductionTest::allNumbersAreUnique ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryProductionTest>( 
    "allNumbersAreNotUnique", 
    &LotteryProductionTest::allNumbersAreNotUnique ) );
    return suiteOfTests;
}