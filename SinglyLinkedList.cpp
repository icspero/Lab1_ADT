#include "structures.h"

#include <iostream>
using namespace std;

// O(N)
void SinglyLinkedList::Clear() {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

// O(1)
void SinglyLinkedList::LONEPUSH_head(string& cell) {

    SingleNode* node = new SingleNode;
    node->cell = cell;
    node->next = nullptr;

    if (head == nullptr) {
        head = tail = node;
        prevTail = nullptr;
        prevTail->next = tail;
    }
    else {
        node->next = head;
        head = node;
    }
}

// O(1)
void SinglyLinkedList::LONEPUSH_tail(string& cell) {
    
    SingleNode* node = new SingleNode;
    node->cell = cell;
    node->next = nullptr;
    if (tail == nullptr) {
        head = tail = node;
        prevTail = nullptr;
    }
    else {
        tail->next = node;
        prevTail = tail; 
        tail = node;
        
    }

}

// O(1)
void SinglyLinkedList::LONEDEL_head() {
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    SingleNode* node = head;
    head = head->next;
    delete node;
    if (head == nullptr) {
        tail = nullptr;
        prevTail = nullptr;
    }

}

// O(1)
void SinglyLinkedList::LONEDEL_tail() {
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        prevTail = nullptr;
        return;
    }
    SingleNode* current = prevTail;
    prevTail->next = tail->next;
    delete tail;
    tail = current;
    tail->next = nullptr;
}

// O(N)
void SinglyLinkedList::LONEDEL_value(string&value) {
    SingleNode* node = head;
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    if (head->cell == value) {
        LONEDEL_head();
        return;
    }
    while (node != nullptr && node->next != nullptr &&  node->next->cell != value ) {
        if (node == nullptr) {
            cout << "\nЗначение не найдено!" << endl;
            return;
        }
        node = node->next;
    }
    
    SingleNode* toDelete = node->next;  
    node->next = toDelete->next;
    if (toDelete == tail) {
        tail = toDelete;
        prevTail->next = tail->next;
    }
    delete toDelete;
    tail = prevTail;

}

// O(N)
void SinglyLinkedList::LONE_search(string& value) {
    SingleNode* node = head;
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    int index = 0;
    while (node != nullptr) {
        if (node->cell == value) {
            cout << "\nЗначение найдено! Индекс: " << index << endl;
            return;
        }
        node = node->next;
        index++;
    }
    
    cout << "\nЗначение не найдено!" << endl;
}

// O(N)
void SinglyLinkedList::LONE_read() {
    SingleNode* node = head;
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    cout << endl;
    while (node != nullptr) {
        cout << node->cell << " ";
        node = node->next;
    }
    cout << endl;
}

SinglyLinkedList::~SinglyLinkedList() {
    Clear();
}