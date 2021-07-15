#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://www.codechef.com/JULY21C/problems/MINNOTES
*/

int gcd(int a, int b){
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int optimalGCD(vi &v, int n){
  int result = v[0];
  int first_val = v[0];
  int prev_res = result;
  int temp_res = result;
  int prev_val = v[0];
  int temp_val = v[0];
  int min_res = result;
  int change_index = 0;
  int change_value = v[0];

  for (int i = 1; i < n; i++){
    result = gcd(v[i], result);
    prev_res = temp_res;
    temp_res = result;
    prev_val = temp_val;
    temp_val = v[i];
    min_res = min(min_res, result);

    cout<<result<<" - "<<prev_res<<' '<<temp_res<<" => "<<v[i];

    if(result == prev_res){
      v[change_index] = change_value;
      change_index = 0;
      change_value = v[0];
      v[0] = result;
    }

    else if(result < prev_res){
      v[change_index] = change_value;
      // v[0] = first_val;
      // v[i-1] = prev_val;
      change_index = i;
      change_value = v[i];
      v[i] = prev_res;
      result = prev_res;
    }
    
    else{
      temp_res = prev_res;
    }
   
    cout<<" -> "<<v[i]<<endl;

    if(result == 1 && prev_res == 1){
      return 1;
    }
    
  }
  
  return result;
}


int optimal_denomination(vi &v, int n){
  int gcd = optimalGCD(v, n);
  int ans = 0;
  for(int i=0; i<n; i++){
    cout<<v[i]<<' ';
    ans += v[i]/gcd;
    // cout<<ans<<' ';
  }
  cout<<endl<<gcd<<" -> ";
  return ans;
}

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vi v(n);
    cout<<"Enter vect: ";
    for(int i=0; i<n; i++){
      cin>>v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int ans = optimal_denomination(v, n);

    cout<<" => "<<ans<<endl;
  }
  return 0;
}



// Enter n: 6       
// Enter vect: 2 4 6 8 10 7