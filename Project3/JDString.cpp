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
	m_Str = new char[m_Cap];

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

		m_Str = new char[m_Cap];

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

	m_Str = new char[m_Cap];

	int i;

	for (i = 0; str != '\0'; i++)
	{
		m_Str[0] = *(str + i);
	}

	setEnd(i);
}

JDString::~JDString()
{
	currentCount--;

	delete[] m_Str;
}

JDString& JDString::operator=(const JDString& argStr)
{
	if (this != &argStr)
	{
		setCapacity(argStr.capacity());
		setEnd(argStr.length());

		for (int i = 0; i < argStr.length(); i++)
		{
			m_Str[i] = argStr.at(i);
		}
	}

	return *this;
}

char JDString::operator[](const int &index) // Wants this to not be const?
{
	return m_Str[index];
}

istream& friend JDString::operator>>(istream& istrm, JDString str) // Fix this
{
	char str[100];

	if ((istrm >> str))
	{
		for (int i = 0; i < 100; i++)
		{
			if (str[i] == '\0')
			{
				setEnd(i);

				break;
			}

			m_Str[i] = str[i];
		}
	}

	return istrm;
}

ostream& JDString::operator<<(ostream& ostrm)
{
	ostrm << c_str();
}

int JDString::compareTo(const JDString& argStr)
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

bool JDString::operator>(const JDString& argStr)
{
	if (compareTo(argStr) > 0)
		return true;

	return false;
}

bool JDString::operator<(const JDString& argStr)
{
	if (compareTo(argStr) < 0)
		return true;

	return false;
}

bool JDString::operator==(const JDString& argStr)
{
	if (compareTo(argStr) == 0)
		return true;

	return false;
}

JDString JDString::operator+(const JDString& argStr)
{
	int startIndex = m_End;

	setEnd(m_End + argStr.length());

	for (int i = startIndex; i < m_End; i++)
	{
		m_Str[i] = argStr.at(i - startIndex);
	}
}

int JDString::length() const
{
	return m_End;
}

int JDString::capacity() const
{
	return m_Cap;
}

char JDString::at(int index) const
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
}

void JDString::setEnd(int newEnd)
{
	if (newEnd > m_Cap)
	{
		JDString temp(*this);

		delete[] m_Str;

		setCapacity(m_Cap + 20);

		m_Str = new char[m_Cap];
	}

	m_Str[newEnd] = '\0';
	m_End = newEnd;
}