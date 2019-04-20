#pragma once






class wrapper {
public:
	wrapper();
	~wrapper();


	void run_app();


	//getters
	int get_currency();
	int get_numoftowers();


	//setters
	void set_currency(int var);
	void set_Numberoftowers(int var);


private:
	int Currency;

	//should we have a maximum number of towers???
	int Numberoftowers;

};