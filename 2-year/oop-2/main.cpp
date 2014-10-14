#include <iostream>
#include <cstring>


using namespace std;

class MyString
{
public:
	MyString()
	{
		this->_length = 0;
		this->_size = 0;
		this->_string = NULL;
	}
	MyString(const char* str)
	{
		this->_length = strlen(str);
		this->_size = this->_length + 1;
		this->_string = new char[this->_size];

		strcpy(this->_string, str);
	}
	~MyString()
	{
		if (this->_string != NULL)
		{
			delete[] this->_string;
			this->_string = NULL;
		}
	}

	MyString& operator=(const char* str) {
		this->_length = strlen(str);
		this->_size = this->_length + 1;

		this->_string = new char[this->_size];
		strcat(this->_string, str);

		return (MyString&) *this;
	}

	MyString& operator+(const char* str)
	{
		MyString* temp = new MyString();

		temp->_length = strlen(str) + strlen(this->_string);
		temp->_size = temp->_length + 1;

		temp->_string = new char[temp->_size];
		strcpy(temp->_string, this->_string);
		strcat(temp->_string, str);

		return (MyString&)*temp;
	}

	MyString& operator-(const int size)
	{
		MyString* temp = new MyString();

		temp->_size = this->_length - size;
		temp->_length = temp->_size;

		temp->_string = new char[temp->_size];
		strncpy(temp->_string, this->_string, temp->_size);

		return (MyString&)*temp;
	}

	size_t Length()
	{
		return this->_length;
	}

	char* getChars() {
		return this->_string;
	}
private:
	size_t _size;
	size_t _length;
	char* _string;
};

int main() {
	cout << "Hello, World!" << endl;

	MyString a = MyString("test a");
	MyString b = a;

	cout << a.getChars() << endl;
	cout << b.getChars() << endl;

	b = "test b";
	cout << endl << "b = \"test b\";" << endl;
	cout << b.getChars() << endl;

	b = b + " test c";
	cout << endl << "b = b + \" test c\";" << endl;
	cout << b.getChars() << endl;

	b = b - 1;
	cout << endl << "b = b - 1;" << endl;
	cout << b.getChars() << endl;

	b = b - 3;
	cout << endl << "b = b - 3;" << endl;
	cout << b.getChars() << endl;

	return 0;
}