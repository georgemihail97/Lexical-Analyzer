// Proiect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]) 
{
	char cuv_ch[37][10] = { "auto","break","case","cout","cin","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","include","int","long","main","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","endl" };
	int i, ok = 0;

	for (i = 0; i < 37; ++i) 
	{
		if (strcmp(cuv_ch[i], buffer) == 0) 
		{
			ok = 1;
			break;
		}
	}

	return ok;
}
static const char const sp[] = {'[',']','{','}','(',')',',',';','"'};
int main() 
{
	char ch, buffer[15], operatori[] = "+-*/%=", variabile[20][15] = { "" };
	ifstream f("program.txt");
	int i, j = 0;
	if (!f.is_open()) 
	{
		cout << "Eroare in deschiderea fisierului.\n";
		exit(0);
	}
	char cod[32656];
	while (!f.eof())
	{
		ch = f.get();
		cod[j++] = ch;
	}
	f.close();
	cod[j] = '\0';
	j = 0;
	char mesaj[32656];
	int ok = 0, h = 0, z, x = 0, y = 0, ii = 0, hh,este =1;
	for (z = 0; z < strlen(cod); z++)
	{
		if (cod[z] == '"')
		{	
			while (cod[++z] != '"')
				mesaj[h++] = cod[z];
			mesaj[h] = '\0';
			cout << mesaj << " este mesaj.\n";
			h = 0;
		}
			for (i = 0; i < 6; ++i)
			{
				if (cod[z] == operatori[i])
				{
					cout << cod[z] << " este operator.\n";
				}

			}

			if ((isalnum(cod[z])!=0)&&(cod[z]!='<')&&(cod[z]!='>'))
			{
				buffer[j++] = cod[z];
			}
			else
			{
				for (hh = 0; hh < 9; hh++)
				{
					if (cod[z] == sp[hh])
						cout << cod[z] << " este delimitator.\n";
				}
				if ((cod[z] == ' ' || cod[z] == '\n' || cod[z] == '<' || cod[z] == '>') && (j != 0))
				{
					buffer[j] = '\0';
					j = 0;
					if ((cod[z] == '<' || cod[z] == '>') && (cod[z + 1] == '<' || cod[z + 1] == '>'))
					{
						cout << cod[z] << cod[z + 1] << " este operator.\n";
					}
					if (isKeyword(buffer) == 1)
					{
						cout << buffer << " este cuvant cheie.\n";
					v:	if ((strcmp(buffer, "int") == 0) ||
						(strcmp(buffer, "const") == 0) ||
						(strcmp(buffer, "double") == 0) ||
						(strcmp(buffer, "float") == 0) ||
						(strcmp(buffer, "long") == 0) ||
						(strcmp(buffer, "short") == 0) ||
						(strcmp(buffer, "signed") == 0) ||
						(strcmp(buffer, "unsigned") == 0))
						{
						if (cod[z] == ' ')
							{
								z++;
								while (isalnum(cod[z]))
								{
									variabile[x][y++] = cod[z];
									z++;
								}
								if (cod[z] == ',')
								{
									variabile[x][y] = '\0';
									x++;
									goto v;
								}
								if (cod[z] == ';')
								{
								break;
								}
							}
						}
					}
					else
						ex:for (ii = 0; ii < x; ii++)
						if (strcmp(buffer, variabile[ii]) == 0)
							cout << buffer << " este identificator.\n";
						else
							if ((strcmp(buffer, "cout") == 0) || (strcmp(buffer, "cin") == 0) || (strcmp(buffer, "void") == 0)|| (strcmp(buffer, "endl") == 0))
							{
								;
							}
							else
							{
								for (int hh = 0; hh <= j; hh++)
									if (isalpha(buffer[hh])!=0)
									{
										este = 0;
										break;
									}
									else
										este = 1;
								if (este)
									if (isdigit(buffer[hh]))
										cout << buffer << " este constanta.\n";
									else
										cout << buffer << " este identificator.\n";
								else
								{
									for (int hh = 0; hh <= j; hh++)
									{
										int lit = 0, num = 0;
										if (isalpha(buffer[hh]) != 0)
										{
											cout << buffer[hh];
											lit = 1;
										}
										if (lit)
											cout << " este identificator.\n";
										if (isdigit(buffer[hh]) != 0)
										{
											cout << buffer[hh];
											num = 1;
										}
										if (num)
											cout << " este constanta.\n";
									}
								}
							}
									
				}
			}
				
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
