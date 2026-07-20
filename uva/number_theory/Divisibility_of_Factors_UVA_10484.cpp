// بسم الله الرحمن الرحيم  
//متنساش تصل على النبي -صلى الله عليه وسلم- بس كده





//changing implementation not logic



#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ///////////////important ,, but take care of comparisons, for ex: min(x,0LL)


//(take care if #define int long long ==> is it used or no)

//don't forget pre processing is not processed each time

bool multi_cases = false ;///////////don't forget if not needed


int mod_mul(int x,int y,int mod){
    x=(x%mod +mod)%mod;
    y=(y%mod +mod)%mod;
    return (  ((__int128)x*y)%mod    );
}




void solve(const int& t){
    
    
    // vector<int>divisors(101);
    // for(int i=1;i<=100;i++){
    //     for(int j=i;j<=100;j+=i){
    //         divisors[j]++;
    //     }
    // }
    
    
    
    
    
    
    //to find numbers divisible by d
    //you can factor the number then find product of all powers+1 : power1+1 x power2+1 ...
        //except for the power of the divisor without +1 
            //to include only the cases of that it exists without the case that it is not taken completely
    //ok this is for divisors which are prime what about others?? mm..
    // mm.. if you saw what happened when choosing primes you calculated number of divisors/that factor
    //and the same when you choose composite you divide by this factor
    // to remove the possibility of removing it
    //for example if prime and it is 2 so you divide by 2 because before it waas calculated pow2 +1 
                            //which is number of 2s in factorization +1
                            // so if 2 has power of 2 it may be 2^0 or 2^1 or 2^3
                            //but you removed the option of removing it by dividing over it
                //same thing if you want to remove possible actions of removing it or elements lower
                // so divide by it so also lower are removed for ex:
                // if 6 so divide by /6 because you removed cases when 2 are removed completely
                                            // and you also removed cases when 3 are removed completely
    //







/*

idea :
factorial of n is 1x2x3x4...xn
so get factors of 1,2,3,4...,n and store them all  ,, this is the way to factorize the prime


after you get the factors of prime to know the number of divisors (not prime only) divisible by d:
    actually when you try to get the number of divisors you make the sum for each power :  power+1 : power1+1 * power2+2 * power3+1 * power4+1 ...............
    when you try to find divisors divisible by prime x , in that prime you don't include +1 , there is a reason for that : you remove the optino that it was not taken
            //also you should notice that if the number doesn't contain that factor so it is impossible to be divisible by it
    also when you want prime x and prime y to be always counted you remove the options of not taking them ...but how?
    visualization:
       for example factors of 36:2^2 * 3^2
                        which are :
                                        2^0  3^0
                                        2^1  3^1
                                        2^2  3^2
                                    now number of these divisors = 2x3=6
                                and now to get the number of divisors (from combinatorics) you multiply first options x second options
                        //now imagine i told you to tell me divisors divisible by 2
                            so you should remove option of 2^0 :
                                        2^1  3^0
                                        2^2  3^1
                                             3^2
                                        and when i tell you i want divisors divisible by 6 , the 6=2^1 * 3^1
                                            so you remove the option of not having any twos and the option of not having any threes:
                                                2^1  3^1
                                                2^2  3^2
                                            now number of these divisors is 2x2=4
                                        what if  said divisors divisible by 12 ?? 
                                                // you should think of removing option of not having any twos and not having any threes ,(and having only one of 2s) because 12 has two 2s in its factorization
                                            //so to do such thing:     
                                                                    2^2  3^1
                                                                         3^2
                                                        number of divisors : 2x1=2
                                    /////////////////////////mm.
                                    notice something??:
                                            you remove the factors of this number which you want to get divisors divisible by it
                                                        // or in other words you divide by it!!!!!!!!!
                                            // but you only need to check that in its factorization there is no prime factor has power with more value than the number it self which is for example 100!




*/


    
    
    auto factorize_all = [](int x){
        map<int,int>factors;
        for(int y = 1; y<=x; y++){//to loop over factorial numbers from 1 to x
            int copy=y;
            while(copy%2==0){
                copy/=2;
                factors[2]++;
            }
            for(int j=3;j*j<=y;j+=2){
                while(copy%j==0){
                    copy/=j;
                    factors[j]++;//j not copy
                }
            }
            if(copy>1) factors[copy]++;
        }
        
        
        return factors;
    };
    
    
    auto factorize = [](int x){
        map<int,int>factors;
        while(x%2==0){
            x/=2;
            factors[2]++;
        }
        for(int j=3;j*j<=x;j+=2){
            while(x%j==0){
                x/=j;
                factors[j]++;//j not copy
            }
        }
        if(x>1) factors[x]++;
        return factors;
    };
    
    
    //now iterate over all factors and print factor+1 for all     and remove factors of d
    // if somefactor in d exist and not exist in result of numbers so it becomes negative after summation
    //and if negative so it is zero
    
    int n,d;
    while(cin>>n>>d,(n!=0||d!=0)){//////fix : n!=0||d!=0     because n&&d means it terminates when any one is zero
        d = abs(d);//forgetting negative divisors handling
        map<int,int>all_factors=factorize_all(n);
        map<int,int>d_factors=factorize(d);
        for(auto&p:d_factors) all_factors[p.first]-=p.second;
        bool ok =true;
        int ans=1;
        for(auto&p:all_factors) {
            if(p.second<0) {ok=false;break;}
            ans*=(p.second+1);
        }
        if(!ok) cout<<0<<'\n';
        else cout<<ans<<'\n';
    }
    
    
}

signed main(){
    
    //turn of cin.exceptions(cin.failbit); when input is dynamic because it makes runtime error
    // cin.exceptions(cin.failbit);// important to know wrong input (sometimes)
    
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
