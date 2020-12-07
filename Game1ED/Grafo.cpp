#include "Grafo.h"

#include <iostream>
using namespace std;
Grafo::Grafo() {
	head = nullptr;
}

void Grafo::eliminaMemoriaGrafo() {
	Nodo* auxNodo = head;
	if (auxNodo != nullptr) {
		while (auxNodo != nullptr) {
			Arista* auxArista = auxNodo->aristas;
			while (auxArista != nullptr) {
				if (auxArista->sig != nullptr) {
					Arista* elArista = auxArista;
					auxArista = auxArista->sig;
					delete(elArista);
				}
				else {
					delete(auxArista);
					break;
				}
			}
			if (auxNodo->sig != nullptr) {
				Nodo* elNodo = auxNodo;
				auxNodo = auxNodo->sig;
				delete(elNodo);
			}
			else {
				delete(auxNodo);
				break;
			}
		}
	}
}

//Unmark every Node in the graph.
void Grafo::desmarca() {
	Nodo* auxNodo = head;
	while (auxNodo != nullptr) {
		auxNodo->visitado = false;

		auxNodo = auxNodo->sig;
	}
	return;
}

//Unmark every Edge of the graph.
void Grafo::desmarcaAristas() {
	Nodo* auxNodo = head;
	while (auxNodo != nullptr) {
		Arista* auxArista = auxNodo->aristas;
		while (auxArista != nullptr) {
			auxArista->revisada = false;
			auxArista = auxArista->sig;
		}
		auxNodo = auxNodo->sig;
	}
	return;
}

//Search a Nodo struct in the main list.Recives a (x,y) coordinate positions.
//Return the Nodo struct if it's find or nullptr if it doesn't.
Nodo* Grafo::buscaNodo(int x, int y) {
	Nodo* auxNodo = head;
	while (auxNodo != nullptr) {
		if ((auxNodo->xPos == x) && (auxNodo->yPos == y)) {
			return auxNodo;
		}
		auxNodo = auxNodo->sig;
	}
	return nullptr;
}

//Recives a (x,y) coordinate positions and insert a Nodo struct in the list.
//Returns true if the insertion was sucesfully done and false if it don't.
bool Grafo::insertaNodo(int x, int y) {
	if (head == nullptr) {
		Nodo* newNodo = new Nodo();
		newNodo->xPos = x;
		newNodo->yPos = y;

		head = newNodo;
		cantNodos++;
		return true;
	}
	else if (buscaNodo(x, y) == nullptr) {
		Nodo* newNodo = new Nodo();
		newNodo->xPos = x;
		newNodo->yPos = y;
		newNodo->sig = head;

		head = newNodo;
		cantNodos++;
		return true;
	}
	return false;
}

//Recives two Nodo structs and see if there is a conection between the first one given and the second one.
//Returns the Arista struct if there's a conection or nullptr if there's not
Arista* Grafo::buscaArista(Nodo* src, Nodo* dest) {

	Arista* auxArista = src->aristas;
	while (auxArista != nullptr) {
		if (auxArista->dest == dest) {
			return auxArista;
		}
		auxArista = auxArista->sig;
	}
	return nullptr;
}

