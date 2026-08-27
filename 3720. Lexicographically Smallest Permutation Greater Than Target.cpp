class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        // Step 1: Count the frequency of each character in s
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string ans = "";
        int n = s.length();

        // Step 2: Traverse the target string
        for (int i = 0; i < n; i++) {
            int target_char_idx = target[i] - 'a';

            // Check if we can put a character STRICTLY GREATER than target[i]
            for (int j = target_char_idx + 1; j < 26; j++) {
                if (count[j] > 0) {
                    // Build the candidate string
                    string candidate = target.substr(0, i); // The matched prefix
                    candidate += (char)(j + 'a');           // The greater character

                    // Copy counts to safely append the rest
                    vector<int> temp_count = count;
                    temp_count[j]--;

                    // Append all remaining characters in alphabetical order
                    for (int k = 0; k < 26; k++) {
                        candidate += string(temp_count[k], (char)(k + 'a'));
                    }
                    
                    // Update our best answer
                    ans = candidate;
                    break; // We only want the smallest greater char, so break early
                }
            }

            // Step 3: Try to match target[i] exactly to continue the loop
            if (count[target_char_idx] > 0) {
                count[target_char_idx]--;
            } else {
                // If we can't match target[i], we can't build any longer prefixes
                break; 
            }
        }

        return ans; // Returns "" if no valid permutation was found
    }
};
