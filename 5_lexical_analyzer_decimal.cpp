#include<bits/stdc++.h>
using namespace std;

bool is_variable(string str);
bool is_valid_number(string str);      //checks if the string contains 0-9 and only one .

// Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
// Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
// Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
// Invalid Input or Undefined = Otherwise

int main(){
    fstream myfile;
    string str;

    myfile.open("input_files/5.txt");
    if(myfile.is_open()){
        while(myfile >> str){
            cout << str << " is ";
            if(is_variable(str))
                cout << "Float Variable." << endl;
            //float always have . in the third position from the last
            else if(str[str.size() - 3] == '.' && is_valid_number(str))
                cout << "Float Number." << endl;
            else if(is_valid_number(str))
                cout << "Double Number." << endl;
            else
                cout << "Invalid Input or Undefined." << endl;
        }
        myfile.close();
    }
}

bool is_variable(string str){
    if(tolower(str[0]) < 'a' || tolower(str[0]) > 'z' || (tolower(str[0]) > 'h' && tolower(str[0] < 'o'))){
        return false;       //wrong for smaller than a, greater than z and in between h, o
    }
    for(int i = 1; i<str.size(); i++){
        if((tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') || (str[i] >= '0' && str[i] <= '9'))
            continue;
        else
            return false;
    }
    return true;
}

bool is_valid_number(string str){
    if(str[0] == '0' && str[1] != '.')      //to check 00.12, 01.012
        return false;

    bool found_point = false;
    for(int i = 0; i<str.size(); i++){
        if(str[i] == '.'){
            if(found_point)
                return false;
            found_point = true;
        }
        else if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
