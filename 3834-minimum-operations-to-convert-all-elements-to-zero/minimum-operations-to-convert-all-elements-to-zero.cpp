class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        unordered_map<int, set<int>> map;

        int upperBound = 0;
        for (int i = 0; i < n; i++) {
            map[nums[i]].insert(i);
        }

        stack<int> st;
        st.push(n - 1);

        
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int j = nse[i];
            count++;
            
            vector<int> toErase;

            for (int curr : map[nums[i]]) {
                if (curr > j) break;
                toErase.push_back(curr);
            }
            for (int curr : toErase) {
                map[nums[i]].erase(curr);
                nums[curr] = 0;
            }
        }

        return count;
    }
};