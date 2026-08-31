/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // We need at least 3 nodes to have a previous, current, and next node.
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1; // Start index at 1 since curr is the second node

        int first_cp = -1;
        int last_cp = -1;
        int min_dist = INT_MAX;

        while (curr->next) {
            // Check for local maxima or local minima
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first_cp == -1) {
                    // This is the very first critical point we've seen
                    first_cp = idx;
                } else {
                    // Compare current distance to the smallest we've seen so far
                    min_dist = std::min(min_dist, idx - last_cp);
                }
                // Update the last seen critical point to the current one
                last_cp = idx;
            }
            
            // Move pointers forward
            prev = curr;
            curr = curr->next;
            idx++;
        }

        // If min_dist is still INT_MAX, we found less than 2 critical points
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }

        // max_dist is always the gap between the first and last critical point
        return {min_dist, last_cp - first_cp};
    }
};
