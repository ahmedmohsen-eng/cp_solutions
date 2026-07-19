// بسم الله الرحمن الرحيم  
//متنساش تصل على النبي -صلى الله عليه وسلم- بس كده


//problem link : https://codeforces.com/contest/271/problem/B

//fixes fixed by ai

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
    
    
    
    //you need primes up to 1e5 due to problem limits
    int N=1e5;
    vector<int>primes;
    vector<bool>isprime(N+1000+1,true);//fix 2 : +100 to know there is at least additional prime number also as needed in logic
    //fix 3 : also keep + 1 in the size
    
    //fix 5 : forgetting 0 , 1
    isprime[0] = isprime[1] = false;
    
    //fix 4 : also keep + 1000 in the loops
    for(int i = 2 ;i <= N+1000 ; i++){//not i*i in the outer loop because you need all primes to be reachable إن شاء الله
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i*i; j<=N+1000 ;j+=i){
                isprime[j]=false;
            }
        }
    }
    
    //now you have primes
    
    
    
    //idea is to save in a matrix : number of steps for each number to reach the next prime
    //at one step operation of +1 is allowed
    
    //then to be prime you want at least one column or one row
        // so pass on columns and see the summation of steps at each
        // same thing for rows
        //
        //take the minimum
        //////////////////////you can use 2d prefix sum for that
    
    //
    
    int n,m;cin>>n>>m;
    //for prefix sum don't forget to initalize with 0s because of the first unused row and column
    vector<vector<int>>matrix(n+1,vector<int>(m+1,0));//is there a preserved keyword (matrix) ??
    
    for(int i = 1 ;i <= n ;i++){//1-indexed arrays are easier for prefix sum
        for(int j =1 ; j <= m; j++){
            cin>>matrix[i][j];
        }
    }
    
    for(int i = 1 ; i <=n ; i++){
        for(int j=1 ;j<=m ;j++){
            //if prime so number of operations need is zero
            //else the number of operations is the difference between it and the first prime after
            if(isprime[matrix[i][j]]) matrix[i][j]=0;
            else{
                auto it=upper_bound(primes.begin(),primes.end(),matrix[i][j]);
                matrix[i][j]=*it-matrix[i][j];
            }
        }
    }
    
    //prefix sum
    for(int i =1 ;i <=n ; i++){
        for(int j=1; j<=m ;j++){
            matrix[i][j]    = matrix[i][j]
                            + matrix[i - 1][j]
                            + matrix[i][j - 1]
                            - matrix[i - 1][j - 1];
        }
    }
    
    int ans=LLONG_MAX;//above this was used : #define int long long so ok it is long long also as a type
    //checking rows
    for(int i = 1; i <=n ;i++){
        int r1=i ,r2=i ,c1=1 ,c2=m ;//fix 1 : m not n
        int current     = matrix[r2][c2]
                        - matrix[r1 - 1][c2]
                        - matrix[r2][c1 - 1]
                        + matrix[r1 - 1][c1 - 1];
        
        
        ans=min(ans,current);
    }
    //checking columns
    for(int i =1 ; i <=m; i++){
        int r1=1 ,r2=n ,c1=i ,c2=i ;//fix 1 also : n not m
        int current     = matrix[r2][c2]
                        - matrix[r1 - 1][c2]
                        - matrix[r2][c1 - 1]
                        + matrix[r1 - 1][c1 - 1];
        
        
        ans=min(ans,current);
    }
    cout<<ans<<'\n';
    
    // actually you can have two matrices one with prefix horizontal 
    //     and the second (after taking it as a copy ) is vertical 
    //then run on columns alone and with rows alone
    
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
