#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TextOutputter.h>

int main( void ) {
    
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextUi::TestRunner runner;
    
    runner.addTest( suite );
    runner.setOutputter( new CppUnit::TextOutputter( &runner.result(), std::cout ) );
    
    bool wasSucessful = runner.run();
    return wasSucessful ? 0 : 1;

}
