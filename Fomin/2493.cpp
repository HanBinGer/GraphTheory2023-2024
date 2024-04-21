class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        vector<int> dis(n, 0);
        int ans = 0;
        vector<int> vis(n, 0);
        auto bfs = [&](int i)
                {
                    queue<int> q;
                    vis[i] = 1;
                    q.push(i);
                    int c = 1;
                    while (!q.empty()) {
                        int sz = q.size();
                        for (int k = 0; k < sz; k++)
                        {
                            int f = q.front();
                            q.pop();
                            for (auto x : adj[f])
                            {
                                if (!vis[x]) {
                                    vis[x] = c + 1;
                                    q.push(x);
                                }
                                else if (abs(vis[x] - c) != 1) {
                                    return -1;
                                }
                            }
                        }
                        c++;
                    }
                    return c - 1;
            };
        for (int i = 0; i < n; i++)
        {
            vis.assign(n, 0);
            dis[i] = bfs(i);
            if (dis[i] == -1) return -1;
        }
        vis.assign(n, 0);
        function<int(int)> dfs;
        dfs = [&](int i)
            {
                vis[i] = 1;
                int mn = dis[i];
                for (auto x : adj[i]) {
                    if (!vis[x]) {
                        mn = max(mn, dfs(x));
                    }
                }
                return mn;
            };
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                ans += dfs(i);
        }
        return ans;
    }
};