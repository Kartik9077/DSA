class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int numberOfColours = colors.size();
        if (numberOfColours <= 1) return 0;
        pair<char, int> previousColour = {colors[0], neededTime[0]};
        char currentColour = 'a';
        int currentColourRemovalCost = 0;
        int cost = 0;
        for (int i = 1; i < numberOfColours; i++) {
            currentColour = colors[i];
            currentColourRemovalCost = neededTime[i];
            if (currentColour != previousColour.first) {
                previousColour.first = currentColour;
                previousColour.second = neededTime[i];
            }
            else {
                cost += min(neededTime[i], previousColour.second);
                previousColour.second = max(neededTime[i], previousColour.second);
            }
        }
        return cost;
    }
};