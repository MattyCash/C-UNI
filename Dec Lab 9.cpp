#include <bits/stdc++.h>
using namespace std;
int main(){
    string message;
    int key;
    cin >> message >> key;
    string decrypted="";
    key%=26;
    for(int i = 0 ; i < message.size(); ++i){
        if(isalpha(message[i])){

            int k=(int)(message[i]);
            k-=key;
            if(islower(message[i])&&k<'a'){
            k+=26;
            }
            else if(isupper(message[i])&&k<'A'){
            k+=26;
            }
            decrypted+=(char)k;
        }
        else{
            decrypted += message[i];
        }
    }
    cout<<decrypted;
}
