#include <stdio.h> // Inclui a biblioteca padr�o de entrada e saida
#include <string.h> // Inclui a biblioteca para manipula��o de strings
#include <locale.h> // Inclui a biblioteca para configura��o de localidade
#include <stdlib.h>  // Inclui a biblioteca para funcionalidaes utilitarias
#include <windows.h> // Inclui a biblioteca para fun��es espec�ficas do Windows


// Estrutura para armazenar informa��eses de um aluno
typedef struct {
    char nome [80];
    char curso [80];
    char disciplinas [10][80];
    char matriculaAluno[20];    
    int periodo,tempoDisponivel,questoesPorEstudo,quantdisciplinas;
} Aluno;

// Estrutura para armazenar informa��es de uma quest�o
typedef struct {
    char materia [80];
    char enunciado[250];
    char alternativas[5][1000];
    char resposta [100]; 
    int quantQuest;
   
} Questao;

// Estrutura para armazenar informa��es de um monitor
typedef struct{
    char nome [80];
    char horario[80];
    char telefone[80];
    int quant;
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
    }while(contstring <= 1);  // Garante que o nome tenha pelo menos um caractere
    aluno -> nome[strcspn(aluno -> nome, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(600); // Pausa a execu��o por 800 milissegundos
    do{
        printf("Digite sua matr�cula: ");
        fgets(aluno->matriculaAluno,20,stdin);  
        contstring = strlen(aluno->matriculaAluno);
    }while(contstring <= 10);
    aluno -> matriculaAluno[strcspn(aluno -> matriculaAluno, "\n")] = '\0';
    Sleep(500);
    do{
        printf("Curso: ");
        fgets(aluno -> curso, 50, stdin);
        contstring = strlen(aluno->curso);
    }while(contstring <= 1);
    aluno -> curso[strcspn(aluno -> curso, "\n")] = '\0';
    Sleep(500);
    do{
        printf("Periodo: ");
        scanf("%d", &aluno -> periodo);
        getchar(); // Limpa o buffer de entrada
    }while(aluno->periodo < 1 || aluno->periodo > 16); // Garante que o per�odo esteja entre 1 e 16
    do{
        printf("Quantidade de disciplinas MAX 10: ");
        scanf("%i",&aluno->quantdisciplinas);
        getchar();
     } while (aluno->quantdisciplinas > 10 || aluno->quantdisciplinas < 1); // Garante que a quantidade esteja entre 1 e 10

    for(int i = 0; i < aluno->quantdisciplinas; i++){
        Sleep(500);
        do{
            printf("Disciplina %d: ", i + 1); 
            fgets(aluno -> disciplinas[i], 80, stdin);
            contstring = strlen(aluno->disciplinas[i]);
        }while(contstring <= 1);
        aluno -> disciplinas[i] [strcspn(aluno -> disciplinas[i], "\n")] = '\0';
    }
    Sleep(500);
    do{
        printf("Tempo disponivel para estudo (em minutos): ");
        scanf("%d", &aluno -> tempoDisponivel);
        getchar(); // Limpa o buffer de entrada
    }while(aluno->tempoDisponivel <= 0 || aluno->tempoDisponivel > 1440);// Garante que o tempo esteja entre 1 minuto e 24 horas (1440 minutos)
    Sleep(500);
    do{
        printf("Quantidade de quest�es que deseja responder ao t�rmino do estudo: ");
        scanf("%d", &aluno -> questoesPorEstudo);
        getchar();
    }while(aluno->questoesPorEstudo <=0 || aluno->questoesPorEstudo > 10000); // Garante que a quantidade esteja entre 1 e 10.000
    Sleep(500);

    // Mensagem de cadastro e grava��o dos dados em arquivos
    printf("Cadastrando...\n");
    Sleep(2000);
    printf("Aluno cadastrado.");
    Sleep(1000);
    
     // Cria e abre um arquivo com o nome do aluno (matr�cula) para escrita
    FILE *alunotxt = fopen(aluno->matriculaAluno ,"W");
   
     // Escreve os dados do aluno no arquivo
    fprintf(alunotxt, "Nome: %s\n", aluno->nome);//fun��o fprintf serve para escrever o nome do aluno no arquivo
    fprintf(alunotxt, "Matricula: %s\n", aluno->matriculaAluno);
    fprintf(alunotxt, "Curso: %s\n", aluno->curso);//fun��o fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(alunotxt, "Periodo: %d\n", aluno->periodo);//fun��o fprintf serve para escrever o periodo que o aluno esta
    fprintf(alunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//fun��o fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar os nomes das disciplinas
        fprintf(alunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }
    
    fprintf(alunotxt, "Tempo Dispon�vel para Estudo (em minutos): %d\n", aluno->tempoDisponivel);// tempo disponivel do aluno
    fprintf(alunotxt, "Quantidade de Quest�es que Deseja Responder: %d\n", aluno->questoesPorEstudo);//quantidade quest�es
    
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
    
    fprintf(nomealunotxt, "Tempo Dispon�vel para Estudo (em minutos): %d\n", aluno->tempoDisponivel);// tempo disponivel do aluno
    fprintf(nomealunotxt, "Quantidade de Quest�es que Deseja Responder: %d\n", aluno->questoesPorEstudo);//quantidade quest�es
    
    fclose(nomealunotxt);
}

void gerarCronograma(Aluno aluno){

    // Calcula o tempo dispon�vel para estudo por disciplina
    int tempoPorDisciplina = aluno.tempoDisponivel / aluno.quantdisciplinas;
    Sleep(500);

    printf("Cronograma de Estudo para o aluno: %s\n", aluno.nome );
    for (int i = 0; i < aluno.quantdisciplinas; i++){  // Loop para mostrar o tempo de estudo para cada disciplina
        Sleep(500);
        printf("Disciplina: %s, = %d minutos de estudo\n", aluno.disciplinas[i], tempoPorDisciplina);
    }
    Sleep(500);
    printf("Resolu��o de quest�es: %d quest�es", aluno.questoesPorEstudo);// Exibe a quantidade de quest�es que o aluno deseja resolver
    Sleep(1000);
}

void cadastrarQuestao(Questao * questao){
    int contstring;
    Sleep(500);
    do{
    printf("Mat�ria: ");
    fgets(questao -> materia, 80, stdin);
    contstring = strlen(questao->materia);
    Sleep(600);
    }while(contstring <= 1);
    questao -> materia[strcspn(questao -> materia, "\n")] = '\0';
    do{
        printf("Enunciado da quest�o: ");
        fgets(questao -> enunciado, 250, stdin);
        contstring = strlen(questao->enunciado);
    }while(contstring <= 1);
    questao -> enunciado[strcspn(questao -> enunciado, "\n")] = '\0';
    Sleep(500);
    for(int i=0; i < 5;i++){ 
        do{
            printf("Alternativa %i: ",i+1);
            fgets(questao -> alternativas[i], 100, stdin);  
            contstring = strlen(questao->alternativas[i]); 
        }while(contstring <= 1) ;
    }
    do{
        printf("N�mero da quest�o correta(1 a 5): ");
        fgets(questao -> resposta, 100, stdin);
        contstring =strlen (questao->resposta);
    }while(contstring != 2);
    
    questao -> resposta[strcspn(questao -> resposta, "\n")] = '\0';
    Sleep(500);
    printf("Cadastrando...\n");
    Sleep(1000);
    printf("Quest�o cadastrada com Sucesso.");
    Sleep(1000);

     // Abre o arquivo para armazenar a quest�o cadastrada
    FILE * questaotxt = fopen(questao->materia,"a");
    fprintf(questaotxt, "Mat�ria: %s\n",questao->materia);
    fprintf(questaotxt,"Enunciado da quest�o: %s\n",questao->enunciado);
    for(int i=0; i <5; i++){
        fprintf(questaotxt,"Alternativa %i: ",i+1);
        fprintf(questaotxt,"%s",questao->alternativas[i]);
    }
    fprintf(questaotxt,"N�mero de quest�o correta(1 a 5): %s\n",questao->resposta);
    
    fclose(questaotxt);  // Fecha o arquivo apois a escrita

   
    FILE * listaquestoestxt = fopen("listamaterias.txt","a");  // Abre o arquivo para armazenar a lista de mat�rias
    fprintf(listaquestoestxt, "Mat�ria: %s\n",questao->materia); // Escreve a mat�ia no arquivo de lista de mat�rias
    
    fclose(listaquestoestxt); // Fecha o arquivo apois a escrita
    
}

void resolverQuestoes(Questao *questoes, int numQuestoes, int *acertos) {
    char resposta[100];
    int contstring;
    char rquestao[80];
    char buffer[255];

    FILE *lista;
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
    
    FILE *file = fopen(rquestao, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de quest�es.\n");
        return;
    }

    // Inicializa o contador de quest�es
    numQuestoes = 0;

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
    fclose(file);

    // exiba as quest�es
    for (int i = 0; i < numQuestoes; i++) {
        Sleep(500);

        // Exibe a mat�ria e o enunciado da quest�o
        printf("%s\n", questoes[i].materia);
        Sleep(500);
        printf("Quest�o %d: %s\n", i + 1, questoes[i].enunciado);
        Sleep(500);
        
        // Exibe as alternativas
        for (int j = 0; j < 5; j++) {
            printf("%s\n", questoes[i].alternativas[j]);
        }

        do {
            printf("\nSua resposta (1 a 5): ");
            fgets(resposta, 100, stdin);
            contstring = strlen(resposta);
            resposta[strcspn(resposta, "\n")] = '\0';
        } while (contstring <= 1);

        if (strcmp(resposta, questoes[i].resposta) == 0) { // Verifica se a resposta est� correta
            (*acertos)++;
        }
    }
}

void cadastrarMonitor(Monitor *monitor){
    int contstring;
    Sleep(500);
    do{
        printf("Nome do Monitor: ");
        fgets(monitor->nome, 50, stdin);
        contstring = strlen(monitor->nome);
    }while(contstring <=1);
    monitor->nome[strcspn(monitor->nome, "\n")] = '\0';
    (monitor->quant = 1); // Inicializa a quantidade de monitores
    Sleep(500);
    do{
        printf("Hor�rio disponivel para monitoria: ");
        fgets(monitor->horario, 80, stdin);
        contstring = strlen(monitor->horario);
    }while(contstring <= 5);
    monitor->horario[strcspn(monitor->horario, "\n")] = '\0';
    Sleep(500);
    do{
        printf("Telefone para contato: 9. ");
        fgets(monitor->telefone, 80, stdin);
        contstring = strlen(monitor->telefone);
    }while(contstring <= 8);
    monitor->telefone[strcspn(monitor->telefone, "\n")] = '\0';
    Sleep(500);
    printf("Cadastrando....\n");
    Sleep(600);
    printf("Monitor cadastrado com sucesso.\n");
    Sleep(1000);

    FILE *monitortxt = fopen("cadastromonitor.txt","a");  // Abre o arquivo para armazenar o monitor cadastrado

     // Escreve os dados do monitor no arquivo
    fprintf(monitortxt,"\nNome do Monitor: %s\n",monitor->nome);
    fprintf(monitortxt,"Hor�rio disponivel para monitoria: %s\n",monitor->horario);
    fprintf(monitortxt,"Telefone para contato:9.%s\n",monitor->telefone);
    fclose(monitortxt);
    
}

void consultarAlunos() {
    char consulta[11];  // Var�vel para armazenar a op��o de consulta
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
        Sleep(500);
        switch (opcao){
            case 1 :  // Acessa e ler o arquivo com a lista de todos os alunos
                lista = fopen("cadastroaluno.txt","r");
                if (lista == NULL) {
                    printf("Lista de alunos n�o encontrada\n");
                } else {
                    while (fgets(buffer, sizeof(buffer), lista)) { // Ler e imprime o conte�do do arquivo
                        printf("%s", buffer);  
                }
                fclose(lista); // Fecha o arquivo apois a leitura
                    }
       
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
        fgets(materia, 80, stdin);
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
            fclose(file);
            Sleep(800);
        }
    }
}

// Fun��o para consultar monitores
void consultarMonitores() {
    FILE *file;  // Ponteiro para o arquivo que armazena dados dos monitores
    char buffer[255]; // Buffer para ler linhas do arquivo
    printf("Consultar Monitores:\n");
    Sleep(500);
    while (1) {  // Loop para continuar a consulta at� que o us�rio decida sair
        file = fopen("cadastromonitor.txt", "r");  // Acessa e ler o arquivo com os dados dos monitores
        if (file == NULL) {
            printf("Monitor n�o encontrado.\n");
            break;
        } else { 
            while (fgets(buffer, sizeof(buffer), file)) { // Ler e imprime o conte�do do arquivo
                printf("%s", buffer);
            }
            fclose(file);
            Sleep(500);
            break;
        }
        /*printf("\nDigite 0 para voltar ao menu anterior: \n");
        fgets(sair, 80, stdin);
        sair[strcspn(sair, "\n")] = '\0';
        if (strcmp(sair, "0") == 0){
            break;

        }
       */ 
    }
}
 
void menuConsulta(){
    int opcao1; // Var�avel para armazenar a op��o escolhida pelo us�rio
    do{
            mostrarlinha(); // Fun��o para mostrar uma linha no console
            printf("\t    Menu Consulta Aluno\n\n");
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
    setlocale(LC_ALL, "Portuguese_Brazil"); // Configura a localiza��o para portugues do Brasil
    Aluno aluno; // Declara uma var�avel do tipo Aluno
    Questao questoes[10]; // Declara um array de Questao com capacidade para 10 quest�es
    questoes->quantQuest = 0; // Inicializa a quantidade de quest�es cadastradas para 0
    Monitor monitor;  // Declara uma var�avel do tipo Monitor
    monitor.quant = 0; // Inicializa a quantidade de monitores cadastrados para 0
    
    int numQuestoes = 0;  // Var�avel para armazenar o n�mero de quest�es cadastradas
    int opcao; // Var�avel para armazenar a op��o escolhida pelo us�rio
    int acertos; // Var�avel para armazenar o n�mero de acertos nas quest�es
    do{
        mostrarlinha();
        printf("\t    Menu\n\n");
        printf("1 -> Cadastrar Aluno\n");
        printf("2 -> Gerar Cronograma de Estudo\n");
        printf("3 -> Cadastrar Quest�es\n");
        printf("4 -> Resolver Quest�es\n");
        printf("5 -> Cadastrar Monitor\n");
        printf("6 -> Consultas:\n");
        printf("0 -> Sair");
        mostrarlinha();
        Sleep(400);
        printf("Escolha uma op��oo: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
            cadastrarAluno(&aluno);
            break;
            case 2:
            gerarCronograma(aluno);
            break;
            case 3:
            if (numQuestoes < 10){ // Verifica se o n�mero de quest�es � menor que 10
                cadastrarQuestao(&questoes[numQuestoes]); // Chama a fun��o para cadastrar uma nova quest�o
                numQuestoes++;  // Incrementa o n�mero de quest�es cadastradas
                questoes->quantQuest++; // Incrementa a quantidade de quest�es no array de quest�es
            }
            else{
                printf("Limite de quest�es atingida.\n");  // Mensagem de erro quando o limite de quest�es at� atingido
            }
            break;
            case 4:
                /*if (questoes->quantQuest == 0){ // Verifica se nenhuma quest�o foi cadastrada
                    printf("Analisando...\n");
                    Sleep(1000);
                    printf("**Nenhuma quest�o foi cadastrada ainda!**\n");
                    Sleep(1000);
                    break;
                }*/
                resolverQuestoes(questoes, numQuestoes, &acertos); // Chama a fun��o para resolver quest�es
                Sleep(600);
                printf("Voce acertou %d de %d quest�es. \n", acertos, numQuestoes); // Exibe o n�mero de acertos
                break;
            case 5:
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