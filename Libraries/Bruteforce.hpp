#include<bits/stdc++.h>

using namespace std;

struct key{
    int curr=0;
    vector<char> alphabet;
    int alphabetSize, keySize=1, mark;
    key(){
        for(int i=32; i<=126; i++)
            alphabet.push_back((char)i);
        mark=alphabetSize=26;
        curr=0;
    }
    key(int s, int e){
        //For all Characters 32-126
        //For Uppercase only 65-90
        //For Lowercase only 97-122
        //For Nummeric only 48-57
        for(int i=s; i<=e; i++)
            alphabet.push_back((char)i);
        mark=alphabetSize=26;
        curr=0;
    }
    key(string alphabet){
        for(size_t i=0; i<alphabet.size(); i++)
            (this->alphabet).push_back(alphabet[i]);
        mark=alphabetSize=alphabet.size();
        curr=0;
    }
    /*
    Increments key
    returns true if another digit is added
    */
    bool incrementKey(){
        curr++;
        if(mark==curr && mark!=1){
            keySize++;
            curr=0;
            mark*=alphabetSize;
            return true;
        }
        return false;
    }
    string getStringKey(){
        string ans="";
        int temp=curr;
        for(int i=0; i<keySize; i++){
            ans+=alphabet[temp%alphabetSize];
            temp/=alphabetSize;
        }
        return ans;
    }
    vector<int> getCeasarKey(){
        vector<int> ans;
        int temp=curr;
        for(int i=0; i<keySize; i++){
            ans.push_back((temp%alphabetSize)+1);
            temp/=alphabetSize;
        }
        return ans;
    }
};