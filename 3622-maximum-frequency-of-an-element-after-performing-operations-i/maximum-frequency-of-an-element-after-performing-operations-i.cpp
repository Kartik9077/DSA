class Solution {
private:
    int getRange(int& val, vector<int>& nums, int& k){
        int left = 0;
        int right = nums.size()-1;
        int mid;

        int target = val+k;
        int maxmIdx = 0;

        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]<=target){
                maxmIdx = mid;
                left = mid+1;
            }
            else right = mid-1;
        }

        left = 0;
        right = nums.size()-1;
        target = val-k;
        int minmIdx = 0;

        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]>=target){
                minmIdx = mid;
                right = mid-1;
            }
            else left = mid+1;
        }

        return maxmIdx-minmIdx+1;
    }

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> mpp;
        int result = 0;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>result) result = mpp[nums[i]];
        }

        sort(nums.begin(),nums.end());
        

        for(int i=nums[0]-k;i<=nums.back()+k;i++){
            int maxmFreq = getRange(i,nums,k);
            int repeats = (mpp.count(i) ? mpp[i]:0);
            int maxmOps = maxmFreq - repeats;

            if(maxmOps > numOperations){
                result = max(result,numOperations + repeats);
            }
            else result = max(result,maxmFreq);
        }

        return result;
    }
};