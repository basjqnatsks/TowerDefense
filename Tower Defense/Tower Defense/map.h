#pragma once
class map {
public:
	map();
	~map();


	//getters
	double get_x();
	double get_y();


	//setters
	void set_x_axis(double var);
	void set_y_axis(double var);
private:
	double x;
	double y;

};