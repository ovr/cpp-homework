#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


//3. Составить программу, которая реализует компьютерный вариант кассового аппарата.
//В структурном шаблоне должны содержаться сведения одного чека: дата, список покупок с указанием их цены, платежная сумма, вносимая покупателем и сумма сдачи, которая должна высчитываться программно.
//В программе по запросу пользователя предусмотреть вывод на экран всех чеков и  процедуру закрытия кассы (т.е. подсчет общей выручки за один день).

struct Item {
	string title;
	float price = 0;
	int count = 0;
};

struct Check
{
	float summa = 0, input = 0;
	int day,month,year;
	vector<Item> products;
};


void printItem(const Check& item) {
		ostringstream ostr;

		ostr << item.day << "-" << item.month << "-" << item.year;

    cout << "|" << setw(40) << (ostr.str())
    << "|" << setw(20) << item.summa
    << "|" << setw(10) << item.input
		<< "|" << setw(10) << (item.input - item.summa)
    << "|" << endl;

		cout << "-----------------------------------Products------------------------------------------" << endl;

		for (size_t i = 0; i < item.products.size(); i++) {
			cout << "|" << setw(40) << item.products[i].title
			<< "|" << setw(20) << item.products[i].price
			<< "|" << setw(10) << item.products[i].count
			<< "|" << setw(10) << (item.products[i].price *item.products[i].count)
			<< "|" << endl;
		}

    cout << "-------------------------------------------------------------------------------------" << endl;
}

void printTableHeader()
{
    cout << "+===================================================================================+" << endl;

		cout << "|" << setw(40) << "Date"
    << "|" << setw(20) << "Summa"
    << "|" << setw(10) << "Input"
		<< "|" << setw(10) << "Payback"
    << "|" << endl;

    cout << "+===================================================================================+" << endl;
}


int main()
{
	// setlocale(LC_ALL,"rus");
	// int V; int s=0,st;

	// cout<<"Êàññà v1.00\n\n\nÌåíþ:\n\n1)Ðåæèì ââîäà\n2)Ðåæèì âûâîäà\n3)Âûõîä\n\nÊîìàíäà: ";
	// cin>>V;

	system("clear");

	vector<Check> checks;
	Check check;
	Item item;
	int day, month, year;
	int total;

	while (true) {
		cout << "1. Add" << endl;
		cout << "2. List" << endl;
		cout << "3. List by date" << endl;
		cout << "4. Total" << endl;
		cout << "5. Exit" << endl;

		int menuItem;
		cin >> menuItem;

		switch (menuItem) {
			case 1:
				system("clear");

				check.products.clear();
				check.summa = 0;

				cout << "Add a check" << endl;
				cout << "day = ?" << endl;
				cin >> check.day;

				cout << "month = ?" << endl;
				cin >> check.month;

				cout << "year = ?" << endl;
				cin >> check.year;

				cout << "input = ?" << endl;
				cin >> check.input;

				cout << "Next you need to add product" << endl;

				//ыыы хитрый я
				while (menuItem == 1) {
					cout << "Title = ?" << endl;
					cin >> item.title;

					cout << "Price = ?" << endl;
					cin >> item.price;

					cout << "Count = ?" << endl;
					cin >> item.count;

					check.summa += item.price * item.count;
					check.products.push_back(item);

					cout << "Add a product? y (1)/n" << endl;
					cin >> menuItem;
				};

				checks.push_back(check);
				break;
			case 2:
				system("clear");
				printTableHeader();

				for (size_t i = 0; i < checks.size(); i++) {
					printItem(checks[i]);
				}
				break;
			case 3:
				system("clear");

				cout << "day = ?" << endl;
				cin >> day;

				cout << "month = ?" << endl;
				cin >> month;

				cout << "year = ?" << endl;
				cin >> year;

				printTableHeader();
				for (size_t i = 0; i < checks.size(); i++) {
					if (checks[i].day == day && checks[i].month == month && checks[i].year == year) {
						printItem(checks[i]);
					}
				}
				break;
			case 4:
				system("clear");
				printTableHeader();

				total = 0;
				for (size_t i = 0; i < checks.size(); i++) {
					total += checks[i].summa;
				}

				cout << "Total  = " << total << endl;
				break;
			case 5:
				system("clear");
				cout << "Goodbie, bitch" << endl;
				break;
			default:
				system("clear");
				cout << "Wrong menu item = " << menuItem << endl;
				exit(0);
				break;
		}

		cout << endl << endl << "Enter any text" << endl;
		cin >> menuItem;
		system("clear");
	}
}

