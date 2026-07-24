using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> uniqueNums;
        bool present[2048] = {false};
        
        // Step 1: Array se duplicates hata kar unique elements filter karna
        for (int x : nums) {
            if (!present[x]) {
                present[x] = true;
                uniqueNums.push_back(x);
            }
        }
        
        int n = uniqueNums.size();
        bitset<2048> pairXor;
        
        // Step 2: Sabhi possible 2-element combinations ka XOR store karna
        // i <= j allowed hai, isliye j ko i se start kiya hai
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[uniqueNums[i] ^ uniqueNums[j]] = 1;
            }
        }
        
        bitset<2048> tripletXor;
        
        // Step 3: Har pair-XOR value ko array ke teesre element ke sath XOR karna
        for (int v = 0; v < 2048; v++) {
            if (pairXor[v]) {
                for (int k = 0; k < n; k++) {
                    tripletXor[v ^ uniqueNums[k]] = 1;
                }
            }
        }
        
        // Step 4: bitset.count() directly total 'true' bits (unique values) de dega
        return tripletXor.count();
    }
};
