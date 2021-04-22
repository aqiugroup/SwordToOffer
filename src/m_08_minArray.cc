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
    int m_08_minArray(vector<int> &numbers) {
        int left = 0, right = (int)numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right]) left = mid + 1;
            else if (numbers[mid] < numbers[right]) right = mid;
            else --right;
        }
        return numbers[right];
    }
};

TEST(m_08_minArray, m_08_minArray_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {4,5,6,1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.m_08_minArray(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
