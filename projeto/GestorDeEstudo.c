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
    int tempoDisponivel ;
    int questoesPorEstudo;
    int contador;
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
    int contstring;// vari�vel para contar a quantidade de caracteres


    do{
        printf("Nome do Aluno: ");
        fgets(aluno -> nome, 50, stdin); // Linha a linha de entrada para o nome do aluno
        contstring = strlen(aluno->nome);  // Obtem o comprimento da string
        if(contstring <=1 ){
            printf("Nome inv�lido! Quantidade m�nima 1 caractere.\n");
        }
    }while(contstring <= 1);  // Garante que o nome tenha pelo menos um caractere
    aluno -> nome[strcspn(aluno -> nome, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(600); // Pausa a execu��o por 600 milissegundos
    do{
        printf("Digite sua matr�cula: ");
        fgets(aluno->matriculaAluno,20,stdin);  
        contstring = strlen(aluno->matriculaAluno);// Obtem o comprimento da string
        if(contstring != 11){
            printf("Matr�cula inv�lida! Digite 10 n�meros.\n");
        }
    }while(contstring != 11);//Garante que a matr�cula tenha pelo menos 10 caracteres
    aluno -> matriculaAluno[strcspn(aluno -> matriculaAluno, "\n")] = '\0'; // Remove a nova linha do final da string
    Sleep(500); // Pausa a execu��o por 500 milissegundos

    // Captura o curso do aluno

    do{
        printf("Curso: ");
        fgets(aluno -> curso, 50, stdin);// L� a entrada do usu�rio
        contstring = strlen(aluno->curso);
        if(contstring <= 1){
            printf("Curso inv�lido! Quantidade m�nima 1 caractere.\n");
        }
    }while(contstring <= 1); //garantindo que n�o seja vazio
    aluno -> curso[strcspn(aluno -> curso, "\n")] = '\0';// Remove a nova linha do final da string
    Sleep(500);// Pausa a execu��o por 500 milissegundos

    // Captura o per�odo em que o aluno est�, garantindo que esteja entre 1 e 16

    do{
        printf("Per�odo: ");
        scanf("%d", &aluno -> periodo);
        getchar(); // Limpa o buffer de entrada
        if (aluno->periodo < 1 || aluno->periodo > 12 ){
            printf("Per�odo inv�lido! Digite um per�odo entre 1 e 12.\n");
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
                printf("Disciplina inv�lida! Quantidade m�nima 1 caractere.\n");
            }
        }while(contstring <= 1);
        aluno -> disciplinas[i] [strcspn(aluno -> disciplinas[i], "\n")] = '\0'; // Remove a nova linha do final da string
    }
    Sleep(500); // Pausa a execu��o por 500 milissegundos

   
    printf("Cadastrando...\n");  // Mensagem de cadastro e grava��o dos dados em arquivos
    Sleep(2000); // Pausa para simular o tempo de cadastro
    printf("Aluno cadastrado.\n");
    Sleep(1000); // Pausa a execu��o por 1 segundo
    system("pause");
     // Cria e abre um arquivo com o nome do aluno (matr�cula) para escrita
    FILE *alunotxt = fopen(aluno->matriculaAluno ,"w");
   
     // Escreve os dados do aluno no arquivo
    fprintf(alunotxt, "Nome: %s\n", aluno->nome);//fun��o fprintf serve para escrever o nome do aluno no arquivo
    fprintf(alunotxt, "Matr�cula: %s\n", aluno->matriculaAluno);
    fprintf(alunotxt, "Curso: %s\n", aluno->curso);//fun��o fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(alunotxt, "Per�odo: %d\n", aluno->periodo);//fun��o fprintf serve para escrever o per�odo que o aluno esta
    fprintf(alunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//fun��o fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar os nomes das disciplinas
        fprintf(alunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }
 

    fclose(alunotxt);  // Escreve os dados do aluno no arquivo e fecha

    // Escreve os dados do aluno no arquivo
    FILE *nomealunotxt = fopen("cadastroaluno.txt","a"); //criar um novo arquivo caso n�o exista, se existir ele imprime no final as novas informa��es
   

    fprintf(nomealunotxt, "Nome: %s\n", aluno->nome);//fun��o fprintf serve para escrever o nome do aluno no arquivo
    fprintf(nomealunotxt, "Matr�cula: %s\n", aluno->matriculaAluno);
    fprintf(nomealunotxt, "Curso: %s\n", aluno->curso);//fun��o fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(nomealunotxt, "Per�odo: %d\n", aluno->periodo);//fun��o fprintf serve para escrever o per�odo que o aluno esta
    fprintf(nomealunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//fun��o fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar o nome das disciplinas
        fprintf(nomealunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }
    
    fclose(nomealunotxt);  // Fecha o arquivo e salva
}

void gerarCronograma(Cronograma *cronograma){
    Questao questoes;
    int opcao;
    char buffer[250];
    memset(&cronograma->quantdisciplinas, 0, sizeof(Cronograma));//garante que n�o tenha lixo de mem�ria.
    memset(&cronograma->tempoDisponivel, 0, sizeof(Cronograma));//garante que n�o tenha lixo de mem�ria.
   
    //FILE *lista;
    
    FILE *listatxt = fopen("listamaterias.txt", "r"); // Abre o arquivo para leitura
    if (listatxt == NULL) { // Se o arquivo n�o existir ( NULL) ele ira entrar na condi��o e criar
        printf("N�o existe disciplinas cadastrada no banco de dados\n"); // imprime a mat�ria no arquivo
        printf("Voc� ser� redirecionado para o cadastro de disciplinas\n");
        Sleep(1200);
        system("pause");
        system("cls");
        cadastrarQuestao(&questoes);
        system("cls");
        printf("Continue gerando seu cronograma.\n");
        printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
        listatxt = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), listatxt)) {
            printf("%s", buffer);
}
    }else{
        printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
        listatxt = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), listatxt)) {
            printf("%s", buffer);
        }
   // fclose(lista);   // Fecha o arquivo apois a leitura
    }
    fclose(listatxt); // fecha e salva o arquivo
    
    do{
        printf("Quantidade de disciplinas que deseja estudar MAX 10: ");
        scanf("%i",&cronograma->quantdisciplinas);// L� a entrada do usu�rio
        getchar();
        if(cronograma->quantdisciplinas > 10 || cronograma->quantdisciplinas <= 0){
            printf("Quantidade MAX disciplinas 10\n");
        }
     } while (cronograma->quantdisciplinas > 10 || cronograma->quantdisciplinas < 1); // Garante que a quantidade esteja entre 1 e 10
    int materia_ja_cadastrada = 0; // inicia o contador de mat�ria cadastrada
    for(int i = 0; i < cronograma->quantdisciplinas; i++){
        Sleep(500); // Pausa a execu��o para melhorar a experi�ncia do usu�rio
        do{
            printf("Disciplina %d: ", i + 1); 
            fgets(cronograma -> disciplinas[i], 80, stdin); // L� a entrada do nome da disciplina
            strupr(cronograma -> disciplinas[i]);
            cronograma -> disciplinas[i] [strcspn(cronograma -> disciplinas[i], "\n")] = '\0'; // Remove a nova linha do final da string

     FILE *listaTxt = fopen("listamaterias.txt", "r"); //abre o arquivo para leitura
     // percorre todas as linhas para verificar se a mat�ria j� existe
    while (fgets(buffer, sizeof(buffer), listaTxt)) { 
        buffer[strcspn(buffer, "\n")] = 0;  // Remove o '\n' para fazer a compara��o corretamente
        if (strcmp(buffer, cronograma->disciplinas[i]) == 0) { // compara o buffer que foi lido pelo while e a mat�ria do cadastro se as strings s�o iguais
            materia_ja_cadastrada = 1; // caso a fun��o strcmp retorne verdadeiro(== 0 ) Significa que a mat�ria ja esta no arquivo listamaterias.txt 
            break;  // Se a mat�ria j� foi encontrada, n�o precisa continuar o loop
        }
        materia_ja_cadastrada = 0;
    }

    // Se a mat�ria n�o foi encontrada
    if (materia_ja_cadastrada == 0) { // se o contador de materias for = 0 
        printf("Diciplina n�o cadastrada no banco de dados\n"); // imprime a materia no arquivo
        printf("Deseja cadastrar a disciplina ? 1 = SIM / 2 = N�O (Qualquer tecla para finalizar): ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            cadastrarQuestao(&questoes);
            return ;
            break;
        case 2:
            continue;
            break;
        default:
            printf("Retornando ao menu principal.\n");
            Sleep(600);
            return ;
            break;
        }

    }

    fclose(listaTxt); // Fecha o arquivo ap�s a opera��o
        
    
       
        }while( materia_ja_cadastrada == 0);

    }
    Sleep(500); // Pausa a execu��o por 500 milissegundos
    do{
        printf("Tempo dispon�vel para estudo (em minutos): ");
        scanf("%d", &cronograma -> tempoDisponivel);// L� a entrada do usu�rio
        fflush(stdin); // Limpa o buffer de entrada
        if(cronograma->tempoDisponivel <= 0 || cronograma->tempoDisponivel > 1440){
           printf("Prezamos pela sua sa�de! Tempo m�ximo de estudo 1440 minutos(24hrs)\n"); 
        }
    }while(cronograma->tempoDisponivel <= 0 || cronograma->tempoDisponivel > 1440);// Garante que o tempo esteja entre 1 minuto e 24 horas (1440 minutos)
    Sleep(500);
    do{
        printf("Quantidade de quest�es que deseja responder ao t�rmino do estudo: ");
        scanf("%d", &cronograma -> questoesPorEstudo);// L� a entrada do usu�rio
        fflush(stdin);
        if(cronograma->questoesPorEstudo <=0 || cronograma->questoesPorEstudo > 1000){
            printf("M�nimo de quest�es 1 e m�ximo de quest�es 1000.\n");
            cronograma->contador = 0;
        }else{
            cronograma->contador = 1;
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
    printf("OBS: SER�O EMITIDOS 2 BEEP COMO ALERTA ASSIM QUE ATINGIDO O TEMPO DE ESTUDO DE CADA DISCIPLINA\n");
    Sleep(1000);
    

}
 
void cadastrarQuestao(Questao * questao){
    system("cls");
    Questao questoes;
    int opcao;//op��o no switch case
    char buffer[255];// vari�vel que ira receber a leitura do bancod e dados e imprimir
    int contstring; // Vari�vel para contar o comprimento das strings
    // Captura a resposta correta
    int respostaCorreta = 0;// inicializa em 0
    Sleep(500); // Pausa para melhorar a experi�ncia do usu�rio

    // Captura a mat�ria da quest�o

    do{
        printf("Mat�ria: ");
        fgets(questao -> materia, 80, stdin);// L� a entrada do usu�rio
        contstring = strlen(questao->materia);// Armazena o comprimento da mat�ria
        if(contstring <= 1){
            printf("Mat�ria inv�lida! Quantidade m�nima 1 caractere.\n");
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
           printf("Enunciado inv�lido! Quantidade m�nima 1 caractere.\n");
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

    do{
        printf("N�mero da quest�o correta(1 a 5): ");
        fgets(questao -> resposta, 100, stdin);// L� a resposta correta
        respostaCorreta = atoi(questao->resposta);// converte a string para int
    }while(respostaCorreta < 1 || respostaCorreta > 5); // Continua pedindo at� ser digitado o n�mero valido
  

    
    questao -> resposta[strcspn(questao -> resposta, "\n")] = '\0'; // Remove a nova linha da resposta
    Sleep(500); // Pausa para melhorar a experi�ncia do usu�rio
    printf("Cadastrando...\n");
    Sleep(1000);// Pausa para simular o tempo de cadastro
    printf("Quest�o cadastrada com sucesso.\n");
    Sleep(1000);// Pausa para simular o tempo de cadastro
    printf("Deseja cadastrar mais quest�es? 1 = SIM / 2 = N�O: ");
    scanf("%d",&opcao);
    getchar();
        switch (opcao){
        case 1:
            cadastrarQuestao(&questoes);
            break;
        case 2:
            break;
        default:
            printf("Op��o inv�lida.\n");
            printf("Retornando ao menu principal.\n");
            Sleep(600);
            break;
        }


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

    int materia_ja_cadastrada = 0; // incia o contador de mat�ria cadastrada
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
        strupr(questao->materia); // imprime no banco de dados o nome da materia mai�scula
        fprintf(listaMateriasTxt, "%s\n", questao->materia); // imprime a materia no arquivo
    }

    fclose(listaMateriasTxt); // Fecha o arquivo ap�s a opera��o
    

}
void resolverQuestoes(Questao *questoes, int numQuestoes, int *acertos) {
    int resposta; // Vari�vel para armazenar a resposta do usu�rio
    char rquestao[80];// Vari�vel para armazenar a mat�ria selecionada pelo usu�rio
    char buffer[7500]; // Buffer para leitura de linhas do arquivo
    char bufferResposta[255];
    int RespostaSn;  
    *acertos = 0; // Inicializa o contador de acertos
    FILE *lista;// Ponteiro para o arquivo da lista de mat�rias
        printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
        lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), lista)) {
                printf("%s", buffer);
               
                
        }
        fclose(lista);   // Fecha o arquivo apois a leitura

    printf("Qual mat�ria voc� deseja resolver as quest�es?\n");
    fgets(rquestao, 80, stdin);
    strupr(rquestao);// deixa o texto mai�sclo
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
    do{
        printf("Quantas quest�es deseja responder de %s: ",rquestao);//solicita ao usu�rio a quantidade de quest�es que deseja responder 
        scanf("%i",&numQuestoes);
        getchar();
        if(numQuestoes <= 0 || numQuestoes > 30){
            printf("Informe um   valor de 1 at� 30\n");
        }
    }while(numQuestoes <= 0 || numQuestoes > 30 );
    questoes->totQuest = numQuestoes;// recebe o n�mero de quest�o que o usu�rio deseja responder, para mostrar no fim do questionario
    // exiba as quest�es
    system("cls");
    for (int i = 0; i < numQuestoes; i++) {
        Sleep(500); // Pausa para melhorar a experi�ncia do usu�rio

        // Exibe a mat�ria e o enunciado da quest�o
        printf("%s\n", questoes[i].materia);
        Sleep(500);
        printf("Quest�o %d:\n%s\n", i + 1, questoes[i].enunciado);
        Sleep(500);
        
        // Exibe as alternativas
        for (int j = 0; j < 5; j++) {
            printf("%s\n", questoes[i].alternativas[j]);
        }
    
    // Solicita a resposta do usu�rio
        int respostaInt = atoi(questoes[i].resposta); // Transforma a reposta cadastrada em int para melhor fazer a compara��o e tratamento de erros
        do {
            printf("N�mero da quest�o correta(1 a 5): ");
            scanf("%i",&resposta); // L� a resposta
            printf("\n");
            if(resposta < 1 || resposta > 5 ){
                printf("Valor inv�lido!\n");
            }
        } while (resposta < 1 || resposta > 5 ); // Continua pedindo at� ser um n�mero vailido entre 1 e 5
        if (respostaInt == resposta) { // Verifica se a resposta est� correta
            (*acertos)++;
            printf("Quest�o %d correta.\n\n",i+1);//exibe se a respota foi correta

            //Estrutura para salvar em um arquivo txt todos as repostas corretas

            FILE *respostaCorretatxt = fopen("RespostaCorreta.txt","a");
            fprintf(respostaCorretatxt,"%s\n",questoes[i].materia);
            fprintf(respostaCorretatxt,"Quest�o %d:\n%s\n", i + 1, questoes[i].enunciado);
            for(int j = 0; j < 5; j++){
                fprintf(respostaCorretatxt,"%s\n",questoes[i].alternativas[j]);
            }
            fprintf(respostaCorretatxt,"Alternativa correta: %i\n\n",resposta);
            

            fclose(respostaCorretatxt);
        }else{
           printf("Quest�o %d errada.\n\n",i+1);//exibe se a repsota foi errada
        }
        
    } 

    //caso o aluno tenha certado mais que uma quest�o. Vai ser feita valida��o se ele deseja visualizar as repostas correta
    //system("cls");
    if((*acertos) >= 1){
        printf("Deseja visualizar as quest�es que voc� acertou? 1 = SIM / (QUALQUER TECLA PARA CONTINUAR SEM VISUALIZAR) \n");
        scanf("%d",&RespostaSn);
        getchar();
        if(RespostaSn == 1){
            
            FILE  *respostaCorreta = fopen("RespostaCorreta.txt","r");
            system("cls");
            printf("Lista de reposta correta:\n");
            mostrarlinha();
                while( fgets(bufferResposta, sizeof(bufferResposta),respostaCorreta)){  // Ler e imprime o conte�do do arquivo
                    Sleep(500);
                    printf("%s", bufferResposta);
                }
            mostrarlinha();
            fclose(respostaCorreta);
            }
    Sleep(1000);
    }
    
    remove("RespostaCorreta.txt");
}
          

