class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        // Step 1: Pair each number with its original index
        vector<pair<int, int>> val_idx(n);
        for (int i = 0; i < n; ++i) {
            val_idx[i] = {nums[i], i};
        }
        
        // Step 2: Sort based on values
        sort(val_idx.begin(), val_idx.end());
        
        vector<int> res(n);
        int i = 0;
        
        // Step 3: Group elements and place them back
        while (i < n) {
            int j = i + 1;
            // Find the boundary of the current group
            while (j < n && val_idx[j].first - val_idx[j-1].first <= limit) {
                j++;
            }
            
            // Extract the original indices for this group
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(val_idx[k].second);
            }
            
            // Sort the original indices
            sort(indices.begin(), indices.end());
            
            // Place the sorted values into the sorted indices
            for (int k = i; k < j; ++k) {
                res[indices[k-i]] = val_idx[k].first;
            }
            
            // Move to the next group
            i = j;
        }
        
        return res;
    }
};
