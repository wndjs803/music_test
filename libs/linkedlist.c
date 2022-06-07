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
    size_t count=0;
    while(ptr != _tail) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void print() {
    Node* ptr;
    ptr=_head;
    ptr = ptr->next;
    printf("LinkedList [");
    while(ptr != _tail) {
        printf(" %s ", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

void print_file(FILE* stream) {
    Node* ptr;
    ptr = _tail->prev;
    fprintf(stream, "%d", size());
    fprintf(stream, "\n");

    while(ptr != _head) {
        fprintf(stream, (ptr->data));
        fprintf(stream, "\n");
        ptr = ptr->prev;
    }
}

void clear() {
    Node* ptr;
    Node* ptr_prev;

    if(empty()){
        printf("LinkedList is cleared!\n");
    }
    else{
        ptr = _head;
        while(true){
            ptr_prev = ptr;
            ptr = ptr->next;
            free(ptr_prev);
            if(ptr == _tail) {
                free(ptr);
                break;
            }
        }

        printf("LinkedList is cleared!\n");
    }
    _cur_node = NULL;
}

Node* append_left(size_t n, char new_data[n]) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    if(empty()) {
        _head = (Node*)malloc(sizeof(Node));
        _tail = (Node*)malloc(sizeof(Node));
        _head->next = new_node;
        new_node->prev = _head;
        new_node->next = _tail;
        new_node->data = new_data;
        _tail->prev = new_node;
        _cur_node = new_node;
        return new_node;
    }

    Node* ptr = _tail->prev;
    new_node->prev = ptr;
    new_node->next = _tail;
    ptr->next = new_node;
    _tail->prev = new_node;
    new_node->data = new_data;
    _cur_node = new_node;
    return new_node;
}

Node* insert_after(Node* cur_node, Node* new_node) {
    Node* cur_left = _cur_node->prev;
    Node* cur_right = _cur_node->next;
    Node* new_right = new_node->next;

    cur_left->next = cur_right;
    cur_right->prev = cur_left;
    new_node->next = cur_node;
    new_right->prev = cur_node;
    cur_node->prev = new_node;
    cur_node->next = new_right;

    return _cur_node;
}

Node* append(size_t n, char new_data[n]) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    if(empty()) {
        _head = (Node*)malloc(sizeof(Node));
        _tail = (Node*)malloc(sizeof(Node));
        _head->next = new_node;
        new_node->prev = _head;
        new_node->next = _tail;
        new_node->data = new_data;
        _tail->prev = new_node;
        _cur_node = new_node;
        return new_node;

    }

    Node* ptr = _head->next;
    new_node->prev = _head;
    new_node->next = ptr;
    _head->next = new_node;
    ptr->prev = new_node;
    new_node->data = new_data;
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
    ptr = _tail;

    while (ptr!=_head){
        ptr = ptr->prev;
        if(!strcmp(ptr->data,data)){
            _cur_node = delete_node(ptr);
            break;
        }
    }
    return _cur_node;
}

Node* get_node(size_t index) {
    if(size()<index) return NULL;

    Node* ptr;
    ptr = _tail;
    int i;

    for(i=0; i<index; i++){
        ptr = ptr->prev;
    }

    return ptr;
}

Node* first_node() {
    if(empty()) return NULL;
    else return _cur_node = _head->next;
}

Node* last_node() {
    if(empty()) return NULL;
    else return _tail->prev;
}

Node* next() {
    if(_cur_node == _tail || _cur_node == _head) return NULL;
    else if(_cur_node->next == _tail) return _cur_node;
    else return _cur_node = _cur_node->next;
}

Node* prev() {
    if(_cur_node == _tail || _cur_node == _head) return NULL;
    else if(_cur_node->prev == _head) return _cur_node;
    else return _cur_node = _cur_node->prev;
}