void cadastrarMonitor(Monitor *monitor){
    system("cls");
    int contstring;
    Sleep(500);// Pausa a execu��o por 500 milissegundos antes de iniciar o cadastro
    do{
        printf("Nome do Monitor: ");
        fgets(monitor->nome, 50, stdin); // Captura o nome do monitor
        contstring = strlen(monitor->nome);
        if(contstring <= 1){
            printf("Monitor inv�lido! Quantidade m�nima 1 caractere.\n");
        }
    }while(contstring <=1); //garantindo que o nome  n�o seja vazio
    monitor->nome[strcspn(monitor->nome, "\n")] = '\0'; // Remove o caractere de nova linha
    (monitor->quant = 1); // Inicializa a quantidade de monitores
    Sleep(500); // Pausa a execu��o por 500 milissegundos

    // Captura o hor�rio dispon�vel para monitoria, garantindo que seja maior que 5 caracteres

    do{
        printf("Hor�rio dispon�vel para monitoria: ");
        fgets(monitor->horario, 80, stdin); // L� a entrada do hor�rio
        contstring = strlen(monitor->horario); 
        if (contstring <= 5){
            printf("Formato de hora inv�lido!\n");
        }
        
    }while(contstring <= 5);// Garante que o hor�rio tenha pelo menos 5 caracteres
    monitor->horario[strcspn(monitor->horario, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(500); // Pausa a execu��o por 500 milissegundos
    do{
        printf("Telefone para contato: 9. ");
        fgets(monitor->telefone, 80, stdin); // L� a entrada do telefone
        contstring = strlen(monitor->telefone);
        if (contstring != 9 && contstring != 10){
            printf("Telefone invalido!\n");
        }
        
    }while(contstring != 9 && contstring != 10); // Garante que o telefone tenha pelo menos 8 ou 9 caracteres
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
    Aluno cadAluno;
    char matricula[80]; // Var�avel para armazenar a matr�cula do aluno para consulta
    char buffer[255]; // Buffer para ler linhas dos arquivos
    int opcao, opcao1;  // Var�avel para armazenar a op��oo selecionada pelo us�ario // Var�avel para armazenar a op��o selecionada pelo us�ario
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
                    //caso n�o exita o arquivo cadastroaluno, fara um valida��o se o aluno deseja cadasrtar um aluno
                    printf("Lista de alunos n�o encontrada\n");
                    printf("Deseja cadastrar uma aluno ? 1 = SIM / 2 = N�O: ");
                    scanf("%d",&opcao1);
                    getchar();
                    switch (opcao1){
                        case 1:
                            system("cls");
                            cadastrarAluno(&cadAluno);
                            return ;
                            break;
                        case 2:
                            printf("Retornando ao menu anterior.\n");
                            Sleep(1200);
                            return ;
                            break;
                        default:
                            printf("Op��o inv�lida.\n");
                            printf("Retornando ao menu anterior.\n");
                            Sleep(1200);
                            return ;
                            break;
                    }
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
                printf("Digite a matr�cula do aluno:");
                fgets(matricula, 80, stdin);
                Sleep(500);
                matricula[strcspn(matricula, "\n")] = '\0';
                if (strcmp(matricula, "0") == 0){
                    break;
                }
                file = fopen(matricula, "r"); // Acessa e ler o arquivo correspondente e matr�cula do aluno
                if (file == NULL) {
                    //se o aluno digitar uma matricula invalida , sera feita uma valida��o para cadastar uma aluno caso desejado
                    printf("Aluno n�o encontrado.\n");
                    printf("Deseja cadastrar uma aluno ? 1 = SIM / 2 = N�O: ");
                    scanf("%d",&opcao1);
                    getchar();
                    switch (opcao1){
                        case 1:
                            system("cls");
                            cadastrarAluno(&cadAluno);
                            return ;
                            break;
                        case 2:
                            printf("Retornando ao menu anterior.\n");
                            Sleep(1200);
                            return ;
                            break;
                        default:
                            printf("Op��o inv�lida.\n");
                            printf("Retornando ao menu anterior.\n");
                            Sleep(1200);
                            return ;
                            break;
                    }
                } else {
                    while (fgets(buffer, sizeof(buffer), file)) {  
                    printf("%s", buffer);// Ler e imprime o conte�do do arquivo
                }
            fclose(file);//fecha o arquivo apois leitura
                }
            system("pause");
            system("cls");
                break;
            case 0: // Sai do loop e volta ao menu anterior
                parar ++;
                break;
            default:
                printf("Opera��o inv�lida.");
                break;
        }
        
    }
}

