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
#include "quiz.h"
using namespace std;
void quiz::getdata() {
	string section, sub;
	cout << "Enter the section for quiz: ";
	cin >> section;

	cout << "Enter the subject for quiz: ";
	cin >> sub;

	fstream fout("quizseclist", ios::app);
	fout << section + sub << endl;
	fout.close();

	cin.ignore();

	cout << "Type down the quiz: ";
	cin.getline(statement, 49);

	ofstream fout1;
	fout1.open(section + sub, ios::out | ios::binary);
	fout1.write((char*)this, sizeof(class quiz));
	fout1.close();
}
void quiz::getdataforone() {
	quiz c;
	string id;
	cout << "Enter the ID for quiz: ";
	cin >> id;

	fstream fout2("quizstulist", ios::app);
	fout2 << id << endl;

	cin.ignore();

	cout << "Type down the quiz: ";
	cin.getline(statement, 49);

	ofstream fout;
	fout.open(id, ios::out | ios::binary);
	fout.write((char*)&c, sizeof(class quiz));
	fout.close();
}
void quiz::display() {
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "Quiz statement: " << statement << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
}