//learnt from tutorial

#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

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



bool multi_cases = true;////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<
// void solve(const int&t);

void solve(const int& t){
    
    // 1000* 60*60*60 =214000000   approximately 2.14e8 which exceeds one second so think in thing lower than n^3
    // إن شاء الله : O (n^2 logn) or lower complexity solution is accepted
    
    
    //finding subsequences which have sum of totalsm-1
    // you can do this by deleting zeros and only one
    // so it is combinatorics problem
    
    int n; cin>>n;
    vector<int>v(n);
    for(auto&x:v)cin>>x;
    
    //putting all zeros and ones at the beginning
    sort(v.begin(),v.end()); // order doesn't matter in sequences
    
    
    
    
    // so it is 2^number of zeros * number of ones ==> this include empty subsequence in somecases so it is already counted
    //but if not ones so ans is zero
    
    int ones=0,zeros=0;
    
    for(auto&x:v){
        if(x==0) zeros++;
        else if(x==1) ones++;
        else break;//already sorted
    }
    
    if(!ones) return void (cout<<0<<'\n');
    // if no ones then skipped below code
    
    
    
    // to avoid pow precisions problems
    int cur=1;
    while(zeros--){
        cur*=2;
    }
    
    
    cout<< cur*ones<<'\n';
    
}


signed main(){
    // freopen("cost.in","r",stdin);       ///// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//forgot to remove it
    
    cin.exceptions(cin.failbit);// important to know wrong input (sometimes)
    ios::sync_with_stdio(0);cin.tie(0);
    
    /////////////////////////////////////////////////hackerrank hasn't defined ONLINE_JUDGE ************
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

