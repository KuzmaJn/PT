/*
Meno a priezvisko:Ján Kužma
*/

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------
void change(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// Hmotnost produktu a obalu. Hmotnost zabaleneho produktu je suctom obidvoch zloziek
struct Weight {
    int product; // hmotnost produktu
    int packing; // hmotnost balenia
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void bubbleSort(int *data, const size_t length) {
    if(length <= 0) return;
    size_t i,j;
    for(i = 0; i < length; i++) {
        for( j = 0; j < length - i - 1; j++) {
            if(data[j] < data [j + 1]) {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void bubbleSort(Weight *data, const size_t length) {
    if(length <= 0) return;
    size_t i,j;
    for(i = 0; i < length; i++) {
        for( j = 0; j < length - i - 1; j++) {
            int current = data[j].packing + data[j].product;
            int next = data[j + 1].packing + data[j + 1].product;
            if(current < next) {
                Weight tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

size_t getPivotIndex(const int *data, const size_t low, const size_t high) {
    if(data == nullptr || low >= high) {
        return -1;
    }
    size_t mid = (low + high) / 2;

    if ((data[low] <= data[mid] && data[mid] <= data[high - 1]) ||
        (data[low] >= data[mid] && data[mid] >= data[high - 1])) {
        return mid;
    }
    else if ((data[low] <= data[high - 1] && data[high - 1] <= data[mid]) ||
             (data[low] >= data[high - 1] && data[high - 1] >= data[mid])) {
        return high - 1;
    }
    else {
        return low;
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

size_t partition(int *data, const size_t pivot, const size_t low, const size_t high) {
    change(&data[pivot], &data[high - 1]);    //premiestnenie pivota na posledne miesto, arr ktoru usporiadavame

    // preusporiadanie pola
    size_t index = low;
    for(size_t i = low; i < high; i++) {
        if(data[i] >= data[high - 1]) {
            change(&data[i],&data[index]);
            index++;
        }
    }
    return index - 1;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void quickSort(int *data, const size_t low, const size_t high) {
    if(low < high){

        size_t pivot_index = (high - 1);

        pivot_index = partition(data, pivot_index, low, high);

        quickSort(data, low, pivot_index);

        quickSort(data, pivot_index+1, high);
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

int main() {
    size_t length = 3;
    cout << length<< endl;
    int data[] = {1,3,2};
    bubbleSort(data, length);
    Weight package1 = {5, 1};
    Weight package2 = {8, 7};
    Weight package3 = {9, 1};
    Weight package4 = {15, 1};
    Weight data2[] = {package1, package2, package3, package4};
    bubbleSort(data2, 4);

    //uloha 3
    int data3[] = {10, 20, 2000, 30, 1000, 40, 5000, 50, 60, 70};
    size_t variable = getPivotIndex(data3, 2, 7);
    cout << variable;
    //size_t newPosPivot = partition(data3, 5, 2, 7);
    return 0;
}
