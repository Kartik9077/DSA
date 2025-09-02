class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int op=0;
        int ans=0;
        set<int> s;
        for(int i=0;i<=n-k;i++){
            while(!s.empty() && *(s.begin())<i){
                int x=*(s.begin());
                s.erase(s.find(x));
            }
            op=(s.size()%2==0)?0:1;
            if((nums[i]==1 && op==0)||(nums[i]==0 && op==1)){
                continue;
            }
            else{
                ans++;
                s.insert(i+k-1);
            }
        }
        for(int i=n-k+1;i<n;i++){
            while(!s.empty() && *(s.begin())<i){
                int x=*(s.begin());
                s.erase(s.find(x));
            }
            op=(s.size()%2==0)?0:1;
            if((nums[i]==1 && op==0)||(nums[i]==0 && op==1)){
                continue;
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};