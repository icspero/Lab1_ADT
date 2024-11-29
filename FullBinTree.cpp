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

int FBT::THeight(FBTnode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height; 
}

int FBT::TBalance(FBTnode* node) {
    if (node == nullptr) return 0; 
    return THeight(node->left) - THeight(node->right); 
}

FBTnode* FBT::TRightRotate(FBTnode* node) {
    FBTnode* A = node->left; // левый потомок узла становится А
    FBTnode* B = A->right;  // правый потомок узла А становится В

    A->right = node; // А становится корнем, ноде становится правым потомком
    node->left = B; // левый потомок ноде становится В

    node->height = max(THeight(node->left), THeight(node->right)) + 1; // ноде и А становятся двумя разными поддеревьями
    A->height = max(THeight(A->left), THeight(A->right)) + 1;

    return A; // корень
}

FBTnode* FBT::TLeftRotate(FBTnode* node) { // симметрия
    FBTnode* A = node->right;
    FBTnode* B = A->left;

    A->left = node;
    node->right = B;

    node->height = max(THeight(node->left), THeight(node->right)) + 1;
    A->height = max(THeight(A->left), THeight(A->right)) + 1;

    return A;
}

FBTnode* FBT::TInsert(FBTnode* node,  string&key) {
    // если текущий узел пустой, создаем новый узел с переданным ключом
    if (node == nullptr) {
        return new FBTnode(key);
    }
    //рекурсивно вставляем в левое поддерево
    if (key < node->key) {
        node->left = TInsert(node->left, key);
    }
    // рекурсивно вставляем в правое поддерево
    else if (key > node->key) {
        node->right = TInsert(node->right, key);
    }
    // если ключ уже существует, возвращаем текущий узел 
    else {
        return node; //(без дубликатов)
    }

    node->height = 1 + max(THeight(node->left), THeight(node->right)); // обновляем высоту текущего узла

    // вычисляем баланс текущего узла
    int balance = TBalance(node);

    // левый-левый
    if (balance > 1 && key < node->left->key)
        return TRightRotate(node);

    // левый-правый
    if (balance > 1 && key > node->left->key) {
        node->left = TLeftRotate(node->left); //меняет местами
        return TRightRotate(node);
    }
    // правый-правый
    if (balance < -1 && key > node->right->key)
        return TLeftRotate(node);

    // правый-левый
    if (balance < -1 && key < node->right->key) {
        node->right = TRightRotate(node->right); // меняет местами
        return TLeftRotate(node);
    }

    return node; // возвращаем корень поддерева
}

FBTnode* FBT::TMinValueLeftNode(FBTnode* node) {
    FBTnode* current = node;
    while (current->left != nullptr) // идем по левому поддереву до самого левого узла
        current = current->left;
    return current;
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