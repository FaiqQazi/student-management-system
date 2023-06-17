#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<cstdio>
#include<iomanip>
#include <windows.h>
#include "person.h"
using namespace std;
void person::setname() {
	cout << "Enter the name: ";
	getline(cin, name);
}

string person::getname() {
	return name;
}

void person::setpassword() {
	cout << "Enter the password: ";
	cin >> password;
	cin.ignore();
}

string person::getpassword() {
	return password;
}

void person::setid() {
	cout << "Enter the ID: ";
	cin >> id;
	cin.ignore();
}

string person::getid() {
	return id;
}

void person::setemail() {
	cout << "Enter the email: ";
	cin.getline(email, 20);
}

string person::getemail() {
	return email;
}

void person::setaddress() {
	cout << "Enter the address: ";
	cin >> address;
	cin.ignore();
}

string person::getaddress() {
	return address;
}

void person::setnumber() {
	cout << "Enter the number: ";
	cin >> number;
	cin.ignore();
}

string person::getnumber() {
	return number;
}