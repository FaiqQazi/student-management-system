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
#include "attendence.h"
using namespace std;
void attendence::setname() {
	cout << "Enter name: ";
	cin >> name;
}

void attendence::setid() {
	cout << "Enter ID: ";
	cin >> id;
}

void attendence::setpresent(int p) {
	present = p;
}

void attendence::settotaldays(int k) {
	tdays = k;
}

string attendence::getid() {
	return id;
}

int attendence::getpresent() {
	return present;
}

int attendence::gettotaldays() {
	return tdays;
}

void attendence::attendenceshow() {
	cout << "Name: " << name << "    ID: " << id << "    Present: " << present << "  Total days: " << tdays << std::endl;
}