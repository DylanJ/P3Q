#ifndef BOTTEST_H
#define BOTTEST_H

#include "Bot.h"
#include <cppunit/extensions/HelperMacros.h>

class BotTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( BotTest );
    CPPUNIT_TEST( testConstructor );
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();
        void testConstructor();
};

#endif
