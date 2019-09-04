/*
	Name: Josiah Derricott
	Section: S
	Program Name: P3 MyString v2

	Description: This is the header file for the JDString class and contains
		member function prototypes and member data for the JDString class to
		be used in the JDString.cpp file
*/

#ifndef JDSTRING_H
#define JDSTRING_H

#include <iostream>

using namespace std;


/*
	This class creates a new data structure that manipulates
	null terminated character arrays to be more useful with less
	complexity and more user-readability
*/
class JDString
{
public:
	// Default constructor
	JDString();

	// Copy Construtor
	JDString(const JDString& str);

	// Param constructor
	JDString(const char*);

	// Destructor
	~JDString();

	/*
		Sets the current string's data fully
		equal to the argStr's data
	*/
	JDString& operator=(const JDString& argStr);

	char operator[](const int &index);

	/*
		Reads from any stream into the string
	*/
	friend istream& operator>>(istream& istrm, JDString& str);

	/*
		Writes from the string to a stream
	*/
	ostream& operator<<(ostream& ostrm);

	/*
		Checks the comparsion of the current string to
		a given string

			returns 1 if greater than
			returns -1 if less than
			returns 0 if equal to
	*/
	int compareTo(const JDString& argStr);

	/*
		Checks if the current string is less than a given string
	*/
	bool operator<(const JDString& argStr);

	/*
		Checks if the current string is greater than a given string
	*/
	bool operator>(const JDString& argStr);

	/*
		Checks if the current string is equal to a given string
	*/
	bool operator==(const JDString& argStr);

	/*
		Appends a given string on to the end of the current string
	*/
	JDString operator+(const JDString& argStr);

	/*
		Returns the current length of the string
	*/
	int length() const;

	/*
		Returns the current memory capacity
	*/
	int capacity() const;

	/*
		Returns char from the string at the given index
	*/
	char at(int index) const;

	/*
		Returns a null terminated char array
	*/
	const char* c_str() const;

	/*
		Sets capacity of string to given integer
	*/
	void setCapacity(int newCap);

	/*
		Sets the end point of the string to the given integer
	*/
	void setEnd(int newEnd);

	/*
		Returns count of static variable currentCount
	*/
	static int getCurrentCount();

	/*
		Returns count of static variable createdCount
	*/
	static int getCreatedCount();
private:
	static int currentCount;
	static int createdCount;
	int m_Cap = 20;
	int m_End = 0;
	char *m_Str;
};

#endif