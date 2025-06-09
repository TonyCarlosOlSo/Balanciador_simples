#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho máximo da pilha
#define MAX_SIZE 100

// Estrutura da Pilha
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initializeStack(Stack *s) {
    s->top = -1; // Indica que a pilha está vazia
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Função para empilhar (push) um item
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Função para desempilhar (pop) um item
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

// Função para verificar o balanceamento de parênteses, colchetes e chaves
int checkBalance(char* expression) {
    Stack stack;
    initializeStack(&stack);
    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        char currentChar = expression[i];

        // Se for um caractere de abertura, empilha
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            push(&stack, currentChar);
        } 
        // Se for um caractere de fechamento
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            // Se a pilha estiver vazia, não há correspondente de abertura
            if (isEmpty(&stack)) {
                return 0; // Desbalanceado
            }

            // Desempilha o último caractere de abertura
            char lastOpen = pop(&stack);

            // Verifica se o par corresponde
            if ((currentChar == ')' && lastOpen != '(') ||
                (currentChar == ']' && lastOpen != '[') ||
                (currentChar == '}' && lastOpen != '{')) {
                return 0; // Desbalanceado
            }
        }
        // Ignora outros caracteres que não sejam parênteses/colchetes/chaves
    }

    // Ao final, a pilha deve estar vazia para a expressão ser balanceada
    return isEmpty(&stack);
}

// Função principal
int main() {
    char expression[MAX_SIZE];
    
    printf("Digite uma expressão para verificar o balanceamento: ");
    fgets(expression, MAX_SIZE, stdin);
    
    // Remove o caractere de nova linha que fgets pode incluir
    expression[strcspn(expression, "\n")] = 0;
    
    if (checkBalance(expression)) {
        printf("A expressão está balanceada.\n");
    } else {
        printf("A expressão NÃO está balanceada.\n");
    }
    
    return 0;
}
