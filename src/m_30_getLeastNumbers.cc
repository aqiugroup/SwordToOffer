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
    vector<int> m_30_getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }

        priority_queue<int> q;
        for(int i=0; i < k; i++) q.push(arr[i]);

        int n = arr.size();
        for(int i=k; i<n; i++) {
            if(arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            vec[i] = q.top();
            q.pop();
        }
        return vec;
    }
};

TEST(m_30_getLeastNumbers, m_30_getLeastNumbers_1)
{
    Solution s;
    vector<int> in2 = {1, 2, 3};
    vector<int> ans2 = {2,1};
    EXPECT_EQ(s.m_30_getLeastNumbers(in2,2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
