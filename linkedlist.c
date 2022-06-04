#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty() {
	if(_head->next == _tail)	return true;
	else return false;
}

size_t size() {
	Node* ptr;
	ptr = _head->next;
	size_t count=0;
	while(ptr != NULL) {
            ptr = ptr->next;
			count++;
		}
	return count;
}

void print() {
	Node* ptr;
	ptr = _head->next;
	printf("LinkedList [");

	while(ptr != NULL) {
		printf("%s ", *(ptr->data));
		ptr = ptr->next;
	}
    printf("]\n");
}

void print_file(FILE* stream) {
    Node* ptr;
	ptr = _tail->prev;
    fprintf(stream, "%d", size())
	fprintf(stream, "\n")

    while(ptr != NULL) {
		frintf(stream, *(ptr->data));
		fprintf(stream, "\n")
		ptr = ptr->prev;
	}
}

void clear() {
    Node* ptr;
    ptr = _head->next;

    while(!empty()) {
        _head->next = ptr->next;
        ptr->next->prev = _head;
        free(ptr);
        ptr = _head->next;
    }
    printf("LinkedList is cleared!\n");
    _cur_node = _head;
}

Node* append_left(size_t n, char new_data[n]) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));

    if(empty()) {
        strcpy(new_node->data, new_data);
        _head->next = new_node;
        new_node->prev = _head;
        new_node->next = _tail;
        _tail->prev = new_node;
        _cur_node = new_node;

        return new_node;
    }

    Node* ptr = _head->next;
    new_node->prev = _haed;
    new_node->next = ptr;
    _haed->next = new_node;
    ptr->prev = new_node;
    strcpy(new_node->data, new_data);
    _cur_node = new_node;

    return new_node;
}

Node* insert_after(Node* cur_node, Node* new_node) {
    Node* left = _cur_node;
    Node* right = _cur_node->next;

    left->next = new_node;
    new_node->next = right;
    new_node->prev = left;
    right->prev = new_node;

    _cur_node = new_node;
    return _cur_node;
}

Node* append(size_t n, char new_data[n]) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));

    if(empty()) {
        strcpy(new_node->data, new_data);
	_head->next = new_node;
        new_node->prev = _head->next;
        new_node->next = _tail;
        _tail->prev = new_node;
        _cur_node = new_node;

        return new_node;
    }

    Node* ptr = _tail->prev;
    new_node->prev = ptr;
    new_node->next = _tail;
    ptr->next = new_node;
    _tail->prev = new_node;
    strcpy(new_node->data, new_data);
    _cur_node = new_node;

    return new_node;
}

Node* delete_node(Node* _cur_node) {
    Node* cur;
    cur = _cur_node;

    Node* left = cur-> prev;
    Node* right = cur->next;

	left->next = right;
	right->prev = left;
	_cur_node = left;
    free(cur);

	return _cur_node;
}

Node* delete_by_data(char* data) {
    Node* ptr;
    ptr = head->next;

    while(ptr!=NULL){
        if(ptr->data == data) {
            Node* cur = (Node*)malloc(sizeof(Node));
            cur = delete_node(ptr);
            return cur
        }
        ptr=ptr->next;
    }
    return _cur_node;
}

Node* get_node(size_t index) {
	if(size()<index)    return NULL;

	Node* ptr;
	ptr = _tail;
	int i;

	for(i=0; i<index; i++)
		ptr = ptr->prev;

	return ptr;
}

Node* first_node() {
    if(empty()) return NULL;
	return _head->next;
}

Node* last_node() {
    if(empty()) return NULL;
	return _tail->prev;
}

Node* next() {
    if(_cur_node == _tail)  return NULL;
	return _cur_node->next;
}

Node* prev() {
    if(_cur_node == _head) return NULL;
	return _cur_node->prev;
}


