class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;
        
        // 1. Locate the targets
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }
        
        int left_index = min(min_idx, max_idx);
        int right_index = max(min_idx, max_idx);
        
        // 2. Evaluate the three strategies
        int front_only = right_index + 1;           
        int back_only = n - left_index;            
        int squeeze = (left_index + 1) + (n - right_index); 
        
        // 3. Find the minimum
        // Note: The curly braces {} allow std::min to compare more than two values
        return min({front_only, back_only, squeeze});
    }
    
};
