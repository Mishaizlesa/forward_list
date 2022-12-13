#include "list.hpp"
#include <gtest.h>
TEST(list, can_create){

    EXPECT_NO_THROW(list<int>a);
}
TEST(list, can_push_front){
    list<int>a;
    a.push_front(3);
    a.push_front(222);
    EXPECT_EQ(222, a.begin()->val);
}
TEST(list, can_pop_front){
    list<int>a;
    a.push_front(3);
    a.push_front(222);
    a.pop_front();
    EXPECT_EQ(3, a.begin()->val);
}
TEST(list, can_push_after)
{
    list<int>a;
    a.insert_after(a.begin(), 2);
    a.insert_after(a.begin(), 3);
    a.pop_front();
    EXPECT_EQ(3, a.begin()->val);
}
TEST(list, can_copy)
{
    list<int>a;
    list<int>b;
    a.push_front(3);
    a.push_front(4);
    a.push_front(5);
    b=a;
    EXPECT_EQ(true, a==b);
    
}
TEST(list, copied_list_has_own_memory)
{
    list<int>a;
    list<int>b;
    a.push_front(3);
    a.push_front(4);
    a.push_front(5);
    b=a;
    a.clear();
    EXPECT_EQ(5, b.begin()->val);
}

TEST(list, can_erase_after)
{
    list<int>a;
    a.push_front(5);a.push_front(6);
    a.erase_after(a.begin());
    EXPECT_EQ(a.begin()->val, 6);
}

TEST(list, correct_unique)
{
    list<int>a;a.push_front(3);
    a.push_front(3);
    a.push_front(4);
    a.push_front(4);
    a.unique();
    auto it=a.begin();
    int cnt=0;
    while (it) {
        cnt++;
        it=it->next;
    }
    EXPECT_EQ(2, cnt);
}
