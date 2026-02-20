#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string x, string y) {
    int m = x.length();
    int n = y.length();

    if (m == 0 || n == 0) {
        return "invalid input";
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs += x[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string x, y;
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registration Number: 24BCE2198"<<endl;
    cout << "Enter first string: ";
    getline(cin, x);

    cout << "Enter second string: ";
    getline(cin, y);

    cout << "LCS: " << LCS(x, y);

    return 0;
}
