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
#include "administrator.h"
#include"person.h"
using namespace std;
bool administrator::login()
{
	bool thebool = false;
	//vector<string>adminpass={"admin123","admin","adminfaiq","adminmoiz"};
	string adminpass[] = { "admin123","admin" };
aap:
	cout << "enter your password: " << endl;
	string pass;
	cin >> pass;
	cin.ignore();
	int i = 0;
	for (i; i < 2; i++)
	{
		if (pass == adminpass[i])
		{
			thebool = true;
			cout << "..........WELCOME..........." << endl;
			return true;
		}
	}
	if (!thebool)
	{
		cout << "cannot login. Please try again." << endl;
		goto aap;
	}
}

void administrator::readfromfile()
{
	cout << "Press 1 to see student records." << endl;
	cout << "Press 2 to see teacher records." << endl;
	int c;
	cin >> c;
	if (c == 1) {
		cout << "Reading from the file." << endl;
		student a;
		ifstream fin;
		fin.open("studentsdata.bin", ios::in | ios::binary);
		fin.read((char*)&a, sizeof(a));
		while (!fin.eof())
		{
			a.display();
			fin.read((char*)&a, sizeof(a));
		}
		fin.close();
	}
	else if (c == 2) {
		cout << "Reading from the file." << endl;
		teacher b;
		ifstream finn;
		finn.open("teachersdata.bin", ios::in | ios::binary);
		finn.read((char*)&b, sizeof(teacher));
		while (!finn.eof())
		{
			b.display();
			finn.read((char*)&b, sizeof(teacher));
		}
		finn.close();
	}
}

void administrator::addtofilestudent()
{
	student a;
	a.setid();
	a.setaddress();
	a.setemail();
	a.setname();
	a.setnumber();
	a.setpassword();
	a.setsection();
	a.setdepartment();
	a.setsemester();
	ofstream fout;
	fout.open("studentsdata.bin", ios::app | ios::binary);
	fout.write((char*)&a, sizeof(a));
	fout.close();
}
void administrator::searchstudentbyid(string idd)
{
	int count = 0;
	student a;
	ifstream file;
	file.open("studentsdata.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "File not found." << endl;
	}
	else
	{
		file.read((char*)&a, sizeof(a));
		while (!file.eof())
		{
			if (idd == a.getid())
			{
				a.display();
				count++;
			}
			file.read((char*)&a, sizeof(a));
		}
		if (count == 0)
			cout << "Not found." << endl;
	}
}

void administrator::removestudentbyidandname(string idd, string name)
{
	int counter = 0;
	student a;
	ifstream fin;
	ofstream fout;
	fin.open("studentsdata.bin", ios::in | ios::binary);
	fout.open("tempstudent.bin", ios::out | ios::binary);
	if (!fin)
	{
		cout << "No record exists." << endl;
	}
	else
	{
		while (fin.read((char*)&a, sizeof(a)))
		{
			if (a.getid() == idd && a.getname() == name)
			{
				counter++;
			}
			else
			{
				fout.write((char*)&a, sizeof(a));
			}
		}
		if (counter == 0)
		{
			cout << "No record found." << endl;
		}
		else
		{
			cout << "Removed " << counter << " records." << endl;
		}
		fin.close();
		fout.close();
		remove("studentsdata.bin");
		rename("tempstudent.bin", "studentsdata.bin");
	}
}

void administrator::resetdatast(string idd)
{
	student a;
	fstream file;
	file.open("studentsdata.bin", ios::in | ios::out | ios::binary);
	if (!file)
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		bool recordFound = false;
		while (file.read((char*)&a, sizeof(a)))
		{
			if (a.getid() == idd)
			{
				recordFound = true;
				a.setid();
				a.setaddress();
				a.setemail();
				a.setname();
				a.setnumber();
				a.setpassword();
				a.setsection();
				a.setdepartment();
				a.setsemester();
				file.seekp(int(file.tellg()) - sizeof(a));
				file.write((char*)&a, sizeof(a));
				break; // Exit the loop after updating the record
			}
		}

		if (recordFound)
		{
			cout << "Record updated successfully." << endl;
		}
		else
		{
			cout << "Record not found." << endl;
		}
	}

	file.close();
}

