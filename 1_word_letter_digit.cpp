#include <bits/stdc++.h>
using namespace std;

void count(vector<string> vs);
void separate(vector<string> vs);

//number of words, letters, digits, other characters
//separate letters, digits, other characters

int main(){
    vector<string> vs;
    string str;
    fstream myfile;

    myfile.open("input_files/1.txt");
    if(myfile.is_open()){
        while (getline(myfile, str)){
            vs.push_back(str);
        }
        myfile.close();
    }

    count(vs);
    separate(vs);
}

void count(vector<string> vs){
    int words, letters, digits, others;
    words = letters = digits = others = 0;
    string str;

    for(int i = 0; i<vs.size(); i++){
        for(int j = 0; j<vs[i].size(); j++){
            if((vs[i][j] >= 'a' && vs[i][j] <= 'z') || (vs[i][j] >= 'A' && vs[i][j] <= 'Z'))
                letters++;
            else if(vs[i][j] >= '0' && vs[i][j] <= '9')
                digits++;
            else if(vs[i][j] != ' ')
                others++;
        }
        istringstream iss(vs[i]);
        while(iss >> str)
            words++;
    }

    cout << "No of word: " << words << endl;
    cout << "No of letters: " << letters << endl;
    cout << "No of digits: " << digits << endl;
    cout << "No of other characters: " << others << endl;
}

void separate(vector<string> vs){
    vector<char> letters, digits, others;

    for(int i = 0; i<vs.size(); i++){
        for(int j = 0; j<vs[i].size(); j++){
            if((vs[i][j] >= 'a' && vs[i][j] <= 'z') || (vs[i][j] >= 'A' && vs[i][j] <= 'Z'))
                letters.push_back(vs[i][j]);
            else if(vs[i][j] >= '0' && vs[i][j] <= '9')
                digits.push_back(vs[i][j]);
            else if(vs[i][j] != ' ')
                others.push_back(vs[i][j]);
        }
    }

    cout << "Existing letters: ";
    for(auto a : letters){
        cout << a << " ";
    }

    cout << "\nExisting digits: ";
    for(auto a : digits){
        cout << a << " ";
    }

    cout << "\nExisting other characters: ";
    for(auto a : others){
        cout << a << " ";
    }
}