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

void printItem(const Item& product) {
    cout << "|" << setw(20) << product.title
    << "|" << setw(20) << product.name
    << "|" << setw(10) << product.color
    << "|" << setw(10) << product.size
    << "|" << setw(10) << product.count
    << "|" << endl;

    cout << "----------------------------------------------------------------------------" << endl;
}

bool sortFunction (const Item& a, const Item& b) {
    return a.title < b.title;
}

void printWomen(const Item& product) {
    if (!product.title.empty() && product.title.at(0) != 'M') {
        printItem(product);
    }
}

void printMen(const Item& product) {
    if (!product.title.empty() && product.title.at(0) == 'M') {
        printItem(product);
    }
}

class ConsoleApplication {
public:
    void readFromFile();
    void addItem();
    void listing();
    void listingMen();
    void listingWomen();
    void clear();
    void sort();
protected:
    std::vector<Item> products;

    void printTableHeader();
};

void ConsoleApplication::sort() {
    std::sort(products.begin(), products.end(), sortFunction);
}

void ConsoleApplication::clear() {
    products.clear();
}

void ConsoleApplication::listing()
{
    printTableHeader();

    for_each(products.begin(), products.end(), printItem);
}


void ConsoleApplication::listingMen()
{
    printTableHeader();

    for_each(products.begin(), products.end(), printMen);
}


void ConsoleApplication::listingWomen()
{
    printTableHeader();

    for_each(products.begin(), products.end(), printWomen);
}


void ConsoleApplication::printTableHeader()
{
    cout << "+==========================================================================+" << endl;
    cout << "|" << setw(20) << "Title"
    << "|" << setw(20) << "Name"
    << "|" << setw(10) << "Color"
    << "|" << setw(10) << "Count"
    << "|" << setw(10) << "Size"
    << "|" << endl;
    cout << "+==========================================================================+" << endl;
}


void ConsoleApplication::addItem()
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

void ConsoleApplication::readFromFile()
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

        this->products.push_back(item);
    }
}

void menu(ConsoleApplication &app)
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
            app.readFromFile();
            cout << "Success, read" << endl << endl;
            break;
        case 2:
            app.addItem();
            cout << "Success, adding" << endl << endl;
            break;
        case 3:
            app.listing();
            cout << "Success, listing" << endl << endl;
            break;
        case 4:
            app.sort();
            cout << "Success, sort" << endl << endl;
            break;
        case 5:
            app.listingMen();
            cout << "Success, listing Men" << endl << endl;
            break;
        case 6:
            app.listingWomen();
            cout << "Success, listing Women" << endl << endl;
            break;
        case 7:
            app.clear();
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

    menu(app);
}

int main()
{
    system("clear");

    ConsoleApplication app;
    menu(app);

    return 0;
}
