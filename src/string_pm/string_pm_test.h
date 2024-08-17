/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "_share/util.h"

#define printString(s) { for (size_t m = strlen(s), k = 0; k < m; k++) printf("%4c", (s)[k]); }

void showProgress ( char*, char*, int, int ); //珆尨呾楊輛最
void printNext ( int*, int, int ); //湖荂Next桶
int* buildNext ( char* ); //凳婖Next桶
void printBC ( int* ); //湖荂BC桶
int* buildBC ( char* ); //凳婖BC桶
void printGS ( char*, int* ); //湖荂GS桶
int* buildGS ( char* ); //凳婖GS桶