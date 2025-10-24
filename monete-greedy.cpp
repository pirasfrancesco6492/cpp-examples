/* In questo algoritmo si utilizza la tecnica algoritmica Greedy 
nell'esempio del gioco delle monete.
Dato in input un certo valore in denaro, l'algoritmo restituisce l'ottimo
globale attraverso una serie di calcoli degli ottimi locali
Complessità logaritmica. */

#include <iostream>
using namespace std;

int local(int values[], int len, int import) {
    int left = 0, right = len - 1;
    int best = -1; // per gestione UB 
    while (left <= right) {
        int mid = left + (right - left) / 2; // per gestione integer overflow
        if (values[mid] <= import) {
            best = values[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return best;
}

void control(int diff, int values[]) {
    while(diff>0) {
        int value = local(values, 9, diff);
        cout << value << endl;
        diff -= value;
    }
}

int main() {
    int import;
    int values[] = {1,2,5,10,20,50,100,200,500};
    cout << "Inserire importo: ";
    cin >> import;
    control(import, values);
    return 0;
}