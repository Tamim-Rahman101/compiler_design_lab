#include<bits/stdc++.h>
using namespace std;

bool is_variable(string str);
bool is_integer(string str);

//int var: (i-nI-N)(a-zA-Z0-9)*
//short int: (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
//long int: (1-9)(0-9)(0-9)(0-9)(0-9)+

int main(){
    fstream myfile;
    string str;

    myfile.open("input_files/4.txt");
    if(myfile.is_open()){
        while(myfile >> str){
            cout << str << " is ";
            if(is_variable(str))
                cout << "Integer Variable." << endl;
            else if(str.size() <= 4 && is_integer(str))
                cout << "ShortInt Number." << endl;
            else if(str.size() > 4 && is_integer(str))
                cout << "LongInt Number." << endl;
            else
                cout << "Invalid Input or Undefined." << endl;
        }
        myfile.close();
    }
}

bool is_variable(string str){
    if(tolower(str[0]) < 'i' || tolower(str[0]) > 'n'){
        return false;
    }
    for(int i = 1; i<str.size(); i++){
        if((tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') || (str[i] >= '0' && str[i] <= '9'))
            continue;
        else
            return false;
    }
    return true;
}

bool is_integer(string str){
    for(int i = 0; i<str.size(); i++){
        if(!(isdigit(str[i])))
            return false;
    }
    return true;
}
