#include <iostream>
#include <stdlib.h>
using namespace std;

#include "../shared_objects/resistor.cpp"

int main(int argc, char* argv []){
  if(argc != 3){
    cout << "This is how you should have called me: ";
    cout << "parallel_resistors [resitance1] [resitance2]" << endl;
    cout << "Try again!" << endl;

    return 1;
  }

  double resistance1 = (double)atof(argv[1]);
  double resistance2 = (double)atof(argv[2]);

	Resistor resistor1(resistance1);
	Resistor resistor2(resistance2);

	Resistor equivalent_resistor = resistor1*resistor2;

	cout << resistance1 << "||" << resistance2 << "=";
	cout << equivalent_resistor.get_resistance() << endl;

  return 0;
}
