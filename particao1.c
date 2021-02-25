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
    int prim;
    int i;
    int ult = 0;
    int index = 0;
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
}

int main()
{
    int N = 1;
    int *a = (int *)malloc(sizeof(int) * N);
    int i;
    printf("\nDigite um numero X para que seja mostrada uma particao de 1 a X: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        printf("\nA particao de inteiros para %d é: \n", i);
        particaoInteiros(i, a);
    }
    return (0);
}