//Inserts a Arista struct to the sublist of a Nodo struct.
//Recives the source and destine Nodo structs and the "int" distance that exists between both structs.
//Returns true if the insertion was sucesfully done and false if it don't.
bool Grafo::insertaArista(Nodo* src, Nodo* dest, int peso, bool doble,char direction) {
	if ((src == nullptr) || (dest == nullptr)) {
		return false;
	}
	else if (src->aristas == nullptr) {
		Arista* newArista = new Arista();
		newArista->src = src;
		newArista->dest = dest;
		newArista->peso = peso;

		src->aristas = newArista;

		char neightbourDir;
		if (direction == 'U') { newArista->up = true; neightbourDir = 'D'; }
		else if (direction == 'D') { newArista->down = true; neightbourDir = 'U'; }
		else if (direction == 'L') { newArista->left = true; neightbourDir = 'R';}
		else { newArista->right = true; neightbourDir = 'L';}

		if (doble == true) {
			insertaArista(dest, src, peso, false, neightbourDir);//Because the edges have to go in both directions.
		}
		return true;
	}
	else if (buscaArista(src, dest) == nullptr) {
		Arista* newArista = new Arista();
		newArista->src = src;
		newArista->dest = dest;
		newArista->peso = peso;

		newArista->sig = src->aristas;
		src->aristas->ant = newArista;
		src->aristas = newArista;

		char neightbourDir;
		if (direction == 'U') { newArista->up = true; neightbourDir = 'D'; }
		else if (direction == 'D') { newArista->down = true; neightbourDir = 'U'; }
		else if (direction == 'L') { newArista->left = true; neightbourDir = 'R'; }
		else { newArista->right = true; neightbourDir = 'L'; }

		if (doble == true) {
			insertaArista(dest, src, peso, false, neightbourDir);//Because the edges have to go in both directions.
		}

		return true;
	}
	return false;
}

//What this function does is create ALL the Nodo structures of the graph based on a matrix.
//For every "6" found in a (x,y) position of the matrix, it'll create a new Nodo structure.
void Grafo::inicializaNodosMatriz(int matriz[23][23]) {
	for (int x = 0; x < 23; x++) {		
		for (int y = 0; y < 23; y++) {  
			if (matriz[x][y] == 6) {
				insertaNodo(x,y);
			}
		}
	}
}
//>>>>>>>AUXILIAR<<<<<<<
/*void Grafo::inicializaNodosMatriz(int matriz[23][23]) {
	eliminaMemoriaGrafo();
	for (int x = 0; x < 23; x++) {
		for (int y = 0; y < 23; y++) {
			if (matriz[x][y] == 0) {
				insertaNodo(x, y);
			}
		}
	}
}*/

//The next four function iterate throuht the matrix and search for "6" that represent that there has to be a Nodo struct element.
//The idea is to look in all direction (up,down,right,left) for some adyacent node and insert a Arista struct to the sublist of edges.
//All the four methods recive a (x,y) coordinate that actuates likes an ID locating the Nodo struct in the list and the matrix with the values of the map.
bool Grafo::adyacentLeft(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	int peso = 1;
	int xAux = x;
	for (xAux; xAux > 0; xAux--) {
		if (matriz[xAux][y] == 6) {
			return insertaArista(auxNodo, buscaNodo(xAux, y), peso, true,'L');
		}
		else if (matriz[xAux][y] == 1) { return false; }

		peso++;
	}
	return false;
}

bool Grafo::adyacentRight(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	int peso = 1;
	int xAux = x;
	for (xAux; xAux < 22; xAux++) {//22 because there'll be ALWAYS a 1 at the last position of the matrix
		if (matriz[xAux][y] == 6) {
			return insertaArista(auxNodo, buscaNodo(xAux, y), peso, true,'R');
		}
		else if (matriz[xAux][y] == 1) { return false; }

		peso++;
	}
	return false;
}

bool Grafo::adyacentDown(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	int peso = 1;
	int yAux = y;
	for (yAux; yAux < 22; yAux++) {
		if (matriz[x][yAux] == 6) {
			return insertaArista(auxNodo, buscaNodo(x, yAux), peso, true,'D');
		}
		else if (matriz[x][yAux] == 1) { return false; }

		peso++;
	}
	return false;
}

bool Grafo::adyacentUp(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	int peso = 1;
	int yAux = y;
	for (yAux; yAux > 0; yAux--) {
		if (matriz[x][yAux] == 6) {
			return insertaArista(auxNodo, buscaNodo(x, yAux), peso, true,'U');
		}
		else if (matriz[x][yAux] == 1) { return false; }

		peso++;
	}
	return false;
}

