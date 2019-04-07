#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Listas e aux.h"

int main(void)
{
	char c;
	int val;
	Lista* lista = lst_cria();

	for (int i = 99; i >= 0; i--)
		lista = lst_insere(lista, i);

	printf("Checando a existencia de conteudos na lista... ");
	loading();
	if (lst_vazia(lista))
	{
		printf("\nLista vazia. O programa sera encerrado.\n\n");
		exit(1);
	}

	printf("\nSucesso! Carregando lista... ");
	loading();

	deseja(lista, 'b');

	printf("\nOs elementos da lista s%co:\n\n%c", 132, 7);
	lst_imprime10x10(lista);

		printf("\nDeseja inserir algum elemento? ");
		scanf(" %c", &c);
		if (c == 's' || c == 'S')
		{
			// case 's':
			printf("Qual? ");
			scanf("%d", &val);
			lista = lst_insere(lista, val);
			printf("\nOs elementos da nova lista s%co:\n\n%c", 132, 7);
			lst_imprime10x10(lista);
		}
	deseja(lista, 'r');

	printf("\n");
	lst_libera(lista);
	
	return 0;
}