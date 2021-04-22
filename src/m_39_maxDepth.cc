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
    int m_39_maxDepth(TreeNode* root) {
        return helper(root);
    }

    int helper(TreeNode* root){
        if(!root) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        return max(left, right) + 1;
    }
};

TEST(m_39_maxDepth, m_39_maxDepth_1)
{
    Solution s;
    Tree in1{1, 4, 2, 3};
    int ans2 = 3;
    EXPECT_EQ(s.m_39_maxDepth(in1.root), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
