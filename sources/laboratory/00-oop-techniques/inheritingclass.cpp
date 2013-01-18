#include <iostream>

#include "inheritingclass.h"


using namespace std;

InheritingClass::InheritingClass() : BaseClass() {
    cout << "InheritingClass instance constructed." << endl;
}

void InheritingClass::whoAmI() const {
    cout << "I am InheritingClass." << endl;
}
