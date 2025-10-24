#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Seme {
	const char* nome;
};

struct Carta {
	int valore;
	Seme seme;
};

Seme quadri = {"Quadri"};
Seme cuori = {"Cuori"};
Seme fiori = {"Fiori"};
Seme picche = {"Picche"};
	
int main() {
    srand(time(NULL));
    Carta carte[100];
    int i=0;
    char string[10];
    int sum = 0;
    bool perso = false;

    cout << "Benvenuto. Ecco la tua carta: " << endl;

    do {
        int random_type = rand()%4+1;
        int random_value = rand()%13+1;
        switch (random_type) {
            case 1:
            carte[i].seme.nome = quadri.nome; break;
            case 2:
            carte[i].seme.nome = cuori.nome; break;
            case 3:
            carte[i].seme.nome = fiori.nome; break;
            case 4:
            carte[i].seme.nome = picche.nome; break;
        }
        carte[i].valore = random_value;
        if(random_value > 10) {
            carte[i].valore = 10;
        }
        int valore_asso;
        if(random_value == 1) {
            if(sum+11 > 21) {
                carte[i].valore = 1;
                cout << "L'asso può solo valere 1." << endl;
            } else {
                do {
                    cout << "L'asso può valere 1 o 11.\nQuanto lo fai valere?" << endl;
                    cin >> valore_asso;
                } while (valore_asso == 1 || valore_asso == 11);
            }
            if(valore_asso == 1) {
                carte[i].valore = 1;
            } else {
                carte[i].valore = 11;
            }
        }
        sum += carte[i].valore;
        cout << carte[i].seme.nome << " " << carte[i].valore << endl;
        if(sum < 21) {
            cout << "Ora puoi chiedere un'altra carta o finire il gioco.\nSe vuoi una carta scrivi si, altrimenti scrivi no.\nNon devi superare i 21 punti o perderai." << endl;
            cin >> string;
        } else {
            cout << "Hai perso!\nHai preso " << sum << " punti." << endl;
            perso = true;
            break;
        }
        i++;
    } while (strcmp(string, "no") != 0);
    
    if (!perso) {
        bool valore_asso = false;
        int sum_computer = 0;
        Carta carte_computer[2];
        for(int i=0; i<2; i++) {
            int random_type = rand()%4+1;
            int random_value = rand()%13+1;
            switch (random_type) {
                case 1:
                carte_computer[i].seme.nome = quadri.nome; break;
                case 2:
                carte_computer[i].seme.nome = cuori.nome; break;
                case 3:
                carte_computer[i].seme.nome = fiori.nome; break;
                case 4:
                carte_computer[i].seme.nome = picche.nome; break;
            }
            carte_computer[i].valore = random_value;
            if(random_value > 10) {
                carte_computer[i].valore = 10;
            }
            
            cout << endl << endl << "Ora gioca il pc" << endl << endl;
            
            valore_asso = rand()%2;
            if(valore_asso) {
                carte_computer[i].valore = 11;
            } else {
                carte_computer[i].valore = 1;
            }
            sum_computer += carte[i].valore;
            cout << carte_computer[i].seme.nome << " " << carte_computer[i].valore << endl;
        }
        
        if(sum_computer > 21) {
            cout << "Ho perso. Hai vinto tu." << endl;
        } else {
            if(sum_computer > sum) {
                cout << "Ho vinto." << endl;
            } else {
                cout << "Hai vinto." << endl;
            }
        }
    }
    
    return 0;
}