class Solution {
public:
    #define ll long long
    int checkRecord(int n) {
        ios_base::sync_with_stdio(0);
        vector<vector<ll>>dp(n+3,vector<ll>(3,0));
        ll mod = 1e9+7LL;
        dp[0][0] = dp[0][1] = dp[0][2] = 1LL;
        dp[1][0] = 2, dp[2][0] = 4;
        ll odds = 1, evens = 0;
        for(ll i = 1; i <= n; i++){
            if(i - 3 >= 0){
                dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-3][0]) % mod;
            }
            if(i % 2){
                dp[i][1] = (dp[i-1][0] + dp[i-1][2] + odds - evens) % mod;
                evens = (evens + dp[i][1]) % mod;
            }
            else{
                dp[i][1] = (dp[i-1][0] + dp[i-1][2] - odds + evens) % mod;
                odds = (odds + dp[i][1]) % mod;
            }
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod;
        }
        return dp[n][2];
    }
};