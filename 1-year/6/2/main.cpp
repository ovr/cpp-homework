#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;

class Student
{
public:
	int d, m, y;
	string name, surname;
	int mark1, mark2, mark3, mark4;
 
    Student(string _name, string _surname, int _d, int _m, int _y, int _mark1, int _mark2, int _mark3, int _mark4) {
		this->name = _name;
		this->surname = _surname;
		
		this->d = _d;
		this->m = _m;
		this->y = _y;
	}
};

bool sortFunction (const Student& studentA, const Student& studentB) {
	return studentA.surname < studentB.surname;
}


void Print(const Student& student) { 
    cout << student.name << " " << student.surname << endl; 
}
 
 
int main()
{
    std::vector<Student> studBase;
 
    std::ifstream ifsStud("STUDENT.DAT");
 
    std::string n, s;
    int d, m, y, mark1, mark2, mark3, mark4;
 
    if (!ifsStud.is_open()) { std::cerr << "ERROR! File can't opened. \n";
        exit(EXIT_FAILURE);
    }
 
    while (!ifsStud.eof())
    {
        ifsStud >> n; ifsStud >> s;
        ifsStud >> d; ifsStud >> m; ifsStud >> y;
		
		ifsStud >> mark1;
		ifsStud >> mark2;
		ifsStud >> mark3;
		ifsStud >> mark4;
 
        studBase.push_back(Student(n, s, d, m, y, mark1, mark2, mark3, mark4));
    }

	
	sort(studBase.begin(), studBase.end(), sortFunction);
	for_each(studBase.begin(), studBase.end(), Print);
	
    return 0;
}