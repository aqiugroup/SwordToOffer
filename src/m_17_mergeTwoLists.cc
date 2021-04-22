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
    ListNode* m_17_mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 思路：从左到右遍历l1和l2，并比较大小,递归解决
        // 注意点：
        // 1 其中一个为空指针，则返回另一条链表即可

        if(!l1) return l2;
        else if(!l2) return l1;

        ListNode* newHead = nullptr;
        if(l1->val < l2->val) {
            // cout << "1 " << &l1;
            newHead = l1;
            newHead->next = m_17_mergeTwoLists(l1->next, l2);
        } else {
            // cout << "2 " << &l2;
            newHead = l2;
            newHead->next = m_17_mergeTwoLists(l1, l2->next);
        }

        // cout << "newHead " << &newHead  <<" " << newHead->val<< endl;

        return newHead;
    }
};

TEST(m_17_mergeTwoLists, m_17_mergeTwoLists_1)
{
    Solution s;
    List in1{1, 2, 3};
    List in2{2, 3, 5, 6};
    print_list(in1.head);
    print_list(in2.head);

    s.m_17_mergeTwoLists(in1.head, in2.head);
    // EXPECT_EQ(is_same_list(s.m_17_mergeTwoLists(in1.head, in2.head), in1.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
