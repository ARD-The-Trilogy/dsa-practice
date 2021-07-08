#include<bits/stdc++.h>
using namespace std;

class Queue{
  public:
    stack <int> s1;

    void push(int val){
      cout<<"pushing "<<val<<endl;
      s1.push(val);
    }

    int pop(){
      if(!empty()){
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
          return x;
        }
        int item = pop();
        s1.push(x);
        return item;
      }
      return -1;
    }

    // int peek(){
    //   if(!empty()){
    //     if(s2.empty()){
    //       while(!s1.empty()){
    //         s2.push(s1.top());
    //         s1.pop();
    //       }
    //       cout<<"top value: "<<s2.top()<<endl;
    //       return s2.top();
    //     }
    //     cout<<"top value: "<<s2.top()<<endl;
    //     return s2.top();
    //   }
    //   return -1;
    // }

    bool empty(){
      if(s1.empty()){
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
  // q.peek();
  cout<<"popping "<<q.pop()<<endl;
  cout<<"popping "<<q.pop()<<endl;
  cout<<"popping "<<q.pop()<<endl;
  cout<<"popping "<<q.pop()<<endl;

  return 0;
}