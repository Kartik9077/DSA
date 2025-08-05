class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int s1=0,s2=0,e1=fruits.size()-1,e2=baskets.size()-1;
        int count=baskets.size();
        while(s1<=e1 && s2<=e2){
            if(fruits[s1]<=baskets[s2]){
                count--;
                baskets[s2]=-1;
                s2=0;
                s1++;
            }
            else if(s2>=e2){
                s1++;
                s2=0;
            }
            else{
                s2++;
            }
        }
        return count;
    }
};