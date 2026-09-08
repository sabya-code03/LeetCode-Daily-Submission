class Solution {
public:
    int countCommas(int n) {
        long long total_commas = 0;
        long long base = 1000;
        
        while (n >= base) {
            total_commas += (n - base + 1);
            base *= 1000;
        }
        
        return total_commas;
    }
};
