#include "structures.h"

#include <iostream>
using namespace std;

// O(N)
void Stack::Clear() {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

// O(1)
void Stack::SPUSH(string& cell) {
    SingleNode* node = new SingleNode;
    node->cell = cell;
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
}

// O(1)
void Stack::SPOP() {
    if (head == tail) {  
        delete head;      
        head = tail = nullptr; 
        return;
    }
    SingleNode* current = head;
    head = head->next;
    delete current;
}

// O(N)
void Stack::SREAD() {
    SingleNode* current = head;
    cout << endl;
    while (current != nullptr) {
        cout << current->cell << " ";
        current = current->next;
    }
    cout << endl;
}

// O(1)
void Stack::WriteFromFile(string& cell) {
    SingleNode* node = new SingleNode;
    node->cell = cell;
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

