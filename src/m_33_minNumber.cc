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
    string m_33_minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for (int i=0; i < nums.size(); i++) strs.push_back(to_string(nums[i]));

        sort(strs.begin(), strs.end(), [](string& x, string& y){return x+y<y+x;});

        for(int i=0; i<strs.size(); i++) res.append(strs[i]);

        return res;
    }
};

TEST(m_33_minNumber, m_33_minNumber_1)
{
    Solution s;
    vector<int> in2 = {2, 4, 3};
    string ans2 = "234";
    EXPECT_EQ(s.m_33_minNumber(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
