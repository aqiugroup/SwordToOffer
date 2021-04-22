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
    int m_34_nthUglyNumber(int n) {
        // 不同丑数因子的丑数指针，初始化都指向第一个丑数
        int a = 0, b = 0, c = 0;
        // 记录丑数的数列，丑数的实质由丑数=某较小的丑数*某因子得到
        vector<int> dp(n, 0);
        // 初始化第一个丑数为1
        dp[0] = 1;
        // 遍历n个丑数
        for (int i = 1; i < n; i++) {
            // 2，3，5分别为三个丑数因子
            // 丑数因子的指针所指丑数*丑数因子=新的丑数
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            // 为保证丑数的升序排序，故需要取三个新丑数中最小的一个
            dp[i] = min(min(n2, n3), n5);
            // 被记录的丑数所使用的因子的丑数指针右移，方便该因子与其右一个丑数相乘得到更大的丑数
            if (dp[i] == n2) a++;
            if (dp[i] == n3) b++;
            if (dp[i] == n5) c++;
        }
        // 返回第n个丑数
        return dp[n - 1];
    }
};

TEST(m_34_nthUglyNumber, m_34_nthUglyNumber_1)
{
    Solution s;
    int ans2 = 12;
    EXPECT_EQ(s.m_34_nthUglyNumber(10), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
