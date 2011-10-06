#include <iostream>
#include <string>
#include "Bot.h"

namespace p3q {

Bot::Bot( std::string name ) {
    this->name = name;
}

void Bot::printName() {
    std::cout << "My name is : " << this->name << std::endl;
}

std::string Bot::getName() {
    return this->name;
}

}
