#include <stdio.h> // Inclui a biblioteca padr�o de entrada e saida
#include <string.h> // Inclui a biblioteca para manipula��o de strings
#include <locale.h> // Inclui a biblioteca para configura��o de localidade
#include <stdlib.h>  // Inclui a biblioteca para funcionalidaes utilitarias
#include <windows.h> // Inclui a biblioteca para fun��es espec�ficas do Windows


// Estrutura para armazenar informa��eses de um aluno
typedef struct {
    char nome [80]; // Nome do aluno
    char curso [80]; // Curso do aluno
    char disciplinas [10][80]; // Lista de disciplinas (m�ximo de 10)
    char matriculaAluno[20];   // Matr�cula do aluno
    int periodo,quantdisciplinas;//Per�odo em que o aluno est�, tempo disponivel para estudo em minutos, N�mero de quest�es que o aluno deseja responder, Quantidade de disciplinas cadastradas
} Aluno;

//Estrutura para armazenar informa��es do gerar cronograma
typedef struct {
    char disciplinas[10][80];
    int quantdisciplinas;
    int tempoDisponivel;
    int questoesPorEstudo;
} Cronograma;

// Estrutura para armazenar informa��es de uma quest�o
typedef struct {
    char materia [80]; // Mat�ria da quest�o
    char enunciado[250]; // Enunciado da quest�o
    char alternativas[5][1000];// Alternativas de resposta (m�ximo de 5)
    char resposta [100];    // Resposta correta (armazenada como string)
    int quantQuest;  // Quantidade total de quest�es
    int totQuest;// contador total quest�es
   
} Questao;

// Estrutura para armazenar informa��es de um monitor
typedef struct{
    char nome [80]; // Nome do monitor
    char horario[80]; // Hor�rio disponivel do monitor
    char telefone[80];  // Telefone de contato do monitor
    int quant; // Quantidade de monitores
} Monitor;

// Fun��o para exibir uma linha separadora no console
void mostrarlinha(){
    printf("\n-------------------------------\n");
}

