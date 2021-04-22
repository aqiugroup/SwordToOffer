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
    char m_35_firstUniqChar(string s) {
        unordered_map<char, bool> dic;
        for(char c : s)
            dic[c] = dic.find(c) == dic.end();
        for(char c : s)
            if(dic[c]) return c;
        return ' ';
    }
};

TEST(m_35_firstUniqChar, m_35_firstUniqChar_1)
{
    Solution s;
    string in2="abccda";
    char ans2 = 'b';
    EXPECT_EQ(s.m_35_firstUniqChar(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
