class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int N = boxes.size();
        vector<int> dp(N + 1, INT32_MAX), ports(N + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dp[N] = 0; // base case
        ports[N] = 1;

        for (int i = N - 1, end = N, taken_boxes = 0, weight =0, last_port =boxes.back()[0]; i >= 0; --i) {
            const int port = boxes[i][0], w = boxes[i][1];
            weight += w;
            taken_boxes += 1;
            ports[i] = ports[i + 1] + (port != last_port);
            while (taken_boxes > maxBoxes || weight> maxWeight){
                taken_boxes -= end == N ? 0 : 1;
                weight -= end == N ? 0 : boxes[end][1];
                end -= 1;
            }
            while (pq.size() && pq.top().second > end) {
                pq.pop();
            }
            if (pq.size()) {
                const auto [key, other_box] = pq.top();
                dp[i] = min((ports[i] - ports[other_box] + 2) + key,2 + dp[i + 1]);
            }
            else {
                dp[i] = 2 + dp[i + 1];
            }     
            pq.emplace(dp[i + 1], i);
            last_port = port;
        }
        return dp[0];
    }
};
