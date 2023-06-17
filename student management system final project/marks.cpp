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
#include "marks.h"
using namespace std;
void marks::setid(string idd)
{
	id = idd;
}

string marks::getid()
{
	return id;
}

void marks::getmarksdata()
{
	string section, sub;
	cout << "Enter section: ";
	cin >> section;
	cout << "Enter subject: ";
	cin >> sub;
	cin.ignore();

	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marks" + section + sub;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();

	ofstream fout2("markseclist", ios::app);
	fout2 << section + sub << endl;
	fout2.close();
}


void marks::getmarksdataone()
{
	cout << "Enter ID: ";
	cin >> id;
	cin.ignore();

	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marks" + id;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();

	ofstream fout2("markseclistone", ios::app);
	fout2 << id << endl;
	fout2.close();
}


void marks::getmarkdataass()
{
	string section, sub;
	cout << "Enter section: ";
	cin >> section;
	cout << "Enter subject: ";
	cin >> sub;
	cin.ignore();

	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marksass" + sub + section;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();

	ofstream fout2("markassseclist", ios::app);
	fstream ifin("markassseclist", ios::in);

	string line;
	bool exists = false;
	while (getline(ifin, line))
	{
		if (line == section + sub)
		{
			exists = true;
			break;
		}
	}
	if (!exists)
	{
		fout2 << section + sub << endl;
	}

	fout2.close();
}


void marks::getmarksdataassone()
{
	string sub;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter the subject: ";
	cin >> sub;
	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marksassone" + id + sub;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();
}


void marks::showmarks() {
	cout << "ID: " << id << std::endl;
	cout << "Marks obtained: " << mark << std::endl;
}