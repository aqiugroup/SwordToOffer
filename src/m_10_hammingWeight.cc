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
    int m_10_hammingWeight(uint32_t n) {
        cout << n << endl;
        int cnt = 0;
        while(n) {
            n&=(n-1);
            cnt++;
        }

        return cnt;
    }
};

TEST(m_10_hammingWeight, m_10_hammingWeight_1)
{
    Solution s;
    uint32_t in2=0001011;
    int ans2 = 3;
    EXPECT_EQ(s.m_10_hammingWeight(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
