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
#include "student.h"
#include"person.h"
using namespace std;
void student::setname() {
	cout << "Enter the name: ";
	getline(cin, name);
}

string student::getname() {
	return name;
}

void student::setsection() {
	cout << "Enter the section: ";
	getline(cin, section);
}

string student::getsection() {
	return section;
}

void student::setdepartment() {
	cout << "Enter the department: ";
	getline(cin, department);
}

string student::getdepartment() {
	return department;
}

void student::setsemester() {
	cout << "Enter the semester: ";
	cin >> semester;
	cin.ignore();
}

int student::getsemester() {
	return semester;
}

void student::givequizforone() {
	quiz a;
	ifstream file;
	string l, id;
	int c = 0;

a:
	cout << "Enter your ID: ";
	cin >> id;

	fstream fout("quizstulist", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (id == l) {
			c++;
			break;
		}
	}

	if (c == 0) {
		cout << "There is no quiz for you." << endl;
		goto a;
	}

	file.open(id, ios::in | ios::binary);
	file.read((char*)&a, sizeof(class quiz));

	while (!file.eof()) {
		a.display();
		file.read((char*)&a, sizeof(class quiz));
	}

	file.close();

	ofstream f;
	string n = id + "answer";
	answer ansss;

	cout << "Enter your answer: " << endl;
	cin.ignore();
	ansss.getanswer();

	f.open(n, ios::out | ios::app | ios::binary);
	f.write((char*)&ansss, sizeof(class answer));
	f.close();
}
void student::givequizforall() {
	quiz a;
	answer aa;
	ifstream file;
	int c = 0;
	string l;
	string sec, sub;

	cout << "Enter your section: ";
	cin >> sec;

	cout << "Enter the subject: ";
	cin >> sub;

	fstream fout("quizseclist", ios::in);

	while (!fout.eof()) {
		getline(fout, l);

		if (sec + sub == l) {
			c++;
		}
	}

	if (c == 0) {
		cout << "\nThere is no quiz for your section.\n";
	}

	if (c == 1) {
		int c1 = 0;

		aa.setid();

		ofstream op;
		ofstream fout1;

		op.open(sec + sub + "taken", ios::app);
		op.close();

		ifstream ifin;
		ifin.open(sec + sub + "taken", ios::in);

		while (!ifin.eof()) {
			getline(ifin, l);

			if (l == aa.getid()) {
				cout << "\nYou have already attempted the quiz.\n";
				c1++;
			}
		}

		if (c1 == 0) {
			fout1.open(sec + sub + "taken", ios::app);
			fout1 << aa.getid() << endl;;
			fout1.close();

			file.open(sec + sub, ios::in | ios::binary);
			file.read((char*)&a, sizeof(a));
			a.display();
			file.close();

			cin.ignore();

			ofstream ff;
			string s = sec + sub + "answer";
			ff.open(s, ios::out | ios::app | ios::binary);

			cout << "\nBelow is your answer:\n";
			aa.getanswer();
			ff.write((char*)&aa, sizeof(class answer));
			ff.close();
		}
	}
}
// Function to check marks of a student in a particular section and subject
void student::checkmarks()
{
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string sec, sub;

	// Ask for section and subject from user
a:
	cout << "Enter your section: " << endl;
	cin >> sec;
	cout << "Enter the subject: " << endl;
	cin >> sub;

	// Open file containing list of sections and subjects
	fstream fout("markseclist", ios::in);
	// Loop through the file and check if the section and subject match
	while (!fout.eof()) {
		getline(fout, l);
		if (sec + sub == l) {
			c++;
			break;
		}
	}

	// If section and subject not found in list, ask again
	if (c == 0) {
		cout << "Your marks have not been uploaded yet. Please try again." << endl;
		goto a;
	}

	// Open file containing marks for the given section and subject
	file.open("marks" + sec + sub, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		string idd;

		// Ask for student ID and read marks from file
		cout << "Enter your ID: " << endl;
		cin >> idd;
		file.read((char*)&m, sizeof(class marks));

		// Loop through the file and display marks if student ID matches
		while (!file.eof()) {
			if (idd == m.getid()) {
				m.showmarks();
			}
			file.read((char*)&m, sizeof(class marks));
		}
	}

	file.close(); // Close the file
}

