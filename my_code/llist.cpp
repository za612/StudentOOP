#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	os << nd->data << endl;
	return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) { 
	if (!head) head = new Node(d);
	else {
		Node* tail = last(head);
		tail->next = new Node(d);
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
	if (!head) os << endl;
	else {
		os << head->data << " ";
		print_list(os, head->next);
	}
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) { // make recursive
	if(!head) return nullptr;
	else {
		if (head->next == nullptr) {
			return head;
		}
		else {
			return last(head->next);
		}
	}
}

bool del_tail(Node*& curr) {
	if (!curr) return false;
	else {
		if (curr->next == nullptr) {
			delete curr;
			curr = nullptr;
			return true;
		}
		else {
			return del_tail(curr->next);
		}
	}
}

Node* reverse(Node* curr, Node* new_next) {
	if (!curr)return new_next;
	else {
		return reverse(curr->next, new Node(curr->data, new_next));
	}
}

bool del_head(Node*& head) {
	if (head != nullptr) {
		Node* second = head->next; 
		delete head; 
		head = second;
		return true;
	}
	return false;
}

Node* duplicate(Node* head) {
	if(!head) return nullptr;
	return new Node(head->data, duplicate(head->next));
}

Node* join(Node*& list1, Node* list2) { 
	last(list1)->next = list2;
	return list1;
}
