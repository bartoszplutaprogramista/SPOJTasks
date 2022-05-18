//#################Czarodziejskie lusterko(AL_05_01)#################//
#include <iostream>
#include <math.h>

using namespace std;

unsigned long long zamiana(unsigned long long int n)
{
    int binarnie[70];
    int i,j;

    for(i=0; n>0; i++)
    {
        binarnie[i]=n%2;
        n= n/2;
    }
    unsigned long long potegaDwojki = 1;
    unsigned long long int liczbaDziesietnaKoniec=0;
    for(i=i-1 ; i >= 0 ; i--)
    {
        liczbaDziesietnaKoniec += binarnie[i]*potegaDwojki;
        potegaDwojki *= 2;
    }
    return liczbaDziesietnaKoniec;
}

int main()
{
    unsigned long long int liczbaDziesietnaPoczatek = 11;
    while (cin >> liczbaDziesietnaPoczatek)
    {
        cout << zamiana(liczbaDziesietnaPoczatek) << endl;
    }
    return 0;
}
//#################Alfabet Morse'a(AL_20_01)#################//
#include<iostream>
#include<string>
#include<map>

using namespace std;

map<char,string> loadData();
string transformText(string text, map<char,string> alphabet);

main() {
    string text = "";
    int counter = 0;
    map<char,string> alphabet;
    alphabet = loadData();
    while (counter < 100){
        cin.clear();
        cin.sync();
        getline(cin, text);
        cout << transformText(text, alphabet) << endl;
        counter++;
    }
}

map<char,string> loadData() {
    map<char,string> alphabet;
        alphabet['A'] = ".-";
        alphabet['B'] = "-...";
        alphabet['C'] = "-.-.";
        alphabet['D'] = "-..";
        alphabet['E'] = ".";
        alphabet['F'] = ".-..";
        alphabet['G'] = "--.";
        alphabet['H'] = "....";
        alphabet['I'] = "..";
        alphabet['J'] = ".---";
        alphabet['K'] = "-.-";
        alphabet['L'] = "..-.";
        alphabet['M'] = "--";
        alphabet['N'] = "-.";
        alphabet['O'] = "---";
        alphabet['P'] = ".--.";
        alphabet['Q'] = "--.-";
        alphabet['R'] = ".-.";
        alphabet['S'] = "...";
        alphabet['T'] = "-";
        alphabet['U'] = "..-";
        alphabet['V'] = "...-";
        alphabet['W'] = ".--";
        alphabet['X'] = "-..-";
        alphabet['Y'] = "-.--";
        alphabet['Z'] = "--..";
        alphabet['a'] = ".-";
        alphabet['b'] = "-...";
        alphabet['c'] = "-.-.";
        alphabet['d'] = "-..";
        alphabet['e'] = ".";
        alphabet['f'] = ".-..";
        alphabet['g'] = "--.";
        alphabet['h'] = "....";
        alphabet['i'] = "..";
        alphabet['j'] = ".---";
        alphabet['k'] = "-.-";
        alphabet['l'] = "..-.";
        alphabet['m'] = "--";
        alphabet['n'] = "-.";
        alphabet['o'] = "---";
        alphabet['p'] = ".--.";
        alphabet['q'] = "--.-";
        alphabet['r'] = ".-.";
        alphabet['s'] = "...";
        alphabet['t'] = "-";
        alphabet['u'] = "..-";
        alphabet['v'] = "...-";
        alphabet['w'] = ".--";
        alphabet['x'] = "-..-";
        alphabet['y'] = "-.--";
        alphabet['z'] = "--..";
        alphabet[' '] = "";
        return alphabet;
}

string transformText(string text, map<char,string> alphabet) {
    string score = "";
    int lengthOfText = text.length();
    map<char, string>::iterator itr;
    for (int x=0; x<lengthOfText; x++) {
        for (itr = alphabet.begin(); itr != alphabet.end(); ++itr) {
            if (itr->first == text[x]) {
                score=score+(itr->second)+('/');
            }
        }
    }
    return score;
}
//#################Kalkulator(CALC)#################//
#include <iostream>

using namespace std;

void wykonajDzialanie(char dzialanie, int pierwszaZmienna, int drugaZmienna)
{
    switch (dzialanie)
    {
    case '+':
    {
        cout<<pierwszaZmienna+drugaZmienna<<endl;
    }
    break;
    case '-':
    {
        cout<<pierwszaZmienna-drugaZmienna<<endl;
    }
    break;
    case '*':
    {
        cout<<pierwszaZmienna*drugaZmienna<<endl;
    }
    break;
    case '/':
    {
        cout<<pierwszaZmienna/drugaZmienna<<endl;
    }
    break;
    case '%':
    {
        cout<<pierwszaZmienna%drugaZmienna<<endl;
    }
    break;
    default:
        cout << "Nie ma takiej opcji w menu! "<<endl;
    }
}

int main()
{
    char dzialanie;
    int pierwszaZmienna, drugaZmienna;
    while (cin>>dzialanie>>pierwszaZmienna>>drugaZmienna)
    {
        wykonajDzialanie(dzialanie, pierwszaZmienna, drugaZmienna);
    }

    return 0;
}
//#################Harry and big doughnuts(DOUGHNUT)#################//
#include <iostream>

using namespace std;

