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
struct FBTnode {

    string key;
    FBTnode* left;
    FBTnode* right;
    int height;

    FBTnode(string key) : key(key), left(nullptr), right(nullptr), height(1) {}

};
struct FBT {
    FBTnode* root;
    FBT() : root(nullptr) {};

    ~FBT();
    void TDestroyFBT(FBTnode* node);
    string key;
    unsigned char height;
    SingleNode* left;
    SingleNode* right;

    int THeight(FBTnode* node);
    int TBalance(FBTnode* node);
    FBTnode* TRightRotate(FBTnode* y);
    FBTnode* TLeftRotate(FBTnode* x);
    FBTnode* TInsert(FBTnode* node, string & key);
    FBTnode* TMinValueLeftNode(FBTnode* node);
    bool IsFullBinaryTree(FBTnode* node);
    FBTnode* TSearch(FBTnode* node, string& key);
    void TDisplay(FBTnode* node);
    void TPUSH(string& key);
    bool TFULL();
    bool TSEARCH(string& key);
    void TREAD();

    void TSaveToFile(FBTnode* node, ofstream& FileWrite);
    void TLoadFromFile(const string& filename);
    void TSaveToFileHelper(const string& filename);
    
};

