#include <bits/stdc++.h>
int main(){
bool verify_pswd(std::size_t salted_hash, std::string salt, std::string pswd) {
    return std::has<decltype(pswd)>{}(pswd+salt) == hash;
}
}

