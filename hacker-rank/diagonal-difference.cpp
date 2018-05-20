#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> a) {
    int i=0,sum_1=0,sum_2=0;
    int n=a.size();
    for(i=0;i<n;i++) {
        sum_1+=a[i][i];
        sum_2+=a[i][n-1-i];
    }
    return abs(sum_1-sum_2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    fout << result << "\n";

    fout.close();

    return 0;
}
