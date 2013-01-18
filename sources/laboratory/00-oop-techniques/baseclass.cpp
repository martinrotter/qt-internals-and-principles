#include <iostream>

#include "baseclass.h"


using namespace std;

BaseClass::BaseClass() {
    cout << "BaseClass instance constructed." << endl;
}

void BaseClass::whoAmI() const {
    cout << "I am BaseClass." << endl;
}
