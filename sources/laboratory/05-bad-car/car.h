#ifndef CAR_H
#define CAR_H

#include <QtCore/QDebug>


class Car {
    private:
	unsigned int NumberOfWheels;
    public:
	Car(int w);
	void showMeThisParticularCar();
    private:
	bool owner;
};
#endif // CAR_H
