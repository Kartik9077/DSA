class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        
        unordered_map<int,int>mp_key,mp_value;
        int id=0;

        set<int>s;
        for(int i=0;i<n;i++) {
            s.insert(nums[i]);
            s.insert(nums[i]-k);
            s.insert(nums[i]+k);
        }

        for(auto x:s){
            if(mp_key.find(x)==mp_key.end()){
                mp_key[x]=id;
                mp_value[id]=x;
                id++;
            }
        }

        vector<int>diff(id+1,0);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[mp_key[nums[i]]]++;
            diff[mp_key[nums[i]-k]]++;
            diff[mp_key[nums[i]+k]+1]--;
        }
        int res=0;
        for(int i=0;i<=id;i++){
            if(i>0)diff[i]+=diff[i-1];
            int f=0;
            if(mp.find(i)!=mp.end()) f=mp[i];
            int x=diff[i]-f;
            res=max(res,f+min(numOperations,x));
        }
        return res;
    }
};