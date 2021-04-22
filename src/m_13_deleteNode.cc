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
    ListNode* m_13_deleteNode(ListNode* head, int val) {
// 原题需注意点： 待删除节点位于
// 1. 尾节点 ： 从头遍历到尾
// 2. 仅有1个头节点 ：删除后需要将头节点设为NULL
        if(!head) return nullptr;
        if(head->val == val) return head->next;
        ListNode *pre = head, *cur = head->next;
        while(cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        if(cur != nullptr) pre->next = cur->next;
        return head;
    }
};

TEST(m_13_deleteNode, m_13_deleteNode_1)
{
    Solution s;
    List in1{1, 4, 2, 3};
    int ans2 = 4;
    ListNode* ret = s.m_13_deleteNode(in1.head, 1);
    EXPECT_EQ(ret->val, ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
