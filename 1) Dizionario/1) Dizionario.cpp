using namespace std;

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <sdkddkver.h>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <string>

void inserimentoFrase();

const int dim = 1000;
int logic_dim;
ifstream dizionario("dizionario.txt");
string fraseInserita;
string fraseInseritaArr[dim];

int main()
{
	inserimentoFrase();


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


//while (!MyFile.eof()) {