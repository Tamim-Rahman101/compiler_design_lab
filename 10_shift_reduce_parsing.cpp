#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, string> rules = {
        {"E+E", "E"},
        {"E*E", "E"},
        {"(E)", "E"},
        {"x", "E"}
    };

// x*(x+x)      Accept
// x*x(x+x)     Reject
    string input;
    cin >> input;
    
    string parsed_string = "";
    string substr;
    for(int in_idx = 0; in_idx<input.size(); in_idx++){
        parsed_string += input[in_idx];
        substr = "";
        for(int ps_idx = parsed_string.size()-1; ps_idx >= 0; ps_idx--){
            substr = parsed_string[ps_idx] + substr;
            if(rules.count(substr) > 0){
                parsed_string = parsed_string.substr(0, ps_idx) + rules[substr];
                substr = "";
                ps_idx = parsed_string.size();     //psi-- will do size() - 1
            }
        }
        // cout << parsed_string << endl;
    }

    if(parsed_string == "E")
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;
}