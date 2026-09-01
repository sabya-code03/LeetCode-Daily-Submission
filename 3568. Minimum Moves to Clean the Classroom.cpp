class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        int litter_count = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        // Step 1: Find Start and assign an ID (0 to k-1) to each Litter
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }
        
        int target_mask = (1 << litter_count) - 1; 
        if (target_mask == 0) return 0; // No litter to clean
        
        // visited[row][col][mask] stores the maximum energy we had when reaching this state
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1)));
        
        // Queue stores: {row, col, current_mask, current_energy}
        queue<tuple<int, int, int, int>> q;
        q.push({start_r, start_c, 0, energy});
        visited[start_r][start_c][0] = energy;
        
        int moves = 0;
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Step 2: BFS Traversal
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c, mask, curr_energy] = q.front();
                q.pop();
                
                // If our mask has all 1s up to litter_count, we collected everything!
                if (mask == target_mask) return moves;
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    // Check grid boundaries and obstacles
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nxt_energy = curr_energy - 1;
                        if (nxt_energy < 0) continue; // Out of energy
                        
                        // Reset energy if stepping on 'R'
                        if (classroom[nr][nc] == 'R') {
                            nxt_energy = energy; 
                        }
                        
                        int nxt_mask = mask;
                        // If cell has litter, update the mask using Bitwise OR
                        if (litter_id[nr][nc] != -1) {
                            nxt_mask |= (1 << litter_id[nr][nc]);
                        }
                        
                        // Only add to queue if we arrive with MORE energy than previously recorded
                        if (nxt_energy > visited[nr][nc][nxt_mask]) {
                            visited[nr][nc][nxt_mask] = nxt_energy;
                            q.push({nr, nc, nxt_mask, nxt_energy});
                        }
                    }
                }
            }
            moves++;
        }
        
        return -1; // Impossible to clean all litter
    }
};
