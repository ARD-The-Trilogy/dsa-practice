#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://www.codechef.com/JULY21C/problems/CHEFORA
  https://www.geeksforgeeks.org/writing-power-function-for-large-numbers/
  https://leetcode.com/problems/count-good-numbers/discuss/1314505/modPow
*/

int cal_cat(int n){
  int i = 0;
  while(n / 10 != 0){
    i++;
    n /= 10;
  }
  return i;
}

long long int chefora(int n){
  int i = cal_cat(n);
  int len = 2*i + 1;
  long long int N = (n)*pow(10, i) + 0.5;   // pow(10, 2) ~ 99.999999 so...
  for(int k=i-1; k >= 0; k--){
    n /= 10;
    N += (n % 10)*(pow(10, k));
  }
  return N;
}

long long modPow(long long x, long long y, int mod = 1000000007)
{
    if (y == 0)
        return 1;
    auto p = modPow(x, y / 2);
    return p * p % mod * (y % 2 ? x : 1) % mod;
}


void solve(int l, int r, long long int chefora_sum[]){
  long long int base = chefora(l);
  long long int exponent = chefora_sum[r] - chefora_sum[l];
  cout<<modPow(base, exponent)<<endl;
}

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  long long int chefora_sum[100000] = {0};
  for(int i=1; i<=100000; i++){
    chefora_sum[i] = chefora_sum[i-1] + chefora(i);
    // cout<<chefora_sum[i]<<' ';
  }
  while(t--){
    int l, r;
    cout<<"Enter l r: ";
    cin>>l>>r;
    
    solve(l, r, chefora_sum);
  }
  return 0;
}