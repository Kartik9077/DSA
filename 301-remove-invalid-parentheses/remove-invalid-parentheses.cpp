class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int open = 0, closed = 0;
        for (char c : s) {
            if (c == '(') open++;
            else if (c == ')') {
                if (open > 0) open--;
                else closed++;
            }
        }

        set<string> banned;
        backtrack(s, 0, open, closed, banned);
        vector<string> who(banned.begin(), banned.end());
        return who;
    }

    void backtrack(string s, int idx, int open, int closed, set<string>& banned) {
        if (open == 0 && closed == 0) {
            if (isValid(s)) banned.insert(s);
            return;
        }
        for (int i = idx; i < (int)s.size(); i++) {
            if (i > idx && s[i] == s[i - 1]) continue;
            if (s[i] == '(' && open > 0) {
                string pat = s.substr(0, i) + s.substr(i + 1);
                backtrack(pat, i, open - 1, closed, banned);
            }
            if (s[i] == ')' && closed > 0) {
                string pat = s.substr(0, i) + s.substr(i + 1);
                backtrack(pat, i, open, closed - 1, banned);
            }
        }
    }

    bool isValid(string s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else if (c == ')') {
                if (bal == 0) return false;
                bal--;
            }
        }
        return bal == 0;
    }
};