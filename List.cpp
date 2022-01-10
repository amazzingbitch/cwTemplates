#include <iostream>
#include <fstream>
#include "List.h"

#define N 0.5

using namespace std;

template<typename T>
List<T>::List() {
    head = nullptr;
    listSize = 0;
    amount = 0;
}

template<typename T>
void List<T>::freeList() {
    while (head != nullptr) {
        deleteByPosition(0);
    }
    listSize = 0;
    amount = 0;
}

template<typename T>
List<T>::~List() { freeList(); }

template<typename T>
bool List<T>::isListEmpty() {
    return (head == nullptr);
}

template <typename T>
void List<T>::addPointer(T& n) {
    if (isListEmpty()) {
        head = new Elem<T>();
        head->next = nullptr;
        listSize++;
        head->array[0] = &n;
        head->array[1] = nullptr;
        head->arrSize++;
    }
    else {
        Elem<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        if (current->arrSize < size) {
            current->array[current->arrSize] = &n;
            current->array[current->arrSize + 1] = nullptr;
            current->arrSize++;
        } else {
            Elem<T>* temp;
            temp = new Elem<T>();
            current->next = temp;
            temp->next = nullptr;
            listSize++;
            temp->array[0] = &n;
            temp->array[1] = nullptr;
            int k = 0;
            for (int i = size * N; i < size; i++, k++)
            {
                temp->array[k] = current->array[i];
                temp->arrSize++;
                current->arrSize--;
                current->array[i] = nullptr;
            }
            temp->array[k] = &n;
            temp->array[k + 1] = nullptr;
            temp->arrSize++;
        }
    }
    amount++;
}

template <typename T>
void List<T>::insertByPosition(T* n, int p) {
    int m = p;
    Elem<T>* current = searchByPosition(p);
    if (current != nullptr) {
        if (current->arrSize >= size) {
            Elem<T> *temp, *k;
            temp = new Elem<T>();
            k = current->next;
            current->next = temp;
            temp->next = k;
            int j = 0;
            for (int i = size * N; i < size; i++, j++) {
                temp->array[j] = current->array[i];
                temp->arrSize++;
                current->arrSize--;
                current->array[i] = nullptr;
            }
            temp->array[j + 1] = nullptr;
            current = searchByPosition(m);
            p = m;
        }
        for (int i = current->arrSize - 1; i >= p; i--)
            current->array[i + 1] = current->array[i];
        current->array[p] = n;
        current->arrSize++;
        amount++;
    } else {
        if (amount == 0 && p >= 0)
            addPointer(*n);
    }
}

template <typename T>
T* List<T>::deleteByPosition(int p) {
    if (amount) {
        Elem<T> *current = searchByPosition(p);
        if (current != nullptr) {
            T *del = current->array[p];
            for (int i = p; i < current->arrSize; i++)
                current->array[i] = current->array[i + 1];
            current->arrSize--;
            amount--;
            if (current->array[0] == nullptr) {
                if (current == head)
                    head = head->next;
                else {
                    Elem<T> *k = head;
                    while (k->next != current)
                        k = k->next;
                    k->next = current->next;
                }
                delete current;
                listSize--;
            }
            return del;
        } else {
            return nullptr;
        }
    } else {
        cout << "can't delete element, list is empty\n";
        return nullptr;
    }
}

template<typename T>
Elem<T>* List<T>::searchByPosition(int& p) {
    if (p < 0) {
        cout << "position can't be negative\n";
        return nullptr;
    }
    if (p >= amount && amount != 0) {
        cout << "position can't be more than amount of pointers\n";
        return nullptr;
    }
    Elem<T>* current = head;
    while (current != nullptr) {
        if (p < current->arrSize)
            break;
        p = p - (current->arrSize);
        current = current->next;
    }
    return current;
}

template <typename T>
T* List<T>::operator[](int p) {
    if (p < 0 || p >= amount)
        return nullptr;
    return searchByPosition(p)->array[p];
}

template <typename T>
void List<T>::sortList() {
    if (!(isListEmpty())) {
        Elem<T> *iElem, *jElem, *minElem;
        T *tmp;
        int i = 0, j, iMin;
        iElem = head;
        while (iElem != nullptr) {
            minElem = jElem = iElem;
            iMin = j = i;
            while (jElem != nullptr) {
                if (*jElem->array[j] < *minElem->array[iMin]) {
                    minElem = jElem;
                    iMin = j;
                }
                if (jElem->array[j + 1] == nullptr) {
                    jElem = jElem->next;
                    j = 0;
                } else j++;
            }
            tmp = minElem->array[iMin];
            minElem->array[iMin] = iElem->array[i];
            iElem->array[i] = tmp;
            if (iElem->array[i + 1] == nullptr) {
                iElem = iElem->next;
                i = 0;
            } else i++;
        }
        cout << "list was sorted successfully\n";
    } else {
        cout << "list is empty, there is nothing to sort\n";
    }
}

