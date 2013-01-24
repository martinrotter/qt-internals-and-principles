#ifndef CAR_H
#define CAR_H


class Car {
    public:
	// Creates new car.
	Car(int number_of_wheels, bool has_owner = true);

	// Displays information about this car.
	void showCar();

    private:
	int m_numberOfWheels;	// Signs count of wheels of this car.
	bool m_hasOwner;	// Does this car have an owner?
};

#endif // CAR_H
