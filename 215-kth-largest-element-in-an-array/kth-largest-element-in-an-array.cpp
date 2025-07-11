class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums)pq.push(it);
        k-=1;
        while(!pq.empty()&&k){
            pq.pop();k--;
        }
        return pq.top();
        
    }
};