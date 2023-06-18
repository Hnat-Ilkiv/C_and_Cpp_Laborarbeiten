#include <iostream>
#include <string>
using namespace std;

class LawnMower {
	private:
		int grasscuttingWidth;
		int enginePower;
		float fueltankVolume;
		string modelName;
	protected:
		int protectNumber;
		string protectString;
	public:
		int publicNumber;
		string publicString;
		//LawnMower() = default;
		LawnMower(string name, int width, int power, float volume) {
			modelName = name;
			grasscuttingWidth = width;
			enginePower = power;
			fueltankVolume = volume;

			cout << "\t" << "A new object is created" << endl;
			
		}

		void InPut_LabTestObject(int Number, string String) {
			protectNumber = Number;
			protectString = String;
		}

		int getWidth() {
			return grasscuttingWidth;
		}

		int getPower() {
			return enginePower;
		}

		float getVolume() {
			return fueltankVolume;
		}

		string getName() {
			return modelName;
		}

		int getProtectNumber();
		string getProtectString();
};

int LawnMower::getProtectNumber() {
	return protectNumber;
}

string LawnMower::getProtectString() {
	return protectString;
}
