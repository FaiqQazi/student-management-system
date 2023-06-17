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
#include "teacher.h"
#include"person.h"
using namespace std;

void teacher::setsalary()
{
	cout << "Enter the salary: ";
	cin >> salary;
	cin.ignore();
}

string teacher::getsalary()
{
	return salary;
}

void teacher::setdepartment()
{
	cout << "Enter the department: ";
	cin >> department;
	cin.ignore();
}

string teacher::getdepartment()
{
	return department;
}

void teacher::makequizforsec()
{
	quiz a;
	a.getdata();
}

void teacher::makequizforone()
{
	quiz f;
	f.getdataforone();
}

void teacher::checkquizforall()
{
	answer anss;
	marks m;
	string a, b;
	cout << "Enter the section of the quiz: " << endl;
	cin >> b;
	cout << "Enter the subject: " << endl;
	cin >> a;
	cin.ignore();
	string my = b + a + "answer";
	ifstream boom;
	boom.open(my, ios::in | ios::binary);
	string s = b + a + "checkedquiz";
	string checked_id;
	if (!boom.is_open()) {
		cout << "Error opening assignment answers file." << endl;
		return;
	}

	while (boom.read((char*)&anss, sizeof(answer))) {
		bool paper_checked = false;
		string current_id = anss.getid();

		// Check if the paper has already been checked
		ifstream checked_papers_file(s);
		while (getline(checked_papers_file, checked_id)) {
			if (checked_id == current_id) {
				paper_checked = true;
				break;
			}
		}
		checked_papers_file.close();

		if (!paper_checked) {
			anss.displayans();
			m.setid(anss.getid());
			m.getmarksdata();

			// Add the paper ID to the checked papers file
			ofstream checked_papers(s, ios::app);
			checked_papers << current_id << endl;

			// Ask the user if they want to check the next paper
			char choice;
			cout << "Do you want to check the next paper? (Y/N): ";
			cin >> choice;
			if (toupper(choice) == 'N') {
				break; // Exit the loop if the user doesn't want to check the next paper
			}
		}
	}

	boom.close();
}

void teacher::checkquizforone()
{
	answer anss;
	marks m1;
	string a, b;
	string roll;
	cout << "Enter the roll number of the student whose quiz is to be checked: " << endl;
	cin >> roll;
	cin.ignore();

	string m = roll + "answer";
	ifstream boom;
	boom.open(m, ios::in | ios::binary);
	boom.read((char*)&anss, sizeof(answer));
	while (!boom.eof()) {
		anss.displayans();
		boom.read((char*)&anss, sizeof(anss));
		m1.getmarksdataone();
	}
	boom.close();
}

void teacher::makeassignmentforall()
{
	assignment f;
	f.getdata();
}

void teacher::makeassignmentforone()
{
	assignment a;
	a.getdataforoneass();
}

void teacher::checkassignmentforall()
{
	answer anss;
	string a, b;
	marks m;
	cout << "Enter the section of the quiz: ";
	cin >> b;
	cin.ignore();
	cout << "Enter the subject of the assignment: ";
	cin >> a;
	string my = b + a + "assighnmentanswers";
	string s = b + a + "checkedpapers";
	string checked_id;

	ifstream boom(my, ios::in | ios::binary);
	if (!boom.is_open()) {
		cout << "Error opening assignment answers file." << endl;
		return;
	}

	while (boom.read((char*)&anss, sizeof(answer))) {
		bool paper_checked = false;
		string current_id = anss.getid();

		// Check if the paper has already been checked
		ifstream checked_papers_file(s);
		while (getline(checked_papers_file, checked_id)) {
			if (checked_id == current_id) {
				paper_checked = true;
				break;
			}
		}
		checked_papers_file.close();

		if (!paper_checked) {
			anss.displayans();
			m.setid(anss.getid());
			m.getmarkdataass();

			// Add the paper ID to the checked papers file
			ofstream checked_papers(s, ios::app);
			checked_papers << current_id << endl;

			// Ask the user if they want to check the next paper
			char choice;
			cout << "Do you want to check the next paper? (Y/N): ";
			cin >> choice;
			if (toupper(choice) == 'N') {
				break; // Exit the loop if the user doesn't want to check the next paper
			}
		}
	}

	boom.close();
}

void teacher::checkassone()
{
	answer anss;
	marks m1;
	string roll, sub;
	cout << "Enter the ID number of the student whose quiz is to be checked: " << endl;
	cin >> roll;
	cout << "Enter the subject: " << endl;
	cin >> sub;
	cin.ignore();

	string m = roll + sub + "assanswer";
	ifstream boom;
	boom.open(m, ios::in | ios::binary);
	boom.read((char*)&anss, sizeof(answer));
	while (!boom.eof()) {
		anss.displayans();
		boom.read((char*)&anss, sizeof(anss));
		m1.setid(anss.getid());
		m1.getmarksdataassone();
	}
	boom.close();

	// Store the student ID and subject in the "markassstuone" file
	ofstream mark_file("markassstuone", ios::out | ios::app);
	mark_file << roll + sub << endl;
	mark_file.close();
}

void teacher::markattendance()
{
	attendence p;
	string section;
	string subject;
	cout << "Enter the section of the class: " << endl;
	cin >> section;
	cout << "Enter the subject: " << endl;
	cin >> subject;
	ifstream ifin(section + subject + "attendencelist", ios::in);
	ofstream fout("temp.txt", ios::out);
	while (ifin.read((char*)&p, sizeof(p))) {
		p.attendenceshow();
		int l = p.getpresent();
		int k = p.gettotaldays();
		cout << "Press 1 if student is present\nPress 2 if student is absent: " << endl;
		int c;
		cin >> c;
		if (c == 1) {
			l++;
			p.setpresent(l);
		}
		k++;
		p.settotaldays(k);
		fout.write((char*)&p, sizeof(p));
	}
	fout.close();
	ifin.close();
	remove((section + subject + "attendencelist").c_str());
	rename("temp.txt", (section + subject + "attendencelist").c_str());
}

void teacher::makemcqquiz()
{
	mcqquiz m;
	m.getdata();
}

void teacher::showmcqresult()
{
	string section;
	string subject;
	cout << "Enter the section: " << endl;
	cin >> section;
	cout << "Enter the subject of the quiz: " << endl;
	cin >> subject;
	string l;
	fstream fin(section + subject + "mcqresult", ios::in);
	while (!fin.eof()) {
		getline(fin, l);
		cout << l << endl;
	}
}

void teacher::display()
{
	cout << "======================================" << endl;
	cout << "ID: " << id << endl;
	cout << "Address: " << address << endl;
	cout << "Email: " << email << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "Password: " << password << endl;
	cout << "Department: " << department << endl;
	cout << "Salary: " << salary << endl;
	cout << "======================================" << endl;
}