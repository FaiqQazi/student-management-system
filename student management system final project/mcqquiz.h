#pragma once
#include<string >
#include<iostream>
#include"quiz.h"
using namespace std;
class mcqquiz : public quiz {
private:
	char option1[20];
	char option2[20];
	char option3[20];
	char option4[20];
	char ans;

public:
	char getans();
	void getdata();
	void display();
};
