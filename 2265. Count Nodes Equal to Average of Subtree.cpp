class Solution {
private:
    int matching_node_count = 0;
    
    pair<int, int> postOrder(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);
        
        int total_sum = left.first + right.first + root->val;
        int total_count = left.second + right.second + 1;
        
        if (total_sum / total_count == root->val) {
            matching_node_count++;
        }
        
        return {total_sum, total_count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return matching_node_count;
    }
};