//t-liczba cyki, c-liczba kotÃ³w, k-udzwig Harrego oraz w-waga paczka
void sprawdz(int c, int k, int w)
{
    if (c*w<=k) cout << "yes"<<endl;
    else cout << "no"<<endl;
}
int main()
{
    int t, c, k, w;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cin>>c>>k>>w;
        sprawdz(c, k, w);
    }
    return 0;
}
//#################Flamaster(FLAMASTE)#################//
#include <iostream>
#include <sstream>  // Zeby dzialala konwersja int -> string
#include <fstream> // zeby dzialalo odczytywanie z pliku
#include <string> // zeby dzialalo odczytywanie z pliku


using namespace std;

string konwersjaIntNaString (int liczba)
{
    ostringstream ss;
    ss<<liczba;
    string str = ss.str();
    return str;
}

int obliczWystapieniaWybranegoZnaku(string wyraz, int pozycjaZnaku)
{
    int iloscWystapien = 1;
    if (wyraz.length()>pozycjaZnaku)
    {
        while(wyraz[pozycjaZnaku]==wyraz[pozycjaZnaku+1])
        {
            iloscWystapien++;
            pozycjaZnaku++;
        }
    }
    else iloscWystapien = 0;

    return iloscWystapien;
}

string skracanieWyrazow(string wyrazDoSkrocenia)
{
    int dlugosc=wyrazDoSkrocenia.length();
    int iloscWystapien;
    char powtarzajacySieZnak;

    //cin >> wyrazDoSkrocenia;
    //cout << wyrazDoSkrocenia << endl;

    for(int i=0; i<dlugosc-2; i++)
    {
        //sprawdzamy czy wystÃªpujÂ¹ 3 takie same znaki obok siebie
        if ((wyrazDoSkrocenia[i] == wyrazDoSkrocenia[i+1])&&(wyrazDoSkrocenia[i+1] == wyrazDoSkrocenia[i+2]))
        {
            iloscWystapien = obliczWystapieniaWybranegoZnaku(wyrazDoSkrocenia, i);
            powtarzajacySieZnak = wyrazDoSkrocenia[i];
            wyrazDoSkrocenia.replace(i,iloscWystapien,powtarzajacySieZnak+konwersjaIntNaString(iloscWystapien));
            dlugosc = wyrazDoSkrocenia.length();
        }
    }

   return wyrazDoSkrocenia;
}

int main()
{
    int iloscTestow;
    string wyraz;

    cin>>iloscTestow;
    for (int i=0; i<iloscTestow; i++)
    {
        cin >> wyraz;
        cout<<skracanieWyrazow(wyraz)<<endl;
    }
    return 0;
}
//#################BMI(FR_02_06)#################//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float calculate(int height, int weight);

void displayScores(vector <string> peopleWithUnderweight,
                  vector <string> peopleWithCorrectWeight,
                  vector <string> peopleWithOverweight);

int main()
{
    int howManyPeople = 0;
    cin >> howManyPeople;

    string nameOfThePerson = "";
    int weightOfThePerson = 0;
    int heightOfThePerson = 0;
    vector <float> BMI;

    vector <string> peopleWithUnderweight;
    vector <string> peopleWithCorrectWeight;
    vector <string> peopleWithOverweight;

    for (int i=0; i<howManyPeople; i++) {
        cin >> nameOfThePerson;;
        cin >> weightOfThePerson;
        cin >> heightOfThePerson;

        BMI.push_back(calculate(heightOfThePerson, weightOfThePerson));

        if (BMI[i] < 18.5)
            peopleWithUnderweight.push_back(nameOfThePerson);
        else if ((BMI[i] >= 18.5)&&(BMI[i] < 25))
            peopleWithCorrectWeight.push_back(nameOfThePerson);
        else
            peopleWithOverweight.push_back(nameOfThePerson);
    }

    displayScores(peopleWithUnderweight, peopleWithCorrectWeight, peopleWithOverweight);

    return 0;
}

float calculate(int height, int weight){
    float BMI;
    float heightMeters = height / 100.;
    BMI = (weight)/(pow(heightMeters,2));
    return BMI;
}

void displayScores(vector <string> peopleWithUnderweight,
                  vector <string> peopleWithCorrectWeight,
                  vector <string> peopleWithOverweight){

    cout << "niedowaga" << endl;
    int lengthUnderweight = peopleWithUnderweight.size();
        for (int i=0; i<lengthUnderweight; i++)
            cout << peopleWithUnderweight[i] << endl;

    cout << endl;
    cout << "wartosc prawidlowa" << endl;
    int lengthCorrectWeight = peopleWithCorrectWeight.size();
        for (int i=0; i<lengthCorrectWeight; i++)
            cout << peopleWithCorrectWeight[i] << endl;

    cout << endl;
    cout << "nadwaga" << endl;
    int lengthOverweight = peopleWithOverweight.size();
        for (int i=0; i<lengthOverweight; i++)
            cout << peopleWithOverweight[i] << endl;
    cout << endl;
}
//#################Obzartuchy(GLUTTON)#################//
#include <iostream>
#include <math.h>

using namespace std;

