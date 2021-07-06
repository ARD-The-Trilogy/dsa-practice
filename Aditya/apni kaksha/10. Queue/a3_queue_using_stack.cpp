#include<bits/stdc++.h>
using namespace std;

class Queue{
  public:
    stack <int> s1;
    stack <int> s2;

    void push(int val){             // O(1)
      cout<<"pushing "<<val<<endl;
      s1.push(val);
    }

    void pop(){                     // O(n)
      if(!empty()){
        if(s2.empty()){
          while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
          }
          cout<<"popping "<<s2.top()<<endl;
          s2.pop();
          return;
        }
        cout<<"popping "<<s2.top()<<endl;
        s2.pop();
      }
    }

    int peek(){
      if(!empty()){
        if(s2.empty()){
          while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
          }
          cout<<"top value: "<<s2.top()<<endl;
          return s2.top();
        }
        cout<<"top value: "<<s2.top()<<endl;
        return s2.top();
      }
      return -1;
    }

    bool empty(){
      if(s1.empty() && s2.empty()){
        cout<<"Empty queue!"<<endl;
        return true;
      }
      return false;
    } 
};


int main(){
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.peek();
  q.pop();
  q.pop();
  q.pop();
  q.pop();

  return 0;
}