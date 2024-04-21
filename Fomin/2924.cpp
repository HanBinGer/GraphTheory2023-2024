class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<char> isChamp(n,1);
        for(auto &edge : edges){
            isChamp[edge[1]] = 0;
        }
        if(reduce(isChamp.begin(),isChamp.end())>1){
                return -1;
            }
        return find(isChamp.begin(), isChamp.end(), 1) - isChamp.begin();
    }
};