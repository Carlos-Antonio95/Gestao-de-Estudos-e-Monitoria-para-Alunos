#include <stdio.h> // Inclui a biblioteca padrão de entrada e saida
#include <string.h> // Inclui a biblioteca para manipulação de strings
#include <locale.h> // Inclui a biblioteca para configuração de localidade
#include <stdlib.h>  // Inclui a biblioteca para funcionalidaes utilitarias
#include <windows.h> // Inclui a biblioteca para funções específicas do Windows

// Estrutura para armazenar informaçõeses de um aluno
typedef struct {
     char nome [80]; // Nome do aluno
    char curso [80]; // Curso do aluno
    char disciplinas [10][80]; // Lista de disciplinas (máximo de 10)
    char matriculaAluno[20];   // Matrícula do aluno
    int periodo,tempoDisponivel,questoesPorEstudo,quantdisciplinas;//Período em que o aluno está, tempo disponivel para estudo em minutos, Número de questões que o aluno deseja responder, Quantidade de disciplinas cadastradas
} Aluno;

// Estrutura para armazenar informações de uma questão
typedef struct {
    char materia [80]; // Matéria da questão
    char enunciado[250]; // Enunciado da questão
    char alternativas[5][1000];// Alternativas de resposta (máximo de 5)
    char resposta [100];    // Resposta correta (armazenada como string)
    int quantQuest;  // Quantidade total de questões
    int totQuest;// contador total questões
   
} Questao;

// Estrutura para armazenar informações de um monitor
typedef struct{
    char nome [80]; // Nome do monitor
    char horario[80]; // Horário disponivel do monitor
    char telefone[80];  // Telefone de contato do monitor
    int quant; // Quantidade de monitores
} Monitor;

// Função para exibir uma linha separadora no console
void mostrarlinha(){
    printf("\n-------------------------------\n");
}

