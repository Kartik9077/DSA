class Solution {
public:
 typedef long long ll;
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long su) {
        sort(po.begin(),po.end());
        vector<int>p(sp.size());
        for(int i=0;i<sp.size();i++){
            ll target=(su+sp[i]-1)/sp[i];
            int low=0,high=po.size()-1;
            int idx=po.size();
            while(low<=high){
                 int mid = (low + high) / 2;
                if (po[mid] >= target) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            p[i]=po.size()-idx;
        }

        return p;

        
    }
};