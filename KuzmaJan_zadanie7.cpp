/*
Meno a priezvisko: Ján Kužma
*/


#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori frontu, ktora obsahuje rovnake prvky ako vstupny zoznam, ale v opacnom poradi.
    Obsah vstupneho zoznamu nemeni.

    Implementujte pomocou reverzneho iteratora!

    PARAMETER:
        [in] data - zoznam prvkov, ktore funkcia nakopiruje do vytvorenej fronty.

    NAVRATOVA HODNOTA:
        Nova fronta, obsahujuca kopie prvkov vstupneho zoznamu v opacnom poradi
*/

queue<int> reverse(const list<int> & data) noexcept {
    list<int> copyData = data;
    queue<int> newData;
    while(!copyData.empty()) {
        newData.push(copyData.back());
        copyData.pop_back();
    }
    return newData;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia preusporiada prvky vo fronte tak, ze budu v opacnom poradi.

    Implementujte pomocou zasobnika!
    Algoritmus ulozi prvky z fronty do zasobnika a potom zo zasobnika naspat do fronty.
    Priebeh alogoritmu je znazorneny v animacii.

    PARAMETER:
        [in, out] data - fronta, v ktorej funkcia zmeni poradie prvkov na opacne
*/

void reverse(queue<int> & data) noexcept {
    list<int> tmp;

    while(!data.empty()) {
        tmp.push_front(data.front());
        data.pop();
    }

    while(!tmp.empty()) {
        data.push(tmp.front());
        tmp.pop_front();
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori vektor, ktoreho prvkami su vektory cisiel typu 'int'.

    PARAMETRE:
        [in] size1 - pocet prvkov hlavneho vektora (pocet vnorenych vektorov)
        [in] size2 - pocet prvkov kazdeho vektora, ktory je prvkom hlavneho vektora (vnorene vektory budu rovnako dlhe, ich dlzka bude 'size2')
        [in] value - hodnota kazdeho celeho cisla vo vektore vektorov

    NAVRATOVA HODNOTA:
        Vektor, ktoreho prvkami su vektory cisiel (pocet jeho prvkov je 'size1').
        Vnorene vektory su rovnako dlhe (pocty ich prvkov su 'size2').
        Vsetky cisla vo vektore vektorov maju hodnotu 'value'.

    PRIKLAD:
        vstup:
            size1 = 2, size2 = 5, value = 10
        vystup:
            { {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10} }
*/

vector<vector<int>> create2dVector(const size_t size1, const size_t size2, const int value) noexcept {
    auto *newVector = new vector<vector<int>>;

    for(size_t i = 0; i < size1; i++) {
        vector<int> otherVector;
        otherVector.assign(size2, value);
        newVector->push_back(otherVector);
    }

    return *newVector;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati textovy retacec, ktory vznikne zretazenim textu 'text', medzery  a cisla 'number'.

    PARAMETRE:
        [in] text - textovy retazec
        [in] number - cislo

    NAVRATOVA HODNOTA:
        Novy textovy retazec, ktory vznikne zretazenim 'text', jednej medzery a 'number'
        (cislo 'number' je skonvertovane na textovy retazec).

    PRIKLADY:
        1. priklad:
            text: "abc", number: 10, vystup: "abc 10"
        2. priklad:
            text: " abc ", number: 10, vystup: " abc  10"
        3. priklad:
            text: "", number: -10, vystup: " -10"
*/

string connectWithSpace(const string & text, const int number) noexcept {
    string newString;
    newString = text + " " + to_string(number);
    return newString;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia precita cisla zo vstupneho textoveho prudu a vrati ich sucet.
    Ak sa vo vstupnom prude vyskytne text, ktory sa neda skonvertovat na cislo,
    tak citanie skonci a vrati sucet precitanych cisiel (funkcia neskusa hladat dalsie cisla).
    Pred, medzi a za cislami moze byt lubovolny pocet bielych znakov.

    PARAMETER:
        [in] text - vstupny textovy prud

    NAVRATOVA HODNOTA:
        Sucet precitanych cisiel (do konca, alebo po vyskyt chyby pri citani alebo konvertovani textu na cislo)

    PRIKLADY:
        text: "10 20 30 10", vystup: 70
        text: " 10   20 30 10 ", vystup: 70
        text: "10 a 20", vystup: 10 (pri konverzii "a" na cislo nastala chyba, funkcia vratila sucet cisiel po vyskyt prvej chyby citania/konverzie)
        text: "", vystup: 0
        text: " ", vystup: 0
*/

int sum(istringstream & text) noexcept {
    int sum = 0, num;
    while(text >> num) {
        sum += num;
    }
    return sum; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prelozi zoznam slov 'sentence' z jedneho jazyka do druheho pomocou slovnika 'translator' a vrati prelozeny zoznam slov.
    Pri prekladani zachova vstupne poradie slov.
    Ak sa v slovniku 'translator' nenachadza preklad, tak do vystupneho zoznamu zapise namiesto prekladu otaznik.
    Pri preklade sa rozlisuju male a velke pismena, cize pri hladani prekladu netreba konvertovat velke pismena na male, alebo opacne.

    PARAMETERE:
        [in] translator - mapuje slova zo vstupneho jazyka do vystupneho jazyka
        [in] sentence   - zoznam slov vo vstupnom jazyku

    NAVRATOVA HODNOTA:
        Novy zoznam slov, prelozenych zo vstupneho do vystupneho jazyka, v poradi, v ktorom boli v 'sentence'.
        Ak slovnik 'translator' neobsahuje preklad slova, tak je vo vystupnom zozname namiesto prekladu otaznik.

    PRIKLADY:
        Vo vsetkych prikladoch predpokladajme obsah prekladoveho slovnika:
            translator: {
                "read" -> "citat",
                "write" -> "pisat",
                "book" -> "kniha",
                "I" -> "ja",
                "you" -> "ty",
                "he" -> "on",
                "she" -> "ona",
                "it" -> "ono"
                "a" -> "",
                "an" -> "",
                "the" -> ""
            }
        1. priklad:
            sentence: { "I", "read", "a", "book"}, vystup: { "ja", "citat", "", "kniha" }
        2. priklad:
            sentence: { "I", "am", "reading", "a", "book" }, vystup: { "ja", "?", "?", "", "kniha"}
        3. priklad:
            sentence: { "He", "reads", "a", "book" }, vystup: { "?", "?", "", "kniha"}, poznamka: neprelozil "He", pretoze v slovniku je len "he"
*/

list<string> translate(const map<string, string> & translator, const list<string> & sentence) noexcept {
    list<string> translated;
    string notFound = "?";
    for (auto& element : sentence) {
        auto it = translator.find(element);
        if( it == translator.end()) {
            translated.push_back(notFound);
        }
        else {
            translated.push_back(it->second);
        }
    }
    return translated;
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su vo vstupnom textovom retazci spravne sparovane zatvorky.
    Ak ano, vrati 'true', inak vrati 'false'.
    Testuje nasledujuce typy zatvoriek: ( ) { } [ ] < >

    V implementacii pouzite na ukladanie otvaracich zatvoriek zasobnik.
    Porovnavajte zatvaracie zatvorky s poslednou otvaracou zatvorkou (na vrchole zasobnika).
    Princip algoritmu je znazorneny v prezentacii.

    PARAMETER:
        [in] mathExpression - textovy retazec, v ktorom funkcia testuje spravnost sparovania zatvoriek

    NAVRATOVA HODNOTA:
        Ak su zatvorky spravne sparovane vrati 'true', inak vrati 'false'.

    PRIKLADY:
        vstup: "ab - (c< d > 1) + {[23 ( [ 45] ) 6] 7} 8 ", vystup: 'true'
        vstup: "(", vystup: 'false'
        vstup: "())", vystup: 'false'
        vstup: "{ >", vystup: 'false'
        vstup: "", vystup: 'true'
*/

bool areParenthesisPaired(const string & mathExpression) noexcept {
    map<char, char> brackets;
    stack<char> bracketsStack;

    brackets['('] = ')';
    brackets['['] = ']';
    brackets['{'] = '}';
    brackets['<'] = '>';

    for(char ch : mathExpression) {
        if(ch == '(' || ch == '<' || ch == '{' || ch == '[') {
            bracketsStack.push(ch);
        }
        else if(ch == ')' || ch == '>' || ch == '}' || ch == ']') {
            if(bracketsStack.empty() || ch != brackets[bracketsStack.top()]) {
                return false;
            }
            else if(ch == brackets[bracketsStack.top()]) {
                bracketsStack.pop();
            }
        }
    }
    return bracketsStack.empty();
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia 'execute' zavola funkciu 'function', s parametrami 'parameter1' a 'parameter2' a vrati jej vysledok.

    PARAMETRE:
        [in] function   - funkcia, ktoru funkcia 'execute' zavola
        [in] parameter1 - pri volani 'function' bude pouzity ako 1. parameter
        [in] parameter2 - pri volani 'function' bude pouzity ako 2. parameter

    NAVRATOVA HODNOTA:
        Vysledok volania 'function(parameter1, parameter2)'

    Funkcie 'multiply' a 'maxValue' su priklady funkcii, ktore mozu byt pouzite ako parameter funkcie 'execute'.

    PRIKLADY:
        1. priklad:
            volanie: execute(multiply, 20, 50) alebo execute(&multiply, 20, 50)
            vystup: 1000
        2. priklad:
            volanie: execute(maxValue, 20, 50) alebo execute(&maxValue, 20, 50)
            vystup: 50
        3. priklad:
            volanie: execute([](int a, int b)->int { return a - b; }, 20, 50)
            vystup: -30
*/

int multiply(int a, int b) noexcept {
    return a * b;
}

int maxValue(int a, int b) noexcept {
    if(a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int execute(int (*function)(int, int), int parameter1, int parameter2) {
    return function(parameter1, parameter2);
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia 'thrownException' zavola funkciu 'function', ktora je vstupnym parametrom.
    Vrati hodnotu podla toho, ci a aku vynimku funkcia 'function' pri volani vyhodi.

    PARAMETER:
        [in] function - funkcia, ktora bude zavolana a testovana (ci a aku vynimku vyhodi)

    NAVRATOVA HODNOTA:
        ExceptionType::NO_EXCEPTION - ak 'function' nevyhodi ziadnu vynimku
        ExceptionType::INVALID_ARGUMENT - ak 'function' vyhodi vynimku typu 'std::invalid_argument'
        ExceptionType::BAD_ALLOC - ak 'function' vyhodi vynimku typu 'std::bad_alloc'
        ExceptionType::UNKNOWN_EXCEPTION - ak 'function' vyhodi iny typ vynimky

    Funkcie: 'doNotThrow', 'throwInvalidArgument', 'throwBadAlloc', 'throwOutOfRange' mozete pouzit pre testovanie.
*/

void doNotThrow() noexcept {
}

void throwInvalidArgument() {
    throw std::invalid_argument("popis vynimky"); // konstruktor vynimky ma parameter
}

void throwBadAlloc() {
    throw std::bad_alloc(); // konstruktor vynimky nema parameter
}

void throwOutOfRange() {
    throw std::out_of_range("popis vynimky");
}

enum class ExceptionType {
    NO_EXCEPTION,
    INVALID_ARGUMENT,
    BAD_ALLOC,
    UNKNOWN_EXCEPTION
};

ExceptionType thrownException(void (*function)()) noexcept {
    try{
        function();
    }
    catch (invalid_argument& e) {
        return ExceptionType::INVALID_ARGUMENT;
    }
    catch (bad_alloc& e) {
        return ExceptionType::BAD_ALLOC;
    }
    catch (...) {
        return ExceptionType::UNKNOWN_EXCEPTION;
    }
    return ExceptionType::NO_EXCEPTION; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori zoznam, ktoreho jeden prvok bude mat hodnotu 1, ostatne prvky hodnotu 0.
    Zoznam bude mat 'length' prvkov.
    Prvok s indexom 'indexOfOne' bude mat hodnotu 1, ostatne prvky hodnotu 0.
    V pripade chybnych vstupnych parametrov, funkcia vyhodi vynimku.

    PARAMETRE:
        [in] length - pocet prvkov vytvoreneho zoznamu
        [in] indexOfOne - index prvku, ktory bude mat hodnotu 1

    NAVRATOVA HODNOTA:
        Zoznam, ktory obsahuje jednu 1 (prvok s indexom 'indexOfOne') a ostatne jeho prvky maju hodnotu 0.
        Prvy prvok ma index nula.
        Pocet prvkov zoznamu je 'length'

    VYNIMKA:
        Ak 'indexOfOne' >= 'length', tak funkcia vyhodi vynimku typu 'IndexOutOfRangeException',
        ktora nesie informacie o pozadovanej dlzke zoznamu a indexe kde mala byt hodnota 1.

    PRIKLADY:
        1. priklad
            vstup: length = 5, indexOfOne = 0
            vystup: {1, 0, 0, 0, 0}
        2. priklad
            vstup: length = 5, indexOfOne = 1
            vystup: {0, 1, 0, 0, 0}
        3. priklad
            vstup: length = 5, indexOfOne = 5
            vyhodi vynimku, ktorej metoda 'getLength' vrati 5 a 'getIndex' vrati 5
        4. priklad
            vstup: length = 5, indexOfOne = 10
            vyhodi vynimku, ktorej metoda 'getLength' vrati 5 a 'getIndex' vrati 10
        5. priklad
            vstup: count = 0, indexOfOne = 0
            vyhodi vynimku, ktorej metoda 'getLength' vrati 0 a 'getIndex' vrati 0
*/

class IndexOutOfRangeException {
private:
    const size_t length;
    const size_t index;
public:
    IndexOutOfRangeException(size_t length, size_t index) noexcept
            : length(length)
            , index(index) {
    }

    size_t getLength() const noexcept {
        return length;
    }

    size_t getIndex() const noexcept {
        return index;
    }

    string what() const noexcept {
        return "index out of range: " + to_string(index) + " >= " + to_string(length);
    }
};

list<int> createList(const list<int>::size_type length, const list<int>::size_type indexOfOne) {
    list<int> clist;
    try{
        if (indexOfOne >= length) {
            throw IndexOutOfRangeException(length, indexOfOne);
        }
        else{

            for (size_t i = 0; i < length; i++) {
                if (i == indexOfOne) {
                    clist.push_back(1);
                    // cout<<1<<endl;
                }
                else {
                    clist.push_back(0);
                    // cout<<0<<endl;
                }
            }

        }
    }

    catch (IndexOutOfRangeException& e ) {
        throw ;
    }
    return clist;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

template<typename T>
void print_container(const T& container) {
    for (auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // uloha 1
    list<int> data = {1, 2, 3, 4, 5, 6};

    queue<int> reversedData = reverse(data);
    // uloha 2
    reverse(reversedData);
    // uloha 3
    vector<vector<int>> vector2d = create2dVector(2, 5, 10);
    // uloha 4
    string str, newStr;
    str.append("seven ate");
    newStr += connectWithSpace(str, 9);
    cout << newStr << endl;

    // uloha 5
    string text = "10 20 30 a   10";
    istringstream iss(text);
    int n = sum(iss);
    cout << "uloha 5: "<< n << endl;
    // uloha 6

    map<string, string> dictionary;
    dictionary["read"] = "citat";
    dictionary["write"] = "pisat";
    dictionary["book"] = "kniha";
    list<string> sentence = {"write", "I", "read"};
    list<string> translated = translate(dictionary, sentence);

    print_container(sentence);
    print_container(translated);

    // uloha 7

    string equation = "()()()";
    cout << areParenthesisPaired(equation) << endl;


    // uloha 8
    cout << execute(multiply, 10, 20) << endl;

    // uloha 9

    thrownException(throwInvalidArgument);
    return 0;
}