// Fun��o para cadastrar um aluno
void cadastrarAluno(Aluno *aluno){ 
    

    int contstring;
    //FILE *consulta;
    do{
        printf("Nome do Aluno: ");
        fgets(aluno -> nome, 50, stdin); // Linha a linha de entrada para o nome do aluno
        contstring = strlen(aluno->nome);  // Obtem o comprimento da string
        if(contstring <=1 ){
            printf("Nome invalido! Quantidade m�nima 1 caractere.\n");
        }
    }while(contstring <= 1);  // Garante que o nome tenha pelo menos um caractere
    aluno -> nome[strcspn(aluno -> nome, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(600); // Pausa a execu��o por 600 milissegundos
    do{
        printf("Digite sua matr�cula: ");
        fgets(aluno->matriculaAluno,20,stdin);  
        contstring = strlen(aluno->matriculaAluno);// Obtem o comprimento da string
        if(contstring != 11){
            printf("Matr�cula invalida!\n");
        }
    }while(contstring != 11);//Garante que a matricula tenha pelo menos 10 caracteres
    aluno -> matriculaAluno[strcspn(aluno -> matriculaAluno, "\n")] = '\0'; // Remove a nova linha do final da string
    Sleep(500); // Pausa a execu��o por 500 milissegundos

    // Captura o curso do aluno

    do{
        printf("Curso: ");
        fgets(aluno -> curso, 50, stdin);// L� a entrada do usu�rio
        contstring = strlen(aluno->curso);
        if(contstring <= 1){
            printf("Curso invalido! Quantidade m�nima 1 caractere.\n");
        }
    }while(contstring <= 1); //garantindo que n�o seja vazio
    aluno -> curso[strcspn(aluno -> curso, "\n")] = '\0';// Remove a nova linha do final da string
    Sleep(500);// Pausa a execu��o por 500 milissegundos

    // Captura o per�odo em que o aluno est�, garantindo que esteja entre 1 e 16

    do{
        printf("Periodo: ");
        scanf("%d", &aluno -> periodo);
        getchar(); // Limpa o buffer de entrada
        if (aluno->periodo < 1 || aluno->periodo > 12 ){
            printf("Periodo invalido! Digite um perido entre 1 e 12.\n");
        }
    }while(aluno->periodo < 1 || aluno->periodo > 12); // Garante que o per�odo esteja entre 1 e 12

    // Captura a quantidade de disciplinas, garantindo um valor entre 1 e 10

    do{
        printf("Quantidade de disciplinas MAX 10: ");
        scanf("%i",&aluno->quantdisciplinas);// L� a entrada do usu�rio
        getchar();
     } while (aluno->quantdisciplinas > 10 || aluno->quantdisciplinas < 1); // Garante que a quantidade esteja entre 1 e 10

    for(int i = 0; i < aluno->quantdisciplinas; i++){
        Sleep(500); // Pausa a execu��o para melhorar a experi�ncia do usu�rio
        do{
            printf("Disciplina %d: ", i + 1); 
            fgets(aluno -> disciplinas[i], 80, stdin); // L� a entrada do nome da disciplina
            contstring = strlen(aluno->disciplinas[i]);
            if(contstring <= 1){
                printf("Disciplina invalida! Quantidade m�nima 1 caractere.\n");
            }
        }while(contstring <= 1);
        aluno -> disciplinas[i] [strcspn(aluno -> disciplinas[i], "\n")] = '\0'; // Remove a nova linha do final da string
    }
    Sleep(500); // Pausa a execu��o por 500 milissegundos

   
    printf("Cadastrando...\n");  // Mensagem de cadastro e grava��o dos dados em arquivos
    Sleep(2000); // Pausa para simular o tempo de cadastro
    printf("Aluno cadastrado.");
    Sleep(1000); // Pausa a execu��o por 1 segundo
    
     // Cria e abre um arquivo com o nome do aluno (matr�cula) para escrita
    FILE *alunotxt = fopen(aluno->matriculaAluno ,"w");
   
     // Escreve os dados do aluno no arquivo
    fprintf(alunotxt, "Nome: %s\n", aluno->nome);//fun��o fprintf serve para escrever o nome do aluno no arquivo
    fprintf(alunotxt, "Matricula: %s\n", aluno->matriculaAluno);
    fprintf(alunotxt, "Curso: %s\n", aluno->curso);//fun��o fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(alunotxt, "Periodo: %d\n", aluno->periodo);//fun��o fprintf serve para escrever o periodo que o aluno esta
    fprintf(alunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//fun��o fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar os nomes das disciplinas
        fprintf(alunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }

    fclose(alunotxt);  // Escreve os dados do aluno no arquivo

    // Escreve os dados do aluno no arquivo
    FILE *nomealunotxt = fopen("cadastroaluno.txt","a");
   

    fprintf(nomealunotxt, "Nome: %s\n", aluno->nome);//fun��o fprintf serve para escrever o nome do aluno no arquivo
    fprintf(nomealunotxt, "Matricula: %s\n", aluno->matriculaAluno);
    fprintf(nomealunotxt, "Curso: %s\n", aluno->curso);//fun��o fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(nomealunotxt, "Periodo: %d\n", aluno->periodo);//fun��o fprintf serve para escrever o periodo que o aluno esta
    fprintf(nomealunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//fun��o fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar o nome das disciplinas
        fprintf(nomealunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }
    
    fclose(nomealunotxt);  // Fecha o arquivo e salva
}

void gerarCronograma(Cronograma *cronograma){
    int contstring;
    FILE *lista;
    char buffer[250];
    char buffer1[250];
    printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
    lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
    while (fgets(buffer, sizeof(buffer), lista)) {
            printf("%s", buffer);
    }
        fclose(lista);   // Fecha o arquivo apois a leitura
    do{
        printf("Quantidade de disciplinas que deseja estudar MAX 10: ");
        scanf("%i",&cronograma->quantdisciplinas);// L� a entrada do usu�rio
        getchar();
     } while (cronograma->quantdisciplinas > 10 || cronograma->quantdisciplinas < 1); // Garante que a quantidade esteja entre 1 e 10
    int materia_ja_cadastrada = 0; // incia o contador de materia cadastrada
    FILE *listatxt = fopen("listamaterias.txt", "r"); // Abre o arquivo para leitura
    if (listatxt == NULL) { // Se o arquivo n�o existir ( NULL) ele ira entrar na condi��o e criar
        listatxt = fopen("listamaterias.txt", "a"); //Abre o arquivo para escrita caso n�o exista ele cria
    }
    fclose(listatxt); // fecha e salva o arquivo
    for(int i = 0; i < cronograma->quantdisciplinas; i++){
        Sleep(500); // Pausa a execu��o para melhorar a experi�ncia do usu�rio
        do{
            printf("Disciplina %d: ", i + 1); 
            fgets(cronograma -> disciplinas[i], 80, stdin); // L� a entrada do nome da disciplina
            cronograma -> disciplinas[i] [strcspn(cronograma -> disciplinas[i], "\n")] = '\0'; // Remove a nova linha do final da string
            contstring = strlen(cronograma->disciplinas[i]);
            if (contstring <= 1){
                printf("Discplina invalida! Quantidade m�nima 1 caractere.\n");
            }
            
        
     FILE *listaTxt = fopen("listamaterias.txt", "r"); //abre o arquivo para leitura
     // percorre todas as linhas para verificar se a mat�ria j� existe
    while (fgets(buffer, sizeof(buffer), listaTxt)) { 
        buffer[strcspn(buffer, "\n")] = 0;  // Remove o '\n' para fazer a compara��o corretamente
        if (strcmp(buffer, cronograma->disciplinas[i]) == 0) { // compara o buffer que foi lido pelo while e a materia do cadastro se as strings s�o iguais
            materia_ja_cadastrada = 1; // caso a fun��o strcmp retorne verdadeiro(== 0 ) Significa que a materia ja esta no arquivo listamaterias.txt 
            break;  // Se a mat�ria j� foi encontrada, n�o precisa continuar o loop
        }
    }

    // Se a mat�ria n�o foi encontrada
    if (materia_ja_cadastrada == 0) { // se o contador de materias for = 0 
        printf("Diciplina n�o cadastrada no banco de dados\n"); // imprime a materia no arquivo
    }

    fclose(listaTxt); // Fecha o arquivo ap�s a opera��o
        
    
       
        }while(contstring <= 1 || materia_ja_cadastrada == 0);

    }
    Sleep(500); // Pausa a execu��o por 500 milissegundos
    do{
        printf("Tempo disponivel para estudo (em minutos): ");
        scanf("%d", &cronograma -> tempoDisponivel);// L� a entrada do usu�rio
        getchar(); // Limpa o buffer de entrada
        if(cronograma->tempoDisponivel <= 0 || cronograma->tempoDisponivel > 1440){
           printf("Prezamos pela sua sa�de! Tempo m�ximo de estudo 1440 minutos(24hrs)\n"); 
        }
    }while(cronograma->tempoDisponivel <= 0 || cronograma->tempoDisponivel > 1440);// Garante que o tempo esteja entre 1 minuto e 24 horas (1440 minutos)
    Sleep(500);
    do{
        printf("Quantidade de quest�es que deseja responder ao t�rmino do estudo: ");
        scanf("%d", &cronograma -> questoesPorEstudo);// L� a entrada do usu�rio
        getchar();
        if(cronograma->questoesPorEstudo <=0 || cronograma->questoesPorEstudo > 1000){
            printf("M�nimo de questoes 1 e m�ximo de quest�es 1000.\n");
        }
    }while(cronograma->questoesPorEstudo <=0 || cronograma->questoesPorEstudo > 1000); // Garante que a quantidade esteja entre 1 e 1.00
    Sleep(500); // Pausa a execu��o por 500 milissegundos

    // Calcula o tempo dispon�vel para estudo por disciplina
    int tempoPorDisciplina = cronograma->tempoDisponivel / cronograma->quantdisciplinas;
    Sleep(500);

    printf("Cronograma de Estudo para o aluno:\n");
    for (int i = 0; i < cronograma->quantdisciplinas; i++){  // Loop para mostrar o tempo de estudo para cada disciplina
        Sleep(500);
        printf("Disciplina: %s = %d minutos de estudo\n", cronograma->disciplinas[i], tempoPorDisciplina);
    }
    Sleep(500);
    printf("Resolu��o de quest�es: %d quest�es por diciplina\n", cronograma->questoesPorEstudo / cronograma->quantdisciplinas);// Exibe a quantidade de quest�es que o aluno deseja resolver
    Sleep(1000);
}

void cadastrarQuestao(Questao * questao){
    char buffer[255];
    int contstring; // Vari�vel para contar o comprimento das strings
    Sleep(500); // Pausa para melhorar a experi�ncia do usu�rio

    // Captura a mat�ria da quest�o

    do{
    printf("Mat�ria: ");
    fgets(questao -> materia, 80, stdin);// L� a entrada do usu�rio
    contstring = strlen(questao->materia);// Armazena o comprimento da mat�ria
    if(contstring <= 1){
        printf("Mat�ria invalida! Quantidade m�nima 1 caractere.\n");
    }
    }while(contstring <= 1); //Continua pedindo se a entrada estiver vazia
    questao -> materia[strcspn(questao -> materia, "\n")] = '\0';// Remove a nova linha do final da string
    Sleep(600); // Pausa para melhorar a experi�ncia do usu�rio
    // Captura o enunciado da quest�o

    do{
        printf("Enunciado da quest�o: ");
        fgets(questao -> enunciado, 250, stdin); // L� a entrada do usu�rio
        contstring = strlen(questao->enunciado); // Verifica o comprimento do enunciado
        if (contstring <= 1){
           printf("Enunciado invalido! Quantidade m�nima 1 caractere.\n");
        }
        
    }while(contstring <= 1); // Continua pedindo se a entrada estiver vazia
    questao -> enunciado[strcspn(questao -> enunciado, "\n")] = '\0'; // Remove a nova linha do final da string
    Sleep(500);  // Pausa para melhorar a experi�ncia do usu�rio    

    // Captura as alternativas da quest�o

    for(int i=0; i < 5;i++){ 
        do{
            printf("Alternativa %i: ",i+1); 
            fgets(questao -> alternativas[i], 100, stdin);  // L� a alternativa
            contstring = strlen(questao->alternativas[i]); // Verifica o comprimento da alternativa
            if (contstring <=1){
                printf("Alternativa invalida! Quantidade m�nima 1 caractere.\n");
            }   
        }while(contstring <= 1) ; // Continua pedindo se a entrada estiver vazia
    }

    // Captura a resposta correta
    int respostaCorreta = 0;// inicializa em 0
    do{
        printf("N�mero da quest�o correta(1 a 5): ");
        fgets(questao -> resposta, 100, stdin);// L� a resposta correta
        respostaCorreta = atoi(questao->resposta);// converte a string para int
    }while(respostaCorreta < 1 || respostaCorreta > 5); // Continua pedindo at� ser digitado o n�mero valido
  

    
    questao -> resposta[strcspn(questao -> resposta, "\n")] = '\0'; // Remove a nova linha da resposta
    Sleep(500); // Pausa para melhorar a experi�ncia do usu�rio
    printf("Cadastrando...\n");
    Sleep(1000);// Pausa para simular o tempo de cadastro
    printf("Quest�o cadastrada com Sucesso.");
    Sleep(1000);// Pausa para simular o tempo de cadastro

     // Abre o arquivo para armazenar a quest�o cadastrada
    FILE * questaotxt = fopen(questao->materia,"a"); // Grava a mat�ria no arquivo
    fprintf(questaotxt, "Mat�ria: %s\n",questao->materia);
    fprintf(questaotxt,"Enunciado da quest�o: %s\n",questao->enunciado);
    for(int i=0; i <5; i++){
        fprintf(questaotxt,"Alternativa %i: ",i+1);
        fprintf(questaotxt,"%s",questao->alternativas[i]);
    }
    fprintf(questaotxt,"%s\n",questao->resposta);//Vai imprimir no banco de dados apenas o n�mero da resposata, assim facilitando na hora da compara��o
    
    fclose(questaotxt);  // Fecha o arquivo apois a escrita

    FILE *listatxt = fopen("listamaterias.txt", "r"); // Abre o arquivo para leitura
    if (listatxt == NULL) { // Se o arquivo n�o existir ( NULL) ele ira entrar na condi��o e criar
        listatxt = fopen("listamaterias.txt", "a"); //Abre o arquivo para escrita caso n�o exista ele cria
    }
    fclose(listatxt); // fecha e salva o arquivo

    int materia_ja_cadastrada = 0; // incia o contador de materia cadastrada
     FILE *listaMateriasTxt = fopen("listamaterias.txt", "r+"); //abre o arquivo para leitura e escrita
     // percorre todas as linhas para verificar se a mat�ria j� existe
    while (fgets(buffer, sizeof(buffer), listaMateriasTxt)) { 
        buffer[strcspn(buffer, "\n")] = 0;  // Remove o '\n' para fazer a compara��o corretamente
        if (strcmp(buffer, questao->materia) == 0) { // compara o buffer que foi lido pelo while e a materia do cadastro se as strings s�o iguais
            materia_ja_cadastrada = 1; // caso a fun��o strcmp retorne verdadeiro(== 0 ) Significa que a materia ja esta no arquivo listamaterias.txt 
            break;  // Se a mat�ria j� foi encontrada, n�o precisa continuar o loop
        }
    }

    // Se a mat�ria n�o foi encontrada, adiciona ao arquivo
    if (materia_ja_cadastrada == 0) { // se o contador de materias for = 0 
        fprintf(listaMateriasTxt, "%s\n", questao->materia); // imprime a materia no arquivo
    }

    fclose(listaMateriasTxt); // Fecha o arquivo ap�s a opera��o
    

}
void resolverQuestoes(Questao *questoes, int numQuestoes, int *acertos) {
    int resposta; // Vari�vel para armazenar a resposta do usu�rio
    char rquestao[80];// Vari�vel para armazenar a mat�ria selecionada pelo usu�rio
    char buffer[1000]; // Buffer para leitura de linhas do arquivo

    FILE *lista;// Ponteiro para o arquivo da lista de mat�rias
    *acertos = 0; // Inicializa o contador de acertos
        printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
        lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), lista)) {
                printf("%s", buffer);
               
                
        }
        fclose(lista);   // Fecha o arquivo apois a leitura

    printf("Qual mat�ria voc� deseja resolver as quest�es?\n");
    fgets(rquestao, 80, stdin);
    rquestao[strcspn(rquestao, "\n")] = '\0'; // Remove nova linha
    
    FILE *file = fopen(rquestao, "r"); // Abre o arquivo da mat�ria selecionada
    if (file == NULL) {
        Sleep(500);
        printf("Erro ao abrir o arquivo de quest�es.\n");
        Sleep(800);
        return;// Retorna em caso de erro
    }

    // Inicializa o contador de quest�es
    numQuestoes = 0;

    // L� as quest�es do arquivo

    while (fgets(questoes[numQuestoes].materia, sizeof(questoes[numQuestoes].materia), file) != NULL) {
        questoes[numQuestoes].materia[strcspn(questoes[numQuestoes].materia, "\n")] = '\0'; // Remove nova linha

        fgets(questoes[numQuestoes].enunciado, sizeof(questoes[numQuestoes].enunciado), file);
        questoes[numQuestoes].enunciado[strcspn(questoes[numQuestoes].enunciado, "\n")] = '\0'; // Remove nova linha

        for (int i = 0; i < 5; i++) {
            fgets(questoes[numQuestoes].alternativas[i], sizeof(questoes[numQuestoes].alternativas[i]), file);
            questoes[numQuestoes].alternativas[i][strcspn(questoes[numQuestoes].alternativas[i], "\n")] = '\0'; // Remove nova linha
        }

        fgets(questoes[numQuestoes].resposta, sizeof(questoes[numQuestoes].resposta), file);
        questoes[numQuestoes].resposta[strcspn(questoes[numQuestoes].resposta, "\n")] = '\0'; // Remove nova linha

        (numQuestoes)++; // Incrementa o n�mero de quest�es lidas
    }
    fclose(file); // Fecha o arquivo de quest�es

    printf("Quantas quest�es deseja responder de %s: ",rquestao);//solicita ao usu�rio a quantidade de quest�es que deseja responder 
    scanf("%i",&numQuestoes);
    getchar();
    questoes->totQuest = numQuestoes;// recebe o n�mero de quest�o que o usu�rio deseja responder, para mostrar no fim do questionario
    // exiba as quest�es
    for (int i = 0; i < numQuestoes; i++) {
        Sleep(500); // Pausa para melhorar a experi�ncia do usu�rio

        // Exibe a mat�ria e o enunciado da quest�o
        printf("%s\n", questoes[i].materia);
        Sleep(500);
        printf("Quest�o %d: %s\n", i + 1, questoes[i].enunciado);
        Sleep(500);
        
        // Exibe as alternativas
        for (int j = 0; j < 5; j++) {
            printf("%s\n", questoes[i].alternativas[j]);
        }

    // Solicita a resposta do usu�rio
        int repostaInt = atoi(questoes[i].resposta); // Transforma a reposta cadastrada em int para melhor fazer a compara��o e tratamento de erros
        do {
            printf("N�mero da quest�o correta(1 a 5): ");
            scanf("%i",&resposta); // L� a resposta
            printf("\n");
        } while (resposta < 1 || resposta > 5 ); // Continua pedindo at� ser um n�mero vailido entre 1 e 5
        if (repostaInt == resposta) { // Verifica se a resposta est� correta
            (*acertos)++;
        }
        
    }
}

void cadastrarMonitor(Monitor *monitor){
    int contstring;
    Sleep(500);// Pausa a execu��o por 500 milissegundos antes de iniciar o cadastro
    do{
        printf("Nome do Monitor: ");
        fgets(monitor->nome, 50, stdin); // Captura o nome do monitor
        contstring = strlen(monitor->nome);
        if(contstring <= 1){
            printf("Monitor invalido! Quantidade m�nima 1 caractere.\n");
        }
    }while(contstring <=1); //garantindo que n�o seja vazio
    monitor->nome[strcspn(monitor->nome, "\n")] = '\0'; // Remove o caractere de nova linha
    (monitor->quant = 1); // Inicializa a quantidade de monitores
    Sleep(500); // Pausa a execu��o por 500 milissegundos

    // Captura o hor�rio dispon�vel para monitoria, garantindo que seja maior que 5 caracteres

    do{
        printf("Hor�rio disponivel para monitoria: ");
        fgets(monitor->horario, 80, stdin); // L� a entrada do hor�rio
        contstring = strlen(monitor->horario); 
        if (contstring <= 5){
            printf("Formato de hora invalido!\n");
        }
        
    }while(contstring <= 5);// Garante que o hor�rio tenha pelo menos 5 caracteres
    monitor->horario[strcspn(monitor->horario, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(500); // Pausa a execu��o por 500 milissegundos
    do{
        printf("Telefone para contato: 9. ");
        fgets(monitor->telefone, 80, stdin); // L� a entrada do telefone
        contstring = strlen(monitor->telefone);
        if (contstring != 9){
            printf("Telefone invalido!\n");
        }
        
    }while(contstring != 9); // Garante que o telefone tenha pelo menos 8 caracteres
    monitor->telefone[strcspn(monitor->telefone, "\n")] = '\0';  // Remove o caractere de nova linha
    Sleep(500);// Pausa a execu��o por 500 milissegundos
    printf("Cadastrando....\n");
    Sleep(600); // Pausa a execu��o para simular o tempo de cadastro
    printf("Monitor cadastrado com sucesso.\n");
    Sleep(1000);// Pausa a execu��o para simular o tempo de cadastro

    FILE *monitortxt = fopen("cadastromonitor.txt","a");  // Abre o arquivo para armazenar o monitor cadastrado

     // Escreve os dados do monitor no arquivo
    fprintf(monitortxt,"\nNome do Monitor: %s\n",monitor->nome); // Escreve o nome do monitor
    fprintf(monitortxt,"Hor�rio disponivel para monitoria: %s\n",monitor->horario); // Escreve o hor�rio dispon�vel
    fprintf(monitortxt,"Telefone para contato:9.%s\n",monitor->telefone);  // Escreve o telefone, prefixando com '9.'
    fclose(monitortxt);// Fecha o arquivo ap�s a escrita
    
}

void consultarAlunos() {
    FILE *file;  // Ponteiro para o arquivo que armazena dados de um aluno espec�fico
    FILE *lista;  // Ponteiro para o arquivo que armazena a lista de todos os alunos
    char matricula[80]; // Var�avel para armazenar a matr�cula do aluno para consulta
    char buffer[255]; // Buffer para ler linhas dos arquivos
    int opcao;  // Var�avel para armazenar a op��oo selecionada pelo us�ario // Var�avel para armazenar a op��o selecionada pelo us�ario
    int parar = 1;   // Var�avel de controle para o loop de consulta
    printf("Consultar Alunos: \n");
    Sleep(500);

    while (parar == 1) {  // Loop para continuar a consulta at� que o us�ario decida sair
        printf("\n1 -> Acessar toda a lista de alunos cadastrados:\n");
        printf("2 -> Consultar um aluno por matricula:\n");
        printf("0 -> Voltar ao menu anterior\n");
        printf("Sua op��o: ");
        scanf("%i",&opcao); // Ler a op��o escolhida pelo us�rio
        getchar(); // Limpa o buffer de entrada
        system("cls");
        Sleep(500);
        switch (opcao){
            case 1 :  // Acessa e ler o arquivo com a lista de todos os alunos
                lista = fopen("cadastroaluno.txt","r");
                if (lista == NULL) {
                    printf("Lista de alunos n�o encontrada\n");
                } else {
                    while (fgets(buffer, sizeof(buffer), lista)) { // Ler e imprime o conteudo do arquivo
                        printf("%s", buffer);  
                }
                fclose(lista); // Fecha o arquivo apois a leitura
                    }
                system("pause");
                system("cls");
                break;
            case 2 :

                // Consulta um aluno espec�fico pela matr�cula
                printf("Digite a matricula do aluno:");
                fgets(matricula, 80, stdin);
                Sleep(500);
                matricula[strcspn(matricula, "\n")] = '\0';
                if (strcmp(matricula, "0") == 0){
                    break;
                }
                file = fopen(matricula, "r"); // Acessa e ler o arquivo correspondente e matr�cula do aluno
                if (file == NULL) {
                    printf("Aluno n�o encontrado.\n");
                    break;
            } else {
                while (fgets(buffer, sizeof(buffer), file)) {  
                printf("%s", buffer);// Ler e imprime o conte�do do arquivo
            }
            fclose(file);
                }
            system("pause");
            system("cls");
                break;
            case 0: // Sai do loop e volta ao menu anterior
            parar ++;
                break;
            default:
                printf("Opera��o invalida.");
                break;
        }
        
    }
}

// Fun��o para consultar questoes
void consultarQuestoes() {
    system("cls");
    FILE *lista;  // Ponteiro para o arquivo que armazena a lista de disciplinas
    FILE *file; // Ponteiro para o arquivo que armazena as quest�es de uma disciplina
    char materia[80];   // Var�avel para armazenar o nome da disciplina para consulta
    char buffer[255];  // Buffer para ler linhas dos arquivos
    printf("Consultar Quest�es:\n");
    Sleep(500);
    
    while (1) { // Loop para continuar a consulta at� que o us�rio decida sair 
        printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
        lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), lista)) {
                printf("%s", buffer);
        }
        fclose(lista);   // Fecha o arquivo apois a leitura
        
        printf("Digite a disciplina  para consultar (ou '0' para voltar ao menu anterior): \n"); // Solicita ao us�rio o nome da disciplina para consultar quest�es
        printf(">>> ");        
        fgets(materia, 80, stdin);
        system("cls");
        materia[strcspn(materia, "\n")] = '\0';
        if (strcmp(materia, "0") == 0){  // Se o us�rio digitar "0", sai do loop
             break;
        }
        file = fopen(materia, "r");  // Acessa e ler o arquivo correspondente � disciplina
        if (file == NULL) {
            printf("Quest�o n�o encontrada.\n");
            Sleep(800);
        } else {
            while (fgets(buffer, sizeof(buffer), file)) { // Ler e imprime o conte�do do arquivo
                printf("%s", buffer);
                Sleep(300);
            }
            system("pause");
            system("cls");
            fclose(file);
            Sleep(800);
        }
    }
}

