#include<stdio.h>
#include<stdlib.h>

void mainMenu(int *opcao) {
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
    scanf("%d", opcao);
}

void submenu(int *opcao) {
    printf("\n1- Listar todos");
    printf("\n2- Listar um");
    printf("\n3- Incluir");
    printf("\n4- Alterar e excluir");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", opcao);
}

int submenuRelatorios(int *opcao) {

}

int main() {
    int opcao = 0, opcaoSubmenu = 0, opcaoSubmenurelatorios = 0;
    do {
        mainMenu(&opcao);
        switch (opcao) {
            case 1:
                printf("\n=============================");
                printf("\nSubmenu de Alunos:");
                submenu(&opcaoSubmenu);
                switch (opcaoSubmenu) {
                    case 1:
                        printf("\nVoce selecionou 1");
                        break;
                    case 2:
                        printf("\nVoce selecionou 2");
                        break;
                    case 3:
                        printf("\nVoce selecionou 3");
                        break;
                    case 4:
                        printf("\nVoce selecionou 4");
                        break;
                break;
                }
            //Inserir a resposta pra opção selecionada
            case 2:
                printf("\n=============================");
                printf("\nSubmenu de Cursos:");
                submenu(&opcaoSubmenu);
                    switch (opcaoSubmenu) {
                        case 1:
                            printf("\nVoce selecionou 1");
                            break;
                        case 2:
                            printf("\nVoce selecionou 2");
                            break;
                        case 3:
                            printf("\nVoce selecionou 3");
                            break;
                        case 4:
                            printf("\nVoce selecionou 4");
                            break;
                    }
                break;
            case 3:
                printf("\n=============================");
                printf("\nSubmenu de Matrícula:");
                submenu(&opcaoSubmenu);
                    switch (opcaoSubmenu) {
                        case 1:
                            printf("\nVoce selecionou 1");
                            break;
                        case 2:
                            printf("\nVoce selecionou 2");
                            break;
                        case 3:
                            printf("\nVoce selecionou 3");
                            break;
                        case 4:
                            printf("\nVoce selecionou 4");
                            break;
                    }
                break;
            case 4:
                printf("\n=============================");
                printf("\nSubmenu Relatórios:");
                submenu(&opcaoSubmenu);
                    switch (opcaoSubmenu) {
                        case 1:
                            printf("\nVoce selecionou 1");
                            break;
                        case 2:
                            printf("\nVoce selecionou 2");
                            break;
                        case 3:
                            printf("\nVoce selecionou 3");
                            break;
                        case 4:
                            printf("\nVoce selecionou 4");
                            break;
                    }
                break;
        }
    }
    while(opcao != 5);
    if(opcao == 5) {
        printf("Encerrando programa.");
    }
}