#include<bits/stdc++.h>
using namespace std;

void count_print(vector<string> vs);
void separate_string(vector<string> vs);

//number of vowels, consonents
//print existing voweld, consonents
//one string contains all the words starting with vowel, other one starting with consonent

int main(){
    vector<string> vs;
    string str;
    fstream myfile;
    
    myfile.open("input_files/2.txt");
    if(myfile.is_open()){
        while (getline(myfile, str)){
            vs.push_back(str);
        }
    }

    count_print(vs);
    separate_string(vs);
}

void count_print(vector<string> vs){
    int vowel, consonent;
    vowel = consonent = 0;
    vector<char> vow, con;

    for(int i = 0; i<vs.size(); i++){
        for(int j = 0; j<vs[i].size(); j++){
            char c = vs[i][j];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                vowel++;
                vow.push_back(c);
            }
            else if((c >= 'b' && c <= 'z') || (c >= 'B' && c <= 'Z')){
                consonent++;
                con.push_back(c);
            }
        }
    }

    cout << "Number of vowels: " << vowel << endl;
    cout << "Number of consonents: " << consonent << endl;

    cout << "Existing vowels: ";
    for(auto a : vow)
        cout << a << " ";
    cout << "\nExisting consonents: ";
    for(auto a : con)
        cout << a << " ";
}

void separate_string(vector<string> vs){
    string s;
    vector<string> vowel_str, consonent_str;

    for(int i = 0; i<vs.size(); i++){
        istringstream iss(vs[i]);
        while(iss >> s){
            if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U'){
                vowel_str.push_back(s);
            }
            else if((s[0] >= 'b' && s[0] <= 'z') || (s[0] >= 'B' && s[0] <= 'Z')){
                consonent_str.push_back(s);
            }
        }    
    }

    cout << "\nString starting with vowels: ";
    for(auto a : vowel_str)
        cout << a << " ";
    
    cout << "\nString starting with consonents: ";
    for(auto a : consonent_str)
        cout << a << " ";
}