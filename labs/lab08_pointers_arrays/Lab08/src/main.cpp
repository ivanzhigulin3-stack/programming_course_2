#include <iostream>

using namespace std;



int main() {
    setlocale(LC_ALL, "RU");
    const int size = 10;
    int size2 = 12;
    int _mass1[size];
    int _mass2[size];
    int* _mass3 = new int[size2];
    int* _mass4 = new int[size2];
   

    for (int i = 0; i < size; i++)
    {
        _mass1[i] = i * i;
        cout << _mass1[i] << " ";
    }
    cout << endl;
    
    for (int* ptr = _mass2; ptr < _mass2 + size; ptr++) {
        *ptr = (ptr - _mass2) * (ptr - _mass2);

        cout << *ptr << " ";
    }
    cout << endl;

    for (int i = 0; i < size2; i++)
    {
        _mass3[i] = i * i;
        cout << _mass3[i] << " ";
    }
    cout << endl;
    
    for (int* ptr = _mass4; ptr < _mass4 + size2; ptr++) {
        *ptr = (ptr - _mass4) * (ptr - _mass4);

        cout << *ptr << " ";
    }
    cout << endl;

    delete[] _mass3;
    delete[] _mass4;


    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    return 0;
}
