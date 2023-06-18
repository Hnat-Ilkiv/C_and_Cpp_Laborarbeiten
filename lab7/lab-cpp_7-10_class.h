#pragma once

#include <string>

class Vehicle{
	private:
		std::string ModalName = "NoName";
	public:
		void set_ModalName(std::string ModalName);
		std::string get_ModalName();
		virtual void moveVehicle() = 0;
};

class Car : public Vehicle{
	public:
		Car(std::string ModalName);
		void moveVehicle();
};

class Bus : public Vehicle{
	public:
		Bus(std::string ModalName);
		void moveVehicle();
};

class Plane : public Vehicle{
	public:
		Plane(std::string ModalName);
		void moveVehicle();
};

class Trolleybus : public Vehicle{
	public:
		Trolleybus(std::string ModalName);
		void moveVehicle();
};

class Tram : public Vehicle{
	public:
		Tram(std::string ModalName);
		void moveVehicle();
};

class MyVehicle{
	public:
		void aboutVehicle(Vehicle *vehicle);
};