template <typename T>
void List<T>::insertAndKeep(T* n) {
    Elem<T>* current = head;
    int k = 0, f = 0;
    while (current != nullptr) {
        for (int i = 0; i < current->arrSize; i++, k++)
            if (*current->array[i] >= *n) {
                cout << "position was found: " << k << "\n";
                insertByPosition(n, k);
                f = 1;
                break;
            }
        if (f)
            break;
        current = current->next;
    }
    if (!f) {
        cout << "position was found: " << amount << "\n";
        addPointer(*n);
    }
}

template <typename T>
Elem<T>* List<T>::findMin() {
    Elem<T>* current = head->next, *min = head;
    while (current != nullptr) {
        if (current->arrSize < min->arrSize)
            min = current;
        current = current->next;
    }
    return min;
}

template <typename T>
Elem<T>* List<T>::findMax() {
    Elem<T>* current = head->next, * max = head;
    while (current != nullptr) {
        if (current->arrSize > max->arrSize)
            max = current;
        current = current->next;
    }
    return max;
}

template <typename T>
void List<T>::makeBalanced() {
    if (!isListEmpty()) {
        Elem<T>* max = findMax(), *min = findMin();
        while (max->arrSize - min->arrSize > 1) {
            min->array[min->arrSize] = max->array[max->arrSize - 1];
            max->array[max->arrSize - 1] = nullptr;
            min->arrSize++;
            max->arrSize--;
            max = findMax();
            min = findMin();
        }
        cout << "list was successfully balanced\n";
    } else {
        cout << "can't balance an empty list\n";
    }
}

template <typename T>
void List<T>::saveBinary(ofstream& file) {
    if (file.is_open()) {
        Elem<T>* current = head;
        while (current != nullptr) {
            file.write((char *) &current->arrSize, sizeof(int));
            for (int i = 0; i < current->arrSize; i++)
                file.write((char *) &(*(current->array[i])), sizeof(T));
            current = current->next;
        }
        cout << "list was saved to the file\n";
        file.close();
    }
}

template <typename T>
void List<T>::loadBinary(ifstream& file) {
    if (file.peek() == std::ifstream::traits_type::eof()) {
        cout << "file is empty, can't load the list\n";
    } else {
        if (file.is_open()) {
            T* temp;
            int count;
            if (head != nullptr)
                freeList();
            while (file.peek() != EOF) {
                file.read((char *) &count, sizeof(int));
                temp = new T[count];
                for (int i = 0; i < count; i++) {
                    file.read((char *) &temp[i], sizeof(T));
                    addPointer(temp[i]);
                }
            }
        }
        file.close();
        cout << "list was loaded successfully\n";
    }
}

template <typename T>
void List<T>::printList() {
    Elem<T>* current = head;
    if (isListEmpty()) {
        cout << "list is empty, add or load elements first\n";
        return;
    }
    while (current != nullptr) {
        current->ElemPrint();
        current = current->next;
        cout << "\n";
    }
}

template <typename T>
void List<T>::printStatus() {
    cout << "=============================================\n";
    cout << "number of list elements: " << listSize << "\nnumber of pointers: " << amount << "\n";
}

template <typename T>
void List<T>::saveText(fstream& file) {
    if (file.is_open()) {
        Elem<T> *current = head;
        while (current != nullptr) {
            file << current->arrSize;
            for (int i = 0; i < current->arrSize; i++) {
                file << " " << *(current->array[i]);
            }
            current = current->next;
            if (current != nullptr) file << endl;
        }
        cout << "list was saved to the file\n";
        file.close();
    }
}

template <typename T>
void List<T>::loadText(fstream& file) {
    if (file.peek() == std::ifstream::traits_type::eof()) {
        cout << "file is empty, can't load the list\n";
    } else {
        if (file.is_open()) {
            T* temp;
            int count;
            if (head != nullptr)
                freeList();
            while (file.peek() != EOF) {
                file >> count;
                temp = new T[count];
                for (int i = 0; i < count; i++) {
                    file >> temp[i];
                    addPointer(temp[i]);
                }
            }
        }
        file.close();
        cout << "list was loaded successfully\n";
    }
}

// специализация

template<>
void List<string>::saveBinary(ofstream& file) {
    if (file.is_open()) {
        Elem<string> *current = head;
        while (current != nullptr) {
            file.write((char *) &current->arrSize, sizeof(int));
            for (int i = 0; i < current->arrSize; i++) {
                size_t len = (current->array[i])->length()+1;
                file.write((char*)&len, sizeof(size_t));
                file.write((char *) ((current->array[i]))->c_str(), sizeof(char)*len);
            }
            current = current->next;
        }
        cout << "list was saved to the file\n";
        file.close();
    }
}
template<>
void List<string>::loadBinary(ifstream& file) {
    if (file.peek() == std::ifstream::traits_type::eof()) {
        cout << "file is empty, can't load the list\n";
    } else {
        if (file.is_open()) {
            char* temp;
            int count;
            if (head != nullptr)
                freeList();
            while (file.peek() != EOF) {
                file.read((char *) &count, sizeof(int));
                for (int i = 0; i < count; i++) {
                    size_t len;
                    file.read((char*)&len, sizeof(len));
                    temp = new char[len];
                    file.read(temp, len);
                    auto *str = new string(temp);
                    addPointer(*str);
                }
            }
        }
        file.close();
        cout << "list was loaded successfully\n";
    }
}

