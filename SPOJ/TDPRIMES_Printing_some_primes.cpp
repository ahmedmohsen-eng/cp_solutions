#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ///////////////important ,, but take care of comparisons, for ex: min(x,0LL)

const char* yes = "YES\n";
const char* no = "NO\n";

bool is_prime(int n){
    bool ok = true;
    for(int i = 2 ; i*i <= n; i++){
        if(n%i==0){
            ok=false;
            break;
        }
    }
    return ok;
}


vector<int>factors;
void prime_factor(int n){
    for(int i = 2; i*i<=n ;i++){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }
    if(n>1)factors.push_back(n);//last one if prime
}

int no_divisors(int n){
    int cnt=0;
    for(int i = 2 ; i*i < n; i++){
        if(n%i==0){
            if (n/i==i) cnt++;
            else cnt+=2;
        }
    }
    return cnt;
}



vector<bool> sieve(int n){
    //bool vs char:
    //char is (sometimes) faster because it is bit by bit ,, but bool is bits beside each other
    //but when i tried both actually (bool) was faster in the sieve
    //this is because:
    //the sieve runs alot of times may be millions
    //which mean that char takes more memory so it much less fits in cpu caches 
    //so once the array becomes much larger than the array than the CPU's cache,
                                // memory bandwidth becomes a bottleneck
    //          So although each access to vector<bool> requires extra bit operations, 
    //              those bit operations are very cheap. The reduction in memory traffic can outweigh their cost.
    
    
    //idea is to mark zero and one as not prime
    //then
    //mark all multiples of numbers starting from 2 as not prime till n
    // and if true so it leave it , as it is prime because it was not marked before 
                //===> as if was not prime so it would be marked from primes before it
    
    
    //start from current_prime*2 (first muliple of it (of course no*1 because it is itself which is prime))
    //optimized to walk from current_prime*current_prime
    //then walk till you reach n
    
    vector<bool> isprime(n+1,true);//+1 to take the number itself 
    //after n+1 also this part is safe which is initializing 0 and 1
    isprime[0]=isprime[1]=0;
    for(int i=2 ; i <=n; i++){
        if(isprime[i]){
            //instead of writing 
            for(int j = i*i; j <= n ; j+=i){ //optimized instead of walking from i*2
            //why it is true , this is because:
            //The reason is that every multiple smaller than i^2 has already been marked by a smaller prime.
            //for example if you have i=5 if you looked at 3*5 , then actually it was marked by 3 muliples and so on...
                isprime[j]=false;
            }
        }
    }
    
    //complexity of sieve :
    //it was O(nlogn) 
    // but enhanced to nloglogn 
    // this happenedafter making it starting fromi*i instead of i*2
    
    //  n + n/3 + n/4 + n/5     it is called harmonic series which is equal to n Ln n (complexity of nlogn) 
    
    return isprime;
}




// int mod=1e9+7; 
// //using prime why in making answer smaller?? 
//          may be because it has no factors other than ones? 
//                  but why does this matter if right?? 
// or what??






//don't forget pre processing is not processed each time

bool multi_cases = false ;

void solve(const int& t){
    //dbg:
    // cerr<< "\ntest case no." << t << " debugging : \n";
    //end_dbg
    
    int N=1e8;// no +1 because we want less not less than or equal
    vector<bool> isprime = sieve( N );
    
    //logic for printing 1mod100 (1st,101st,201st,...) primes:
    cout<<2<<'\n';
    int cnt=1;                            // starting with cnt=1 as counted 2
    for(int i = 3 ; i < (int)1e8 ; i+=2){ //starting from 3 to check odds
        if(isprime[i]){
            cnt++;
            if(cnt%100==1) cout<<i<<'\n';
        }
    }
    
    //important
    //actually (sometimes) sequential access is faster than jumping more than one cell
    //sometimes looping with i++ is faster than i+=2 because cpu prefers sequential access
    
    
    
    //old logic : 
    // vector<int>kth_prime={2};//adding the first prime which is 2 and then walk on odds only to walk only n/2 instead of n
    // for(int i = 3 ;i < N ; i+=2){
    //     if(isprime[i])kth_prime.push_back(i);
    // }
    
    // for(int i=0 ; i<(int)kth_prime.size() ;i+=100){ //don't forget to check validity of index because here in this code you didn't introduce whether numbers are prime or not starting from 1e8
    //     cout<<kth_prime[i]<<'\n';
    // }
    
    
    //debugging to know how many primes are there for the current limit put in the sieve and the loop
    // cerr<<kth_prime.size()<<'\n';
    
    
}

signed main(){
    
    cin.exceptions(cin.failbit);// important to know wrong input (sometimes)
    
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    #endif
    
    int test_cases=1;
    if(multi_cases)cin>>test_cases;
    for(int i = 1 ; i <= test_cases; i++){
        solve(i);
    }
    
    //test_cases are 1-indexed
    
    return 0;
}
