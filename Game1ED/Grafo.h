#pragma once
#ifndef GRAFO_H
#define GRAFO_H

struct Arista;

struct NodoCola {
	NodoCola* ant;
	NodoCola* sig;
	Arista* ptr;
};

struct Nodo{
	int xPos;
	int yPos;

	Arista* aristas;

	Nodo* sig;

	bool visitado;
	int index;
};

struct Arista {
	int peso;

	Nodo* src;
	Nodo* dest;

	Arista* sig;
	Arista* ant;

	bool revisada;
};

struct ColaAristas {
	NodoCola* inicio;
	NodoCola* fin;

	bool colaVacia() { return (inicio == nullptr) ? true : false; }//Retorna true si la cola esta vacia, en caso contrario retorna false.

	void push(Arista* arista) {//Inserta al final de la cola.
		NodoCola* auxNC = new NodoCola();
		auxNC->ptr = arista;
		if (colaVacia()) {
			inicio = auxNC;
		}
		else {
			fin->sig = auxNC;
		}
		fin = auxNC;
	}

	Arista* pop() {//Saca el primer elemento de la cola
		Arista* auxNodo = inicio->ptr;
		NodoCola* auxInicio = inicio;

		if (inicio == fin) {
			inicio = nullptr;
			fin = nullptr;
		}
		else {
			inicio = inicio->sig;
		}
		delete auxInicio;
		return auxNodo;
	}

	void vaciarCola() {
		while (inicio != nullptr) {
			NodoCola* auxInicio = inicio;
			inicio = inicio->sig;
			delete auxInicio;
		}
	}
};


class Grafo {
public:
	Nodo* head;
	ColaAristas* CPA = new ColaAristas();
	int cantNodos = 0;
	//Constructor
	Grafo();

	//Unmark functions.
	void desmarca();
	void desmarcaAristas();

	//Vertex insertion
	Nodo* buscaNodo(int x, int y);
	bool insertaNodo(int x, int y);

	//Edges insertion
	Arista* buscaArista(Nodo* src, Nodo* dest);
	bool insertaArista(Nodo* src, Nodo* dest, int peso, bool doble);

	//Creation of the Graph using a matrix
	void inicializaNodosMatriz(int matriz[23][23]);
	bool adyacentUp(int x, int y, int matriz[23][23]);
	bool adyacentLeft(int x, int y, int matriz[23][23]);
	bool adyacentRight(int x, int y, int matriz[23][23]);
	bool adyacentDown(int x, int y, int matriz[23][23]);
	void inicializaAristasMatriz(int matriz[23][23]);

	//DIJKSTRA
	Arista** Dijkstra(Nodo* src, Nodo* dest);
};

#endif