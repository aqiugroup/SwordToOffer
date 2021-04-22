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
    int m_36_reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size()-1);
    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        // 终止条件
        if (l >= r) return 0;
        // 递归划分
        int mid = l + (r-l)/2;
        int res = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid+1, r);

        // 合并阶段
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                res += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            res += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return res;
    }
};

TEST(m_36_reversePairs, m_36_reversePairs_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> in2 = {4, 1, 2, 3};
    int ans2 = 3;
    EXPECT_EQ(s.m_36_reversePairs(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
