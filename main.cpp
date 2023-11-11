#include <iostream>
#include <string>
#include <unistd.h>
#include "Person.h"
#include <memory>
using namespace std;

class SmartInt
{
    private:
        int * pointer ;
    public :
    explicit SmartInt(int * ptr=nullptr) : pointer(ptr){}

    ~SmartInt(){
        delete pointer;
        cout << "poiinter deleted" << endl;
    }
    
    int& operator*() { return *pointer;}

    SmartInt& operator=(int* ptr) {
        // Clean up the existing pointer
        delete pointer;
        // Assign the new pointer
        pointer = ptr;
        return *this;
    }

 friend ostream& operator<<(ostream& os, const SmartInt& si) {
        os << si.pointer;
        return os;
    }

};

int main() {
    SmartInt pointer;

    #include <memory>

    std::unique_ptr<int> p1(new int(5));
    std::unique_ptr<int> p2= std::make_unique<int>(10);
    if (true) { // the pointer gets a nullptr
        cout << "pointer " << pointer << endl;
        pointer = new int; // calls the operator = overloading
        // will delete the former assigned int (in case there is one)

        *pointer = 5;
        cout << "pointer " << *pointer << endl;

        *pointer = 10;
        usleep(6000000);
    }
    cout << " pointer " << *pointer << endl;

    return 0 ;
}