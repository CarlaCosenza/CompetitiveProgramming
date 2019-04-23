#include <bits/stdc++.h>
using namespace std;

struct point {
    long long x, y;

    long long operator%(point p){
        return x*p.y - y*p.x;
    }

    long long operator~(){
        return x*x + y*y;
    }

    point operator-(point p){
        point t;
        t.x = x-p.x;
        t.y = y-p.y;
        return t;
    }

    bool operator<(point p) const{
        if(x == p.x) return y < p.y;
        return x < p.x;
    }

};

point orgin, p;
vector <point> v;
vector <point> ch;
long long n, l;
map <point, int> m;
long double d;

bool calculator(point p, point q){
    long long v = (p - orgin)%(q - orgin);
    if(v == 0) return ~(p - orgin) < ~(q - orgin);
    return v > 0;
}

int main(){

    scanf("%lld" , &n);
    orgin.x = 1e10;
    for(int i = 0 ; i < n ; i++){
        scanf("%lld%lld" , &p.x, &p.y);
        v.push_back(p);
        m[p] = i + 1;
        if(orgin.x > p.x){
            orgin = p;
        }
        if(orgin.x == p.x and orgin.y > p.y) orgin = p;
    }
    sort(v.begin(), v.end(), calculator);

    //for(int i = 0 ; i < v.size() ; i++) printf("%lld %lld" , v[i].x, v[i].y);

    ch.push_back(v[0]);
    ch.push_back(v[1]);

    for(int i = 2 ; i < v.size() ; i++){
        while((ch[ch.size()-1] - ch[ch.size() - 2])%(v[i] - ch[ch.size() - 2]) <= 0){
            ch.pop_back();
            if(ch.size() == 1) break;
        }
        ch.push_back(v[i]);
    }
    printf("%lu\n" , ch.size());
    for(int i = 0 ; i < ch.size() ; i++) printf("%d " , m[ch[i]]);
    printf("\n");

    d = 0;

    for(int i = 1 ; i < ch.size() ; i++){
        d += sqrt(~(ch[i] - ch[i-1]));
        printf("d = %lf\n", (double)d);
    }
    d += sqrt(~(ch[0] - ch[ch.size() - 1]));
    printf("%.9lf\n" , (double)d);

    d = 0;
    l = 0;
    for(int i = 0 ; i < ch.size() - 1 ; i++){
        l += ch[i].y*ch[i+1].x - ch[i].x*ch[i+1].y;
    }
    l += ch[0].x*ch[ch.size() - 1].y - ch[0].y*ch[ch.size() - 1].x;
    l = abs(l);
    if(l%2 == 0) printf("%lld.0\n" , l/2);
    else printf("%lld.5\n" , l/2);

    return 0;
}



