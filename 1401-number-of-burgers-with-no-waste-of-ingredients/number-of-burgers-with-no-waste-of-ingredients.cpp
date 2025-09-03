class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int jumbo = 0;
        int small = 0;

        for (int i = 0; i < cheeseSlices + 1; i++) {
            jumbo = i;
            small = cheeseSlices - i;
            if (4 * jumbo + 2 * small == tomatoSlices)
                return {jumbo, small};
        }

        return {};
    }
};