#include "pch.h"
#include "JDString.h"
#include <iostream>

using namespace std;

int JDString::createdCount = 0;
int JDString::currentCount = 0;

int JDString::getCreatedCount()
{
	return createdCount;
}

int JDString::getCurrentCount()
{
	return currentCount;
}

JDString::JDString()
{
	setCapacity(20);

	createdCount++;
	currentCount++;

	setEnd(0);
}

JDString::JDString(const JDString& str)
{
	if (this != &str)
	{
		createdCount++;
		currentCount++;

		setCapacity(str.capacity());

		setEnd(str.length());

		for (int i = 0; i < str.length(); i++)
		{
			m_Str[i] = str.at(i);
		}
	}
}

JDString::JDString(const char* str)
{
	createdCount++;
	currentCount++;

	setCapacity(20);

	int i;

	for (i = 0; *str != '\0'; i++)
	{
		if (i >= capacity())
		{
			setEnd(i);
			updateEnd(i);
		}

		m_Str[i] = *str;

		str++;
	}

	setEnd(i);
}

JDString::~JDString()
{
	currentCount--;

	delete[] m_Str;
}

JDString& JDString::operator = (const JDString& argStr)
{
	if (this != &argStr)
	{
		clear();

		if (argStr.capacity() > m_Cap)
			setCapacity(argStr.capacity());

		setEnd(argStr.length());

		for (int i = 0; i < argStr.length(); i++)
		{
			m_Str[i] = argStr.at(i);
		}
	}

	return *this;
}

const char JDString::operator [] (const int &index) const
{
	return m_Str[index];
}

char& JDString::operator [] (const int &index)
{
	return m_Str[index];
}

istream& operator >> (istream& istrm, JDString &str)
{
	char strArr[100];

	str.clear();

	if (istrm >> strArr)
	{
		for (int i = 0; i < 100; i++)
		{
			if (i > str.m_End)
				str.setEnd(i);

			if (i >= str.capacity())
			{
				str.updateEnd(i);
			}

			if (strArr[i] == '\0')
			{
				str.setEnd(i);

				break;
			}

			str[i] = strArr[i];
		}
	}

	return istrm;
}

ostream& operator << (ostream& ostrm, const JDString &str)
{
	ostrm << str.c_str();

	return ostrm;
}

int JDString::compareTo(const JDString& argStr) const
{
	// Set the size based on smallest string
	int size = length() < argStr.length() ? length() : argStr.length();

	// Iterate based on size and compare each character
	for (int i = 0; i < size + 1; i++)
	{
		if (at(i) < argStr.at(i))
		{
			return -1;
		}
		else if (at(i) > argStr.at(i))
		{
			return 1;
		}
	}

	return 0;
}

bool JDString::operator > (const JDString& argStr) const
{
	if (compareTo(argStr) > 0)
		return true;

	return false;
}

bool JDString::operator < (const JDString& argStr) const
{
	if (compareTo(argStr) < 0)
		return true;

	return false;
}

bool JDString::operator == (const JDString& argStr) const
{
	if (compareTo(argStr) == 0)
		return true;

	return false;
}

JDString JDString::operator + (const JDString& argStr) const
{
	JDString temp(*this);

	int startIndex = temp.length();

	temp.updateEnd(temp.length() + argStr.length());

	for (int i = startIndex; i < temp.length(); i++)
	{
		temp[i] = argStr.at(i - startIndex);
	}

	return temp;
}

int JDString::length() const
{
	return m_End;
}

int JDString::capacity() const
{
	return m_Cap;
}

const char JDString::at(int index) const
{
	if (index < length())
		return m_Str[index];

	return '\0';
}

const char* JDString::c_str() const
{
	return m_Str;
}

void JDString::setCapacity(int newCap)
{
	m_Cap = newCap;

	m_Str = new char[m_Cap];
}

void JDString::setEnd(int newEnd)
{
	m_End = newEnd;

	if (m_End < capacity())
		m_Str[m_End] = '\0';
}

void JDString::updateEnd(int newEnd)
{
	if (newEnd >= m_Cap)
	{
		char* temp = m_Str;
		int prevLen = length() + 1;

		int capAddition = m_Cap + 20;

		while (capAddition < newEnd)
			capAddition += 20;

		setCapacity(capAddition);

		for (int i = 0; i < prevLen; i++)
		{
			m_Str[i] = temp[i];
		}

		delete[] temp;

		setEnd(newEnd);
	}
	else
	{
		setEnd(newEnd);
	}
}

void JDString::clear()
{
	setCapacity(20);
	setEnd(0);
}