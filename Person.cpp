
#include "Person.h"


Person::Person()
{
	name = "";
	age = 0;
	scores_array = nullptr;
	scores_array = new float[5];
}

Person::Person(string name, int age)
{
	this->age = age;
	this->name = name;

	scores_array = nullptr;
	scores_array = new float[5];
}

string Person::GetName()
{
	return name;
}

int Person::GetAge()
{
	return age;
}

void Person::SetName(string name)
{
	this->name = name;
}
void Person::SetAge(int age)
{
	this->age = age;
}

Person::~Person()
{
	cout << "Person object destroyed " << endl;
	delete scores_array;
}