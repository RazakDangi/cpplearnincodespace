#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Student {

    public :

    string name ;
    int id;
    vector<Student*> teammates;

    Student ()
    {
        name= "";
        id= 0;
    }

    Student (string name, int id)
    {
        this-> name = name;
        this-> id = id;
    }

        
    Student (Student&& other) noexcept 
    {
        cout<<"move constructor is cald"<<endl;
        // for non primary variables , we use MOVE
        this->name = move (other.name);
        this->teammates = move (other.teammates);
        
        // for primary variables (int float double ...) just copy and 
        this->id =other.id;
        other.id = 0;
    }
    
    void addTeammate (Student* st)
    {
        teammates.push_back (st);
    }

    void Display ()
    {
        cout << this->name << endl << this->id << endl;
        for(auto& st : teammates)
        {
            cout << st->name << endl << st->id << endl;
        }
    }
    
    Student& operator=(const Student& other) {
        cout<<"copy assignment is cald"<<endl;
           if (this != &other) {
            name = other.name;
            id = other.id;
        }
        return *this;
    }

    Student& operator=(Student&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            id = other.id;
            other.id = -1;
        }
        return *this;
    }
    
};

int main ()
{
    
    Student* st = nullptr;
    st=  new Student ("Mohamed", 1);

   
    
     Student* alicePtr = new Student("Alice", 1001);
    Student* bobPtr = new Student("Bob", 1002);

    st->addTeammate (alicePtr);
    st->addTeammate (bobPtr);
     Student st1 = move (*st);
    
    
    st->Display();
    st1.Display();

  /*  alicePtr->Display();
    bobPtr->Display();

   *alicePtr = move(*bobPtr);

    std::cout << "After move:\n";
    alicePtr->Display(); 
    bobPtr->Display();   
    
    delete bobPtr; 
    */
    return 0;
}