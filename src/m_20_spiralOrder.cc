/**
 *
 * Copyright (c) 2021
 *
 * @file
 * @author   qzc (1457615966@qq.com)
 * @date     2019-11
 * @brief
 * @version  0.0.1
 *
 * Last Modified:  2021-02-20
 * Modified By:    qzc (1457615966@qq.com)
 *
 */
#include "headers.h"

class Solution
{
public:
    vector<int> m_20_spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = m==0? 0 : matrix[0].size();
        if (m == 0) return ans;
        // ans.resize(n*m);

        int i =0;
        int left = 0, right = n-1, up = 0, bottom = m-1;
        while(true) {
            for(i=left; i <= right; i++) ans.push_back(matrix[up][i]);
            up++;
            if(up>bottom) break;

            for(i=up; i<=bottom; i++) ans.push_back(matrix[i][right]);
            right--;
            if(left>right) break;

            for(i=right; i>=left; i--) ans.push_back(matrix[bottom][i]);
            bottom--;
            if(up>bottom) break;

            for(i=bottom; i>=up; i--) ans.push_back(matrix[i][left]);
            left++; 
            if(left>right) break;
        }

        return ans;
    }
};

TEST(m_20_spiralOrder, m_20_spiralOrder_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.m_20_spiralOrder(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
