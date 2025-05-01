#include <stdio.h>
#include <locale.h>
#include <string.h>

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
    case 4:
        verificar_substring();
        break;
    default:
        break;
    }
}

int main() {
    setlocale(LC_ALL, "");

    menu();
    return 0;
}