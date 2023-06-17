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
#include "assignment.h"
using namespace std;
void assignment::getdata()
{
	int c1 = 0;
	string section;
	string subject;
	string l;
	cout << "Enter the section for assignment " << endl;
	cin >> section;
	cout << "Enter the subject" << endl;
	cin >> subject;
	string s = section + subject;
	ofstream fout;
	fout.open("assseclist", ios::app);
	fout << s << endl;
	fout.close();
	cin.ignore();
	cout << "Type down assignment " << endl;
	cin.getline(statement, 49);
	assignment c;
	ofstream fout1;
	string seet;
	seet = s + "assignment";
	fout1.open(seet, ios::out | ios::binary | ios::app);
	fout1.write((char*)this, sizeof(class assignment));
	fout1.close();
}

void assignment::getdataforoneass()
{
	assignment a;
	string id, sub;
	cout << "Enter the id for assignment " << endl;
	cin >> id;
	cout << "Enter subject" << endl;
	cin >> sub;
	fstream fout2("assstulist", ios::app);
	fout2 << id + sub << endl;
	cin.ignore();
	cout << "Type down assignment " << endl;
	cin.getline(statement, 49);
	ofstream fout;
	fout.open(id + sub + "assignment", ios::out | ios::binary);
	fout.write((char*)this, sizeof(class assignment));
	fout.close();
}

void assignment::display()
{
	cout << "--------------------------------------------------------" << endl;
	cout << "Assignment: " << statement << endl;
	cout << "--------------------------------------------------------" << endl;
}