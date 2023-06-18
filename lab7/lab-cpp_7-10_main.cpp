#include "lab-cpp_7-10_class.h"

int main() {
	Car *myCar = new Car("Fiat 126p");
	Bus *myBus = new Bus("MAN 135 Premium");
	Plane *myPlane = new Plane("Mriia");
	Trolleybus *myTrolleybus = new Trolleybus("Bohdan #1408");
	Tram *myTram = new Tram("Lviv Cyberpunk #77");

	MyVehicle I_have_got;

	I_have_got.aboutVehicle(myCar);
	I_have_got.aboutVehicle(myBus);
	I_have_got.aboutVehicle(myPlane);
	I_have_got.aboutVehicle(myTrolleybus);
	I_have_got.aboutVehicle(myTram);

	delete myCar, myBus, myPlane, myTrolleybus, myTram;
}
