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
    bool m_24_verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size()-1);
    }

    bool helper(vector<int>& postorder, int i, int j) {
        if(i >= j) return true;
        int p = i;
        while(postorder[p] < postorder[j]) p++;
        int m = p;
        while(postorder[p] > postorder[j]) p++;

        return p == j && helper(postorder, i, m - 1) && helper(postorder, m, j - 1);
    }
};

TEST(m_24_verifyPostorder, m_24_verifyPostorder_1)
{
    Solution s;
    vector<int> in2 = {4, 8, 6, 12, 16, 14, 10};
    bool ans2 = true;
    EXPECT_EQ(s.m_24_verifyPostorder(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
