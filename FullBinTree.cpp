#include "structures.h"

#include <iostream>
#include <fstream>
using namespace std;

// O(N)
void FullBinaryTree::DestroyTree(FBTNode* node) {
    if (node == nullptr) {
        return;
    }
    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}

// O(logN)
void FullBinaryTree::TINSERT(string key) {
    if (root == nullptr) {
        root = new FBTNode(key);
        return;
    }
    TINSERT_HELPER(root, key);
}

// O(logN)
void FullBinaryTree::TINSERT_HELPER(FBTNode* node, string& key) {
    node->nodeCount++; // увеличиваем количество узлов текущего узла

    // выбираем поддерево для вставки
    if (node->left == nullptr) {
        node->left = new FBTNode(key);
    } else if (node->right == nullptr) {
        node->right = new FBTNode(key);
    } else if (node->left->nodeCount <= node->right->nodeCount) {
        TINSERT_HELPER(node->left, key);
    } else {
        TINSERT_HELPER(node->right, key);
    }
}

// O(N)
bool FullBinaryTree::TFULL() {
    return TFULL_HELPER(root);
}

// O(N)
bool FullBinaryTree::TFULL_HELPER(FBTNode* node) {
    if (node == nullptr) return true;
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }
    if (node->left != nullptr && node->right != nullptr) {
        return TFULL_HELPER(node->left) && TFULL_HELPER(node->right);
    }
    return false;
}

// O(N)
FBTNode* FullBinaryTree::TSEARCH(string key) {
    return TSEARCH_HELPER(root, key);
}

// O(N)
FBTNode* FullBinaryTree::TSEARCH_HELPER(FBTNode* node, const string& key) {
    if (node == nullptr) return nullptr;
    if (node->key == key) return node;

    FBTNode* leftSearch = TSEARCH_HELPER(node->left, key);
    if (leftSearch != nullptr) return leftSearch;

    return TSEARCH_HELPER(node->right, key);
}

// O(N)
void FullBinaryTree::TREAD() {
    TREAD_HELPER(root);
    cout << endl;
}

// O(N)
void FullBinaryTree::TREAD_HELPER(FBTNode* node) {
    if (node != nullptr) {
        cout << node->key << " ";
        TREAD_HELPER(node->left);
        TREAD_HELPER(node->right);
    }
}

// O(N)
void FullBinaryTree::SaveToFile(FullBinaryTree& tree, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Не удалось открыть файл для записи!" << endl;
        return;
    }
    SaveToFileHelper(tree.root, outFile);
    outFile.close();
}

// O(N)
void FullBinaryTree::SaveToFileHelper(FBTNode* node, ofstream& outFile) {
    if (!node) {
        outFile << "null ";
        return;
    }
    outFile << node->key << " ";
    SaveToFileHelper(node->left, outFile);
    SaveToFileHelper(node->right, outFile);
}


FullBinaryTree::~FullBinaryTree() {
    DestroyTree(root);
}