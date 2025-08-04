class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int count=0,n=fruits.size();
        int prev=-1,pc=0,first,second=-1;
        int maxCount=0;
        for(int i=0;i<n;i++){
         int s=m.size();

         if((m.find(fruits[i])!=m.end()) || s<2 ){
             m[fruits[i]]++;
             count++;
             if(s==0)first=fruits[i];
             else if(second==-1 || second==fruits[i]) second=fruits[i];
             else {
             first=second;
             second=fruits[i];
             }

             if(fruits[i]==prev || prev==-1) pc++;
             else pc=1;
            
         }
         else {
         maxCount=max(maxCount,count);
         count=pc+1;
         pc=1;
         m.erase(first);
         first=second;
         second=fruits[i];
         m[fruits[i]]++;
         }
         prev=fruits[i];

        }
        return max(maxCount,count);
    }
};