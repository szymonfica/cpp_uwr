#include "classes.hpp"

using namespace calculator;

bool is_number(const string& s) {
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

double calc(string ex) {
    stack<symbol> S;
    //cout<< "ex : " << ex << endl;
    for(unsigned int i=0; i<ex.size(); i++) {
        if(ex[i] == ' ') continue;
        string ans;
        ans.push_back(ex[i]);
        while(i+1 < ex.size() && ex[i+1] != ' ') {
            i++;
            ans += ex[i];
        }
        if(is_number(ans)) {
            S.push(number(ans));
        }
        else if(fun::is_fun(ans)) {
            if(S.size() < fun::degree(ans)) {
                throw invalid_argument("Invalid number of function arguments!");
            }
            vector<double> a;
            for(int i=0; i<fun::degree(ans); i++) {
                a.push_back(S.top().get_value());
                S.pop();
            }
            reverse(a.begin(), a.end());
            fun f(ans, a);
            S.push(number(f.value()));
        }
        else if(constant::is_con(ans)) {
            S.push(constant(ans, constant::get_value(ans)));
        }
        else if(variable::is_var(ans)) {
            S.push(variable(ans));
        }
        else {
            throw invalid_argument("Invalid expression!");
        }
    }
    if(S.size() != 1) {
        throw invalid_argument("Invalid expression!");
    }
    double ans =  S.top().get_value();
    //cout<< "print: " << ans << '\n';
    return ans;
}

int main() {
    cout<< fixed << setprecision(4);
    clog<< "Reverse Polish Notation - Calculator: \n";
    clog<< "Actions: \n";
    clog<< "- print *expression* \n";
    clog<< "- set *var* to *expression* \n";
    clog<< "- clear \n";
    clog<< "- exit \n";

    while(true) {
        string action, var;
        char line[100];
        cin.getline(line, 200);
        string s = line;
        if(s.substr(0, 5) == "print") {
            try {
                cout<< calc(s.substr(6)) << '\n';
            }
            catch(const exception& e) {
                cerr << e.what() << '\n';
            }
        }
        else if(s.substr(0, 4) == "exit") {
            break;
        }
        else if(s.substr(0, 5) == "clear") {
            variable::clear();
        }
        else if(s.substr(0, 3) == "set") {
            string var = "";
            int i=0;
            for(i=4; i<s.size(); i++) {
                if(s[i] == ' ') 
                    break;
                var.push_back(s[i]);
            }
            if(s[i] != ' ' || s[i+1] != 't' || s[i+2] != 'o' || s[i+3] != ' ') {
                cerr<< "Unknown action!\n";
                continue;
            }
            i += 4;
            string ex = s.substr(i);
            double x = 0;
            try {
                x = calc(ex);
                variable a(var, x);
            }
            catch(const exception& e) {
                cerr << e.what() << '\n';
            }
        }
        else {
            cerr<< "Unknown action!\n";
        }
    }

    return 0;
}

