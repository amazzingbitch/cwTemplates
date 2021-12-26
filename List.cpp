#include <iostream>
#include "List.h"
#include <fstream>
#define N 0.5
using namespace std;

template<typename T>
List<T>::List() {
    head = nullptr;
    list_sz = 0;
}

template<typename T>
List<T>::~List() {
    while (!IsEmpty()) {
        Delete(0);
    }
}

template<typename T>
bool List<T>::IsEmpty() {
    if (list_sz == 0)
        return true;
    else
        return false;
}

template<typename T>
void List<T>::Add(T& n) {//добавление в конец списка
    if (IsEmpty()) { //добавление заголовка
        head = new Node<T>();
        head->next = nullptr;
        head->data[0] = &n;
        head->data[1] = nullptr;
        head->ar_sz++;
        list_sz++;
    }
    else {
        Node<T>* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        if (cur->ar_sz < S)//если текущий массив указателей заполнен не полностью, добавляем в него новый элемент
        {
            cur->data[cur->ar_sz] = &n;
            cur->data[cur->ar_sz + 1] = nullptr;
            cur->ar_sz++;
        }
        else {// иначе - создаем новый элемент списка, записываем в его массив первый элемент
            Node<T>* temp;
            temp = new Node<T>;
            cur->next = temp;
            temp->next = nullptr;
            temp->ar_sz = 1;
            list_sz++;
            temp->data[0] = &n;
            temp->data[1] = nullptr;
        }
    }
}

template <typename T>
T* List<T>::Delete(int pos) {//удаление по позиции
    if (pos < 0) {
        return nullptr;
    }
    Node<T>* cur = head, * p;
    T* deleted;
    while (true) {
        if (pos < cur->ar_sz)
            break;
        pos = pos - (cur->ar_sz);
        p = cur;
        cur = cur->next;
    }
    deleted = cur->data[pos];
    cur->ar_sz;
    for (int i = pos + 1; i < cur->ar_sz + 1; i++)
        cur->data[i - 1] = cur->data[i];
    cur->ar_sz--;
    if (cur->data[0] == nullptr) {
        if (cur == head) {
            head = head->next;
        } else {
            p->next = cur->next;
        }

        list_sz--;
        delete cur;
    }
    return deleted;
}


template <typename T>
void List<T>::ListPrint() {//учесть случай, когда список пустой
    if (head != nullptr) {
        Node<T>* cur = head;
        while (cur != nullptr) {
            for (int i = 0; cur->data[i] != nullptr; i++)
                cout << *(cur->data[i]) << " ";
            cur = cur->next;
            cout << "\n";
        }
    }
}

template<typename T>
ofstream &List<T>::binOut(ofstream &os) {
    Node<T> *p = head;
    while (p != nullptr) {
        os.write((char *)&p->ar_sz, sizeof(int));
        for (int i = 0; i < p->ar_sz; i++) {
            int k = *p->data[i];
            os.write((char *)&k, sizeof(int));
        }
        p = p->next;
    }
    return os;
}

template<typename T>
ifstream &List<T>::binIn(ifstream &is) {
    is.seekg(0, ios::end);
    long long size = is.tellg();
    is.seekg(0, ios::beg);
    while (is.tellg() != size) {
        int v;
        int arr_size = -1;
        is.read((char *) &arr_size, sizeof(int));
        int* arr = new int[arr_size];
        for (int i = 0; i < arr_size; i++) {
            is.read((char *) &arr[i], sizeof(int));
            Add(arr[i]);
        }

        cout << "\n";
        //delete[] arr;

    }
    return is;
}