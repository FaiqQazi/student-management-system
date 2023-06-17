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
#include"student.h"
#include"teacher.h"
using namespace std;
class administrator {
public:
	bool login();
	void readfromfile();
	void addtofilestudent();
	void searchstudentbyid(string idd);
	void removestudentbyidandname(string idd, string name);
	void resetdatast(string idd);
	void addtofileteacher();
	void searchteacherbyid(string idd);
	void removeteacherbyidandname(string idd, string namee);
	void resetdatateach(string idd);
	void makeattendencelist();
	void writedatesheet();
};
