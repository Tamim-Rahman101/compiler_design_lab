#include<bits/stdc++.h>
using namespace std;

string department(string dept);
string year(string code);
string semester(string code);
string course(string str);
string course_type(string code);

//CSE-3141 as Computer Science & Engineering, 3rd Year, 1st Semester, 
//Compiler Design, Theory

int main(){
    fstream myfile;
    string str, dept, code;

    myfile.open("input_files/3.txt");
    if(myfile.is_open()){
        while (getline(myfile, str)){
            dept = str.substr(0, str.size() - 5);   //CSE-3141 > CSE
            code = str.substr(str.size() - 4, 4);   //CSE-3141 > 3141

            cout << str << " as " << department(dept) << ", " << year(code);
            cout << " Year, " << semester(code) << " Semester, ";
            cout << course(str.substr(0, str.size() - 1));     //CSE-3141 > CSE-314
            cout  << ", " << course_type(code) << "." << endl;
        }
    }   
}

string department(string dept){
	if(dept == "CSE") return "Computer Science & Engineering";
    else if(dept == "EEE") return "Electrical & Electronics Engineering";
	else if(dept == "ICE") return "Information Communication & Engineering";
	else return "Invalid";
}
string year(string code){
	if(code[0] =='1') return "1st";
	else if(code[0] =='2') return "2nd";
	else if(code[0] =='3') return "3rd";
	else if(code[0] =='4') return "4th";
	else return "Invalid";
}
string semester(string code){
	if(code[1] == '1') return "1st";
	else if(code[1] == '2') return "2nd";
	else return "Invalid";	
}
string course(string str){
	if(str == "CSE-314") return "Compiler Design";
	else if(str == "ICE-316") return "Communication Engineering";
    else if(str == "EEE-113") return "Basic Electronics";
    else return "Invalid";
}
string course_type(string code){
	if(code[3] == '1') return "Theory";
	else if(code[3] == '2') return "Lab";
	else return "Invalid";
}
