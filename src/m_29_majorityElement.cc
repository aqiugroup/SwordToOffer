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
    int m_29_majorityElement(vector<int> &nums) {
        int target = 0;
        int cnt = 0;
        for(auto& n : nums) {
            if(cnt==0) target = n;

            if(n==target) cnt++;
            else cnt--;
        }

        cout <<"target "<< target << endl;

        return target;
    }
};

TEST(m_29_majorityElement, m_29_majorityElement_1)
{
    Solution s;
    vector<int> in2 = {1, 2, 3, 2, 2};
    int ans2 = 2;
    EXPECT_EQ(s.m_29_majorityElement(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
