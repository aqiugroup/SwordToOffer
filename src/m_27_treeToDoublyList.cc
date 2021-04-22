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
    TreeNode *head, *pre;
    TreeNode* treeToDoublyList(TreeNode* root) {
        if(!root) return nullptr;

        dfs(root);

        pre->right = head;
        head->left = pre;//进行头节点和尾节点的相互指向，这两句的顺序也是可以颠倒的

        return head;
    }

    void dfs(TreeNode* cur) {
        if(!cur) return;

        if(cur->left) dfs(cur->left);

        //pre用于记录双向链表中位于cur左侧的节点，即上一次迭代中的cur,
        // 当pre==null时，cur左侧没有节点,即此时cur为双向链表中的头节点
        if(!pre) head = cur;
        //反之，pre!=null时，cur左侧存在节点pre，需要进行pre.right=cur的操作。
        else pre->right = cur;
        cur->left = pre;//pre是否为null对这句没有影响,且这句放在上面两句if else之前也是可以的。
        pre = cur;//pre指向当前的cur

        if(cur->right) dfs(cur->right);
    }
};

TEST(m_27_treeToDoublyList, m_27_treeToDoublyList_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    // EXPECT_EQ(s.m_27_treeToDoublyList(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
