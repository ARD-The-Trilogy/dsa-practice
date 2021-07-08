#include<bits/stdc++.h>
using namespace std;

class student {
  public:
    string name;
    char gender;
    int age;

    student(){                                // we have to define default constructor
      cout<<"default constructor"<<endl;      // if we are defining any other constructor
    }                                         // otherwise, studend a; will throw error;

    student(string n, char g, int a){         // parameterized constructor
      name = n;
      gender = g;
      age = a;
      cout<<"parameterized constructor"<<endl;
    }

    student(student &a){                      // deep copy
      name = a.name;                          // default copy constructor => shallow copy
      gender = a.gender;
      age = a.age;                            
      cout<<"copy constructor"<<endl;
    }

    ~student(){                               // destructor
      cout<<"destructor called"<<endl;
    }

    void printInfo(){
      cout<<name<<' '<<gender<<' '<<age<<" years"<<endl;
    }
};


int main(){
  student a;                      // default constructor
  student b("Aditya", 'M', 21);   // parameterized constructor
  student c = b;                  // copy constructor
  
  a.printInfo();
  b.printInfo();
  c.printInfo();

  return 0;                       // destructor called * 3
}