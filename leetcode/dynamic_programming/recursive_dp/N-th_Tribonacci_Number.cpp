//problem link : https://leetcode.com/problems/n-th-tribonacci-number/description/

class Solution {
public:
    static const int N=38;
    int dp[N];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int tribonacci(int n) {

        if(n==0) return 0;
        if(n==1||n==2) return 1;

        if(~dp[n])return dp[n];

        return dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3); //don't forget to store not only returning

    }
};
