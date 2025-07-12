class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>arr(3,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        nums.clear();
        int k=arr.size();int i=0;
        while(i<k){
            while(arr[i]!=0){
                nums.push_back(i);
                arr[i]-=1;
            }
            i++;
        }
    

        
    }
};