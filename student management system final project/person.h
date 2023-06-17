#pragma once
#include<string >
#include<iostream>
using namespace std;
class person {
protected:
	string name;
	string password;
	string id;
	char email[20];
	string number;
	string address;

public:
	void    setname();
	string getname();
	void    setpassword();
	string  getpassword();
	void    setid();
	string   getid();
	void    setemail();
	string  getemail();
	void   setaddress();
	string   getaddress();
	void    setnumber();
	string    getnumber();
	void     display() ;
};
