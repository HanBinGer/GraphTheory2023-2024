class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int, double>>> g(n);
    for(int i=0; i<edges.size(); ++i) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
    vector<double> d(n, 0.0);
    d[start_node] = 1;
    priority_queue<pair<double, int>> q;
    q.push({1, start_node});
    while (!q.empty()) {
        auto [cur_d, v] = q.top();
        q.pop();
        if (cur_d < d[v])
            continue;
        for (auto&& [u, w] : g[v]) {
            if (d[u] < d[v] *  w) {
                d[u] = d[v] * w;
                q.push({d[u], u});
            }
        }
    }
    return d[end_node];
    }
};