class Solution {
public:
    int n;
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            long long left  = 1LL * (a[1] - a[0]) * b[1] * (b[1] + 1);
            long long right = 1LL * (b[1] - b[0]) * a[1] * (a[1] + 1);
            return left < right; 
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        n = classes.size();
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap(
            classes.begin(),classes.end()
        );

        for(int i=0;i<extraStudents;i++){
            auto top = heap.top();
            heap.pop();
            top[0] += 1;
            top[1] += 1;
            heap.push(top);
        }
        double max_avg;
        while (!heap.empty()) {
            auto top = heap.top(); heap.pop();
            double gain = (double)(top[0]) / (top[1]);
            max_avg += gain;
        }

        return max_avg / n;
    }
};