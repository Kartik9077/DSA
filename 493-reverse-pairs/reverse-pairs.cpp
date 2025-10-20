#define all(x) (x).begin(), (x).end()
#define ll long long
class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        vector<vector<ll>> seg(4*n);

        function<void(int, int, int)> build = [&](int ind, int low, int high){
            if(low == high) return seg[ind].push_back(arr[low]*(1ll));
            int mid = (low+high)/2;
            build(2*ind+1, low, mid);
            build(2*ind+2, mid+1, high);
            seg[ind].resize(seg[2*ind+1].size() + seg[2*ind+2].size());
            merge(all(seg[2*ind+1]), all(seg[2*ind+2]), seg[ind].begin());
        };

        function<ll(int, int, int, int, int, ll)> query = [&](int ind, int low, int high, int l, int r, ll x)->ll{
            if(l>high || r<low) return 0ll;
            if(l<=low && high<=r){
                return seg[ind].end()-upper_bound(all(seg[ind]), x);
            }
            int mid = (low+high)/2;
            return  query(2*ind+1, low, mid, l, r, x) + query(2*ind+2, mid+1, high, l, r, x);
        };

        build(0, 0, n-1);
        ll res = 0;
        for(int j=1; j<n; j++){
            ll x = (2ll)*arr[j];
            res += query(0, 0, n-1, 0, j-1, x);
        }

        return res;
    }
};