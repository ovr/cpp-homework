#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "table_printer.h"

using namespace std;

struct Item {
    int size, color, count;
    string title, name;
};

bool sortFunction (const Item& a, const Item& b) {
    return a.title < b.title;
}


void Print(const Item& product) {
    cout << "|" << setw(20) << product.title
         << "|" << setw(20) << product.name
         << "|" << setw(10) << product.color
         << "|" << setw(10) << product.size
         << "|" << setw(10) << product.count
         << "|" << endl;

    cout << "----------------------------------------------------------------------------" << endl;
}

void PrintWomen(const Item& product) {
    if (!product.title.empty() && product.title.at(0) != 'M') {
        Print(product);
    }
}

void PrintMen(const Item& product) {
    if (!product.title.empty() && product.title.at(0) == 'M') {
        Print(product);
    }
}

std::vector<Item> products;

inline void addItem()
{
    Item item;

    cout << "Add item:" << endl;

    cout << "title = ";
    cin >> item.title;

    cout << "name = ";
    cin >> item.name;


    cout << "size = ";
    cin >> item.size;


    cout << "color = ";
    cin >> item.color;


    cout << "count = ";
    cin >> item.count;

    products.push_back(item);
}

void printTableHeader()
{
    cout << "============================================================================" << endl;
    cout << "|" << setw(20) << "Title"
    << "|" << setw(20) << "Name"
    << "|" << setw(10) << "Color"
    << "|" << setw(10) << "Count"
    << "|" << setw(10) << "Size"
    << "|" << endl;
    cout << "============================================================================" << endl;
}

void readFromFile()
{
    ifstream ifsStud("products.txt");

    if (!ifsStud.is_open()) { std::cerr << "ERROR! File can't opened. \n";
        exit(EXIT_FAILURE);
    }

    Item item;

    while (!ifsStud.eof()) {
        ifsStud >> item.title;
        ifsStud >> item.name;

        ifsStud >> item.size;
        ifsStud >> item.color;
        ifsStud >> item.count;

        products.push_back(item);
    }
}

void menu()
{
    cout << "Please select" << endl;
    cout << "1. Read from file" << endl;
    cout << "2. Add an item" << endl;
    cout << "3. Listing" << endl;
    cout << "4. Sort listing" << endl;
    cout << "5. Lising men" << endl;
    cout << "6. Lising women" << endl;
    cout << "7. Clear db" << endl;
    cout << "8. Exit" << endl;

    int menuItem;
    cin >> menuItem;

    system("clear");

    switch (menuItem) {
        case 1:
            readFromFile();
            cout << "Success, read" << endl << endl;
            break;
        case 2:
            addItem();
            cout << "Success, adding" << endl << endl;
            break;
        case 3:
            printTableHeader();

            for_each(products.begin(), products.end(), Print);
            cout << "Success, listing" << endl << endl;
            break;
        case 4:
            sort(products.begin(), products.end(), sortFunction);

            printTableHeader();
            for_each(products.begin(), products.end(), Print);
            cout << endl << endl;
            break;
        case 5:

            printTableHeader();
            for_each(products.begin(), products.end(), PrintMen);
            cout << endl << endl;
            break;
        case 6:

            printTableHeader();
            for_each(products.begin(), products.end(), PrintWomen);
            cout << endl << endl;
            break;
        case 7:
            products.clear();
            cout << "Success, clear memory db" << endl << endl;
            break;
        case 8:
            cout << "Good buy" << endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "Unknown" << endl;
            break;
    }

    menu();
}

int main()
{
    system("clear");
    menu();

    return 0;
}