// Função para cadastrar um aluno
void cadastrarAluno(Aluno *aluno){ 
    

    int contstring;
    //FILE *consulta;
    do{
        printf("Nome do Aluno: ");
        fgets(aluno -> nome, 50, stdin); // Linha a linha de entrada para o nome do aluno
        contstring = strlen(aluno->nome);  // Obtem o comprimento da string
    }while(contstring <= 1);  // Garante que o nome tenha pelo menos um caractere
    aluno -> nome[strcspn(aluno -> nome, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(600); // Pausa a execução por 600 milissegundos
    do{
        printf("Digite sua matrícula: ");
        fgets(aluno->matriculaAluno,20,stdin);  
        contstring = strlen(aluno->matriculaAluno);// Obtem o comprimento da string
    }while(contstring <= 10);//Garante que a matricula tenha pelo menos 10 caracteres
    aluno -> matriculaAluno[strcspn(aluno -> matriculaAluno, "\n")] = '\0'; // Remove a nova linha do final da string
    Sleep(500); // Pausa a execução por 500 milissegundos

    // Captura o curso do aluno

    do{
        printf("Curso: ");
        fgets(aluno -> curso, 50, stdin);// Lê a entrada do usuário
        contstring = strlen(aluno->curso);
    }while(contstring <= 1); //garantindo que não seja vazio
    aluno -> curso[strcspn(aluno -> curso, "\n")] = '\0';// Remove a nova linha do final da string
    Sleep(500);// Pausa a execução por 500 milissegundos

    // Captura o período em que o aluno está, garantindo que esteja entre 1 e 16

    do{
        printf("Periodo: ");
        scanf("%d", &aluno -> periodo);
        getchar(); // Limpa o buffer de entrada
    }while(aluno->periodo < 1 || aluno->periodo > 16); // Garante que o período esteja entre 1 e 16

    // Captura a quantidade de disciplinas, garantindo um valor entre 1 e 10

    do{
        printf("Quantidade de disciplinas MAX 10: ");
        scanf("%i",&aluno->quantdisciplinas);// Lê a entrada do usuário
        getchar();
     } while (aluno->quantdisciplinas > 10 || aluno->quantdisciplinas < 1); // Garante que a quantidade esteja entre 1 e 10

    for(int i = 0; i < aluno->quantdisciplinas; i++){
        Sleep(500); // Pausa a execução para melhorar a experiência do usuário
        do{
            printf("Disciplina %d: ", i + 1); 
            fgets(aluno -> disciplinas[i], 80, stdin); // Lê a entrada do nome da disciplina
            contstring = strlen(aluno->disciplinas[i]);
        }while(contstring <= 1);
        aluno -> disciplinas[i] [strcspn(aluno -> disciplinas[i], "\n")] = '\0'; // Remove a nova linha do final da string
    }
    Sleep(500); // Pausa a execução por 500 milissegundos
    do{
        printf("Tempo disponivel para estudo (em minutos): ");
        scanf("%d", &aluno -> tempoDisponivel);// Lê a entrada do usuário
        getchar(); // Limpa o buffer de entrada
        
    }while(aluno->tempoDisponivel <= 0 || aluno->tempoDisponivel > 1440);// Garante que o tempo esteja entre 1 minuto e 24 horas (1440 minutos)
    Sleep(500);
    do{
        printf("Quantidade de questões que deseja responder ao término do estudo: ");
        scanf("%d", &aluno -> questoesPorEstudo);// Lê a entrada do usuário
        getchar();
    }while(aluno->questoesPorEstudo <=0 || aluno->questoesPorEstudo > 10000); // Garante que a quantidade esteja entre 1 e 10.000
    Sleep(500); // Pausa a execução por 500 milissegundos

   
    printf("Cadastrando...\n");  // Mensagem de cadastro e gravação dos dados em arquivos
    Sleep(2000); // Pausa para simular o tempo de cadastro
    printf("Aluno cadastrado.");
    Sleep(1000); // Pausa a execução por 1 segundo
    
     // Cria e abre um arquivo com o nome do aluno (matrícula) para escrita
    FILE *alunotxt = fopen(aluno->matriculaAluno ,"w");
   
     // Escreve os dados do aluno no arquivo
    fprintf(alunotxt, "Nome: %s\n", aluno->nome);//função fprintf serve para escrever o nome do aluno no arquivo
    fprintf(alunotxt, "Matricula: %s\n", aluno->matriculaAluno);
    fprintf(alunotxt, "Curso: %s\n", aluno->curso);//função fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(alunotxt, "Periodo: %d\n", aluno->periodo);//função fprintf serve para escrever o periodo que o aluno esta
    fprintf(alunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//função fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar os nomes das disciplinas
        fprintf(alunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }
    
    fprintf(alunotxt, "Tempo Disponível para Estudo (em minutos): %d\n", aluno->tempoDisponivel);// tempo disponivel do aluno
    fprintf(alunotxt, "Quantidade de Questões que Deseja Responder: %d\n", aluno->questoesPorEstudo);//quantidade questões
    
    fclose(alunotxt);  // Escreve os dados do aluno no arquivo

    // Escreve os dados do aluno no arquivo
    FILE *nomealunotxt = fopen("cadastroaluno.txt","a");
   

    fprintf(nomealunotxt, "Nome: %s\n", aluno->nome);//função fprintf serve para escrever o nome do aluno no arquivo
    fprintf(nomealunotxt, "Matricula: %s\n", aluno->matriculaAluno);
    fprintf(nomealunotxt, "Curso: %s\n", aluno->curso);//função fprintf serve para escrever o nome do curso do aluno no arquivo
    fprintf(nomealunotxt, "Periodo: %d\n", aluno->periodo);//função fprintf serve para escrever o periodo que o aluno esta
    fprintf(nomealunotxt, "Quantidade de Disciplinas: %d\n", aluno->quantdisciplinas);//função fprintf serve para escrever a quantidade de disciplinas do aluno
    
    for (int i = 0; i < aluno->quantdisciplinas; i++) {//este for serve para listar o nome das disciplinas
        fprintf(nomealunotxt, "Disciplina %d: %s\n", i + 1, aluno->disciplinas[i]);
    }
    
    fprintf(nomealunotxt, "Tempo Disponível para Estudo (em minutos): %d\n", aluno->tempoDisponivel);// tempo disponivel do aluno
    fprintf(nomealunotxt, "Quantidade de Questões que Deseja Responder: %d\n", aluno->questoesPorEstudo);//quantidade questões
    
    fclose(nomealunotxt);  // Fecha o arquivo e salva
}

void gerarCronograma(Aluno aluno){

    // Calcula o tempo disponível para estudo por disciplina
    int tempoPorDisciplina = aluno.tempoDisponivel / aluno.quantdisciplinas;
    Sleep(500);

    printf("Cronograma de Estudo para o aluno: %s\n", aluno.nome );
    for (int i = 0; i < aluno.quantdisciplinas; i++){  // Loop para mostrar o tempo de estudo para cada disciplina
        Sleep(500);
        printf("Disciplina: %s, = %d minutos de estudo\n", aluno.disciplinas[i], tempoPorDisciplina);
    }
    Sleep(500);
    printf("Resolução de questões: %d questões", aluno.questoesPorEstudo);// Exibe a quantidade de questões que o aluno deseja resolver
    Sleep(1000);
}

void cadastrarQuestao(Questao * questao){
    int contstring; // Variável para contar o comprimento das strings
    Sleep(500); // Pausa para melhorar a experiência do usuário

    // Captura a matéria da questão

    do{
    printf("Matéria: ");
    fgets(questao -> materia, 80, stdin);// Lê a entrada do usuário
    contstring = strlen(questao->materia);// Armazena o comprimento da matéria
    Sleep(600); // Pausa para melhorar a experiência do usuário
    }while(contstring <= 1); //Continua pedindo se a entrada estiver vazia
    questao -> materia[strcspn(questao -> materia, "\n")] = '\0';// Remove a nova linha do final da string

    // Captura o enunciado da questão

    do{
        printf("Enunciado da questão: ");
        fgets(questao -> enunciado, 250, stdin); // Lê a entrada do usuário
        contstring = strlen(questao->enunciado); // Verifica o comprimento do enunciado
    }while(contstring <= 1); // Continua pedindo se a entrada estiver vazia
    questao -> enunciado[strcspn(questao -> enunciado, "\n")] = '\0'; // Remove a nova linha do final da string
    Sleep(500);  // Pausa para melhorar a experiência do usuário    

    // Captura as alternativas da questão

    for(int i=0; i < 5;i++){ 
        do{
            printf("Alternativa %i: ",i+1); 
            fgets(questao -> alternativas[i], 100, stdin);  // Lê a alternativa
            contstring = strlen(questao->alternativas[i]); // Verifica o comprimento da alternativa
        }while(contstring <= 1) ; // Continua pedindo se a entrada estiver vazia
    }

    // Captura a resposta correta

    do{
        printf("Número da questão correta(1 a 5): ");
        fgets(questao -> resposta, 100, stdin);// Lê a resposta correta
        contstring =strlen (questao->resposta);// Verifica o comprimento da resposta
    }while(contstring != 2); // Continua pedindo se a entrada estiver vazia
    
    questao -> resposta[strcspn(questao -> resposta, "\n")] = '\0'; // Remove a nova linha da resposta
    Sleep(500); // Pausa para melhorar a experiência do usuário
    printf("Cadastrando...\n");
    Sleep(1000);// Pausa para simular o tempo de cadastro
    printf("Questão cadastrada com Sucesso.");
    Sleep(1000);// Pausa para simular o tempo de cadastro

     // Abre o arquivo para armazenar a questão cadastrada
    FILE * questaotxt = fopen(questao->materia,"a"); // Grava a matéria no arquivo
    fprintf(questaotxt, "Matéria: %s\n",questao->materia);
    fprintf(questaotxt,"Enunciado da questão: %s\n",questao->enunciado);
    for(int i=0; i <5; i++){
        fprintf(questaotxt,"Alternativa %i: ",i+1);
        fprintf(questaotxt,"%s",questao->alternativas[i]);
    }
    fprintf(questaotxt,"%s\n",questao->resposta);//Vai imprimir no banco de dados apenas o número da resposata, assim facilitando na hora da comparação
    
    fclose(questaotxt);  // Fecha o arquivo apois a escrita

    // Grava a matéria na lista de matérias
    FILE * listaquestoestxt = fopen("listamaterias.txt","a");  // Abre o arquivo para armazenar a lista de matérias
    fprintf(listaquestoestxt, "Matéria: %s\n",questao->materia); // Escreve a matéia no arquivo de lista de matérias
    
    fclose(listaquestoestxt); // Fecha o arquivo apois a escrita
    
}

void resolverQuestoes(Questao *questoes, int numQuestoes, int *acertos) {
    char resposta[100]; // Variável para armazenar a resposta do usuário
    int contstring; // Variável para contar o comprimento das strings
    char rquestao[80];// Variável para armazenar a matéria selecionada pelo usuário
    char buffer[255]; // Buffer para leitura de linhas do arquivo

    FILE *lista;// Ponteiro para o arquivo da lista de matérias
    *acertos = 0; // Inicializa o contador de acertos
        printf("Lista de todas as Disciplinas disponíveis para estudo:\n");
        lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), lista)) {
                printf("%s", buffer);
               
                
        }
        fclose(lista);   // Fecha o arquivo apois a leitura

    printf("Qual matéria você deseja resolver as questões?\n");
    fgets(rquestao, 80, stdin);
    rquestao[strcspn(rquestao, "\n")] = '\0'; // Remove nova linha
    
    FILE *file = fopen(rquestao, "r"); // Abre o arquivo da matéria selecionada
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de questões.\n");
        return;// Retorna em caso de erro
    }

    // Inicializa o contador de questões
    numQuestoes = 0;

    // Lê as questões do arquivo

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

        (numQuestoes)++; // Incrementa o número de questões lidas
    }
    fclose(file); // Fecha o arquivo de questões

    printf("Quantas questões deseja responder de %s: ",rquestao);//solicita ao usuário a quantidade de questões que deseja responder 
    scanf("%i",&numQuestoes);
    getchar();
    questoes->totQuest = numQuestoes;// recebe o número de questão que o usuário deseja responder, para mostrar no fim do questionario
    // exiba as questões
    for (int i = 0; i < numQuestoes; i++) {
        Sleep(500); // Pausa para melhorar a experiência do usuário

        // Exibe a matéria e o enunciado da questão
        printf("%s\n", questoes[i].materia);
        Sleep(500);
        printf("Questão %d: %s\n", i + 1, questoes[i].enunciado);
        Sleep(500);
        
        // Exibe as alternativas
        for (int j = 0; j < 5; j++) {
            printf("%s\n", questoes[i].alternativas[j]);
        }

    // Solicita a resposta do usuário

        do {
            printf("Número da questão correta(1 a 5): ");
            fgets(resposta, 100, stdin); // Lê a resposta
            contstring = strlen(resposta); // Verifica o comprimento da resposta
            resposta[strcspn(resposta, "\n")] = '\0'; // Remove nova linha
        } while (contstring <= 1); // Continua pedindo se a entrada estiver vazia
        if (strcmp(resposta, questoes[i].resposta) == 0) { // Verifica se a resposta está correta
            (*acertos)++;
            printf("Você acerto a questão.\n");//Vi dizer ao usuário se ele acertou ou não, vai ser retirado depois vamos dexiar para facilitar o estudo durante as provas
        }
        
    }
}

