#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
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
    cout << endl << endl;

    delete[] _mass3;
    delete[] _mass4;



    int SIZE1 = 7;
    int SIZE2 = 9;

    int* arr1 = new int[SIZE1];
    int* arr2 = new int[SIZE2];
    int* result = new int[SIZE1 + SIZE2];
    
    arr1[0] = rand() % 10;
    cout << arr1[0] << " ";
    for (int i = 1; i < SIZE1; i++)
    {
        arr1[i] = arr1[i - 1] + rand() % 5 + 1;
        cout << arr1[i] << " ";
    }
    cout << endl;

    arr2[0] = rand() % 10;
    cout << arr2[0] << " ";
    for (int i = 1; i < SIZE2; i++)
    {
        arr2[i] = arr2[i - 1] + rand() % 5 + 1;
        cout << arr2[i] << " ";
    }
    cout << endl;



    int i = 0, j = 0, k = 0;

    while (i < SIZE1 && j < SIZE2)
    {
        if (arr1[i] < arr2[j]) {
            result[k] = arr1[i];
            i++;
        }
        else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < SIZE1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    int* _ptr = result + k;
    int* _ptr2 = arr2 + j;
    while (j < SIZE2)
    {
        *_ptr = *_ptr2;
        _ptr++;
        _ptr2++;
        j++;
        k++;
    }

    for (int* i = result; i < result + SIZE1 + SIZE2; i++)
    {
        cout << *i << " ";
    }
    cout << endl << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] result;
    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    const int SIZE10 = 10;

    Node* head = new Node;
    head->data = 1;
    head->next = nullptr;
    head->prev = nullptr;

    Node* current = head;

    for (int i = 2; i <= SIZE10; i++)
    {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = nullptr;
        newNode->prev = current;

        current->next = newNode;
        current = newNode;
    }

    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}
