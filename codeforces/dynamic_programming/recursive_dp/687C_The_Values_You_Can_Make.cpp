//problem link : https://codeforces.com/contest/687/problem/C

//what you are actually solving is :
//for each subset of sum k:
    //find each subset sum of this subset
//then print all these sums

#include<bits/stdc++.h>
using namespace std;

#define int long long

static const int MOD = 1'000'000'007;

int add_mod(int a,int b){  //this function is also considering cases when adding negatives
  return (
      (a%MOD + MOD) +
      (b%MOD + MOD) + MOD
    )%MOD;
}

int n,k;

vector<int>coins;


//calc what ? , and what are the states?    ,transitions,base cases

bool ans[505];  //to store all possible sums
//the sum of subset of a subset can't be larger than the sum of the larger subset
        //and each chosen subset is with only sum of k , so its subsets sums can't exceed this k which is 500

bool dp[501][501][501];//it is used to store if we visited this state or no
            //but for storing answer the answer variable is enough
void go(int i,int s,int x){ 
    
    if(s>k) return;
    
    if(dp[i][s][x]) return;
    
    dp[i][s][x]=1;
    
    if(i==n){
        if(s==k) ans[x] = true;//sum of the subset itself
        return;
    }
    
    //you have 3 possibilities which are :
    //1 - not to take ,,   2- take in subset but not in the subset of subset  
                                    // ,, 3- take in subset but and in the subset of subset
    //if it was not taken in the subset so it is impossible to take in the subset of the subset
    
    go(i+1,s,x);
    go(i+1,s+coins[i],x);
    go(i+1,s+coins[i],x+coins[i]);
    
    
}

signed main(){
    memset(dp,0,sizeof(dp));
    
    cin>>n>>k;
    coins.assign(n,0);
    
    memset(ans, false, sizeof(ans));
    
    for(auto&x:coins)cin>>x;
    
    go(0,0,0);
    
    int cnt = count_if(ans, ans + k + 1, [](bool x) { return x; });//counting non zero elements
    cout<<cnt<<'\n';
    for(int i=0 ;i <=500 ;i++) if(ans[i]) cout<<i<<' ';
    
}
