class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        // Array to store the count of subsequences ending with each character (a-z)
        vector<long long> end(26, 0);
        long long total = 0;
        
        for (char c : s) {
            // Remember how many sequences ended with this character previously
            long long old_end = end[c - 'a'];
            
            // The new count of sequences ending with 'c' is the total previous sequences + 1 (for 'c' alone)
            end[c - 'a'] = (total + 1) % MOD;
            
            // New total is the old total + new sequences ending in 'c' - duplicates
            total = (total + end[c - 'a'] - old_end) % MOD;
            
            // In C++, modulo of a negative number can be negative, so we adjust it
            if (total < 0) {
                total += MOD;
            }
        }
        
        return total;
    }
};
