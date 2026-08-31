class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        std::vector<std::pair<long long, int>> lcm_list;
        
        // 1. Precompute the LCM for every subset of coins (Inclusion-Exclusion setup)
        // mask goes from 1 to 2^n - 1 to represent all non-empty subsets
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bits = 0; // To count how many coins are in this subset
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                    bits++;
                }
            }
            // Odd number of coins = add (1), Even number of coins = subtract (-1)
            int sign = (bits % 2 == 1) ? 1 : -1;
            lcm_list.push_back({current_lcm, sign});
        }

        // 2. Binary Search
        long long low = 1;
        long long high = (long long)*std::min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            // 3. Count how many valid amounts are <= mid using PIE
            for (auto& p : lcm_list) {
                count += p.second * (mid / p.first);
            }

            if (count >= k) {
                ans = mid;       // We found enough multiples, but can we go smaller?
                high = mid - 1; 
            } else {
                low = mid + 1;   // Not enough multiples, we need a larger number
            }
        }

        return ans;
    }
};
