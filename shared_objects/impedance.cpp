#include <complex>
#include <cmath>

class Impedance{
  std::complex<double> impedance;
  double magnitude;
  double phase;

  void compute_magnitude_and_phase(){
    this->magnitude = sqrt(
      this->get_real()*this->get_real() + this->get_imag()*this->get_imag()
    );

    double phase_rad = atan(this->get_imag()/this->get_real());
    this->phase = phase_rad * 180/M_PI;
  }

  void compute_impedance(){
    this->impedance = std::complex<double> (
      this->magnitude * cos(phase_in_radians()),
      this->magnitude * sin(phase_in_radians())
    );
  }

  double phase_in_radians() const{
    return this->phase * M_PI / 180;
  }

  public:
  Impedance(std::complex<double> _impedance){
    this->impedance = _impedance;
  }

  Impedance(double param1, double param2, bool polar = false){
    if(polar){
      this->magnitude = param1;
      this->phase = param2;
      compute_impedance();
    }
    else{
      this->impedance = std::complex<double>(param1, param2);
      compute_magnitude_and_phase();
    }
  }

  std::complex<double> get_impedance() const {
    return this->impedance;
  }

  double get_real() const {
    return this->impedance.real();
  }

  double get_imag() const {
    return this->impedance.imag();
  }

  double get_magnitude() const{
    return this->magnitude;
  }

  double get_phase() const{
    return this->phase;
  }

  std::complex<double> inverse() const{
    return (std::complex<double>)1/this->impedance;
  }

  Impedance operator *(Impedance _imp){
    //TODO: DRY this up
    std::complex<double> complex_impedance = \
      (std::complex<double>)1/(_imp.inverse() + this->inverse());

    Impedance imp(complex_impedance);

    return imp;
  }

  ~Impedance(){}
};