void cadastrarMonitor(Monitor *monitor){
    int contstring;
    Sleep(500);// Pausa a execução por 500 milissegundos antes de iniciar o cadastro
    do{
        printf("Nome do Monitor: ");
        fgets(monitor->nome, 50, stdin); // Captura o nome do monitor
        contstring = strlen(monitor->nome);
    }while(contstring <=1); //garantindo que não seja vazio
    monitor->nome[strcspn(monitor->nome, "\n")] = '\0'; // Remove o caractere de nova linha
    (monitor->quant = 1); // Inicializa a quantidade de monitores
    Sleep(500); // Pausa a execução por 500 milissegundos

    // Captura o horário disponível para monitoria, garantindo que seja maior que 5 caracteres

    do{
        printf("Horário disponivel para monitoria: ");
        fgets(monitor->horario, 80, stdin); // Lê a entrada do horário
        contstring = strlen(monitor->horario); 
    }while(contstring <= 5);// Garante que o horário tenha pelo menos 5 caracteres
    monitor->horario[strcspn(monitor->horario, "\n")] = '\0'; // Remove o caractere de nova linha
    Sleep(500); // Pausa a execução por 500 milissegundos
    do{
        printf("Telefone para contato: 9. ");
        fgets(monitor->telefone, 80, stdin); // Lê a entrada do telefone
        contstring = strlen(monitor->telefone);
    }while(contstring <= 8); // Garante que o telefone tenha pelo menos 8 caracteres
    monitor->telefone[strcspn(monitor->telefone, "\n")] = '\0';  // Remove o caractere de nova linha
    Sleep(500);// Pausa a execução por 500 milissegundos
    printf("Cadastrando....\n");
    Sleep(600); // Pausa a execução para simular o tempo de cadastro
    printf("Monitor cadastrado com sucesso.\n");
    Sleep(1000);// Pausa a execução para simular o tempo de cadastro

    FILE *monitortxt = fopen("cadastromonitor.txt","a");  // Abre o arquivo para armazenar o monitor cadastrado

     // Escreve os dados do monitor no arquivo
    fprintf(monitortxt,"\nNome do Monitor: %s\n",monitor->nome); // Escreve o nome do monitor
    fprintf(monitortxt,"Horário disponivel para monitoria: %s\n",monitor->horario); // Escreve o horário disponível
    fprintf(monitortxt,"Telefone para contato:9.%s\n",monitor->telefone);  // Escreve o telefone, prefixando com '9.'
    fclose(monitortxt);// Fecha o arquivo após a escrita
    
}

