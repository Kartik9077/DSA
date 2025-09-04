class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-x)==abs(z-y))return 0;
        return abs(z-x)<abs(z-y)?1:2;
    }
};