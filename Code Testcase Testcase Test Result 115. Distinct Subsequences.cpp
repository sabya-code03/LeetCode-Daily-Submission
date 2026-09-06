class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Use unsigned long long to avoid intermediate integer overflow
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // 1 way to form an empty string
        
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};
