#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

void array_generator(char arr[], int len) {
    char list_a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char list_n[] = "0123456789";
    char list_s[] = "!\"#$%&'()*+,-./:;<=>?@[]^_`{|}~";
    int r, i;
    r = rand()%strlen(list_a);
    arr[0] = list_a[r];
    r = rand()%strlen(list_n);
    arr[1] = list_n[r];
    r = rand()%strlen(list_s);
    arr[2] = list_s[r];
    for(int j=3; j<len; j++) {
        i = rand()%3;
        switch(i) {
            case 0:
            { r = rand()%strlen(list_a);
                arr[j] = list_a[r];
                break;
            }
            case 1:
            { r = rand()%strlen(list_n);
                arr[j] = list_n[r];
                break;
            }
            case 2:
            { r = rand()%strlen(list_s);
                arr[j] = list_s[r];
                break;
            }
            default: {}
        }
    }
    for(int j=0; j<len; j++) {
        i = rand()%len;
        char temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    srand(time(NULL));
    int n;
    cout << "Inserisci dimensione password: ";
    cin >> n;
    char arr[n];
    array_generator(arr, n);
    cout << endl << endl << "Password di " << n << " caratteri: ";
    for(int i=0; i<n; i++) {
        cout << arr[i];
    }
    cout << endl << endl;
    return 0;
}
