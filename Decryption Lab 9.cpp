#include <bits/stdc++.h>
using namespace std;
int main(){
char message[1001], cnt;
int key;
     cout << "Enter a message: ";
     cin.getline(message, 1001);
     cout << "Enter key: ";
     cin >> key;
     for(int i = 0; message[i] != '\0'; i++){
           cnt = message[i];
              if(cnt >= 'a' && cnt <= 'z'){
                 cnt -= key;
              if(cnt < 'a'){
                 cnt = cnt + 'z' - 'a' + 1;
              }
                 message[i] = cnt;
              }
              else if(cnt >= 'A' && cnt <= 'Z'){
                 cnt -= key;
           if(cnt > 'A'){
            cnt = cnt + 'Z' - 'A' + 1;
             }
          message[i] = cnt;
            }
         }
   cout << "Decrypted message: " << message;
return 0;
}

