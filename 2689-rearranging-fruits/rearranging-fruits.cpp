class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int,int>cnt;
        for(auto it:b1)cnt[it]++;
        for(auto it:b2)cnt[it]--;
        vector<int>last;
        for(auto&[k,v]:cnt){
            if(v%2)return -1;
            for(int i=0;i<abs(v)/2;i++){
                last.push_back(k);
            }
        }
        int minx=min(*min_element(b1.begin(),b1.end()),*min_element(b2.begin(),b2.end()));
          nth_element(last.begin(), last.begin() + last.size() / 2, last.end());
        return accumulate(last.begin(), last.begin() + last.size() / 2, 0ll, 
            [&](long long s, int x) -> long long { return s + min(2*minx, x); }
        );
    }
};