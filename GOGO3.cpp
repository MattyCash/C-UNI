#include <bits/stdc++.h>
using namespace std;
int main(){
    string message;
    int key;
    cin >> message >> key;
    string encrypted="";
    key%=26;
    for(int i = 0 ; i < message.size(); ++i){
        if(isalpha(message[i])){

            int k=(int)(message[i]);
            k+=key;
            if(islower(message[i])&&k>'z'){
            k-=26;
            }
            else if(isupper(message[i])&&k>'Z'){
            k-=26;
            }
            encrypted+=(char)k;
        }
        else{
            encrypted += message[i];
        }
    }
    cout<<encrypted;
}
