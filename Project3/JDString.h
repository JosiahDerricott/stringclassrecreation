/*
	Name: Josiah Derricott
	Program Name: P3 MyString v2

	Description: This is a recreation of the built in C++ string class
	which has some operator overloading to allow fluid use, and utility functions
	such as length() and capacity() which return information about the memory
	being stored.
*/

#ifndef JDSTRING_H
#define JDSTRING_H

#include <iostream>

using namespace std;

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
	JDString& operator = (const JDString& argStr);

	/*
		Returns the read-only value at the given index
	*/
	const char operator [] (const int &index) const;
	/*
		Returns the modifiable value at the given index
	*/
	char& operator [] (const int &index);

	/*
		Checks the comparsion of the current string to
		a given string

			returns 1 if greater than
			returns -1 if less than
			returns 0 if equal to
	*/
	int compareTo(const JDString& argStr) const;

	/*
		Checks if the current string is less than a given string
	*/
	bool operator < (const JDString& argStr) const;

	/*
		Checks if the current string is greater than a given string
	*/
	bool operator > (const JDString& argStr) const;

	/*
		Checks if the current string is equal to a given string
	*/
	bool operator == (const JDString& argStr) const;

	/*
		Appends a given string on to the end of the current string
	*/
	JDString operator + (const JDString& argStr) const;

	/*
		Reads from any stream into the string
	*/
	friend istream& operator >> (istream& istrm, JDString &str);

	/*
		Writes from the string to a stream
	*/
	friend ostream& operator << (ostream& ostrm, const JDString &str);

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
	const char at(int index) const;

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
		Updates end point with capacity checking
	*/
	void updateEnd(int newEnd);

	/*
		Clears string contents and resets it
	*/
	void clear();

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
	int m_Cap = 0;
	int m_End = 0;
	char *m_Str = nullptr;
};

#endif