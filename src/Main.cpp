#include <cstdio>
#include <cstdlib>
#include <string>
#include "Bot.h"
#include "List.h"

using namespace p3q;

int main( void ) {

    List<std::string> list;
    std::string a, b, c, d, e;

    a = std::string("a");
    b = std::string("b");
    c = std::string("c");
    d = std::string("d");
    e = std::string("e");

    list.insertAtEnd( a );
    list.insertAtEnd( b );
    list.insertAtEnd( c );
    list.insertAtEnd( d );
    list.insertAtEnd( e );

    list.remove( b );
    list.remove( a );
    list.remove( e );

    list.printList();
    list.clear();

    return 0;
}

