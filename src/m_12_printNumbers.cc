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
    vector<int> m_12_printNumbers(int n) {
        vector<int> nums;
        if (n < 0) return nums;

        string num(n, '0');
        Recurse(nums, num, n, 0);

        return nums;
    }

    /*递归实现从最高位到最低位的数字全排列*/
    void Recurse(vector<int>& nums, string& num, int n, int index)
    {
        if (index == n) {//如果索引index为目标位数n，则到达递归边界，保存当前数字后返回
            PrintNum(nums, num);
            return;
        }

        for (int i = 0; i <= 9; i++) {//每一位数从0到9排列，记录当前位数的一种情况后递归进行下一位数的排列
            num[index] = '0' + i;
            Recurse(nums, num, n, index + 1);
        }
    }

    /*实现字符串数字去掉高位0并转换为int存入nums向量操作*/
    void PrintNum(vector<int>& nums, string num)
    {
        string temp_s = "";
        bool isBeginZero = true; //高位0标记
        for (int i = 0; i < num.size(); i++) {
            if (isBeginZero && num[i] != '0')  isBeginZero = false;
            if (!isBeginZero) temp_s += num[i];
        }

        if(temp_s != "") nums.push_back(stoi(temp_s));
    }
};

TEST(m_12_printNumbers, m_12_printNumbers_1)
{
    Solution s;
    vector<int> ans2 = {1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(s.m_12_printNumbers(1), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
