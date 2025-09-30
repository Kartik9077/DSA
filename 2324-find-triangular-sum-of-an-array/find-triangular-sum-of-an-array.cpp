class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int>q;
        for(auto it:nums)q.push(it);
        while(!q.empty()){
            int n=q.size();
            if(n==1)return q.front();
            int a=q.front();q.pop();
           for(int i=1;i<n;i++){
            int b=q.front();q.pop();
            q.push((a+b)%10);
            a=b;
           }
        }
        return q.front();
    }
};