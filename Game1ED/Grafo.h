#pragma once
#ifndef GRAFO_H
#define GRAFO_H

struct Arista;

struct Nodo{
	int xPos;
	int yPos;

	Arista* aristas;

	Nodo* sig;
};

struct Arista {
	int peso;

	Nodo* src;
	Nodo* dest;

	Arista* sig;
	Arista* ant;
};

class Grafo {
public:
	Nodo* head;

	//Constructor
	Grafo();

	//Vertex insertion
	Nodo* buscaNodo(int x, int y);
	bool insertaNodo(int x, int y);

	//Edges insertion
	Arista* buscaArista(Nodo* src, Nodo* dest);
	bool insertaArista(Nodo* src, Nodo* dest, int peso);

	//Creation of the Graph using a matrix
	void inicializaNodosMatriz(int matriz[23][23]);
	bool adyacentUp(int x, int y, int matriz[23][23]);
	bool adyacentLeft(int x, int y, int matriz[23][23]);
	bool adyacentRight(int x, int y, int matriz[23][23]);
	bool adyacentDown(int x, int y, int matriz[23][23]);
	void inicializaAristasMatriz(int matriz[23][23]);
};

#endif