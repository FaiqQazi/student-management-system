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
#include "answer.h"
using namespace std;
void answer::getanswer()
{
	cin.getline(anss, 69);
}

void answer::setid()
{
	cout << "enter id" << endl;
	cin >> id;
}

string answer::getid()
{
	return id;
}

void answer::getidone(string idd)
{
	id = idd;
}
void answer::displayans()
{
	const int width = 80; // total width of output
	const int idWidth = 20; // width reserved for ID

	// Create separator line
	string separatorLine(width, '-');

	// Display answer information
	cout << separatorLine << endl;
	cout << "ID: " << setw(idWidth) << left << id << endl;
	cout << "Answer given:" << endl;
	cout << anss << endl;
	cout << separatorLine << endl;
}