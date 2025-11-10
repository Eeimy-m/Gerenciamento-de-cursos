#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
    char nome[40], dataNascimento[11], sexo, emails[10][40], telefones[10][14], cpf[14]; //CPF é único por aluno 
    int quantTelefones, quantEmails;
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

void imprimirAluno(struct aluno listaAlunos[], int n) {
    int i;
    printf("\n=============================");
    printf("\nNome: %s", listaAlunos[n].nome);
    printf("\n");
    printf("\nCPF: %s", listaAlunos[n].cpf);
    printf("\n");
    printf("\nData de nascimento: %s", listaAlunos[n].dataNascimento);
    printf("\n");
    printf("\nSexo: %c", listaAlunos[n].sexo);
    printf("\n");
    printf("\nNúmeros telefônicos:");
    for(i = 0; i < listaAlunos[n].quantTelefones; i++) {
        printf("\n%s", listaAlunos[n].telefones[i]);
    }
    printf("\n");
    printf("\nE-mails: ");
    for(i = 0; i < listaAlunos[n].quantEmails; i++) {
        printf("\n%s", listaAlunos[n].emails[i]);
    }
    printf("\n=============================");
    printf("\n");
}

void inserirEmArqCursos(struct curso cursos[], int quant) {
    FILE *arq;
    arq = fopen("alunos.dat", "ab"); //insere ao fim do arquivo
    if(arq == NULL) {
        printf("Não foi possível abrir o arquivo.");
        exit(0);
    }
    if((fwrite(&cursos[quant], sizeof(struct aluno), 1, arq)) != 1) {
        printf("\nErro na escrita");
        exit(0);
    } 
}

void inserirEmArqAlunos(struct aluno alunos[], int quant) {
    FILE *arq;
    arq = fopen("alunos.dat", "ab");
    if(arq == NULL) {
        printf("Não foi possível abrir o arquivo.");
        exit(0);
    }
    if((fwrite(&alunos[quant], sizeof(struct aluno), 1, arq)) != 1) {
        printf("\nErro na escrita");
        exit(0);
    } 
}

void leituraDeArquivos() { //Lê os dados de arquivo texto e imprime
    FILE *arq;
    char c;
    arq = fopen("cursos.dat", "r"); //apenas conlúi a ação se o arquivo existir
    if(arq == NULL) {
        arq = fopen("cursos.dat", "w+"); //caso o arquivo não exista, ele será criado
    }
    while((c = fgetc(arq)) != EOF) {
        printf("%c", c);
    }
    fclose(arq);
}

int incluirAluno(struct aluno listaAlunos[], int *quant) {
    int quantEmails = 0, i, quantTelefones = 0;
    printf("\nNome: ");
    getchar();
    fgets(listaAlunos[*quant].nome, 40, stdin);
    listaAlunos[*quant].nome[strcspn(listaAlunos[*quant].nome, "\n")] = '\0';

    printf("\nData de nascimento (dd/mm/aaaa): ");
    scanf("%10s", listaAlunos[*quant].dataNascimento);

    printf("\nSexo: ");
    getchar();
    scanf("%c", &listaAlunos[*quant].sexo);

    printf("\nInforme a quantidade de e-mails a serem inseridos: ");
    scanf("%d", &listaAlunos[*quant].quantEmails);
    printf("\nInsira a seguir o(s) e-mail(s) do aluno: ");
    for(i = 0; i < listaAlunos[*quant].quantEmails; i++) {
        scanf("%s", &listaAlunos[*quant].emails[i]);
    }
    printf("\n");
    printf("\ne-mail(s) inserido(s) com sucesso.");
    printf("\n");

    printf("\nInforme a quantidade de números telefônicos: ");
    scanf("%d", &listaAlunos[*quant].quantTelefones);
    printf("\nInsira a seguir o(s) telefone(s): ");
    for(i = 0; i < listaAlunos[*quant].quantTelefones; i++) {
        scanf("%s", &listaAlunos[*quant].telefones[i]);
    }

    printf("Telefone(s) inserido(s) com sucesso.");
    printf("\n");

    printf("\nData de nascimento: %s", listaAlunos[*quant].dataNascimento);
    (*quant)++;
    return 1;
}

int incluirCurso(struct curso listaCursos[], int *quantCursos) {
    printf("\nDescrição do curso: ");
    getchar();
    fgets(listaCursos[*quantCursos].descricao, 60, stdin);
    printf("\nCarga horária: ");
    scanf("%f", &listaCursos[*quantCursos].cargaHoraria);
    printf("\nPreço: ");
    scanf("%f", &listaCursos[*quantCursos].preco);
    (*quantCursos)++;
    return 1;
}

