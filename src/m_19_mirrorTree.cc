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
    TreeNode* m_19_mirrorTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* tmp = root->left;
        root->left = m_19_mirrorTree(root->right);
        root->right = m_19_mirrorTree(tmp);

        return root;
    }
};

TEST(m_19_mirrorTree, m_19_mirrorTree_1)
{
    Solution s;
    Tree in1{1, 4, 2, 3};
    int ans2 = 1;
    auto a = s.m_19_mirrorTree(in1.root);
    EXPECT_EQ(a->val, ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
