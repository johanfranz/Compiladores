#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
using namespace std;

int cont, n = 0;
char calc_primero[10][100];
char calc_siguiente[10][100];
int m = 0;
char produccion[10][10];
char f[10], primero[10];
int k;
char ck;
int e;

void siguientePrimero(char, int, int);
void siguiente(char c);
void buscarPrimero(char, int, int);
void buscarPrimero(char c, int q1, int q2)
{
	int j;
	if(!(isupper(c))) {
		primero[n++] = c;
	}
	for(j = 0; j < cont; j++)
	{
		if(produccion[j][0] == c)
		{
			if(produccion[j][2] == '#')
			{
				if(produccion[q1][q2] == '\0')
					primero[n++] = '#';
				else if(produccion[q1][q2] != '\0'
						&& (q1 != 0 || q2 != 0))
				{
		
					buscarPrimero(produccion[q1][q2], q1, (q2+1));
				}
				else
					primero[n++] = '#';
			}
			else if(!isupper(produccion[j][2]))
			{
				primero[n++] = produccion[j][2];
			}
			else
			{
				buscarPrimero(produccion[j][2], j, 3);
			}
		}
	}
}

void siguientePrimero(char c, int c1, int c2)
{
	int k;
	if(!(isupper(c)))
		f[m++] = c;
	else
	{
		int i = 0, j = 1;
		for(i = 0; i < cont; i++)
		{
			if(calc_primero[i][0] == c)
				break;
		}
		
		while(calc_primero[i][j] != '!')
		{
			if(calc_primero[i][j] != '#')
			{
				f[m++] = calc_primero[i][j];
			}
			else
			{
				if(produccion[c1][c2] == '\0')
				{
					siguiente(produccion[c1][0]);
				}
				else
				{
					siguientePrimero(produccion[c1][c2], c1, c2+1);
				}
			}
			j++;
		}
	}
}


void siguiente(char c)
{
	int i, j;
	if(produccion[0][0] == c) {
		f[m++] = '$';
	}
	for(i = 0; i < 10; i++)
	{
		for(j = 2;j < 10; j++)
		{
			if(produccion[i][j] == c)
			{
				if(produccion[i][j+1] != '\0')
				{
					siguientePrimero(produccion[i][j+1], i, (j+2));
				}
				
				if(produccion[i][j+1]=='\0' && c!=produccion[i][0])
				{
					siguiente(produccion[i][0]);
				}
			}
		}
	}
}


int main(int argc, char **argv)
{
	int jm = 0;
	int km = 0;
	int i, opcion;
	char c, ch;
	cont = 8;
	strcpy(produccion[0], "E=TA");
	strcpy(produccion[1], "A=+T");
	strcpy(produccion[2], "A=#");
	strcpy(produccion[3], "T=FB");
	strcpy(produccion[4], "B=*FB");	
	strcpy(produccion[5], "B=#");	
	strcpy(produccion[6], "F=(E)");	
	strcpy(produccion[7], "F=n");	
	int kay;
	char done[cont];
	int ptr = -1;
	

	for(k = 0; k < cont; k++) {
		for(kay = 0; kay < 100; kay++) {
			calc_primero[k][kay] = '!';
		}
	}
	int point1 = 0, point2, auxx;
	cout<<"PRIMEROS"<<endl;
	for(k = 0; k < cont; k++)
	{
		c = produccion[k][0];
		point2 = 0;
		auxx = 0;
		
		for(kay = 0; kay <= ptr; kay++)
			if(c == done[kay])
				auxx = 1;
				
		if (auxx == 1)
			continue;
		
		buscarPrimero(c, 0, 0);
		ptr += 1;
		
		done[ptr] = c;
		cout<<endl;
		cout<<c<<" = {";
		calc_primero[point1][point2++] = c;
		
		for(i = 0 + jm; i < n; i++) {
			int lark = 0, chk = 0;
			
			for(lark = 0; lark < point2; lark++) {
				
				if (primero[i] == calc_primero[point1][lark])
				{
					chk = 1;
					break;
				}
			}
			if(chk == 0)
			{
				printf("%c, ", primero[i]);
				calc_primero[point1][point2++] = primero[i];
			}
		}
		cout<<"}"<<endl;
		jm = n;
		point1++;
	}
	cout<<endl;
	cout<<"______________________________________________"<<endl<<endl;

	char donee[cont];
	ptr = -1;
	
	for(k = 0; k < cont; k++) {
		for(kay = 0; kay < 100; kay++) {
			calc_siguiente[k][kay] = '!';
		}
	}
	point1 = 0;
	int land = 0;
	cout<<"SIGUIENTES"<<endl;
	for(e = 0; e < cont; e++)
	{
		ck = produccion[e][0];
		point2 = 0;
		auxx = 0;
		
		for(kay = 0; kay <= ptr; kay++)
			if(ck == donee[kay])
				auxx = 1;
				
		if (auxx == 1)
			continue;
		land += 1;
		
		siguiente(ck);
		ptr += 1;
		
		donee[ptr] = ck;
		cout<<ck<<" = {";
		calc_siguiente[point1][point2++] = ck;
		
		for(i = 0 + km; i < m; i++) {
			int lark = 0, chk = 0;
			for(lark = 0; lark < point2; lark++)
			{
				if (f[i] == calc_siguiente[point1][lark])
				{
					chk = 1;
					break;
				}
			}
			if(chk == 0)
			{
				printf("%c, ", f[i]);
				calc_siguiente[point1][point2++] = f[i];
			}
		}
		cout<<"}"<<endl<<endl;
		km = m;
		point1++;
	}
}

