/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        auto ret = image;
        int rows = image.size(), cols = image[0].size();
        vector<unsigned char> visited(rows * cols, 0);
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        int cmp = ret[sr][sc];
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            ret[t.first][t.second] = color;
            visited[(t.first * cols) + t.second] = true;
            
            if (t.first + 1 < rows && !visited[(t.first + 1) * cols + t.second] &&
                ret[t.first + 1][t.second] == cmp)
                q.push({ t.first + 1, t.second });
            if (t.first - 1 >= 0 && !visited[(t.first - 1) * cols + t.second] &&
                ret[t.first - 1][t.second] == cmp)
                q.push({ t.first - 1, t.second });
            if (t.second + 1 < cols && !visited[t.first * cols + t.second + 1] &&
                ret[t.first][t.second + 1] == cmp)
                q.push({ t.first, t.second + 1 });
            if (t.second - 1 >= 0 && !visited[t.first * cols + t.second - 1] &&
                ret[t.first][t.second - 1] == cmp)
                q.push({ t.first, t.second - 1 });
        }
        return ret;
    }
};
// @lc code=end

