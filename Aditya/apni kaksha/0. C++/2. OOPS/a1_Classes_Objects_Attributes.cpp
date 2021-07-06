#include<bits/stdc++.h>
using namespace std;

class student {           // class
  private:
    int age;              // attribute
  public:
    string name;          // attribute
    string gender;        // attribute

    void setAge(int a){   // method
      age = a;
    }
    
    int getAge(){         // method
      return age;
    }

    void printInfo(){     // method
      cout<<name<<' '<<gender<<' '<<age<<" years"<<endl;
    }
};                        // ; is compulsory after }


int main(){
  student a;              // Object of class student // default constructor
  cout<<"name: ";
  cin>>a.name;
  cout<<"gender: ";
  cin>>a.gender;
  int age;
  cout<<"age: ";
  cin>>age;
  a.setAge(age);
  
  cout<<a.getAge()<<endl;

  a.printInfo();
}