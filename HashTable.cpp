#include "structures.h"

#include <iostream>
using namespace std;

// O(N)
void HashTable::HDestroyTable(NodeHash* node) {
    while (node != nullptr) {
        NodeHash* temp = node;
        node = node->next; 
        delete temp; 
    }
}

// O(N)
HashTable::HashTable(int initialSize) {
    size = initialSize;  
    count = 0;  
    table = new NodeHash * [size];  
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;  
    }
}

// O(N)
int HashTable::HashFunc(string& str) {
    int hash = 0;  
    for (char c : str) {
        hash += c;  // ASCII
    }
    return hash % size;
}

// O(1) - O(N)
void HashTable::HPUSH(string& key, string& value) {
    int index = HashFunc(key); 
    NodeHash* current = table[index]; 

    while (current != nullptr) {  
        if (current->key == key) { 
            current->value = value; 
            return; 
        }
        current = current->next; 
    }

    NodeHash* newNode = new NodeHash(key, value);  // создание нового узла
    newNode->next = table[index];  // новый узел указывает на текущий узел по индексу
    table[index] = newNode;  // новый узел становится текущим узлом по индексу
    count++;  

}

// O(1) - O(N)
void HashTable::HDEL(string& key) {
    int index = HashFunc(key); 
    NodeHash* current = table[index];  
    NodeHash* prev = nullptr; 

    while (current != nullptr) {  
        if (current->key == key) {  
            if (prev == nullptr) {  // если это первый узел в списке
                table[index] = current->next;  // следующий узел становится текущим
            }
            else {
                prev->next = current->next;  // предыдущий узел указывает на следующий узел
            }
            delete current;  
            count--;  
            cout << "Элемент успешно удален!" << endl;
            return;  
        }
        prev = current;  // переход к следующему узлу
        current = current->next;
    }
    cout << "Такого элемента нет!" << endl;
}

// O(1) - O(N)
string HashTable::HGET(string& key) {
    int index = HashFunc(key);  
    NodeHash* current = table[index]; 

    while (current != nullptr) {  
        if (current->key == key) { 
            return current->value;  
        }
        current = current->next; 
    }

    return "Ключ не был найден!";  
}

// O(N)
void HashTable::HREAD() {
    for (int i = 0; i < size; i++) {  
        cout << "[" << i << "]: ";
        NodeHash* current = table[i]; 
        if (current == nullptr) {
            cout << "пусто" << endl;  
            continue;  
        }
        while (current != nullptr) {
            cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next; 
        }
        cout << endl;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        HDestroyTable(table[i]);
    }
    delete[] table;
}