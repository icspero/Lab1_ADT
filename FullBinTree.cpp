#include "structures.h"

#include <iostream>
using namespace std;



// Очистка дерева
void DestroyTree(FBTNode* node) {
    if (node == nullptr) {
        return;
    }
    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}

void InsertHelper(FBTNode* node, string& key) {
    // Если у узла отсутствует левый потомок
    if (node->left == nullptr) {
        node->left = new FBTNode(key);
    }
    // Если у узла отсутствует правый потомок
    else if (node->right == nullptr) {
        node->right = new FBTNode(key);
    }
    // Рекурсивно идём по левому и правому поддеревьям
    else if (CountNodes(node->left) <= CountNodes(node->right)) {
        InsertHelper(node->left, key);
    } else {
        InsertHelper(node->right, key);
    }
}

// Вставка узла
void Insert(string key) {
    if (root == nullptr) {
        root = new FBTNode(key);
        return;
    }
    InsertHelper(root, key);
}

// Подсчёт узлов в поддереве
int CountNodes(FBTNode* node) {
    if (node == nullptr) return 0;
    return 1 + CountNodes(node->left) + CountNodes(node->right);
}

// Проверка, является ли дерево Full Binary Tree
bool IsFullBinaryTree() {
    return IsFullBinaryTreeHelper(root);
}

bool IsFullBinaryTreeHelper(FBTNode* node) {
    if (node == nullptr) return true;

    // Если у узла нет потомков, это корректный узел
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }

    // Если у узла оба потомка присутствуют, проверяем их рекурсивно
    if (node->left != nullptr && node->right != nullptr) {
        return IsFullBinaryTreeHelper(node->left) &&
                IsFullBinaryTreeHelper(node->right);
    }

    // Если у узла один потомок, это не Full Binary Tree
    return false;
}

// Поиск элемента
FBTNode* Search(string key) {
    return SearchHelper(root, key);
}

FBTNode* SearchHelper(FBTNode* node, const string& key) {
    if (node == nullptr) return nullptr;

    // Если ключ совпал, возвращаем узел
    if (node->key == key) return node;

    // Рекурсивный поиск в левом поддереве
    FBTNode* leftSearch = SearchHelper(node->left, key);
    if (leftSearch != nullptr) return leftSearch;

    // Если в левом поддереве не найдено, ищем в правом
    return SearchHelper(node->right, key);
}

// Отображение дерева (обход в глубину)
void TREAD() {
    TREAD_HELPER(root);
    cout << endl;
}

void TREAD_HELPER(FBTNode* node) {
    if (node != nullptr) {
        cout << node->key << " ";
        TREAD_HELPER(node->left);
        TREAD_HELPER(node->right);
    }
}