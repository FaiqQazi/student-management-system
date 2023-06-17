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
class student :public person {
private:
	
	string section;
	string department;
	int semester;
public:
	void setname();
	string getname();
	void setsection();
	string getsection();
	void setdepartment();
	string getdepartment();
	void setsemester();
	int getsemester();
	void givequizforone();
	void givequizforall();
	void checkmarks();
	void checkmarksone();
	void checkmarkass();
	void giveassignmentforall();
	void giveassignmentforone();
	void checkmarksassone();
	void checkattendance();
	void showdatesheet();
	void givemcqquiz();
	void display();
};
