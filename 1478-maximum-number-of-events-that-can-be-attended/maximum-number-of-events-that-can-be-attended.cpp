class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> PQ;
        int i = 0, n = events.size(), ans = 0;
        for(int day = 1; day <= 100000; day++) {
            while(!PQ.empty() && PQ.top() < day) {
                PQ.pop();
            }
            while(i < n && events[i][0] <= day) {
                PQ.push(events[i][1]);
                i++;
            }
            if(!PQ.empty()) {
                PQ.pop();
                ans++;
            }
        }
        return ans;
    }
};