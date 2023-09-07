#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
  if(n == 1) return 0;
  if(n % 2 == 0 && n != 2){
    return 0;
  }
  for(int i = 3 ; i * i <= n; ++i)
    if(n % i == 0) return 0;
  return 1;
}

main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0,x ; i < n; ++i){
      cin >> x;
      ans += prime(x);
  }
  cout<<ans;
}
