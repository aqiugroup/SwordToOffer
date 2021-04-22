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
// 算法流程：
// 初始化： 辅助栈 stack ，弹出序列的索引 i ；
// 遍历压栈序列： 各元素记为 num ；
// 元素 num 入栈；
// 循环出栈：若 stack 的栈顶元素 == 弹出序列元素 popped[i] ，则执行出栈与 i++ ；
// 返回值： 若 stack 为空，则此弹出序列合法。

    bool m_22_validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for(auto n : pushed) {
            s.push(n);
            while(!s.empty() && s.top()==popped[i]) {
                s.pop();
                i++;
            }
        }

        return s.empty();
    }
};

TEST(m_22_validateStackSequences, m_22_validateStackSequences_1)
{
    Solution s;
    vector<int> in1 = {1,2,3,4,5};
    vector<int> in2 = {4,5,3,2,1};
    bool ans2 = true;
    EXPECT_EQ(s.m_22_validateStackSequences(in1, in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
