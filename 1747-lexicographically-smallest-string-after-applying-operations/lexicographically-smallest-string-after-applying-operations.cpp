class Solution {
    string addOperation(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            int val = (s[i] - '0' + a) % 10;
            s[i] = '0' + val;
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string ans = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            ans = min(ans, cur);

            string added = addOperation(cur, a);
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            string rotated = rotateOperation(cur, b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};