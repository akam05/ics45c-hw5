#include "list.hpp"
#include <ostream>

// returns a linked list from a c-string s
list::Node* from_string(const char *s)
{
	Node* head = nullptr;
	Node* tail = nullptr;

	for (int i = 0; s[i] != '\0'; i++)
	{
		Node* node = new Node{s[i], nullptr};
		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			tail->next = node;
		}
		tail = node;
	}
	return head;
}

// deletes all nodes of linked list
void list::free(Node* head)
{
    while (head!= nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
}

// prints linked list to ostream out
void list::print(std::ostream& out, Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        out << temp->data;
        temp = temp->next;
    }
}

// returns an exact duplicate of linked list starting at head
list::Node* copy(Node* head)
{
    Node* copy = nullptr;
    Node* tail = nullptr;
    Node *temp = head;

    while (temp != nullptr)
    {
        Node* node = new Node{temp->data, nullptr};
        if (copy == nullptr)
        {
            copy = node;
        }
        else 
        {
            tail->next = node;
        }
        tail = node;
        temp = temp->next;
    }
    return copy;
}

// similar to strcmp but for lists
int list::compare(Node* lhs, Node* rhs
{

}

// similar to strncmp but for lists
int list::compare(Node* lhs, Node* rhs, int n)
{

}

// counts number of nodes in linked list
int list::length(Node* head)
{
    Node* temp = head;
    int len = 0;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len; 
}

// returns reversed copy of linked list
list::Node* reverse(Node* head)
{

}

// returns new list containing all nodes of lhs followed by all nodes of rhs
list::Node* append(Node* lhs, Node* rhs)
{

}

// returns index of node in list starting at head
int list::index(Node* head, Node* node)
{
    Node* temp = head;
    int index = 0;
    while (temp != nullptr && temp != node) {
        index++;
        temp = temp->next;
    }
    return index; 
}

// similar to strchr but for a linked list
list::Node* list::find_char(Node* head, char c)
{
    if (c == '\0')
    {
        return nullptr;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != c) {
        temp = temp->next;
    }
    return temp;
}

// similar to strstr but for two linked lists
list::Node* find_list(Node* haystack, Node* needle)
{

}

// get the nth node of linked list
list::Node* list::nth(Node* head, int n)
{
    if (n < 0) {
        return nullptr;
    }
    
    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < n) {
        count++;
        temp = temp->next;
    }
    return temp;
}

// get the last node of linked list
list::Node* list::last(Node* head)
{
    Node* slow = head;
    Node* temp = head->next;

    while(temp != nullptr) {
        slow = temp;
        temp = temp->next;
    }
    return slow;
}


