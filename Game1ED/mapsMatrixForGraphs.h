#pragma once
#ifndef MAPSMATRIXFORGRAPHS_H
#define MAPSMATRIXFORGRAPHS_H

//Lv1 map with graphs
int grafoMlvl1[23][23] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
	{ 1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },
	{ 1,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1 },
	{ 1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

//Lvl2 map with graphs
int grafoMlvl2[23][23] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1 },
	{ 1,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1 },
	{ 1,0,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1 },
	{ 1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1 },
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
int grafoMlvl3[23][23] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
	{ 1,0,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1 },
	{ 1,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1 },
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