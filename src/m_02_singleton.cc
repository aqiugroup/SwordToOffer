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


/**
 * -----------------------------------------------------------------------
 * 1 singleton non thread-safe --- begin !!!!!!!
 * -----------------------------------------------------------------------
 */
// If this is a header .h file, class implements should be written in .cpp file
// Otherwise, compile error occurs.
class Singleton1
{
public:
    static Singleton1* Instance(); /* Static access method. */
    // Singleton1(Singleton1&) = delete; // Copy prohibited
    // void operator=(const Singleton1&) = delete; // Assignment prohibited
    // Singleton1& operator=(Singleton1&&) = delete; // Move assignment

private:
    Singleton1() {};    // forbid create instance outside
    ~Singleton1() {};   // forbid to delete instance outside

    Singleton1(const Singleton1& rhs);  // Don't forget to disable copy
    Singleton1& operator=(const Singleton1& rhs); // Don't forget to disable copy

    Singleton1(const Singleton1&& rhs);  // move constructor
    Singleton1& operator=(Singleton1&& rhs);  // move assignment

    static Singleton1* m_instance; /* Here will be the instance stored. */
};

/* Null, because instance will be initialized on demand. */
Singleton1* Singleton1::m_instance = nullptr; // Don't forget !!!

Singleton1* Singleton1::Instance() {
    // create new instance if null
    if (m_instance == nullptr) {
        m_instance = new Singleton1();
    }

    return m_instance;
}
/**
 * -----------------------------------------------------------------------
 * 1 singleton non thread-safe --- end !!!!!!!
 * -----------------------------------------------------------------------
 */

/**
 * -----------------------------------------------------------------------
 * 2 singleton thread-safe --- end !!!!!!!
 * -----------------------------------------------------------------------
 */
class Singleton2
{
public:
    static Singleton2* Instance();

private: //deletes don't need to be private, but it's of no interest publically either
    Singleton2() {};   // Default constructor
    ~Singleton2() {}; // Default destructor

    Singleton2(const Singleton2& rhs)=delete;   // copy constructor
    Singleton2 operator=(const Singleton2& rhs)=delete; // copy assignment

    Singleton2(const Singleton2&& rhs)=delete;  // move constructor
    Singleton2 operator=(const Singleton2&& rhs)=delete;    // move assignmen

    static Singleton2* m_instance;
    // static std::mutex m_mutex; // why not ok ?
};

/* Null, because instance will be initialized on demand. */
Singleton2* Singleton2::m_instance = nullptr; // Don't forget !!!
std::mutex m_mutex;

Singleton2* Singleton2::Instance(){
    if (m_instance == nullptr) {
        {
            std::unique_lock<std::mutex> autoLock(m_mutex);
            if (m_instance == nullptr) {
                m_instance = new Singleton2();
            }
        }
    }

    return m_instance;
}

/**
 * -----------------------------------------------------------------------
 * 2 singleton thread-safe --- end !!!!!!!
 * -----------------------------------------------------------------------
 */


/**
 * -----------------------------------------------------------------------
 * 3 singleton thread-safe --- end !!!!!!! ---- recommend
 * -----------------------------------------------------------------------
 */

class Singleton3
{
public:
    static Singleton3& Instance() {
        static Singleton3 staticSingleton3;
        return staticSingleton3;
    };

private:
    Singleton3() {};
    ~Singleton3() {};

    Singleton3(const Singleton3& rhs);// copy constructor
    Singleton3& operator=(const Singleton3& rhs);// copy assignment

    Singleton3(const Singleton3&& rhs);// move constructor
    Singleton3& operator=(const Singleton3&& rhs);// move asignment
};


/**
 * -----------------------------------------------------------------------
 * 3 singleton thread-safe --- end !!!!!!!
 * -----------------------------------------------------------------------
 */

class Solution
{
public:
    int sword2offer_m_02_singleton(vector<int> &nums) {
        return 1;
    }
};

TEST(sword2offer_m_02_singleton, sword2offer_m_02_singleton_1)
{

    //new Singleton1(); // Won't work
    Singleton1* s1 = Singleton1::Instance(); // Ok
    Singleton1* s2 = Singleton1::Instance();

    /* The addresses will be the same. */
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.sword2offer_m_02_singleton(in2), ans2);

}


TEST(sword2offer_m_02_singleton, sword2offer_m_02_singleton_2)
{

    //new Singleton2(); // Won't work
    Singleton2* s1 = Singleton2::Instance(); // Ok
    Singleton2* s2 = Singleton2::Instance();

    /* The addresses will be the same. */
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.sword2offer_m_02_singleton(in2), ans2);

}

TEST(sword2offer_m_02_singleton, sword2offer_m_02_singleton_3)
{

    //new Singleton3(); // Won't work
    Singleton3& s1 = Singleton3::Instance(); // Ok
    Singleton3& s2 = Singleton3::Instance();
    // Singleton3 s3 = Singleton3::Instance(); // not Ok

    /* The addresses will be the same. */
    std::cout << &s1 << std::endl;
    std::cout << &s2 << std::endl;

    Solution s;
    // Tree in1{1, NULL, 2, 3};
    Tree in1{1, 4, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.sword2offer_m_02_singleton(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
