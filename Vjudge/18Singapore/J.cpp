#include <bits/stdc++.h>

using namespace std;

long long H(long long previousHash, string &transaction) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return v * 7 % 1000000007;
}

long long HH(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

long long FUCK = 1e7;

int main() {
    long long v, h1, h2, t1, t2;
    string a = "a", b = "b";
    cin >> v;
    h1 = H(v, a);
    t1 = FUCK - h1 % FUCK;
    h1 += t1;
    cout << a << " " << t1 << endl;
    //cout << HH(v, a, t1) << endl;
    h2 = H(h1, b);
    t2 = FUCK - h2 % FUCK;
    h2 += t2;
    cout << b << " " << t2 << endl;
    //cout << HH(HH(v, a, t1), b, t2);

}