#include<stdio.h>
#include<stdlib.h>

int mainMenu(int *opcao) {
    printf("\n=============================");
    printf("\nMenu principal:");
    printf("\n1- Submenu de Alunos");
    printf("\n2- Submenu de Cursos");
    printf("\n3- Submenu de Matrícula");
    printf("\n4- Submenu Relatórios");
    printf("\n5- Sair");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", *opcao);
}

int submenu(int *opcao) {
    printf("\n1- Listar todos");
    printf("\n2- Listar um");
    printf("\n3- Incluir");
    printf("\n4- Alterar e excluir");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", *opcao);
}

int main() {
    int opcao = 0, opcaoSubmenu = 0;
    do {
        mainMenu(&opcao);
        switch (opcao) {
            case 1:
                printf("\n=============================");
                printf("\nSubmenu de Alunos:");
                submenu(&opcaoSubmenu);
            //Inserir a resposta pra opção selecionada
            case 2:
                printf("\n=============================");
                printf("\nSubmenu de Cursos:");
                submenu(&opcaoSubmenu);
            case 3:
                printf("\n=============================");
                printf("\nSubmenu de Matrícula:");
                submenu(&opcaoSubmenu);
            case 4:
                printf("\n=============================");
                printf("\nSubmenu Relatórios:");
                submenu(&opcaoSubmenu);
        }
    }
    while(opcao != 5);
}