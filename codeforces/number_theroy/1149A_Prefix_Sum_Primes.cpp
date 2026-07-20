#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// bool good(int x){
//     string s=to_string(x);
//     int cnt=0;
//     int dec[10]={};
//     int n = s.size();
//     for(int i = 0 ; i < n;i++){
//         dec[s[i]-'0']=1;
//     }
//     for(int i = 0 ; i < 10 ; i++){
//         cnt+=dec[i];
//     }
//     if(cnt>2)return false;
//     return true;
// }




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

void solve(const int& t){
    
    //idea is to generate 1 1 1 2 2 2 2 2 then rest of 1s
    // or                 2 1 2 2 2 2 2 then rest of 1s,, 
    // wait we can check prime in both and put the one with largest 
    // or there is a greedy in choosing one of them?
    // what to do to get the highest of them or both are the same or what?
    
    //or it doesn't matter?
    
    //idea depends on that all primes are odd except 2 which is the only even
    
    int n; cin>>n;
    vector<int>v(n);
    for(auto&x:v)cin>>x;
    int twos=0,ones=0;
    for(auto&x:v){
        //constrains say that input contains 2s and 1s only !!
        if(x==1)ones++;
        else twos++;
    }
    if(ones+twos==1) cout<<v[0]<<' ';
    else if(ones==0){
        //fix : >0 to handle negatives
        while(twos-->0)cout<<2<<' ';
    } else if ( twos==0){//fix : == not = (silent error)
        while(ones-->0)cout<<1<<' ';
    } else{
        cout<<2<<' ';
        cout<<1<<' ';
        twos--,ones--;
        while(twos-->0)cout<<2<<' ';
        while(ones-->0)cout<<1<<' ';
    }
    
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

