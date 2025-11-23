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
    char codigoCurso[10], dataInicio[11], dataFim[11], cpfAluno[14];
};

void dataInseridaInvalida() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nData inserida é inválida");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void matriculaRemovidaComSucesso() {
    system("clear||cls");
    printf("\n=============================");
    printf("\nMatrícula removida do sistema com sucesso!");
    printf("\n=============================");
    printf("\n");
}

void alunoRemovidoComSucesso() {
    system("clear||cls");
    printf("\n=============================");
    printf("\nAluno removido do sistema com sucesso!");
    printf("\n=============================");
    printf("\n");   
}

void cursoRemovidoComSucesso() {
    system("clear||cls");
    printf("\n=============================");
    printf("\nCurso removido do sistema com sucesso!");
    printf("\n=============================");
    printf("\n");  
}

void codigoNaoEncontrado() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nCódigo não encontrado no sistema.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void cpfOuCodigoNaoEncontrado() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nCPF/Código de curso não encontrados no sistema");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void nenhumaMatriculaEncontrada() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nNenhuma matrícula encontrada");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void sucessoInserirArqRelatorios() {
    system("clear||cls");
    printf("\n=============================");
    printf("\nDados inseridos no arquivo com sucesso!");
    printf("\n=============================");
    printf("\n");
}

void matriculaNaoEncontrada() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nMatrícula não encontrada");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void naoHaCadastro() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nNão há nenhum cadastro no sistema.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void cpfNaoEncontrado() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nCPF não encontrado no sistema.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void MensagemErroCadastro() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nNão foi possível concluir o cadastro.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void MensagemErroAloca() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nMemória insuficiente");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void ErroNaExclusao() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nErro na exclusão.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void ImprimirMensagemDeErro() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nA opção inserida não é válida, tente novamente.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void mensagemAlterarSucesso() {
    system("clear||cls");
    printf("\n=============================");
    printf("\nDados alterados com sucesso!");
    printf("\n=============================");
    printf("\n");   
}

void mensagemErroAlterar() {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\nErro na alteração de dados");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
}

void NaoFoiPossivelAbrirOArq(FILE *arq) {
    system("clear||cls");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("Não foi possível abrir o arquivo.");
    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n");
    fclose(arq);
    exit(0);
}

int TamanhoArqu(FILE *arq, int limite, int sizeStruct) {
    int quant, tamTotal;
    long tamanho;

    if(fseek(arq, 0, SEEK_END) != 0)  { //move o cursor para o final do arquivo
        return -1; //indica que o arquivo está vazio
    }
    else {
        tamanho = ftell(arq); //retorna o tamanho do arquivo em bytes
        if(tamanho < 0) {
            return -1;
        }
        tamTotal = (int) (tamanho / sizeStruct); //tamTotal vai ter a quantidade de structs que o arquivo contém
        return tamTotal; 
    }
}

void imprimirAlunoRelatorio(struct aluno *alunos, int n) {
    int i;
    printf("\n=============================");
    printf("\nCPF: %s", alunos[n].cpf);
    printf("\n");
    printf("\nNome: %s", alunos[n].nome);
    printf("\n");
    printf("\nE-mails: ");
    for(i = 0; i < alunos[n].quantEmails; i++) {
        printf("\n%s", alunos[n].emails[i]);
    }
    printf("\n=============================");
    printf("\n");
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
    printf("Preço: %f", cursos[n].preco);
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
    printf("\nDesconto: %f", matriculas[n].desconto);
    printf("\n");
    printf("\nData de início: %s", matriculas[n].dataInicio);
    printf("\n");
    printf("\nData de conclusão: %s", matriculas[n].dataFim);
    printf("\n=============================");
    printf("\n");
}

void inserirEmArqCursos(struct curso cursos[], int *quantAdicionados, int quantJaNoArquivo) {
    FILE *arq;
    arq = fopen("cursos.dat", "ab");
    if(arq == NULL) {
        NaoFoiPossivelAbrirOArq(arq);
    }

    if(*quantAdicionados > 0) {
        if((fwrite(cursos + quantJaNoArquivo, sizeof(struct curso), *quantAdicionados, arq)) != *quantAdicionados) {
            printf("\nErro na escrita");
            fclose(arq);
            exit(0);
        } 
    }
    fclose(arq);
}

void inserirEmArqAlunos(struct aluno alunos[], int *quantAdicionados, int quantJaNoArquivo) { //quant está indicando a posição do elemento que vai ser gravado no arquivo
    FILE *arq;
    arq = fopen("alunos.dat", "ab"); //arq binário 
    //A partir de que elemento do vetor é necessário gravar no arquivo
    //quantJaNoArquivo = índice de onde começar a pegar pra gravar

    if(arq == NULL) {
        printf("\nNão foi possível abrir o arquivo.");
        fclose(arq);
        exit(0);
    }
    if(*quantAdicionados > 0) {
        if((fwrite(alunos + quantJaNoArquivo, sizeof(struct aluno), *quantAdicionados, arq)) != *quantAdicionados) { 
            printf("\nErro na escrita");
            fclose(arq);
            exit(0);
        } 
    }
    fclose(arq);
}

void inserirEmArqMatricula(struct matricula matriculas[], int *quantAdicionados, int quantJaNoArquivo) {
    FILE *arq;
    arq = fopen("matriculas.dat", "ab"); 
    if(arq == NULL) {
        NaoFoiPossivelAbrirOArq(arq);
    }

    if(*quantAdicionados > 0) {
        if((fwrite(matriculas + quantJaNoArquivo, sizeof(struct matricula), *quantAdicionados, arq)) != *quantAdicionados) {
            printf("\nErro na escrita");
            fclose(arq);
            exit(0);
        } 
    }
    fclose(arq);
}

