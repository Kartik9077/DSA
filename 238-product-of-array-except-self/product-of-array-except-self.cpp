class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n,1);
        vector<int>left(n,1);
        for(int i=1;i<n;i++){
            right[i]=nums[i-1]*right[i-1];
        }
        for(int i=n-2;i>=0;i--){
            left[i]=left[i+1]*nums[i+1];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(right[i]*left[i]);
        }
        return ans;

    }
};