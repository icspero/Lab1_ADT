#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "structures.h"

using namespace std;

// ---------- Запись в структуру ----------
void WritingFromFileToArray(Array& array, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    string value;
    while (getline(inFile, value)) {
        array.MPUSH_end(value);
    }

    inFile.close();
}

void WritingFromFileToSinglyLinkedList(SinglyLinkedList& list, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    string value;
    while (getline(inFile, value)) {
        list.LONEPUSH_tail(value);
    }

    inFile.close();
}

void WritingFromFileToDoublyLinkedList(DoublyLinkedList& list, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    string value;
    while (getline(inFile, value)) {
        list.LTWOPUSH_tail(value);
    }

    inFile.close();
}

void WritingFromFileToQueue(Queue& queue, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    string value;
    while (getline(inFile, value)) {
        queue.QPUSH(value);
    }

    inFile.close();
}

void WritingFromFileToStack(Stack& stack, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    string value;
    while (getline(inFile, value)) {
        stack.SPUSH(value);
    }

    inFile.close();
}

void WritingFromFileToHashTable(HashTable& hashTable, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        size_t delimPos = line.find('=');
        if (delimPos != string::npos) {
            string key = line.substr(0, delimPos);
            string value = line.substr(delimPos + 1);
            hashTable.HPUSH(key, value);
        }
    }

    inFile.close();
}

// ---------- Запись в файл ----------
void WritingFromArrayToFile(Array& array, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    for (int i = 0; i < array.size; ++i) {
        outFile << array.MGET(i) << endl;
    }

    outFile.close();
}

void WritingFromSinglyLinkedListToFile(SinglyLinkedList& list, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    SingleNode* current = list.head;
    while (current != nullptr) {
        outFile << current->cell << endl;
        current = current->next;
    }

    outFile.close();
}

void WritingFromDoublyLinkedListToFile(DoublyLinkedList& list, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    DoubleNode* current = list.head;
    while (current != nullptr) {
        outFile << current->cell << endl;
        current = current->next;
    }

    outFile.close();
}

void WritingFromQueueToFile(Queue& queue, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    SingleNode* current = queue.head;
    while (current != nullptr) {
        outFile << current->cell << endl;
        current = current->next;
    }

    outFile.close();
}

void WritingFromStackToFile(Stack& stack, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    SingleNode* current = stack.head;
    while (current != nullptr) {
        outFile << current->cell << endl;
        current = current->next;
    }

    outFile.close();
}

void WritingFromHashTableToFile(HashTable& hashTable, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    for (int i = 0; i < hashTable.size; ++i) {
        NodeHash* current = hashTable.table[i];
        while (current != nullptr) {
            outFile << current->key << "=" << current->value << endl;
            current = current->next;
        }
    }

    outFile.close();
}