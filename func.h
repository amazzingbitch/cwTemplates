#ifndef COURSE_WORK_FUNC_H
#define COURSE_WORK_FUNC_H

#include <fstream>
using namespace std;

void saveBin(List <int> &lst) {
    ofstream fileOut;
    fileOut.open("binText.dat", ios::out | ios::binary);
    lst.binOut(fileOut);
    fileOut.close();
}

void loadBin(List <int> &lst) {
    ifstream fileIn;
    fileIn.open("binText.dat", ios::in | ios::binary);

    if (fileIn.peek() == std::ifstream::traits_type::eof()) {
        cout << "! The file is empty. Save something there first\n\n";
    } else {
        if (fileIn.is_open()) {
            lst.binIn(fileIn);
        }
    }
    fileIn.close();
}


#endif //COURSE_WORK_FUNC_H
