class Solution {
    using ll = long long;
    ll lcm(ll n1, ll n2){
        return n1 * n2 / gcd(n1, n2);
    }
    ll gcd(ll n1, ll n2){
        if(n2 == 0) return n1;
        return gcd(n2, n1 % n2);
    }
    struct Fraction{
        bool sign = true;
        int numerator = 0;
        int denominator = 0;
    };
    vector<Fraction> convert(string& expression){
        vector<Fraction> fractions;
        for(int i = 0, n =expression.size(); i<n;){
            fractions.push_back({});
            auto& [sign, nume, deno] = fractions.back();
            if(expression[i] == '-' || expression[i] == '+'){
                sign = expression[i] == '+';
                ++i;
            }
            while(i<n && expression[i] != '/'){
                nume *= 10;
                nume += expression[i] - '0';
                ++i;
            }
            ++i;
            while(i<n && expression[i] >= '0' && expression[i] <= '9'){
                deno *= 10;
                deno += expression[i] - '0';
                ++i;
            }
        }
        return fractions;
    }
public:
    string fractionAddition(string expression) {
        vector<Fraction> fractions = convert(expression);
        ll totLcm = 1;
        for(auto& [a, b, deno] : fractions){
            totLcm = lcm(totLcm, deno);
        }
        ll totNume = 0;
        for(auto& [sign, nume, deno] : fractions){
            totNume += (sign?1:-1) * (totLcm / deno * nume);
        }
        if(totNume == 0) return "0/1";
        ll _gcd = gcd(totNume<0?-totNume:totNume, totLcm);
        return to_string(totNume/_gcd) + "/" + to_string(totLcm/_gcd);
    }
};