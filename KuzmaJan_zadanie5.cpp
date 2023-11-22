/*
Meno a priezvisko: Ján Kužma

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/


#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void siftUp(int data[], const size_t addIndex) {
    if (addIndex == 0) return;
    size_t iChild = addIndex;
    do {
        size_t iParent = (iChild - 1) / 2;

        if(data[iParent] > data[iChild]) {
            swap(&data[iParent], &data[iChild]);
        }

        iChild = iParent;
    } while (iChild != 0);
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void buildHeapSiftUp(int data[], const size_t length) {
    size_t i = 1;
    while(i != length) {
        siftUp(data, i);
        i++;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void siftDown(int data[], const size_t topIndex, const size_t length) {
    size_t iLeftChild = 2* topIndex + 1;
    size_t iRightChild = 2* topIndex + 2;
    size_t iSwap = topIndex;

    if(iLeftChild >= length) {
        return;
    }
    if(data[iLeftChild] >= data[iSwap] && data[iRightChild] >= data[iSwap]) {
        return;
    }
    if(data[iLeftChild] < data[iSwap]) {
        iSwap = iLeftChild;
    }
    if(iRightChild < length && data[iRightChild] < data[iSwap]) {
        iSwap = iRightChild;
    }
    if(iSwap != topIndex) {
        swap(&data[topIndex], &data[iSwap]);
        siftDown(data, iSwap, length);
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void buildHeapSiftDown(int data[], const size_t length) {
    for(size_t i = length/2 - 1; i != SIZE_MAX; i--){
        siftDown(data, i, length);
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void heapSort(int data[], const size_t length) {
    if(length == 0) return;

    buildHeapSiftDown(data, length);
    for (size_t i = length - 1; i > 0; i--) {

        swap(&data[0], &data[i]); // Move the root (minimum) element to the end

        siftDown(data, 0, i); // Restore the heap property
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

void printData(int *data, size_t length) {
    for(size_t i = 0; i < length; i++) {
        cout << data[i] << ", ";
    }
    cout << endl;
}

int main() {
    int data[] = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6};
    int len = 11;
    printData(data, len);

    //siftDown(data, 1, len); //buildHeapSiftDown(data, len);
    // buildHeapSiftUp(data, len); //siftUp(data, len);
    heapSort(data, len);
    printData(data, len);
    return 0;
}


