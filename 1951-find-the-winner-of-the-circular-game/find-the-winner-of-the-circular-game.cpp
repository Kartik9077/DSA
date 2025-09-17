class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
         for(int i=1;i<=n;i++)q.push(i);
    
         while(q.size()>1){
            for(int i=1;i<=k;i++)
            { 
                if(i==k&&q.size()>1)q.pop();
                else if(q.size()>1){
            int p=q.front();
            q.pop();q.push(p);
                }
                else break;  
         }}
         return q.front();
    }
};