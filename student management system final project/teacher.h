#pragma once
#include<string >
#include<iostream>
#include"person.h"
#include"marks.h"
#include"quiz.h"
#include"assignment.h"
#include"datesheet.h"
#include"attendence.h"
#include"answer.h"
#include"mcqquiz.h"
using namespace std;
class teacher : public person
{
protected:
	string department;
	string degree;
	string salary;
	int experience;
	int numresearch;
	vector<string> publications;

public:
	void setsalary();
	string getsalary();
	string getdepartment();
	void setdepartment();
	void makequizforsec();
	void makequizforone();
	void checkquizforall();
	void checkquizforone();
	void makeassignmentforall();
	void makeassignmentforone();
	void checkassignmentforall();
	void checkassone();
	void markattendance();
	void makemcqquiz();
	void showmcqresult();
	void display();
};

