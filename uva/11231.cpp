#include<bits/stdc++.h>
using namespace std;

#define fileio          freopen("in.txt","r",stdin);\
                        freopen("out.txt","w",stdout);
#define int long long

bool multi_=false;

void solve(const int& tt){
    //dbg
    // cerr<<"\n\nDebugging in test case no."<<tt<<" : \n";
    
    //required how many chess boards ,, chess boards bottom right are always white and they are 8x8
    int n,m,c; // c is bottom right
        
    while(cin>>n>>m>>c && n!=0 ){ // read the problem well , because if wrong input ==> program terminates
        int rem= (c == 1 ? 1 : 0 ); 
        // why ? because if area is odd so there is always one colour more than the another one
            // and if it is starting with 1 so always the larger number will be of ones
                // by adding this one it will not do any effect if even because we do floor division (natural by integers)
                    //and if it was even adding one doesn't do any effect
        
        cout<<((n-7)*(m-7)+rem)/2<<'\n';
        //start of logic  is here then up is read not vice versa
        //you must have seven points up and seven points left (hor and ver)
            //without forgetting the case if area is odd and one colour number is larger than another
                                                                // this is shown above  
        
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
