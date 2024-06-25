#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Utility function to print the stack
void printStack(stack<char> s)
{
    string result;
    while (!s.empty())
    {
        result = s.top() + result;
        s.pop();
    }
    cout << result;
}

// Utility function to print the vector of characters
void printVector(const vector<char>& v)
{
    for (char c : v)
    {
        cout << c;
    }
}

void parseInput(const string& input)
{
    // Define grammar rules
    unordered_map<char, unordered_map<char, string>> parseTable = {
        {'E', {{'i', "TH"}}},
        {'H', {{'+', "+TH"}, {'$', "#"}}},
        {'T', {{'i', "FU"}}},
        {'U', {{'*', "*FU"}, {'+', "#"}, {'$', "#"}}},
        {'F', {{'i', "i"}}}
    };

    /*unordered_map<char, unordered_map<char,string>> parseTable =
    {
        {'E', {{'i', "TH"}}},
        {'T', {{'i', "FU"}}},
        {'F', {{'i', "i"}}},
        {'U', {{'*', "FU"},{'+', "#"}, {'$', "#"}}},
        {'H', {{'+', "+TH"}, {'$', "#"}}}
    };*/

    stack<char> parseStack;
    parseStack.push('$');
    parseStack.push('E');

    vector<char> inputVec(input.begin(), input.end());
    inputVec.push_back('$');

    cout << "Stack\t\tInput\t\tOutput\n";

    while (!parseStack.empty())
    {
        char stackTop = parseStack.top();
        char currentInput = inputVec[0];

        // Print current stack and input
        printStack(parseStack);
        cout << "\t\t";
        printVector(inputVec);
        cout << "\t\t";

        if (stackTop == currentInput)
        {
            parseStack.pop();
            inputVec.erase(inputVec.begin());
            cout << "Match " << currentInput << "\n";
        }
        else if (parseTable.find(stackTop) != parseTable.end() && parseTable[stackTop].find(currentInput) != parseTable[stackTop].end())
        {
            parseStack.pop();
            string production = parseTable[stackTop][currentInput];
            cout << stackTop << "->" << production << "\n";
            if (production != "#")
            {
                for (auto it = production.rbegin(); it != production.rend(); ++it)
                {
                    parseStack.push(*it);
                }
            }
        }
        else
        {
            cout << "Error: Invalid input string.\n";
            return;
        }
    }

    cout << "Input string is accepted.\n";
}

int main()
{
    string inputString = "i+i*i";
    parseInput(inputString);
    return 0;
}
