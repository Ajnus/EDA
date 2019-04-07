#include <Windows.h>

struct lista
{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;
struct lista2
{
	int info;
	struct lista2* ant;
	struct lista2* prox;
};
typedef struct lista2 Lista2;

/* parte 1 */
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

/* parte 2 */
Lista* lst_insere_ordenado(Lista* lst, int val)		// insere ordenado: insere elemento em ordem
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));	// aloca e inicializa
	novo->info = val;

	Lista* ant = NULL;								// ponteiro para anterior							
	Lista* p = lst;									// ponteiro para percorrer lista
	/* procura posição para inserção */
	while (p != NULL && p->info < val)
	{
		ant = p;
		p = p->prox;
	}
	/* encadear */
	if (ant == NULL)								// insere no início
	{
		novo->prox = lst;
		lst = novo;
	}
	else											// insere no meio ou fim
	{
		novo->prox = ant->prox;						// || novo->prox = p;
		ant->prox = novo;
	}

	return lst;										// reetorna lista ordenada com elemento inseridow
}
Lista* lst_retira_rec(Lista* lst, int val)
{
	if(!lst_vazia(lst))
	{
		if (lst->info == val)				// verifica se o elemento a ser retirado é o 1º
		{
			Lista* t = lst;
			lst = lst->prox;
			free(t);
		}
		else
			lst->prox = lst_retira_rec(lst->prox, val);
	}
	return lst;
}
int lst_igual(Lista* lst01, Lista* lst02)
{
	Lista* p1;
	Lista* p2;

	for (p1 = lst01, p2 = lst02; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox)
		if (p1->info != p2->info)
			return 0;

	return (p1 == p2);
}
int lst_igual_rec(Lista* lst01, Lista* lst02)
{
	if (lst01 == NULL && lst02 == NULL)			// trata se vazias e se chegam ao final ao mesmo tempo
		return 1;
	else if (lst01 == NULL || lst02 == NULL)
		return 0;
	else
		return (lst01->info == lst02->info) && (lst_igual_rec(lst01->prox, lst02->prox));
}
void lcirc_imprime(Lista* lst)
{
	Lista*p = lst;						// ponteiro para lista
	
	if (p)								// se lista não for vazia
		do
		{
			printf("%d", p->info);
			p = p->prox;
		} while (p != lst);				// enquanto não apontar para o início da lista
	else
		printf("A lista fornecida esta vazia.\n");
}
Lista2* lst2_insere(Lista2* lst, int val)
{
	Lista2* novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = val;
	novo->prox = lst;
	novo->ant = NULL;

	if (lst != NULL)			// se lista não vazia
		lst->ant = novo;

	return novo;
}
Lista2* lst2_busca(Lista2* lst, int val)
{
	Lista2* p;
	for (p = lst; p != NULL; p = p->prox)
		if (p->info == val)
			return p;
	return NULL;					// não achou
}
Lista2* lst2_retira(Lista2* lst, int val)
{
	Lista2* p = lst2_busca(lst, val);		//  busca elemento

	if (p != NULL)							// se não achou, retorna lista inalterada
		return lst;
	/* achou, retira o elemento */
	if (lst == p)							// se for o 1o elemento
		lst = p->prox;
	else
		p->ant->prox = p->prox;				// costura pra frente

	if (p->prox != NULL)					// se NÃO for o último elemento
		p->prox->ant = p->ant;				// costura pra trás [se for o 1o elemento p->ant = NULL, correto. não costura com lst]

	free(p);								// remove elemento
	return lst;								// retorna lista atualizada
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
				lst = lst_retira_rec(lst, val);
				printf("\nOs elementos da nova lista s%co:\n\n%c", 132, 7);
				lst_imprime10x10(lst);
			}
	break;
	}
}
