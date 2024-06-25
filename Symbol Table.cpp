#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    int i = 0, j = 0, x = 0, n, flag = 0;
    void *add[15]; // Array to store addresses (using void* for illustration)
    char b[15], d[15], c, srch;

    cout << "Expression terminated by $:\n";
    while ((c = getchar()) != '$') {
        b[i] = c;
        i++;
    }
    b[i] = '\0'; // Null-terminate the string

    n = i - 1; // Length of the string

    cout << "Given expression: " << b << endl;

    cout << "Symbol table" << endl;
    cout << "Symbol\tAddress\tType" << endl;

    i = 0;
    while (i <= n) {
        c = b[i];
        if (isalpha(c)) {
            if (i == n) { // Last character
                void *p = malloc(sizeof(char)); // Example: Allocate memory for char
                add[x] = p;
                d[x] = c;
                cout << c << "\t" << p << "\tIdentifier" << endl; // Printing address using pointer directly
                x++;
            } else {
                char ch = b[i + 1];
                if (ch == '+' || ch == '-' || ch == '*' || ch == '=') {
                    void *p = malloc(sizeof(char)); // Example: Allocate memory for char
                    add[x] = p;
                    d[x] = c;
                    cout << c << "\t" << p << "\tIdentifier" << endl; // Printing address using pointer directly
                    x++;
                }
            }
        }
        i++;
    }

    cout << "Enter the symbol to be searched: ";
    srch = getchar(); // Read character for search

    for (i = 0; i < x; i++) {
        if (srch == d[i]) {
            cout << "Symbol found" << endl;
            cout << srch << "\t@address\t" << add[i] << endl; // Printing address using pointer directly
            flag = 1;
            break; // Exit loop on first match
        }
    }

    if (flag == 0) {
        cout << "Symbol not found" << endl;
    }

    return 0;
}
