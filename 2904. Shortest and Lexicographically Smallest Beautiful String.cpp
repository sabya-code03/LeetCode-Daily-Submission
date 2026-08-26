class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string best = ""; // This will hold our final answer
        
        // i is the starting point of our substring
        for (int i = 0; i < s.length(); i++) {
            int ones = 0;
            string current = "";
            
            // j expands the substring starting from i
            for (int j = i; j < s.length(); j++) {
                current += s[j]; // Add the current character
                
                if (s[j] == '1') {
                    ones++;
                }
                
                // If we found exactly k ones, let's see if it's the new best
                if (ones == k) {
                    // We update 'best' if:
                    // 1. It is our first time finding a beautiful string (best == "")
                    // 2. The current string is shorter
                    // 3. The lengths are the same, but current is lexicographically smaller
                    if (best == "" || current.length() < best.length() || 
                       (current.length() == best.length() && current < best)) {
                        best = current;
                    }
                } 
                // If we exceed k ones, no need to keep checking further for this starting point
                else if (ones > k) {
                    break;
                }
            }
        }
        
        return best;
    }
};
