#include <iostream>
#include "lock.hpp"

using namespace std;

void writedb(int &db, int value);
void updatedb(int &db, int value);

int main() // Imagine mutithreading
{
	int db = 0;
	try
	{
		updatedb(db, -1);
		cout << "db updated" << endl;
	}
	catch (exception e)
	{
		cout << "Exception!" << endl;
	}
}

void writedb(int &db, int value)
{
	if (value < 0)
		throw exception("Cannot store negative value");

	db = value;
}

void updatedb(int &db, int value)
{
	
	lock lockdb;
	if (lockdb.lock_successful())
	{
		writedb(db, value);
	}
}