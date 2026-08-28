class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;

        // Count frequency of elements in arr1
        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        // Add elements according to the order in arr2
        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        // Collect elements not present in arr2
        vector<int> remaining;

        for (auto& [x, count] : freq) {
            while (count > 0) {
                remaining.push_back(x);
                count--;
            }
        }

        // Sort remaining elements in ascending order
        sort(remaining.begin(), remaining.end());

        // Add remaining elements
        for (int x : remaining) {
            ans.push_back(x);
        }

        return ans;
    }
};