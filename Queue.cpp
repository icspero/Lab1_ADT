#include "structures.h"

#include <iostream>
using namespace std;

// O(N)
void Queue::Clear() {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;  
        delete temp;        
    }
    tail = nullptr; 
}

// O(1)
void Queue::QPUSH(string& cell) {
    SingleNode* node = new SingleNode;
    node->cell = cell; 
    node->next = nullptr;

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

// O(1)
void Queue::QPOP() {
    SingleNode* node = head;
    head = head->next;
    delete node;
    if (head == nullptr) {
        tail = nullptr;
    }
}

// O(N)
void Queue::QREAD() {
    SingleNode* current = head;
    cout << endl;
    while (current != nullptr) {
        cout << current->cell << " ";
        current = current->next;
    }
    cout << endl;
}