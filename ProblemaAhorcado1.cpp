#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Existe (string Palabra, char Letra) {
    for (int k = 0; k < Palabra.size(); k++) {
        if (Palabra[k]== Letra) {
            cout << "Existe la letra" << Letra << endl;
            return true;
        } 
    }
    return false;
}

vector <int> PosicionLetra (string Palabra, char Letra) {
    vector <int> Posicion;
    for (int k = 0; k < Palabra.size(); k++) {
        if (Palabra[k]== Letra) {
            cout << "Existe la letra" << endl;
            Posicion.push_back(k);
        } 
    }
    return Posicion;
}

void Ejemplo(string Palabra) {
    for (int k=0; k < Palabra.size(); k++) {
        cout << Palabra[k] << endl;
    } 

}

void MostrarProgreso(string Palabra, vector <bool> Estado) {
for (int i=0; i < Palabra.size(); i++) {
        if (Estado[i]) {
            cout << Palabra[i];
        } else {
            cout << '_';
        }
    }
    cout << endl;
}

void MostrarProgreso(string Palabra, vector <bool> Estado, char Vacio) {
for (int i=0; i < Palabra.size(); i++) {
        if (Estado[i]) {
            cout << Palabra[i];
        } else {
            cout << Vacio;
        }
    }
    cout << endl;
}

void Pantalla(int Turno, vector<char> hist) {

    cout << "Ahorcado" << endl;
    cout << "Numero de turno: " << Turno << endl;
    
    for (char &c: hist) {
        cout << c;
    }
    cout << endl;
}

int main () {
    string Palabra;
    char Letra;
    int Turnos=1;

    vector<char> Historial;

     do {

        Pantalla(Turnos, Historial);

    cout << "Dame una palabra" << endl;
    cin >> Palabra;

    cout << "Dame una letra" << endl;
    cin >> Letra;

    Turnos++;
        Historial.push_back(Letra);

    } while (Letra != 'n');


    vector<bool> Mostrar (Palabra.size());

    Mostrar[2] = true;
    MostrarProgreso(Palabra, Mostrar, '_');

    int count=0;

    for (int j=0; j < Mostrar.size(); j++) {
        Mostrar [j]=true;

    }

    if (Existe (Palabra, Letra) == true) {
        cout << "La letra '" << Letra << "' SI esta en la palabra" << endl;
    } else {
        cout << "La letra '" << Letra << "' NO esta en la palabra" << endl;
    }

    vector<int> Posicion = PosicionLetra (Palabra, Letra);

    for (int &P : Posicion) {
        cout << "La letra '" << Letra << "' esta en la posicion: " << P << endl;

    }

    MostrarProgreso(Palabra, Mostrar, '_');  

    for (int k=0; k < Mostrar.size(); k++) {
        if (Mostrar[k]==true) {
            count++;
        }
    }

    if (count==Mostrar.size()) {
        cout << "Se descubrieron todas las letras" << endl;
    } else {
        cout << "Perdiste" << endl;
    }

    cout << "Numero de caracteres: " << count << endl;

    return 0;
    
}