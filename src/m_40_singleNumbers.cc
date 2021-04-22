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
    vector<int> m_40_singleNumbers(vector<int>& nums) {
        // 先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
        int OR = 0;
        for(auto& n : nums) OR ^= n;

        // 在异或结果中找到任意为 11 的位。
        int lowbit = 1;
        // lowbit = OR & (-OR);
        while ((lowbit & OR) == 0) lowbit <<= 1;

        // 根据这一位对所有的数字进行分组。
        // 在每个组内进行异或操作，得到两个数字。
        int a = 0, b = 0;
        for (int n : nums)
            if (lowbit & n) a ^= n;
            else b ^= n;
        return vector<int>{a, b};
    }
};

TEST(m_40_singleNumbers, m_40_singleNumbers_1)
{
    Solution s;
    vector<int> ans1 = {1, 1, 3, 2,4,5,5,4};
    vector<int> ans2 = {3,2};
    EXPECT_EQ(s.m_40_singleNumbers(ans1), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
