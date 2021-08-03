#include<bits/stdc++.h>
using namespace std;

/*
  https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
*/

void search_pattern(string txt, string pat){
  int n = txt.size();
  int m = pat.size();
  for(int i=0; i <= n-m; i++){
    int j;
    for(j=0; j < m; j++){
      if(txt[i+j] != pat[j]){
        break;
      }
    }
    if(j == m){
      cout<<"pattern found at index: "<<i<<endl;
    }
  }
}

void search_pattern_2(string txt, string pat){
  int n = txt.size();
  int m = pat.size();
  for(int i=0; i <= n-m; i++){
    if(txt.substr(i, m) == pat){
      cout<<"pattern found at index: "<<i<<endl;
    }
  }
}


int main()
{
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
    // string txt = "AABCCAADDEE";      // best case
    // string pat = "FAA";
    // string txt = "AAAAAAAAAAAAAAAAAB";  // worst case
    // string pat = "AAAAB";

    search_pattern_2(txt, pat);
    return 0;
}