void consultarAlunos() {
    char consulta[11];  // Varível para armazenar a opção de consulta
    FILE *file;  // Ponteiro para o arquivo que armazena dados de um aluno específico
    FILE *lista;  // Ponteiro para o arquivo que armazena a lista de todos os alunos
    char matricula[80]; // Varíavel para armazenar a matrícula do aluno para consulta
    char buffer[255]; // Buffer para ler linhas dos arquivos
    int opcao;  // Varíavel para armazenar a opçãoo selecionada pelo usúario // Varíavel para armazenar a opção selecionada pelo usúario
    int parar = 1;   // Varíavel de controle para o loop de consulta
    printf("Consultar Alunos: \n");
    Sleep(500);

    while (parar == 1) {  // Loop para continuar a consulta até que o usúario decida sair
        printf("\n1 -> Acessar toda a lista de alunos cadastrados:\n");
        printf("2 -> Consultar um aluno por matricula:\n");
        printf("0 -> Voltar ao menu anterior\n");
        printf("Sua opção: ");
        scanf("%i",&opcao); // Ler a opção escolhida pelo usúrio
        getchar(); // Limpa o buffer de entrada
        Sleep(500);
        switch (opcao){
            case 1 :  // Acessa e ler o arquivo com a lista de todos os alunos
                lista = fopen("cadastroaluno.txt","r");
                if (lista == NULL) {
                    printf("Lista de alunos não encontrada\n");
                } else {
                    while (fgets(buffer, sizeof(buffer), lista)) { // Ler e imprime o conteudo do arquivo
                        printf("%s", buffer);  
                }
                fclose(lista); // Fecha o arquivo apois a leitura
                    }
       
                break;
            case 2 :

                // Consulta um aluno específico pela matrícula
                printf("Digite a matricula do aluno:");
                fgets(matricula, 80, stdin);
                Sleep(500);
                matricula[strcspn(matricula, "\n")] = '\0';
                if (strcmp(matricula, "0") == 0){
                    break;
                }
                file = fopen(matricula, "r"); // Acessa e ler o arquivo correspondente e matrícula do aluno
                if (file == NULL) {
                    printf("Aluno não encontrado.\n");
                    break;
            } else {
                while (fgets(buffer, sizeof(buffer), file)) {  
                printf("%s", buffer);// Ler e imprime o conteúdo do arquivo
            }
            fclose(file);
                }
                break;
            case 0: // Sai do loop e volta ao menu anterior
            parar ++;
                break;
            default:
                printf("Operação invalida.");
                break;
        }
        
    }
}

