class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>res,c,y;
        for(int i:arr){
            y={i};
            for(int j:c)y.insert(i|j);
            for(int j:c=y)res.insert(j);
        }
        return res.size();
    }
};