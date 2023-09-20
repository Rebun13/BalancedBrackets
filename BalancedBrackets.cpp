#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string isBalanced(string s) {
    char openTag = 'o';
    map<char, char> brackets{
        {'[',openTag},
        {'{',openTag},
        {'(',openTag},
        {']','['},
        {'}','{'},
        {')','('}
    };
    stack<char> bracketsStack;
    for(char c : s) {
        auto bracket = brackets.find(c);
        if(bracket == brackets.end()) return "NO"; // Unexpected character
        if(bracket->second == openTag) bracketsStack.push(c); // Opening bracket
        else { // Closing bracket
            if(bracketsStack.top() != bracket->second) return "NO";
            else bracketsStack.pop();
        }
    }
    if(!bracketsStack.empty()) return "NO";
    return "YES";
}

string isBalancedDebug(string s) {
    char openTag = 'o';
    map<char, char> brackets{
        {'[',openTag},
        {'{',openTag},
        {'(',openTag},
        {']','['},
        {'}','{'},
        {')','('}
    };
    stack<char> bracketsStack;
    for(char c : s) {
        auto bracket = brackets.find(c);
        if(bracket == brackets.end()) { // Unexpected character
            cout << "Unexpected character: " << c << endl;
            return "NO";
        }
        if(bracket->second == openTag) { // Opening bracket
            bracketsStack.push(c);
            cout << "New opening bracket: " << c << endl;
        } else { // Closing bracket
            if(bracketsStack.top() != bracket->second) {
                cout << "Wrong closing bracket: " << c << endl;
                return "NO";
            }
            else {
                cout << "Correct closing bracket: " << c << endl;
                bracketsStack.pop();
            }
        }
    }
    if(!bracketsStack.empty()) {
        cout << "Bracket stack not empty" << endl;
        return "NO";
    }
    return "YES";
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}
