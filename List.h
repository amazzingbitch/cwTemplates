#include "Node.h"

using namespace std;
template<typename T>
class List {
public:
    List();
    ~List();
    void Add(T& n);
    void ListPrint();
    bool IsEmpty();
    T* Delete(int pos);
    ofstream &binOut(ofstream &os);
    ifstream &binIn(ifstream &is);
private:
    Node<T>* head;
    int list_sz;
};