#include <bits/stdc++.h>
using namespace std;
int isKPalindrome(string X, int m, string Y, int n)
{
	if (m == 0 || n == 0)
		return n + m;
	if (X[m - 1] == Y[n - 1])
		return isKPalindrome(X, m - 1, Y, n - 1);
	int x = isKPalindrome(X, m - 1, Y, n);
	int y = isKPalindrome(X, m, Y, n - 1);
	return 1 + min(x, y);
}
int main()
{
	string str = "CABCBC";
	int K = 2;
	string rev = str;
	reverse(rev.begin(), rev.end());
	if (isKPalindrome(str, str.length(), rev, str.length()) <= 2 * K)
		cout << "String is K-Palindrome";
	else
		cout << "String is not a K-Palindrome";
	return 0;
}