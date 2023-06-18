#include "lab-cpp_7-10_class.h"
#include <iostream>
#include <string>

void Vehicle::set_ModalName(std::string ModalName) {
	this->ModalName = ModalName;
}

std::string Vehicle::get_ModalName() {
	return ModalName;
}

Car::Car(std::string ModalName) {
	set_ModalName(ModalName);
}
void Car::moveVehicle() {
	std::cout << "This "  << get_ModalName() << " is very fast but it has very little space." << std::endl;
}

Bus::Bus(std::string ModalName) {
	set_ModalName(ModalName);
}
void Bus::moveVehicle() {
	std::cout << "This " << get_ModalName() << " is very slow, but it can carry a lot of people." << std::endl;
}

Plane::Plane(std::string ModalName) {
	set_ModalName(ModalName);
}
void Plane::moveVehicle() {
	std::cout << "This "  << get_ModalName() << " is very fast and can carry a lot of people but it is expensive." << std::endl;
}

Trolleybus::Trolleybus(std::string ModalName) {
	set_ModalName(ModalName);
}
void Trolleybus::moveVehicle() {
	std::cout << "This "  << get_ModalName() << " is very quiet and can carry a lot of people, but it cannot deviate from the route." << std::endl;
}

Tram::Tram(std::string ModalName) {
	set_ModalName(ModalName);
}
void Tram::moveVehicle() {
	std::cout << "This "  << get_ModalName() << " is fast, very quiet and can carry many people, but it cannot deviate from the route." << std::endl;
}

void MyVehicle::aboutVehicle(Vehicle *vehicle) {
	vehicle->moveVehicle();
}
