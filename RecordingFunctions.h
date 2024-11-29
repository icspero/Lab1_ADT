#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "structures.h"

using namespace std;

void WritingFromFileToArray(Array& array, const string& filename);
void WritingFromFileToSinglyLinkedList(SinglyLinkedList& list, const string& filename);
void WritingFromFileToDoublyLinkedList(DoublyLinkedList& list, const string& filename);
void WritingFromFileToQueue(Queue& queue, const string& filename);
void WritingFromFileToStack(Stack& stack, const string& filename);
void WritingFromFileToHashTable(HashTable& hashTable, const string& filename);
// ------------------------------------------------------------------------------------
void WritingFromArrayToFile(Array& array, const string& filename);
void WritingFromSinglyLinkedListToFile(SinglyLinkedList& list, const string& filename);
void WritingFromDoublyLinkedListToFile(DoublyLinkedList& list, const string& filename);
void WritingFromQueueToFile(Queue& queue, const string& filename);
void WritingFromStackToFile(Stack& stack, const string& filename);
void WritingFromHashTableToFile(HashTable& hashTable, const string& filename);
