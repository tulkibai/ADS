#include <iostream>
using namespace std;

int gcd (int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        if (b >= a) b = b % a;
    }
    return a + b;
}

int main () {
    int a, b;
    cin >> a >> b;

    gcd (a, b);
}