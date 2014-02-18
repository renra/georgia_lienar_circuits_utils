#include <iostream>
#include <stdlib.h>
using namespace std;

#include "../shared_objects/impedance.cpp"

int main(int argc, char* argv []){
  if(argc != 3){
    cout << "This is how you should have called me: ";
    cout << "./inverse_impedance [impedance real] [impedance imag]" << endl;
    cout << "Try again!" << endl;

    return 1;
  }

  double real = (double)atof(argv[1]);
  double imag = (double)atof(argv[2]);

  Impedance impedance(real, imag);

	cout << impedance.get_impedance() << "^-1=";
	cout << impedance.inverse() << endl;

  return 0;
}
