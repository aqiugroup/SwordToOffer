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
    unordered_map<int, int> index;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if(preL > preR) {
            return nullptr;
        }

        int preRoot = preL; // 前序遍历中的第一个节点就是根节点
        int inRoot = index[preorder[preRoot]]; // 在中序遍历中定位根节点
        TreeNode* root = new TreeNode(preorder[preRoot]);// 先把根节点建立出来
        int leftChildNum = inRoot - inL;// 得到左子树中的节点数目

        root->left = helper(preorder, inorder, preL+1, preL+leftChildNum, inL, inRoot-1);
        root->right = helper(preorder, inorder, preL+leftChildNum+1, preR, inRoot+1, inR);

        return root;
    }
    TreeNode* m_06_buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            index[inorder[i]] = i; // 构造哈希映射，帮助我们快速定位根节点
        }

        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
};

TEST(m_06_buildTree, m_06_buildTree_1)
{
    Solution s;
    vector<int> in1 = {3,9,20,15,7};
    vector<int> in2 = {9,3,15,20,7};
    Tree ans2 {3,9,20,NULL,NULL,15,7};
    EXPECT_EQ(is_same_tree(s.m_06_buildTree(in1, in2), ans2.root), true);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
