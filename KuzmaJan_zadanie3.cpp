/*
Meno a priezvisko: Jan Kuzma
*/
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void insertionSort(int *data, const size_t length) {
    for(size_t i = 1; i < length; i++) {
        int tmp = data[i];
        size_t j = i;
        while (j > 0 && data[j - 1] < tmp) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }
}


//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void insertionSort(const char *data[]) {
    if(data == nullptr || data[0] == nullptr) {
        return;
    }

    int i = 1;
    while(data[i] != nullptr) {
        int j = i-1;
        const char *tmp = data[i];

        while (j >= 0 && strcmp(data[j], tmp) < 0) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = tmp;
        i++;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void insertionSort(List * list) {
    if(list == nullptr || list->first == nullptr || list->first->next == nullptr) {
        // list sa nezmeni ... uz je usporiadany
        return;
    }

    Node* sortedList = nullptr; // inicializacia prazneho zoznamu

    while (list->first != nullptr) {
        Node* current = list->first;
        list->first = current->next; // odstrani current uzol z povodneho zoznamu

        if (sortedList == nullptr || current->data >= sortedList->data) {
            // ak je current rovny alebo vacsi ako prvy uzol,
            // prida sa na zaciatok noveho zoznamu sortedList
            current->next = sortedList;
            sortedList = current;
        } else {
            // hladanie spravnej pozicie v zozname pre uzol current
            Node* prev = sortedList;
            while (prev->next != nullptr && prev->next->data > current->data) {
                // ak je uzol current mensi ako data nasledujuceho uzla a zaroven nasledujuci uzol nie je nullptr,
                // tak prev menime na nasledujuci uzol
                // pozn. prev->next je nasledujuci uzol, napr. prev = {2, uzol{3, uzol2}}
                // cize porovnavame current->data s 3
                prev = prev->next;
            }
            current->next = prev->next;
            prev->next = current;
        }
    }

    list->first = sortedList; // povodny list updatujeme
}


//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
void mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high) {
    size_t in1 = low;
    size_t in2 = middle;
    size_t out = low;

    // Merge the two subarrays while maintaining the descending order.
    while (in1 < middle && in2 < high) {
        if (input[in1] >= input[in2]) {
            output[out] = input[in1];
            ++in1;
        } else {
            output[out] = input[in2];
            ++in2;
        }
        ++out;
    }

    // Copy any remaining elements from the left subarray (if any).
    while (in1 < middle) {
        output[out] = input[in1];
        ++in1;
        ++out;
    }

    // Copy any remaining elements from the right subarray (if any).
    while (in2 < high) {
        output[out] = input[in2];
        ++in2;
        ++out;
    }
}


//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------

void mergeSort(int *data, const size_t length) {
    int *temp = new int[length];

    int *input = data;
    int *output = temp;
    bool need = false;
    for (size_t step = 1; step < length; step *= 2) {
        for(size_t i = 0; i < length; i += 2*step) {
            size_t low = i;
            size_t middle = min(i + step, length);
            size_t high = min(i + 2 * step, length);
            mergeNeighbours(output, input, low, middle, high);
        }
        need = ! need;

        int *c = *(&input);
        *(&input) = *(&output);
        *(&output) = c;
    }
    if(need) {
        memcpy(data, temp, length * sizeof(int));
    }

    delete[] temp;

}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
/*
    Node fourth= {1, nullptr};
    Node third = {2, &fourth};
    Node second = {1, &third};
    Node first = {2, &second};
    List *list = nullptr;
    // uloha 1
    size_t length = 5;
    int data[5] = {3, 2, 1, 4, 5};
    insertionSort(data, length);
    // uloha 2
    const char *mena[] = {nullptr};
    insertionSort(mena);
    //uloha 3
    insertionSort(list);

    //uloha 4
    int input[] = {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10};
    int output[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

    mergeNeighbours(output, input, 4, 8, 12);
    */
    int data[7] = {1,5,7,9,3,6,1};
    mergeSort(data,7);
    for(int i : data) {
        cout<<i<<" ";
    }
    return 0;
}
