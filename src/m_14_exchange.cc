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
    vector<int> m_14_exchange(vector<int>& nums) {
// 思路： 头尾双指针
        int start = 0, end = nums.size()-1;
        while(start < end) {
            while (start < end && (nums[start] & 0x1) == 1) {
                start++;
            }

            while(start < end && (nums[end] & 0x1) == 0) {
                end--;
            }

            if(start < end) {
                int tmp = nums[start];
                nums[start] = nums[end];
                nums[end] = tmp;
            }
        }
        return nums;
    }

    vector<int> m_14_exchange(vector<int>& nums, bool (*func)(int)) {
// 思路：头尾双指针
// 扩展：使用函数指针 进行代码解耦
        int start = 0, end = nums.size()-1;
        while(start < end) {
            while (start < end && !func(nums[start])) {
                start++;
            }

            while(start < end && func(nums[end])) {
                end--;
            }

            if(start < end) {
                int tmp = nums[start];
                nums[start] = nums[end];
                nums[end] = tmp;
            }
        }
        return nums;
    }


};


TEST(m_14_exchange, m_14_exchange_1)
{
    Solution s;
    vector<int> in2 = {1, 2, 3};
    vector<int> ans2 = {1, 3, 2};
    EXPECT_EQ(s.m_14_exchange(in2), ans2);

}

bool isEven(int n) {
    return (n & 1) == 0;
}

TEST(m_14_exchange, m_14_exchange_2)
{
    Solution s;
    vector<int> in2 = {1, 2, 3};
    vector<int> ans2 = {1, 3, 2};
    EXPECT_EQ(s.m_14_exchange(in2, isEven), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
