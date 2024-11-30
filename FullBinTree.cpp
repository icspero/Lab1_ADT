#include "structures.h"

#include <iostream>
#include <fstream>
using namespace std;

void FBT::TDestroyFBT(FBTnode* node) {
    if (node == nullptr) {
        return;
    }
    TDestroyFBT(node->left);
    TDestroyFBT(node->right);
    delete node;
}

FBTnode* FBT::TInsert(FBTnode* node, string& key) {
    // Если текущий узел пустой, создаем новый узел и возвращаем его
    if (node == nullptr) {
        return new FBTnode(key);
    }

    // Если у узла есть только один потомок, добавляем в недостающий
    if (node->left == nullptr) {
        node->left = TInsert(node->left, key);
    } else if (node->right == nullptr) {
        node->right = TInsert(node->right, key);
    } 
    // Если оба потомка существуют, рекурсивно переходим в левое поддерево,
    // затем в правое поддерево
    else {
        // Определяем, куда двигаться: в левое или правое поддерево
        // Для FBT идем влево, пока все уровни слева не заполнены
        if (IsFullBinaryTree(node->left)) {
            node->right = TInsert(node->right, key);
        } else {
            node->left = TInsert(node->left, key);
        }
    }

    // Возвращаем текущий узел
    return node;
}

bool FBT::IsFullBinaryTree(FBTnode* node) {
    // Базовый случай: пустое дерево
    if (node == nullptr) {
        return true;
    }

    // Если узел — лист (нет потомков)
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }

    // Если оба потомка существуют, проверяем их рекурсивно
    if (node->left != nullptr && node->right != nullptr) {
        return IsFullBinaryTree(node->left) && IsFullBinaryTree(node->right);
    }

    // Если один из потомков отсутствует, дерево не является полным бинарным
    return false;
}

FBTnode* FBT::TSearch(FBTnode* node, string & key) {
    if (node == nullptr || node->key == key) {// если узел пустой или ключ найден, возвращаем узел
        return node;
    }

    if (key < node->key)
        return TSearch(node->left, key); 
    else
        return TSearch(node->right, key);
}

void FBT::TDisplay(FBTnode* node) {
    if (node != nullptr) {
        cout << node->key << " "; // выводим ключ текущего узла
        TDisplay(node->left); // рекурсивно обходим левое поддерево
        TDisplay(node->right); // рекурсивно обходим правое поддерево
    }
}

void FBT::TSaveToFile(FBTnode* node, ofstream& FileWrite) {
    if (node == nullptr) {
        return;
    }

    FileWrite << node->key << " "; // записываем ключ текущего узла

    // рекурсивно записываем левое и правое поддеревья
    TSaveToFile(node->left, FileWrite);
    TSaveToFile(node->right, FileWrite);
}

void FBT::TPUSH(string &key) {
    root = TInsert(root, key);
}

bool FBT::TFULL() {
    return IsFullBinaryTree(root);
}

bool FBT::TSEARCH(string&key) {
    return TSearch(root, key) != nullptr;
}

void FBT::TREAD() {
    TDisplay(root);
    cout << endl;
}

FBT::~FBT() {
    TDestroyFBT(root);
}

void FBT::TLoadFromFile(const string& filename) {
    ifstream FileRead(filename);
    if (!FileRead.is_open()) {
        cerr << "Ошибка открытия файла для чтения: " << filename << endl;
        return;
    }

    string key;
    while (FileRead >> key) { // считываем ключи из файла
        TPUSH(key);          // добавляем их в дерево
    }

    FileRead.close();
}

void FBT::TSaveToFileHelper(const string& filename) {
    ofstream FileWrite(filename); // открытие файла для записи
    if (!FileWrite.is_open()) {
        cerr << "Ошибка открытия файла для записи: " << filename << endl;
        return;
    }

    TSaveToFile(root, FileWrite); // рекурсивно сохраняем дерево
    FileWrite.close();
}