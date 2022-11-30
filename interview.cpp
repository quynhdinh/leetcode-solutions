#include <bits/stdc++.h>
using namespace std;

string getFromMap(map<string, string> mp, string s){
    if(mp.find(s) != mp.end()){
        return mp[s];
    } else {
        return '{' + s + '}';
    }
}
string formatString(string input, map<string, string> dict) {
    const int N = (int)input.size();
    int i = 0;
    string answer = "";
    for (; i < N; i++) {
        if (input[i] == '{') {
            string s = "";
            int j = i;
            while (j < N && input[j] != '}') {
                s += input[j];
                j++;
            }
            if(input[j] == '}'){
                answer += getFromMap(dict, s.erase(0, 1));
            } else {
                answer += s;
            }
            i = j;
        } else {
            answer += input[i];
        }
    }
    return answer;
}
int main() {
    string input = "Hi {me}, welcome to {company}!";
    string input2 = "Hi {me}, welcome to {company!";
    string input3 = "Hi {me}, welcome to company}!";
    string input4 = "Hi {him}, welcome to {company}!";
    map<string, string> mapping({{"me", "Luan"}, {"company", "PrimeData"}});
    cout<<formatString(input, mapping)<<'\n';
    cout<<formatString(input2, mapping)<<'\n';
    cout<<formatString(input3, mapping)<<'\n';
    cout<<formatString(input4, mapping)<<'\n';
}