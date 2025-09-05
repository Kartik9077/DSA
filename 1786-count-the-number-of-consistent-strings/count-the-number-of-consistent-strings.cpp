class Solution {
public:
bool check(string a,unordered_set<char>st){
    for(auto it:a)if(st.find(it)==st.end())return 0;
    return 1;
}
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        unordered_set<char>st;
        for(auto it:allowed)st.insert(it);
        for(int i=0;i<words.size();i++){
            if(check(words[i],st))ans++;
        }
        return ans;
    }
};