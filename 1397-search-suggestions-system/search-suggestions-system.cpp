class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       vector<vector<string>>res(searchWord.size());
        sort(products.begin(),products.end());
        list<string>all;
        for(const auto &s:products) all.push_back(s);
        for (int i = 0; i < searchWord.size();i++) {
            auto it = all.begin();
            while (it != all.end() ) {
                if (i < (*it).size() &&  searchWord[i] == (*it)[i]) {
                    if(res[i].size() < 3) res[i].push_back(*it);
                    ++it;
                } else {
                    it = all.erase(it);
                }
            }
        }

        return res;
        
    }
};