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
class CMYString
{
public:
    CMYString(char* pData = NULL) {
        cout << "Constructor" << endl;
        m_pData = pData;
    };
    CMYString(const CMYString& str) {
        cout << "Copy Constructor" << endl;
    };
    CMYString& operator=(const CMYString& str) {
        cout << "Assign Constructor" << endl;
        if (this != &str) {
            CMYString strTemp(str);
            cout << "------" << endl;

            char* pTemp = str.m_pData;
            strTemp.m_pData = m_pData;
            m_pData = pTemp;
        }

        return *this;
    }
    ~CMYString() {};

// private:
    char* m_pData;
};

class Solution
{
public:
    int sword2offer_m_01(vector<int> &nums) {
        CMYString str1, str2, str3("abc");
        cout << "begin " << endl;
        str1 = str3;
        cout << "str1 " << str1.m_pData[0] << endl;
        cout << "str3 " << str3.m_pData[0] << endl;
        cout << "str1 " << str1.m_pData << endl;
        cout << "str3 " << str3.m_pData << endl;
        return 1;
    }
};

TEST(sword2offer_m_01, sword2offer_m_01_1)
{
    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.sword2offer_m_01(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
