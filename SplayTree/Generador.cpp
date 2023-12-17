#include "SplayTree.h"
#include <time.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

void generar();
void opInsert();
void opFind();
void opErase();
void InsertaElems(int valor);
void InsertaElem(int valor);
void BuscaElem(int valor);
void BorraElems(int valor);
void BorraElem(int valor);

int main() {

	generar();

	return 0;
}

void generar() {
	int op;
	do {
		cout << "Escoge la operacion que quieres probar:\n";
		cout << "\n 1: Operaciones de insertado";
		cout << "\n 2: Operaciones de busqueda";
		cout << "\n 3: Operaciones de borrado";
		cout << "\n 0: Salir";

		cout << "\n\nOperacion: ";
		
		cin >> op;

		switch (op) {
		case 1:
			opInsert();
			break;
		case 2:
			opFind();
			break;
		case 3:
			opErase();
			break;
		default:
			cout << "\nOperacion no valida";
			break;
		}
		
	} while (op != 0);

	cout << "\n\nEjecucion terminada\n";
}

void opInsert() {

	int op;
	do {
		cout << "Escoge la operacion que quieres probar:\n";
		cout << "\n 1: Insertar 100 elementos";
		cout << "\n 2: Insertar 1000 elementos";
		cout << "\n 3: Insertar 10000 elementos";
		cout << "\n 4: Insertar 100000 elementos";
		cout << "\n 5: Insertar 1 elemento en un arbol de 100 elementos";
		cout << "\n 6: Insertar 1 elemento en un arbol de 1000 elementos";
		cout << "\n 7: Insertar 1 elemento en un arbol de 10000 elementos";
		cout << "\n 8: Insertar 1 elemento en un arbol de 100000 elementos";
		cout << "\n 0: Salir";

		cout << "\n\nOperacion: ";

		cin >> op;

		switch (op) {
		case 1:
			InsertaElems(100);
			break;
		case 2:
			InsertaElems(1000);
			break;
		case 3:
			InsertaElems(10000);
			break;
		case 4:
			InsertaElems(100000);
			break;
		case 5:
			InsertaElem(100);
			break;
		case 6:
			InsertaElem(1000);
			break;
		case 7:
			InsertaElem(10000);
			break;
		case 8:
			InsertaElem(100000);
			break;
		default:
			break;
		}
	} while (op != 0);

}

void opFind(){
	int op;
	do {
		cout << "Escoge la operacion que quieres probar:\n";
		cout << "\n 1: Buscar un elemento aleatorio en un arbol de 100 elementos";
		cout << "\n 2: Buscar un elemento aleatorio en un arbol de 1000 elementos";
		cout << "\n 3: Buscar un elemento aleatorio en un arbol de 10000 elementos";
		cout << "\n 4: Buscar un elemento aleatorio en un arbol de 100000 elementos";
		cout << "\n 0: Salir";

		cout << "\n\nOperacion: ";

		cin >> op;

		switch (op) {
		case 1:
			BuscaElem(100);
			break;
		case 2:
			BuscaElem(1000);
			break;
		case 3:
			BuscaElem(10000);
			break;
		case 4:
			BuscaElem(100000);
			break;
		default:
			break;
		}
	} while (op != 0);
}

void opErase(){
	
	int op;
	do {
		cout << "Escoge la operacion que quieres probar:\n";
		cout << "\n 1: Borrar los 100 elementos de un arbol";
		cout << "\n 2: Borrar los 1000 elementos de un arbol";
		cout << "\n 3: Borrar los 10000 elementos de un arbol";
		cout << "\n 4: Borrar los 100000 elementos de un arbol";
		cout << "\n 5: Borrar 1 elemento en un arbol de 100 elementos";
		cout << "\n 6: Borrar 1 elemento en un arbol de 1000 elementos";
		cout << "\n 7: Borrar 1 elemento en un arbol de 10000 elementos";
		cout << "\n 8: Borrar 1 elemento en un arbol de 100000 elementos";
		cout << "\n 0: Salir";

		cout << "\n\nOperacion: ";

		cin >> op;

		switch (op) {
		case 1:
			BorraElems(100);
			break;
		case 2:
			BorraElems(1000);
			break;
		case 3:
			BorraElems(10000);
			break;
		case 4:
			BorraElems(100000);
			break;
		case 5:
			BorraElem(100);
			break;
		case 6:
			BorraElem(1000);
			break;
		case 7:
			BorraElem(10000);
			break;
		case 8:
			BorraElem(100000);
			break;
		default:
			break;
		}
	} while (op != 0);

}

void BorraElem(int valor){
	SplayTree<int> st;
	for(int i = 0; i < valor-1;i++){
		st.insert(i);
	}
	clock_t ini,fin;
	double time = 0;
	
	
	for(int i = 0; i < 10000;i++){
		st.insert(valor);
		ini = clock();
		st.erase(valor);
		fin = clock();	
		time += (((double)(fin - ini)) / CLOCKS_PER_SEC);
	}
	
	time /= 100000;

	cout << "La media de 10000 ejecuciones ha sido de " << time << " segundos" << endl;
	system("pause");
}

void BorraElems(int valor){
	SplayTree<int> st;

	clock_t ini,fin;
	double time = 0;

	for (int i = 0; i < 100; i++) {
		set<int> s;
		int num;
		for (int j = 0; j < valor; j++) {
			num = rand() % 10000000;
			st.insert(num);
			s.insert(num);
		}

		ini = clock();
		for (auto it : s) {
			st.erase(it);
		}
		fin = clock();
		time += (((double)(fin - ini)) / CLOCKS_PER_SEC);
	}

	time /= 100;
	cout << "La media de 100 ejecuciones ha sido de " << time << " segundos" << endl;
	system("pause");
}

void BuscaElem(int valor){

	SplayTree<int> st;
	int num;
	for(int i = 0; i < valor;i++){
		num = rand() % 10000000;
		st.insert(num);
	}

	clock_t ini,fin;
	ini = clock();

	for(int i = 0; i < 100000;i++){
		num = rand() % 10000000;
		st.find(num);
	}
	fin = clock();

	double time = (((double)(fin - ini)) / CLOCKS_PER_SEC); 

	time /= 100000;

	cout << "La media de 100000 busquedas ha sido de " << time << " segundos" << endl;
	system("pause");
}

void InsertaElems(int valor) {
	int num;
	vector<int> v(valor);
	SplayTree<int> st;
	for (int i = 0; i < valor; i++)
		v[i] = rand() % (valor*10000);

	clock_t ini,fin;
	double time = 0;
	
	for (int j = 0; j < 100; j++) {
		SplayTree<int> st;
		for (int i = 0; i < valor; i++) {
			ini = clock();
			st.insert(v[i]);
			fin = clock();
			time += (((double)(fin - ini)) / CLOCKS_PER_SEC) ;
		}
	}

	time /= 100;

	cout << "La media de 100 ejecuciones ha sido de " << time << " segundos " << endl;
	system("pause");
}

void InsertaElem(int valor) {
	
	int num;
	SplayTree<int> st;
	for (int i = 0; i < valor; i++) {
		num = rand() % 100000;
		st.insert(num);
	}

	clock_t ini,fin;
	double time = 0;
	
	ini = clock();
	for (int j = 0; j < 100000; j++) {
		num = rand() % 100000;
		st.insert(num);
	}
	fin = clock();
	time += (((double)(fin - ini)) / CLOCKS_PER_SEC);
	time /= 100000;

	cout << "La media de 100000 ejecuciones ha sido de " << time << " segundos " << endl;
	system("pause");

}