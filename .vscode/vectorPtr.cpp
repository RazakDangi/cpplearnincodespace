#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Person{
    string name;
    int age;
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
};

class Employee{
    private:
        vector<Person *> family;
        char* arr;
        int len;
    public:
        Employee(){
            arr = new char[5];
        }
        void addEmployee(char* name, int len){
            this->len = len;
            for(int i = 0; i < len; i++){
                *(arr+i) = *(name+i);
            }
        }
        void display(){
            cout<<"employee name is"<<endl;
            for(int i = 0; i < len; i++){
                cout<<*(arr+i)<<endl;
            }
            cout<<"employee family members are"<<endl;
            for(auto i = 0; i < family.size(); i++){
                cout<<"name is"<<family[i]->getName()<<"age is:"<<family[i]->getAge()<<endl;
            }
        }
        void addFamilyMember(Person *p){
            family.push_back(p);
        }
};

int main(){
    Employee v;
    v.addEmployee("rashid", strlen("rashid"));
    Person *p = new Person("farida", 31);
    v.addFamilyMember(p);
    v.display();
}