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
#include "datesheet.h"
using namespace std;
void datesheet::setdate() {
	cout << "Enter the date in this format D/M/Y: " << std::endl;
	cin >> date;
}

void datesheet::setsubject() {
	cout << "Enter the subject: " << std::endl;
	cin >> subject;
}

void datesheet::settime() {
	cout << "Enter the time in the format 11:30-12:30: " << std::endl;
	cin >> time;
}

void datesheet::display() {
	cout << "-------------------------------------------------" << std::endl;
	cout << "|" << std::setw(20) << std::left << subject << "|"
		<< std::setw(10) << std::left << date << "|"
		<< std::setw(15) << std::left << time << "|" << std::endl;
	cout << "-------------------------------------------------" << std::endl;
}