// Fun��o para consultar monitores
void consultarMonitores() {
    FILE *file;  // Ponteiro para o arquivo que armazena dados dos monitores
    char buffer[255]; // Buffer para ler linhas do arquivo
    system("cls");
    printf("Consultar Monitores:\n");
    Sleep(500);
    while (1) {  // Loop para continuar a consulta at� que o us�rio decida sair
        file = fopen("cadastromonitor.txt", "r");  // Acessa e ler o arquivo com os dados dos monitores
        if (file == NULL) {
            printf("Analisando...\n");
            Sleep(800);
            printf("Monitor n�o encontrado.\n");
            Sleep(1000);
            break;
        } else { 
            while (fgets(buffer, sizeof(buffer), file)) { // Ler e imprime o conte�do do arquivo
                printf("%s", buffer);
            }
            system("pause");
            system("cls");
            fclose(file);
            Sleep(500);
            break;
        }

    }
}
 
void menuConsulta(){
    int opcao1; // Var�avel para armazenar a op��o escolhida pelo us�rio
    do{
            system("cls");
            mostrarlinha(); // Fun��o para mostrar uma linha no console
            printf("\tMenu de Consultas\n\n");
            printf("1 -> Consultar Aluno\n");
            printf("2 -> Consultar Quest�es\n");
            printf("3 -> Consultar Monitor\n");
            printf("0 -> Voltar para tela anterior");
            mostrarlinha(); // Fun��o para mostrar uma linha no console
            printf("Ecolha uma op��o: ");
            scanf("%i",&opcao1);  // Ler a op��o escolhida pelo us�rio
            getchar(); // Limpa o buffer do teclado
            switch (opcao1){  // Switch para executar a ap��o com base na op��o escolhida

                case 1:
                    system("cls");
                    consultarAlunos();  // Chama a fun��o para consultar alunos
                    break;
                case 2:
                    consultarQuestoes();  // Chama a fun��o para consultar quest�es
                    break; 
                case 3:
                    consultarMonitores(); // Chama a fun��o para consultar monitores
                    break;
                case 0:
                    printf("Retornando a tela principal.\n");
                    Sleep(1000);
                    break;
                default:
                    printf("Opera��o invalida."); // Mensagem de erro para op��o inv�lida
                    break;
            }
    }while(opcao1 != 0);   
}
   
