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
    string m_04_replace_space(string s) {
        string ans = "";
        for(auto c : s) {
            if (c==' ') ans += "%20";
            else ans+=c;
        }

        return ans;
    }
};

TEST(m_04_replace_space, m_04_replace_space_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    string in2 = "We are happy.";
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    string ans2 = "We%20are%20happy.";
    EXPECT_EQ(s.m_04_replace_space(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
