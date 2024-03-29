/*
	Name: Josiah Derricott
	Program Name: P3 MyString v2

	Description: This is a recreation of the built in C++ string class which
		uses const char pointers and manipulates them in varying ways using
		dynamic memory, pointer arithmetic, operator overloading, and streams
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
	vector<JDString> myStrs;

	ifstream fin("infile3.txt");

	if (fin.fail())
	{
		cout << " >> Error: File not found!\n";
		exit(1);
	}

	JDString mainStr, temp;
	int count = 0;

	while (fin >> temp)
	{
		mainStr = mainStr + temp;
		count++;

		if (!(count % 5))
		{
			myStrs.push_back(mainStr);
			mainStr.clear();
		}
	}

	if (mainStr.length() > 0)
		myStrs.push_back(mainStr);

	fin.close();

	for (int i = 0; i < myStrs.size() - 1; i++)
	{
		for (int j = 0; j < myStrs.size() - i - 1; j++)
		{
			if (myStrs.at(j) > myStrs.at(j + 1))
			{
				JDString temp(myStrs.at(j));
				myStrs.at(j) = myStrs.at(j + 1);
				myStrs.at(j + 1) = temp;
			}
		}
	}

	for (const JDString& str : myStrs)
	{
		cout << left << setw(34) << str
			<< str.length() << ":" << str.capacity()
			<< endl;
	}

	cout << "\nCreated Count : " << JDString::getCreatedCount()
		<< endl << "Current Count : " << JDString::getCurrentCount()
		<< endl;

	system("pause");
}

// Expected Output:
/*
	Ibegantocomparethe                18:20
	Ifeltwasimpossible.Or             21:40
	Theyseemedamazinglybusy.I         25:40
	andrulesinhisbody?                18:20
	anironcladorasteam                18:20
	asaman'sbrainsits                 17:20
	askmyselfforthefirst              20:40
	begantoaskmyselfwhat              20:40
	didaMartiansitwithin              20:40
	each,ruling,directing,using,much  32:40
	enginewouldseemtoan               19:20
	intelligentloweranimal.ThisIsMyAmazinglyLongStringToMakeYourExtractionOperatorWorkCorrectly.92:100
	intelligentmechanisms?Suchathing  32:40
	theycouldbe.Werethey              20:40
	thingstohumanmachines,to          24:40
	timeinmylifehow                   15:20

	Created Count : 266
	Current Count : 18
*/