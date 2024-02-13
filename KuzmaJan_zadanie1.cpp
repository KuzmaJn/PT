/*
Meno a priezvisko:Ján Kužma
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Bod v rovine
struct Point {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Usecka v rovine
struct Line {
    Point start; // zaciatocny bod
    Point end;   // koncovy bod
};

// Student
struct Student {
    char *name; // meno studenta
    int year;  // rocnik studia
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

// Matematicka funkcia
enum class Operation {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
};

// Vstup pre matematicky vypocet funkcie s dvoma parametrami
struct CalculationInput {
    int operand1; // prvy parameter
    int operand2; // druhy parameter
    Operation operation; // funkcia
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

void printArray(const int * data, std::size_t length) {
    if(length == 0) {
        cout << "()" << endl;
    }
    else {
        cout << "(";
        for (int i = 0; i < length; i++) {
            if (i == length - 1) {
                cout << data[i] << ")" << endl;
            } else {
                cout << data[i] << " ";
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

int sumOfTwoNumbersFromConsole(){
    int x, y;
    cin >> x >> y;
    return x + y;
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

bool containsUpperCase(const char *text) {
    int i = 0;
    while(isalpha(text[i])){
        if(isupper(text[i])){
            return true;
        }
        i++;
    }
    return false;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

bool isAscending(const int *data, std::size_t length) {
    for(int i = 1; i < length; i++){
        if(data[i - 1] >= data[i]){
            return false;
        }
    }
    return true;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

void shiftUp(int *data, std::size_t length) {
    if(length == 0) {
        //TODO;
    }
    else {
        int saved = data[length - 1];
        for (int i = 1; i < length; i++) {
            data[length - i] = data[length - (i + 1)];
        }
        data[0] = saved;
    }
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

void reverse(int * data, std::size_t length) {

    for(int i = 0; i < length/2; i++){
        int savedN = data[i];
        data[i] = data[length - (i + 1)];
        data[length - (i + 1)] = savedN;
    }
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

double length(const Line * line) {
    double x_squared = pow(line->end.x - line->start.x, 2);
    double y_squared = pow(line->end.y - line->start.y, 2);
    double length = sqrt(x_squared + y_squared);
    return length;
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Implementujte rovnaku funkcionalitu ako v predchadzajucom priklade. Rozdielny je len typ parametra funkcie.
*/
double length(const Line & line) {

    double x_squared = pow(line.end.x - line.start.x, 2);
    double y_squared = pow(line.end.y - line.start.y, 2);
    double length = sqrt(x_squared + y_squared);
    return length;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------

Student * createStudent(const char *name, int year) {
    Student *newStudent;
    newStudent = new Student;                               //alokacia pamate pre studenta --- new lebo Student je single object

    newStudent->name = new char[strlen(name) + 1];      //alokacia pamate pre name ---- new[] lebo name je array,
    //strlen(name) + 1 ---- dlzka retazca name +1 => pre ukoncovaci znak
    strcpy(newStudent->name, name);
    newStudent->year = year;

    return newStudent;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vypocita celociselny matematicky vypocet zadany parametrom 'input'.
    Vysledok ulozi do 'output'.

    PARAMETRE:
        [in] input - vstupne udaje pre matematicky vypocet
        [out] output - vystupna hodnota vypoctu (v pripade moznosti vypoctu)

    NAVRATOVA HODNOTA:
        Result::SUCCESS - ak je mozne vypocitat vyslednu hodnotu
        Result::FAILURE - ak nie je mozne vypocitat vyslednu hodnotu (v pripade delenia nulou)

    VYSTUPNE PODMIENKY:
        - Vysledok vypoctu je celociselny.
        - Ak je mozne vykonat vypocet, tak sa vysledok ulozi do 'output' a funkcia vrati 'Result::SUCCESS',
          inak (v pripade delenia nulou) sa hodnota 'output' nemeni a funkcia vrati 'Result::FAILURE'.
*/
Result calculate(int *output, const CalculationInput * input) {
    if(input->operation == Operation::DIVIDE && input->operand2 == 0) {
        return Result::FAILURE;
    }

    switch (input->operation) {
        case Operation::PLUS:
            *output = input->operand1 + input->operand2;
            break;
        case Operation::MINUS:
            *output = input->operand1 - input->operand2;
            break;
        case Operation::MULTIPLY:
            *output = input->operand1 * input->operand2;
            break;
        case Operation::DIVIDE:
            *output = input->operand1 / input->operand2;
            break;
    }
    return Result::SUCCESS; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

int main() {
    int data[] = {100, 299, 4, 78, 9};
    printArray(data, 5);

    int sum = sumOfTwoNumbersFromConsole();
    cout << sum << endl;

    char text[] = "blala";
    bool value = containsUpperCase(text);

    bool value2 = isAscending(data, 5);

    printArray(data, 6);
    reverse(data, 6);
    printArray(data, 6);

    Line line {{10, 20},{100, 50}};
    double sexy_variable = length1(&line);
    double sexy_variable2 = length2(line);

    Student *sexy_student = createStudent("Zuzana", 21);

    int output = 0;
    CalculationInput input{1, 0, Operation::PLUS};
    Result example = calculate(&output, &input);
    cout << output;
    return 0;
}
