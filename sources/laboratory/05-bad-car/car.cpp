#include "car.h"

Car::Car(int w) {
    NumberOfWheels = w;
}

void Car::showMeThisParticularCar() {
    qDebug() << "This car has" << NumberOfWheels << "wheels.";
}
