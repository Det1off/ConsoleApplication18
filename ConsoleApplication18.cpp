#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isVowel(char ch);
string generatePassword(int length);

int main() {
    setlocale(0, "ru");

    // Task 1
    const int MAX_LENGTH = 256;
    char text[MAX_LENGTH];
    char symbol;
    int count = 0;

    cout << "Введите строку (не более 255 символов): ";
    cin.getline(text, MAX_LENGTH);

    cout << "Введите символ для поиска: ";
    cin >> symbol;

    cout << "Индексы вхождений символа '" << symbol << "': ";

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == symbol) {
            cout << i << " ";
            count++;
        }
    }

    if (count == 0) {
        cout << "совпадений нет.";
    }

    cout << "\n" << "Количество совпадений: " << count << "\n";

    // Task 2

    int totalChars = 0, words = 0, vowels = 0, consonants = 0, punctuation = 0, digits = 0, others = 0;
    bool inWord = false;

    cout << "Введите строку текста (на английском языке): ";
    cin.getline(text, MAX_LENGTH);

    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            totalChars++;
            if (isVowel(ch)) {
                vowels++;
            }
            else {
                consonants++;
            }
            if (!inWord) {
                words++;
                inWord = true;
            }
        }
        else {
            if (isspace(ch)) {
                inWord = false;
            }
            else if (isdigit(ch)) {
                digits++;
                totalChars++;
            }
            else if (ispunct(ch)) {
                punctuation++;
                totalChars++;
            }
            else {
                others++;
                totalChars++;
            }
        }
    }

    // Вывод результатов
    cout << "Всего символов в строке текста – " << totalChars << ", из них:\n";
    cout << "Слов – " << words << "\n";
    cout << "Гласных букв - " << vowels << "\n";
    cout << "Согласных букв - " << consonants << "\n";
    cout << "Знаков пунктуации - " << punctuation << "\n";
    cout << "Цифр – " << digits << "\n";
    cout << "Других символов – " << others << "\n";


    // Task 3

    int totalLetters = 0, words = 0;
    bool inWord = false;

    cout << "Введите строку текста: ";
    cin.getline(text, MAX_LENGTH);

    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            totalLetters++;
            if (!inWord) {
                words++;
                inWord = true;
            }
        }
        else {
            if (isspace(ch)) {
                inWord = false;
            }
        }
    }

    double averageWordLength = (words > 0) ? static_cast<double>(totalLetters) / words : 0;

    cout << "Количество слов: " << words << "\n";
    cout << "Средняя длина слова: " << averageWordLength << "\n";

    // Task 4

    const int MAX_SIZE = 1000;
    char text[MAX_SIZE];
    char word[MAX_SIZE];

    cout << "Введите строку текста: ";
    cin.getline(text, MAX_SIZE);

    cout << "Введите слово для поиска: ";
    cin >> word;

    int count = 0;
    char* p = text;

    while ((p = strstr(p, word)) != nullptr) {
        count++;
        p++;
    }

    cout << "Слово \"" << word << "\" встречается " << count << " раз(а) в тексте." << "\n";

    // Task 5

    int length;

    cout << "Введите длину пароля: ";
    cin >> length;

    if (length <= 0) {
        cout << "Длина пароля должна быть положительным числом!" << "\n";
        return 1;
    }

    string password = generatePassword(length);
    cout << "Сгенерированный пароль: " << password << "\n";

}

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

string generatePassword(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()_+[]{}|;:,.<>?";
    string password;

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        password += characters[index];
    }

    return password;
}