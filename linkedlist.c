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
    ptr=_head;
    ptr = ptr->next;
    printf("LinkedList [");
    while(ptr != _tail) {
        printf(" %s ", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

//void print_file(FILE* stream) {
//
//}
//
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

    last()->next = new_node;
    new_node->prev = last();
    new_node->next = _tail;
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

    first()->prev = new_node;
    new_node->next = first();
    new_node->prev = _head;
    _head->next = new_node;
    new_node->data = new_data;
    _cur_node = new_node;
    return new_node;
}

Node* delete_node(Node* _cur_node) {
    Node* left = _cur_node-> prev;
    Node* right = _cur_node->next;

    left->next = right;
    right->prev = left;

    _cur_node = left;
    return left;
}

Node* delete(char* data) {
    Node* ptr;
    ptr = _tail;

    while (true){
        ptr = ptr->prev;
        if(!strcmp(ptr->data,data)){
            _cur_node = delete_node(ptr);
            break;
        }
    }

    return _cur_node;
}

Node* get_node(size_t index) {
    Node* ptr;
    ptr = _tail;
    int i;
    for(i=0; i<index; i++){
        if(ptr->prev = _head){
            ptr = ptr;}
        else ptr = ptr->prev;
    }
    return ptr;
}

Node* first() {
    return _cur_node = _head->next;
}

Node* last() {
    return _tail->prev;
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