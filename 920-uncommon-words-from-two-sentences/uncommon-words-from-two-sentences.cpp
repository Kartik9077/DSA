class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
         unordered_map<string,int>mpp;
        istringstream iss(s1),iss2(s2);
        string word;
        while(iss>>word) mpp[word]++;
        while(iss2>>word) mpp[word]++;
        vector<string>res;
        for (auto& [w, count]:mpp) {
            if (count == 1) res.push_back(w);
        }
        return res;
    }
};