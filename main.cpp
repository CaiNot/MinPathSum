#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> grid = {{1,2,3}};

    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}