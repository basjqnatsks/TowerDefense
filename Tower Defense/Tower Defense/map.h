#pragma once
class map {
public:
	map();
	~map();


	//getters
	double ** get_location_Backend();


	//setters
	void set_location_backend(double var[800][800]);

private:
	double Location_BackEnd[800][800];

};