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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    void push(int x) {
        m_data.push(x);
        if(m_min.size()==0 || x < m_min.top()) m_min.push(x);
        else m_min.push(m_min.top());
    }
    void pop() {
        if (m_data.empty() == false) {
            m_data.pop();
            m_min.pop();
        }
    }
    int top() {
        if (m_data.empty() == false) {
            return m_data.top();
        }
        return 0;
    }
    int min() {
        assert(m_min.size() > 0);
        return m_min.top();
    }
    stack<int> m_data;
    stack<int> m_min;
};


class Solution
{
public:
    int m_21_stackWithMin(vector<int> &nums) {
        return 1;
    }
};

TEST(m_21_stackWithMin, m_21_stackWithMin_1)
{
    Solution s;
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();

    vector<int> in2 = {1, 2, 3};
    int ans2 = 1;
    EXPECT_EQ(s.m_21_stackWithMin(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
