#pragma once
#ifndef MAPSMATRIXFORGRAPHS_H
#define MAPSMATRIXFORGRAPHS_H

//Lv1 map with graphs
int mlvl1[23][23] = {//Lista, ya tiene todos los 6 que representan grafos colocados.
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,6,0,6,0,0,0,0,6,1,6,1,1,6,1,6,1,6,1,6,0,6,1 },
	{ 1,6,0,6,1,1,1,1,0,1,6,6,0,6,0,6,0,6,1,0,1,0,1 },
	{ 1,1,6,6,0,0,0,0,6,6,6,6,1,0,1,1,1,0,1,6,0,6,1 },
	{ 1,6,6,6,1,1,1,1,1,0,1,0,1,0,1,6,0,6,0,0,1,0,1 },
	{ 1,0,1,6,0,0,0,0,0,6,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,6,0,0,0,6,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,6,0,0,1,1,1,0,1,0,1,0,1,6,0,6,1,0,1,0,1 },
	{ 1,0,1,0,1,6,0,0,0,6,1,0,1,0,1,0,1,6,0,6,1,0,1 },
	{ 1,0,1,0,1,6,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },
	{ 1,0,1,0,1,1,1,0,0,0,0,6,1,6,0,6,1,6,1,0,1,0,1 },
	{ 1,0,1,6,0,6,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,6,1,0,1,0,1,0,1,6,0,6,1,0,1,0,1 },
	{ 1,6,0,6,0,6,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,6,0,6,1,0,1 },
	{ 1,6,6,1,6,6,0,6,0,6,0,6,0,6,0,6,0,6,1,0,1,0,1 },
	{ 1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,6,6,6,1 },
	{ 1,1,0,1,0,1,6,1,6,1,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,1,0,1,0,1,6,0,6,6,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,6,6,6,1 },
	{ 1,6,6,0,6,0,0,0,0,6,0,6,1,6,0,6,0,6,1,6,1,6,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

//Lvl2 map with graphs
int mlvl2[23][23] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,3,0,0,1,0,1,1,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,3,1,0,1 },
	{ 1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1 },
	{ 1,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1 },
	{ 1,0,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1 },
	{ 1,0,1,1,1,1,1,0,0,3,0,0,1,0,0,0,1,1,1,0,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1 },
	{ 1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1 },
	{ 1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1 },
	{ 1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1 },
	{ 1,1,0,1,0,1,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,1 },
	{ 1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,0,1,0,0,1,1 },
	{ 1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,1 },
	{ 1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1 },
	{ 1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

//Lvl3 map with graphs
int mlvl3[23][23] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,3,0,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,3,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
	{ 1,0,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1 },
	{ 1,0,1,0,1,1,1,0,0,3,0,0,1,0,0,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,1 },
	{ 1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1 },
	{ 1,1,0,1,1,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1 },
	{ 1,1,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};
#endif