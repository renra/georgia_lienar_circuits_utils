#include <iostream>
#include <stdlib.h>
using namespace std;

#include "../shared_objects/impedance.cpp"

int main(int argc, char* argv []){
  if(argc != 5){
    cout << "This is how you should have called me: ";
    cout << "./parallel_impedance [impedance1 real] [impedance1 imag] [impedance2 real] [impedance2 imag]" << endl;
    cout << "Try again!" << endl;

    return 1;
  }

  double real1 = (double)atof(argv[1]);
  double real2 = (double)atof(argv[3]);

  double imag1 = (double)atof(argv[2]);
  double imag2 = (double)atof(argv[4]);

  Impedance impedance1(real1, imag1);
  Impedance impedance2(real2, imag2);

  Impedance equivalent_impedance = impedance1*impedance2;

	cout << impedance1.get_impedance() << "||" << impedance2.get_impedance() << "=";
	cout << equivalent_impedance.get_impedance() << endl;

  return 0;
}
