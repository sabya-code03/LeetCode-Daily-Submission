class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the graph (Adjacency List)
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: Find all suspicious methods using BFS
        vector<bool> suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : adj[current]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Check the quarantine rule
        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0]; // Caller
            int v = inv[1]; // Callee
            
            // If a healthy method calls a suspicious method, we can't remove them
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }
        
        // Step 4: Collect the results
        vector<int> result;
        for (int i = 0; i < n; i++) {
            // Add if we can't remove anything, OR if the method is healthy
            if (!can_remove || !suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the graph (Adjacency List)
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: Find all suspicious methods using BFS
        vector<bool> suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : adj[current]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Check the quarantine rule
        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0]; // Caller
            int v = inv[1]; // Callee
            
            // If a healthy method calls a suspicious method, we can't remove them
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }
        
        // Step 4: Collect the results
        vector<int> result;
        for (int i = 0; i < n; i++) {
            // Add if we can't remove anything, OR if the method is healthy
            if (!can_remove || !suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
