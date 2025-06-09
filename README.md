
---

# 📌 Projeto: Verificador de Balanceamento com CRUD em C

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)  
![GitHub license](https://img.shields.io/github/license/TonyCarlosOlSo/Balanciador_simples)

Este é um programa escrito em **linguagem C** que verifica se uma expressão contém **parênteses `()`, colchetes `[]` e chaves `{}` balanceados**, utilizando uma **estrutura de dados do tipo pilha**.

Além disso, foi implementado um **CRUD básico (Create, Read, Update, Delete)** para gerenciar as expressões verificadas, armazenando-as em um arquivo `.txt` como um **banco de dados simples**.

---

## 🧠 Objetivo

O objetivo principal do projeto é:

✅ Desenvolver um sistema que:
- Verifique o balanceamento de símbolos em expressões matemáticas ou lógicas.  
- Permita ao usuário gerenciar o histórico dessas verificações através de um menu interativo com funcionalidades de **CRUD**.  
- Utilize arquivos para armazenar os resultados, simulando um sistema de persistência de dados.

---

## 🧩 Funcionalidades Principais

### 1. **Verificação de Balanceamento**
- Usa uma **pilha** para verificar se os pares de símbolos estão corretamente abertos e fechados.
- Suporta os seguintes símbolos: `(`, `)`, `[`, `]`, `{`, `}`.
- Retorna se a expressão está **balanceada** ou **desbalanceada**.

### 2. **CRUD Básico**
Implementado com uso de arquivos `.txt` como base de dados:

| Função | Ação |
|-------|------|
| **Create (Criar)** | Adiciona novas expressões ao arquivo `resultados.txt`. |
| **Read (Ler)** | Exibe todas as expressões já verificadas. |
| **Update (Atualizar)** | Permite editar uma linha específica do arquivo. |
| **Delete (Excluir)** | Remove uma entrada do histórico salvo. |

### 3. **Interface Interativa**
- Menu com opções claras e fáceis de usar.
- O usuário pode fazer várias verificações e operações sem precisar reiniciar o programa.

---

## 📁 Estrutura do Projeto

```
Balanciador_simples/
├── main.c
├── README.md
└── resultados.txt (gerado automaticamente)
```

- **main.c**: Código-fonte principal com todas as funções.
- **README.md**: Este documento.
- **resultados.txt**: Arquivo onde os resultados das verificações são armazenados (funciona como um "banco de dados").

---

## 🔧 Como Executar

### Requisitos
- Compilador **GCC** instalado.
- Terminal ou prompt de comando.
- Sistema operacional: Windows, Linux ou macOS.

---

### Passo a Passo

1. **Abra o terminal** na pasta do projeto.
2. **Compile o código**:
   ```bash
   gcc main.c -o balanciador
   ```

3. **Execute o programa**:
   ```bash
   ./balanciador
   ```

4. **Siga as opções do menu** para realizar verificações ou gerenciar o histórico.

---

## 💻 Exemplo de Uso

### Menu Principal
```
===== MENU =====
1. Verificar Nova Expressão
2. Listar Todas as Expressões
3. Editar uma Expressão
4. Excluir uma Expressão
5. Sair
Escolha uma opção: 
```

### Opção 1: Verificar Nova Expressão
```text
Digite uma expressão para verificar: { [ ( ) ] } ( )
Resultado: Balanceada
Expressão adicionada com sucesso!
```

### Opção 2: Listar Todas as Expressões
```text
=== Histórico de Expressões ===
Expressão: "{ [ ( ) ] } ( )" -> Balanceada
Expressão: "[ ( { } ]" -> Desbalanceada
```

### Opção 3: Editar uma Expressão
```text
1: Expressão: "{ [ ( ) ] } ( )" -> Balanceada
Escolha o número da linha que deseja editar: 1
Digite a nova expressão: ( ( ( ) )
Linha atualizada com sucesso!
```

### Opção 4: Excluir uma Expressão
```text
1: Expressão: "( ( ( ) )"
Escolha o número da linha que deseja excluir: 1
Linha excluída com sucesso!
```

---

## 📚 Conceitos Aplicados

- **Estruturas de Dados** (Pilha)
- **Manipulação de Strings**
- **Controle de Fluxo** (`if`, `for`, `switch`)
- **Funções** reutilizáveis e modularizadas
- **Leitura e Escrita em Arquivos**
- **CRUD Simples**

---

## 📄 Exemplo de Saída no Arquivo `resultados.txt`

```
Expressão: "{ [ ( ) ] } ( )" -> Balanceada
Expressão: "[ ( { } ]" -> Desbalanceada
Expressão: "( ( ( ) )" -> Balanceada
```

---

## 📎 Observações

- O arquivo `resultados.txt` é criado automaticamente na primeira execução.
- O programa não usa bibliotecas externas além das nativas do C.
- Ideal para estudo de estruturas de dados e persistência de dados básica.

---

## 📝 Licença

Este projeto está licenciado sob a **MIT License** – veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👥 Contribuições

Contribuições são sempre bem-vindas! Se você quiser melhorar o projeto, adicionar novas funcionalidades ou otimizar o código, fique à vontade!

---

## 📬 Contato

Se tiver dúvidas ou sugestões, entre em contato:

- **GitHub**: [@TonyCarlosOlSo](https://github.com/TonyCarlosOlSo)
- **Email**: tonycarlos@email.com

---

> ✅ Com este projeto, você tem um exemplo prático de aplicação de **pilhas**, **manipulação de arquivos** e **interação com o usuário**, tudo isso com uma interface intuitiva e fácil de entender.

--- 