void obliczIlePudelek(int liczbaObzartuchow, double liczbaCiastekWPudelku)
{
        int czasJedzeniaPojedynczegoCiastka, dobaSek = 86400, suma=0, ileCiastekNaDobe;
        double ilePudelekKupic;
        for (int j=1; j<=liczbaObzartuchow; j++)
        {
            cin >> czasJedzeniaPojedynczegoCiastka;
            ileCiastekNaDobe = dobaSek/czasJedzeniaPojedynczegoCiastka;

            suma = suma + ileCiastekNaDobe;
            ilePudelekKupic = suma/liczbaCiastekWPudelku;

            ilePudelekKupic = ceil(ilePudelekKupic);
        }
        cout << ilePudelekKupic << endl;

}

int main()
{
    int ileZestawow, liczbaObzartuchow;
    double liczbaCiastekWPudelku;
    cin >> ileZestawow;
    for (int i=1; i<=ileZestawow; i++)
    {
        cin >> liczbaObzartuchow >> liczbaCiastekWPudelku;

        obliczIlePudelek(liczbaObzartuchow, liczbaCiastekWPudelku);
    }

    return 0;
}
//#################Lamacz gg(JGGHACK)#################//
#include <iostream>

using namespace std;

void lamaczGG(string haslo)
{
    int dlugosc = haslo.length();
    string tablicaZnakow = "ABCDEFGHIJKLMNOP";
    int tablicaWartosciPierwszegoZnaku[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int tablicaWartosciDrugiegoZnaku[] = {0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240};
    int wartoscPierwszegoZnaku = 0, wartoscDrugiegoZnaku = 0, sumaWartosciPierwszegoiDrugiegoZnaku = 0;
    for (int i=0; i<dlugosc; i=i+2)
    {
        int k=0;
        while (k<=15)
        {
            if (haslo[i] == tablicaZnakow[k])
            {
                wartoscPierwszegoZnaku = tablicaWartosciPierwszegoZnaku[k];
                break;
            }
            k++;
        }
        int p=0;
        while (p<=15)
        {
            if (haslo[i+1] == tablicaZnakow[p])
            {
                wartoscDrugiegoZnaku = tablicaWartosciDrugiegoZnaku[p];
                break;
            }
            p++;
        }

        sumaWartosciPierwszegoiDrugiegoZnaku = wartoscPierwszegoZnaku + wartoscDrugiegoZnaku;
        cout << (char)sumaWartosciPierwszegoiDrugiegoZnaku;
    }
    cout << endl;
}

int main()
{
    string haslo;
    while (cin >> haslo)
    {
        lamaczGG(haslo);
    }
    return 0;
}
//#################Liczba na slowo(JLITOSL)#################//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long int,string> loadData1to19();

map<long long int,string> loadDataDecimal();

map<long long int,string> loadDataHundredths();

string addToWord (string numberInWords, map<long long int, string>::iterator itr);

string convertNumberToText(map<long long int,string> naturalNumbersToText,
                           map<long long int,string> decimalToText,
                           map<long long int,string> hundredthsToText);

int main() {
    map<long long int,string> naturalNumbersToText;
    map<long long int,string> decimalToText;
    map<long long int,string> hundredthsToText;
    naturalNumbersToText = loadData1to19();
    decimalToText = loadDataDecimal();
    hundredthsToText = loadDataHundredths();


    int howManyTimes = 0;
    cin >> howManyTimes;

    for (int z=0; z<howManyTimes; z++){
        cout << convertNumberToText(naturalNumbersToText, decimalToText, hundredthsToText) << endl;
    }

    return 0;
}

map<long long int,string> loadData1to19() {
    map<long long int,string> naturalNumbersToText;
        naturalNumbersToText[1] = "jeden";
        naturalNumbersToText[2] = "dwa";
        naturalNumbersToText[3] = "trzy";
        naturalNumbersToText[4] = "cztery";
        naturalNumbersToText[5] = "piec";
        naturalNumbersToText[6] = "szesc";
        naturalNumbersToText[7] = "siedem";
        naturalNumbersToText[8] = "osiem";
        naturalNumbersToText[9] = "dziewiec";
        naturalNumbersToText[10] = "dziesiec";
        naturalNumbersToText[11] = "jedenascie";
        naturalNumbersToText[12] = "dwanascie";
        naturalNumbersToText[13] = "trzynascie";
        naturalNumbersToText[14] = "czternascie";
        naturalNumbersToText[15] = "pietnascie";
        naturalNumbersToText[16] = "szesnascie";
        naturalNumbersToText[17] = "siedemnascie";
        naturalNumbersToText[18] = "osiemnascie";
        naturalNumbersToText[19] = "dziewietnascie";
        return naturalNumbersToText;
}

map<long long int,string> loadDataDecimal() {
    map<long long int,string> decimalToText;
        decimalToText[2] = "dwadziescia";
        decimalToText[3] = "trzydziesci";
        decimalToText[4] = "czterdziesci";
        decimalToText[5] = "piecdziesiat";
        decimalToText[6] = "szescdziesiat";
        decimalToText[7] = "siedemdziesiat";
        decimalToText[8] = "osiemdziesiat";
        decimalToText[9] = "dziewiecdziesiat";
        return decimalToText;
}

map<long long int,string> loadDataHundredths() {
    map<long long int,string> hundredthsToText;
        hundredthsToText[1] = "sto";
        hundredthsToText[2] = "dwiescie";
        hundredthsToText[3] = "trzysta";
        hundredthsToText[4] = "czterysta";
        hundredthsToText[5] = "piecset";
        hundredthsToText[6] = "szescset";
        hundredthsToText[7] = "siedemset";
        hundredthsToText[8] = "osiemset";
        hundredthsToText[9] = "dziewiecset";
        return hundredthsToText;
}

string addToWord (string numberInWords, map<long long int, string>::iterator itr){
    if (numberInWords == "")
        numberInWords=numberInWords +(itr->second);
    else
        numberInWords=numberInWords + " " +(itr->second);
    return numberInWords;
}

string convertNumberToText(map<long long int,string> naturalNumbersToText,
                           map<long long int,string> decimalToText,
                           map<long long int,string> hundredthsToText){
        map<long long int, string>::iterator itr;
        long long int naturalNumber = 0;
        int j=0;
        string numberInWords="";
        cin >> naturalNumber;

        j=0;
        vector <int> nextGroupOfDigits;
        while(naturalNumber>0) {
            int numberSeparated=naturalNumber % 1000;
            nextGroupOfDigits.push_back(numberSeparated);
            naturalNumber/=1000;
        }
        int naturalNumberShorter = 0;
        int lengthOfNextGroupOfDigits = nextGroupOfDigits.size();
        int k=lengthOfNextGroupOfDigits-1;
        int tysMlnMldBln = lengthOfNextGroupOfDigits;

        while (k>=0){
            naturalNumberShorter = nextGroupOfDigits[k];
            int tysMlnMldBlnNumberLesser = naturalNumberShorter;
            vector <int> singleDigits;
            int numbersFrom10To19;
            itr = naturalNumbersToText.begin();
            while (itr != naturalNumbersToText.end()) {
                    while(naturalNumberShorter>0) {
                        int digitSeparated=naturalNumberShorter % 10;
                        singleDigits.push_back(digitSeparated);
                        naturalNumberShorter/=10;
                    }
                ++itr;
                j++;
            }

            int lengthOfSingleDigits = singleDigits.size();

            int i = lengthOfSingleDigits-1;

            while(i>=0){
                if (lengthOfSingleDigits==3){
                    for (itr = hundredthsToText.begin(); itr != hundredthsToText.end(); ++itr) {
                        if ((itr->first) == singleDigits[i]) {
                            numberInWords = addToWord(numberInWords, itr);
                        }
                    }
                }

                else if ((lengthOfSingleDigits==2)&&(singleDigits[i]==1)){
                        numbersFrom10To19 = singleDigits[i] + 9 + singleDigits[i-1];
                    for (itr = naturalNumbersToText.begin(); itr != naturalNumbersToText.end(); ++itr) {
                        if ((itr->first) == numbersFrom10To19) {
                            numberInWords = addToWord(numberInWords, itr);
                        }
                    }
                    lengthOfSingleDigits--;
                }

                else if (lengthOfSingleDigits==2){
                    for (itr = decimalToText.begin(); itr != decimalToText.end(); ++itr) {
                        if ((itr->first) == singleDigits[i]) {
                            numberInWords = addToWord(numberInWords, itr);
                        }
                    }
                }

                else if (lengthOfSingleDigits==1){
                    for (itr = naturalNumbersToText.begin(); itr != naturalNumbersToText.end(); ++itr) {
                        if ((itr->first) == singleDigits[i]) {
                            numberInWords = addToWord(numberInWords, itr);
                        }
                    }
                }
                i--;
                lengthOfSingleDigits--;
            }
            k--;
            if ((tysMlnMldBln == 2)&&(tysMlnMldBlnNumberLesser != 0)) {
                numberInWords=numberInWords+" "+"tys.";
            }
            else if ((tysMlnMldBln == 3)&&(tysMlnMldBlnNumberLesser != 0)) {
                numberInWords=numberInWords+" "+"mln.";
            }
            else if ((tysMlnMldBln == 4)&&(tysMlnMldBlnNumberLesser != 0)) {
                numberInWords=numberInWords+" "+"mld.";
            }
            else if ((tysMlnMldBln == 5)&&(tysMlnMldBlnNumberLesser != 0)) {
                numberInWords=numberInWords+" "+"bln.";
            }
            tysMlnMldBln--;
        }
    return numberInWords;
}

//#################Pesel(JPESEL)#################//
#include <iostream>
using namespace std;

void sprawdzPesel(long long int pesel)
{
    int cyfryOdTyl[11];
    int cyfryOdwroc[11];

    for (int i=0; i<11; i++)
    {
        cyfryOdTyl[i] = pesel%10;
        pesel = (pesel - cyfryOdTyl[i]) / 10;
    }

    int szyfr[11] = {1,3,7,9,1,3,7,9,1,3,1};
    int suma = 0;

    cyfryOdwroc[0] = cyfryOdTyl[10];
    cyfryOdwroc[1] = cyfryOdTyl[9];
    cyfryOdwroc[2] = cyfryOdTyl[8];
    cyfryOdwroc[3] = cyfryOdTyl[7];
    cyfryOdwroc[4] = cyfryOdTyl[6];
    cyfryOdwroc[5] = cyfryOdTyl[5];
    cyfryOdwroc[6] = cyfryOdTyl[4];
    cyfryOdwroc[7] = cyfryOdTyl[3];
    cyfryOdwroc[8] = cyfryOdTyl[2];
    cyfryOdwroc[9] = cyfryOdTyl[1];
    cyfryOdwroc[10] = cyfryOdTyl[0];

    for (int i=0; i<11; i++)
    {
        suma = suma + cyfryOdwroc[i]*szyfr[i];
    }
    if (suma % 10 == 0)
        cout << "D" << endl;
    else cout << "N" << endl;
}
int main()
{
    int liczbaTestow;
    cin>>liczbaTestow;
    for (int j=1; j<=liczbaTestow; j++)
    {
        long long int numerPesel;
        cin >> numerPesel;
        sprawdzPesel(numerPesel);
    }
    return 0;
}
//#################Dodawanie rzymskie(JSUMRZYM)#################//
#include <iostream>
#include <map>

using namespace std;

map<char, int> loadDataRomanToArabic();

map<int, char> loadDataArabicToRoman();

int changeOnArabic(string romanCharacters, map<char, int> romanNumeralsToArabicNumerals);

string changeOnRoman(int number, map<int, char> arabicNumeralsToRomanNumerals);

int main()
{
    string firstRomanCharacters;
    string secondRomanCharacters;
    map<char, int> romanNumeralsToArabicNumerals;
    map<int, char> arabicNumeralsToRomanNumerals;
    int firstArabicNumber = 0;
    int secondArabicNumber = 0;
    romanNumeralsToArabicNumerals = loadDataRomanToArabic();
    arabicNumeralsToRomanNumerals = loadDataArabicToRoman();
    int sumOfArabic = 0;
    while (cin >> firstRomanCharacters) {
            cin >> secondRomanCharacters;
            firstArabicNumber = changeOnArabic(firstRomanCharacters, romanNumeralsToArabicNumerals);
            secondArabicNumber = changeOnArabic(secondRomanCharacters, romanNumeralsToArabicNumerals);
            sumOfArabic = firstArabicNumber + secondArabicNumber;
        cout << changeOnRoman(sumOfArabic, arabicNumeralsToRomanNumerals) << endl;
        sumOfArabic = 0;
    }
    return 0;
}

map<char, int> loadDataRomanToArabic() {
    map<char, int> romanNumeralsToArabicNumerals;
        romanNumeralsToArabicNumerals['I'] = 1;
        romanNumeralsToArabicNumerals['V'] = 5;
        romanNumeralsToArabicNumerals['X'] = 10;
        romanNumeralsToArabicNumerals['L'] = 50;
        romanNumeralsToArabicNumerals['C'] = 100;
        romanNumeralsToArabicNumerals['D'] = 500;
        romanNumeralsToArabicNumerals['M'] = 1000;
        return romanNumeralsToArabicNumerals;
}

map<int, char> loadDataArabicToRoman() {
    map<int, char> arabicNumeralsToRomanNumerals;
        arabicNumeralsToRomanNumerals[1] = 'I';
        arabicNumeralsToRomanNumerals[5] = 'V';
        arabicNumeralsToRomanNumerals[10] = 'X';
        arabicNumeralsToRomanNumerals[50] = 'L';
        arabicNumeralsToRomanNumerals[100] = 'C';
        arabicNumeralsToRomanNumerals[500] = 'D';
        arabicNumeralsToRomanNumerals[1000] = 'M';
        return arabicNumeralsToRomanNumerals;
}

int changeOnArabic(string romanCharacters, map<char, int> romanNumeralsToArabicNumerals){
    int i=0,score=0,help=0,last=0;
    i=romanCharacters.length()-1;
    while(i>=0) {
        help=romanNumeralsToArabicNumerals[romanCharacters[i]];
        if (help>=last) {
            last=help;
            score+=help;
        } else score-=help;
        i--;
    }
    return score;
}

string changeOnRoman(int number, map<int, char> arabicNumeralsToRomanNumerals) {
    string result="";
    const int quantityOfElements = 7;

    map<int, char>::iterator itr, LPOS = arabicNumeralsToRomanNumerals.end ( );
    map<int, char>::iterator itr1, LPOS1 = arabicNumeralsToRomanNumerals.end ( );
    map<int, char>::iterator itr2, LPOS2 = arabicNumeralsToRomanNumerals.end ( );

    int i = 0;

    int const firstControlLPOS = -1;
    int secondControlLPOS1 = -2;
    int thirdControlLPOS2  = -3;

    int auxiliary = 2;

    advance (LPOS, firstControlLPOS);
    advance (LPOS1, secondControlLPOS1);
    advance (LPOS2, thirdControlLPOS2);

    while (i < quantityOfElements) {

        if(number >= LPOS->first) {
            number -= LPOS->first;
            result += LPOS->second;
        } else if ((i%2 == 0) &&
                   (i<quantityOfElements-2) &&
                   (number >= LPOS->first - LPOS2->first) &&
                   (LPOS2->first != LPOS->first - LPOS2->first)) {
            number -= LPOS->first - LPOS2->first;
            result += LPOS2->second;
            result += LPOS->second;

                if (auxiliary < quantityOfElements) {
                    i++;
                    LPOS2 = arabicNumeralsToRomanNumerals.end();
                    thirdControlLPOS2--;
                    LPOS1 = arabicNumeralsToRomanNumerals.end();
                    secondControlLPOS1--;
                    auxiliary++;
                    advance ( LPOS, firstControlLPOS);
                    advance ( LPOS1, secondControlLPOS1);
                    advance ( LPOS2, thirdControlLPOS2);
                } else if (auxiliary == quantityOfElements) {
                    i++;
                    LPOS1 = arabicNumeralsToRomanNumerals.end();
                    secondControlLPOS1--;
                    auxiliary++;
                    advance ( LPOS, firstControlLPOS);
                    advance ( LPOS1, secondControlLPOS1);
                } else {
                    if(LPOS->first>1) {
                        advance ( LPOS, firstControlLPOS);
                    }
                    i++;
                }

        } else if ((i%2 == 1) &&
                   (i<quantityOfElements-1) &&
                   (number >= LPOS->first - LPOS1->first) &&
                   (LPOS1->first != LPOS->first - LPOS1->first)) {
            number -= LPOS->first - LPOS1->first;
            result += LPOS1->second;
            result += LPOS->second;

                if (auxiliary < quantityOfElements) {
                    i++;
                    LPOS2 = arabicNumeralsToRomanNumerals.end();
                    thirdControlLPOS2--;
                    LPOS1 = arabicNumeralsToRomanNumerals.end();
                    secondControlLPOS1--;
                    auxiliary++;
                    advance ( LPOS, firstControlLPOS);
                    advance ( LPOS1, secondControlLPOS1);
                    advance ( LPOS2, thirdControlLPOS2);
                } else if (auxiliary == quantityOfElements) {
                    i++;
                    LPOS1 = arabicNumeralsToRomanNumerals.end();
                    secondControlLPOS1--;
                    auxiliary++;
                    advance ( LPOS, firstControlLPOS);
                    advance ( LPOS1, secondControlLPOS1);
                } else {
                    if(LPOS->first>1) {
                        advance ( LPOS, firstControlLPOS);
                    }
                    i++;
                }

        } else {
                if (auxiliary < quantityOfElements) {
                    i++;
                    LPOS2 = arabicNumeralsToRomanNumerals.end();
                    thirdControlLPOS2--;
                    LPOS1 = arabicNumeralsToRomanNumerals.end();
                    secondControlLPOS1--;
                    auxiliary++;
                    advance ( LPOS, firstControlLPOS);
                    advance ( LPOS1, secondControlLPOS1);
                    advance ( LPOS2, thirdControlLPOS2);
                } else if (auxiliary == quantityOfElements) {
                    i++;
                    LPOS1 = arabicNumeralsToRomanNumerals.end();
                    secondControlLPOS1--;
                    auxiliary++;
                    advance ( LPOS, firstControlLPOS);
                    advance ( LPOS1, secondControlLPOS1);
                } else {
                    if(LPOS->first>1) {
                        advance ( LPOS, firstControlLPOS);
                    }
                    i++;
                }
        }
    }
    return result;
}
//#################Szyfr Cezara(JSZYCER)#################//
#include <iostream>

using namespace std;

void zaszyfruj(int dlugoscWyrazu, string wyrazDoZaszyfrowania)
{
    for (int i=0; i<dlugoscWyrazu; i++)
    {
        if ((wyrazDoZaszyfrowania[i]>=65)&&(wyrazDoZaszyfrowania[i]<=87))
            wyrazDoZaszyfrowania[i] = wyrazDoZaszyfrowania[i]+3;
        else if ((wyrazDoZaszyfrowania[i]>=88)&&(wyrazDoZaszyfrowania[i]<=90))
            wyrazDoZaszyfrowania[i] = wyrazDoZaszyfrowania[i]-23;
    }
    cout << wyrazDoZaszyfrowania << endl;
}

int main()
{
    string wyrazDoZaszyfrowania;
    while(getline (cin, wyrazDoZaszyfrowania))
    {
        int dlugoscWyrazu = wyrazDoZaszyfrowania.length();
        zaszyfruj(dlugoscWyrazu, wyrazDoZaszyfrowania);
    }
    cout << endl;

    return 0;
}
//#################Dodawanie liczb calkowitych(KC001)#################//
#include <iostream>

using namespace std;

int suma(int a, int b, int c)
{
    int wynik=0;
    wynik = a + b + c;
    return wynik;
}

int main()
{
    int a, b ,c;
    cin>>a>>b>>c;
    cout<<suma(a, b, c)<<endl;
    return 0;
}
//#################Szpieg(MWP2_1E)#################//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void displayWords(vector <string> wordToDisplay) {
    int length = wordToDisplay.size();
    for (int i = 0; i < length; i++) {
    cout << wordToDisplay[i] << endl;
    }
}

