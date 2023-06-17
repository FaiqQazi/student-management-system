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
#include"student.h"
#include"thegraduatestudent.h"
using namespace std;
void thegraduatestudent::researchpaper()
{
	cout << "enter the topic of the research" << endl;
	string topic;
	cin >> topic;
	ofstream fout;
	fout.open("resarchpapers.txt", ios::out | ios::binary);
	char all[200];
	cout << "enter the details " << endl;
	cin >> all;
	getch();
	cout << "research has been inclluded "
		<< endl;
}