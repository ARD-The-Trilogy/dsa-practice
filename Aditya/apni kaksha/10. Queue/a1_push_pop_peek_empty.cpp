#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000

class Queue{
  public:
    int front;
    int back;
    int arr[MAX_SIZE];
    
    Queue(){
      front = -1;
      back = -1;
    }

    void push(int val){
      if(back < MAX_SIZE-1){
        back++;
        arr[back] = val;
        if(front = -1)
          front++;
        cout<<"pushed "<<val<<endl;
        return;
      }
      cout<<"Queue overflow"<<endl;
    }

    void pop(){
      if(!empty()){
        cout<<"popped "<<arr[front]<<endl;
        front++;
      }
    }

    int peek(){
      if(!empty()){
        cout<<"peek value: "<<arr[front]<<endl;
        return arr[front];
      }
      return -1;
    }

    bool empty(){
      if(front == -1 || front > back){
        cout<<"empty Queue!"<<endl;
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