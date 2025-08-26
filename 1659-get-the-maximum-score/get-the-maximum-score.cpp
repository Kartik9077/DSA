class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
    int mod = 1e9 + 7;
    long max1(0), max2(0);
    int i1 = nums1.size()-1, i2 = nums2.size()-1;

    while(i1 >= 0 && i2 >= 0){
        if (nums1[i1] > nums2[i2]){
            max1 = max1 + nums1[i1--];
        }
        else if (nums2[i2] > nums1[i1]){
            max2 = max2 + nums2[i2--];
        }
        else {
            max1 = max2 = max(max1, max2) + nums1[i1];
            i1--, i2--;
        }
    }
    while(i1>=0) max1 += nums1[i1--];
    while(i2>=0) max2 += nums2[i2--];


    return max(max1, max2) % mod;


    }
};