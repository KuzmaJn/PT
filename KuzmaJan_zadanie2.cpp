/*
Meno a priezvisko: Ján Kužma
*/

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

void prependNode(List* list, const int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = list->first;
    list->first = newNode;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

void appendNode(List* list, const int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    if(!list->first) {
        list->first = newNode;
    }
    else {
        Node *temp = list->first;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

List* createListFromArray(const int* data, const size_t n) {
    List *list = new List;
    list->first = nullptr;

    for (size_t i = 0; i < n; i++)
        prependNode(list, data[(n - 1) - i]);

    return list;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

List* createSymmetricList(const int val) {
    List *list = new List;
    list->first = nullptr;
    if(val < 0) {
        return nullptr;
    }
    else if(val == 0) {
        prependNode(list, 0);
    }
    else {
        for(int i = 0; i < val; i++) {
            prependNode(list, i);
        }
        for(int i = 0; i <= val; i++) {
            prependNode(list, val - i);
        }
    }
    return list;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

Result removeFirstNode(List* list) {
    if(list->first == nullptr) {
        return Result::FAILURE;
    }
    Node *temp = list->first;
    list->first = temp->next;
    delete temp;
    return Result::SUCCESS;
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

Node* findNodeInList(List* list, const int val) {
    Node *temp = list->first;

    while(temp != nullptr) {
        if(temp->data == val) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
bool areListsEqual(List* list1, List* list2) {
    Node * current1= list1->first;
    Node * current2= list2->first;
    while (current1 != nullptr and current2 != nullptr){
        if (current1->data == current2->data)
        {
            current1=current1->next;
            current2=current2->next;
        } else{
            return false;
        }

    }

    if (current1 != nullptr or current2 != nullptr)
        return false;

    return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}


//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

List* copyListReverse(List* list) {
    List *newList = new List;
    newList->first = nullptr;
    if(list->first == nullptr) {
        return newList;
    }

    Node *temp = list->first;

    do {
        prependNode(newList, temp->data);
        temp = temp->next;
    } while(temp != nullptr);
    return newList;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

Node* findPreviousNode(List* list, Node* node) {
    if (node->data == list->first->data) {
        return nullptr;                             //ak je hladany uzol na prvej pozicii v liste
    }
    Node *temp = list->first;
    do {
        if(temp->next->data == node->data) {        //ci je hodnota nasledujuceho uzla rovna hladanej hodnote
            break;                                  //ak ano cyklus konci
        }
        temp = temp->next;
    } while(temp != nullptr);
    return temp;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
void duplicatePositiveNodes(List* list) {
    if(list->first != nullptr) {
        Node *tmp = list->first;                //tmp reprezentuje povodne uzly

        do {
            if(tmp->data > 0) {
                Node *newNode = new Node;       //newNode bude duplikat tmp ak je tmp kladne
                newNode->data = tmp->data;
                newNode->next = tmp->next;
                tmp->next = newNode;
                tmp = tmp->next;                //presunutie na duplikat povodneho uzla

            }

            tmp = tmp->next;                    //presunutie na nasledujuci povodny uzol
        } while(tmp != nullptr);
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// vypis listu
void printList(const List *list) {
    Node *tmp = list->first;
    while (tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    // vytvorenie prazdneho listu
    List *list = new List;
    list->first = nullptr;

    // priradenie hodnot do listu --- ULOHA 1
    const int x = 5;
    for(int i = 0; i < x; i++) {
        prependNode(list, x - i);
    }

    prependNode(list, 10);            //uloha 1
    appendNode(list, 19);             //uloha 2
    printList(list);

    //uloha 3
    /*int data[5] = {1,0,-2,3,-4};
    List *list2 = createListFromArray(data, 1);
    printList(list2);
    */
    //uloha 4
    /*List *list3 = createSymmetricList(10);
    printList(list3);*/
/*  //uloha 5
    Result end = removeFirstNode(list);
    printList(list);
*/
    //uloha 6
    //Node *result = findNodeInList(list, 5);

    //uloha 7
    //bool result = areListsEqual(list, list2);

    //uloha 8
/*
    List *newList = copyListReverse(list);
    printList(list);
    printList(newList);
*/
    //uloha 9
/*
    Node *search = new Node;
    search->data = 6;
    search->next = nullptr;
    Node *returned = findPreviousNode(list2, search);
*/
    //uloha 10
    //duplicatePositiveNodes(list);
    //printList(list);
    return 0;
}

