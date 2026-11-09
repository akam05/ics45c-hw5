#include "string.hpp"

#include <iostream>
#include <utility>
using namespace std;

// constructs this string from a C string, defaults to empty string
String::String(const char *s) : head(list::from_string(s))
{
}

// construct this string as a copy of string s
String::String(const String &s) : head(list::copy(s.head))
{
}

// construct this string by moving from string s
String::String(String &&s) : head(s.head)
{
    s.head = nullptr;
}

// swap this string with s
void String::swap(String &s)
{
    std::swap(head, s.head);
}

// assignment operator from one string, s, to this string
String& String::operator=(const String &s)
{
    if (this != &s)
    {
        String temp(s);
        swap(temp);
    }
    return *this;
}

// assign to this string by moving
String& String::operator=(String &&s)
{
    if (this != &s)
    {
        list::free(head);
        head = s.head;
        s.head = nullptr;
    }
    return *this;
}

// check if we can index at position i in this string
bool String::in_bounds(int index) const
{
    return index >= 0 && index < size();
}

// allow const indexing
char String::operator[](int index) const
{
    if (!in_bounds(index)) {
        cout << "ERROR: Index Out of Bounds\n";
        return '\0';
    }
    return list::nth(head, index)->data;
}

// returns the logical length of this string (# of chars up to '\0')
int String::size() const
{
    return list::length(head);
}

// returns a reversal of this string, does not modify this string
String String::reverse() const
{
    return String(list::reverse(head));
}

// returns index into this string for first occurrence of c
int String::indexOf(char c) const
{
    list::Node* res = list::find_char(head, c);

    if (res == nullptr)
        return -1;
    return list::index(head,res);
}

// returns index into this string for first occurrence of s
int String::indexOf(const String &s) const
{
    list::Node* res = list::find_list(head, s.head);
    if (res == nullptr)
        return -1;
    return list::index(head, res); 
}

// compare this string with another string by equality
// note: != is auto-generated since C++20
bool String::operator==(const String &s) const
{
    return list::compare(head, s.head) == 0;
}

// C++20 way of defining all comparisons at once
std::strong_ordering String::operator<=>(const String &s) const
{
    return list::compare(head, s.head) <=> 0;
}

// concatenate this and s to form a return string
String String::operator+(const String &s) const
{
    return String(list::append(head, s.head));
}

// concatenate s onto the end of this string
String& String::operator+=(const String &s)
{
    list::Node* temp = list::copy(s.head);
    if (head == nullptr)
        head = temp;
    else
        list::last(head)->next = temp;

    return *this;
}

// print this string, hint: use operator << to send buf to out
void String::print(std::ostream &out) const
{
    list::print(out,head);
}

// read next word into this string
// hint: use operator >> to read from in into a temporary buffer
void String::read(std::istream &in)
{

    char buf[1024];
    if (in>>buf)
    {
        String temp(buf);
        swap(temp);
    }
}

// destructor for this string
String::~String()
{
    list::free(head);
}

// private constructor
String::String(list::Node* head) : head(head)
{
}

ostream& operator<<(ostream& out, const String& s)
{
    s.print(out);
    return out;
}

istream& operator>>(istream &in, String& s)
{
    s.read(in);
    return in;
}