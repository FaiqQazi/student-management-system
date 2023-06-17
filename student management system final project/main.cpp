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
#include"person.h"
#include"marks.h"
#include"quiz.h"
#include"assignment.h"
#include"datesheet.h"
#include"attendence.h"
#include"answer.h"
#include"mcqquiz.h"
#include"administrator.h"
#include"teacher.h"
#include "student.h"
using namespace std;
const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;
const int GRAY = 8;

void setColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

int main() {
	administrator a;
go1:
	system("CLS");
	cout << setw(80) << setfill('=') << "" << endl;
	setColor(WHITE, BLUE);
	cout << setw(39) << setfill(' ') << "STUDENT MANAGEMENT SYSTEM" << setw(40) << "" << endl;
	setColor(WHITE, BLACK);
	cout << setw(80) << setfill('=') << "" << endl;
	cout << endl;
	cout << "1 : Administrator login" << endl;
	cout << "2 : Student login" << endl;
	cout << "3 : Teacher login" << endl;
	cout << endl;
	int nn;
	cout << "Enter: ";
	cin >> nn;
	if (nn == 1)
	{
		bool bb;
		bb = a.login();
		if (bb)
		{
		go2:
			system("CLS");
			cout << setw(80) << setfill('=') << "" << endl;
			setColor(WHITE, BLUE);
			cout << setw(39) << setfill(' ') << "WELCOME TO ADMIN LOBBY" << setw(40) << "" << endl;
			setColor(WHITE, BLACK);
			cout << setw(80) << setfill('=') << "" << endl;
			cout << endl;
			cout << "1 Search student record with ID" << endl;
			cout << "2 Search teacher record with ID" << endl;
			cout << "3 Remove student record with ID and name" << endl;
			cout << "4 Remove teacher record with ID and name" << endl;
			cout << "5 Reset student record" << endl;
			cout << "6 Reset teacher record" << endl;
			cout << "7 Access whole record" << endl;
			cout << "8 Add a student to record" << endl;
			cout << "9 Add a teacher to record" << endl;
			cout << "10 Make attendance list" << endl;
			cout << "11 Press to make datesheet" << endl;
			cout << "12 Press to go to main" << endl;
			cout << endl;
			int nnn;
			cout << "Enter: ";
			cin >> nnn;
			cin.ignore();
			if (nnn == 1)
			{
				string m;
				cout << "Enter student ID: ";
				cin >> m;
				cin.ignore();
				a.searchstudentbyid(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;

			}
			else if (nnn == 2)
			{
				string m;
				cout << "Enter teacher ID: ";
				cin >> m;
				cin.ignore();
				a.searchteacherbyid(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 3)
			{
				string m;
				string n;
				cout << "Enter student ID: ";
				cin >> m;
				cin.ignore();
				cout << "Enter student name: ";
				getline(cin, n);
				a.removestudentbyidandname(m, n);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 4)
			{
				string m;
				string n;
				cout << "Enter teacher ID: ";
				cin >> m;
				cin.ignore();
				cout << "Enter teacher name: ";
				getline(cin, n);
				a.removeteacherbyidandname(m, n);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 5)
			{
				string m;
				cout << "Enter ID: ";
				cin >> m;
				a.resetdatast(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 6)
			{
				string m;
				cout << "Enter ID: ";
				cin >> m;
				a.resetdatateach(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 7)
			{
				a.readfromfile();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 8)
			{
				a.addtofilestudent();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 9)
			{
				a.addtofileteacher();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 10)
			{
				a.makeattendencelist();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 11)
			{
				a.writedatesheet();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 12)
			{
				goto go1;
			}

		}
	}
	else if (nn == 2)
	{
		student s;
		int l = 1;
		if (l == 1)
		{
			string pass;

			ifstream fin("studentsdata.bin", ios::in | ios::binary);
			if (!fin) {
				cout << "Error opening file." << endl;
				return false;
			}
			cout << "Enter your password: ";
			cin >> pass;
			cin.ignore();
			student ssss;
			bool thebool = false;
			while (fin.read((char*)&ssss, sizeof(student))) {

				if (pass == ssss.getpassword()) {


					cout << "..........WELCOME........... " << endl;
					goto sheela;
				}
			}
			if (!thebool) {
				cout << "Cannot login. Please try again." << endl;
				exit(0);
			}
			fin.close();
		go3:
		sheela:

		
			system("CLS");
			cout << setw(80) << setfill('=') << "" << endl;
			setColor(WHITE, BLUE);
			cout << setw(39) << setfill(' ') << "WELCOME TO STUDENT LOBBY" << setw(40) << "" << endl;
			setColor(WHITE, BLACK);
			cout << setw(80) << setfill('=') << "" << endl;
			cout << endl;
			cout << "1 Give assignment of section" << endl;
			cout << "2 View date sheet" << endl;
			cout << "3 Give quiz for all" << endl;
			cout << "4 Give quiz for one" << endl;
			cout << "5 Check attendance" << endl;
			cout << "6 Check marks of quiz" << endl;
			cout << "7 Check marks of assignment" << endl;
			cout << "8 Display information" << endl;
			cout << "9 To give MCQ test" << endl;
			cout << "10 Go to main menu" << endl;
			int h;
			cout << endl;
			cout << "Enter choice: ";
			cin >> h;
			cin.ignore();
			if (h == 1)
			{
				s.giveassignmentforall();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 2)
			{
				s.showdatesheet();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 3)
			{
				s.givequizforall();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 4)
			{
				s.givequizforone();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 5)
			{
				s.checkattendance();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 6)
			{
				int c;
				setColor(WHITE, MAGENTA);
				cout << "Press 1 to check marks for collective quiz or 2 for individual quiz: ";
				setColor(WHITE, BLACK);
				cin >> c;
				if (c == 1) {
					s.checkmarks();
				}
				else if (c == 2) {
					s.checkmarksone();
				}
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 7)
			{
				int c;
				setColor(WHITE, MAGENTA);
				cout << "Press 1 to check marks for collective assignment or 2 for individual assignment: ";
				setColor(WHITE, BLACK);
				cin >> c;
				if (c == 1) {
					s.checkmarkass();
				}
				else if (c == 2) {
					s.checkmarksassone();
				}
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 8)
			{
				//s.displayinfo();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 9)
			{
				s.givemcqquiz();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 10)
			{
				goto go1;
			}
			else
			{
				cout << "Invalid input, please try again" << endl;
				goto go3;
			}
		}
	}
	else if (nn == 3)
	{
	
		int l = 1;
		

			teacher t;

			if (1)
			{
				bool thebool = false;
				ifstream fin;
				teacher ss;
				fin.open("teachersdata.bin", ios::in | ios::binary);
				fin.read((char*)&ss, sizeof(class teacher));
			aap:
				cout << "enter you password " << endl;
				string pass;
				cin >> pass;
				cin.ignore();
				int i = 0;
				while (!fin.eof())
				{
					if (pass == ss.getpassword())
					{
						thebool = true;
						cout << "..........WELCOME........... " << endl;
						goto jawani;
					}
					fin.read((char*)&ss, sizeof(class teacher));
				}
				if (!thebool)
				{
					cout << "cannot login .please try again " << endl;

					exit(0);
				}
			go4:
			jawani:
		
			system("CLS");
			cout << setw(80) << setfill('=') << "" << endl;
			setColor(WHITE, BLUE);
			cout << setw(39) << setfill(' ') << "WELCOME TO TEACHER LOBBY" << setw(40) << "" << endl;
			setColor(WHITE, BLACK);
			cout << setw(80) << setfill('=') << "" << endl;
			cout << endl;
			cout << "1 Check assignment of section" << endl;
			cout << "2 Check assignment for one" << endl;
			cout << "3 Check quiz for section" << endl;
			cout << "4 Check quiz for one" << endl;
			cout << "5 Display information from record" << endl;
			cout << "6 Student record display" << endl;
			cout << "7 Mark attendance" << endl;
			cout << "8 Make assignment for all" << endl;
			cout << "9 Make assignment for one" << endl;
			cout << "10 Make quiz for section" << endl;
			cout << "11 Make quiz for one" << endl;
			cout << "12 Make MCQ quiz" << endl;
			cout << "13 Go to main menu" << endl;
			int bu;
			cout << endl;
			cout << "Enter option: ";
			cin >> bu;
			cin.ignore();
			if (bu == 1)
			{
				t.checkassignmentforall();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 2)
			{
				t.checkassone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 3)
			{
				t.checkquizforall();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 4)
			{
				t.checkquizforone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 5)
			{
				//t.displayinfo();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 6)
			{
				//t.sturecord();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 7)
			{
				t.markattendance();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 8)
			{
				t.makeassignmentforall();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 9)
			{
				t.makeassignmentforone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 10)
			{
				t.makequizforsec();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 11)
			{
				t.makequizforone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 12)
			{
				t.makemcqquiz();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 13)
			{
				goto go1;
			}
		}
	}
	return 0;
}