// Função para consultar questoes
void consultarQuestoes() {
    FILE *lista;  // Ponteiro para o arquivo que armazena a lista de disciplinas
    FILE *file; // Ponteiro para o arquivo que armazena as questões de uma disciplina
    char materia[80];   // Varíavel para armazenar o nome da disciplina para consulta
    char buffer[255];  // Buffer para ler linhas dos arquivos
    printf("Consultar Questões:\n");
    Sleep(500);
    while (1) { // Loop para continuar a consulta até que o usúrio decida sair 
        printf("Lista de todas as Disciplinas disponíveis para estudo:\n");
        lista = fopen("listamaterias.txt","r"); // Acessa e ler o arquivo com a lista de todas as disciplinas
        while (fgets(buffer, sizeof(buffer), lista)) {
                printf("%s", buffer);
        }
        fclose(lista);   // Fecha o arquivo apois a leitura
        
        printf("Digite a disciplina  para consultar (ou '0' para voltar ao menu anterior): \n"); // Solicita ao usúrio o nome da disciplina para consultar questões
        fgets(materia, 80, stdin);
        materia[strcspn(materia, "\n")] = '\0';
        if (strcmp(materia, "0") == 0){  // Se o usúrio digitar "0", sai do loop
             break;
        }
        file = fopen(materia, "r");  // Acessa e ler o arquivo correspondente á disciplina
        if (file == NULL) {
            printf("Questão não encontrada.\n");
            Sleep(800);
        } else {
            while (fgets(buffer, sizeof(buffer), file)) { // Ler e imprime o conteúdo do arquivo
                printf("%s", buffer);
                Sleep(300);
            }
            fclose(file);
            Sleep(800);
        }
    }
}