// Fun��o para consultar questoes
void consultarQuestoes() {
    system("cls");
    int opcao;
    Questao questoes;
    FILE *lista;  // Ponteiro para o arquivo que armazena a lista de disciplinas
    FILE *file; // Ponteiro para o arquivo que armazena as quest�es de uma disciplina
    char materia[80];   // Var�avel para armazenar o nome da disciplina para consulta
    char buffer[550];  // Buffer para ler linhas dos arquivos
    printf("Consultar Quest�es:\n");
    Sleep(500);
    
    while (1) { // Loop para continuar a consulta at� que o us�rio decida sair 
     lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
      if (lista == NULL) { // Se o arquivo n�o existir ( NULL) ele ira entrar na condi��o e criar
        printf("N�o tem disciplinas cadastradas\n");
        printf("Deseja cadastrar uma disciplina ? 1 = SIM / 2 = N�O: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
            case 1:
            cadastrarQuestao(&questoes);
                return ;
                break;
            case 2:
                printf("Retornando ao menu anterior.\n");
                Sleep(1200);
                return ;
                break;
            default:
                printf("Op��o inv�lida.\n");
                printf("Retornando ao menu anterior.\n");
                Sleep(1200);
                return ;
                break;
        }
    }else{
        printf("Lista de todas as Disciplinas dispon�veis para estudo:\n");
        while (fgets(buffer, sizeof(buffer), lista)) {
                printf("%s", buffer);
        }
        fclose(lista);   // Fecha o arquivo apois a leitura
    }
        printf("Digite a disciplina  para consultar (ou '0' para voltar ao menu anterior): \n"); // Solicita ao us�rio o nome da disciplina para consultar quest�es
        printf(">>> ");        
        fgets(materia, 80, stdin);
        strupr(materia);
        system("cls");
        materia[strcspn(materia, "\n")] = '\0';
        if (strcmp(materia, "0") == 0){  // Se o us�rio digitar "0", sai do loop
             break;
        }
        file = fopen(materia, "r");  // Acessa e ler o arquivo correspondente � disciplina
        if (file == NULL) {
            printf("Quest�o n�o encontrada.\n");
             printf("Deseja cadastrar uma disciplina ? 1 = SIM / 2 = N�O: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
            case 1:
            cadastrarQuestao(&questoes);
                return ;
                break;
            case 2:
                printf("Retornando ao menu anteior.\n");
                Sleep(1200);
                return ;
                break;
            default:
                printf("Op��o inv�lida.\n");
                printf("Retornando ao menu anterior.\n");
                Sleep(1200);
                return ;
                break;
        }
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
    int opcao;
    Monitor monitor;
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
            printf("Deseja cadastrar um monitor ? 1 = SIM / 2 = N�O: ");
            scanf("%d",&opcao);
            getchar();//limpa o buffer de entrada
            switch (opcao){
                case 1:
                    cadastrarMonitor(&monitor);//chama a fun��o para cadastrar monitor
                    return;
                    break;
                case 2:
                    printf("Retornando ao menu anterior.\n");
                    Sleep(1200);
                    return ;
                    break;
                default:
                    printf("Op��o inv�lida.\n");
                    printf("Retornando ao menu anterior.\n");
                    Sleep(1200);
                    return ;
                    break;
            }
        
        } else { 
            while (fgets(buffer, sizeof(buffer), file)) { // Ler e imprime o conte�do do arquivo
                printf("%s", buffer);
            }
            system("pause");
            system("cls");
            fclose(file);//fecha o arquivo apois leitura
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
            printf("0 -> Voltar para menu anterior");
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
                    printf("Retornando � tela principal.\n");
                    Sleep(1000);
                    break;
                default:
                    printf("Opera��o inv�lida."); // Mensagem de erro para op��o inv�lida
                    Sleep(1000);
                    break;
            }
    }while(opcao1 != 0);   
}

