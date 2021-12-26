#ifndef COURSE_WORK_NODE_H
#define COURSE_WORK_NODE_H

#define S 3

template<typename T>
class Node {
public:
    Node() { //Конструктор по умолчанию
        next = nullptr; ar_sz = 0;
        for (int i = 0; i < S; i++) {
            data[i] = nullptr;
        }
    }
    Node* next;
    T* data[S + 1];
    int ar_sz;
};
#endif //COURSE_WORK_NODE_H