void administrator::addtofileteacher()
{
	teacher a;
	a.setid();
	a.setaddress();
	a.setemail();
	a.setname();
	a.setnumber();
	a.setpassword();
	a.setdepartment();
	a.setsalary();
	//a.setclasses();
	ofstream fout;
	fout.open("teachersdata.bin", ios::app | ios::binary);
	fout.write((char*)&a, sizeof(teacher));
	fout.close();
}

void administrator::searchteacherbyid(string idd)
{
	teacher a;
	ifstream file;
	file.open("teachersdata.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "File not found." << endl;
	}
	else
	{
		file.read((char*)&a, sizeof(teacher));
		while (!file.eof())
		{
			if (idd == a.getid())
			{
				a.display();
			}
			file.read((char*)&a, sizeof(teacher));
		}
	}
}

void administrator::removeteacherbyidandname(string idd, string namee)
{
	teacher a;
	ifstream fin;
	ofstream fout;
	fin.open("teachersdata.bin", ios::in | ios::binary);
	if (!fin)
	{
		cout << "No record exists." << endl;
		return;
	}
	fout.open("tempteacher.bin", ios::out | ios::binary);
	fin.read((char*)&a, sizeof(teacher));
	while (!fin.eof())
	{
		if (a.getid() == idd && a.getname() == namee)
		{
			cout << "Teacher removed: " << a.getname() << endl;
		}
		else
		{
			fout.write((char*)&a, sizeof(teacher));
		}
		fin.read((char*)&a, sizeof(teacher));
	}
	fin.close();
	fout.close();
	remove("teachersdata.bin");
	rename("tempteacher.bin", "teachersdata.bin");
}

void administrator::resetdatateach(string idd)
{
	teacher t;
	fstream file;
	file.open("teachersdata.bin", ios::in | ios::out | ios::binary);
	file.seekg(0);
	if (!file)
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		bool found = false;
		while (file.read((char*)&t, sizeof(teacher)))
		{
			if (t.getid() == idd)
			{
				found = true;
				t.setid();
				t.setaddress();
				t.setemail();
				t.setname();
				t.setnumber();
				t.setpassword();
				t.setdepartment();
				t.setsalary();
				file.seekp(int(file.tellg()) - sizeof(teacher));
				file.write((char*)&t, sizeof(teacher));
				break;
			}
		}

		if (!found)
		{
			cout << "Teacher with ID " << idd << " not found." << endl;
		}
	}
	file.close();
}

void administrator::makeattendencelist() {
	attendence p;
	string section;
	string subject;
	cout << "Enter the section of class:" << endl;
	cin >> section;
	cout << "Enter the subject:" << endl;
	cin >> subject;
	int l;
	cout << "Enter the number of students you want to enter:" << endl;
	cin >> l;
	ofstream fout;
	fout.open(section + subject + "attendencelist", ios::app, ios::binary);
	for (int i = 0; i < l; i++) {
		p.setname();
		p.setid();
		p.setpresent(0);
		p.settotaldays(0);
		fout.write((char*)&p, sizeof(p));
	}
}

void administrator::writedatesheet() {
	string c;
	cout << "Enter the class:" << endl;
	cin >> c;

	// Check if the class record already exists
	ifstream checkFile("datesheetmade");
	string line;
	bool classExists = false;
	while (getline(checkFile, line)) {
		if (line == c) {
			classExists = true;
			break;
		}
	}
	checkFile.close();

	// If the class record exists, ask if the user wants to overwrite it
	if (classExists) {
		char choice;
		cout << "A date sheet for this class already exists. Do you want to overwrite it? (Y/N)" << endl;
		cin >> choice;
		if (choice != 'Y' && choice != 'y') {
			return;
		}
	}

	// Open the file to write the date sheet for the class
	ofstream fout;
	fout.open(c + "datesheet");

	int l;
	cout << "How many subjects you want to enter?" << endl;
	cin >> l;

	for (int i = 0; i < l; i++) {
		datesheet d;
		d.setsubject();
		d.setdate();
		d.settime();
		fout.write((char*)&d, sizeof(d));
	}

	// Add the class name to the list of date sheets made
	ofstream classList("datesheetmade", ios::app);
	classList << c << endl;
	classList.close();

	cout << "Date sheet created successfully." << endl;
}