int main() {
    vector <string> word;
    string wordFromTheKeyboard = "";

    while (cin >> wordFromTheKeyboard) {
        word.push_back(wordFromTheKeyboard);
    }
    sort(word.begin(), word.end());
    displayWords(word);

    return 0;
}
//#################Budka suflera(MWP8_1B)#################//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

vector <string> returnSongVector(string originalSongText);

vector <string> returnKrzysztofVector(string textProvidedByKrzysztof);

vector <string> calculate(vector <string> textOfSong, vector <string> textOfKrzysztof);

void displayResults(vector <string> textThatKrzysztofSkipped);

int main(){
    string originalSongText;
    string textProvidedByKrzysztof;
    vector <string> textOfSong;
    vector <string> textOfKrzysztof;
    vector <string> textThatKrzysztofSkipped;
    cin.clear();
    cin.sync();
    getline(cin, originalSongText);
    cin.clear();
    cin.sync();
    getline(cin, textProvidedByKrzysztof);

    textOfSong = returnSongVector(originalSongText);

    textOfKrzysztof = returnKrzysztofVector(textProvidedByKrzysztof);

    textThatKrzysztofSkipped = calculate(textOfSong, textOfKrzysztof);

    displayResults(textThatKrzysztofSkipped);

    return 0;
}

