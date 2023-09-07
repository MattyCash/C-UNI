#include <bits/stdc++.h>
using namespace std;

struct{
    int id;
    string name;
    string surname;
    int n;
    double grades[100];
} student;

main(){
    cin >>student.id >> student.name>> student.surname >> student.n;
    for(int i = 0 ; i < student.n; ++i){
        cin >> student.grades[i];
    }
    sort(student.grades,student.grades+student.n);
    cout<<student.id << " " << student.name << ' ' << student.surname << " :";
    for(int i = 0 ; i < student.n; ++i){
        cout<<' '<<student.grades[i];
    }
}
