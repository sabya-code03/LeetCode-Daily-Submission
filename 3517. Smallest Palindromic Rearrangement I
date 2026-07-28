class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string firstHalf = "";
        string middle = "";

        // Step 2 & 3: Build first half and find the middle character
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                // If frequency is odd, one character goes to the middle
                middle = string(1, i + 'a');
            }
            // Append half of the occurrences to the first half
            firstHalf += string(freq[i] / 2, i + 'a');
        }

        // Step 4: Reverse first half for the second half
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + middle + secondHalf;
    }
};
