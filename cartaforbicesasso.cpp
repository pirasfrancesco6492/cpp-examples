#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

void genera(char bot_string[]) {
    int value;
    value = rand()%3;
    if (value == 0) {
        strcpy(bot_string, "sasso");
    } else if (value == 1) {
        strcpy(bot_string, "carta");
    } else {
        strcpy(bot_string, "forbice");
    }
}

int verifica(char bot_string[], char user_string[]) {
    if (strcmp(bot_string, user_string) == 0) {
        return 2;
    } else {
        if (strcmp(bot_string, "sasso") == 0) {
            return strcmp(user_string, "carta") == 0;
        } else if (strcmp(bot_string, "carta") == 0) {
            return strcmp(user_string, "forbice") == 0;
        } else {
            return strcmp(user_string, "sasso") == 0;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char user_string[8];
    char bot_string[8];
    int punti_user = 0;
    int punti_bot = 0;
    int val;
    
    cout << "Benvenuto al gioco di carta, forbice, sasso. Digita stop per terminare la partita." << endl;
    
    do {
        do {
            cout << "Sasso, carta o forbice? ";
            cin >> user_string;
        } while ((strcmp(user_string, "sasso") != 0 && strcmp(user_string, "carta") != 0 && strcmp(user_string, "forbice") != 0) && strcmp(user_string, "stop") != 0);
        
        if (strcmp(user_string, "stop") != 0) {
        genera(bot_string);
        cout << "Il bot ha scelto: " << bot_string << endl;
        val = verifica(bot_string, user_string);
            if (val == 1) {
                cout << "Hai vinto!" << endl;
                punti_user++;
            } else if (val == 0) {
                cout << "Hai perso!" << endl;
                punti_bot++;
            } else {
                cout << "Pareggio!" << endl;
                punti_bot++;
                punti_user++;
            }
            }
    } while (strcmp(user_string, "stop") != 0);
    cout<< "Punteggio finale: " << endl << "Bot: " << punti_bot << endl << "Tu: " << punti_user << endl << (punti_user > punti_bot ? "Hai vinto" : punti_bot > punti_user ? "Hai perso" : "Pareggio") << endl;
    return 0;
}