#include "structures.h"

#include <iostream>
using namespace std;

// O(1)
void Array::MPUSH_end(string& value) {
    data[size++] = value;
}

// O(N)
void Array::MPUSH_index(const int& index, string& value) {
    if (index < 0 || index >= size ) {
        cout << endl << "Неверный ввод!" << endl; //
        return;
    }
    for (int i = size; i > index; i--) { 
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++; 
}

// O(1)
string Array::MGET(const int& index) {
    if (index < 0 || index >= size ) {
        cout << endl << "Неверный ввод!" << endl; //
        return "Ошибка!";
    }
    return data[index]; 
}

// O(N)
void Array::MDEL(const int& index) {
    if (index < 0 || index >= size ) {
        cout << endl << "Неверный ввод!" << endl; //
        return;
    }
    for (int i = index; i < size - 1; i++) { 
        data[i] = data[i + 1];
    }
    size--; 
}

// O(1)
void Array::MREP(const int& index, string& value) {
    if (index < 0 || index >= size ) {
        cout << endl << "Неверный ввод!" << endl; //
        return;
    }
    data[index] = value; 
}

// O(1)
int Array::MSIZE() {
    return size;  
}

// O(N)
void Array::MREAD() {
    cout << endl;
    for (int i = 0; i < size; i++) {  
        cout << data[i] << " ";
    }
    cout << endl;
}

Array::Array() : size(0), capacity(100) {
    data = new string[capacity];
}
Array::~Array() {
    delete[] data;  
}