// Function to check marks of a student using their ID
void student::checkmarksone() {
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string id;

	// Ask for student ID from user
a:
	cout << "Enter your ID: " << endl;
	cin >> id;

	// Open file containing list of student IDs
	fstream fout("markseclistone", ios::in);
	// Loop through the file and check if the student ID matches
	while (!fout.eof()) {
		getline(fout, l);
		if (id == l) {
			c++;
			break;
		}
	}

	// If student ID not found in list, ask again
	if (c == 0) {
		cout << "Your marks have not been uploaded yet. Please try again." << endl;
		goto a;
	}

	// Open file containing marks for the given student ID
	file.open("marks" + id, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		// Read marks from file and display if student ID matches
		file.read((char*)&m, sizeof(class marks));
		while (!file.eof()) {
			if (id == m.getid()) {
				m.showmarks();
				file.read((char*)&m, sizeof(class marks));
				c++;
			}
		}
	}

	// If no marks found for the given student ID, display message
	if (c == 0) {
		cout << "Your result is not present." << endl;
	}

	file.close(); // Close the file
}
void student::checkmarkass() {
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string sec, sub;
a:
	cout << "Enter your section:" << endl;
	cin >> sec;
	cout << "Enter your subject:" << endl;
	cin >> sub;
	string s = sec + sub;
	fstream fout("markassseclist", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (s == l) {
			c++;
			break;
		}
	}
	if (c == 0) {
		cout << "Your marks have not been uploaded yet." << endl;
		goto a;
	}
	file.open("marksass" + sub + sec, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		string idd;
		string name;
		cout << "Enter your ID:" << endl;
		cin >> idd;
		file.read((char*)&m, sizeof(class marks));
		while (!file.eof()) {
			if (idd == m.getid()) {
				m.showmarks();
			}
			file.read((char*)&m, sizeof(class marks));
		}
	}
	file.close();
}
void student::giveassignmentforall() {
	string sec, subject;
	cout << "Enter your section: ";
	cin >> sec;
	cout << "Enter the subject of the assignment: ";
	cin >> subject;
	string section_subject = sec + subject;

	ifstream section_list_file("assseclist");
	string section_list_line;

	bool section_found = false;
	while (getline(section_list_file, section_list_line)) {
		if (section_list_line == section_subject) {
			section_found = true;
			break;
		}
	}
	section_list_file.close();

	if (!section_found) {
		cout << "There is no assignment for your section." << endl;
		return;
	}

	answer aa;
	aa.setid();

	ifstream taken_file(section_subject + "taken");
	string taken_id;

	bool already_taken = false;
	while (getline(taken_file, taken_id)) {
		if (taken_id == aa.getid()) {
			already_taken = true;
			break;
		}
	}
	taken_file.close();

	if (already_taken) {
		cout << "You have already attempted the assignment." << endl;
		return;
	}

	assignment as;
	ifstream assignment_file;
	assignment_file.open(section_subject + "assignment", ios::in | ios::binary);
	assignment_file.read((char*)&as, sizeof(as));
	as.display();
	assignment_file.close();

	cin.ignore();

	ofstream ff;
	ff.open(section_subject + "assighnmentanswers", ios::out | ios::app | ios::binary);
	cout << "Below, enter your answer:" << endl;
	aa.getanswer();
	ff.write((char*)&aa, sizeof(class answer));
	ff.close();

	ofstream taken_out(section_subject + "taken", ios::out | ios::app);
	taken_out << aa.getid() << endl;
	taken_out.close();

	cout << "Assignment completed successfully." << endl;
}
void student::giveassignmentforone() {
	assignment a;
	ifstream file;
	string l, id, sub;
	int c = 0;
a:
	cout << "Enter your ID: ";
	cin >> id;
	cout << "Enter the subject: ";
	cin >> sub;

	// Check if the user has already submitted the assignment
	ifstream given_file("assonegiven");
	while (getline(given_file, l)) {
		if (id + sub == l) {
			cout << "You have already submitted this assignment." << endl;
			given_file.close();
			return;
		}
	}
	given_file.close();

	fstream fout("assstulist", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (id + sub == l) {
			c++;
			break;
		}
	}
	fout.close();
	if (c == 0) {
		cout << "There is no assignment for you." << endl;
		goto a;
	}

	file.open(id + sub + "assignment", ios::in | ios::binary);
	file.read((char*)&a, sizeof(a));
	while (!file.eof()) {
		a.display();
		file.read((char*)&a, sizeof(class assignment));
	}
	file.close();

	ofstream f;
	string n = id + sub + "assanswer";
	answer ansss;
	cout << "Enter your answer: " << endl;
	cin.ignore();
	ansss.getanswer();
	f.open(n, ios::out | ios::app | ios::binary);
	f.write((char*)&ansss, sizeof(class answer));
	f.close();

	// Store the student id in the "assonegiven" file
	ofstream given_file_out("assonegiven", ios::out | ios::app);
	given_file_out << id + sub << endl;
	given_file_out.close();
}
void student::checkmarksassone() {
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string id, sub;
a:
	cout << "Enter your ID: " << endl;
	cin >> id;
	cout << "Enter the subject: " << endl;
	cin >> sub;

	fstream fout("markassstuone", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (id + sub == l) {
			c++;
			break;
		}
	}
	fout.close();

	if (c == 0) {
		cout << "Your marks have not been uploaded yet." << endl;
		goto a;
	}

	file.open("marksassone" + id + sub, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		file.read((char*)&m, sizeof(class marks));
		while (!file.eof()) {
			if (id == m.getid()) {
				m.showmarks();
				file.read((char*)&m, sizeof(class marks));
				c++;
			}
		}
	}
	file.close();

	if (c == 0) {
		cout << "Your result is not present." << endl;
	}
}
void student::checkattendance() {
	attendence p; // Create an instance of the "attendence" class
	string section;
	string subject;
	string l; // Declare a variable to store the student's ID
	cout << "Enter the section of class" << endl;
	cin >> section;
	cout << "Enter the subject" << endl;
	cin >> subject;
	cout << "Enter your ID" << endl;
	cin >> l;
	ifstream ifin; // Declare an input file stream
	ifin.open(section + subject + "attendencelist", ios::in, ios::binary); // Open the attendance list file for the specified section and subject
	ifin.read((char*)&p, sizeof(p)); // Read attendance data into the "attendence" instance
	while (!ifin.eof()) {
		if (l == p.getid()) { // Check if the student ID matches the current attendance record
			p.attendenceshow(); // Display the attendance data for the current record
		}
		ifin.read((char*)&p, sizeof(p)); // Read the next attendance record
	}
}
void student::showdatesheet() {
	datesheet d;
	string c;
	cout << "Enter the class:" << endl;
	cin >> c;

	ifstream checkfile;
	checkfile.open("datesheetmade");
	string classname;
	bool found = false;
	while (checkfile >> classname) {
		if (classname == c) {
			found = true;
			break;
		}
	}
	checkfile.close();

	if (!found) {
		cout << "Date sheet has not been made for this class." << endl;
		return;
	}

	ifstream fin;
	fin.open(c + "datesheet");
	fin.read((char*)&d, sizeof(d));
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(20) << left << "Subject" << "|"
		<< setw(10) << left << "Date" << "|"
		<< setw(15) << left << "Time" << "|"
		<< endl;
	while (!fin.eof()) {
		d.display();
		fin.read((char*)&d, sizeof(d));
	}
}
void student::givemcqquiz() {
	mcqquiz m;
	string section;
	string subject;
	string id;
	int c = 0;
	int c1 = 0;
	char a;
	cout << "Enter your section" << endl;
	cin >> section;
	cout << "Enter the subject you want to take quiz" << endl;
	cin >> subject;
	cout << "Enter your id" << endl;
	cin >> id;
	string l;

	// Check if the quiz section exists
	fstream fout("mcqquizseclist", ios::in);
	bool sectionFound = false;
	while (getline(fout, l)) {
		if (l == section + subject) {
			sectionFound = true;
			break;
		}
	}
	fout.close();
	if (!sectionFound) {
		cout << "There is no quiz for your section" << endl;
		return; // Exit the function
	}

	// Check if the student has already attempted the quiz
	ifstream ifin;
	ifin.open(section + subject + "mcqtaken", ios::in);
	while (getline(ifin, l)) {
		if (l == id) {
			cout << "You have already attempted the quiz" << endl;
			c1++;
			break;
		}
	}
	ifin.close();
	if (c1 > 0) {
		return; // Exit the function
	}

	// Take the quiz
	int num = 0;
	int total = 0;
	ofstream fout1;
	fout1.open(section + subject + "mcqtaken", ios::app);
	fout1 << id << endl;
	fout1.close();
	ifstream file;
	file.open(section + subject, ios::in | ios::binary);
	file.read((char*)&m, sizeof(m));
	while (file) { // Use the file object to check if there is more data to read
		m.display();
		while (true) {
			try {
				cout << "Enter your answer: ";
				cin >> a;
				if (a != 'a' && a != 'b' && a != 'c' && a != 'd') {
					throw runtime_error("Invalid answer, please try again.");
				}
				break;
			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}
		}
		if (a == m.getans()) {
			num++;
		}
		total++;
		file.read((char*)&m, sizeof(m));
	}
	file.close();

	// Show the results
	cout << "You have answered " << num << " out of " << total << " questions correctly" << endl;
	double percentage = static_cast<double>(num) / total * 100;
	cout << "Your percentage is " << setprecision(2) << fixed << percentage << "%" << endl;
	fstream fout2(section + subject + "mcqresult", ios::app);
	fout2 << id << ":" << num << endl;
	fout2.close();
}

void student::display() {
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "ID:         " << id << endl;
	cout << "Name:       " << name << endl;
	cout << "Email:      " << email << endl;
	cout << "Number:     " << number << endl;
	cout << "Address:    " << address << endl;
	cout << "Password:   " << password << endl;
	cout << "Department: " << department << endl;
	cout << "Section:    " << section << endl;
	cout << "Semester:   " << semester << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
}
