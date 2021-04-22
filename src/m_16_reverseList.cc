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
    ListNode* m_16_reverseList(ListNode* head) {
        ListNode* newHead = nullptr, *pre = nullptr, *cur = head;
        while(cur) {
            ListNode* next = cur->next;
            if (next == nullptr) newHead = cur;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return newHead;
    }
};

TEST(m_16_reverseList, m_16_reverseList_1)
{
    Solution s;
    List in1{1, 4, 2, 3};
    int ans2 = 3;
    EXPECT_EQ(s.m_16_reverseList(in1.head)->val, ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
