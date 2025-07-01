class Solution {
public:
  struct comp{
    bool operator()(pair<int,int>a,pair<int,int> b){
        if(abs(a.first-a.second)==abs(b.second-b.first))return a.first>b.first;
        return abs(a.first-a.second)>abs(b.first-b.second);
    }
  };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=*min_element(arr.begin(),arr.end());
        int m=*max_element(arr.begin(),arr.end());
        vector<int>ans;
        if(x<=n){
            int i=0;
            while(k--)ans.push_back(arr[i++]);

            return ans;
        }
        if(x>=m){
            int i=arr.size()-1;
            while(k--)ans.push_back(arr[i--]);

           sort(ans.begin(),ans.end());
            return ans;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto it:arr)pq.push({it,x});
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};