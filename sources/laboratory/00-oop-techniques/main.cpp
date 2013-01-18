#include <iostream>

#include "baseclass.h"
#include "inheritingclass.h"


using namespace std;

int main() {
    BaseClass class_1;
    InheritingClass class_2;
    class_1.whoAmI();
    class_2.whoAmI();

    BaseClass *class_3 = &class_2;
    class_3->whoAmI();

    ((InheritingClass*) class_3)->whoAmI();

    return 0;
}

