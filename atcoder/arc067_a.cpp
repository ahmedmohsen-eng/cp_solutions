// بسم الله الرحمن الرحيم  
//متنساش تصل على النبي -صلى الله عليه وسلم- بس كده

//problem link :
  // https://atcoder.jp/contests/arc067/tasks/arc067_a

#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ///////////////important ,, but take care of comparisons, for ex: min(x,0LL)


//(take care if #define int long long ==> is it used or no)

//don't forget pre processing is not processed each time

bool multi_cases = false ;


int mod_mul(int x,int y,int mod){
    x=(x%mod +mod)%mod;
    y=(y%mod +mod)%mod;
    return (  ((__int128)x*y)%mod    );
}


void solve(const int& t){
    //dbg:
    // cerr<< "\ntest case no." << t << " debugging : \n";
    //end_dbg
    
    int n; cin>>n;
    //idea is to gain the factors for each number
    //and then iterate on each i from 1 to n which are factorial numbers
        // and then increase map[x] for all factorails of i ,,,,,,to save powers
    //then initalize result=1
    // and loop on all prime factorials 
        // and muliplty(with mod) by the power+1
    
    vector<int>lpf(n+1,0);//lowest prime factor
    vector<bool>isprime(n+1,true);
    vector<int>primes;     
    for(int i = 2; i <= n; i++){
        if(isprime[i]){
            lpf[i]=i;
            primes.push_back(i);
            for(int j=i*i; j<=n ;j+=i){
                isprime[j]=false;
                if(lpf[j]==0) lpf[j]=i;
            }
        }
    }
    
    //now you have lpf , isprime , primes
    
    
    map<int,vector<int>>factors;
    for(int i = 1 ; i<=n ;i++){ //NlogN
        int copy=i;//to avoid editing the index and breaking the loop
        
        while(copy!=1){
            factors[i].push_back(lpf[copy]);
            copy/=lpf[copy];
        }
        
    }
    
    map<int,int>ans;
    for(int i = 1; i <=n ;i++){
        for(auto&x:factors[i]){
            ans[x]++;
        }
    }
    
    
    int res=1;
    int mod=1e9+7;
    
    for(auto&p:ans){
        res=mod_mul(res,p.second+1,mod);
    }
    
    cout<<res<<'\n';
    
}

signed main(){
    
    cin.exceptions(cin.failbit);// important to know wrong input (sometimes)
    
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    // // //if output is too large let output be in terminal not in file to avoid crashing
    freopen("out.txt","w",stdout);
    #endif
    
    int test_cases=1;
    if(multi_cases)cin>>test_cases;
    for(int i = 1 ; i <= test_cases; i++){
        solve(i);
    }
    
    //test_cases are 1-indexed
    
    return 0;
}
