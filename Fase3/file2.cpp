#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
using namespace std;

int contador, z = 0;
char prims[10][100];
char next[10][100];
int l = 0;
char prod[10][10];
char f[10], prim[10];
int k;
char ck;
int e;

void siguienteprim(char, int, int);
void siguiente(char letra);
void buscarprim(char, int, int);
void buscarprim(char letra, int s1, int s2)
