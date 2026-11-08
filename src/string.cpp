#include "list.hpp"
#include <ostream>

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
