#include <iostream>
#include <Python/Python.h>

using namespace std;

struct Date {
public:
    unsigned y, m, d;
};

enum Sex {MEN, WOMAN};

class Employer {
protected:
    string firstname;
    string lastname;

    /**
     * Пол
     */
    Sex sex;

    Date incomeDate;
public:
    Employer() {

    }

    string getFirstname() const {
        return firstname;
    }

    string getLastname() const {
        return lastname;
    }


    virtual unsigned int calcWorkExperience() {
        return 2014-this->incomeDate.y;
    }

    friend ostream &operator << (ostream &fo, Employer *employer)
    {
        fo << employer->getFirstname() << " " << employer->getLastname() << endl;
        fo << "Work exp: " << employer->calcWorkExperience() << endl;

        return fo;
    }

    Employer(string firstname, string lastname, Sex sex, Date incomeDate) : firstname(firstname), lastname(lastname), sex(sex), incomeDate(incomeDate) {}
};

class Pensioner : public Employer {
protected:
    Date birthday;

public:
    Pensioner(string firstname, string lastname, Sex sex, Date incomeDate, Date birthDay) {
        this->firstname = firstname;
        this->lastname = lastname;
        this->sex = sex;
        this->incomeDate = incomeDate;
        this->birthday = birthDay;
    }

    virtual unsigned int calcPensYear() {
        unsigned int days = 2014 - birthday.y;

        if (this->sex == Sex::MEN) {
            if (days > 60) {
                return days - 60;
            }

            return 0;
        }

        if (days > 55) {
            return days - 55;
        }

        return 0;
    }

    friend ostream &operator << (ostream &fo, Pensioner *entity)
    {
        fo << entity->getFirstname() << " " << entity->getLastname() << endl;
        fo << "Work exp: " << entity->calcWorkExperience() << endl;
        fo << "calcPensYear : " << entity->calcPensYear() << endl;

        return fo;
    }
};

int main() {
    Date incomeDate;
    incomeDate.y = 1980;

    Employer *employer = new Employer("Илья", "Сахар", Sex::MEN, incomeDate);
    cout << employer << endl;

    Date birthDay;
    birthDay.y = 1945;

    Pensioner *pensioner = new Pensioner("Илья", "Сахар Пенсионер", Sex::MEN, incomeDate, birthDay);
    cout << pensioner << endl;

    cout << "Hello, World!" << endl;
    return 0;
}