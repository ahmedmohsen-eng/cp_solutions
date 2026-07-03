//link: https://atcoder.jp/contests/awc0105/tasks/awc0105_c

#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

bool good(int x){
    string s=to_string(x);
    int cnt=0;
    int dec[10]={};
    int n = s.size();
    for(int i = 0 ; i < n;i++){
        dec[s[i]-'0']=1;
    }
    for(int i = 0 ; i < 10 ; i++){
        cnt+=dec[i];
    }
    if(cnt>2)return false;
    return true;
}




bool cmp(pair<char,int>&p1,pair<char,int>&p2){
    return p1.second>p2.second;//write return right
}

//strong custom hash for antihacking
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template<class T1, class T2>
    size_t operator()(const pair<T1,T2>& p) const {
        uint64_t h1 = splitmix64(hash<T1>{}(p.first));
        uint64_t h2 = splitmix64(hash<T2>{}(p.second));
        return h1 ^ (h2 << 1);
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};



bool multi_cases = false;////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<
// void solve(const int&t);


        ////////////////logic start////////////////////// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // i used ai to learn how to solve this problem
              // i used it also in solving and completing the solution
void solve(const int& t){
    
    //dbg:
    // cerr<< "\ntest case no." << t << " debugging : \n";
    //end_dbg
    
    
    
    int n;cin>>n;
    string s;cin>>s;
    vector<int>v(n);
    for(int i=0 ; i < n;i++) v[i]=s[i];
    
    vector<int>prf_xor=v,suf_xor=v;
    for(int i = 1 ; i < n ;i++) prf_xor[i]^=prf_xor[i-1];
    for(int i = n-2 ; i>= 0 ; i--) suf_xor[i]^=suf_xor[i+1];
    
    
    int ans=0;
    //first index (index 0) is always at the first part, so start the second part from the second
    for(int i = 1 ; i < n; i++){
        int xl = prf_xor[i-1];
        int xr = suf_xor[i];
        
        //
        bool ok = true; // to check conditions
        const long long INF = 1e18; // to define the huge variable of infinity
        
        long long prev = INF;   // to initialize it to get minimum      
                        // ,, actually we need this because we must make sure that sequence of D is not decreasing
        
        for(int j = 0 ; j < n; j++){
            int A;
            if(j<i) A=v[j]^xr;
            else    A=v[j]^xl;
            
            //97≤A+D≤122
            // so 97-A<=D<=122-A
            // and there is an addititonal condition of : D >= 0
            
            long long L = max(0LL, 97LL - A);
            long long R = 122LL - A;
            
            // Largest value we are allowed to choose
            
            if(R<L || L>prev) {ok=false; break; } //checking r<l because if 10<=d<=7 so it is impossible
            prev=min(prev,R);
            
        }
        if(ok)ans++;
    }
    cout<<ans<<'\n';
    
}


signed main(){
    // freopen("cost.in","r",stdin);       ///// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//forgot to remove it
    
    cin.exceptions(cin.failbit);// important to know wrong input (sometimes)
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
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

