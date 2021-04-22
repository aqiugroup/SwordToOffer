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
    int m_09_fibonacci(int n) {
        if (n == 0 || n == 1) return n;
        int f0 = 0, f1 = 1;
        int ans = f0 + f1;
        for (int i = 2; i < n; ++i)
        {
            f0 = f1;
            f1 = ans;
            ans = f0 + f1;
            ans %= 1000000007;
        }
        cout << ans << endl;
        return ans;
    }
};

TEST(m_09_fibonacci, m_09_fibonacci_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 687995182;
    EXPECT_EQ(s.m_09_fibonacci(100), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
