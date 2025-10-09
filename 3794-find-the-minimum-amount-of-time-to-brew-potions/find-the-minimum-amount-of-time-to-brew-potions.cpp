class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana){
        int n = skill.size(), m = mana.size();
        vector<int> pre_sum = skill;
        for(int i=1; i<n; i++){
            pre_sum[i] += pre_sum[i - 1];
        }

        vector<long long> potions(n);
        for(int i=0; i<m; i++){
            long long start = potions[0];
            for(int j=0; j<n-1; j++){
                start = max(start, potions[j+1] - (1LL*pre_sum[j]*mana[i]));
            }
            for(int j=0; j<n; j++){
                potions[j] = start + (1LL*pre_sum[j]*mana[i]);
            }
        }

        return potions[n-1];
    }
};