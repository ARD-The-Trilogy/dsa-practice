#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000

class Stack{
  public:
    int top;
    int arr[MAX_SIZE];

    Stack(){
      top = -1;
    }
    
    void push(int val){
      if(top < MAX_SIZE-1){
        arr[++top] = val;
        cout<<"pushed "<<val<<endl;
        return;
      }
      cout<<"stack overflow"<<endl;
    }

    void pop(){
      if(!empty()){
        cout<<"popped "<<arr[top]<<endl;
        top--;
      }
    }

    int peek(){
      if(!empty()){                // passed as function not object
        cout<<"peek value: "<<arr[top]<<endl;
        return arr[top];
      }
      return 0;
    }

    bool empty(){
      if(top == -1){
        cout<<"Empty stack!"<<endl;
        return 1;
      }
      return 0;
    }
};


int main(){
  Stack st;

  st.push(1);
  st.push(2);
  st.push(3);
  st.peek();
  st.pop();
  st.pop();
  st.pop();
  st.pop();

  return 0;
}