#include<bits/stdc++.h>
#include "../Libraries/Bruteforce.hpp"
using namespace std;

string alphabet;
string Decrypt(string c, vector<int> shifts){
    for(int i=0; i<c.size(); i++){
        int j=i%shifts.size();
        c[i]+=alphabet.size();
        c[i]-=shifts[j];
        c[i]%=alphabet.size();
        c[i]=alphabet[(int)c[i]];
    }
    return c;
}
string Encrypt(string c, vector<int> shifts){
    for(int i=0; i<c.size(); i++){
        int j=i%shifts.size();
        c[i]+=shifts[j];
        c[i]%=alphabet.size();
        c[i]=alphabet[(int)c[i]];
    }
    return c;
}
void matchTheAlphabet(string& c){
    for(int i=0; i<c.size(); i++)
        for(int j=0; j<alphabet.size(); j++)
            if(c[i]==alphabet[j]){
                c[i]=j;
                break;
            }
}
void makeTheAlphadet(){
    for(int i=0; i<26; i++)
        alphabet+=(char)('a'+i);
    alphabet+="! ";
}
int main(int argc, char** argv){
    string c;
    getline(cin, c);
    makeTheAlphadet();
    matchTheAlphabet(c);
    key s=key(alphabet);
    while(true){
        vector<int> ans;
        ans=s.getCeasarKey();
        cout<<Decrypt(c, ans)<<endl;
        if(s.incrementKey())
            cin.get();
    }
}