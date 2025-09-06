class Solution {
public:
    double trimMean(vector<int>& arr) {
        int five_percent = (arr.size() * 5)/100;
        sort(arr.begin(), arr.end());
        while(five_percent-- > 0) {
            arr.erase(arr.begin());
            arr.pop_back();
        }
        double base = arr.size();
        double sum = 0;
        for(auto num : arr) {
            sum += num;
        }
        return sum / base;
    }
};