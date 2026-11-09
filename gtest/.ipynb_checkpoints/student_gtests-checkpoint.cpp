#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, copy) {
    Node* const head = list::from_string("foo");
    Node* copy = list::copy(head);

    Node* original = head;
    Node* duplicate = copy;
    
    while(original !=nullptr)
    {
        EXPECT_NE(original, duplicate);
        EXPECT_EQ(original->data, duplicate->data);
        original = original->next;
        duplicate = duplicate->next;
    }
    EXPECT_EQ(original, nullptr);
    
    list::free(head);
    list::free(copy);
}

TEST(ListTests, compare) {
    Node* lhs = list::from_string("");
    Node* rhs = list::from_string("");

    EXPECT_EQ(list::compare(lhs, rhs), 0);
    
    Node* lhs = list::from_string("a");
    Node* rhs = list::from_string("aa");
    EXPECT_LT(list::compare(lhs, rhs), 0);

    Node* lhs = list::from_string("aa");
    Node* rhs = list::from_string("a");
    EXPECT_GT(list::compare(lhs, rhs), 0);

    Node* lhs = list::from_string("aaaa");
    Node* rhs = list::from_string("aaaa");
    EXPECT_EQ(list::compare(lhs, rhs,3), 0);
    list::free(lhs);
    list::free(rhs);
}

TEST(ListTests, reverse) {
    Node* head = list::from_string("foo");
    Node* expected = list::from_string("oof");
    Node* reverse = list::reverse(head);

    Node* temp = reverse;
    while(temp!= nullptr)
    {
        EXPECT_EQ(reverse->data,expected->data);
        reverse=reverse->next;
        expected=expected->next;
    }
    list::free(head);
    list::free(expected);
}

TEST(ListTests, append) {
    Node* lhs = list::from_string("foo");
    Node* rhs = list::from_string("oof");
    Node* expected = list::from_string("foooof");

    Node* result = list::append(lhs, rhs);
    Node* temp = result;
    while(temp != nullptr)
    {
        EXPECT_EQ(result->data,expected->data);
        result=result->next;
        expected=expected->next;
    }
    list::free(lhs);
    list::free(rhs);
    list::free(expected);
}

TEST(ListTests, index) {
    Node third{'a', nullptr};
    Node second{'a', &third};
    Node first{'a', &second};

    EXPECT_EQ(list::index(&first,&first),0);
    EXPECT_EQ(list::index(&first,&third),2);
}

TEST(ListTests, find_char) {
    Node third{'c', nullptr};
    Node second{'b', &third};
    Node first{'a', &second};

    EXPECT_EQ(list::find_char(&first, 'a'), &first);
    EXPECT_EQ(list::find_char(&first, 'c'), &third);
    EXPECT_EQ(list::find_char(&first, '\0'), nullptr);
}