vector <string> returnSongVector(string originalSongText){
    istringstream v1(originalSongText);
    vector<string> textOfSong((istream_iterator<string>(v1)),istream_iterator<string>());
    return textOfSong;
}
vector <string> returnKrzysztofVector(string textProvidedByKrzysztof){
    istringstream v2(textProvidedByKrzysztof);
    vector<string> textOfKrzysztof((istream_iterator<string>(v2)),istream_iterator<string>());
    return textOfKrzysztof;
}

vector <string> calculate(vector <string> textOfSong, vector <string> textOfKrzysztof){
    sort(textOfSong.begin(), textOfSong.end());
    sort(textOfKrzysztof.begin(), textOfKrzysztof.end());
    int lengthOfTextSong=textOfSong.size();
    int lengthOfTextKrzysztof=textOfKrzysztof.size();
    int help=0;
    vector <string> textThatKrzysztofSkipped;
    for (int i=0; i<lengthOfTextSong; i++){
        int j=help;
        if (j<lengthOfTextKrzysztof){
            while (j<lengthOfTextKrzysztof){
                if (textOfSong[i]==textOfKrzysztof[j]){
                    help++;
                    j=lengthOfTextKrzysztof;
                }
                else {
                    if (j==lengthOfTextKrzysztof-1){
                        textThatKrzysztofSkipped.push_back(textOfSong[i]);
                    }
                    j++;
                }
            }
        }
        else if (j==lengthOfTextKrzysztof){
            textThatKrzysztofSkipped.push_back(textOfSong[i]);
        }
    }
    return textThatKrzysztofSkipped;
}

