#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{

Protected :
    string name ;
    int age;

public:

virtual void Show ()
{
    cout << name << " is "<< age << " years old "<<endl;
}

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
    //cout << "PERSON DESTRUCTOR CALL" << endl;
}

Person (string name , int age)
{
    this->name = name;
    this->age = age;
    //cout << "PERSON CONSTRUCTOR CALL" << endl;
}

};


class Student : public Person {
private :
int classRoomCode;

public :
Student (string name , int age , int classRoomCode) 
{
    this->classRoomCode = classRoomCode;
    
    
    // now , we have access to name and age because the are being inherited as PROTECTED
    this->name = name ;
    this->age = age;
}

void Show () override
{
    cout << getName() << " is "<< getAge() << " years old " <<endl;
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

vector<int> getClassRooms() const
{
    return classRooms;
}

void Show ()
{
    cout << getName() << " is " << getAge() << " years old "<< endl;
    //cout << "His classes are : "<< getClassRooms().at(0) << endl;      
}

Professor (string name , int age) : Person (name , age)
{   
    //cout << "Prof constructor call" << endl ;
}

~Professor()
{
    //cout << "PROFESSOR DESTRUCTOR CALL" << endl;
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
    //cout<< "PROFESSOR CONSTRUCTOR CALL" << endl ;
}

vector<int> &getClassRooms()
{
    return this->classRooms;

}

};

int main ()
{
    vector<int> vec = {5 , 10000 ,100};
    Student s1 ("Ahmad" , 18 , 10000);
    Professor p1 ("Eslam", 30 ,  vec);

    Person * pointer = nullptr;
    pointer = &s1 ;// upcasting or static polymorphism
    // a pointer of parent class can point to objects of child classes
    
   // pointer->Show(); // this will not work because the pointer is of type Person   
  

    Person * pointer2 = &p1;
   // pointer2->Show();    

    vector<Person*> vec2;
    vec2.push_back(&s1);
    vec2.push_back(&p1);

    Student * s3 = static_cast<Student*>(vec2.at(0));
    s3->Show();

    Person * p3 = static_cast<Professor*>(vec2.at(0));
    if(p3 != nullptr)
    {
    p3->Show();
    }

    for (auto v: vec2)
    {
        v->Show();
        Student* castedv = dynamic_cast<Student*>(v); // static_cast
        if(castedv != nullptr){
         cout<< castedv->getClassRoomCode()<<endl;
        } 
        Professor* castedv2 = dynamic_cast<Professor*>(v);
        if(castedv2 != nullptr){
        cout<< castedv2->getClassRooms()[0]<<endl;
        }   
    }
    
    
}

/*Professor p1("Mohamed" , 30) ;
    p1.getClassRooms().push_back(5);
    cout << "DEBUG" <<endl ;
    cout << p1.getClassRooms().at(0)<< endl << p1.getName() << endl << p1.getAge() << endl;

    string& n1 = p1.getName();

    cout << n1 << " --- "<< p1.getName()<<endl; 

    n1.pop_back();

    cout << n1 << " --- "<< p1.getName()<<endl; */