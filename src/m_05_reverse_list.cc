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
    vector<int> m_05_reverse_list(ListNode* head) {
        // vector<int> ans;
        // while(head) {
        //     ans.push_back(head->val);
        //     head=head->next;
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;

        if (head == nullptr) return {};
        vector<int> a = m_05_reverse_list(head->next);
        a.push_back(head->val);

        return a;
    }
};

TEST(m_05_reverse_list, m_05_reverse_list_1)
{
    Solution s;
    List in1{1, 4, 2, 3};
    print_list(in1.head);
    vector<int> ans2 = {3, 2, 4, 1};
    EXPECT_EQ(s.m_05_reverse_list(in1.head), ans2);

    vector<int> out1 = s.m_05_reverse_list(in1.head);
    print_array(out1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
