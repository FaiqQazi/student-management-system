#pragma once
#include<iostream>
#include<string>
using namespace std;
class datesheet {
private:
	string date;
	string subject;
	string time;

public:
	void setdate();
	void setsubject();
	void settime();
	void display();
};