void displayResults(vector <string> textThatKrzysztofSkipped){
    int howManyTimes = textThatKrzysztofSkipped.size();
    cout << howManyTimes << endl;
    sort(textThatKrzysztofSkipped.begin(), textThatKrzysztofSkipped.end());
    for (int i=0; i<howManyTimes; i++){
        cout << textThatKrzysztofSkipped[i] << endl;
    }
}
//#################Nowa dzialka(MWPZ06X)#################//
    #include <iostream>

    using namespace std;

    int liczbaKrokowOblicz(int liczbaKrokow)
    {
        int wynik;
        wynik=liczbaKrokow*liczbaKrokow;
        return wynik;
    }

    int main()
    {
        int ile;
        cin>>ile;
        for(int i=1; i<=ile; i++)
        {
            int liczbaKrokow;
            cin>>liczbaKrokow;
            cout<<liczbaKrokowOblicz(liczbaKrokow)<<endl;
        }
        return 0;
    }
//#################Polowa(POL)#################//
#include <iostream>

using namespace std;

string podzielWyraz (string wyraz)
{
    int dlugosc=wyraz.length();
    int pol = dlugosc/2;

    wyraz.erase(pol,pol);
    return wyraz;
}

int main()
{
    int ile;
    cin>>ile;
    for (int i=1; i<=ile; i++)
    {
        string wyraz;
        cin >> wyraz;
        cout << podzielWyraz(wyraz) << endl;
    }
    return 0;
}
//#################Samolot(POTSAM)#################//
#include <iostream>

