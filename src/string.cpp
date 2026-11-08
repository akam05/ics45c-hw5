// constructs this string from a C string, defaults to empty string
explicit String(const char *s = "")
{
}

// construct this string as a copy of string s
Stiring::String(const String &s)
{
}

// construct this string by moving from string s
String::String(String &&s)
{
}

// swap this string with s
void String::swap(String &s)
{
}

// assignment operator from one string, s, to this string
String::String &operator=(const String &s)
{
}

// assign to this string by moving
String::String &operator=(String &&s)
{
}

// check if we can index at position i in this string
bool String::in_bounds(int index) const
{
}

// allow const indexing
char String::operator[](int index) const
{
}

// returns the logical length of this string (# of chars up to '\0')
int String::size() const
{
}

// returns a reversal of this string, does not modify this string
String::String reverse() const
{
}

// returns index into this string for first occurrence of c
int String::indexOf(char c) const
{
}

// returns index into this string for first occurrence of s
int String::indexOf(const String &s) const
{
}

// compare this string with another string by equality
// note: != is auto-generated since C++20
bool String::operator==(const String &s) const
{
}

// C++20 way of defining all comparisons at once
std::strong_ordering String::operator<=>(const String &s) const
{
}

// concatenate this and s to form a return string
String::String operator+(const String &s) const
{
}

// concatenate s onto the end of this string
String::String &operator+=(const String &s)
{
}

// print this string, hint: use operator << to send buf to out
void String::print(std::ostream &out) const
{
}

// read next word into this string
// hint: use operator >> to read from in into a temporary buffer
void String::read(std::istream &in)
{
}

// destructor for this string
String::~String()
{
}