// Função para consultar monitores
void consultarMonitores() {
    FILE *file;  // Ponteiro para o arquivo que armazena dados dos monitores
    char buffer[255]; // Buffer para ler linhas do arquivo
    printf("Consultar Monitores:\n");
    Sleep(500);
    while (1) {  // Loop para continuar a consulta até que o usúrio decida sair
        file = fopen("cadastromonitor.txt", "r");  // Acessa e ler o arquivo com os dados dos monitores
        if (file == NULL) {
            printf("Monitor não encontrado.\n");
            break;
        } else { 
            while (fgets(buffer, sizeof(buffer), file)) { // Ler e imprime o conteúdo do arquivo
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
    int opcao1; // Varíavel para armazenar a opção escolhida pelo usúrio
    do{
            
            mostrarlinha(); // Função para mostrar uma linha no console
            printf("\t    Menu Consulta Aluno\n\n");
            printf("1 -> Consultar Aluno\n");
            printf("2 -> Consultar Questões\n");
            printf("3 -> Consultar Monitor\n");
            printf("0 -> Voltar para tela anterior");
            mostrarlinha(); // Função para mostrar uma linha no console
            printf("Ecolha uma opção: ");
            scanf("%i",&opcao1);  // Ler a opção escolhida pelo usúrio
            getchar(); // Limpa o buffer do teclado
            switch (opcao1){  // Switch para executar a apção com base na opção escolhida

                case 1:
                    consultarAlunos();  // Chama a função para consultar alunos
                    break;
                case 2:
                    consultarQuestoes();  // Chama a função para consultar questï¿½es
                    break; 
                case 3:
                    consultarMonitores(); // Chama a função para consultar monitores
                    break;
                case 0:
                    printf("Retornando a tela principal.\n");
                    Sleep(1000);
                    break;
                default:
                    printf("Operação invalida."); // Mensagem de erro para opção inválida
                    break;
            }
    }while(opcao1 != 0);   
}
   
int main(){
    FILE *materias;
    setlocale(LC_ALL, "Portuguese_Brazil"); // Configura a localização para portugues do Brasil
    Aluno aluno; // Declara uma varíavel do tipo Aluno
    Questao questoes[10]; // Declara um array de Questao com capacidade para 10 questões
    questoes->quantQuest = 0; // Inicializa a quantidade de questões cadastradas para 0
    Monitor monitor;  // Declara uma varíavel do tipo Monitor
    monitor.quant = 0; // Inicializa a quantidade de monitores cadastrados para 0
    
    int numQuestoes = 0;  // Varíavel para armazenar o número de questões cadastradas
    int opcao; // Varíavel para armazenar a opção escolhida pelo usúrio
    int acertos; // Varíavel para armazenar o número de acertos nas questões
    do{
        mostrarlinha();
        printf("\t    Menu\n\n");
        printf("1 -> Cadastrar Aluno\n");
        printf("2 -> Gerar Cronograma de Estudo\n");
        printf("3 -> Cadastrar Questões\n");
        printf("4 -> Resolver Questões\n");
        printf("5 -> Cadastrar Monitor\n");
        printf("6 -> Consultas:\n");
        printf("0 -> Sair");
        mostrarlinha();
        Sleep(400);
        printf("Escolha uma opção: ");
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
            if (numQuestoes < 10){ // Verifica se o número de questões ï¿½ menor que 10
                cadastrarQuestao(&questoes[numQuestoes]); // Chama a função para cadastrar uma nova questï¿½o
                numQuestoes++;  // Incrementa o nï¿½mero de questões cadastradas
                questoes->quantQuest++; // Incrementa a quantidade de questões no array de questões
            }
            else{
                printf("Limite de questões atingida.\n");  // Mensagem de erro quando o limite de questões até atingido
            }
            break;
            case 4:
                materias = fopen("listamaterias.txt","r");
                if (materias == NULL){ // Verifica se nenhuma questão foi cadastrada
                    printf("Analisando...\n");
                    Sleep(1000);
                    printf("**Nenhuma questão foi cadastrada ainda!**\n");
                    Sleep(1000);
                    break;
                }else{
                resolverQuestoes(questoes, numQuestoes, &acertos); // Chama a função para resolver questões
                Sleep(600);
                printf("Voce acertou %d de %d questões. \n", acertos, questoes->totQuest); // Exibe o número de acertos
                }
                break;
            case 5:
                cadastrarMonitor(&monitor); // Chama a função para cadastrar um monitor
                break;
            case 6:
                menuConsulta(); // Chama a função para acessar o menu de consulta
                break;
            case 0:
                printf("Saindo do Programa...\n");
                Sleep(1000);
                printf("Programa FINALIZADO.");
                Sleep(1000);
                break;
            default:
                printf("Operação invalida, tente novamente.\n");
        }
    }while (opcao != 0); // Continua no menu até que o usúrio escolha a opção 0 para sair
return 0; // Retorna 0 indicando que o programa terminou com sucesso
}   