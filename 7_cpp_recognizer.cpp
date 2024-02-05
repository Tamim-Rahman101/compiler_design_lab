#include<bits/stdc++.h>
using namespace std;

bool is_keyword(string str);
bool is_operator(string str);
bool is_constant(string str);
bool is_identifier(string str);


int main(){
    fstream myfile;
    string str;

    myfile.open("input_files/7.txt");
    if(myfile.is_open()){
        while (myfile >> str){
            cout << str << " is ";
            if(is_keyword(str))
                cout << "a keyword" << endl;
            else if(is_operator(str))
                cout << "an operator" << endl;
            else if(is_constant(str))
                cout << "a constant" << endl;
            else if(is_identifier(str))
                cout << "an identifier" << endl;
            else
                cout << "invalid" << endl;
        }
    }
}

bool is_keyword(string str){
    vector<string> keywords = {
        "asm", "double", "new", "switch",
        "auto", "else", "operator", "template",
        "break", "enum", "private", "this",
        "case", "extern", "protected", "throw",
        "catch", "float", "public", "try",
        "char", "for", "register", "typedef",
        "class", "friend", "return", "union",
        "const", "goto", "short", "unsigned",
        "continue", "if", "signed", "virtual",
        "default", "inline", "sizeof", "void",
        "delete", "int", "static", "volatile",
        "do", "long", "struct", "while"
    };

    for(int i = 0; i<keywords.size(); i++){
        if(keywords[i] == str)
            return true;
    }
    return false;
}

bool is_operator(string str){
    vector<std::string> operators = {
        "+", "-", "*", "/", "%",  // Arithmetic operators
        "++", "--",               // Increment and decrement operators
        "==", "!=",               // Relational operators
        "<", ">", "<=", ">=",     // Relational operators
        "&&", "||", "!",          // Logical operators
        "&", "|", "^", "~",       // Bitwise operators
        "<<", ">>",               // Bitwise shift operators
        "=", "+=", "-=", "*=", "/=", "%=",  // Assignment operators
        "<<=", ">>=",             // Assignment operators
        "&=", "|=", "^=",         // Assignment operators
        "?", ":",                 // Ternary conditional operator
        "->", ".",                // Member access operators
        "[]", "()"
    };

    for(int i = 0; i<operators.size(); i++){
        if(operators[i] == str)
            return true;
    }
    return false;
}

bool is_constant(string str){
    if((str[0] == '"' && str[str.size() - 1] == '"') || (str[0] == '\'' && str[str.size() - 1] == '\''))
        return true;

    for(int i = 0; i<str.size(); i++){
        if(!isdigit(str[i]) && str[i] != '.')
            return false;
    }
    return true;
}

bool is_identifier(string str){
    if(str[0] != '_' && !isalpha(str[0]))
        return false;

    for(int i = 1; i<str.size(); i++){
        if(!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_')
            return false;
    }
    return true;
}