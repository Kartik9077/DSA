class Solution {
public:

    void nextSmallest(vector<int> &next, int size, vector<int> &vec)
    {
        stack<int> stk;
        stk.push(size);

        for(int i=size-1; i>=0; i--)
        {
            while(stk.top() != size && vec[stk.top()] >= vec[i]){
                stk.pop();
            }
            next[i] = stk.top();
            stk.push(i);
        }

    }

    void prevSmallest(vector<int> &prev, int size, vector<int> &vec)
    {
        stack<int> stk;
        stk.push(-1);

        for(int i=0; i<size; i++)
        {
            while(stk.top() != -1 && vec[stk.top()] >= vec[i]){
                stk.pop();
            }
            prev.push_back(stk.top());
            stk.push(i);
        }

    }

    int solve(vector<int> &vec, int size)
    {
        vector<int> next(size);
        vector<int> prev;

        nextSmallest(next, size, vec);
        prevSmallest(prev, size, vec);
        int ans = INT_MIN;

        for(auto it: vec)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        for(int i=0; i<size; i++)
        {
            ans = max(ans, (next[i]-prev[i]-1) * vec[i]);
        }

        return ans; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans = INT_MIN;
        vector<int> vec(matrix[0].size(), 0);

        for(int i=0; i<matrix.size(); i++)
        {
            int size = matrix[i].size();
            int temp = INT_MIN;

            for(int j=0; j<size; j++)
            {
                if(matrix[i][j] == '1')
                {
                    vec[j] += 1;
                } else {
                    vec[j] = 0;
                }
            }
            temp = solve(vec, size);
            ans = max(ans, temp);
        }

        return ans;
    }
};