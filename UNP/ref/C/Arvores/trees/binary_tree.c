#include <stdio.h>
#include <stdlib.h>
// #include "pilha-lista.h"

typedef struct arvore
{
    int num;
    struct arvore *esquerda;
    struct arvore *direita;
} Arvore;

Arvore *createArvore()
{
    return NULL;
}

int ArvoreIsEmpty(Arvore *t)
{
    return t == NULL;
}

void showArvore(Arvore *t)
{
    printf("<");
    if (!ArvoreIsEmpty(t))
    {
        printf("%d ", t->num);
        showArvore(t->direita);
        showArvore(t->esquerda);
    }
    printf(">");
}

void insertArvore(Arvore **t, int num)
{
    if (*t == NULL)
    {
        *t = (Arvore *)malloc(sizeof(Arvore));
        (*t)->direita = NULL;
        (*t)->esquerda = NULL;
        (*t)->num = num;
    }
    else
    {
        if (num < (*t)->num)
            insertArvore(&(*t)->direita, num);
        if (num > (*t)->num)
            insertArvore(&(*t)->esquerda, num);
    }
}

int isInArvore(Arvore *t, int num)
{
    if (ArvoreIsEmpty(t))
        return 0;
    return t->num == num || isInArvore(t->direita, num) || isInArvore(t->esquerda, num);
}

int contarNos(Arvore *a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + contarNos(a->esquerda) + contarNos(a->direita);
}

int Verificar_Ordem(Arvore *a)
{
    int vetor_ordenacao[contarNos(a)], i = 0;
    if (a != NULL)
    {
        Verificar_Ordem(a->esquerda);
        vetor_ordenacao[i] = a->num;
        i++;
        Verificar_Ordem(a->direita);
    }
    for (i = 0; i <= (contarNos(a)); i++)
    {
        if (vetor_ordenacao[i] <= vetor_ordenacao[i + 1])
            continue;
        else
            return 1;
    }
    return 0;
}

void pre_ordem(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }
    printf("%d ", tree->num);
    pre_ordem(tree->esquerda);
    pre_ordem(tree->direita);
}

void pos_ordem(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }

    pos_ordem(tree->esquerda);
    pos_ordem(tree->direita);
    printf("%d ", tree->num);
}

void em_ordem(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }
    em_ordem(tree->esquerda);
    printf("%d ", tree->num);
    em_ordem(tree->direita);
}

void em_nivel(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }
    Stack *stack = createStack(10); // Ajuste o tamanho da pilha conforme necessário.
    push(stack, tree);

    while (!isEmpty(stack))
    {
        Arvore *current = pop(stack);
        printf("%d ", current->num);

        if (current->esquerda != NULL)
        {
            push(stack, current->esquerda);
        }
        if (current->direita != NULL)
        {
            push(stack, current->direita);
        }
    }

    // Libere a memória alocada para a pilha.
    free(stack->array);
    free(stack);
}

typedef struct Stack
{
    int top;
    int capacity;
    Arvore **array;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Node **)malloc(stack->capacity * sizeof(Arvore *));
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, Node *item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
}

Arvore *pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return NULL;
    }
    return stack->array[stack->top--];
}

int main()
{
    Arvore *t = createArvore();
    insertArvore(&t, 5);
    insertArvore(&t, 3);
    insertArvore(&t, 2);
    insertArvore(&t, 4);
    insertArvore(&t, 7);
    insertArvore(&t, 6);
    insertArvore(&t, 8);
    showArvore(t);
    printf("\nExibindo a árvore em ordem\n==================\n");
    em_ordem(t);
    printf("\nExibindo a árvore em Pos-ordem\n==================\n");
    pos_ordem(t);
    printf("\nExibindo a árvore em Pre-ordem\n==================\n");
    pre_ordem(t);
    printf("\nExibindo a árvore em Nivel\n==================\n");
    em_nivel(t);
    printf("\n");
    if (isInArvore(t, 4))
        printf("4 pertence a arvore\n");
    else
        printf("4 nao pertence a arvore\n");
    if (isInArvore(t, 1))
        printf("1 pertence a arvore\n");
    else
        printf("1 nao pertence a arvore\n");

    return 1;
}