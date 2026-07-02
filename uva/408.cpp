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
                      //           ^ the (mod)th number is the first which have result with zero after (%) ,, because gcd(step,mod)=1
  
    
  //after that the period repeats because of the logic of % depends on periods
  // so the only condition is to have __gcd(step,mod)=1


  //
  // this happens because if you see numbers :
  // 7x1  7x2 7x3 7x4 .........  7x10 (=70)
  //so numbers before 7x10 are not divisible by 10 
  //because 7 itself has no common divsiors with 10 that complement with any of previous elements of 10 to make it perfectly divisble by 10 achiving % = 0
  //and of course (NO) elements before 10 are divisible by 10
  //
  //so because there may be be elements before 10 which : 10 are divisible by them  .. i mean may be 10%x=0 but what matters is x%110=0 not vice versa
  // but the 7*that element is not divisible by 10


  

  // take care of representation mistakes
  
  

  
    int x,y;
    while(cin>>x>>y){          // number of lines are not determined
        cout<<setw(10)<<x<<setw(10)<<y<<"    ";    // the setw(x) makes x spaces and then fill from the right column starting at column number x
                                                                // for example if setw(10)
                                                                    // .........1     << i mean spaces instead of points  , here only one space consumed out of 10
                                                                    // ........10     << here one space was consumed because it is a 2-digits number
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








//if you didn't understand explanation here is one by copilot:

    /*
     * PROBLEM INSIGHT:
     * We need to determine if step sizes x and y will eventually both land on 
     * the same line after some number of steps.
     * 
     * MATHEMATICAL PRINCIPLE:
     * Consider sequences: x, 2x, 3x, ... (mod total) and y, 2y, 3y, ... (mod total)
     * 
     * Example with x=7, mod=10:
     *   Sequence: 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, ...
     *   After mod: 7, 4, 1, 8, 5, 2, 9, 6, 3, 0, ...
     *   
     * The period is determined by gcd(x, mod):
     * - If gcd(x, mod) = 1 (coprime): period = mod, covers all residues 0 to mod-1
     * - If gcd(x, mod) > 1: period < mod, covers only gcd(x, mod) residues
     * 
     * WHY COPRIME MATTERS:
     * Two sequences will hit the same point (% 0) if and only if:
     * gcd(x, y) = 1
     * 
     * When gcd(x, y) = 1:
     * - The two step sizes are coprime
     * - They will eventually synchronize and land on the same line
     * - This is a "Good Choice" for the problem
     * 
     * When gcd(x, y) > 1:
     * - They share common factors
     * - They will never synchronize properly
     * - This is a "Bad Choice"
     */
  