using namespace std;

int oblicz(int n1, int k1, int n2, int k2)
{
    int wynik = 0;
    wynik = n1*k1+n2*k2;
    return wynik;
}

int main()
{
    int n1, k1, n2, k2;
    cin>>n1>>k1>>n2>>k2;
    cout << oblicz(n1,k1,n2,k2)<<endl;
    return 0;
}
//#################Tablice(PP0502B)#################//
#include <iostream>

using namespace std;

void odwrocTablice (int tablicaNaLiczby[100], int n)
{
    cin >> n;
    for (int j=0; j<n; j++)
    {
        cin >> tablicaNaLiczby[j];
    }
    for (int j=n-1; j>=0; j--)
    {
        cout << tablicaNaLiczby[j] << " ";
    }
}
int main()
{
    int liczbaTestow, n;
    int tablicaNaLiczby [100];

    cin >> liczbaTestow;
    for (int i=0; i<liczbaTestow; i++)
    {
        odwrocTablice(tablicaNaLiczby, n);
    }
    return 0;
}
//#################Podzielnosc(PP0601B)#################//
#include <iostream>

using namespace std;

void podzielnosc(int n, int x, int y)
{
        int ai = 1;
        while (ai<n)
        {
            if ((ai%x == 0)&&(ai%y != 0))
            {
                cout<<ai<< " ";
            }
            ai++;
        }
}
int main()
{
    int ile_prob;
    cin>>ile_prob;

    for (int i=1; i<=ile_prob; i++)
    {
        int n, x, y;
        cin>>n>>x>>y;
        podzielnosc(n,x,y);
    }
    return 0;
}
//#################Parzyste nieparzyste(PP0602A)#################//

#include <iostream> //SPOJ!!!!!!!!!!!
#include <cstdio>

using namespace std;

