
# Verificador de Balanceamento de Parênteses, Colchetes e Chaves

Este é um projeto simples em C que verifica se uma expressão contém parênteses (`()`), colchetes (`[]`) e chaves (`{}`) balanceados. Ele utiliza uma **estrutura de dados de pilha** para realizar a verificação.

---

## Funcionalidades

- **Verificação de Balanceamento**: O programa verifica se os parênteses, colchetes e chaves estão corretamente abertos e fechados na ordem adequada.
- **Interface Simples**: O usuário pode inserir uma expressão diretamente no terminal, e o programa informará se ela está balanceada ou não.
- **Tratamento de Erros**: Caso a expressão esteja desbalanceada, o programa identifica o problema e informa ao usuário.

---

##  Como Inicializar o Projeto

### Pré-requisitos
- Compilador C instalado (como `gcc`).
- Um editor de texto ou IDE de sua preferência (opcional).

### Passos para Executar o Projeto

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/SEU_USUARIO/nome-do-repositorio.git
   cd nome-do-repositorio
   ```

2. **Compile o código**:
   Use o compilador GCC para gerar o executável:
   ```bash
   gcc -o balance_checker main.c
   ```

3. **Execute o programa**:
   Após a compilação, execute o programa com:
   ```bash
   ./balance_checker
   ```

4. **Insira uma expressão**:
   O programa solicitará que você insira uma expressão para verificar o balanceamento. Por exemplo:
   ```
   Digite uma expressão para verificar o balanceamento: { [ ( ) ] } ( )
   A expressão está balanceada.
   ```

---

##  Estrutura do Código

O código implementa uma **pilha** para verificar o balanceamento. Aqui estão as principais funções:

- **`initializeStack`**: Inicializa a pilha.
- **`isEmpty`**: Verifica se a pilha está vazia.
- **`isFull`**: Verifica se a pilha está cheia.
- **`push`**: Empilha um caractere de abertura.
- **`pop`**: Desempilha um caractere de abertura.
- **`checkBalance`**: Verifica o balanceamento da expressão fornecida.
- **`main`**: Função principal que lê a entrada do usuário e exibe o resultado.

---

##  Exemplos de Entrada e Saída

### Exemplo 1: Expressão Balanceada
Entrada:
```
Digite uma expressão para verificar o balanceamento: { [ ( ) ] } ( )
```
Saída:
```
A expressão está balanceada.
```

### Exemplo 2: Expressão Desbalanceada
Entrada:
```
Digite uma expressão para verificar o balanceamento: { [ ( ] ) }
```
Saída:
```
A expressão NÃO está balanceada.
```

---

## Casos de Teste

| Expressão                     | Resultado Esperado |
|-------------------------------|--------------------|
| `{ [ ( ) ] } ( )`            | Balanceada         |
| `{ [ ( ] ) }`                | Desbalanceada      |
| `( ( (`                      | Desbalanceada      |
| `) ) )`                      | Desbalanceada      |
| `({[]})`                     | Balanceada         |

---

