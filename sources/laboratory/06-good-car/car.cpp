#include <QDebug>

#include "car.h"


Car::Car(int number_of_wheels, bool has_owner) {
    m_numberOfWheels = number_of_wheels;
    m_hasOwner = has_owner;
}

void Car::showCar() {
    qDebug() << "This car has" << m_numberOfWheels << "wheels.";
}
