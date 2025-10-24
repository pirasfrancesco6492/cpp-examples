/* Calcolo del fattoriale con metodo iterativo e ricorsivo */

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n<1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

/* int factorial(int n, int i) {
    if (i == 0) {
        return n;
    } else {
        return factorial(n*i, i-1);
    }
} */

int main() {
    int n;
    cout << "Inserire numero: ";
    cin >> n;

    /*int val = n;

    for(int i=1; i<val; i++) {
        n = n*i;
    }
    cout << "Fattoriale: " << n << endl;*/

    cout << "Fattoriale: " << factorial(n) << endl;

    return 0;
}
