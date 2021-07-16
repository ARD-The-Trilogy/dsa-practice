#include<bits/stdc++.h>
using namespace std;

class student {
  public:
    string name;
    char gender;
    int age;

    student(){                              // default constructor
      cout<<"default constructor"<<endl;
    }

    student(string n, char g, int a){       // parameterized constructor
      name = n;
      gender = g;
      age = a;
    }

    bool operator == (student &a){           // operator overloading
      if(name == a.name && age == a.age && gender == a.gender){
        return true;
      }
      return false;
    }
};


int main(){
  student a("Aditya", 'M', 21);
  student b("Phantom", 'M', 21);

  student c = a;                  // shallow copy (default copy constructor called)

  if(a == b){                     // operator overlaading is required
    cout<<"a & b are same"<<endl;
  }
  else{
    cout<<"a & b are not same"<<endl;
  }
  if(a == c){
    cout<<"a & c are same"<<endl;
  }
  else{
    cout<<"a & c are not same"<<endl;
  }

  return 0;
}