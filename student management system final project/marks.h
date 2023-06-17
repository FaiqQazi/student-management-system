#pragma once
#include<iostream>
#include<string>
using namespace std;
class marks
{
private:
	int mark;
	string id;

public:
	void setid(string idd);
	string getid();
	void getmarksdata();
	void getmarksdataone();
	void getmarkdataass();
	void getmarksdataassone();
	void showmarks();
};
