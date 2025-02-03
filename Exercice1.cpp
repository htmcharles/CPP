#include <iostream>

using namespace std;


namespace userDefined {
    int insideNamespace = 3;


    int cout() {
        return insideNamespace;
    }
}

int myGlobal = 2; 

int cout() {
    return myGlobal * myGlobal;
}

// Main function
int main() {
    int count = 5; 

    std::cout << "The local variable count in main is " << count << endl;
    std::cout << "The variable in userDefined namespace is " << userDefined::insideNamespace << endl;
    std::cout << "The output of cout() in userDefined is " << userDefined::cout() << endl;
    std::cout << "The value of myGlobal is " << myGlobal << endl;
    std::cout << "The output of global cout() is " << ::cout() << endl; 

    return 0;
}

