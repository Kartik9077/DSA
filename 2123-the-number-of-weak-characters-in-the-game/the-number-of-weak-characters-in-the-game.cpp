class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
   sort(properties.begin() , properties.end() , [](const vector<int>& a , const vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        int res = 0, n = properties.size(), maxi = INT_MIN;
        for(int i = 0; i < n; ++i){
            if(properties[i][1] < maxi) ++res;
            else maxi = properties[i][1];
        }
        return res;
    }
};