class Resistor{
	double resistance;

	public:
	Resistor(double _resistance){
		this->resistance = _resistance;
	}

	~Resistor(){
	}

	// Better not overload ||, it could cause trouble for someone
	Resistor operator *(Resistor _res){
		double parallel_resistance = (this->resistance * _res.get_resistance()) \
			/(this->resistance + _res.get_resistance());

		Resistor r(parallel_resistance);

		return r;
	}

	double get_resistance() const {
		return this->resistance;
	}
};
