#include <iostream>
#include "List.cpp"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int printMenu();
void menu();

int main() {
    menu();
    return 0;
}

int printMenu() {
    cout << "=============================================\n";
    cout << "  0.  leave the program\n";
    cout << "  1.  add new pointer\n";
    cout << "  2.  insert by position\n";
    cout << "  3.  insert & keep order\n";
    cout << "  4.  get by position\n";
    cout << "  5.  delete by position\n";
    cout << "  6.  sort the list\n";
    cout << "  7.  balance the list\n";
    cout << "  8.  save list in binary file\n";
    cout << "  9.  load list from binary file\n";
    cout << "  10. print out list\n";
    cout << "  11. save list in text file\n";
    cout << "  12. load list from text file\n";
    cout << "=============================================\n";
    cout << "choose menu option & enter number:";
    int k = 0;
    cin >> k;
    return k;
}

void menu() {
    List <string> obj;
    string* str;
    ofstream file;
    ifstream file2;
    fstream file3;
    int p = 0, t;
    bool f = true;
    while (f) {
        obj.printStatus();
        t = printMenu();
        switch (t) {
            case 0:
                f = false;
                break;
            case 1: {
                cout << "enter element:";
                str = new string;
                cin >> *str;
                obj.addPointer(*str);
                break;
            }
            case 2: {
                cout << "enter element:";
                str = new string;
                cin >> *str;
                cout << "enter position:";
                cin >> p;
                obj.insertByPosition(str, p);
                break;
            }

            case 3: {
                cout << "enter element:";
                str = new string;
                cin >> *str;
                obj.insertAndKeep(str);
                break;
            }

            case 4: {
                cout << "enter position of element you want to get:";
                cin >> p;
                if (obj[p] != nullptr)
                    cout << "element in position " << p << ":" << *obj[p] << "\n";
                else
                    cout << "position is invalid\n";
                break;
            }
            case 5: {
                cout << "enter position of element you want to delete:";
                cin >> p;
                string* str2;
                str2 = obj.deleteByPosition(p);
                if (str2 != nullptr) {
                    cout << "deleted element is " << *str2 << "\n";
                }
                break;
            }
            case 6: {
                obj.sortList();
                break;
            }

            case 7: {
                obj.makeBalanced();
                break;
            }

            case 8: {
                file.open("bin.dat");
                obj.saveBinary(file);
                break;
            }

            case 9: {
                file2.open("bin.dat", ios::in | ios::binary);
                obj.loadBinary(file2);
                break;
            }
            case 10: {
                obj.printList();
                break;
            }
            case 11: {
                file3.open("text.txt", fstream::out);
                obj.saveText(file3);
                break;
            }
            case 12: {
                file3.open("text.txt", fstream::in);
                obj.loadText(file3);
                break;
            }
            default:
                cout << "please try again and enter a number of menu option\n";
                break;
        }
    }
}

/*List <int> obj, obj1, obj2;
    List <char> obj0, obj01, obj02;
    int* str;
    for (int i = 0; i < 1000; i++) {
        str = new int;
        *str = rand()%100;
        obj.addPointer(*str);
    }
    for (int i = 0; i < 10000; i++) {
        str = new int;
        *str = rand()%100;
        obj1.addPointer(*str);
    }
    for (int i = 0; i < 50000; i++) {
        str = new int;
        *str = rand()%100;
        obj2.addPointer(*str);
    }
    srand(time(NULL));
    clock_t startTime = clock();
    obj.sortList();
    cout << "[int] 1000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
    startTime = clock();
    obj1.sortList();
    cout << "[int] 10000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
    startTime = clock();
    obj2.sortList();
    cout << "[int] 50000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
    char* str0;
    for (int i = 0; i < 1000; i++) {
        str0 = new char;
        *str0 = 'A'+rand()%('z'-'A');
        obj0.addPointer(*str0);
    }
    for (int i = 0; i < 10000; i++) {
        str0 = new char;
        *str0 = 'A'+rand()%('z'-'A');
        obj01.addPointer(*str0);
    }
    for (int i = 0; i < 50000; i++) {
        str0 = new char;
        *str0 = 'A'+rand()%('z'-'A');
        obj02.addPointer(*str0);
    }
    startTime = clock();
    obj0.sortList();
    cout << "[char] 1000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
    startTime = clock();
    obj01.sortList();
    cout << "[char] 10000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
    startTime = clock();
    obj02.sortList();
    cout << "[char] 50000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
*/
/*
    case 11: {
                startTime = clock();
                file3.open("text.txt", fstream::out);
                obj02.saveText(file3);
                cout << "[char] 1000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
                break;
            }
    case 12: {
                startTime = clock();
                file3.open("text.txt", fstream::in);
                obj02.loadText(file3);
                cout << "[char] 1000: " << (float)(clock() - startTime)/CLOCKS_PER_SEC << endl;
                break;
            }
 */