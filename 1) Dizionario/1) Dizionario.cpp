using namespace std;

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <sdkddkver.h>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <time.h>
#pragma execution_character_set( "utf-8" )

void inserimentoFrase(), dividiFrase(string frase, char divisore, string destinazione[]), controlloVeloce(), controlloLento();
bool isAnagramma(string parola1, string parola2);

const int dim = 1000;
ifstream dizionario("dizionario.txt");
string fraseInserita;
string fraseInseritaArr[dim];

int main()
{
	SetConsoleOutputCP(65001);	//Imposto il char_set per mostrare i caratteri UTF-8
	inserimentoFrase();
	dividiFrase(fraseInserita, ' ', fraseInseritaArr);
	cout << "\n";
	bool finito = false;
	while (!finito) {
		system("CLS");
		cout << "Frase inserita: " << fraseInserita << "\n\n";

		cout << "Scegliere l'algoritmo da utilizzare\n\n";
		cout << "1) molti cicli dizionario, 1 ciclo parole (lento ca. 3 sec a parola)\n";
		cout << "2) 1 ciclo dizionario, molti cicli parole (veloce)\n";
		cout << "-1) Exit\n";
		cout << "\n\n>> ";
		string scelta;
		cin >> scelta;
		int numeroInt;
		try
		{
			numeroInt = stoi(scelta);
			switch (numeroInt)
			{
			case 1:
				controlloLento();
				break;
			case 2:
				controlloVeloce();
				break;
			case -1:
				finito = true;
				break;
			default:
				system("CLS");
				break;
			}
		}
		catch (const std::exception& exc)
		{

		}
	}
	return 0;
}

void controlloVeloce() {
	//Per ogni parola della frase inserita eseguo il confronto con ogni elemento all'interno del dizionario
	//Scorro solamente 1 volta il dizionario ma molte volte le parole inserite
	clock_t start = clock();
	int pos = 0, nAnagrammi = 0;
	string parola = fraseInseritaArr[pos];
	while (!dizionario.eof()) {
		string linea;
		dizionario >> linea;
		while (parola != "") {
			if (isAnagramma(parola, linea)) cout << "Anagramma n. " << nAnagrammi++ << " : Parola inserita -> " << parola << " Parola dizionario -> " << linea << "\n";
			pos++;
			parola = fraseInseritaArr[pos];
		}
		pos = 0;
		parola = fraseInseritaArr[pos];
	}
	clock_t end = clock();
	dizionario.clear();
	dizionario.seekg(0);	//Reimposto la posizione nel file dizionario
	cout << "\nTempo di esecuzione = secondi " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
	cout << "\n";
	system("PAUSE");
}

void controlloLento() {
	int pos = 0, nAnagrammi = 0;
	string parola = fraseInseritaArr[pos];;
	//Per ogni parola della frase inserita eseguo il confronto con ogni elemento all'interno del dizionario
	clock_t start = clock();
	while (parola != "") {
		dizionario.clear();
		dizionario.seekg(0);	//Reimposto la posizione nel file dizionario
		cout << "Parola analizzata: " << parola << "\n";
		while (!dizionario.eof()) {
			string linea;
			dizionario >> linea;
			if (isAnagramma(parola, linea)) cout << "Anagramma n. " << nAnagrammi++ << " : " << linea << "\n";
		}
		pos++;
		parola = fraseInseritaArr[pos];
	}
	clock_t end = clock();
	dizionario.clear();
	dizionario.seekg(0);	//Reimposto la posizione nel file dizionario
	cout << "\nTempo di esecuzione = secondi " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
	cout << "\n";
	system("PAUSE");
}

void inserimentoFrase() {
	cout << "Inserire la frase da ricercare\n";
	cout << "\n>> ";
	getline(cin, fraseInserita);
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

bool isAnagramma(string parola1, string parola2) {
	if (parola1.length() != parola2.length()) return false;
	int dim = parola1.length();
	const int dimArr = 255;
	int nCaratteri[dimArr] = { 0 }; //Inizializzo il vettore a 0
	//Riempio un vettore nelle posizioni dei caratteri, ovvero mi salvo quali e quanti caratteri ascii extended sono presenti, e sottraggo quelli di parola2.
	//Se al termine avrò un vettore le quali celle sono tutte 0 le due parole sono anagrammi
	for (int i = 0; i < dim; i++) {
		nCaratteri[parola1[i]]++;
		nCaratteri[parola2[i]]--;
	}
	//Controllo zeri
	for (int i = 0; i < dimArr; i++) {
		if (nCaratteri[i] != 0) return false;
	}
	return true;
}