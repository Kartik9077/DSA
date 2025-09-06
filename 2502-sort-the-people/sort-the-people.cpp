class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i=0;i<heights.size()-1;i++)
        {
            for(int j=i+1;j<heights.size();j++)
            {
                if(heights[i]<heights[j])
                {
                    swap(heights[i],heights[j]);
                    swap(names[i],names[j]);
                }
            }
        }
        return names;
    }
};