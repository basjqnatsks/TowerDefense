#include "wrapper.h"

wrapper::wrapper() {
	//starting amount of money       1000?
	this->Currency = 1000;




}
wrapper::~wrapper() {

}


void wrapper::run_app() {

}

//getters
int wrapper::get_currency() {
	return this->Currency;
}
int wrapper::get_numoftowers() {
	return this->Numberoftowers;
}


//setters
void wrapper::set_currency(int var) {
	this->Currency = var;
}
void wrapper::set_Numberoftowers(int var) {
	this->Numberoftowers = var;
}