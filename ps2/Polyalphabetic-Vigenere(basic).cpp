#include <bits/stdc++.h>
using namespace std;

int charshift(char c) {
    if (isupper(c)) return c - 'A';
    if (islower(c)) return c - 'a';
    return 0;
}

string Encode(string &text,string &keyword) {
    string result;
    int k = keyword.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        int shift = charshift(keyword[i % k]);

        if (isupper(c)) {
            result += char(((c - 'A' + shift) % 26) + 'A');
        } else if (islower(c)) {
            result += char(((c - 'a' + shift) % 26) + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

string Decode(string &text,string &keyword) {
    string result;
    int k = keyword.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        int shift = charshift(keyword[i % k]);
        if (isupper(c)) {
            result += char(((c - 'A' - shift + 26) % 26) + 'A');
        } else if (islower(c)) {
            result += char(((c - 'a' - shift + 26) % 26) + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string message, keyword;
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter keyword: ";
    cin >> keyword;
    cout << "\n";
    string caesarEnc = Encode(message, keyword);
    cout << "Result : " << caesarEnc << endl;
    return 0;
}
