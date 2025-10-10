#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
    char nome[40], dataNascimento[10], sexo, emails[10][40], telefones[10][14]; //CPF é único por aluno 
    //int quantEmails, quantTelefones;
    int cpf;
};

struct curso {
    char codigo[10], descricao[60]; //código é único por curso
    float preco, cargaHoraria;
};

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

void submenuRelatorios(int *opcao) {
    printf("\n=============================");
    printf("\nSubmenu Relatórios:");
    printf("\n1- Mostrar dados de todos os alunos de um curso");
    printf("\n2- Mostrar os dados de todos os cursos oferecidos entre as datas X e Y");
    printf("\n3- Mostrar os dados de todos os cursos realizados por um aluno");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções:");
    scanf("%d", opcao);
}

int incluirAluno(struct aluno listaAlunos[], int quant) {
    int quantEmails = 0, i, quantTelefones = 0;
    printf("\nNome: ");
    getchar();
    fgets(listaAlunos[quant].nome, 40, stdin);
    printf("\nData de nascimento (dd/mm/aaaa): ");
    scanf("%s", &listaAlunos[quant].dataNascimento);
    printf("\nSexo: ");
    getchar();
    scanf("%c", &listaAlunos[quant].sexo);
    printf("\nInforme a quantidade de e-mails a serem inseridos: ");
    scanf("%d", &quantEmails);
    printf("\nInsira a seguir o(s) e-mail(s) do aluno: ");
    for(i = 0; i < quantEmails; i++) {
        scanf("%s", &listaAlunos[quant].emails[i]);
    }
    printf("");
    printf("\n");
    printf("\ne-mail(s) inserido(s) com sucesso.");
    printf("\nInforme a quantidade de números telefônicos: ");
    scanf("%d", &quantTelefones);
    printf("\nInsira a seguir o(s) telefone(s): ");
    for(i = 0; i < quantTelefones; i++) {
        scanf("%s", &listaAlunos[quant].telefones[i]);
    }
    printf("Telefone(s) inserido(s) com sucesso.");
    printf("\n");
    return 1;
}

int incluirCurso(struct curso listaCursos[], int quantCursos) {
    printf("\nDescrição do curso: ");
    getchar();
    fgets(listaCursos[quantCursos].descricao, 60, stdin);
    printf("\nCarga horária: ");
    scanf("%f", &listaCursos[quantCursos].cargaHoraria);
    printf("\nPreço: ");
    scanf("%f", &listaCursos[quantCursos].preco);
    return 1;
}

int main() {
    struct aluno alunos[100];
    struct curso cursos[20];
    int opcao = 0, opcaoSubmenu = 0, opcaoSubmenurelatorios = 0, i, quantAlunos = 0, cpfExiste, resultado = 0, cpf, quantCursos = 0, codigoExiste = 0;
    do {
        mainMenu(&opcao);
        switch (opcao) {
            case 1:
                printf("\n=============================");
                printf("\nSubmenu de Alunos:");
                submenu(&opcaoSubmenu);
                switch (opcaoSubmenu) {
                    case 1:
                        printf("\nVocê selecionou 1"); //teste 
                        break;
                    case 2:
                        printf("\nVoce selecionou 2");
                        break;
                    case 3:
                        cpfExiste = 0;
                        printf("\nIncluindo aluno no sistema...");
                        printf("\n");
                        printf("\n Informe o CPF do aluno (apenas os números): ");
                        scanf("%d", &cpf);
                        for(i = 0; i < quantAlunos; i++) {
                            if(cpf == alunos[i].cpf) {
                                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                printf("\nO CPF inserido já existe no sistema.");
                                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                printf("\n");
                                cpfExiste = 1;
                                break;
                            }
                        } 
                        if(cpfExiste == 0 && quantAlunos < 100) {
                            alunos[quantAlunos].cpf = cpf;
                            resultado = incluirAluno(alunos, quantAlunos);
                            if(resultado == 1) { //feedback
                                quantAlunos++;
                                printf("\n=============================");
                                printf("\nAluno adicionado ao sistema com sucesso!");
                                printf("\n=============================");
                                printf("\n");
                            }
                            else {
                                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                printf("\nNão foi possível adicionar o aluno ao sistema.");
                                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                printf("\n");
                            }
                        } 
                        break;
                    case 4:
                        printf("\nVoce selecionou 4");
                        break;
                }
                break;
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
                            printf("\nInsira o código do curso a ser inserido no sistema: ");
                            scanf("%s", &cursos[quantCursos].codigo);
                            for(i = 0; i < quantCursos && codigoExiste == 0; i++) {
                                if(strcmp(cursos[quantCursos].codigo, cursos[i].codigo) == 0) {
                                    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                    printf("\nO código inserido já existe no sistema.");
                                    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                    printf("\n");
                                    codigoExiste = 1;
                                    break;
                                }
                            }
                            if(codigoExiste == 0) {
                                resultado = incluirCurso(cursos, quantCursos);
                                if(resultado == 1) {
                                    printf("\n=============================");
                                    printf("\nCurso cadastrado com sucesso!");
                                    printf("\n=============================");
                                    printf("\n");
                                }
                            }
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
                submenuRelatorios(&opcaoSubmenurelatorios);
                    switch (opcaoSubmenurelatorios) {
                        case 1:
                            printf("\nVoce selecionou 1");
                            break;
                        case 2:
                            printf("\nVoce selecionou 2");
                            break;
                        case 3:
                            printf("\nVoce selecionou 3");
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