#include<bits/stdc++.h>
using namespace std;

bool is_balanced(string s){
  stack <char> st;
  for(int i=0; i<s.length(); i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      if(!st.empty() && st.top() == '('){
        st.pop();
      }
      else if(st.top() == '{' || st.top() == '[')
        return false;
    }
    else if(s[i] == '}'){
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }
      else if(st.top() == '(' || st.top() == '[')
        return false;
    }
    else if(s[i] == ']'){
      if(!st.empty() && st.top() == '['){
        st.pop();
      }
      else if(st.top() == '(' || st.top() == '{')
        return false;
    }
  }
  if(st.empty())
    return true;
  return false;
}

int main(){
  string str;
  cout<<"Enter str: ";
  cin>>str;
  
  cout<<is_balanced(str);
  
  return 0;
}



// Enter str: [{()}]
// 1

// Enter str: [{(})]
// 0

// Enter str: 7+[6+4*(2/1)-6/2*{4-3}]
// 1