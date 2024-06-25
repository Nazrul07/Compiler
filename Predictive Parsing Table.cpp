#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

char prol[7][10] = {"S", "A", "A", "B", "B", "C", "C"};
char pror[7][10] = {"A", "Bb", "Cd", "aB", "@", "Cc", "@"};
char prod[7][10] = {"S->A", "A->Bb", "A->Cd", "B->aB", "B->@", "C->Cc", "C->@"};
char first[7][10] = {"abcd", "ab", "cd", "a@", "@", "c@", "@"};
char follow[7][10] = {"$", "$", "$", "a$", "b$", "c$", "d$"};

map<char, map<char, string>> parsingTable;
set<char> terminals;
set<char> nonTerminals;
vector<char> orderedTerminals;

// Function to build the parsing table
void buildParsingTable()
{
    for (int i = 0; i < 7; ++i)
    {
        char left = prol[i][0];
        string right = pror[i];
        string firstSet = first[i];
        string followSet = follow[i];

        nonTerminals.insert(left);

        for (char firstCh : firstSet)
        {
            if (firstCh != '@')
            {
                parsingTable[left][firstCh] = right;
                terminals.insert(firstCh);
            }
            else
            {
                for (char followCh : followSet)
                {
                    parsingTable[left][followCh] = right;
                    terminals.insert(followCh);
                }
            }
        }
    }
    terminals.insert('$'); // Adding end marker to terminals

    // Order terminals for consistent column display
    orderedTerminals.assign(terminals.begin(), terminals.end());
    sort(orderedTerminals.begin(), orderedTerminals.end());
}

// Function to print the parsing table
void printParsingTable()
{
    cout << "---------------------------------------------------------------------" << endl;
    cout << setw(10) << " ";
    for (char t : orderedTerminals)
    {
        cout << setw(10) << t;
    }
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (char nt : nonTerminals)
    {
        cout << setw(10) << nt;
        for (char t : orderedTerminals)
        {
            if (parsingTable[nt].count(t))
            {
                cout << setw(10) << parsingTable[nt][t];
            }
            else
            {
                cout << setw(10) << "";
            }
        }
        cout << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }
}

int main()
{
    buildParsingTable();
    printParsingTable();
    return 0;
}
