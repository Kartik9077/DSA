class Solution {
public:
    vector<int> getFactors(int num) {
        vector<int> factors;
        for (int f = 2; f * f <= num; ++f) {
            if (num % f == 0) {
                factors.push_back(f);
                while (num % f == 0) num /= f;
            }
        }
        if (num > 1) factors.push_back(num); 
        return factors;
    }

    int dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        visited.insert(node);
        int size = 1;
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                size += dfs(neighbor, graph, visited);
            }
        }
        return size;
    }

    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, vector<int>> factor_to_nums;
        unordered_map<int, vector<int>> graph;
        for (int num : nums) {
            vector<int> factors = getFactors(num);
            for (int factor : factors) {
                factor_to_nums[factor].push_back(num);
            }
        }
        for (auto& [factor, nodes] : factor_to_nums) {
            for (int i = 1; i < nodes.size(); ++i) {
                graph[nodes[i]].push_back(nodes[0]);
                graph[nodes[0]].push_back(nodes[i]);
            }
        }
        unordered_set<int> visited;
        int maxSize = 0;

        for (int num : nums) {
            if (!visited.count(num)) {
                int size = dfs(num, graph, visited);
                maxSize = max(maxSize, size);
            }
        }

        return maxSize;
    }
};