#include <iostream> // Для нормальної компіляції може знадобитися ключ -lstdc++
#include <string>
#include "lab-cpp_4-46_class.h"
using namespace std;

int main() {
	cout << "Creation of Alfa, Beta, Hama objects:" << endl;

	LawnMower Alfa("A-1000lm", 40, 500, 2.5);
	LawnMower Beta("B-2000lm", 50, 700, 4.7);
	LawnMower Hama("H-3000lm", 60, 900, 8.3);
	//LawnMower Dela();

	Alfa.InPut_LabTestObject(-1, "Protected string Alfa");
	Beta.InPut_LabTestObject(-2, "Protected string Beta");
	Hama.InPut_LabTestObject(-3, "Protected string Hama");

	Alfa.publicNumber = 1;		Alfa.publicString = "Public string Alfa";
	Beta.publicNumber = 2;		Beta.publicString = "Public string Beta";
	Hama.publicNumber = 3;		Hama.publicString = "Public string Hama";

	cout << endl;

	cout << "Object Alfa:" << endl
		<< "\t" << "Model name: " << Alfa.getName() << endl
		<< "\t" << "Characteristic:" << endl
		<< "\t\t" << "Grass mowing width: " << Alfa.getWidth() << " centimeters" << endl
		<< "\t\t" << "Engine power: " << Alfa.getPower() << " watts" << endl
		<< "\t\t" << "The volume of the fule tank " << Alfa.getVolume() << " liters" << endl;

	cout << "Object Beta:" << endl
		<< "\t" << "Model name: " << Beta.getName() << endl
		<< "\t" << "Characteristic:" << endl
		<< "\t\t" << "Grass mowing width: " << Beta.getWidth() << " centimeters" << endl
		<< "\t\t" << "Engine power: " << Beta.getPower() << " watts" << endl
		<< "\t\t" << "The volume of the fule tank " << Beta.getVolume() << " liters" << endl;

	cout << "Object Hama:" << endl
		<< "\t" << "Model name: " << Hama.getName() << endl
		<< "\t" << "Characteristic:" << endl
		<< "\t\t" << "Grass mowing width: " << Hama.getWidth() << " centimeters" << endl
		<< "\t\t" << "Engine power: " << Hama.getPower() << " watts" << endl
		<< "\t\t" << "The volume of the fule tank " << Hama.getVolume() << " liters" << endl;

	cout << "Test object:" << endl
		<< "\t" << "Protected Alfa: " << "\t" << Alfa.getProtectString() << " " << Alfa.getProtectNumber() << endl
		<< "\t" << "Public Alfa: " << "\t\t" << Alfa.publicString << " " << Alfa.publicNumber << endl
		<< "\t" << "Protected Beta: " << "\t" << Beta.getProtectString() << " " << Beta.getProtectNumber() << endl
		<< "\t" << "Public Beta: " << "\t\t" << Beta.publicString << " " << Beta.publicNumber << endl
		<< "\t" << "Protected Hama: " << "\t" << Hama.getProtectString() << " " << Hama.getProtectNumber() << endl
		<< "\t" << "Public Hama: " << "\t\t" << Hama.publicString << " " << Hama.publicNumber << endl;

	return 0;
}
