class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        if(total_sum%3!=0)return false;
        int need_sum = total_sum/3, sum = 0;
        int need = 3;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==need_sum){
                sum = 0;
                need--;
            }
        }
        return need<=0;
    }
};