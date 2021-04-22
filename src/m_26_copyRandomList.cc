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
    TreeNode* m_26_copyRandomList(TreeNode* head) {
        if(!head) return nullptr;
        // 1. clone TreeNode  拷贝结点放在当前结点后面
        //原地复制链表,且仅将right指针连接起来，例如A->B->C变成A->A'->B->B'->C->C'
        TreeNode* cur = head;
        while(cur) {
            TreeNode* newTreeNode = new TreeNode(cur->val);
            newTreeNode->right = cur->right;
            cur->right = newTreeNode;
            cur = newTreeNode->right;
        }

        cur=head;//cur指针复位
        // 2. connect sibling TreeNode 连接right和left指针
        while(cur) {
            if(cur->left) cur->right->left = cur->left->right;
            cur = cur->right->right;
        }

        // 3. reconnect node 拆分原始链表和clone链表
        // 将链表断开，例如A->A'->B->B'->C->C'变为A'->B'->C',且注意这一步应当将原链表复原。
        TreeNode* copyhead=head->right;
        TreeNode* copycur=copyhead;
        cur=head;
        while(cur) {
            cur->right = cur->right->right;
            cur = cur->right;
            if(copycur->right) {
                copycur->right = copycur->right->right;
                copycur = copycur->right;
            }
        }
        return copyhead;

    }
};

TEST(m_26_copyRandomList, m_26_copyRandomList_1)
{
    Solution s;
    Tree in1{1, 4, 2, 3};
    bool ans2 = true;
    EXPECT_EQ(is_same_tree(s.m_26_copyRandomList(in1.root), in1.root), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
