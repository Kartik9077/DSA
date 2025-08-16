class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int singleLength = words[0].length();
        int wordCount = words.size();
        int totalLength = singleLength * wordCount;
        if (s.size() < totalLength) return ans;

        unordered_map<string,int> wordFreq;
        for (string &w : words) {
            wordFreq[w]++;
        }

      
        for (int offset = 0; offset < singleLength; offset++) {
            int left = offset, count = 0;
            unordered_map<string,int> seen;

            for (int right = offset; right + singleLength <= (int)s.size(); right += singleLength) {
                string word = s.substr(right, singleLength);

                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

               
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, singleLength);
                        seen[leftWord]--;
                        left += singleLength;
                        count--;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);
                        
                        string leftWord = s.substr(left, singleLength);
                        seen[leftWord]--;
                        left += singleLength;
                        count--;
                    }
                } 
                else { 
                    seen.clear();
                    count = 0;
                    left = right + singleLength;
                }
            }
        }
        return ans;
    }
};