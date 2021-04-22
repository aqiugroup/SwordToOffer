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
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> m_25_pathSum(TreeNode* root, int sum) {
        helper(root, sum);
        return res;
    }

    void helper(TreeNode* root, int sum) {
        if(!root) return;

        path.push_back(root->val);
        sum-=root->val;

        if(sum==0 && root -> left == nullptr && root -> right == nullptr) {
            res.push_back(path);
        }

        helper(root->left, sum);
        helper(root->right, sum);

        path.pop_back();
    }
};

TEST(m_25_pathSum, m_25_pathSum_1)
{
    Solution s;
    Tree in1{5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    vector<vector<int>> in3 = {{5,4,11,2},{5,8,4,5}};
    EXPECT_EQ(s.m_25_pathSum(in1.root,22), in3);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
