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
    int m_38_search(vector<int>& nums, int target) {
        // 搜索右边界 right
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] <= target) i = m + 1;
            else j = m - 1;
        }
        int right = i;

        // 若数组中无 target ，则提前返回
        if(j >= 0 && nums[j] != target) return 0;

        // 搜索左边界 right
        i = 0; j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] < target) i = m + 1;
            else j = m - 1;
        }
        int left = j;
        return right - left - 1;
    }
};

TEST(m_38_search, m_38_search_1)
{
    Solution s;
    vector<int> in2 = {1, 2,2,2, 3};
    int ans2 = 3;
    EXPECT_EQ(s.m_38_search(in2,2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
