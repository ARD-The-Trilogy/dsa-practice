#include<bits/stdc++.h>
using namespace std;

void reverse_by_char(string str){
  stack <char> st;
  for(int i=0; i<str.size(); i++){
    st.push(str[i]);
  }
  while(!st.empty()){
    cout<<st.top();
    st.pop();
  }
  cout<<endl;
}

void reverse_by_words(string str){
  stack <string> st;
  for(int i=0; i<str.size(); i++){
    string word = "";
    while(str[i] != ' ' && i < str.size()){
      word += str[i];
      i++;
    }
    st.push(word);
  }
  while(!st.empty()){
    cout<<st.top()<<' ';
    st.pop();
  }
  cout<<endl;
}

int main(){
  string str;
  cout<<"Enter a sentence: ";
  getline(cin, str);              // sentence as input
  cout<<str<<endl;
  
  reverse_by_char(str);
  reverse_by_words(str);

  return 0;
}