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
    ListNode* m_15_getKthFromEnd(ListNode* head, int k) {
// 思路： 快慢指针
// 注意点：
// 1 当链表长度小于k使，应该返回nullptr
// 2 当链表长度为空
// 3 当链表长度为k时，应该就等于头指针
        ListNode* slow = head, *fast=head;
        int cnt = 1;
        while(fast != nullptr && fast->next != nullptr) {
            if(cnt == k) break;
            cnt++;
            fast = fast->next;
        }

        if(cnt < k) return nullptr;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

TEST(m_15_getKthFromEnd, m_15_getKthFromEnd_1)
{
    Solution s;
    List in1{1, 4, 2, 3};
    int ans2 = 2;
    ListNode* ret = s.m_15_getKthFromEnd(in1.head,2);
    EXPECT_EQ(ret->val, ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
