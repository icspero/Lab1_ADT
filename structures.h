#pragma once

#include <iostream>
#include <string>
using namespace std;

// Массив
struct Array {
    string* data;
    int size;
    int capacity;

    Array();
    ~Array();

    void MPUSH_end(string& value);
    void MPUSH_index(const int& index, string& value);
    string MGET(const int& index);
    void MDEL(const int& index);
    void MREP(const int& index, string& value);
    int MSIZE();
    void MREAD();
};

// Односвязный список
struct SingleNode {
    string cell;
    SingleNode* next;
};
struct SinglyLinkedList {
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    SingleNode* prevTail = nullptr;

    ~SinglyLinkedList();

    void LONEPUSH_head(string& cell);
    void LONEPUSH_tail(string& cell);
    void LONEDEL_head();
    void LONEDEL_tail();
    void LONEDEL_value(string& value);
    void LONE_search(string& value);
    void LONE_read();
    void Clear();
};

// Двусвязный список
struct DoubleNode {
    string cell;
    DoubleNode* next;
    DoubleNode* prev;
};
struct DoublyLinkedList {
    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;

    ~DoublyLinkedList();

    void LTWOPUSH_head(string& element);
    void LTWOPUSH_tail(string& element);
    void LTWODEL_head();
    void LTWODEL_tail();
    void LTWODEL_value(string& value);
    void LTWO_search(string& value);
    void LTWO_read();
    void Clear();
};

// Очередь
struct Queue {
    string cell;
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;

    ~Queue();

    void QPUSH(string& cell);
    void QPOP();
    void QREAD();
    void Clear();
};

// Стек
struct Stack {
    string cell;
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;

    ~Stack();
    
    void SPUSH(string& cell);
    void SPOP();
    void SREAD();
    void Clear();
};

// Хэш-таблица
struct NodeHash {
    string key;
    string value;
    NodeHash* next;
    NodeHash(string& k, string& v) : key(k), value(v), next(nullptr) {}
};
struct HashTable {
    NodeHash** table; // массив указателей на узлы хеш-таблицы
    int size; 
    int count; 
    
    HashTable(int initialSize = 100);
    int HashFunc(string& str);
    void HPUSH(string& key, string& value);
    string HGET(string& key);
    void HDEL(string& key);
    void HREAD();

    void HDestroyTable(NodeHash* node);
    ~HashTable();
};

// Full Binary Tree
struct FBTNode {
    string key;
    FBTNode* left;
    FBTNode* right;
    int nodeCount;

    FBTNode(string key) : key(key), left(nullptr), right(nullptr), nodeCount(1) {}
};
struct FullBinaryTree {
    FBTNode* root;

    FullBinaryTree() : root(nullptr) {}

    void TINSERT(string key);
    void TINSERT_HELPER(FBTNode* node, string& key);
    bool TFULL();
    bool TFULL_HELPER(FBTNode* node);
    FBTNode* TSEARCH(string key);
    FBTNode* TSEARCH_HELPER(FBTNode* node, const string& key);
    void TREAD();
    void TREAD_HELPER(FBTNode* node);
    void SaveToFile(FullBinaryTree& tree, const string& filename);
    void SaveToFileHelper(FBTNode* node, ofstream& outFile);

    void DestroyTree(FBTNode* node);
    ~FullBinaryTree();
};
