#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    if(s[8]=='P'&&(s.substr(0,2).compare("12")!=0)){
        s[0]+=1;
        s[1]+=2;
    }
    else if(s[8]=='A'&&(s.substr(0,2).compare("12")==0)) {
        s[0]='0';
        s[1]='0';
    }
    return s.substr(0,s.length()-2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
