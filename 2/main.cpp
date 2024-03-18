#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool vst[1007];
vector<int> prime;
int64_t nn;

void sito(int range) {
    vst[0] = true;
    vst[1] = true;
    vst[2] = false;
    for(int i=2; i <= range; i++) {
        if(!vst[i]){
            prime.push_back(i);
            for(int j=i+i; j<=range; j+=i) {
                vst[j]=true;
            }
        }
    }
}

int64_t ilo(int64_t a, int64_t b, int64_t mod) {
    int64_t wynik = 0;
    a%=mod;
    b%=mod;
    while(b>0) {
        if(b&1){
            wynik += a;
            if(wynik > mod) {
                wynik -= mod;
            }
        }
        a<<=1;
        if(a>mod) {
            a-=mod;
        }
        b>>=1;
    }
    return wynik;
}

int64_t pot(int64_t a, int64_t b, int64_t mod) {
    int64_t wynik = 1;
    while(b>0) {
        if(b&1){
            wynik = ilo(wynik,a,mod);
        }
        a = ilo(a, a, mod);
        b >>= 1;
    }
    return wynik;
}

int64_t nwd(int64_t l1, int64_t l2) {
    if(l2 == 0)
        return l1;
    return nwd(l2, l1%l2);
}

bool MRTest(int64_t a, int64_t d) {
    srand(time(NULL));
    int64_t x = (rand()%(a-1)) + 1;
    int64_t y = pot(x, d, a);
    if(y == 1 || y == a-1)
        return true;
    while(d!=a-1) {
        y = ilo(y,y,a);
        d *= 2;
        if(y == 1) return false;
        if(y == a-1) return true;
    }
    return true;
}

int64_t is_prime(int64_t a,int tc) {
    if(a == 1)
        return true;
    for(int i : prime) {
        if(!(a%i)){
            return i;
        }
    }
    int64_t d = a-1;
    while(!(d&1))
        d /= 2;
    for(int i=0; i < tc; i++) {
        if(MRTest(a,d) == false)
            return 0;
    }
    return a;
}

int64_t find_div(int64_t a) {
    for(unsigned int i=0; i<5 && i < prime.size(); i++) {
        if(a % prime[i] == 0) return prime[i];
    }
    int64_t d = is_prime(a, 7);
    if(d > 0)
        return d;
    //srand(time(NULL));
    int64_t x = (rand()%(a-2))+2;
    int64_t y = x;
    int64_t c = (rand()%(a-1))+1;
    d=1;
    while(d==1){
        x = (pot(x, 2, a) + c + a)%a;
        y = (pot(y, 2, a) + c + a)%a;
        d = nwd(abs(x-y), nn);
        if(d == nn) return find_div(a);
    }
    return d;
}

vector<int64_t> factorization(unsigned long long m) {
    vector<int64_t> res;
    while(m > 1) {
        int64_t d = find_div(m);
        m /= d;
        res.push_back(d);
    }
    sort(res.begin(), res.end());
    return res;
}

void solve(int64_t n) {
    if(n == -1 || n == 0 || n == 1) {
        cout<< n << " = " << n << '\n';
        return;
    }
    unsigned long long m = n;
    vector<int64_t> res = factorization(m);
    cout<< n << " = ";
    if(n < 0) cout<< "-1 * ";
    for(unsigned int i=0; i<res.size(); i++) {
        cout<< res[i] << ' ';
        if(i != res.size()-1) cout<< "* ";
    }
    cout<< '\n';
}

int main(int argc, char* argv[]) {

    if(argc <= 1) {
        cerr<< "Enter the numbers to factor. ex: ./main 14 8 \n";
    }
    sito(1000);
    for(int i=1; i<argc; i++) {
        int64_t n = 0;
        try {
            n = stoll(argv[i], nullptr, 10);
            int j=0;
            if(argv[i][j] == '-') j++;
            for(; argv[i][j] != '\0'; j++) {
                int ld = int(argv[i][j] - '0');
                if(ld < 0 || ld > 9) throw 1;
            }
        }
        catch(invalid_argument const& ex) {
            clog<< "Error: Incorrect input!\n";
            continue;
        }
        catch(int ex) {
            clog<< "Error: Incorrect input! Not a number\n";
            continue;
        }
        solve(n);
    }   
    // ./main 1231 12423 -34237 9223372036854775783 -9223372036854775808
    return 0;
}