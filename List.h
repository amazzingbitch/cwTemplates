#include "Elem.h"

template<typename T>
class List {
public:
    List();
    ~List();
    void addPointer(T& n);
    Elem<T>* searchByPosition(int& p);
    T* operator[](int p);
    void printList();
    void makeBalanced();
    void insertAndKeep(T* n);
    T* deleteByPosition(int p);
    void saveBinary(ofstream& file);
    void loadBinary(ifstream& file);
    void printStatus();
    void insertByPosition(T* n, int p);
    void sortList();
    bool isListEmpty();
    void freeList();
    Elem<T>* findMin();
    Elem<T>* findMax();
    void saveText(fstream& file);
    void loadText(fstream& file);


private:
    Elem<T>* head;
    int listSize, amount;
};
template
class List<string>;

template
class List<int>;

template
class List<float>;

template
class List<double>;

template
class List<char>;

template
class List<unsigned int>;

template
class List<long>;

template
class List<long long>;

template
class List<short>;