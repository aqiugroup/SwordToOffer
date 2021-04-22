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
    int sum = 0;
    int helper(int n) {
        sum += n;
        n && helper(n-1);
        return 1;
    }
    int m_46_sumNums(int n) {
        helper(n);
        return sum;
    }
};

TEST(m_46_sumNums, m_46_sumNums_1)
{
    Solution s;
    int ans2 = 15;
    EXPECT_EQ(s.m_46_sumNums(5), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
