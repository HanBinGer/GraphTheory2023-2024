class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        if(y < x) swap(x,y);

        vector<int> ans(n);
        int cycle = y - x + 1, halfCycle = cycle - 1 >> 1, left = x - 1, right = n - y,
            line = left + right + 1 + (x != y);

        for (int i = 0; i < halfCycle; ++i)
            ans[i] = cycle * 2;
        if(cycle % 2 == 0){
            ans[halfCycle] = cycle;
            }

        for (int i = 1; i < line; ++i)
            ans[i - 1] += (line - i) * 2;
        if (x != y) {
            ans[0] -= 2;
            for (int i = 1; i <= left; i++)
                    ans[i] -= 2;
            for (int i = 1; i <= right; i++)
                    ans[i] -= 2;
        }

        for (int tail : {left, right}) {
            for (int i = 1; i < tail + halfCycle; i++)
                ans[i] += 4 * min({tail, halfCycle, i, tail + halfCycle - i});
            if (cycle % 2 == 0)
                for (int i = 1; i <= tail; i++)
                    ans[i + halfCycle] += 2;
        }

        return ans;

    }
};