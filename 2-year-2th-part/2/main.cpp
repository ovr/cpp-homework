#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Item {
    int size, color, count;
    string title, name;
};

bool sortFunction (const Item& a, const Item& b) {
    return a.title < b.title;
}


void Print(const Item& product) {
    cout << product.title << " " << product.name << endl;
}

void PrintWomen(const Item& product) {
    if (!product.title.empty() && product.title.at(0) != 'M') {
        cout << product.title << " " << product.name << endl;
    }
}

void PrintMen(const Item& product) {
    if (!product.title.empty() && product.title.at(0) == 'M') {
        cout << product.title << " " << product.name << endl;
    }
}

std::vector<Item> products;

inline void readFromFile()
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
    cout << "2. Listing" << endl;
    cout << "3. Sort listing" << endl;
    cout << "4. Lising men" << endl;
    cout << "5. Lising women" << endl;
    cout << "6. Clear db" << endl;
    cout << "7. Exit" << endl;

    int menuItem;
    cin >> menuItem;

    system("clear");

    switch (menuItem) {
        case 1:
            readFromFile();
            cout << "Success, read" << endl << endl;
            break;
        case 2:
            for_each(products.begin(), products.end(), Print);
            cout << "Success, listing" << endl << endl;
            break;
        case 3:
            sort(products.begin(), products.end(), sortFunction);
            for_each(products.begin(), products.end(), Print);
            cout << endl << endl;
            break;
        case 4:
            for_each(products.begin(), products.end(), PrintMen);
            cout << endl << endl;
            break;
        case 5:
            for_each(products.begin(), products.end(), PrintWomen);
            cout << endl << endl;
            break;
        case 6:
            products.clear();
            cout << "Success, clear memory db" << endl << endl;
            break;
        case 7:
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
