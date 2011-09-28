#include <string>

class Bot {
    public:
        Bot( std::string name );
        void printName();
        std::string getName();

    private:
        std::string name;
};
