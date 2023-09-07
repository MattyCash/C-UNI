#include <iostream>
using namespace std;
int f(int v) {
v = 2 * v;
return v*v;}
int main() {
int i = 6;
f(i);
cout<<i;
return 0;}
