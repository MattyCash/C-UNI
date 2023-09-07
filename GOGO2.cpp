#include <bits/stdc++.h>
using namespace std;
char convert(char arr) {
  if ('a' <= arr && arr <= 'z') {
    return char(arr - 32);
  }
  else {
    return arr;
  }
}
int main() {
  char arr[1000];
  cin >> arr;
  int length = strlen(arr);
  for (int i = 0; i < length; i++) {
    cout << convert(arr[i]);
  }
}
