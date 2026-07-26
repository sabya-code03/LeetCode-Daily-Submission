class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort the array in ascending order
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Calculate the two possible maximum products
        int option1 = nums[n-1] * nums[n-2] * nums[n-3]; // Top 3 largest
        int option2 = nums[0] * nums[1] * nums[n-1];     // 2 most negative + 1 largest
        
        // Step 3: Return the maximum of the two options
        return std::max(option1, option2);
    }
};
