class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        int odd_count = 0;
        string mid_char = "";
        vector<int> half_counts(26, 0);

        // Calculate character frequencies for the first half
        for (int i = 0; i < 26; i++) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = string(1, i + 'a');
            }
            half_counts[i] = counts[i] / 2;
        }

        // If more than one character has an odd frequency, a palindrome is impossible
        if (odd_count > 1) return "";

        int m = n / 2;
        
        // Try to share a common prefix of length i with target, starting from the longest possible
        for (int i = m; i >= 0; i--) {
            vector<int> temp_counts = half_counts;
            bool possible = true;
            
            // Deduct counts needed to match target[0...i-1]
            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';
                temp_counts[c]--;
                if (temp_counts[c] < 0) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) continue;

            if (i == m) {
                // We matched the entire first half of target
                string H = target.substr(0, m);
                string rev_H = H;
                reverse(rev_H.begin(), rev_H.end());
                string P = H + mid_char + rev_H;
                if (P > target) return P;
            } else {
                // Find the smallest available character strictly greater than target[i]
                int target_char = target[i] - 'a';
                int best_char = -1;
                for (int c = target_char + 1; c < 26; c++) {
                    if (temp_counts[c] > 0) {
                        best_char = c;
                        break;
                    }
                }
                
                if (best_char != -1) {
                    temp_counts[best_char]--;
                    string H = target.substr(0, i) + (char)(best_char + 'a');
                    
                    // Fill remaining spots in increasing order to keep it lexicographically smallest
                    for (int c = 0; c < 26; c++) {
                        H += string(temp_counts[c], c + 'a');
                    }
                    
                    string rev_H = H;
                    reverse(rev_H.begin(), rev_H.end());
                    string P = H + mid_char + rev_H;
                    return P;
                }
            }
        }
        
        return "";
    }
};
