#include <iostream>
#include <string>

using namespace std;

struct car
{
	string brand;
	string model;
	int year;
	int horsepower;
};

ostream& operator<<(ostream& os, const car& c)
{
	os << "{" << c.brand << " " << c.model << " " << c.year << " " << c.horsepower << "hp}";
	return os;
}

int main()
{
	car cars[3] = {
		{"Dodge", "Challenger SRT Hellcat", 2023, 717},
		{"Ford", "Mustang Shelby GT500", 2022, 760},
		{"Chevrolet", "Camaro ZL1", 2023, 650}
	};

	cout << cars[0] << endl;
	cout << cars[1] << endl;
	cout << cars[2] << endl;

	return 0;
}
