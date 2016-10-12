#include<bits/stdc++.h>
using namespace std;

long long jumlahDigit(long long x){
    long long cnt = 0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}

long long divider(long long x){
    long long tmp = 1;
    while(x){
        tmp*=10;
        x--;
    }
    return tmp;
}

long long maxN(long long x){
    long long q;
    switch(x){
        case 2 : q = 9; break;
        case 4 : q = 99; break;
        case 6 : q = 999; break;
        case 8 : q = 9999; break;
        case 10 : q = 99999; break;
    }
    return q;
}

int main(){
    int terakhir = 0;
    long long p, q;
    cout << "masukkan N digit angka ajaib = ";
    cin >> p;
    q = maxN(p);
    bool flag = true;
    for(long long i = 0; i <= q; i++){
        long long a, b, digit, digitB, kuadrat;
        kuadrat = i*i;
        digitB = jumlahDigit(kuadrat);
        digit = jumlahDigit(kuadrat);
        digit -= (digit/2);
        a = kuadrat / divider(digit);
        b = kuadrat % divider(digit);
        if((a+b) == i && digitB == p){
            if (terakhir == 1) {cout << "dan "<< kuadrat;}
            else {cout << kuadrat<<", ";}
            flag = false;
        }
        if (i == (q - 1)) terakhir = 1;
    }
    if (flag) cout << "INVALID RANGE";
    cout << endl;
    return 0;
}
