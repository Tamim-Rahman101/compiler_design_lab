#include<bits/stdc++.h>
using namespace std;

bool is_variable(string str);
bool is_binary(string str);

// Character variable = ch_(a-2A-Z0-9)(a-2A-Z0-9)*
// Binary variable = bn_(a-2A-20-9)(a-zA-Z0-9)*
// Binary Number = 0(0|1)(0|1)*
// Invalid Input or Undefined = Otherwise

int main(){
    fstream myfile;
    string str;

    myfile.open("input_files/6.txt");
    if(myfile.is_open()){
        while(getline(myfile, str)){
            cout << str << " is ";
            if(str[0] == 'c' && str[1] == 'h' && str[2] == '_' && is_variable(str))
                cout << "Character Variable." << endl;
            else if(str[0] == 'b' && str[1] == 'n' && str[2] == '_' && is_variable(str))
                cout << "Binary Variable." << endl;
            else if(is_binary(str))
                cout << "Binary Number." << endl;
            else
                cout << "Invalid Input or Undefined." << endl;
        }
    }
}

bool is_variable(string str){
    if(str.size() < 4)
        return false;
    
    for(int i = 3; i<str.size(); i++){
        if((tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') || (tolower(str[i]) >= '0' && tolower(str[i]) <= '9'))
            continue;    
        else
            return false;
    }
    return true;
}

bool is_binary(string str){
    if(str[0] != '0' || str.size() < 2)
        return false;

    for(int i = 1; i<str.size(); i++){
        if(str[i] != '1' && str[i] != '0')
            return false;
    }
    return true;
}