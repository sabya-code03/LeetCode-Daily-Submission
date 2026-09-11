class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Step 1: Count available digits from the input
        vector<int> available(10, 0);
        for (int d : digits) {
            available[d]++;
        }
        
        int validCount = 0;
        
        // Step 2: Iterate through all possible 3-digit even numbers
        for (int num = 100; num <= 998; num += 2) {
            
            // Step 3: Extract the hundreds, tens, and ones digits
            int ones = num % 10;
            int tens = (num / 10) % 10;
            int hundreds = num / 100;
            
            // Tally up what this specific number requires
            vector<int> required(10, 0);
            required[ones]++;
            required[tens]++;
            required[hundreds]++;
            
            // Step 4 & 5: Verify against available digits and increment
            if (available[ones] >= required[ones] && 
                available[tens] >= required[tens] && 
                available[hundreds] >= required[hundreds]) {
                
                validCount++;
            }
        }
        
        return validCount;
    }
};
