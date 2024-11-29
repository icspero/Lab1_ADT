#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "structures.h"
#include "RecordingFunctions.h"

using namespace std;

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
    FBT tree;

    int index;
    string commandWord, element, indexStr;
    
    stringstream ss(queryConsole);
    ss >> commandWord;
    ss >> element;
    ss >> indexStr;

    indexStr.erase(0, indexStr.find_first_not_of(" \t"));
    //cout << "Command: '" << commandWord << "', Element: '" << element << "', IndexStr: '" << indexStr << "'" << endl;

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
                cout << "Элемент добавлен!" << endl;
            }
            else if(commandWord == "QPOP"){
                queue.QPOP();
                cout << "Элемент удалён!" << endl;
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
            tree.TLoadFromFile(filenameConsole);
            if (commandWord == "TPUSH") {
                tree.TPUSH(element);
                cout << "Элемент успешно добавлен!" << endl;
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
                bool test = tree.TSEARCH(element);
                if (test){
                    cout << "Элемент найден!" << endl;
                } else {
                    cout << "Элемент не найден!" << endl;
                }
            }
            if (commandWord == "TREAD") {
                tree.TREAD();
            }
            tree.TSaveToFileHelper(filenameConsole);
        } else {
            cout << "Неизвестная команда: " << commandWord << endl;
        }
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    
    return 0;
}