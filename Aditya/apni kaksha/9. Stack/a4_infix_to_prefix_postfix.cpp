#include<bits/stdc++.h>
using namespace std;

int precedence(char op){
  if(op == '^')
    return 3;
  else if(op == '*' || op == '/')
    return 2;
  else if(op == '+' || op == '-')
    return 1;
  else                    // '(' || ')'
    return -1;
}

string infix_to_postfix(string s){
  string res;
  stack <char> st;
  for(int i=0; i<s.length(); i++){
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
      res += s[i];
    }
    else if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      while(!st.empty() && st.top() != '('){
        res += st.top();
        st.pop();
      }
      if(!st.empty()){
        st.pop();
      }
    }
    else{
      while(!st.empty() && precedence(st.top()) > precedence(s[i])){
        res += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty()){
    res += st.top();
    st.pop();
  }
  return res;
}

string infix_to_prefix(string s){
  reverse(s.begin(), s.end());
  for(int i=0; i<s.length(); i++){
    if(s[i] == '('){
      s[i] = ')';               // unlike java or python
    }                           // c++ strings are mutable
    else if(s[i] == ')'){
      s[i] = '(';
    }
  }
  // cout<<s<<endl;
  string res = infix_to_postfix(s);
  reverse(res.begin(), res.end());
  return res;
}


int main(){
  string infix_exp;
  cout<<"Enter infix expression: ";
  cin>>infix_exp;
  cout<<"postfix expression: ";
  cout<<infix_to_postfix(infix_exp)<<endl;
  cout<<"prefix expression: ";
  cout<<infix_to_prefix(infix_exp)<<endl;

  return 0;
}


// Enter infix expression: (a-b/c)*(a/k-l)
// postfix expression: abc/-ak/l-*
// prefix expression: *-a/bc-/akl