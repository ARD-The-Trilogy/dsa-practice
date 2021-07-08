#include<bits/stdc++.h>
using namespace std;

int prefix_evaluation(string s){
  stack <int> st;
  for(int i=s.length()-1; i>=0; i--){
    if(s[i] >= '0' && s[i] <= '9'){       // operand
      st.push(s[i] - '0');
    }
    else{                                 // operator
      int op1 = st.top();
      st.pop();
      int op2 = st.top();
      st.pop();
      
      switch(s[i]){
        case '+':
          st.push(op1 + op2);
          break;
        case '-':
          st.push(op1 - op2);
          break;
        case '*':
          st.push(op1 * op2);
          break;
        case '/':
          st.push(op1 / op2);
          break;
        case '^':
          st.push(pow(op1, op2));
          break;
      }
    }
  }
  return st.top();
}

int postfix_evaluation(string s){
  stack <int> st;
  for(int i=0; i<s.length(); i++){
    if(s[i] >= '0' && s[i] <= '9'){    // operand
      st.push(s[i] - '0');
    }
    else{                              // operator
      int op2 = st.top();
      st.pop();
      int op1 = st.top();
      st.pop();
      
      switch(s[i]){
        case '+':
          st.push(op1 + op2);
          break;
        case '-':
          st.push(op1 - op2);
          break;
        case '*':
          st.push(op1 * op2);
          break;
        case '/':
          st.push(op1 / op2);
          break;
        case '^':
          st.push(pow(op1, op2));
          break;
      }
    }
  }
  return st.top();
}

int main(){
  string infix_exp, prefix_exp, postfix_exp;

  cout<<"Enter infix expression: 5+7-3*8/2+4-6"<<endl;
  // cin>>infix_exp;
  cout<<5+7-3*8/2+4-6<<endl;

  cout<<"Enter prefix expression: ";
  cin>>prefix_exp;
  cout<<prefix_evaluation(prefix_exp)<<endl;

  cout<<"Enter postfix expression: ";
  cin>>postfix_exp;
  cout<<postfix_evaluation(postfix_exp)<<endl;


  return 0;
}


// Enter infix expression: 7+4*5-2+0
// 25
// Enter prefix expression: -+7*45+20
// 25
// Enter postfix expression: 46+2/5*7+
// 32

// Enter infix expression: 5+7-3*8/2+4-6
// -2
// Enter prefix expression: -+-+57/*38246
// -2
// Enter postfix expression: 57+38*2/-4+6-
// -2