void parzysteNieparzyste (int *tablicaNaLiczby, int n)
{
    for (int j=0; j<n; j++)
    {
        cin >> tablicaNaLiczby[j];
    }
    for (int k=1; k<n; k+=2)
    {
        cout << tablicaNaLiczby[k] << " ";
    }
    for (int l=0; l<n; l+=2)
    {
        cout << tablicaNaLiczby[l] << " ";
    }
    cout << endl;
}
int main()
{
    int liczbaTestow, n;
    int *tablicaNaLiczby;

    cin >> liczbaTestow;
    for (int i=0; i<liczbaTestow; i++)
    {
        cin >> n;
        tablicaNaLiczby = new int [n];
        parzysteNieparzyste(tablicaNaLiczby, n);
        delete [] tablicaNaLiczby;
    }
    return 0;
}
//#################Liczby Pierwsze(PRIME_T)#################//
#include <iostream>
#include <math.h>

using namespace std;

void sprawdzanieLiczbaPierwsza(int liczbaDoSprawdzenia)
{
    int ileRazy=1;
    int pierwiastek = sqrt(liczbaDoSprawdzenia);
    if ((liczbaDoSprawdzenia==2)||(liczbaDoSprawdzenia==3))
        cout << "TAK" << endl;
    else if (liczbaDoSprawdzenia==1)
        cout << "NIE" << endl;
    else
    {
        int j=2;
        while (j<=pierwiastek)
        {
            if (liczbaDoSprawdzenia%j != 0)
            {
                j++;
                ileRazy++;
            }

            else
            {
                cout << "NIE" << endl;
                j = pierwiastek+1;
                ileRazy=1;
            }
        }
        if (ileRazy >1) cout << "TAK" << endl;
    }
}

int main()
{
    int ileProb, liczbaDoSprawdzenia;
    cin >> ileProb;


    for (int i=0; i<ileProb; i++)
    {
        cin >> liczbaDoSprawdzenia;
        sprawdzanieLiczbaPierwsza(liczbaDoSprawdzenia);

    }
    return 0;
}
//#################Przedszkolanka(PRZEDSZK)#################//
#include<iostream>
using namespace std;

int NWD(int a, int b)
{
    while(a!=b)
    {
       if(a>b)
         a = a-b;
       else
         b = b-a;
    }
    return a;
}

int main()
{
    int N;
    cin>>N;
    for (int i=1; i<=N; i++)
    {
        int a, b;
        cin>>a>>b;
        cout<<a*b/NWD(a, b)<<endl;
    }
    return 0;
}
//#################Zadanie probne(PTEST)#################//
#include <iostream>

using namespace std;

int a,b;


int main()
{
    cin>>a>>b;
    cout<<a+b<<endl;
    return 0;
}
//#################ROL(PTROL)#################//
#include <iostream>

using namespace std;

void przesunElementy (int *tablicaNaLiczby, int n)
{
    for (int j=0; j<n; j++)
    {
        cin >> tablicaNaLiczby[j];
    }
    for (int j=1; j<n; j++)
    {
        cout << tablicaNaLiczby[j] << " ";
    }
    int j=0;
    cout << tablicaNaLiczby[j];
    cout << endl;
}

int main()
{
    int liczbaTestow, n;
    int *tablicaNaLiczby;

    cin >> liczbaTestow;
    for (int i=0; i<liczbaTestow; i++)
    {
        cin >> n;
        tablicaNaLiczby = new int [n];
        przesunElementy(tablicaNaLiczby, n);
        delete [] tablicaNaLiczby;
    }
    return 0;
}
//#################Sprawdzanie sudoku(SUDOKUC)#################//
#include <iostream>

using namespace std;

bool sprawdzenieKwadratu3x3(int tab[9][9])
{
    int suma = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int a = (3 * i); a < (3 * i + 3); a++)
            {
                for (int b = (3 * j); b < (3 * j + 3); b++)
                {
                    suma += tab[a][b];
                    if (a == (3 * i + 2) && b == (3 * j + 2) && suma != 45) return 0;
                }
            }
            suma = 0;
        }
    }
    return 1;
}
bool sprawdzenieWierszyiKolumn(int tab[9][9])
{
    for (int x = 0; x < 9; x++)
    {
        for (int i = 0; i < 9; i++)
        {
            if ((tab[x][i] < 1) || (tab[x][i] > 9)) return 0;
            for (int j = 8; j >= 0; j--)
            {
                if (j == i) break;
                if (tab[x][i] == tab[x][j]) return 0;
                if (tab[i][x] == tab[j][x]) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int ileZestawow;
    cin >> ileZestawow;
    int tab[9][9];
    for (int a = 0; a < ileZestawow; a++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> tab[i][j];
            }
        }
        bool odpowiedz1 = 0, odpowiedz2 = 0;
        odpowiedz1 = sprawdzenieKwadratu3x3(tab);
        odpowiedz2 = sprawdzenieWierszyiKolumn(tab);
        if ((odpowiedz1 == true)&&(odpowiedz2 == true)) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}
//#################Predkosc srednia(VSR)#################//
#include <iostream>

using namespace std;

int v1,v2,ile;

int main()
{
    cin>>ile;
    for(int i=1; i<=ile; i++)
    {
        cin>>v1>>v2;
        cout<<2*v1*v2/(v1+v2)<<endl;
    }
    return 0;
}








