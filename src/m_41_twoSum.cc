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
    vector<int> m_41_twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<r) {
            if(nums[l]+nums[r] == target) return vector<int>{nums[l], nums[r]};
            else if(nums[l]+nums[r] > target) r--;
            else l++;
        }

        return vector<int>{};
    }
};

TEST(m_41_twoSum, m_41_twoSum_1)
{
    Solution s;
    vector<int> in2 = {1, 2, 3};
    vector<int> ans2 = {1,2};
    EXPECT_EQ(s.m_41_twoSum(in2,3), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
