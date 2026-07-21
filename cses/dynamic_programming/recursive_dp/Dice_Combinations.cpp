//problem link : https://cses.fi/problemset/task/1633

#include<bits/stdc++.h>
using namespace std;

#define int long long

static const int N = 1e6+20 , MOD=1'000'000'007;//fix : i firstly wrong a wrong MOD
int dp[N];

int add_mod(int a,int b){  //this function is also considering cases when adding negatives
  return (
      (a%MOD + MOD) +
      (b%MOD + MOD) + MOD
    )%MOD;
}

int goal;

int go(int sm){ //calc operations
if(sm==0)return 1;
if(sm<0)return 0;
if(~dp[sm]) return dp[sm];
  int ans=0;
  for(int i = 1; i<=6 ;i++){
    ans=add_mod(ans,go(sm-i));//fix : don't forget adding using the MOD
  }
  
  return dp[sm]=ans;
}

signed main(){
  memset(dp,-1,sizeof(dp));
  cin>>goal;//global variable
  cout<<go(goal);

}
