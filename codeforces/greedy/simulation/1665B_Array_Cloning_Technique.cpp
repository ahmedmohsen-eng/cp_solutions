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



bool multi_cases = true;////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<
// void solve(const int&t);

void solve(const int& t){
    
    //observations and thinknig (even false at the beginning):
    //of course order doesn't matter
    
    // mainly depeneds on number of distinct elements ==> answer depends on that
    // if there are duplicated elements so number of duplicated reduces the answer
    
    //there is something in pairty when number of distncit is even and when odd
    //
    //for ex: 4 3 2 1    ,, number of distinct : even (4) , == +1 ==>  , ans : (5) 
    //and :   2 5 7 6 3  ,, number of distinct : odd  (5) , == +2 ==>  , ans : (7)
    
    //when there are duplicates:
    //for ex: 0 1 3 3 7 0 ,,, number of distinct : 4 ,, ans : 6 .. oh ! it increased .. so wait it may be depending on :
                                                                                                    // size of array
                                                                                                    // and may be highest frequent


    // solution__________________________________________________________________________________________________
    
    // so finally greedy idea is to see the most frequent element and try to make all elements same as it
    // and firstly clone array and make variable to see available copies to swap (ava) 
    // and when ava is zero so take additional step of cloning with the current value of most freq (not the first value but it is updating each index)
    // and do this only when you are passing on an element which is not equal to the element with most freq. ( i mean not a copy of it )
    
    
    int n; cin>>n;
    map<int,int>freq;
    vector<int>v(n);
    int most_freq_el=-1e9/*due to problem constrains*/,mx_freq=0;
    
    int tmp;//put here to save constant time operations
    for(auto&x:v){
        cin>>x;
        freq[x]++;
        tmp=freq[x];// to save log time operations because its value may be needed multiple times
        if(tmp>mx_freq){
            mx_freq=tmp;
            most_freq_el=x;
        }
    }
    
    // int others=n-mx_freq;
    
    int ava=0; // fix : intialize with zero , because you only have 1 array at the beginining
    
    int ans=0;
    
    
    for(int i = 0 ; i < n; i++){
        if(v[i]!=most_freq_el){
            if(ava==0){
                ava=mx_freq;
                ans++;
            }
            ava--;
            mx_freq++;
            ans++;
        }
    }
    cout<<ans<<'\n';
    
    
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
