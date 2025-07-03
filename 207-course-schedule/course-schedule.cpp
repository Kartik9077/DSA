class Solution {
public:
    bool topologicalsortCheck(unordered_map<int, vector<int>>& adj, int numCourse, vector<int>& indegree) {
        queue<int> qu;
        int count = 0;
        for (int i = 0; i < numCourse; i++) {
            if (indegree[i] == 0)
                qu.push(i);
        }
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            count++; 
            for (auto v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    qu.push(v);
                }
            }
        }
        return count == numCourse;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);  
            indegree[u]++;        
        }

        return topologicalsortCheck(adj, numCourses, indegree);
    }
};