#include<bits/stdc++.h>
using namespace std;

#define fileio          freopen("in.txt","r",stdin);\
                        freopen("out.txt","w",stdout);
#define int long long

bool multi_=false;

void solve(const int& tt){
    //dbg
    // cerr<<"\n\nDebugging in test case no."<<tt<<" : \n";

  // step   step*2    step*3 ............
  //after mod
  // step % mod   step*2 % mod  ..............
  //
  // for example take step is 7 and mod is 10
  // see 
  //                   ↓ here is the first number divisble by 10 , so from here the period repeats 
  // 7 14 21  ....... 70
  // after mod    ===============================>> it doesn't matter if you increment all then take mod or you make it one by one ,, same result 
  //7 4 1 .... 0       all numbers achieved
  //           ^ end of period
  //the idea is that when the step has no common divisor with the mod except the one : gcd(step,mod)=1
        // then the first number divisible by mod is step*mod so before it there were (mod-1) numbers which are not divisible by mod so ans after modulus is zero at the (mod)th number
              // as said in the previous example:
                      // 7 14 ... 70
                      //           ^ the (mod)th number is the first which have result with zero after (%) 
  //after that the period repeats because of the logic of % depends on periods
  // so the only condition is to have __gcd(step,mod)=1



  // take care of representation mistakes
  
  

  
    int x,y;
    while(cin>>x>>y){
        cout<<setw(10)<<x<<setw(10)<<y<<"    ";
        if((__gcd(x,y)==1)) cout<<"Good Choice\n\n";
        else cout<<"Bad Choice\n\n";
    }
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    fileio;
    #endif
    int tt=1;
    if(multi_)cin>>tt;
    for(int i = 1 ; i <= tt ; i++){
        solve(i);
    }
    
    
}
