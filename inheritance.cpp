#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{

private :
 string name ;
int age;

public:

string& getName() 
{
    return name;
}

int getAge()
{
    return age;
}

void SetAge (int age)
{

    this->age = age;
}

void SetName (string name)
{
    this->name = name;
}

~Person()
{
    cout << "PERSON DESTRUCTOR CALL" << endl;
    throw 1;
}

Person (string name , int age)
{
    this->name = name;
    this->age = age;
    cout << "PERSON CONSTRUCTOR CALL" << endl;
}

};


class Student : public Person {
private :
int classRoomCode;

public :
Student (string name , int age , int classRoomCode) : Person (name , age)
{
    this->classRoomCode = classRoomCode;
}

int getClassRoomCode()
{
    return classRoomCode;
}

void setClassRoomCode(int classRoomCode)
{
    this->classRoomCode = classRoomCode;
}
};

class Professor : public Person {
private :

vector<int> classRooms;

public :
Professor (string name , int age) : Person (name , age)
{   
    cout << "Prof constructor call" << endl ;
}

~Professor()
{
    cout << "PROFESSOR DESTRUCTOR CALL" << endl;
    try
    {
        throw  std::exception();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Professor (string name , int age , vector<int> classRooms) : Person (name , age)
{
    this->classRooms = classRooms;
    cout<< "PROFESSOR CONSTRUCTOR CALL" << endl ;
}

vector<int> &getClassRooms()
{
    return this->classRooms;

}

};

int main ()
{
    Professor p1("Mohamed" , 30) ;
    p1.getClassRooms().push_back(5);
    cout << "DEBUG" <<endl ;
    cout << p1.getClassRooms().at(0)<< endl << p1.getName() << endl << p1.getAge() << endl;

    string& n1 = p1.getName();

    cout << n1 << " --- "<< p1.getName()<<endl; 

    n1.pop_back();

    cout << n1 << " --- "<< p1.getName()<<endl; 
}
