// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...  
// 1.   Вияснити, чи є серед цих символів пара сусідні букв "aa" або "bb" або "cc".  
// 2.   Замінити кожну пару сусідніх букв "aa" або "bb" або "cc" трійкою зірочок "***". 
//      Lab 8.1 Ітераційний спосіб

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

void Process(char* str, char* newStr, bool &changed) {
    char state = ' ';
    int strPos = 0;
    int newStrPos = 0;
    changed = false;

    while (str[strPos] > 0) {
        switch (str[strPos]) {
        case 'a':
            if (state == 'a') {
                newStr[newStrPos++] = '*';
                newStr[newStrPos++] = '*';
                newStr[newStrPos++] = '*';
                changed = true;
                state = ' ';
            }
            else {
                if (state == 'b') newStr[newStrPos++] = 'b';
                if (state == 'c') newStr[newStrPos++] = 'c';
                state = 'a';
            }
            break;
        case 'b':
            if (state == 'b') {
                newStr[newStrPos++] = '*';
                newStr[newStrPos++] = '*';
                newStr[newStrPos++] = '*';
                changed = true;
                state = ' ';
            }
            else {
                if (state == 'a') newStr[newStrPos++] = 'a';
                if (state == 'c') newStr[newStrPos++] = 'c';
                state = 'b';
            }
            break;
        case 'c':
            if (state == 'c') {
                newStr[newStrPos++] = '*';
                newStr[newStrPos++] = '*';
                newStr[newStrPos++] = '*';
                changed = true;
                state = ' ';
            }
            else {
                if (state == 'a') newStr[newStrPos++] = 'a';
                if (state == 'b') newStr[newStrPos++] = 'b';
                state = 'c';
            }
            break;
        default:
            if (state == 'a') newStr[newStrPos++] = 'a';
            if (state == 'b') newStr[newStrPos++] = 'b';
            if (state == 'c') newStr[newStrPos++] = 'c';
            newStr[newStrPos++] = str[strPos];
            state = ' ';
            break;
        }
        strPos++;
    }
    if (state == 'a') newStr[newStrPos++] = 'a';
    if (state == 'b') newStr[newStrPos++] = 'b';
    if (state == 'c') newStr[newStrPos++] = 'c';
    newStr[newStrPos++] = '\0';
    return;
}

int main() {
    char str[101];
    char newStr[151];
    bool changed;

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    Process(str, newStr, changed);

    cout << "String: " << str << endl << endl;
    if (changed) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }
    
    return 0;
}