// Fun��o do temporizador que vai ser executada em uma thread separada(segundo plano)
DWORD WINAPI temporizador(LPVOID lpParam) {
    Cronograma *cronograma = (Cronograma *)lpParam; // Converte o par�metro recebido para o tipo Cronograma
    int tempo = cronograma->tempoDisponivel / cronograma->quantdisciplinas; // Calcula o tempo dispon�vel para cada disciplin

    if(cronograma->contador == 1){ // Verifica se o contador de disciplinas est� ativo
        for(int i = 0; i < cronograma->quantdisciplinas; i++){// Loop para cada disciplina
            tempo = cronograma->tempoDisponivel / cronograma->quantdisciplinas;  // Recalcula o tempo dispon�vel para a disciplina atual
            while (tempo > 0) {// Enquanto houver tempo dispon�vel para a disciplina

                // Espera 1 minuto (60000 ms)
                Sleep(60000);
                tempo--; //decrementa 1 minuto do tempo
            }
              // Som de alarme para sinalizar o fim do tempo de estudo
            for (int j = 0; j < 2; j++) {
                Beep(880, 1000);  // Emite um beep de 880 Hz durante 1 segundo
                Sleep(500); // Espera meio segundo entre os beeps
            }
            //exibe ao aluno, que o tempo de estudo acabou da discplina e indica a proxima disciplina a ser estudada
            if(i+1 < cronograma->quantdisciplinas){
                printf("\nTempo de estudo da disciplina %s chegou ao fim estude %s agora.\n",cronograma->disciplinas[i],cronograma->disciplinas[i+1]);  // Exibe a mensagem sobre a disciplina atual e a pr�xima
                Sleep(300);
                printf("Continue com a escolha da op��o anterior: ");
                Sleep(300);
            }else{// Mensagem final para a �ltima disciplina
                Sleep(300);
                printf("\nTempo de estudo da disciplina %s chegou ao fim \n",cronograma->disciplinas[i]);
                Sleep(300);
                //printf("Tempo total de estudo: %i minutos.\n",tempo*cronograma->quantdisciplinas);
                  printf("Tempo total de estudo: %i minutos.\n",cronograma->tempoDisponivel);// Exibe o tempo total de estudo
                Sleep(300);
                printf("Continue com a escolha da op��o anterior: ");
                Sleep(300);
            }
            
            //reseta o contador de discplinas para 0, assim encerrandoa fun��o ate ser chamanda novamente

            if(i + 1 == cronograma->quantdisciplinas){
                 cronograma->contador = 0;
            }
        }
       

    }

    return 0; // Retorna 0 ao final da execu��o da fun��o
    
}


    
int main(){
    FILE *materias;
    setlocale(LC_ALL, "Portuguese_Brazil"); // Configura a localiza2��o para portugues do Brasil
    Aluno aluno; // Declara uma var�avel do tipo Aluno
    Cronograma cronograma; //Declara uma var�avel do tipo Cronograma
    Questao questoes[50]; // Declara um array de Questao com capacidade para 50 quest�es
    questoes->quantQuest = 0; // Inicializa a quantidade de quest�es cadastradas para 0
    Monitor monitor;  // Declara uma var�avel do tipo Monitor
    monitor.quant = 0; // Inicializa a quantidade de monitores cadastrados para 0
    int numQuestoes = 0;  // Var�avel para armazenar o n�mero de quest�es cadastradas
    int opcao; // Var�avel para armazenar a op��o escolhida pelo us�rio
    int acertos; // Var�avel para armazenar o n�mero de acertos nas quest�es
   
    do{
        system("cls"); // Limpa a tela do console
        HANDLE hThread = CreateThread(NULL, 0, temporizador, &cronograma, 0, NULL);
        if (hThread == NULL) { // Verifica se houve erro ao criar a thread
            printf("Erro ao criar thread do temporizador.\n");
            return 1;// Retorna 1 indicando erro
            }
        // Cria a thread do temporizador
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
            if (numQuestoes < 20){ // Verifica se o n�mero de quest�es � menor que 20
                cadastrarQuestao(&questoes[numQuestoes]); // Chama a fun��o para cadastrar uma nova quest�o
                numQuestoes++;  // Incrementa o n�mero de quest�es cadastradas
                questoes->quantQuest++; // Incrementa a quantidade de quest�es no array de quest�es
            }
            else{
                printf("Limite de quest�es atingida.\n");  // Mensagem de erro quando o limite de quest�es at� atingido
            }
            break;
            case 4:
            system("cls");

                materias = fopen("listamaterias.txt","r");
                if (materias == NULL){ // Verifica se nenhuma quest�o foi cadastrada
                    printf("Analisando...\n");
                    Sleep(1000);
                    printf("**Nenhuma quest�o foi cadastrada ainda!**\n");
                    Sleep(1500);
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
                printf("Opera��o inv�lida, tente novamente.\n");
        }
     
       // Fecha o handle da thread
        CloseHandle(hThread);
    }while (opcao != 0); // Continua no menu at� que o us�rio escolha a op��o 0 para sair
   
return 0; // Retorna 0 indicando que o programa terminou com sucesso
}   