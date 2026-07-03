//link: https://www.spoj.com/problems/EASYMATH/

#include<bits/stdc++.h>
using namespace std;

#define fileio          freopen("in.txt","r",stdin);\
                        freopen("out.txt","w",stdout);
#define int long long

bool multi_=true;


//can also be solved either bitmasking iterations or recursion
//here it is the solution using normal brute force iteration without bitmasking

//for avoiding overflow:
long long Lcm(long long x, long long y) {
    return x / __gcd(x, y) * y;
}


int ie_divison(int&n,int&a,int&d){
    
    
    int cnt2=0; //result
    for(int i = 0 ; i<2 ;i++){
        for(int j = 0 ; j<2 ;j++){
            for(int k =0 ; k<2 ;k++){
                for(int l=0 ; l<2 ; l++){
                    for(int m=0 ; m<2; m++){    
                        int dd=1, elementsCnt=0;  //dd here is the digit here (what matters is lcm, because it makes)
                        
                        if(i)dd= Lcm(dd, a) ,elementsCnt++;
                        if(j)dd= Lcm(dd, a+d) ,elementsCnt++;
                        if(k)dd= Lcm(dd, a+2*d) ,elementsCnt++;
                        if(l)dd= Lcm(dd, a+3*d) ,elementsCnt++;
                        if(m)dd= Lcm(dd, a+4*d) ,elementsCnt++;
                        
                        if(elementsCnt==0) continue; //skipping empty subset
                        
                        int sign=elementsCnt%2?1:-1; //when functino have odd inputs its sign is positive in inclusion exclusion principle
                        
                        cnt2+=sign*(n/dd);  // because numbers from 1 to n that are divisible by dd is n/dd
                        
                        
                    }
                }
            }
        }
    }
    
    
    return cnt2;
}


void solve(const int& tt){
    //dbg
    // cerr<<"\n\nDebugging in test case no."<<tt<<" : \n";
    
    int n,m,a,d;
    cin>>n>>m>>a>>d;
    if(n>m) swap(n,m);
    
    int before_n= ie_divison(n-1,a,d);
    int till_m=  ie_divison(m,a,d);
    int bad = till_m - before_n;
    int total=m-n+1;
    cout<<total-bad<<'\n'; //needed are numbers (not) divisible
    
    
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
