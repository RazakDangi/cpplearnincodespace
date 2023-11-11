#pragma once

#include <string>
#include <iostream>
using namespace std;

class Person {

public:
	string name;
	int age;
	float* scores_array;

public:

	Person();
	Person(string name, int age);

	~Person();
	
	
	string GetName();
	
	int GetAge();
	
	void SetName(string name);
	
	void SetAge(int age);
	

};

