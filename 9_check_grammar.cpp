#include<bits/stdc++.h>
using namespace std;

bool check_grammar(string str);

int main(){
    fstream myfile;
    string input;

    myfile.open("input_files/9.txt");
    if(myfile.is_open()){
        while(getline(myfile, input)){
            cout << input << " is ";
            if(check_grammar(input))
                cout << "a valid sentence" << endl;
            else
                cout << "an invalid sentence" << endl;
        }
    }
}

// S => SUB PRED
// SUB => PN | P
// PRED => V|V N
// PN => Sagor | Selim | Salma | Nipu
// P => he | she | I | we | you | they
// V => read | eat | take | run | write
// N => book | cow | dog | home | grass | rice | mango

bool check_grammar(string input){
    set<string> PN = {"Sagor", "Selim", "Salma", "Nipu"};
    set<string> P = {"he", "she", "I", "we", "you", "they"};
    set<string> V = {"read", "eat", "take", "run", "write"};
    set<string> N = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

    string str;
    vector<string> vs;
    istringstream iss(input);
    while (iss >> str){
        vs.push_back(str);
    }

    if(vs.size() > 3 || vs.size() < 2)
        return false;
    
    if(!PN.count(vs[0]) && !P.count(vs[0]))     // SUB => PN | P (first word)
        return false;
    else if(!V.count(vs[1]))                    // PRED => V (second word)
        return false;
    else if(vs.size() == 3 && !N.count(vs[2]))  // PRED => N (third word)
        return false;
    
    return true;   
}