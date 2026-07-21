//problem link : https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    static const int N = 45+1;//46
    int dp[N];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int climbStairs(int n) {
        if(~dp[n]) return dp[n];
        
        /*
        if(n<1) return 0;
        if(n==1) return 1;
        if(n==2) return 2;//fix : forgetting to set the base case when n == 2
        */
        ////instead : 
        if(n<=2) return n;//small optimization and actually it can not reach negatives with this so it is ok
        
        int ch1=climbStairs(n-1);
        int ch2=climbStairs(n-2);
    
        return dp[n] =ch1+ch2;

    }
};
