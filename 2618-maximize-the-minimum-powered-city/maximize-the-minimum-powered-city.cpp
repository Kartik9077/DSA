#define ll long long
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        ll low = 0,high = 1e14,ans = -1;

        vector<ll> ele(n+1,0);

        for(int i=0;i<n;++i) {
            ele[max(0,i-r)] += stations[i];
            ele[min(n,i+r+1)] -= stations[i];
        }
        for(int i=0;i<n;++i)   ele[i+1] += ele[i];

        auto possi = [&](ll req){
            ll cnt = 0;
            vector<ll> diff(n+1,0);
            for(int i=0;i<n;++i) {
                ll need = req - ele[i] - diff[i];;
                if(need > 0) {
                    cnt += need;
                    diff[i] += need;
                    diff[min(n,i+2*r+1)] -= need;
                }
                diff[i+1] += diff[i];
            }
            return cnt <= k;
        };

        while(low <= high) {
            ll mid = low + ( high - low ) / 2;
            if(possi(mid)) {
                ans = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        return ans;

    }
};