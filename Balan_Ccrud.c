#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define FILE_NAME "resultados.txt"

// Estrutura da Pilha
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initializeStack(Stack *s) {
    s->top = -1;
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
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (isEmpty(&stack)) return 0;

            char lastOpen = pop(&stack);

            if ((currentChar == ')' && lastOpen != '(') ||
                (currentChar == ']' && lastOpen != '[') ||
                (currentChar == '}' && lastOpen != '{')) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

// === FUNÇÕES DO CRUD ===

// Listar todas as entradas do arquivo
void listAll() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Nenhuma expressão cadastrada ainda.\n");
        return;
    }

    char line[256];
    printf("\n=== Histórico de Expressões ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Adicionar nova expressão
void addExpression() {
    char expression[MAX_SIZE];
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite uma expressão para verificar: ");
    scanf(" %[^\n]", expression); // Lê até newline

    int result = checkBalance(expression);
    printf("Resultado: %s\n", result ? "Balanceada" : "Desbalanceada");

    fprintf(file, "Expressão: \"%s\" -> %s\n",
            expression, result ? "Balanceada" : "Desbalanceada");
    fclose(file);
    printf("Expressão adicionada com sucesso!\n");
}

// Editar uma linha específica
void editLine() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Nenhuma expressão encontrada.\n");
        return;
    }

    char lines[100][256];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), file)) {
        printf("%d: %s", count + 1, lines[count]);
        count++;
    }
    fclose(file);

    int choice;
    printf("Escolha o número da linha que deseja editar: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Opção inválida.\n");
        return;
    }

    printf("Digite a nova expressão: ");
    scanf(" %[^\n]", lines[choice - 1] + 12); // Pula "Expressão: "

    file = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
    }
    fclose(file);
    printf("Linha atualizada com sucesso!\n");
}

// Excluir uma linha específica
void deleteLine() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Nenhuma expressão encontrada.\n");
        return;
    }

    char lines[100][256];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), file)) {
        printf("%d: %s", count + 1, lines[count]);
        count++;
    }
    fclose(file);

    int choice;
    printf("Escolha o número da linha que deseja excluir: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Opção inválida.\n");
        return;
    }

    file = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++) {
        if (i != choice - 1)
            fputs(lines[i], file);
    }
    fclose(file);
    printf("Linha excluída com sucesso!\n");
}

// Menu principal
int main() {
    int option;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Verificar Nova Expressão\n");
        printf("2. Listar Todas as Expressões\n");
        printf("3. Editar uma Expressão\n");
        printf("4. Excluir uma Expressão\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpression();
                break;
            case 2:
                listAll();
                break;
            case 3:
                editLine();
                break;
            case 4:
                deleteLine();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (option != 5);

    return 0;
}