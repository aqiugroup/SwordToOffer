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
    vector<int> m_23_levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front(); q.pop();
                if (t) {
                    q.push(t->left);
                    q.push(t->right);
                    tmp.push_back(t->val);
                }
            }
            if (tmp.size() > 0) ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }
};

TEST(m_23_levelOrder, m_23_levelOrder_1)
{
    Solution s;
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 4,2,3};
    EXPECT_EQ(s.m_23_levelOrder(in1.root), ans1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
