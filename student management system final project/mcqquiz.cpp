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
#include "mcqquiz.h"
using namespace std;
char mcqquiz::getans() {
	return ans;
}

void mcqquiz::getdata() {
	string section;
	string subject;
	int l;
	cout << "Enter the section for the quiz: " << endl;
	cin >> section;
	cout << "Enter the subject of the quiz: " << endl;
	cin >> subject;
	fstream fout("mcqquizseclist", ios::app);
	fout << section + subject << endl;
	fout.close();
	cin.ignore();
	cout << "How many MCQs do you want to enter? " << endl;
	cin >> l;
	cin.ignore(); // Ignore the newline character
	ofstream fout1(section + subject, ios::out | ios::binary | ios::app);
	for (int i = 0; i < l; i++) {
		cout << "Type down MCQ statement: " << endl;
		cin.getline(statement, 50);
		cout << "Enter option 1: " << endl;
		cin.getline(option1, 20);
		cout << "Enter option 2: " << endl;
		cin.getline(option2, 20);
		cout << "Enter option 3: " << endl;
		cin.getline(option3, 20);
		cout << "Enter option 4: " << endl;
		cin.getline(option4, 20);
		while (true) {
			try {
				cout << "Enter your answer: ";
				cin >> ans;
				if (ans != 'a' && ans != 'b' && ans != 'c' && ans != 'd') {
					throw runtime_error("Invalid answer, please try again.");
				}
				break;
			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}
		}
		cin.ignore(); // Ignore the newline character
		fout1.write((char*)this, sizeof(mcqquiz));
	}
	fout1.close();
}



void mcqquiz::display() {
	cout << "MCQ Statement: " << statement << endl;
	cout << endl;
	cout << "Options:" << endl;
	cout << "   a. " << option1 << endl;
	cout << "   b. " << option2 << endl;
	cout << "   c. " << option3 << endl;
	cout << "   d. " << option4 << endl;
}