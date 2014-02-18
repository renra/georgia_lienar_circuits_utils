#include <iostream>
#include <stdlib.h>
using namespace std;

#include "../shared_objects/impedance.cpp"

int main(int argc, char* argv []){
  if(argc != 3){
    cout << "This is how you should have called me: ";
    cout << "./pol2rect [magnitude] [phase]" << endl;
    cout << "Try again!" << endl;

    return 1;
  }

  double magnitude = (double)atof(argv[1]);
  double phase = (double)atof(argv[2]);

  Impedance impedance(magnitude, phase, true);

  cout << impedance.get_magnitude() << "<" << impedance.get_phase() << "=";
  cout << impedance.get_impedance() << endl;

  return 0;
}
