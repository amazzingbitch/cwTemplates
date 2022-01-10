#include <iostream>
#define size 4

using namespace std;

template<typename T>

class Elem {
public:
    Elem() {
        next = nullptr; 
        arrSize = 0;
        
        for (int i = 0; i < size; i++) {
            array[i] = nullptr;
        }
    }
    
    ~Elem() {
        int i = 0;
        while (array[i] != nullptr) {
            delete array[i];
            i++;
        }
    }

    void ElemPrint() {
        for (int i = 0; array[i] != nullptr; i++) {
            cout << *array[i];
            if (array[i+1] != nullptr) 
                cout << " ";
        }
    }
    
    Elem* next;
    T* array[size + 1];
    int arrSize;
};
