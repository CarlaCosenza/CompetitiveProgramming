#include <bits/stdc++.h>
using namespace std;

int pi[1000020], si;
char s[1000010];

void p_f(){
    pi[0] = -1;
    for(int i = 0 , j = -1; i < si ; pi[++i] = ++j){
        while(j >= 0 and s[i] != s[j]) j = pi[j];
    }
}

int main(){

    scanf("%s" , s);
    si = strlen(s);
    p_f();
    for(int i = 1 ; i <= si ; i++) printf("%d " , pi[i]);
    printf("\n");

    return 0;
}
