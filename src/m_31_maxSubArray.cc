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
    int m_31_maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] += max(nums[i-1], 0);
            res = max(res, nums[i]);
        }

        return res;
    }
};

TEST(m_31_maxSubArray, m_31_maxSubArray_1)
{
    Solution s;
    vector<int> in2 = {1, -2, 3};
    int ans2 = 3;
    EXPECT_EQ(s.m_31_maxSubArray(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
