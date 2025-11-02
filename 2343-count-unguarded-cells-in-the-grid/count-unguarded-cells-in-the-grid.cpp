class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        char mp[100000] = {0};
        for (auto& g : guards)
        {
            mp[g[0] * n + g[1]] = 2;
        }
        for (auto& w : walls)
        {
            mp[w[0] * n + w[1]] = 2;
        }
        for (auto& g : guards)
        {
            int x = g[0], y = g[1];
            for (int i = x - 1; i >= 0 && mp[i * n + y] != 2; i--)
            {
                mp[i * n + y] = 1;
            }
            for (int i = x + 1; i < m && mp[i * n + y] != 2; i++)
            {
                mp[i * n + y] = 1;
            }
            for (int j = y - 1; j >= 0 && mp[x * n + j] != 2; j--)
            {
                mp[x * n + j] = 1;
            }
            for (int j = y + 1; j < n && mp[x * n + j] != 2; j++)
            {
                mp[x * n + j] = 1;
            }
        }
        return (int)count(&mp[0], &mp[0] + m * n, 0);
    }
};