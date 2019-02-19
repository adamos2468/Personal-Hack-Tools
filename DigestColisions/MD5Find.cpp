#include <openssl/md5.h>
#include <bits/stdc++.h>
#include "../Libraries/Bruteforce.hpp"

using namespace std;

bool tryMD5(char* digest, string temp){
    unsigned char * C = new unsigned char [temp.length()+1];
    strcpy ((char*)C, temp.c_str());
    int n=temp.size();
    unsigned char* md=(unsigned char*)malloc(16);
    MD5(C, n, md);
    bool flag=true;
    flag&=!strcmp(digest, (char*)md);
    free(md);
    delete[] C;
    return flag;
}

unsigned int hexVal(char c){
    if('0'<=c && c<='9')
        return c-'0';
    else if('a'<=c && c<='f')
        return c-'a'+10;
    else if('A'<=c && c<='F')
        return c-'A'+10;
    return -1;
}

string String2Hex(string c){
    string s;
    for(size_t i=0; i<c.size(); i+=2){
        int val=(hexVal(c[i])<<4)+hexVal(c[i+1]);
        s+=(char)val;
    }
    return s;
}

int main(int argc, char** argv){
    string temp;
    cin>>temp;
    temp=String2Hex(temp);
    char *c=new char[temp.size()+1];
    strcpy(c,temp.c_str());
    if(argc==2){
        ifstream in (argv[1]);
        string klidi;
        bool flag=false;
        while(in>>klidi){
            if(tryMD5(c, klidi)){
                cout<<klidi<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<"Not in the database\n";
    }
    else{
        key k=key('a', 'z');
        while(!tryMD5(c, k.getStringKey()))
            k.incrementKey();
        cout<<k.getStringKey()<<endl;
    }
    delete[] c;
}