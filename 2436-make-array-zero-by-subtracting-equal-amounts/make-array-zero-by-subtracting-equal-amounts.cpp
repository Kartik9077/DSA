class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        queue<int>pq;
        sort(nums.begin(),nums.end());
        for(auto it:nums){
            if(it!=0)pq.push(it);
        }
        int ans=0;
        while(!pq.empty()){
            ans++;
            int n=pq.front();pq.pop();
            int si=pq.size();
            while(si--){
                int k=pq.front();pq.pop();
                k-=n;
                if(k!=0)pq.push(k);
            }
        }
        return ans;
       
    }
};