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
    int reverse_string(string& s, int start, int end) {
        for (int i = start; i <= (start + end) / 2; i++) {
            char temp = s[i];
            s[i] = s[start+end-i];
            s[start+end-i] = temp;
        }
        return 0;
    }

    string m_42_reverseLeftWords(string s, int n) {
        int length = s.length();

        reverse_string(s, 0, length-1);
        reverse_string(s, 0, length-n-1);
        reverse_string(s, length-n, length-1);

        return s;
    }
};

TEST(m_42_reverseLeftWords, m_42_reverseLeftWords_1)
{
    Solution s;
    string in2="abc";
    string ans2 = "bca";
    EXPECT_EQ(s.m_42_reverseLeftWords(in2,1), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
