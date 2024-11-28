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

void WritingFromFileToFullBinaryTree(FullBinaryTree& tree, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла  " << filename << endl;
        return;
    }

    string key;
    while (getline(inFile, key)) {
        tree.TINSERT(key);
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

void WritingFromFullBinaryTreeToFile(FullBinaryTree& tree, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    tree.SaveToFile(tree, filename);

    outFile.close();
}

// Функция обработки аргументов командной строки
void inputArguments(int argc, char* argv[], string& filename, string& query) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--file") == 0) {
            if (i + 1 < argc) {
                filename = argv[i + 1];
                i++;
            } else {
                cerr << "Ошибка: Отсутствует имя файла после --file" << endl;
                exit(1);
            }
        } else if (strcmp(argv[i], "--query") == 0) {
            if (i + 1 < argc) {
                query = argv[i + 1];
                i++;
            } else {
                cerr << "Ошибка: Отсутствует запрос после --query" << endl;
                exit(1);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    string filenameConsole = "";
    string queryConsole = "";

    // Получение аргументов командной строки
    inputArguments(argc, argv, filenameConsole, queryConsole);

    // Если запрос пустой и командная строка передана, присваиваем команду из аргументов
    if (queryConsole.empty() && argc > 2) {
        queryConsole = argv[2]; // Присваиваем команду из аргументов
    }

    Array array;
    Queue queue;
    Stack stack;
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;
    HashTable hashTable;
    FullBinaryTree tree;

    int index;
    string commandWord, element, indexStr;
    
    stringstream ss(queryConsole);
    ss >> commandWord;
    ss >> element;
    ss >> indexStr;

    indexStr.erase(0, indexStr.find_first_not_of(" \t"));
    cout << "Command: '" << commandWord << "', Element: '" << element << "', IndexStr: '" << indexStr << "'" << endl;
    
    try {
        if (commandWord.at(0) == 'M'){
            WritingFromFileToArray(array, filenameConsole);
            if (commandWord == "MPUSH") {
                if (indexStr.empty()) {
                    array.MPUSH_end(element);
                    cout << "Элемент добавлен в конец: " << element << endl;
                } else {
                    index = stoi(indexStr);
                    array.MPUSH_index(index, element);
                    cout << "Элемент добавлен по индексу " << index << ": " << element << endl;
                }
            } else if (commandWord == "MGET") {
                cout << indexStr;
                string value = array.MGET(stoi(element));
                cout << "Элемент по индексу " << element << ": " << value << endl;
            } else if (commandWord == "MDEL") {
                index = stoi(element);
                array.MDEL(index);
                cout << "Элемент с индексом " << index << " удален." << endl;
            } else if (commandWord == "MREP") {
                index = stoi(indexStr);
                array.MREP(index, element);
                cout << "Элемент с индексом " << index << " заменен на: " << element << endl;
            } else if (commandWord == "MSIZE") {
                int size = array.MSIZE();
                cout << "Размер коллекции: " << size << endl;
            } else if (commandWord == "MREAD") {
                array.MREAD();
            }
            WritingFromArrayToFile(array, filenameConsole);
        } else if (commandWord.at(0) == 'Q'){
            WritingFromFileToQueue(queue, filenameConsole);
            if (commandWord == "QPUSH") {
                queue.QPUSH(element);
            }
            else if(commandWord == "QPOP"){
                queue.QPOP();
            }
            else if(commandWord == "QREAD"){
                queue.QREAD();
            }
            WritingFromQueueToFile(queue, filenameConsole);
        } else if (commandWord.at(0) == 'S') {
            WritingFromFileToStack(stack, filenameConsole);
            if (commandWord == "SPUSH") {
                stack.SPUSH(element);
            }
            if (commandWord == "SPOP") {
                stack.SPOP();
            }
            if (commandWord == "SREAD") {
                stack.SREAD();
            }
            WritingFromStackToFile(stack, filenameConsole);
        } else if (commandWord.at(0) == 'L' && commandWord.at(1) == 'O'){
            WritingFromFileToSinglyLinkedList(singlyList, filenameConsole);
            if (commandWord == "LONEPUSH_head") {
                singlyList.LONEPUSH_head(element);
            }
            if (commandWord == "LONEPUSH_tail") {
                singlyList.LONEPUSH_tail(element);
            }
            if (commandWord == "LONEDEL_head") {
                singlyList.LONEDEL_head();
            }
            if (commandWord == "LONEDEL_tail") {
                singlyList.LONEDEL_tail();
            }
            if (commandWord == "LONEDEL_value") {
                singlyList.LONEDEL_value(element);
            }
            if (commandWord == "LONE_search") {
                singlyList.LONE_search(element);
            }
            if (commandWord == "LONE_read") {
                singlyList.LONE_read();
            }
            WritingFromSinglyLinkedListToFile(singlyList, filenameConsole);
        } else if (commandWord.at(0) == 'L' && commandWord.at(1) == 'T'){
            WritingFromFileToDoublyLinkedList(doublyList, filenameConsole);
            if (commandWord == "LTWOPUSH_head") {
                doublyList.LTWOPUSH_head(element);
            }
            if (commandWord == "LTWOPUSH_tail") {
                doublyList.LTWOPUSH_tail(element);
            }
            if (commandWord == "LTWODEL_head") {
                doublyList.LTWODEL_head();
            }
            if (commandWord == "LTWODEL_tail") {
                doublyList.LTWODEL_tail();
            }
            if (commandWord == "LTWODEL_value") {
                doublyList.LTWODEL_value(element);
            }
            if (commandWord == "LTWO_search") {
                doublyList.LTWO_search(element);
            }
            if (commandWord == "LTWO_read") {
                doublyList.LTWO_read();
            }
            WritingFromDoublyLinkedListToFile(doublyList, filenameConsole);
        } else if (commandWord.at(0) == 'H'){
            WritingFromFileToHashTable(hashTable, filenameConsole);
            string key = indexStr;
            string value = element;
            if (commandWord == "HPUSH") {
                hashTable.HPUSH(key, value);
            }
            if (commandWord == "HDEL") {
                hashTable.HDEL(key);
            }
            if (commandWord == "HGET") {
                hashTable.HGET(key);
            }
            if (commandWord == "HREAD") {
                hashTable.HREAD();
            }
            WritingFromHashTableToFile(hashTable, filenameConsole);
        } else if (commandWord.at(0) == 'T'){
            WritingFromFileToFullBinaryTree(tree, filenameConsole);
            if (commandWord == "TINSERT") {
                tree.TINSERT(element);
            }
            if (commandWord == "TFULL") {
                bool test = tree.TFULL();
                if (test == true){
                    cout << "Tree full!" << endl;
                } else {
                    cout << "The tree is not full!" << endl;
                }
            }
            if (commandWord == "TSEARCH") {
                tree.TSEARCH(element);
            }
            if (commandWord == "TREAD") {
                tree.TREAD();
            }
            WritingFromFullBinaryTreeToFile(tree, filenameConsole);
        } else {
            cout << "Неизвестная команда: " << commandWord << endl;
        }
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    
    return 0;
}