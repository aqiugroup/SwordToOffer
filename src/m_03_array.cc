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
    int sword2offer_m_03_array(vector<vector<int>> &nums, int target) {
        bool found = false;
        int m = nums.size();
        int n = m==0 ? 0 : nums[0].size();
        // if (m == 0) {
        //     return found;
        // }

        int row = 0;
        int col = n - 1;
        while(row < m && col >= 0) {
            if (nums[row][col] == target) {
                found = true;
                break;
            } else if (nums[row][col] < target) {
                ++row;
            } else {
                --col;
            }
        }

        return found;
    }
};

TEST(sword2offer_m_03_array, sword2offer_m_03_array_1)
{
    Solution s;
    vector<vector<int>> in3 = {{1,2,8},{2,4,9},{6,8,23}};
    bool ans2 = true;
    EXPECT_EQ(s.sword2offer_m_03_array(in3, 9), ans2);
}

TEST(sword2offer_m_03_array, sword2offer_m_03_array_2)
{
    Solution s;
    vector<vector<int>> in3 = {{1,2,8},{2,4,9},{6,8,23}};
    bool ans2 = false;
    EXPECT_EQ(s.sword2offer_m_03_array(in3, 10), ans2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
