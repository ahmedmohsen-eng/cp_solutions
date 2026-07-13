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
    
    int x,y;
    cin>>x>>y;
    
    if(x==y) return void (cout<<0<<' '<<0<<'\n');//if same then they can reach zero , zero which have gcd of infinity
    //fix 2 : don't forget the output format 0 0 in that case
    
    
    // explanation :
    
    //difference is invariant (not changing)
    //gcd | x , gcd | y ==> gcd | abs(x-y)
    //so because gcd divides the difference the maximum is to be the difference itself
    
    //can we reach that both are multiples of dif?
    // yes , because :
    // after some moves x+k,y+k
    //if a+k % d =0 ===then==>> b+k= a+k - dif
    //                              which means if a+k is multiple of dif , and dif of course is a multiple of itself(x1)
    //                                      then of course the summation of both which is b+k is also a multiple
    //summary : making one of them divisible by dif so the second is automatically divisible by the dif also
    
    
    
    //what about number of steps:
    // we need both numbers to become multiples of dif so the ans is dif
    //there are two ways and you get the min of them:
    //1-   first is the lower  : x mod d       ,, if r is reminder when a is divisible by d so only decrease it by this reminder
    //                                              so this is the number of steps to reach the previous muliple of dif
    //2-   second is the upper : d - (x mod d) ,, this is the dif - reminder of a/d 
    //                                              because it is the number of steps to the next multiple of dif
    
    //but what if actually x is divible by dif?
    // don't become worry ,, the fomrula handles it : min ( x mod d , d-(x mod d) )
    //                                           so this part ^ becomes zero
    
    int dif=abs(x-y);
    int steps=min(x%dif , dif- x%dif );//fix 1 : don't forget the min
    cout<<dif<<' '<<steps<<'\n';
    
    
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