int main(){
    FILE *materias;
    setlocale(LC_ALL, "Portuguese_Brazil"); // Configura a localiza��o para portugues do Brasil
    Aluno aluno; // Declara uma var�avel do tipo Aluno
    Cronograma cronograma; //Declara uma var�avel do tipo Cronograma
    Questao questoes[50]; // Declara um array de Questao com capacidade para 10 quest�es
    questoes->quantQuest = 0; // Inicializa a quantidade de quest�es cadastradas para 0
    Monitor monitor;  // Declara uma var�avel do tipo Monitor
    monitor.quant = 0; // Inicializa a quantidade de monitores cadastrados para 0
    
    int numQuestoes = 0;  // Var�avel para armazenar o n�mero de quest�es cadastradas
    int opcao; // Var�avel para armazenar a op��o escolhida pelo us�rio
    int acertos; // Var�avel para armazenar o n�mero de acertos nas quest�es
    do{
        system("cls");
        mostrarlinha();
        printf("\t    Menu\n\n");
        printf("1 -> Cadastrar Aluno\n");
        printf("2 -> Gerar Cronograma de Estudo\n");
        printf("3 -> Cadastrar Quest�es\n");
        printf("4 -> Resolver Quest�es\n");
        printf("5 -> Cadastrar Monitor\n");
        printf("6 -> Consultas\n");
        printf("0 -> Sair");
        mostrarlinha();
        Sleep(400);
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
            system("cls");
            cadastrarAluno(&aluno);
            break;
            case 2:
            system("cls");
            gerarCronograma(&cronograma);
            system("pause");
            break;
            case 3:
            system("cls");
            if (numQuestoes < 20){ // Verifica se o n�mero de quest�es � menor que 10
                cadastrarQuestao(&questoes[numQuestoes]); // Chama a fun��o para cadastrar uma nova quest�o
                numQuestoes++;  // Incrementa o n�mero de quest�es cadastradas
                questoes->quantQuest++; // Incrementa a quantidade de quest�es no array de quest�es
            }
            else{
                printf("Limite de quest�es atingida.\n");  // Mensagem de erro quando o limite de quest�es at� atingido
            }
            break;
            case 4:
                materias = fopen("listamaterias.txt","r");
                if (materias == NULL){ // Verifica se nenhuma quest�o foi cadastrada
                    printf("Analisando...\n");
                    Sleep(1000);
                    printf("**Nenhuma quest�o foi cadastrada ainda!**\n");
                    Sleep(1000);
                    break;
                }else{
                resolverQuestoes(questoes, numQuestoes, &acertos); // Chama a fun��o para resolver quest�es
                Sleep(600);
                printf("Voce acertou %d de %d quest�es. \n", acertos, questoes->totQuest); // Exibe o n�mero de acertos
                system("pause");
                Sleep(600);
                }
                break;
            case 5:
                system("cls");
                cadastrarMonitor(&monitor); // Chama a fun��o para cadastrar um monitor
                break;
            case 6:
                menuConsulta(); // Chama a fun��o para acessar o menu de consulta
                break;
            case 0:
                printf("Saindo do Programa...\n");
                Sleep(1000);
                printf("Programa FINALIZADO.");
                Sleep(1000);
                break;
            default:
                printf("Opera��o invalida, tente novamente.\n");
        }
    }while (opcao != 0); // Continua no menu at� que o us�rio escolha a op��o 0 para sair
return 0; // Retorna 0 indicando que o programa terminou com sucesso
}   