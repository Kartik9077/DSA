class Solution {
    bool check(string a,string b){
        int n=a.size();
        if(b.substr(0,n)==a&&b.substr(b.size()-n,n)==a)return 1;
        return 0;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[i],words[j]))c++;
            }
        }
        return c;
    }
};