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
    bool m_18_isSubStructure(TreeNode* A, TreeNode* B) {
// 思路： 递归， 先找到根节点相等的，进行子树比较； 不满足则继续遍历A寻找根节点和B一样的
        if(!A || !B) return false;

        if (A->val == B->val && isChildTree(A->left, B->left) && isChildTree(A->right, B->right)) return true;

        return m_18_isSubStructure(A->left, B) || m_18_isSubStructure(A->right, B);
    }

    bool isChildTree(TreeNode* root1, TreeNode* root2) {
        if (root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr) {
            return false;
        }
        if (root1->val == root2->val) {
            return isChildTree(root1->left, root2->left) && isChildTree(root1->right, root2->right);
        } else {
            return false;
        }
    }
};

TEST(m_18_isSubStructure, m_18_isSubStructure_1)
{
    Solution s;
    Tree in1{1, 4, 2, 3};
    Tree in2{4};
    bool ans2 = true;
    EXPECT_EQ(s.m_18_isSubStructure(in1.root, in2.root), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
