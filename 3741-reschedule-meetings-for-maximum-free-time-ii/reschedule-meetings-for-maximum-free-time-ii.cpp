class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<vector<int>>events;
        for(int i=0;i<n;i++){
            events.push_back({startTime[i],endTime[i]});
        }
        vector<int>gaps;
        gaps.push_back(startTime[0]-0);
        
        for(int i=0;i<events.size()-1;i++){
            int diff=events[i+1][0]-events[i][1];
            gaps.push_back(diff);
        }
        gaps.push_back(eventTime-endTime[n-1]);
        for(auto &i:gaps)cout<<i<<" ";
        multiset<int>s(gaps.begin(),gaps.end());
        
        int ans=0;
        for(int i=0;i<events.size();i++){
            int space=events[i][1]-events[i][0], prev=gaps[i],next=gaps[i+1];
            s.erase(s.find(prev));
            s.erase(s.find(next));
            auto it=s.lower_bound(space);
            if(it!=s.end()){
                ans=max(ans,space+prev+next);
            }
            else{
                ans=max(ans,prev+next);
            }
            s.insert(prev);
            s.insert(next);
        }
        return ans;
    }
};