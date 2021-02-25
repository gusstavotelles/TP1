#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int prim;
    int n;
    int index;
} Call;

void imprime(int n, int *a)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void particaoInteiros(int n, int *a)
{
    int prim, i, ult = 0, index = 0, numParts = 0;
    Call *pilha = (Call *)malloc(sizeof(Call) * 1000);
    pilha[0].prim = -1;
    pilha[0].n = n;
    pilha[0].index = index;
    while (ult >= 0)
    {
        prim = pilha[ult].prim;
        n = pilha[ult].n;
        index = pilha[ult].index;
        if (n >= 1)
        {
            if (prim == -1)
            {
                a[index] = n;
                imprime(index, a);
                numParts++;
                prim = (index == 0) ? 1 : a[index - 1];
                i = prim;
            }
            else
            {
                i = prim;
                i++;
            }
            if (i <= n / 2)
            {
                a[index] = i;
                pilha[ult].prim = i;
                ult++;
                pilha[ult].prim = -1;
                pilha[ult].n = n - i;
                pilha[ult].index = index + 1;
            }
            else
            {
                ult--;
            }
        }
        else
        {
            ult--;
        }
    }
    printf("%d", numParts);
}

int main()
{
    int N = 1, *vetor = (int *)malloc(sizeof(int) * N), i;
    printf("\nDigite um inteiro positivo: ");
    scanf("%d", &N);
    printf("\nResultado %d: \n", N);
    particaoInteiros(N, vetor);
    return (0);
}