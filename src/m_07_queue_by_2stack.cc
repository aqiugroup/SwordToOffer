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
class CQueue {
public:
    CQueue() { }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if(s2.empty()) {
            return -1;
        }

        int top = s2.top();
        s2.pop();
        return top;
    }

    stack<int> s1;
    stack<int> s2;
};

class Solution
{
public:
    int m_07_queue_by_2stack(vector<int> &nums) {

        CQueue* obj = new CQueue();
        obj->appendTail(1);
        int param_2 = obj->deleteHead();

        return 1;
    }
};

TEST(m_07_queue_by_2stack, m_07_queue_by_2stack_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.m_07_queue_by_2stack(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
