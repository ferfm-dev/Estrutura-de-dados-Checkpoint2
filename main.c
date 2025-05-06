#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
INTEGRANTES:
Fernando Melo - RM 564297
Ryan Santos - RM 565102
Pedro Henrique Martins 564090
*/


void fatoriais(){
    int n, resultado;
    printf("\nDigite um número inteiro (1 a 20):");
    scanf("%i", &n);
    
    printf("\nFatoriais:\n");
    for (int i = 1; i <= n; i++) {
        printf("%i! = ", i);
        resultado = 1;
        for (int j = i; j >= 1; j--){
            resultado *= j;
        }
        printf("%i\n", resultado);
    } 
    
}

void palindromo() {
    char palavra[100];
    char aux[100];
    int index_aux = 0;
    
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);
    for (int i = tamanho - 1; i >= 0; i--) {
        aux[index_aux] = palavra[i];
        index_aux++;
    }

    aux[index_aux]  =  '\0';

    if (strcmp(palavra, aux) == 0) {
        printf("\nA palavra é um palíndromo.");
    } else {
        printf("\nA palavra NÃO é um palíndromo.");
    }
}

int sequencia_fibonacci() {
    int tamanho = 0;
    printf("\nDigite a quantidade de termos da sequência de Fibonacci (1 a 50): ");
    scanf("%i", &tamanho);
    
    
    
    if (tamanho < 1)
    tamanho = 1;
    else if (tamanho > 50)
    tamanho = 50;
    
    
    int vetor_sequencia[tamanho];
    vetor_sequencia[0] = 0;
    
    if (tamanho > 1)
    vetor_sequencia[1] = 1;
    
    
    for (int i = 2; i < tamanho; i++) {
        vetor_sequencia[i] = vetor_sequencia[i - 2] + vetor_sequencia[i - 1];
    }
    
    printf("\nSequência de Fibonacci: ");
    for (int i = 0; i < tamanho; i++) 
        printf("%i ", vetor_sequencia[i]);

    return 0;
}

void verificar_substring() {
    char palavra1[100], palavra2[100];

    printf("\nDigite a primeira palavra: ");
    scanf("%s", palavra1);

    printf("\nDigite a segunda palavra: ");
    scanf("%s", palavra2);

    int len_palavra1 = strlen(palavra1);
    int len_palavra2 = strlen(palavra2);

    int aux = 0;

    for (int i = 0; i <= len_palavra1 - len_palavra2; i++) {
        aux = 0;
        
        for (int j = 0; j < len_palavra2; j++) {
            if (palavra1[i + j] == palavra2[j]) {
                aux++;
            }
        }
        
        if (aux == len_palavra2) {
            printf("A segunda string está contida na primeira.");
            break;
        }
    }
    if (aux != len_palavra2) {
        printf("A segunda string NÃO está contida na primeira.");
    }
}

void menu() {
    int opcao = 0;
    printf("\n==== MENU DE EXERCÍCIOS ====");
    printf("\n1 - Sequência de Fibonacci");
    printf("\n2 - Fatoriais");
    printf("\n3 - Verificar Palíndromo");
    printf("\n4 - Verificar Substring");
    printf("\nDigite o número do exercício: ");

    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
        sequencia_fibonacci();
        break;
    case 2:
        fatoriais();
        break;
    case 3:
        palindromo();
        break;
    case 4:
        verificar_substring();
        break;
    
    }
}

int main() {
    setlocale(LC_ALL, "");

    menu();
    return 0;
}

