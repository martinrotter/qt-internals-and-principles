#ifndef INHERITINGCLASS_H
#define INHERITINGCLASS_H

#include "baseclass.h"


/*
 * Class declaration
 * This class inherits BaseClass
 */
class InheritingClass : public BaseClass {
    public:
	InheritingClass();

	void whoAmI() const;
};

#endif // INHERITINGCLASS_H
