#pragma once
#include<iostream>
#include<string>
using namespace std;
class attendence {
protected:
	string name;
	string id;
	int tdays;
	int present;

public:
	void setname();
	void setid();
	void setpresent(int p);
	void settotaldays(int k);
	std::string getid();
	int getpresent();
	int gettotaldays();
	void attendenceshow();
};
