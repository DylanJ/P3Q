#ifndef LISTTEST_H
#define LISTTEST_H

#include <string>
#include <cppunit/extensions/HelperMacros.h>
#include "List.h"

using namespace p3q;

class ListTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( ListTest );
    CPPUNIT_TEST( testBadInsert );
    CPPUNIT_TEST( testBadRemove );
    CPPUNIT_TEST( testClear );
    CPPUNIT_TEST( testConstructor );
    CPPUNIT_TEST( testContains );
    CPPUNIT_TEST( testCount );
    CPPUNIT_TEST( testInsert );
    CPPUNIT_TEST( testRemove );
    CPPUNIT_TEST_SUITE_END();

    public:
        ListTest();

        void setUp();
        void tearDown();

        void testBadInsert();
        void testBadRemove();
        void testClear();
        void testConstructor();
        void testContains();
        void testCount();
        void testInsert();
        void testRemove();

    private:
        List<std::string> *testList;
        std::string a, b, c, d, e;
};

#endif

