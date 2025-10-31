class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
           vector<int> freq(103, 0);
        vector<int> res(2);

        int idx = 0;

        for(auto &x : nums){

            freq[x]++;

            if(freq[x] > 1)
                res[idx++] = x;
        }


        return res;
    }
};