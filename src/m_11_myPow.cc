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
    double m_11_myPow(double x, int n) {
        if(fabs(x)<1e-6) return 0;

        long b = n;
        double res = 1.0;
        if(b<0){
            x = 1/x;
            b=-b;
        }

        while(b>0) {
            if(b & 0x1 == 1) res *= x;
            x*=x;
            b >>=1;
        }

        return res;
    }
};

TEST(m_11_myPow, m_11_myPow_1)
{
    Solution s;
    double in1 = 2.0;
    int n = -2;
    double ans2 = 0.25;
    EXPECT_EQ(s.m_11_myPow(in1, n), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
