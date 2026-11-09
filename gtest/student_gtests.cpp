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
        ASSERT_NE(duplicate, nullptr);
        EXPECT_NE(original, duplicate);
        EXPECT_EQ(original->data, duplicate->data);
        original = original->next;
        duplicate = duplicate->next;
    }
    EXPECT_EQ(duplicate, nullptr);
    
    list::free(head);
    list::free(copy);
}

TEST(ListTests, compare) {
    Node* lhs = list::from_string("");
    Node* rhs = list::from_string("");

    EXPECT_EQ(list::compare(lhs, rhs), 0);
    list::free(lhs);
    list::free(rhs);
    
    lhs = list::from_string("a");
    rhs = list::from_string("aa");
    EXPECT_LT(list::compare(lhs, rhs), 0);
    list::free(lhs);
    list::free(rhs);
    
    lhs = list::from_string("aa");
    rhs = list::from_string("a");
    EXPECT_GT(list::compare(lhs, rhs), 0);
    list::free(lhs);
    list::free(rhs);
    
    lhs = list::from_string("aaaa");
    rhs = list::from_string("aaaa");
    EXPECT_EQ(list::compare(lhs, rhs,3), 0);
    list::free(lhs);
    list::free(rhs);

    Node a{'a', nullptr};
    Node b{'b', nullptr};

    EXPECT_EQ(list::compare(&a, &b, 0), 0);

    Node x{'x', nullptr};
    Node left_node{'a', &x};
    
    Node y{'y', nullptr};
    Node right_node{'a', &y};
    
    EXPECT_LT(list::compare(&left_node, &right_node), 0);
    EXPECT_GT(list::compare(&right_node, &left_node), 0);
}

TEST(ListTests, reverse) {
    Node* head = list::from_string("foo");
    Node* expected = list::from_string("oof");
    Node* reverse = list::reverse(head);

    Node* temp = reverse;
    Node* wanted = expected;
    while(wanted!= nullptr)
    {
        ASSERT_NE(temp, nullptr);
        EXPECT_EQ(temp->data,wanted->data);
        
        temp=temp->next;
        wanted=wanted->next;
    }
    EXPECT_EQ(temp, nullptr);
    list::free(head);
    list::free(expected);
    list::free(reverse);
}

TEST(ListTests, append) {
    Node* lhs = list::from_string("foo");
    Node* rhs = list::from_string("oof");
    Node* expected = list::from_string("foooof");

    
    Node* result = list::append(lhs, rhs);
    Node* temp = result;
    Node* wanted = expected;
    while (wanted != nullptr)
    {
        ASSERT_NE(temp, nullptr);
        EXPECT_EQ(temp->data, wanted->data);
        temp = temp->next;
        wanted = wanted->next;
    }
    EXPECT_EQ(temp, nullptr);
    
    list::free(lhs);
    list::free(rhs);
    list::free(expected);
    list::free(result);
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

TEST(ListTests, needle) {
    Node third{'c', nullptr};
    Node second{'b', &third};
    Node first{'a', &second};

    EXPECT_EQ(list::find_list(&first, &second), &second);

    Node a{'a', nullptr};
    Node b{'b', nullptr};

    EXPECT_EQ(list::find_list(&a, nullptr), &a);
    EXPECT_EQ(list::find_list(nullptr, nullptr), nullptr);
    EXPECT_EQ(list::find_list(nullptr, &a), nullptr);
    EXPECT_EQ(list::find_list(&a, &b), nullptr);
}

TEST(ListTests, nth) {
    Node third{'a', nullptr};
    Node second{'a', &third};
    Node first{'a', &second};

    EXPECT_EQ(list::nth(&first,1),&second);
}

TEST(ListTests, last) {
    Node third{'a', nullptr};
    Node second{'a', &third};
    Node first{'a', &second};

    EXPECT_EQ(list::last(&first),&third);
}