int verificarCPF(struct aluno listaAlunos[], char *cpf, int quantAlunos) { 
    int i, resultado; 
    if(quantAlunos == 0) {
        return -1;
    }
    else {
        for(i = 0; i < quantAlunos; i++) {
            if(strcmp(cpf, listaAlunos[i].cpf) == 0) {
                return i;
            }
        }
        return -1; //não foi encontrado
    }
}

int verificarCodigo(struct curso listaCursos[], char *codigo, int quantCursos) {
    int i, j;
    if(quantCursos == 0) {
        return -1;
    }
    else {
        for(i = 0; i < quantCursos; i++) {
            if(strcmp(codigo, listaCursos[i].codigo) == 0) {
                return i;
            }
        }
        return -1;
    }
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

void mainMenu() {
    int opcao, limiteAlunos = 100, limiteCursos = 50, quantAlunos = 0, quantCursos = 0, resultado, posicao, i;
    char *cpf, *codigo;

    struct aluno *alunos; 
    struct curso *cursos;

    alunos = (struct aluno *) malloc (limiteAlunos * sizeof(struct aluno));
    cursos = (struct curso*) malloc (limiteCursos * sizeof(struct curso));

    do {
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
        scanf("%d", &opcao);

        if(opcao == 1) {
            cpf = (char *) malloc(sizeof (char) * 16); 
            if(alunos != NULL && cpf != NULL) {
                printf("\n=============================");
                printf("\nSubmenu de Alunos");
                submenu(&opcao);
                switch (opcao) {
                    case 1:
                        system("clear||cls");
                        printf("\n=============================");
                        printf("\nTodos os alunos cadastrados"); 
                        for(i = 0; i < quantAlunos; i++) {
                            imprimirAluno(alunos, i);
                        }
                        break;
                    case 2:
                        printf("\nInforme o cpf do aluno:");
                        scanf("%s", cpf);
                        posicao = verificarCPF(alunos, cpf, quantAlunos);
                        if(posicao < 0) {
                            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            printf("\nCPF não encontrado no sistema.");
                            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        }
                        else {
                            imprimirAluno(alunos, posicao);
                        }
                        break;
                    case 3:
                        system("clear||cls");

                        printf("\nIncluindo aluno no sistema...");
                        printf("\n");
                        printf("\nInforme o CPF do aluno: ");

                        getchar();
                        fgets(cpf, 15, stdin);
                        cpf[strcspn(cpf, "\n")] = '\0';
                        if(verificarCPF(alunos, cpf, quantAlunos) >= 0) {
                            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            printf("\nO CPF inserido já existe no sistema.");
                            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            printf("\n");
                        }
                        else {
                            strcpy(alunos[quantAlunos].cpf, cpf);
                            free(cpf); //liberar o locald a memória
                            resultado = incluirAluno(alunos, &quantAlunos);
                            if(resultado == 1) { //feedback
                                system("clear||cls");

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
                    default:
                        system("clear||cls");
                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("\nA opção inserida não é válida, tente novamente.");
                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("\n");
                }
            }
            else {
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\nMemória insuficiente");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\n");
            }
        }
        else if(opcao == 2) {
            if(cursos != NULL) {
                printf("\n=============================");
                printf("\nSubmenu de Cursos:");
                submenu(&opcao);
                switch (opcao) {
                    case 1:
                        printf("\n=============================");
                        printf("\nDados de todos os cursos");
                        printf("\n");
                    case 2:
                        printf("\nVoce selecionou 2");
                    case 3:
                        printf("\nInsira o código do curso a ser inserido no sistema: ");
                        codigo = (char *) malloc(sizeof(char) * 12);
                        if(codigo != NULL) {
                            scanf("%s", codigo);   
                            
                            if(verificarCodigo(cursos, codigo, quantCursos) >= 0) {
                                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                printf("\nO código inserido já existe no sistema.");
                                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                                printf("\n");
                            }
                            else {
                                strcpy(cursos[quantCursos].codigo, codigo);

                                if(incluirCurso(cursos, &quantCursos) == 1) { //confirma se o processo de incluir foi terminado
                                    system("clear||cls");
                                    printf("\n=============================");
                                    printf("\nCurso cadastrado com sucesso!");
                                    printf("\n=============================");
                                    printf("\n");
                                }
                            }
                        }
                        else {
                            printf("\nmemória indisponível.");
                        }
                    case 4:
                        printf("\nVoce selecionou 4");
                }
            }
            else {
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\nMemória insuficiente");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\n");
            }
        }
        else if(opcao == 3) {
            printf("\n=============================");
            printf("Submenu de Matrícula");
            submenu(&opcao);
        }
        else if(opcao == 4) {
            printf("\n=============================");
            printf("Submenu de Relatórios");
            submenuRelatorios(&opcao);
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

int main() {
    mainMenu();
}