/*
	Name: Josiah Derricott
	Section: S
	Program Name: P3 MyString v2

	Description: This is a recreation of the built in C++ string class which
		uses const char pointers and manipulates them in varying ways using
		dynamic memory, pointer arithmetic, and streams
*/

#include "pch.h"
#include "JDString.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int index = 0;

	vector<JDString> strVec;
	
	ifstream fin("infile3.txt");

	if (fin.bad())
	{
		cout << " >> ERROR: File read is bad!\n\n";

		system("pause");

		exit(0);
	}

	JDString resultStr, tempStr;

	while (!fin.eof())
	{
		if (strVec.at(index).getCreatedCount() % 5 == 0)
		{
			strVec.push_back(resultStr);

			resultStr = "";
		}

		cin >> tempStr;


	}

	if (tempStr[0] != '\0')
	{
		strVec.push_back(tempStr);
	}

	system("pause");
}

// Output