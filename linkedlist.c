#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty() {
	if(_cur_node == NULL)	return true;
	else return false;
}

size_t size() {
	Node* ptr;
	ptr = _head;
	ptr = ptr->next;
	int count=0;
	while(ptr != NULL) {
			ptr = ptr->next;
			count++;
		}
	return count;
}

void print() {
	Node* ptr;
	ptr = _head;
	ptr = ptr->next;
	int count = size();
	int i;
	while(ptr != NULL) {
		printf("%s ", *(ptr->data));
		ptr = ptr->next;
	}
}

void print_file(FILE* stream) {

}

void clear() {

}

Node* append_left(size_t n, char new_data[n]) {
    Node* new_node;

    if(empty()) {
        _head->next = new_node;
        new_node->prev = _head->next;
        new_node->next = _tail;
        new_node->data = new_data[n];
        _tail->prev = new_node;

        return new_node;
    }

    last()->next = new_node;
    new_node->prev = last();
    new_node->next = _tail;
    _tail->prev = new_node;
    new_node->data = new_data[n];

    return new_node;

}

Node* insert_after(Node* cur_node, Node* new_node) {

}

Node* append(size_t n, char new_data[n]) {
    Node* new_node;

    if(empty()) {
        _head->next = new_node;
        new_node->prev = _head->next;
        new_node->next = _tail;
        new_node->data = new_data[n];
        _tail->prev = new_node;

        return new_node;
    }

    first()->prev = new_node;
    new_node->next = first();
    new_node->prev = _head;
    _head->next = new_node;
    new_node->data = new_data[n];

    return new_node;
}

Node* delete_node(Node* _cur_node) {
	_cur_node->next
}

Node* delete(char* data) {

}

Node* get_node(size_t index) {
	Node* ptr;
	ptr = _head;
	int i;

	for(i=0; i<index; i++)
		ptr = ptr->next;

	return ptr;
}

Node* first() {
	return _head->next;
}

Node* last() {
	return _tail->prev;
}

Node* next() {
	return _cur_node->next;
}

Node* prev() {
	return _cur_node->prev;
}
