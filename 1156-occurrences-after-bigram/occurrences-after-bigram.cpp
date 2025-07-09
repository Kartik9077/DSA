class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream ss(text);
        string w1, w2, word;
        vector<string> ans;
        ss >> w1 >> w2;
        while (ss >> word) {
            if (w1 == first && w2 == second) ans.push_back(word);
            w1 = w2;
            w2 = word;
        }
        return ans;
    }
};