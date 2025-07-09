class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> parents;
        int level = 0;
        int len_name = 0;
        bool isFile = false;
        int ans = 0;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '\n') {
                parents.resize(level);
                if (isFile) {
                    ans = max(ans, int(accumulate(parents.begin(), parents.end(), 0) + parents.size() + len_name));
                } else {
                    parents.push_back(len_name);
                }
                len_name = 0;
                level = 0;
                isFile = false;
            } else if (input[i] == '\t') {
                ++level;
            } else {
                ++len_name;
                if (input[i] == '.') {
                    isFile = true;
                }
            }
        }

        if (isFile) {
            parents.resize(level);
            ans = max(ans, int(accumulate(parents.begin(), parents.end(), 0) + parents.size() + len_name));
        }

        return ans;


    }
};