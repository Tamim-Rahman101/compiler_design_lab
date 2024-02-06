#include<bits/stdc++.h>
using namespace std;

int get_precedence(char c){
    string precedence_str = "-+/*%^";
    for(int i = 0; i<precedence_str.size(); i++){
        if(precedence_str[i] == c)
            return i;
    }
    return -1;
}

// (A-B)*(D/E)              AB-DE/*
// A+(B*C-(D/E^F)*G)*H      ABC*DEF^/G*-H*+
// a+b*(c^d-e)^(f+g*h)-i    abcd^e-fgh*+^*+i-

int main(){
    string str;
    string exp = "";
    cin >> str;
    str += ")";

    stack<char> stk;
    stk.push('(');
    for(int i = 0; i<str.size(); i++){
        if(str[i] == '(')
            stk.push(str[i]);
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^'){
            while(get_precedence(str[i]) <= get_precedence(stk.top())){
                exp += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
        else if(str[i] == ')'){
            while(stk.top() != '('){
                exp += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
            exp += str[i];
        // cout << i << "   " << exp << endl;
    }
    cout << "The postfix notation is: " << exp << endl;
}