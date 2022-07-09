#include <iostream>
int main()
{

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'

    int a = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo

    int *b = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)

    int v[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)

    std::cout << &a << std::endl;

    // 5) Imprima o VALOR da variável declarada em (1)

    std::cout << a << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)

    std::cout << &b << std::endl;

    // 7) Imprima o VALOR da variável declarada em (2)

    std::cout << b << std::endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)

    std::cout << &v << std::endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)

    std::cout << &v[0] << std::endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)

    std::cout << v[0] << std::endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)

    b = &a;

    // 12) Imprima o VALOR da variável declarada em (2)

    std::cout << b << std::endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << *b << std::endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)

    if (&a == b)
        std::cout << "1" << std::endl;
    else
        std::cout << "0" << std::endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)

    *b = 5;

    // 16) Imprima o VALOR da variável declarada em (1)

    std::cout << a << std::endl;

    // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)

    b = &v[0];

    // 18) Imprima o VALOR da variável declarada em (2)

    std::cout << b << std::endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << *b << std::endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)

    b = &v[0];

    // 21) Imprima o VALOR da variável declarada em (2)

    std::cout << b << std::endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << *b << std::endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)

    for (int i = 9; i >= 0; i--)
        b[i] = i * 10;

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)

    for (int i = 9; i >= 0; i--)
    {
        std::cout << v[i];
        if (v[i] != 0)
            std::cout << " ";
        else
            std::cout << std::endl;
    }

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento

    int i = 10;
    do
    {
        std::cout << v[i - 1];
        if (v[i - 1] == 0)
            std::cout << std::endl;
        else
            std::cout << " ";
        i--;
    } while (i != 0);

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento

    int x = 10;
    do
    {
        std::cout << b[x - 1];
        if (b[x - 1] == 0)
            std::cout << std::endl;
        else
            std::cout << " ";
        x--;
    } while (x != 0);

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)

    b = &v[5];

    // 28) Imprima o VALOR da variável declarada em (2)

    std::cout << b << std::endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << *b << std::endl;

    // 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4

    std::cout << *b + (4 * 10) << std::endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)

    int **d = &b;

    // 32) Imprima o VALOR da variável declarada em (31)

    std::cout << d << std::endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)

    std::cout << &d << std::endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)

    std::cout << *&d << std::endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)

    std::cout << **d << std::endl;

    return 0;
}