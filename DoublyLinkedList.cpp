#include "structures.h"

#include <iostream>
using namespace std;

// O(N)
void DoublyLinkedList::Clear() {
    while (head != nullptr) {
        DoubleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

// O(1)
void DoublyLinkedList:: LTWOPUSH_head(string& element) {
    DoubleNode* node = new DoubleNode;
    node->cell = element;
    node->next = nullptr;
    node->prev = nullptr;

    if (head == nullptr) {
        head = tail = node;
    }
    else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

// O(1)
void DoublyLinkedList::LTWOPUSH_tail(string& element) {
    DoubleNode* node = new DoubleNode;
    node->cell = element;
    node->next = nullptr;
    node->prev = nullptr;
    if (tail == nullptr) {
        head = tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

// O(1)
void DoublyLinkedList::LTWODEL_head() {
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    DoubleNode* node = head;
    head = head->next;
    delete node;
    if (head == nullptr) {
        tail = nullptr;
    }
}

// O(1)
void DoublyLinkedList::LTWODEL_tail() {
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    DoubleNode* current = tail->prev; 
    current->next = tail->next;
    delete tail;
    tail = current;
    tail->next = nullptr;
    tail->prev = current->prev;
}

// O(N)
void DoublyLinkedList::LTWODEL_value(string& value) {
    DoubleNode* node = head;
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    if (head->cell == value) {
        LTWODEL_head();
        return;
    }
    while (node != nullptr && node->cell != value) {
        node = node->next;
    }
    if (node == nullptr) {
        cout << "\nЗначение не найдено!" << endl;
        return;
    }
    if(node->prev) {
        node->prev->next = node->next;
    }
    else {
        head = node->prev;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    else {
        tail = node->next;
    }

    delete node;

}

// O(N)
void DoublyLinkedList::LTWO_search(string& value) {
    DoubleNode* node = head;
    if (head == nullptr) {
        cout << "\nСписок пуст!" << endl;
        return;
    }
    int index = 0;
    if (head->cell == value) {
        cout << "\nЭлемент найден! Индекс: " << index << endl;
        return;
    }
    while (node != nullptr && node->cell != value) {
        node = node->next;
        index++;
    }
    if (node == nullptr) {
        cout << "\nЗначение не найдено!" << endl;
        return;
    }
    cout << "\nЭлемент найден! Индекс: " << index << endl;

}

// O(N)
void DoublyLinkedList::LTWO_read() {
    DoubleNode* node = head;
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