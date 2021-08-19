using namespace std;

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <sdkddkver.h>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <string>

void inserimentoFrase(), dividiFrase(string frase, char divisore, string* destinazione);

const int dim = 1000;
int logic_dim;
ifstream dizionario("dizionario.txt");
string fraseInserita;
string fraseInseritaArr[dim];

int main()
{
	inserimentoFrase();
	cout << "\n" << fraseInserita.length() << "\n";

	dividiFrase(fraseInserita, ' ', fraseInseritaArr);
	system("PAUSE");

	/*
	while (!dizionario.eof()) {
		string linea;
		dizionario >> linea;
		cout << linea << "\n";
	}
	cout << "\n";
	dizionario.close();
	return 0;
	*/
}

void inserimentoFrase() {
	cout << "Inserire la frase da ricercare\n";
	cout << "\n>> ";
	getline(cin, fraseInserita);
	cout << fraseInserita;
	return;
}

void dividiFrase(string frase, char divisore, string destinazione[]) {
	//Funzione che mi permette di trasformare una frase in un array, dividendo le parole in base ad un divisore dato
	int lunghezza = frase.length();
	string parola;
	int pos = 0;
	for (int i = 0; i < lunghezza; i++) {
		char carattere = frase[i];
		if (carattere == divisore) {
			destinazione[pos] = parola;
			pos++;
			parola.clear();
		}
		else parola += carattere;
	}
	destinazione[pos] = parola;
}