/*
bool Grafo::adyacentLeft(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	if ((x > 0) && ((matriz[x - 1] == 0))) {
		return insertaArista(auxNodo, buscaNodo(x-1, y), 1, true, 'L');
	}
	return false;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>AUXILIARES<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool Grafo::adyacentRight(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	if ((x < 22) && ((matriz[x + 1] == 0))) {
		return insertaArista(auxNodo, buscaNodo(x+1, y), 1, true, 'R');
	}
	return false;
}

bool Grafo::adyacentDown(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	if ((y < 22) && ((matriz[y + 1] == 0))) {
		return insertaArista(auxNodo, buscaNodo(x, y+1), 1, true, 'D');
	}
	return false;
}

bool Grafo::adyacentUp(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	if ((y > 0) && ((matriz[y - 1] == 0))) {
		return insertaArista(auxNodo, buscaNodo(x, y - 1), 1, true, 'U');
	}
	return false;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
//Inserts all the edges to the Nodo sturctures in the main list.
//Recives a matrix with the values of the map used to created the graph.
void Grafo::inicializaAristasMatriz(int matriz[23][23]) {
	Nodo* auxNodo = head;
	if (head != nullptr) {
		while (auxNodo != nullptr) {
			adyacentLeft(auxNodo->xPos, auxNodo->yPos, matriz);
			adyacentRight(auxNodo->xPos, auxNodo->yPos, matriz);
			adyacentDown(auxNodo->xPos, auxNodo->yPos, matriz);
			adyacentUp(auxNodo->xPos, auxNodo->yPos, matriz);

			auxNodo = auxNodo->sig;
		}
	}
}

//Short ways
char Grafo::Dijkstra(Nodo* inicio, Nodo* fin) {//HACE FALTA DEVOLVER EL ARREGLO CON LOS VERTICES QUE FORMAN EL CAMINO
	desmarca();
	desmarcaAristas();
	CPA->vaciarCola();

	int pesos[442];
	Nodo* vertices[442] = { nullptr };
	Nodo* ruta[442] = { nullptr };

	vertices[0] = inicio;
	ruta[0] = inicio;
	pesos[0] = 0;
	inicio->index = 0;
	inicio->visitado = true;

	Arista* arista = inicio->aristas;
	while (arista != nullptr) {
		CPA->push(arista);
		arista = arista->sig;
	}

	while (!CPA->colaVacia()) {
		arista = CPA->pop();
		arista->revisada = true;
		if (arista->dest->visitado == false) {
			for (int i = 0; i < cantNodos; i++) {
				if (vertices[i] == nullptr) {
					vertices[i] = arista->dest;
					ruta[i] = arista->src;
					pesos[i] = pesos[arista->src->index] + arista->peso;
					arista->dest->index = i;
					arista->dest->visitado = true;
					break;
				}
			}
		}

		else if (arista->dest->visitado == true) {
			if (pesos[arista->dest->index] > pesos[arista->src->index] + arista->peso) {
				pesos[arista->dest->index] = pesos[arista->src->index] + arista->peso;
				ruta[arista->dest->index] = arista->src;
			}
		}

		Arista* auxArista = arista->dest->aristas;
		if (auxArista != nullptr) {
			while (auxArista != nullptr) {
				if (auxArista->revisada == false) {
					CPA->push(auxArista);
				}
				auxArista = auxArista->sig;
			}
		}
	}

	for (int i = 0; i < cantNodos; i++) {
		if (ruta[i] == inicio) {
			Nodo* auxNodo = vertices[i];
			
			cout << "Ruta:  " << endl;
			cout << "X= " << ruta[i]->xPos << "Y=" << ruta[i]->yPos << endl;

			cout << "Vertice:  " << endl;
			cout << "X= " << vertices[i]->xPos << "Y=" << vertices[i]->yPos << endl;
			system("pause");

			Arista* auxArista = ruta[i]->aristas;//The edges of the the src position
			while (auxArista != nullptr) {
				if (auxArista->dest == auxNodo) {
					if (auxArista->up == true) {
						return 'U';
					}
					else if (auxArista->down == true) {
						return 'D';
					}
					else if (auxArista->left == true) {
						return 'L';
					}
					else {
						return 'R';
					}
				}
			}
		}
	}
}
