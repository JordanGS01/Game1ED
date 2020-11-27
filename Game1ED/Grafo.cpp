#include "Grafo.h"

Grafo::Grafo() {
	head = nullptr;
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
		return true;
	}
	else if (buscaNodo(x, y) == nullptr) {
		Nodo* newNodo = new Nodo();
		newNodo->xPos = x;
		newNodo->yPos = y;
		newNodo->sig = head;
		head = newNodo;
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
bool Grafo::insertaArista(Nodo* src, Nodo* dest, int peso) {
	if ((src == nullptr) || (dest == nullptr)) {
		return false;
	}
	else if (src->aristas == nullptr) {
		Arista* newArista = new Arista();
		newArista->src = src;
		newArista->dest = dest;
		newArista->peso = peso;

		src->aristas = newArista;
		
		insertaArista(dest, src, peso);//Because the edges have to go in both directions.
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

		insertaArista(dest, src, peso);
		return true;
	}
	return false;
}

//What this function does is create ALL the Nodo structures of the graph based on a matrix.
//For every "6" found in a (x,y) position of the matrix, it'll create a new Nodo structure.
void Grafo::inicializaNodosMatriz(int matriz[23][23]) {
	for (int y = 0; y < 23; y++) {
		for (int x = 0; x < 23; x++) {
			if (matriz[x][y] == 6) {
				insertaNodo(x,y);
			}
		}
	}
}

//The next four function iterate throuht the matrix and search for "6" that represent that there has to be a Nodo struct element.
//The idea is to look in all direction (up,down,right,left) for some adyacent node and insert a Arista struct to the sublist of edges.
//All the four methods recive a (x,y) coordinate that actuates likes an ID locating the Nodo struct in the list and the matrix with the values of the map.
bool Grafo::adyacentLeft(int x, int y, int matriz[23][23]) {
	Nodo* auxNodo = buscaNodo(x, y);
	int peso = 1;
	int xAux = x;
	for (xAux; xAux > 0; xAux--) {
		if (matriz[xAux][y] == 6) {
			return insertaArista(auxNodo, buscaNodo(xAux, y), peso);
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
			return insertaArista(auxNodo, buscaNodo(xAux, y), peso);
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
			return insertaArista(auxNodo, buscaNodo(x, yAux), peso);
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
			return insertaArista(auxNodo, buscaNodo(x, yAux), peso);			
		}
		else if (matriz[x][yAux] == 1) { return false; }

		peso++;
	}
	return false;
}

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


