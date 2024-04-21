class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<unsigned int> totPathes (n, 0);
        totPathes[0] = 1;
        vector<unsigned long long> d(n,  ULLONG_MAX);
        unsigned int MOD = 1e9 +7;
        d[0] = 0;
        vector <vector <pair <int, int>>> g(n+1);
        for(auto& x: roads) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<pair<unsigned long long, unsigned int>, vector<pair<unsigned long long, unsigned int>>, greater<pair<unsigned long long, unsigned int>>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [cur_d, v] = q.top();
            q.pop();
            if (cur_d > d[v])
                continue;
            for (auto&& [u, w] : g[v]) {
                if (d[u] > d[v] + w) {
                    totPathes[u] = totPathes[v];
                    d[u] = d[v] + w;
                    q.push({d[u], u});
                }
                else if (d[u] == d[v] + w)
                    totPathes[u] += totPathes[v];
                    totPathes[u] %= MOD;
            }
        }
        return totPathes[n-1];
    }
};