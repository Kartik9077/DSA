class Solution {
public:
int atmostK(vector<int>& nums, int k){
        int n=nums.size();  
        int cnt=0;
        int r=0;int l=0; 
        unordered_map<int,int>m;     
        while(r<n){
             m[nums[r]]++;
            while(m.size()>k){ 
                m[nums[l]]--;
                if(m[nums[l]]==0){ 
                    m.erase(nums[l]);
                }
                l++;
                    
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums,k)-atmostK(nums,k-1);
        
    }
}; 
