class Solution {
public:
    long long sum = 0;
    set<pair<int,int>> main;
    set<pair<int,int>> sec;
    void inserts(pair<int,int> p,int x){
        if(main.size()<x || p>*main.begin()){
            main.insert(p);
            sum+=1LL*p.first*p.second;
            if(main.size()>x){
                auto small = *main.begin();
                main.erase(small);
                sum-=1LL*small.first*small.second;
                sec.insert(small);
            }
        }
        else sec.insert(p);
    }
    void removes(pair<int,int> p,int x){
        if(main.find(p)!=main.end()){
            main.erase(p);
            sum-= 1LL*p.first*p.second;
            if(!sec.empty()){
                auto large = *sec.rbegin();
                sec.erase(large);
                main.insert(large);
                sum+= 1LL*large.first*large.second;
            }

        }
        else sec.erase(p);
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res;
        unordered_map<int,int> mp;
        int i =0;
        int j = 0;
        while(j<n){
            if(mp[nums[j]]>0){
                removes({mp[nums[j]],nums[j]},x);
            }
            mp[nums[j]]++;
            inserts({mp[nums[j]],nums[j]},x);
            if(j-i+1==k){
                res.push_back(sum);
                removes({mp[nums[i]],nums[i]},x);

                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                else{
                    inserts({mp[nums[i]],nums[i]},x);

                }
                i++;
            }
            j++;
        }
        return res;
    }
};