int gravarRelatorioPorData(struct curso *cursos, int *listaPosicoes, int TamanhoLista, char *dataIni, char *dataFim) {
    FILE *arq;
    int i = 0;
    arq = fopen("relatorioPorData.txt", "a");

    if(arq != NULL) {
        fprintf(arq, "\n---------------------------------\n");
        fprintf(arq, "\nRelatório de cursos entre as datas:");
        fprintf(arq, "\nData de início: %s", dataIni);
        fprintf(arq, "\nData de fim: %s", dataFim);
        fprintf(arq, "\n---------------------------------");

        if(TamanhoLista == 0) {
            fprintf(arq, "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            fprintf(arq, "\nNenhuma matrícula encontrada no período procurado.");
            fprintf(arq, "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            fprintf(arq, "\n");
        }

        else {
            for(i = 0; i < TamanhoLista; i++) {
                fprintf(arq, "\nCódigo: %s", cursos[listaPosicoes[i]].codigo);
                fprintf(arq, "\nDescrição: %s", cursos[listaPosicoes[i]].descricao);
                fprintf(arq, "\nCarga horária: %.2f", cursos[listaPosicoes[i]].cargaHoraria);
                fprintf(arq, "\nPreço: %.2f", cursos[listaPosicoes[i]].preco);
                fprintf(arq, "\n---------------------------------");
                fprintf(arq, "\n");
            }
            sucessoInserirArqRelatorios();
        }
    }
    else {
        MensagemErroAloca();
    }
}

int gravarRelatorioPorCodigo(struct aluno *alunos, int *listaPosicoes, int tamanhoLista, char *codigo) { 
    int i, j;
    FILE *arq;
    arq = fopen("relatorioPorCodigo.txt", "a");

    if(arq != NULL) {
        fprintf(arq, "\n---------------------------------");
        fprintf(arq, "\nRelatório de alunos matriculados em um curso");
        fprintf(arq, "\nCódigo: %s", codigo);
        fprintf(arq, "\n---------------------------------");
        
        if(tamanhoLista > 0) {
            for(i = 0; i < tamanhoLista; i++) {
                fprintf(arq, "\nCPF: %s", alunos[listaPosicoes[i]].cpf);
                fprintf(arq, "\nNome: %s", alunos[listaPosicoes[i]].nome);
                fprintf(arq, "\nE-mails:");
                for(j = 0; j < alunos[listaPosicoes[i]].quantEmails; j++) {
                    fprintf(arq, "\n%s", alunos[listaPosicoes[i]].emails[j]);
                }
                fprintf(arq, "\n---------------------------------");
                fprintf(arq, "\n");
            }
            sucessoInserirArqRelatorios();
        }
        else {
            fprintf(arq, "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            fprintf(arq, "\nNenhuma matrícula encontrada");
            fprintf(arq, "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            fprintf(arq, "\n");
        }
    }
    else {
        MensagemErroAloca();
    }
}

int gravarRelatorioPorCPF(struct curso *cursos, int *listaPosicoes, int tamanhoLista, char *cpf) { //cursos que um cpf está matriculado
    int i;
    FILE *arq;
    arq = fopen("relatorioPorCPF.txt", "a");

    if(arq != NULL) {
        fprintf(arq, "\n---------------------------------");
        fprintf(arq, "\nRelatório de cursos em que o cpf está matriculado");
        fprintf(arq, "\nCPF: %s", cpf);
        fprintf(arq, "\n---------------------------------");

        if(tamanhoLista > 0) {
            for(i = 0; i < tamanhoLista; i++) {
                fprintf(arq, "\nCódigo: %s", cursos[listaPosicoes[i]].codigo);
                fprintf(arq, "\nDescrição: %s", cursos[listaPosicoes[i]].descricao);
                fprintf(arq, "\nCarga Horária: %.2f", cursos[listaPosicoes[i]].cargaHoraria);
                fprintf(arq, "\nPreço: %.2f", cursos[listaPosicoes[i]].preco);
                fprintf(arq, "\n---------------------------------");
                fprintf(arq, "\n");
            }
            sucessoInserirArqRelatorios();
        }
        else {
            fprintf(arq, "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            fprintf(arq, "\nNenhuma matrícula encontrada");
            fprintf(arq, "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            fprintf(arq, "\n");
        }
    }
    else {
        MensagemErroAloca();
    }
}

int sobrescreverArqAlunos(struct aluno *alunos, int totalAlunos) {
    FILE *arq;
    arq = fopen("alunos.dat", "wb");
    if(arq == NULL) {
        NaoFoiPossivelAbrirOArq(arq);
    }
    else {
       if(fwrite(alunos, sizeof(struct aluno), totalAlunos, arq) != totalAlunos) {
            printf("\nErro na escrita");
            fclose(arq);
            exit(0);
       }
       fclose(arq);
       return 1; //caso dê certo, retorna 1
    }
}

int sobrescreverArqCursos(struct curso *cursos, int total) {
    FILE *arq;
    arq = fopen("cursos.dat", "wb");
    if(arq == NULL) {
        NaoFoiPossivelAbrirOArq(arq);
    }
    else {
       if(fwrite(cursos, sizeof(struct curso), total, arq) != total) {
            printf("\nErro na escrita");
            fclose(arq);
            exit(0);
       }
       fclose(arq);
       return 1; 
    }
}

int sobrescreverArqMatriculas(struct matricula *matriculas, int total) {
    FILE *arq;
    arq = fopen("matriculas.dat", "wb");
    if(arq == NULL) {
        NaoFoiPossivelAbrirOArq(arq);
    }
    else {
       if(fwrite(matriculas, sizeof(struct matricula), total, arq) != total) {
            printf("\nErro na escrita");
            fclose(arq);
            exit(0);
       }
       fclose(arq);
       return 1; 
    }
}

struct aluno *leituraAlunos(int limiteAlunos, int *quantAlunos) {
    FILE *arq;
    int tamanhoArquivo, lidos;
    struct aluno *alunos;

    arq = fopen("alunos.dat", "ab+");
    if(arq == NULL) {
        *quantAlunos = 0;
        NaoFoiPossivelAbrirOArq(arq);
    }

    tamanhoArquivo = TamanhoArqu(arq, limiteAlunos, sizeof(struct aluno));
    alunos = (struct aluno*) malloc ((limiteAlunos + (int) tamanhoArquivo) * sizeof(struct aluno));

    rewind(arq);
    lidos = fread(alunos, sizeof(struct aluno), tamanhoArquivo, arq); 

    if(alunos == NULL) {
        MensagemErroAloca();
    }

    if(lidos != tamanhoArquivo) {
        printf("\nErro na leitura do arquivo.");
        system("pause");
        fclose(arq);
        exit(0);
    }

    fclose(arq);
    *quantAlunos = (int) lidos;
    return alunos;
}

struct curso *leituraCursos(int limiteCursos, int *quantCursos) { //Lê os dados de arquivo texto e imprime
    FILE *arq;
    int tamanhoArquivo, lidos;
    struct curso *cursos;
    
    arq = fopen("cursos.dat", "ab+");
    if(arq == NULL) {
        *quantCursos = 0;
        NaoFoiPossivelAbrirOArq(arq);
    }

    tamanhoArquivo = TamanhoArqu(arq, limiteCursos, sizeof(struct curso));
    cursos = (struct curso*) malloc ((limiteCursos + (int) tamanhoArquivo) * sizeof(struct curso));

    rewind(arq);
    lidos = fread(cursos, sizeof(struct curso), tamanhoArquivo, arq);

    if(cursos == NULL) {
        MensagemErroAloca();
    }

    if(lidos != tamanhoArquivo) {
        printf("\nErro na leitura do arquivo.");
        system("pause");
        fclose(arq);
        exit(0);
    }

    fclose(arq);
    *quantCursos = (int) lidos;
    return cursos;
}

struct matricula *leituraMatriculas(int limiteMatriculas, int *quantMatriculas) {
    FILE *arq;
    int tamanhoArquivo, lidos;
    struct matricula *matriculas;
    
    arq = fopen("matriculas.dat", "ab+");
    if(arq == NULL) {
        *quantMatriculas = 0;
        NaoFoiPossivelAbrirOArq(arq);
    }

    tamanhoArquivo = TamanhoArqu(arq, limiteMatriculas, sizeof(struct matricula));
    matriculas = (struct matricula*) malloc ((limiteMatriculas + (int) tamanhoArquivo) * sizeof(struct matricula));

    rewind(arq);
    lidos = fread(matriculas, sizeof(struct matricula), tamanhoArquivo, arq);

    if(matriculas == NULL) {
        MensagemErroAloca();
    }

    if(lidos != tamanhoArquivo) {
        printf("\nErro na leitura do arquivo.");
        system("pause");
        fclose(arq);
        exit(0);
    }

    fclose(arq);
    *quantMatriculas = (int) lidos;
    return matriculas;
}

int excluirAluno(struct aluno alunos[], int posicaoExcluir, int *totalAlunos) {
    int i, j;
    for(i = posicaoExcluir; i < *totalAlunos; i++) {
        strcpy(alunos[i].cpf, alunos[i+1].cpf);
        strcpy(alunos[i].dataNascimento, alunos[i+1].dataNascimento);
        strcpy(alunos[i].nome, alunos[i+1].nome);
        alunos[i].sexo = alunos[i+1].sexo;
        alunos[i].quantEmails = alunos[i+1].quantEmails;
        alunos[i].quantTelefones = alunos[i+1].quantTelefones;
        for(j = 0; j < alunos[i+1].quantEmails; j++) {
            strcpy(alunos[i].emails[j], alunos[i+1].emails[j]);
        }
        for(j = 0; j < alunos[i+1].quantTelefones; j++) {
            strcpy(alunos[i].telefones[j], alunos[i+1].telefones[j]);
        }
    }
    (*totalAlunos)--;
    return 1;
}

int excluirCurso(struct curso cursos[], int posicaoExcluir, int *totalCursos) {
    int i;
    for(i = posicaoExcluir; i < *totalCursos; i++) {
        strcpy(cursos[i].codigo, cursos[i+1].codigo);
        strcpy(cursos[i].descricao, cursos[i+1].descricao);
        cursos[i].cargaHoraria = cursos[i+1].cargaHoraria;
        cursos[i].preco = cursos[i+1].preco;
    }
    (*totalCursos)--;
    return 1;
}

int excluirMatricula(struct matricula matriculas[], int posicaoExcluir, int *totalMatriculas) {
    int i;
    for(i = posicaoExcluir; i < *totalMatriculas; i++) {
        matriculas[i].desconto = matriculas[i+1].desconto;
        strcpy(matriculas[i].dataInicio, matriculas[i+1].dataInicio);
        strcpy(matriculas[i].dataFim, matriculas[i+1].dataFim);
    }
    (*totalMatriculas)--;
    return 1;
}

void *realocarMemoria(void *vetor, int *limite, int tamanhoElemento) {
    int novoLimite = 2 * (*limite);
    void *novoVetor = realloc(vetor, novoLimite * tamanhoElemento);

    if(novoVetor == NULL) {
        MensagemErroAloca();
    }
    *limite = novoLimite; //atualizar o valor de comparação
    return novoVetor;
}

int verificarFormatoDaData(int dia, int mes, int ano) {
    if(dia > 31 || mes > 12 || ano > 2026) {
        return 0;
    }
    return 1;
}

int transformarDataEmInt(char *data, int *dia, int *mes, int *ano) {
    int i = 0;
    char *copiaData;
    char *token;
    copiaData = (char *) malloc (11 * sizeof(char));

    strcpy(copiaData, data);
    token = strtok(copiaData, "/");

    while(token != NULL && i < 3) {
        if(i == 0) {
            *dia = atoi(token);
            //printf("\nDia: %d", *dia);
        }
        else if(i == 1) {
            *mes = atoi(token);
            //printf("\nMês: %d", *mes);
        }
        else if(i == 2) {
            *ano = atoi(token);
            //printf("\nAno: %d", *ano);
        }
        token = strtok(NULL, "/"); //continue de onde você parou
        i++;
    }
    if(verificarFormatoDaData(*dia, *mes, *ano) == 1) {
        free(copiaData);
        return 1;
    }
    free(copiaData);
    return 0;
}

int incluirAluno(struct aluno *listaAlunos, int *posicao, int *quantAdicionados) {
    int i;
    int dia, mes, ano;
    char *dataNascimento;
    dataNascimento = (char *) malloc (11 * sizeof(char));

    if(dataNascimento != NULL) {
        printf("\nNome: ");
        getchar();
        fgets(listaAlunos[*posicao].nome, sizeof(listaAlunos[*posicao].nome), stdin);
        listaAlunos[*posicao].nome[strcspn(listaAlunos[*posicao].nome, "\n")] = '\0';

        printf("\nData de nascimento (dd/mm/aaaa): ");
        scanf("%10s", dataNascimento);
        
        if(transformarDataEmInt(dataNascimento, &dia, &mes, &ano) == 1) {
            getchar();
            printf("\nSexo: ");
            scanf("%c", &listaAlunos[*posicao].sexo);

            printf("\nInforme a quantidade de e-mails a serem inseridos: ");
            scanf("%d", &listaAlunos[*posicao].quantEmails);
            printf("\nInsira a seguir o(s) e-mail(s) do aluno: ");
            for(i = 0; i < listaAlunos[*posicao].quantEmails; i++) {
                scanf("%s", listaAlunos[*posicao].emails[i]);
            }
            printf("\n");
            printf("\ne-mail(s) inserido(s) com sucesso.");
            printf("\n");

            printf("\nInforme a quantidade de números telefônicos: ");
            scanf("%d", &listaAlunos[*posicao].quantTelefones);
            printf("\nInsira a seguir o(s) telefone(s): ");
            for(i = 0; i < listaAlunos[*posicao].quantTelefones; i++) {
                scanf("%s", listaAlunos[*posicao].telefones[i]);
            }

            printf("\nTelefone(s) inserido(s) com sucesso.");
            printf("\n");

            (*posicao)++;
            (*quantAdicionados)++;
            return 1;
        }
        else {
            dataInseridaInvalida();
            return 0;
        }
    }
    else {
        MensagemErroAloca();
        return 0;
    }
}

int incluirCurso(struct curso listaCursos[], int *posicao, int *quantAdicionados) {
    printf("\nDescrição do curso: ");
    fgets(listaCursos[*posicao].descricao, sizeof(listaCursos[*posicao].descricao), stdin);
    listaCursos[*posicao].descricao[strcspn(listaCursos[*posicao].descricao, "\n")] = '\0';
    printf("\nCarga horária: ");
    scanf("%f", &listaCursos[*posicao].cargaHoraria);
    printf("\nPreço: ");
    scanf("%f", &listaCursos[*posicao].preco);

    (*quantAdicionados)++; //aumenta a quantidade de alunos adicionados nessa sessão
    (*posicao)++; //aumenta na quantidade total de alunos no vetor
    return 1;
}

int incluirMatricula(struct matricula matriculas[], int *posicao, int *quantAdicionados) {
    int dia, mes, ano;
    char *dataInicio, *dataFim;
    dataInicio = (char *) malloc (11 * sizeof(char));
    dataFim = (char *) malloc (11 * sizeof(char));

    if(dataInicio != NULL && dataFim != NULL) {
        printf("\nDesconto:");
        scanf("%f", &matriculas[*posicao].desconto);
        printf("\nData de início: ");
        scanf("%s", dataInicio);
        printf("\nData de conclusão: ");
        scanf("%s", dataFim);
        if(transformarDataEmInt(dataInicio, &dia, &mes, &ano) == 1 && transformarDataEmInt(dataFim, &dia, &mes, &ano) == 1) {
            strcpy(matriculas[*posicao].dataInicio, dataInicio);
            strcpy(matriculas[*posicao].dataFim, dataFim);
            (*quantAdicionados)++;
            (*posicao)++;
            return 1;
        }
        else {
            dataInseridaInvalida();
            return 0;
        }
    }
    else {
        MensagemErroAloca();
        return 0;
    }
}

int verificarCPF(struct aluno listaAlunos[], char *cpf, int *quantAlunos) { 
    int i;
    if(*quantAlunos == 0) {
        return -1;
    }
    else {
        for(i = 0; i < *quantAlunos; i++) {
            if(strcmp(cpf, listaAlunos[i].cpf) == 0) {
                return i;
            }
        }
        return -1; //não foi encontrado
    }
}

int verificarCodigo(struct curso listaCursos[], char *codigo, int *quantCursos) {
    int i;
    if(*quantCursos == 0) {
        return -1; //vetor vazio
    }
    else {
        for(i = 0; i < *quantCursos; i++) {
            if(strcmp(codigo, listaCursos[i].codigo) == 0) {
                return i;
            }
        }
        return -1; //Não vazio, mas codigo não encontrado
    }
}

int verificarCodigoeCPFMatricula(struct matricula matriculas[], char *codigo, char *cpf, int quantMatriculas) {
    int i, j;

    if(quantMatriculas == 0) {
        printf("\nVetor vazio");
        return -2; //vetor vazio 
    }

    else {
        for(i = 0; i < quantMatriculas; i++) {
            if(strcmp(cpf, matriculas[i].cpfAluno) == 0 && strcmp(codigo, matriculas[i].codigoCurso) == 0) {
                return i;
            }
        }
        printf("\nvetor não vazio mas matrícula procurada não existe");
        return -1; //vetor não vazio mas matrícula procurada não existe
    } 
}

int verificarCodigoParaRelatorio(struct aluno *alunos, struct matricula *matriculas, char *codigo, int quantMatriculas, int quantAlunos, int *listaPosicoes) {
    int i, contador = 0, posicao;

    for(i = 0; i < quantMatriculas; i++) {
        if(strcmp(codigo, matriculas[i].codigoCurso) == 0) {
            posicao = verificarCPF(alunos, matriculas[i].cpfAluno, &quantAlunos);
            if(posicao >= 0) {
                listaPosicoes[contador] = posicao;
                contador++;
            }
        }
    }
    return contador;
}

int validarIntervaloDeData(int diaMatricIni, int mesMatricIni, int anoMatricIni, int diaMatricFim, int mesMatricFim, int anoMatricFim, int diaIni, int mesIni, int anoIni, int diaFim, int mesFim, int anoFim) {
    int dataMatricIni = anoMatricIni * 10000 + mesMatricIni * 100 + diaMatricIni;
    int dataMatricFim = anoMatricFim * 10000 + mesMatricFim * 100 + diaMatricFim;
    int dataInicio = anoIni * 10000 + mesIni * 100 + diaIni;
    int dataFim = anoFim * 10000 + mesFim * 100 + diaFim;

    if(dataMatricIni >= dataInicio && dataMatricIni <= dataFim) {
        return 1;
    }

    else if(dataMatricFim >= dataInicio && dataMatricFim <= dataFim) {
        return 1;
    }

    return 0;
}

int verificarDataRelatorio(struct matricula *matriculas, struct curso *cursos, int quantMatriculas, int quantCursos, char *dataInicio, char *dataFim, int *listaPosicoes) {
    //percorrer vetor matriculas e procurar o código de cursos com matrículas ativas entre dataInicio e dataFim
    int contador = 0, i, posicao, dataValida;
    int diaMatriculaFim, mesMatriculaFim, anoMatriculaFim;
    int diaMatriculaIni, mesMatriculaIni, anoMatriculaIni;
    int diaInseridoIni, mesInseridoIni, anoInseridoIni;
    int diaInseridoFim, mesInseridoFim, anoInseridoFim;

    if(transformarDataEmInt(dataInicio, &diaInseridoIni, &mesInseridoIni, &anoInseridoIni) == 1 && transformarDataEmInt(dataFim, &diaInseridoFim, &mesInseridoFim, &anoInseridoFim) == 1) {
        for(i = 0; i < quantMatriculas; i++) {
            if(transformarDataEmInt(matriculas[i].dataInicio, &diaMatriculaIni, &mesMatriculaIni, &anoMatriculaIni) == 1 && transformarDataEmInt(matriculas[i].dataFim, &diaMatriculaFim, &mesMatriculaFim, &anoMatriculaFim) == 1) {
                if(validarIntervaloDeData(diaMatriculaIni, mesMatriculaIni, anoMatriculaIni, diaMatriculaFim, mesMatriculaFim, anoMatriculaFim, diaInseridoIni, mesInseridoIni, anoInseridoIni, diaInseridoFim, mesInseridoFim, anoInseridoFim) == 1) {
                    posicao = verificarCodigo(cursos, matriculas[i].codigoCurso, &quantCursos);
                    if(posicao >= 0) {
                        if(contador > 0 && listaPosicoes[contador - 1] != posicao) {
                            listaPosicoes[contador] = posicao;
                            contador++;
                        }
                        else if(contador == 0) {
                            listaPosicoes[contador] = posicao;
                            contador++;
                        }
                    }
                }   
            }
            else {
                return -1;
            }
        }
    }
    else {
        return -1;
    }
    return contador;
    //para comparar as datas: pegar dia, mês e ano e transformar em int
}

int verificarCpfParaRelatorio(struct matricula *matriculas, struct curso *cursos, int quantMatriculas, int quantCursos, char *cpf, int *listaPosicoes) {
    int i, contador = 0, posicao;
    for(i = 0 ; i < quantMatriculas; i++) {
        if(strcmp(matriculas[i].cpfAluno, cpf) == 0) {
            posicao = verificarCodigo(cursos, matriculas[i].codigoCurso, &quantCursos);
            if(posicao >= 0) {
                listaPosicoes[contador] = posicao;
                contador++;
            }
        }
    }
    return contador;
}

void submenu(int *opcao) {
    printf("\n1- Listar todos");
    printf("\n2- Listar um");
    printf("\n3- Incluir");
    printf("\n4- Alterar e excluir");
    printf("\n5- Sair");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", opcao);
}

int submenuAlterarAluno(struct aluno alunos[], int posicaoAlterar, int *quantTotal) {
    int i, quantEmailsAlterar, opcao, alteracaoFeita = 0;
    do {
        printf("\n=============================");
        printf("\nSubmenu Alterar Aluno");
        printf("\n1- Nome");
        printf("\n2- data de nascimento");
        printf("\n3- Sexo");
        printf("\n4- E-mail");
        printf("\n5- Telefone");
        printf("\n6- Sair");
        printf("\n=============================");
        printf("\n");
        printf("\nSelecione uma das opções:");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("\nInsira o nome do aluno:");
                getchar();
                fgets(alunos[posicaoAlterar].nome, sizeof(alunos[posicaoAlterar].nome), stdin);
                alunos[posicaoAlterar].nome[strcspn(alunos[posicaoAlterar].nome, "\n")] = '\0';
                alteracaoFeita = 1;
                break;
            case 2:
                printf("\nInsira a data de nasicmento:");
                printf("\nData de nascimento (dd/mm/aaaa): ");
                scanf("%10s", alunos[posicaoAlterar].dataNascimento);
                alteracaoFeita = 1;
                break;
            case 3:
                getchar();
                printf("\nInsira o gênero do aluno:");
                scanf("%c", &alunos[posicaoAlterar].sexo);
                alteracaoFeita = 1;
                break;
            case 4:
                //procurar e mostrar os emails disponíveis
                printf("\n=============================");
                printf("\nEmails disponíveis:");
                for(i = 0; i < alunos[posicaoAlterar].quantEmails; i++) { //printa as opções de e-mails p/ alterar
                    printf("\n%d- %s", i+1, alunos[posicaoAlterar].emails[i]);
                }
                printf("\n=============================");
                printf("\n");
                printf("\nSelecione uma das opções:");
                scanf("%d", &opcao);
                printf("\n");
                printf("\nInforme o novo e-mail:");
                scanf("%s", alunos[posicaoAlterar].emails[opcao-1]);
                alteracaoFeita = 1;
                break;
            case 5:
                printf("\n=============================");
                printf("\nTelefones disponíveis: ");
                for(i = 0; i < alunos[posicaoAlterar].quantTelefones; i++) {
                    printf("\n%d- %s", i+1, alunos[posicaoAlterar].telefones[i]);
                }
                printf("\n=============================");
                printf("\n");
                printf("\nSelecione uma das opções:");
                scanf("%d", &opcao);
                printf("\n");
                printf("\nInforme o novo telefone:");
                scanf("%s", alunos[posicaoAlterar].telefones[opcao-1]);
                alteracaoFeita = 1;
                break;
            default:
                if(opcao != 6) {
                    ImprimirMensagemDeErro();
                }
        }
    }
    while(opcao != 6);
    if(opcao == 6) {
        return alteracaoFeita;
    }
}

int submenuAlterarCurso(struct curso cursos[], int posicaoAlterar, int *quantTotal) {
    int alterou = 0, opcao;
    do {
        printf("\n============================="); 
        printf("Submenu Alterar Curso");
        printf("\n1- Descrição");
        printf("\n2- Carga horária");
        printf("\n3- Preço");
        printf("\n4- Sair");
        printf("\n============================="); 
        printf("\n");
        printf("\nSelecione uma das opções:");
        scanf("%d", opcao);
        switch(opcao) {
            case 1:
                printf("Altere a descrição do curso:");
                fgets(cursos[posicaoAlterar].descricao, 61, stdin);
                cursos[posicaoAlterar].descricao[strcspn(cursos[posicaoAlterar].descricao, "\n")] = '\0';
                alterou = 1;
                break;
            case 2:
                printf("\nAltere a carga horária:");
                scanf("%f", &cursos[posicaoAlterar].cargaHoraria);
                alterou = 1;
                break;
            case 3:
                printf("\nAltere o preço: ");
                scanf("%f", &cursos[posicaoAlterar].preco);
                alterou = 1;
                break;
            default:
                if(opcao != 4) {
                    ImprimirMensagemDeErro();
                }
        }
    }
    while(opcao != 4);
    if(opcao == 4) {
        return alterou;
    }
}

int submenuAlterarMatricula(struct matricula matriculas[], int posicaoAlterar, int *quantTotal) {
    int alterou = 0, opcao;
    do{
        printf("\n============================="); 
        printf("\n1- Desconto");
        printf("\n2- Data de início");
        printf("\n3- Data de conclusão");
        printf("\n4- Sair");
        printf("\n============================="); 
        printf("\n");
        printf("\nSelecione uma das opções:");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("\nDesconto:");
                scanf("%f", &matriculas[posicaoAlterar].desconto);
                alterou = 1;
                break;
            case 2:
                printf("\nData de início: ");
                scanf("%s", matriculas[posicaoAlterar].dataInicio);
                alterou = 1;
                break;
            case 3:
                printf("\nData de conclusão: ");
                scanf("%s", matriculas[posicaoAlterar].dataFim);
                alterou = 1;
                break;
            default:
            if(opcao != 4) {
                ImprimirMensagemDeErro();
            }
        }
    }
    while(opcao != 4);
    if(opcao == 4) {
        return alterou;
    }
}

void submenuRelatorios(int *opcao) {
    system("clear||cls");
    printf("\n=============================");
    printf("\nSubmenu Relatórios:");
    printf("\n1- Mostrar dados de todos os alunos de um curso"); //percorrer matrículas e procurar um código (pegar todos os cpfs dos alunos que tem matrícula ativa nesse curso)
    printf("\n2- Mostrar os dados de todos os cursos oferecidos entre as datas X e Y"); //dados de todos os cursos entre as datas x e y
    printf("\n3- Mostrar os dados de todos os cursos realizados por um aluno"); //usuário informa o cpf 
    printf("\n4- Sair");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções:");
    scanf("%d", opcao);
}

void submenuAlterarExcluir(int *opcao) {
    system("clear||cls");
    printf("\n=============================");
    printf("\nSubmenu alterar ou excluir");
    printf("\n1- Alterar");
    printf("\n2- Excluir");
    printf("\n3- Sair");
    printf("\n=============================");
    printf("\n");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", opcao);
}

void submenuAlunos(struct aluno alunos[], char *cpf, int *quantTotal, int quantArquivo, int limiteAlunos) {
    int opcao, opcaoSubmenu, posicao, resultado, resultSobrescrever, i;
    int quantAdicionados = 0;

    do{
        system("clear||cls");

        printf("\n=============================");
        printf("\nSubmenu de Alunos");
        submenu(&opcao);
            if(opcao == 1) {
                if(*quantTotal == 0) {
                    naoHaCadastro();
                }
                else {
                    system("clear||cls");

                    printf("\n=============================");
                    printf("\nTodos os alunos cadastrados"); 
                    for(i = 0; i < *quantTotal; i++) {
                        imprimirAluno(alunos, i);
                    }
                }
            }
            else if(opcao == 2) {
                if(*quantTotal > 0) {
                    
                    printf("\nInforme o cpf do aluno:");
                    getchar();
                    fgets(cpf, 15, stdin);
                    cpf[strcspn(cpf, "\n")] = '\0';

                    posicao = verificarCPF(alunos, cpf, quantTotal);
                    if(posicao < 0) {
                        cpfNaoEncontrado();
                    }
                    else {
                        imprimirAluno(alunos, posicao);
                    }
                }
                else {
                    naoHaCadastro();
                }
            }
            else if(opcao == 3) {
                if(*quantTotal == limiteAlunos) {
                    alunos = realocarMemoria(alunos, &limiteAlunos, sizeof(struct aluno));
                }
                system("clear||cls");
                printf("\n=============================");
                printf("\nIncluindo aluno no sistema...");
                printf("\n=============================");
                printf("\n");
                printf("\nInforme o CPF do aluno: ");

                getchar();
                fgets(cpf, 15, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                if(verificarCPF(alunos, cpf, quantTotal) >= 0) {
                    system("clear||cls");

                    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                    printf("\nO CPF inserido já existe no sistema.");
                    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                    printf("\n");
                }
                else {
                    strcpy(alunos[*quantTotal].cpf, cpf);
                    resultado = incluirAluno(alunos, quantTotal, &quantAdicionados); //quantAlunos contém o endereço de memória pro local onde aponta

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
            }  
               
            else if(opcao == 4) {
                do {
                    submenuAlterarExcluir(&opcaoSubmenu);
                    if(opcaoSubmenu != 3) {
                        printf("\nInforme o cpf do aluno:");
                        scanf("%s", cpf);
                        posicao = verificarCPF(alunos, cpf, quantTotal);

                        if(posicao >= 0) {
                            if(opcao == 1) {
                                resultado = submenuAlterarAluno(alunos, posicao, quantTotal);
                                resultSobrescrever = sobrescreverArqAlunos(alunos, *quantTotal);
                                if(resultSobrescrever == 1 && resultado == 1) {
                                    mensagemAlterarSucesso();
                                }
                                else {
                                    mensagemErroAlterar();
                                }
                            }
                            else if(opcaoSubmenu == 2) {
                                if(*quantTotal > 1) {
                                    resultado = excluirAluno(alunos, posicao, quantTotal); //altera o vetor
                                    resultSobrescrever = sobrescreverArqAlunos(alunos, *quantTotal); //altera o arquivo 

                                    if(resultado == 1 && resultSobrescrever == 1) {
                                        alunoRemovidoComSucesso();   
                                    }
                                    else {
                                        ErroNaExclusao();
                                    }
                                }
                                else if(*quantTotal == 1) {
                                    if(remove("alunos.dat") == 0 && excluirAluno(alunos, 0, quantTotal) == 1) {
                                        alunoRemovidoComSucesso();
                                    }
                                    else {
                                        ErroNaExclusao();
                                    }
                                }
                            }
                            else {
                                ImprimirMensagemDeErro();
                            }
                        }
                        else {
                            cpfNaoEncontrado();
                        }   
                    }
                }
                while(opcaoSubmenu != 3);
            }

            else {
                ImprimirMensagemDeErro();
            }
    }
    while(opcao != 5);
    if(opcao == 5) {
        inserirEmArqAlunos(alunos, &quantAdicionados, quantArquivo); //liberar o local da memória
        system("clear||cls");

        printf("\n=============================");
        printf("\nSaindo do submenu de Alunos");
        printf("\n=============================");
        printf("\n");
    }
}

void submenuCursos(struct curso cursos[], char *codigo, int *quantTotal, int quantArquivo, int limiteCursos) {
    int opcao, i, posicao, resultado, resultSobrescrever;
    int quantAdicionados = 0;

    do{
        system("clear||cls");

        printf("\n=============================");
        printf("\nSubmenu de Cursos:");
        submenu(&opcao);
        if(opcao == 1) {
            if(*quantTotal > 0) {
                system("clear||cls");

                printf("\n=============================");
                printf("\nTodos os cursos cadastrados");
                printf("\n");

                for(i = 0; i < *quantTotal; i++) {
                    imprimirCurso(cursos, i);
                }
            }
            else {
                naoHaCadastro();
            }
        } 
        else if(opcao == 2) {
            if(*quantTotal > 0) {

                printf("\nInforme o código do curso:");
                getchar();
                fgets(codigo, 11, stdin);
                codigo[strcspn(codigo, "\n")] = '\0';

                posicao = verificarCodigo(cursos, codigo, quantTotal);
                
                if(posicao < 0) {
                    codigoNaoEncontrado();
                }
                else {
                    imprimirCurso(cursos, posicao);
                }
            }
            else {
                naoHaCadastro();
            }
        }
        else if(opcao == 3) {
            system("clear||cls");
            printf("\n=============================");
            printf("\nIncluindo curso no sistema...");
            printf("\n=============================");
            printf("\n");
            printf("\nInsira o código do curso: ");
            getchar();
            fgets(codigo, 11, stdin);
            codigo[strcspn(codigo, "\n")] = '\0';  
            
            if(verificarCodigo(cursos, codigo, quantTotal) >= 0) {
                system("clear||cls");

                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\nO código inserido já existe no sistema.");
                printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("\n");
            }
            else {
                if(*quantTotal == limiteCursos) {
                    cursos = realocarMemoria(cursos, &limiteCursos, sizeof(struct curso));
                }
                strcpy(cursos[*quantTotal].codigo, codigo);

                if(incluirCurso(cursos, quantTotal, &quantAdicionados) == 1) { //confirma se o processo de incluir foi terminado
                    system("clear||cls");

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
        else if(opcao == 4) {
            do {
                submenuAlterarExcluir(&opcao);
                if(opcao != 3) {
                    printf("\nInforme o código do curso:");
                    scanf("%s", codigo);
                    posicao = verificarCodigo(cursos, codigo, quantTotal);

                    if(posicao >= 0) {
                        submenuAlterarExcluir(&opcao);
                        if(opcao == 1) {
                            submenuAlterarCurso(cursos, posicao, quantTotal);
                        }
                        else if(opcao == 2) {
                            if(*quantTotal > 1) {
                                resultado = excluirCurso(cursos, posicao, quantTotal); //altera o vetor
                                resultSobrescrever = sobrescreverArqCursos(cursos, *quantTotal); //altera o arquivo 

                                if(resultado == 1 && resultSobrescrever == 1) {
                                    cursoRemovidoComSucesso();   
                                }
                                else {
                                    ErroNaExclusao();
                                }
                            }
                            else if(*quantTotal == 1) {
                                if(remove("cursos.dat") == 0 && excluirCurso(cursos, 0, quantTotal) == 1) {
                                    cursoRemovidoComSucesso();   
                                }
                                else {
                                    ErroNaExclusao();
                                }
                            }
                        }
                        else {
                            ImprimirMensagemDeErro();
                        }
                    }
                    else {
                        codigoNaoEncontrado();
                    }   
                }
            }
            while(opcao != 3);
        }
        else if(opcao < 1 || opcao > 5) {
            ImprimirMensagemDeErro();
        }
    }
    while(opcao != 5);
    if(opcao == 5) {
        inserirEmArqCursos(cursos, &quantAdicionados, quantArquivo); //Quando o submenu for fechado, os dados do vetor vão pro arquivo

        system("clear||cls");

        printf("\n=============================");
        printf("\nSaindo do submenu de Cursos");
        printf("\n=============================");
        printf("\n");
    }
}

void submenuMatricula(struct matricula *matriculas, struct aluno *alunos, struct curso *cursos, int *quantTotalMatriculas, int quantArquivo, int quantAlunos, int quantCursos, char *cpf, char *codigo, int limiteMatriculas) {
    int opcao, quantMatriculasAdd = 0, i, posicao, resultado, resultadoSobrescrever;

    do {
        system("clear||cls");
        printf("\n=============================");
        printf("\nSubmenu de Matrícula");
        submenu(&opcao);
        switch(opcao) {
            case 1:
                if(*quantTotalMatriculas > 0) {
                    system("clear||cls");
                    printf("\n=============================");
                    printf("\nTodas as matrículas cadastradas:");
                    for(i = 0; i < *quantTotalMatriculas; i++) {
                        imprimirMatricula(matriculas, i);
                    }
                }
                else {
                    naoHaCadastro();
                }
                break;
            case 2:
                if(*quantTotalMatriculas > 0) {
                    printf("\nInforme o cpf do aluno:");
                    scanf("%s", cpf);
                    printf("\nInforme o código do curso:");
                    scanf("%s", codigo);
                    if(verificarCPF(alunos, cpf, &quantAlunos) >= 0 && verificarCodigo(cursos, codigo, &quantCursos) >= 0) {
                        posicao = verificarCodigoeCPFMatricula(matriculas, codigo, cpf, *quantTotalMatriculas);
                        if(posicao == -1) {
                            matriculaNaoEncontrada();
                        }
                        else if(posicao == -2) {
                            naoHaCadastro();
                        }
                        else if(posicao >= 0) {
                            imprimirMatricula(matriculas, posicao);
                        }
                    }
                    else {
                        cpfOuCodigoNaoEncontrado();
                    }
                }
                else {
                    naoHaCadastro();
                }
                break;
            case 3:
                system("clear||cls");
                printf("\n=============================");
                printf("\nIncluindo matrícula no sistema...");
                printf("\n=============================");
                printf("\n");
                printf("\nInforme o cpf do aluno:");
                scanf("%s", cpf);
                printf("\nInforme o código do curso:");
                scanf("%s", codigo);

                if(verificarCPF(alunos, cpf, &quantAlunos) >= 0 && verificarCodigo(cursos, codigo, &quantCursos) >= 0) {
                    posicao = verificarCodigoeCPFMatricula(matriculas, codigo, cpf, *quantTotalMatriculas);
                    if(posicao < 0) {
                        if(*quantTotalMatriculas == limiteMatriculas) {
                            matriculas = realocarMemoria(matriculas, &limiteMatriculas, sizeof(struct matricula));
                        }

                        strcpy(matriculas[*quantTotalMatriculas].codigoCurso, codigo);
                        strcpy(matriculas[*quantTotalMatriculas].cpfAluno, cpf);

                        resultado = incluirMatricula(matriculas, quantTotalMatriculas, &quantMatriculasAdd);
                        if(resultado == 1) {
                            system("clear||cls");
                            printf("\n=============================");
                            printf("\nMatrícula cadastrada com sucesso!");
                            printf("\n=============================");
                            printf("\n");
                        }
                        else {
                            MensagemErroCadastro();
                        }
                    }
                    else if(posicao == -1) {
                        matriculaNaoEncontrada();
                    }
                    else {
                        system("clear||cls");
                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("\nA matrícula inserida já existe no sistema.");
                        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("\n");
                    }
                }
                else {
                    cpfOuCodigoNaoEncontrado();
                }
                break;
            case 4:
                do {
                    submenuAlterarExcluir(&opcao);
                    if(opcao != 3) {
                        printf("\nInforme o CPF do aluno: ");
                        scanf("%s", cpf);
                        printf("\nInforme o código do curso: ");
                        scanf("%s", codigo);
                        if(verificarCPF(alunos, cpf, &quantAlunos) >= 0 && verificarCodigo(cursos, codigo, &quantCursos) >= 0) {
                            posicao = verificarCodigoeCPFMatricula(matriculas, codigo, cpf, *quantTotalMatriculas);
                            if(posicao >= 0) {
                                if(opcao == 1) {
                                    resultado = submenuAlterarMatricula(matriculas, posicao, quantTotalMatriculas);
                                    resultadoSobrescrever = sobrescreverArqMatriculas(matriculas, *quantTotalMatriculas);
                                    if(resultado == 1 && resultadoSobrescrever == 1) {
                                        mensagemAlterarSucesso();
                                    }
                                    else {
                                    mensagemErroAlterar(); 
                                    }
                                }
                                else if(opcao == 2) {
                                    if(*quantTotalMatriculas > 1) {
                                        resultado = excluirMatricula(matriculas, posicao, quantTotalMatriculas);
                                        resultadoSobrescrever = sobrescreverArqMatriculas(matriculas, *quantTotalMatriculas);
                                        if(resultado == 1 && resultadoSobrescrever == 1) {
                                            matriculaRemovidaComSucesso();
                                        }
                                        else {
                                            ErroNaExclusao();
                                        }
                                    }
                                    else if(*quantTotalMatriculas == 1) {
                                        if(remove("matriculas.dat") == 0 && excluirMatricula(matriculas, 0, quantTotalMatriculas) == 1) {
                                            matriculaRemovidaComSucesso(); 
                                        }
                                        else {
                                            ErroNaExclusao();
                                        }
                                    }
                                }
                                else {
                                    ImprimirMensagemDeErro();
                                }
                            }
                            else if(posicao == -1) {
                                matriculaNaoEncontrada();
                            }
                            else if(posicao == -2) {
                                naoHaCadastro();
                            }
                        }
                        else {
                            cpfOuCodigoNaoEncontrado();
                        }   
                    }
                }
                while(opcao != 3);
                break;
            default:
                if(opcao != 5) {
                    ImprimirMensagemDeErro();
                }
                else if(opcao == 5) {
                    inserirEmArqMatricula(matriculas, &quantMatriculasAdd, quantArquivo); //Quando o submenu for fechado, os dados do vetor vão pro arquivo

                    system("clear||cls");

                    printf("\n=============================");
                    printf("\nSaindo do submenu de Matriculas");
                    printf("\n=============================");
                    printf("\n");
                }
        }
    }
    while(opcao != 5);
}

void Relatorios(int quantTotalMatriculas, char *cpf, char *codigo, struct matricula *matriculas, struct curso *cursos, struct aluno *alunos, int quantCursos, int quantAlunos) {
    char *dataInicio, *dataFim;
    int opcao, posicao, tamanhoLista, i, resultado;
    int *listaPosicoes;
    listaPosicoes = (int *) malloc (quantTotalMatriculas * sizeof(int));
    dataInicio = (char *) malloc (11 * sizeof(char));
    dataFim = (char *) malloc (11 * sizeof(char));

    if(listaPosicoes != NULL && dataInicio != NULL && dataFim != NULL) {
        do {
            submenuRelatorios(&opcao);

            if(opcao == 1) {
                //verificar se existem cadastros de matrículas
                if(quantTotalMatriculas > 0) {
                    printf("\nInsira o código do curso: ");
                    getchar();
                    fgets(codigo, 11, stdin);
                    codigo[strcspn(codigo, "\n")] = '\0';

                    posicao = verificarCodigo(cursos, codigo, &quantCursos);
                    if(posicao >= 0) {
                        tamanhoLista = verificarCodigoParaRelatorio(alunos, matriculas, codigo, quantTotalMatriculas, quantAlunos, listaPosicoes); //altera a lista 
                        
                        if(tamanhoLista > 0) {
                            system("clear||cls");

                            printf("\n=============================");
                            printf("\n%s", cursos[posicao].descricao);
                            printf("\n=============================");
                            printf("\n");
                            //listar todos os dados dos alunos encontrados
                            for(i = 0; i < tamanhoLista; i++) {
                                imprimirAlunoRelatorio(alunos, listaPosicoes[i]);
                            }
                        }
                        else {
                            naoHaCadastro();
                        }
                        gravarRelatorioPorCodigo(alunos, listaPosicoes, tamanhoLista, codigo);
                    }
                    else {
                       codigoNaoEncontrado(); 
                    }
                }
                else {
                    naoHaCadastro();
                }
            }
            else if(opcao == 2) {
                if(quantTotalMatriculas > 0 ) {
                    system("clear||cls");
                    printf("\nInforme a data de início para o relatório (dd/mm/aaaa): ");
                    scanf("%s", dataInicio);
                    printf("\nInforme a data de fim para o relatório (dd/mm/aaaa): ");
                    scanf("%s", dataFim);

                    tamanhoLista = verificarDataRelatorio(matriculas, cursos, quantTotalMatriculas, quantCursos, dataInicio, dataFim, listaPosicoes);

                    if(tamanhoLista > 0 || tamanhoLista == 0) {
                        if(tamanhoLista > 0) {
                            for(i = 0; i < tamanhoLista; i++) {
                                imprimirCurso(cursos, listaPosicoes[i]);
                            }
                        }
                        else {
                            nenhumaMatriculaEncontrada();
                        }
                        gravarRelatorioPorData(cursos, listaPosicoes, tamanhoLista, dataInicio, dataFim);
                    }
                    else if(tamanhoLista < 0) {
                        dataInseridaInvalida();
                    }
                }
                else {
                    naoHaCadastro();
                }
                
            }
            else if(opcao == 3) {
                if(quantTotalMatriculas > 0) {
                    system("clear||cls");
                    printf("\n=============================");
                    printf("Fazendo relatório por cpf...");
                    printf("\n=============================");
                    printf("\n");
                    printf("\nInsira o cpf do aluno: ");
                    getchar();
                    fgets(cpf, 16, stdin);
                    cpf[strcspn(cpf, "\n")] = '\0';

                    if(verificarCPF(alunos, cpf, &quantAlunos) >= 0) {
                        tamanhoLista = verificarCpfParaRelatorio(matriculas, cursos, quantTotalMatriculas, quantCursos, cpf, listaPosicoes);
                        if(tamanhoLista > 0) {
                            system("clear||cls");

                            for(i = 0; i < tamanhoLista; i++) {
                                imprimirCurso(cursos, listaPosicoes[i]);
                            }
                        }
                        else {
                            nenhumaMatriculaEncontrada();
                        }
                        gravarRelatorioPorCPF(cursos, listaPosicoes, tamanhoLista, cpf);
                    }
                    else {
                        cpfNaoEncontrado();
                    }
                }
                else {
                    naoHaCadastro();
                }
            }
            else if(opcao < 1 || opcao > 4) {
                ImprimirMensagemDeErro();
            }
        }
        while(opcao != 4); 
        if(opcao == 4) {
            free(dataFim);
            free(dataInicio);
            free(listaPosicoes);

            system("clear||cls");

            printf("\n=============================");
            printf("\nSaindo do submenu de Relatórios");
            printf("\n=============================");
            printf("\n");
        }  
    }
    else {
        MensagemErroAloca();
    }
}

void mainMenu() {
    int opcao, opcaoSubmenu, opcaoAlterarExcluir, opcaoSubmenuAlterar;
    int quantAlunosArquivo = 0, quantCursosArquivo = 0, quantMatriculasArquivo = 0, resultado, posicao, i;
    int quantTotalAlunos = 0, quantTotalCursos = 0, quantTotalMatriculas = 0;
    int limiteAlunos = 100, limiteCursos = 50, limiteMatriculas = 200;
    char *cpf, *codigo;
 
    struct aluno *alunos;
    struct curso *cursos;
    struct matricula *matriculas;

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
            alunos = leituraAlunos(limiteAlunos, &quantAlunosArquivo); //quantAlunos = quant de coisas no arquivo 

            quantTotalAlunos = quantAlunosArquivo;

            if(cpf != NULL) {
                submenuAlunos(alunos, cpf, &quantTotalAlunos, quantAlunosArquivo, limiteAlunos);
                free(alunos);
                free(cpf);
            }
            else {
                MensagemErroAloca();
            }
        }
        else if(opcao == 2) {
            codigo = (char *) malloc(sizeof(char) * 12);
            cursos = leituraCursos(limiteCursos, &quantCursosArquivo);
            
            quantTotalCursos = quantCursosArquivo;

            if(codigo != NULL) {
                submenuCursos(cursos, codigo, &quantTotalCursos, quantCursosArquivo, limiteCursos);
                free(cursos); 
                free(codigo);
            }
            else {
                MensagemErroAloca();
            }
        }
        else if(opcao == 3 || opcao == 4) {
            codigo = (char *) malloc(sizeof(char) * 12);
            cpf = (char *) malloc(sizeof (char) * 16); 
            alunos = leituraAlunos(limiteAlunos, &quantAlunosArquivo);
            cursos = leituraCursos(limiteCursos, &quantCursosArquivo);
            matriculas = leituraMatriculas(limiteMatriculas, &quantMatriculasArquivo);

            quantTotalAlunos = quantAlunosArquivo;
            quantTotalCursos = quantCursosArquivo;
            quantTotalMatriculas = quantMatriculasArquivo;

            if(opcao == 3) {
                if(matriculas != NULL && alunos != NULL && cursos != NULL) {
                submenuMatricula(matriculas, alunos, cursos, &quantTotalMatriculas, quantMatriculasArquivo, quantTotalAlunos, quantTotalCursos, cpf, codigo, limiteMatriculas);
                free(cursos); 
                free(alunos);
                free(matriculas);
                free(cpf);
                free(codigo);
                }
                else {
                    MensagemErroAloca();
                }
            }
            else if(opcao == 4) {
                Relatorios(quantTotalMatriculas, cpf, codigo, matriculas, cursos, alunos, quantTotalCursos, quantTotalAlunos);
                free(cursos); 
                free(alunos);
                free(matriculas);
                free(cpf);
                free(codigo);
            }
        }
        else if(opcao > 5 || opcao <= 0) {
            ImprimirMensagemDeErro();
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