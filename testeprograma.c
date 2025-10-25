#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
    char nome[40], dataNascimento[10], sexo, emails[10][40], telefones[10][14], cpf[14]; //CPF é único por aluno 
    //int quantEmails, quantTelefones;
};

struct curso {
    char codigo[10], descricao[60]; //código é único por curso
    float preco, cargaHoraria;
};

struct matricula {//Não pode existir mais de um mesmo cpf com um mesmo código de curso
    float desconto;
    char codigoCurso[10], dataInicio, dataFim, cpfAluno[14];
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
    switch(*opcao) {
        case 1:
            printf("\n=============================");
            printf("\nSubmenu de Alunos:");

    }
}

void submenu(struct aluno listaAlunos) {
    int opcao;
    struct aluno *alunos;
    printf("\n1- Listar todos");
    printf("\n2- Listar um");
    printf("\n3- Incluir");
    printf("\n4- Alterar e excluir");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", opcao);
    alunos = (struct aluno *) malloc (limiteAlunos * sizeof(struct aluno));
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

int incluirAluno(struct aluno *listaAlunos, int *quant) {
    int quantEmails = 0, i, quantTelefones = 0;
    printf("\nNome: ");
    getchar();
    fgets(listaAlunos[*quant].nome, 40, stdin);
    printf("\nData de nascimento (dd/mm/aaaa): ");
    scanf("%s", &listaAlunos[*quant].dataNascimento);
    printf("\nSexo: ");
    getchar();
    scanf("%c", &listaAlunos[*quant].sexo);
    printf("\nInforme a quantidade de e-mails a serem inseridos: ");
    scanf("%d", &quantEmails);
    printf("\nInsira a seguir o(s) e-mail(s) do aluno: ");
    for(i = 0; i < quantEmails; i++) {
        scanf("%s", &listaAlunos[*quant].emails[i]);
    }
    printf("\n");
    printf("\ne-mail(s) inserido(s) com sucesso.");
    printf("\n");
    printf("\nInforme a quantidade de números telefônicos: ");
    scanf("%d", &quantTelefones);
    printf("\nInsira a seguir o(s) telefone(s): ");
    for(i = 0; i < quantTelefones; i++) {
        scanf("%s", &listaAlunos[*quant].telefones[i]);
    }
    printf("Telefone(s) inserido(s) com sucesso.");
    printf("\n");
    (*quant)++;
    for(i = 0; i < 1; i++) {
        printf("\n%s", listaAlunos[*quant].cpf);
        printf("\n%s", listaAlunos[*quant].nome);
        printf("\n%s", listaAlunos[*quant].dataNascimento);
        printf("\n%s", listaAlunos[*quant].sexo);
        printf("\n%s", listaAlunos[*quant].emails);
        printf("\n%s", listaAlunos[*quant].telefones);
    }
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

int verificarCPF(struct aluno listaAlunos[], const char *cpf, int quantAlunos) { //Não está identificando strings iguais
    int i, resultado;
    printf("\n%s", cpf);
    if(quantAlunos == 0) {
        return -1;
    }
    else {
        for(i = 0; i < quantAlunos; i++) {
            printf("%d", strcmp(cpf, listaAlunos[i].cpf));
            printf("%s", listaAlunos[i].cpf);
            if(strcmp(cpf, listaAlunos[i].cpf) == 0) {
                return i;
            }
        }
        return -1; //não foi encontrado
    }
}

int verificarCodigo(struct curso listaCursos[], char codigo[], int quantCursos) {
    int i, j, resultado;
    if(quantCursos == 0) {
        return -1;
    }
    else {
        for(i = 0; i < quantCursos; i++) {
            resultado = strcmp(codigo, listaCursos[i].codigo);
            if(resultado == 0) {
                return i;
            }
        }
        return -1;
    }
}

int main() {
    //Alocar dinamicamente os vetores alunos e cursos
    struct curso *cursos;
    int opcao = 0, opcaoSubmenu = 0, opcaoSubmenurelatorios = 0, i, quantAlunos = 0, resultado = 0, quantCursos = 0, codigoExiste = 0, limiteAlunos = 100, limiteCursos = 50, alocou;
    char *codigo, *cpf; 
    do {
        mainMenu(&opcao);
        switch (opcao) {
            case 1:
                if(alunos != NULL) {

                    submenu(&opcaoSubmenu);
                    switch (opcaoSubmenu) {
                        case 1:
                            printf("\nVocê selecionou 1"); //teste 
                        case 2:
                            printf("\nVoce selecionou 2");
                        case 3:
                            system("clear||cls");

                            printf("\nIncluindo aluno no sistema...");
                            printf("\n");
                            printf("\n Informe o CPF do aluno (apenas os números): ");

                            cpf = (char *) malloc(14); 
                            if(cpf != NULL) {
                                scanf("%14s", cpf);
                                if(verificarCPF(alunos, cpf, quantAlunos) >= 0) {
                                    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                    printf("\nO CPF inserido já existe no sistema.");
                                    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                    printf("\n");
                                }
                                else {
                                    strcpy(alunos[quantAlunos].cpf, cpf);
                                    free(cpf);
                                    resultado = incluirAluno(alunos, &quantAlunos);
                                    if(resultado == 1) { //feedback
                                        //system("clear||cls");

                                        printf("\n=============================");
                                        printf("\nAluno adicionado ao sistema com sucesso!");
                                        printf("\n=============================");
                                        printf("\n");
                                        
                                        /* Print teste
                                        printf("\n%s", alunos[quantAlunos].nome); 
                                        printf("\n%s", alunos[quantAlunos].cpf);
                                        printf("\n%s", alunos[quantAlunos].dataNascimento);
                                        printf("\n%s", alunos[quantAlunos].sexo);
                                        printf("\n%s", alunos[quantAlunos].emails);
                                        printf("\n%s", alunos[quantAlunos].telefones);*/
                                    }
                                    else {
                                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                        printf("\nNão foi possível adicionar o aluno ao sistema.");
                                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                        printf("\n");
                                    }
                                }
                            } 
                            else {
                                printf("\nMemória indisponível.");
                            }
                            break;
                        case 4:
                            printf("\nVoce selecionou 4");
                        default:
                            system("clear||cls");
                            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            printf("\nA opção inserida não é válida, tente novamente.");
                            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            printf("\n");
                    }
                }
                else {
                    printf("\nMemória indisponível!");
                }
                break;
            case 2:
                printf("\n=============================");
                printf("\nSubmenu de Cursos:");
                submenu(&opcaoSubmenu);
                    switch (opcaoSubmenu) {
                        cursos = (struct curso *) malloc(limiteCursos * sizeof(struct curso));
                        if(cursos != NULL) { //verifica se a memória foia locada corretamente
                            case 1:
                                printf("\nVoce selecionou 1");
                            case 2:
                                printf("\nVoce selecionou 2");
                            case 3:
                                printf("\nInsira o código do curso a ser inserido no sistema: ");
                                codigo = (char *) malloc(10);
                                if(codigo != NULL) {
                                    scanf("%s", &codigo);   
                                    if(verificarCodigo(cursos, codigo, quantCursos) >= 0) {
                                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                        printf("\nO código inserido já existe no sistema.");
                                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                        printf("\n");
                                    }
                                    else {
                                        strcpy(cursos[quantCursos].codigo, codigo);
                                        resultado = incluirCurso(cursos, quantCursos);
                                        if(resultado == 1) { //confirma se o processo de incluir foi terminado
                                            system("clear||cls");
                                            printf("\n=============================");
                                            printf("\nCurso cadastrado com sucesso!");
                                            printf("\n=============================");
                                            printf("\n");
                                            quantCursos++;
                                        }
                                    }
                                }
                                else {
                                    printf("\nmemória indisponível.");
                                }
                            case 4:
                                printf("\nVoce selecionou 4");
                        }
                        else {
                            printf("\nMemória insuficiente!");
                        }
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
            default:
                system("clear||cls");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\nA opção inserida não é válida, tente novamente.");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\n");
                break;
        }
    }
    while(opcao != 5);
    if(opcao == 5) {
        system("clear||cls");
        printf("\n");
        printf("\n=============================");
        printf("\nEncerrando programa.");
        printf("\n=============================");
    }
}