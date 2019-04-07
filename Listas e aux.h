#include <Windows.h>

struct lista
{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria(void)
{
	return NULL;
}
Lista* lst_insere(Lista* lst, int valor)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = lst;

	return novo;
}
Lista* lst_busca(Lista* lst, int val)
{
	for (Lista* p = lst; p != NULL; p = p->prox)
	{
		if (p->info == val)
			return p;
	}
	return NULL;
}
Lista* lst_retira(Lista* lst, int val)
{
	Lista* ant = NULL;
	Lista* p = lst;

	while (p != NULL && p->info != val)
	{
		ant = p;
		p = p->prox;
	}

	if (p == NULL)
		return lst;
	if (ant == NULL)
		lst = p->prox;
	else
		ant->prox = p->prox;

	free(p);
	return lst;
}
void lst_imprime10x10(Lista* lst)
{
	int i = 0;
	for (Lista* p = lst; p != NULL; p = p->prox)
	{
		printf("%.2d ", p->info);
		i++;
		if (i % 10 == 0)
			printf("\n");
	}
}
int lst_vazia(Lista* lst)
{
	return (lst == NULL);
}
void lst_libera(Lista* lst)
{
	Lista* p = lst;
	while (p != NULL)
	{
		Lista* t = p->prox;
		free(p);
		p = t;
	}
}

void loading()
{
	for (int i = 0; i < 10; i++)
	{
		printf("\\%c", 8);
		Sleep(100);
		printf("/%c", 8);
		Sleep(100);
		printf("-%c", 8);
		Sleep(100);
	}
	printf("%c", 32);
}
void deseja(Lista* lst, char op)
{
	char c;
	int val;
	switch (op)
	{
	case 'b':
		printf("\n\nDeseja buscar algum elemento? ");
		scanf(" %c", &c);
			if (c == 's' || c == 'S')
			{
				// case 's':
				printf("Qual? ");
				scanf("%d", &val);
				if (lst_busca(lst, val))
					printf("O valor digitado encontra-se presente na lista.\n");
				else
					printf("O valor digitado nao encontra-se presente na lista.\n");
			}
	break;
	/*case 'i':
			printf("\nDeseja inserir algum elemento? ");
			scanf(" %c", &c);
			if (c == 's' || c == 'S')
			{
				// case 's':
				printf("Qual? ");
				scanf("%d", &val);
				lst = lst_insere(lst, val);
				printf("\nOs elementos da nova lista s%co:\n\n%c", 132, 7);
				lst_imprime10x10(lst);
			}
	break;*/
	case 'r':
			printf("\n\nDeseja remover algum elemento? ");
			scanf(" %c", &c);
			if (c == 's' || c == 'S')
			{
				// case 's':
				printf("Qual? ");
				scanf("%d", &val);
				lst = lst_retira(lst, val);
				printf("\nOs elementos da nova lista s%co:\n\n%c", 132, 7);
				lst_imprime10x10(lst);
			}
	break;
	}
}
