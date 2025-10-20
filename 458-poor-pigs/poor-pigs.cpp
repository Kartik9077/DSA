class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
         int attempts = minutesToTest / minutesToDie;
        int peppa = 0;

        while ( pow( attempts + 1, peppa ) < buckets ) peppa++;
        return peppa;
    }
};