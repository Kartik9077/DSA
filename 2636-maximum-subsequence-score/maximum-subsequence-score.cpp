class Solution {
public:
    long long maxScore(vector<int>&a, vector<int>&b, int k) {
        int n=a.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({b[i],a[i]});
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long ans=0,sum=0;
        for(int i=0;i<n;i++){

        int f = v[i].first , s = v[i].second ;
            if(pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
            sum += s;
            pq.push(s);
            if(pq.size() == k ) ans = max(ans , 1LL*sum*f);
        }
        return ans ;

    }
};