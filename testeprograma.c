#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
    char nome[40], dataNascimento[11], sexo, emails[10][40], telefones[10][14], cpf[14]; //CPF é único por aluno 
    int quantTelefones, quantEmails;
};

struct curso {
    char codigo[10], descricao[60]; //código é único por curso
    float preco, cargaHoraria;
};

struct matricula {//Não pode existir mais de um mesmo cpf com um mesmo código de curso
    float desconto;
    char codigoCurso[10], dataInicio, dataFim, cpfAluno[14];
};

void MensagemErroAloca() {
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nMemória insuficiente");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

int TamanhoArqu(FILE *arq, int limite) {
    int quant;
    long tamanho;
    size_t tamTotal;

    if(fseek(arq, 0, SEEK_END) != 0)  { //move o cursor para o final do arquivo
        return -1; //indica que o arquivo está vazio
    }
    else {
        tamanho = ftell(arq); //retorna o tamanho do arquivo em bytes
        if(tamanho < 0) {

            return -1;
        }
        tamTotal = (size_t) (tamanho / sizeof(struct aluno)); //tamTotal vai ter a quantidade de structs que o arquivo contém
        printf("%zu", tamTotal);
        return tamTotal;
    }
}

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

void imprimirCurso(struct curso cursos[], int n) {
    printf("\n=============================");
    printf("\nCodigo: %s", cursos[n].codigo);
    printf("\n");
    printf("\nDescrição: %s", cursos[n].descricao);
    printf("\n");
    printf("Preço: %f", cursos[n].descricao);
    printf("\n");
    printf("\nCarga horária: %f", cursos[n].cargaHoraria);
    printf("\n=============================");
    printf("\n");
}

void imprimirMatricula(struct matricula matriculas[], int n) {
    printf("\n=============================");
    printf("\nCódigo: %s", matriculas[n].codigoCurso);
    printf("\n");
    printf("\nCPF do aluno: %s", matriculas[n].cpfAluno);
    printf("\n");
    printf("\nData de início: %s", matriculas[n].dataInicio);
    printf("\n");
    printf("\nData de conclusão: %s", matriculas[n].dataFim);
    printf("\n");
    printf("\nDesconto: %f", matriculas[n].desconto);
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
    fclose(arq);
}

void inserirEmArqAlunos(struct aluno alunos[], int quant) { //quant está indicando a posição do elemento que vai ser gravado no arquivo
    FILE *arq;
    arq = fopen("alunos.dat", "ab"); //arq binário 
    if(arq == NULL) {
        printf("Não foi possível abrir o arquivo.");
        exit(0);
    }
    if((fwrite(alunos, sizeof(struct aluno), quant, arq)) != quant) {
        printf("\nErro na escrita");
        exit(0);
    } 
    fclose(arq);
}

void inserirEmArqMatricula(struct matricula matriculas[], int quant) {

}

struct aluno *leituraAlunos(int limiteAlunos, int *quantAlunos) {
    FILE *arq;
    size_t tamanhoArquivo, lidos;
    struct aluno *alunos;

    arq = fopen("alunos.dat", "ab+");
    if(arq == NULL) {
        printf("\nNão foi possível abrir o arquivo.");
        fclose(arq);
        exit(0);
    }

    tamanhoArquivo = TamanhoArqu(arq, limiteAlunos);
    alunos = (struct aluno*) malloc ((limiteAlunos * sizeof(struct aluno)) + (int) tamanhoArquivo);

    rewind(arq);
    lidos = fread(alunos, sizeof(struct aluno), tamanhoArquivo, arq); 

    if(alunos == NULL) {
        MensagemErroAloca();
    }
    printf("%zu", lidos);

    if(lidos != tamanhoArquivo) {
        printf("\nErro na leitura do arquivo.");
        system("pause");
        fclose(arq);
        exit(0);
    }

    *quantAlunos = (int) lidos;
    return alunos;
}

void leituraCursos(struct curso cursos, int limiteCursos) { //Lê os dados de arquivo texto e imprime
    FILE *arq;
}

void excluir() {

}

int incluirAluno(struct aluno *listaAlunos, int *quant) {
    int i;
    printf("\nNome: ");
    getchar();
    fgets(listaAlunos[*quant].nome, sizeof listaAlunos[*quant].nome, stdin);
    listaAlunos[*quant].nome[strcspn(listaAlunos[*quant].nome, "\n")] = '\0';

    printf("\nData de nascimento (dd/mm/aaaa): ");
    scanf("%10s", &listaAlunos[*quant].dataNascimento);

    getchar();
    printf("\nSexo: ");
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
    
    printf("\n%s", listaAlunos[*quant].cpf);
    printf("\n%s", listaAlunos[*quant].nome);
    printf("\n%s", listaAlunos[*quant].dataNascimento);

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

int incluirMatricula(struct matricula matriculas[], int *quant) {
    //fazer verificação do código do curso e do cpf (se existem ou não e se já tem alguma matrícula igual)
    printf("\nDesconto:");
    scanf("%f", &matriculas[*quant].desconto);
    printf("\nData de início: ");
    scanf("%s", &matriculas[*quant].dataInicio);
    printf("\nData de conclusão: ");
    scanf("%s", &matriculas[*quant].dataFim);
    (*quant)++;
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

int verificarCodigoeCPFMatricula(struct matricula matriculas[], char *codigo, char *cpf, int quantMatriculas) {
    int i, j, contadorCPF = 0, contadorCodigo = 0;
    int posicoesCPF[contadorCPF];
    int posicoesCodigo[contadorCodigo];

    if(quantMatriculas == 0) {
        return -1;
    }

    else {
        for(i = 0; i < quantMatriculas; i++) {
        if(codigo == matriculas[i].codigoCurso) {
            posicoesCodigo[contadorCodigo] = i;
            contadorCodigo++;
        }
        }

        for(i = 0; i < quantMatriculas; i++) {
            if(cpf == matriculas[i].cpfAluno) {
                posicoesCPF[contadorCPF] = i;
                contadorCPF++;
            }
        }

        for(i = 0; i < contadorCodigo; i++) { //ocupam o mesmo endereço na lista de structs de matrícula = essa matrícula já existe
            for(j = 0; j < contadorCPF; j++) {
                if(posicoesCodigo[i] == posicoesCPF[j]) {
                    return i;
                }
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

void submenuAlterar(int *opcao) {
    printf("\n=============================");
    printf("\n1- Nome");
    printf("\n2- data de nascimento");
    printf("\n3- Sexo");
    printf("\n1- E-mail");
    printf("\n1- Telefone");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções:");
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

void submenuAlterarExcluir(int *opcao) {
    printf("\n");
    printf("\n=============================");
    printf("\n1- Alterar");
    printf("\n2- Excluir");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", opcao);
}

void ImprimirMensagemDeErro() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nA opção inserida não é válida, tente novamente.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void MensagemErroCadastro() {
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nNão foi possível concluir o cadastro.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void submenuAlunos(struct aluno alunos[], char *cpf, int *quantAlunos) {
    int opcao, posicao, resultado, i;
    int quant = *quantAlunos;

    printf("\n=============================");
    printf("\nSubmenu de Alunos");
    submenu(&opcao);
    switch (opcao) {
        case 1:
            system("clear||cls");
            printf("\n=============================");
            printf("\nTodos os alunos cadastrados"); 
            for(i = 0; i < *quantAlunos; i++) {
                imprimirAluno(alunos, i);
            }
            break;
        case 2:
            printf("\nInforme o cpf do aluno:");
            getchar();
            fgets(cpf, 15, stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            posicao = verificarCPF(alunos, cpf, quant);
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

            if(verificarCPF(alunos, cpf, quant) >= 0) {
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\nO CPF inserido já existe no sistema.");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\n");
            }
            else {
                strcpy(alunos[*quantAlunos].cpf, cpf);
                free(cpf); //liberar o locald a memória
                resultado = incluirAluno(alunos, quantAlunos); //quantAlunos contém o endereço de memória pro local onde aponta

                if(resultado == 1) { //feedback
                    system("clear||cls");

                    printf("\n=============================");
                    printf("\nAluno adicionado ao sistema com sucesso!");
                    printf("\n=============================");
                    printf("\n");
                }
                else {
                    MensagemErroCadastro();
                }
            }
            break;
        case 4:
            printf("\nInforme o cpf do aluno:");
            scanf("%s", cpf);
            submenuAlterarExcluir(&opcao);
            posicao = verificarCPF(alunos, cpf, quant);
            if(opcao == 1) {
                submenuAlterar(&opcao);
            }
            else if(opcao == 2) {
                printf("\n=============================");
                printf("\nAluno removido do sistema com sucesso!");
                printf("\n=============================");
                printf("\n");
            }
            else {
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\nA opção inserida não é válida, tente novamente.");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            }
            break;
        default:
            ImprimirMensagemDeErro();
            break;
    }
}

void submenuCursos(struct curso cursos[]) {
    int opcao, quantCursos;
    char *codigo;

    if(cursos != NULL) {
        printf("\n=============================");
        printf("\nSubmenu de Cursos:");
        submenu(&opcao);
        switch (opcao) {
            case 1:
                printf("\n=============================");
                printf("\nDados de todos os cursos");
                printf("\n");
                break;
            case 2:
                printf("\nVoce selecionou 2");
                break;
            case 3:
                printf("\nInsira o código do curso a ser inserido no sistema: ");
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

                            inserirEmArqCursos(cursos, quantCursos);

                            printf("\n=============================");
                            printf("\nCurso cadastrado com sucesso!");
                            printf("\n=============================");
                            printf("\n");
                        }

                        else {
                            MensagemErroCadastro();
                        }
                    }
                }
                else {
                    printf("\nInforme o código do curso:");
                    scanf("%s", &codigo);
                    submenuAlterarExcluir(&opcao);
                    if(opcao == 1) {
                        submenuAlterar(&opcao);
                    }
                    else if(opcao == 2) {
                        printf("\n=============================");
                        printf("\nCurso removido do sistema com sucesso!");
                        printf("\n=============================");
                        printf("\n");
                    }
                    else {
                        printf("\nA opção inserida é inválida.");
                    }
                }
                break;
            case 4:
                printf("\nVoce selecionou 4");
                break;
            default:
                ImprimirMensagemDeErro();
                break;
        }
    }
    else {
        MensagemErroAloca();
    }
}

void submenuMatricula(struct matricula matriculas[], struct aluno alunos[], struct curso cursos[]) {
    int opcao, quantMatriculas = 0, quantAlunos = 0, quantCursos = 0, i, posicao, resultado;
    char *cpf, *codigo;

    if(matriculas != NULL && cpf != NULL && codigo != NULL) {
        printf("\n=============================");
        printf("\nSubmenu de Matrícula");
        submenu(&opcao);
        switch(opcao) {
            case 1:
                system("clear||cls");
                printf("\n=============================");
                printf("\nTodas as matrículas cadastradas:");
                for(i = 0; i < quantMatriculas; i++) {
                    imprimirMatricula(matriculas, i);
                }
                break;
            case 2:
                printf("\nInforme o cpf do aluno:");
                scanf("%s", cpf);
                printf("\nInforme o código do curso:");
                scanf("%s", codigo);
                posicao = verificarCodigoeCPFMatricula(matriculas, codigo, cpf, quantMatriculas);
                printf("%d", posicao);
                /*if(posicao < 0) {

                }*/
                break;
            case 3:
                system("clear||cls");

                printf("\nIncluindo matrícula no sistema...");
                printf("\n");
                printf("\nInforme o cpf do aluno:");
                scanf("%s", cpf);
                printf("\nInforme o código do curso:");
                scanf("%s", codigo);

                if(verificarCPF(alunos, cpf, quantAlunos) >= 0 && verificarCodigo(cursos, codigo, quantCursos) >= 0) {
                    posicao = verificarCodigoeCPFMatricula(matriculas, codigo, cpf, quantMatriculas);
                    if(posicao < 0) {
                        strcpy(matriculas[quantMatriculas].codigoCurso, codigo);
                        strcpy(matriculas[quantMatriculas].cpfAluno, cpf);
                        free(cpf);
                        free(codigo);

                        resultado = incluirMatricula(matriculas, &quantMatriculas);
                        if(resultado == 1) {
                            printf("\n=============================");
                            printf("\nMatrícula cadastrada com sucesso!");
                            printf("\n=============================");
                            printf("\n");
                        }
                        else {
                            MensagemErroCadastro();
                        }
                    }
                    else {
                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("\nA matrícula inserida já existe no sistema.");
                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("\n");
                    }
                }

                break;
            case 4:
                printf("Alterar ou excluir do sistema");
                break;
            default:
                ImprimirMensagemDeErro();
        }
    }
    else {
        MensagemErroAloca();
    }
}

void Relatorios() {
    int opcao;
    printf("\n=============================");
    printf("Submenu de Relatórios");
    submenuRelatorios(&opcao);
}

void mainMenu() {
    int opcao, opcaoSubmenu, opcaoAlterarExcluir, opcaoSubmenuAlterar;
    int quantAlunos = 0, quantCursos = 0, quantMatriculas, resultado, posicao, i;
    int limiteAlunos = 100, limiteCursos = 50, limiteMatriculas = 200;
    char *cpf, *codigo;
 
    struct aluno *alunos;
    struct curso *cursos;
    struct matricula *matriculas;

    cursos = (struct curso*) malloc (limiteCursos * sizeof(struct curso));
    matriculas = (struct matricula*) malloc (limiteMatriculas * sizeof(struct matricula));
    alunos = leituraAlunos(limiteAlunos, &quantAlunos);

    cpf = (char *) malloc(sizeof (char) * 16); 
    codigo = (char *) malloc(sizeof(char) * 12);

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
            if(cpf != NULL) {
                submenuAlunos(alunos, cpf, &quantAlunos);
            }
            else {
                MensagemErroAloca();
            }
        }
        else if(opcao == 2) {
            submenuCursos(cursos);
        }
        else if(opcao == 3) {
            submenuMatricula(matriculas, alunos, cursos);
        }
        else if(opcao == 4) {
            Relatorios();
        }
        else {
            ImprimirMensagemDeErro();
        }
    }
    while(opcao != 5);
    if(opcao == 5) { 
        system("clear||cls");
        inserirEmArqAlunos(alunos, quantAlunos);
        free(alunos);
        free(cursos);

        printf("\n");
        printf("\n=============================");
        printf("\nEncerrando programa.");
        printf("\n=============================");
    }
}

int main() {
    mainMenu();
}