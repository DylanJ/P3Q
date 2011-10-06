#include "ListTest.h"
/* check insert
 *  - insert null items
 *  - insert items out of range
 *  - check addend, addfront
 * check remove
 *  - remove null items
 *  - remove items out of range
 *  - remove head
 *  - remove tail
 * check contains
 *  - check if item that we know exists - exists
 *  - check if null exists
 * check constructor
 * check deconstructor
 * check count
 *  - add items x 3
 *  - remove items x 2
 *  - remove null item
 *  - check count
 * check making node
 *  - create null node
 *  - create node with item. */
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ListTest );

ListTest::ListTest()
{
    a = std::string( "a|hello" );
    b = std::string( "b|hai" );
    c = std::string( "c|ho" );
    d = std::string( "d|beep" );
    e = std::string( "e|blah" );

}

void ListTest::setUp()
{
    testList = new List<std::string>();
}

void ListTest::tearDown()
{
    delete testList;
}

void ListTest::testConstructor()
{
    testList = new List<std::string>();

    CPPUNIT_ASSERT_EQUAL( 0, testList->size() );
}

void ListTest::testBadInsert()
{
    int size = testList->size();

    CPPUNIT_ASSERT_EQUAL( false, testList->insertAt( b, -32 ) );
    CPPUNIT_ASSERT_EQUAL( false, testList->insertAt( b, 32 ) );

    testList->printList();

    CPPUNIT_ASSERT_EQUAL( size, testList->size() );
}

/* - insert null items
 * - insert items out of range
 * - check addend, addfront */
void ListTest::testInsert()
{
    // insert items all should return 0.
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtFront( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( c ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAt( b, 2 ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAt( e, 1 ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtFront( d ) );

    // make sure size is only 3.
    CPPUNIT_ASSERT_EQUAL( 5, testList->size() );

    // check order of items.
    CPPUNIT_ASSERT( testList->get(0).compare( d ) == 0 );
    CPPUNIT_ASSERT( testList->get(1).compare( a ) == 0 );
    CPPUNIT_ASSERT( testList->get(2).compare( e ) == 0 );
    CPPUNIT_ASSERT( testList->get(3).compare( c ) == 0 );
    CPPUNIT_ASSERT( testList->get(4).compare( b ) == 0 );
}

void ListTest::testBadRemove()
{
    int size = testList->size();

    CPPUNIT_ASSERT_EQUAL( false, testList->removeAt( -3 ) );
    CPPUNIT_ASSERT_EQUAL( false, testList->removeAt( 100 ) );
    CPPUNIT_ASSERT_EQUAL( false, testList->remove( c ) );

    // make sure size is unaffected.
    CPPUNIT_ASSERT_EQUAL( size, testList->size() );
}

/*  - remove null items
 *  - remove items out of range
 *  - remove head
 *  - remove tail */
void ListTest::testRemove()
{

    // insert items all should return 0.
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtFront( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( b ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( c ) );

    // remove head and tail
    CPPUNIT_ASSERT_EQUAL( true, testList->remove( testList->getHead() ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->remove( testList->getTail() ) );

    // make sure head and tail are the same and that it's str b
    CPPUNIT_ASSERT( testList->getTail().compare( testList->getHead() ) == 0 );
    CPPUNIT_ASSERT( testList->getTail().compare( b ) == 0 );

    // check size is 1
    CPPUNIT_ASSERT_EQUAL( 1, testList->size() );

    // remove last item
    CPPUNIT_ASSERT_EQUAL( true, testList->remove( testList->getTail() ) );

    // check size is 0
    CPPUNIT_ASSERT_EQUAL( 0, testList->size() );
}

// TODO:
// add nulls, remove nulls, add and remove, count
void ListTest::testCount()
{
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( b ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( c ) );

    CPPUNIT_ASSERT_EQUAL( true, testList->remove( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->remove( b ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->remove( c ) );

    CPPUNIT_ASSERT_EQUAL( 0, testList->size() );

    // for good measure try remove after list is empty and make sure size 
    // is still 0
    CPPUNIT_ASSERT_EQUAL( false, testList->remove( c ) );
    CPPUNIT_ASSERT_EQUAL( 0, testList->size() );
}

void ListTest::testClear()
{
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( b ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( c ) );

    CPPUNIT_ASSERT_EQUAL( true, testList->clear() );
    CPPUNIT_ASSERT_EQUAL( false, testList->clear() ); // error trying to clear

    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( b ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( c ) );

    CPPUNIT_ASSERT_EQUAL( 3, testList->size() );
}

void ListTest::testContains()
{
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( a ) );
    CPPUNIT_ASSERT_EQUAL( true, testList->insertAtEnd( c ) );

    CPPUNIT_ASSERT_EQUAL( true, testList->contains( c ) );
    CPPUNIT_ASSERT_EQUAL( false, testList->contains( d ) );
}
