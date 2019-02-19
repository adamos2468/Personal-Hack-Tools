#include<bits/stdc++.h>

using namespace std;
char pin[100][100];
void printTable(string c, int h){
    memset(pin, 0, sizeof(pin));
    int row=h, col=c.size()/h, count=0;
    for(int j=0; j<=col; j++){
        for(int i=0; i<row; i++){
            if(count<c.size())
                pin[i][j]=c[count];
            count++;
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<=col; j++){
            if(pin[i][j]!=0)
                cout<<pin[i][j];
        }
    }
    cout<<endl;
}
int main(){
    string c;
    getline(cin, c);
    for(int h=1; h<=c.size(); h++){
        printTable(c, h);
    }
}