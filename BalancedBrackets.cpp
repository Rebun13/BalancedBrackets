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
string isBalancedAlt(string s)
{
    char openTag = 'o';
    map<char, char> brackets{
        {'[', openTag},
        {'{', openTag},
        {'(', openTag},
        {']', '['},
        {'}', '{'},
        {')', '('}};
    stack<char> bracketsStack;
    for (char c : s)
    {
        auto bracket = brackets.find(c);
        if (bracket == brackets.end())
            return "NO"; // Unexpected character
        if (bracket->second == openTag)
            bracketsStack.push(c); // Opening bracket
        else
        { // Closing bracket
            if (bracketsStack.top() != bracket->second)
                return "NO";
            else
                bracketsStack.pop();
        }
    }
    if (!bracketsStack.empty())
        return "NO";
    return "YES";
}

string isBalanced(string s)
{
    stack<char> bracketsStack;
    for (char c : s)
    {
        cout << "Next: " << c << endl;
        try {        
            switch (c)
            {
            case '[':
            case '(':
            case '{':
                bracketsStack.push(c);
                break;
            case ']':
                if (bracketsStack.empty() || bracketsStack.top() != '[')
                    return "NO";
                else
                    bracketsStack.pop();
                break;
            case ')':
                if (bracketsStack.empty() || bracketsStack.top() != '(')
                    return "NO";
                else
                    bracketsStack.pop();
                break;
            case '}':
                if (bracketsStack.empty() || bracketsStack.top() != '{')
                    return "NO";
                else
                    bracketsStack.pop();
                break;
            default:
                break;
            }
        } catch (const exception& e) {
            return "NO";
        }
    }
    if (!bracketsStack.empty())
    {
        return "NO";
    }
    return "YES";
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c)
                { return !ispunct(c); }));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c)
                { return !ispunct(c); })
            .base(),
        s.end());

    return s;
}
