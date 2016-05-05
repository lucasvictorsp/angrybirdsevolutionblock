/* 
 * File:   CriaBlockEvoluido.cpp
 * Author: Lucas Victor Silva Pereira es71512
 * 
 * Created on 09 de Abril de 2016, 09:38
 */

#include <fstream>
#include <iostream>
#include <cstdlib> //função rand() e função exit()
#include <string>
#include <sstream> //uso da função stringstream na criação do nome dos arquivos de saída, especificamente na criação da variavel (stringstream auxStringNumberXml;) na função (void openFileWrite)

#include <cmath> //Biblioteca que implementa funções matematicas, usada na criação da função espelho (usando o modulo)   --->//já foi adicionado no Block.h
#include <vector> //Biclioteca para trabalhar com array sem a necessidade de estipular tamanho pra eles
//#include <list> //foi substituida pela biblioteca <vector> visto que ela é masi simples de manipular, mais facil de acessar os elementose mais rapida
//#include <cstdlib>
//#include <cstdio>
#include <iomanip> //biblioteca usada nesse codigo com a função setprecision()
#include <unistd.h> //implementa a função sleep(float) usanda em alguns DEBUGS

#include "Block.h"

using std::ofstream;
using std::ifstream;
using std::ios;
using std::cerr;
using std::cout;
using std::endl;
using std::fflush;
using std::cin;
using std::string;
using std::stringstream;
using std::ostringstream;
using std::abs;
using std::setprecision;
using std::fixed;
using std::vector;
//ssing std::list;

#define CIRCLEX 8
#define CIRCLEY 7
#define SMALLCIRCLEX 4
#define SMALLCIRCLEY 3
#define RECTBIGLYINGX 2
#define RECTBIGLYINGY 20
#define RECTFATLYINGX 4
#define RECTFATLYINGY 8
#define RECTMEDIUMLYINGX 2
#define RECTMEDIUMLYINGY 17
#define RECTSMALLLYINGX 2
#define RECTSMALLLYINGY 8
#define RECTTINYLYINGX 2
#define RECTTINYLYINGY 4
#define SQUAREHOLEXY 8
#define SQUARESMALLXY 4
#define SQUARETINYXY 2
#define TRIANGLEXY 8
#define TRIANGLEHOLEX 8
#define TRIANGLEHOLEY 9
#define TRIANGLEMIRRORXY 8
#define PLATAFORMXY 6


const int Circle[CIRCLEX][CIRCLEY] = {0, 0, 1, 1, 1, 0, 0,
                                      0, 1, 1, 1, 1, 1, 0,
                                      1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1,
                                      0, 1, 1, 1, 1, 1, 0,
                                      0, 0, 1, 1, 1, 0, 0};

const int SmallCircle[SMALLCIRCLEX][SMALLCIRCLEY] = {0, 1, 0,
                                                     1, 1, 1,
                                                     1, 1, 1,
                                                     0, 1, 0};

const int RectBigLying[RECTBIGLYINGX][RECTBIGLYINGY] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const int RectBigStanding[RECTBIGLYINGY][RECTBIGLYINGX] = {1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1,
                                                           1, 1};


const int RectFatLying[RECTFATLYINGX][RECTFATLYINGY] = {1, 1, 1, 1, 1, 1, 1, 1,
                                                        1, 1, 1, 1, 1, 1, 1, 1,
                                                        1, 1, 1, 1, 1, 1, 1, 1,
                                                        1, 1, 1, 1, 1, 1, 1, 1};

const int RectFatStanding[RECTFATLYINGY][RECTFATLYINGX] = {1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1};

const int RectMediumLying[RECTMEDIUMLYINGX][RECTMEDIUMLYINGY] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const int RectMediumStanding[RECTMEDIUMLYINGY][RECTMEDIUMLYINGX] = {1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1,
                                                                    1, 1};

const int RectSmallLying[RECTSMALLLYINGX][RECTSMALLLYINGY] = {1, 1, 1, 1, 1, 1, 1, 1,
                                                              1, 1, 1, 1, 1, 1, 1, 1};

const int RectSmallStanding[RECTSMALLLYINGY][RECTSMALLLYINGX] = {1, 1,
                                                                 1, 1,
                                                                 1, 1,
                                                                 1, 1,
                                                                 1, 1,
                                                                 1, 1,
                                                                 1, 1,
                                                                 1, 1};

const int RectTinyLying[RECTTINYLYINGX][RECTTINYLYINGY] = {1, 1, 1, 1,
                                                           1, 1, 1, 1};

const int RectTinyStanding[RECTTINYLYINGY][RECTTINYLYINGX] = {1, 1,
                                                              1, 1,
                                                              1, 1,
                                                              1, 1};

const int SquareHole[SQUAREHOLEXY][SQUAREHOLEXY] = {1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1};

const int SquareSmall[SQUARESMALLXY][SQUARESMALLXY] = {1, 1, 1, 1,
                                                       1, 1, 1, 1,
                                                       1, 1, 1, 1,
                                                       1, 1, 1, 1};

const int SquareTiny[SQUARETINYXY][SQUARETINYXY] = {1, 1,
                                                    1, 1};

const int Triangle[TRIANGLEXY][TRIANGLEXY] = {1, 0, 0, 0, 0, 0, 0, 0,
                                              1, 1, 0, 0, 0, 0, 0, 0,
                                              1, 1, 1, 0, 0, 0, 0, 0,
                                              1, 1, 1, 1, 0, 0, 0, 0,
                                              1, 1, 1, 1, 1, 0, 0, 0,
                                              1, 1, 1, 1, 1, 1, 0, 0,
                                              1, 1, 1, 1, 1, 1, 1, 0,
                                              1, 1, 1, 1, 1, 1, 1, 1};

const int TriangleHole[TRIANGLEHOLEX][TRIANGLEHOLEY] = {0, 0, 0, 0, 1, 0, 0, 0, 0,
                                                        0, 0, 0, 1, 1, 1, 0, 0, 0,
                                                        0, 0, 0, 1, 1, 1, 0, 0, 0,
                                                        0, 0, 1, 1, 1, 1, 1, 0, 0,
                                                        0, 0, 1, 1, 1, 1, 1, 0, 0,
                                                        0, 1, 1, 1, 1, 1, 1, 1, 0,
                                                        0, 1, 1, 1, 1, 1, 1, 1, 0,
                                                        1, 1, 1, 1, 1, 1, 1, 1, 1};

const int TriangleMirror[TRIANGLEXY][TRIANGLEXY] = {0, 0, 0, 0, 0, 0, 0, 1,
                                                    0, 0, 0, 0, 0, 0, 1, 1,
                                                    0, 0, 0, 0, 0, 1, 1, 1,
                                                    0, 0, 0, 0, 1, 1, 1, 1,
                                                    0, 0, 0, 1, 1, 1, 1, 1,
                                                    0, 0, 1, 1, 1, 1, 1, 1,
                                                    0, 1, 1, 1, 1, 1, 1, 1,
                                                    1, 1, 1, 1, 1, 1, 1, 1};

const int Plataform[6][6] = {1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1};

#define XMAXIMUM 13.16
//#define XMINIMUM -12.80
//#define XMINUMUMGOOD -5.0
//#define XMEDIUM 0.23
//#define XMEDIUMGOOD 4.08
#define YMAXIMUM 7.06
#define YMINIMUM -2.91
//#define YMEDIUM 10.08
#define DESCRETIZACAOGRID 0.1
#define PRECISION 1 //quantidade de casas depois da virgula


//Funcitoins
void ReadFile(vector<string> & , vector<string> & , vector<string> & , vector<string> &);


void openFileWrite(const int , const Block * , const int , const double * );
void openFileWrite(const int , int ** , const int , const int , const bool = false);


double round(double);

double roundDown(double);


double calculationObjectMirror(const Block & , double);

double changePositionObjectMirror(const Block & , float);


void resetMatrix(int **, int );


bool checkPositionGrid(Block & , int , int , int ** , const int , const int , const int , double & , double & );


void RetornaMatrixEstadoAnterior(int ** , const Block & , int , int , bool );


void backtracking(int **, Block * , double *, int, const int, const int, const int , const double );


//Variaveis Globais
const int sizeYGrid = (((int) ((YMAXIMUM - (YMINIMUM)) / DESCRETIZACAOGRID)) + 1); // + (2 * moreXY);
const string head = "<?xml version=\"1.0\" encoding=\"utf-16\"?>\n<Level>\n   <BirdsAmount>";
const string afterBirds = "</BirdsAmount>\n   <GameObjects>\n";
const string finishedXml = "   </GameObjects>\n</Level>";

bool finished = false;
int contNiveisCridos = 0;
int numberXml = 0;


int main(){
    clock_t time1, time2, time_diff;
    srand(time(NULL));

  vector<string> materiais;
  vector<string> birds;
  vector<string> pigs;
  vector<string> block;

  ReadFile(materiais, birds, pigs, block);

    double positionXinicial;
    do{
        cout << "Digite um valor (numero real) inicial de x onde os blocos pode ser posicionados em tela (>= -7.4, preferencialmente >= -5.0 e <= 9.0): ";
        cin >> positionXinicial;
        if(positionXinicial < -7.4 && positionXinicial > 9){
            cerr << "Valor de entrada inicial pra x invalido.\nPor favor: ";
        }
    } while(positionXinicial < -7.4 && positionXinicial > 9);
    double positionXMiddle = (XMAXIMUM - positionXinicial) / 2;

    positionXMiddle += positionXinicial; // ESPELHO = abs(positionXObject) + positionXMiddle;

    unsigned int numBlocks; //rand();
    do{
        cout << "Digite um numero (inteiro) de blocos que deseja ter em tela (>= 3): ";
        cin >> numBlocks;
        if(numBlocks < 3){
            cerr << "numero de blocos invalidos.\nPor favor: ";
        }
    } while(numBlocks < 3);

    float percentagem; //rand();
    do{
        cout << "Deseja ter uma variação da simetrica nos niveis (porcentagem de chance, valor entre 0, 1, onde 0 é igual a não ter e 1 igual a todos objetos com variações): ";
        cin >> percentagem;
        if((percentagem < 0) || (percentagem > 1)){
            cerr << "Valor da porcentavgem é invalidos.\nPor favor: ";
        }
    } while((percentagem < 0) || (percentagem > 1));
    cout << "--------------------------------------------------------------------------------------------------\n";

    unsigned int auxSelecionaBlock;
    Block arrayBlocks[numBlocks];

    for(int i = 0; i < numBlocks; i++){
        if(i == 0){
            auxSelecionaBlock = 4;
        } else if(i == 1){
            auxSelecionaBlock = 3;
        } else {
            auxSelecionaBlock = 2;
        }//*/
        //auxSelecionaBlock = rand() % block.size();
        arrayBlocks[i].setId(auxSelecionaBlock);
        arrayBlocks[i].setName(block[auxSelecionaBlock]);
        arrayBlocks[i].setMaterial(materiais[rand() % materiais.size()]);
    }

/*for(int i = 0; i < numBlocks; i++){
        cout << arrayBlocks[i] << '\n';
}//*/

    int sizeXGrid = ((int) (round((positionXMiddle - (positionXinicial)) / DESCRETIZACAOGRID))) + 1; // + (2 * moreXY);
    int sizeXGridMatriz = sizeXGrid + (RECTBIGLYINGY - 1);

        //Declaração dinamica da matriz de pontos
    int **drawGrid = new int*[sizeXGridMatriz];

    for(int i = 0; i < sizeXGridMatriz; i++){
        drawGrid[i] = new int[sizeYGrid];
    }
        //fim da declaração dinamica

/*for(int i = 0; i < sizeYGrid; i++){
        for(int j = 0; j < sizeXGrid; j++){
                cout << drawGrid[j][i] << ' ';
        }
        cout << '\n';
}//*/

        //------------------------------------------------------------------------------------- CRIANDO BLOCKS CONEXOS INICIO -------------------------------------------------------------------------------------\\//
    int contBlocks = 0;
    double auxXmirror[numBlocks] = {-9};
    resetMatrix(drawGrid, sizeXGridMatriz);
    time1 = clock() / (CLOCKS_PER_SEC / 1000);
    backtracking(drawGrid, arrayBlocks, auxXmirror, contBlocks, numBlocks, sizeXGrid, sizeXGridMatriz, positionXinicial);
    time2 = clock() / (CLOCKS_PER_SEC / 1000);
    time_diff = time2 - time1;
    cout << "time_diff = " << time_diff << endl;
    cout << "cont Niveis Criados = " << contNiveisCridos << endl; //*/
    
    ofstream arqDadosExecucao;
    arqDadosExecucao.open("Dados Da Execucao.txt", ios::out); //abre o arquivo para escrita com ponteiro iniciando no começo do arquivo (arquivo "*.xml")

    if(arqDadosExecucao.fail()){ //verifica se a abertura foi feita corretamente, caso contrario ele apresenta uma mensagem...
        cerr << "Falha ao abrir arquivo de escrita para guarda os dados da execucao.\n"; //de erro na tela e returna 1 finaliando o programa.
        exit(1);
    } else {
        arqDadosExecucao << "Os Blocos usados nesta execucao são:\n";
        for(int i = 0; i < numBlocks; i++){
            arqDadosExecucao << "Block-" << i << ":\nId = " << arrayBlocks[i].getId() << "\nNome = " << arrayBlocks[i].getName() << "\n\n";
        }
        arqDadosExecucao << "\nTotal de niveis Gerados = " << contNiveisCridos << '\n';
        arqDadosExecucao << "Tempo total gasto na execucao dos dados = " << time_diff << " milissegundos\n";
    }
    arqDadosExecucao.close();
        //------------------------------------------------------------------------------------- CRIANDO BLOCKS CONEXOS INICIO -------------------------------------------------------------------------------------\\//

    return 0;
}

void ReadFile(vector<string> & materiais, vector<string> & birds, vector<string> & pigs, vector<string> & block){
  //ofstream arqCriaBoxColliderBlocks;

  ifstream arqCSAngryBirds;
  arqCSAngryBirds.open("ABConstants.cs", ios::in); //abre o arquivo ABConstants.cs, que esta no caminho ../ScienceBirds-master/Assets/Scripts/Utils/, a partir da pasta deste arquivo

    if (arqCSAngryBirds.fail()) { //verifica se a abertura foi feita corretamente, caso contrario ele apresenta uma mensagem...
        cerr << "Falha ao abrir arquivo de Leitura.\n"; //de erro na tela e returna 1 finaliando o programa.
        exit(1);
    }

    bool finishedRead = false;
    string leArquivoAngryBirds;
    while(arqCSAngryBirds >> leArquivoAngryBirds){
      if(leArquivoAngryBirds == "enum"){
        arqCSAngryBirds >> leArquivoAngryBirds;
        if(leArquivoAngryBirds == "MATERIALS"){
          while(arqCSAngryBirds >> leArquivoAngryBirds){
            if(leArquivoAngryBirds == "{" || leArquivoAngryBirds == ","){
              continue;
            } else if(leArquivoAngryBirds == "};"){
              break;
            }
            materiais.push_back(leArquivoAngryBirds);
          }
        } else if(leArquivoAngryBirds == "BIRDS"){
          while(arqCSAngryBirds >> leArquivoAngryBirds){
            if(leArquivoAngryBirds == "{" || leArquivoAngryBirds == ","){
              continue;
            } else if(leArquivoAngryBirds == "};"){
              break;
            }
            birds.push_back(leArquivoAngryBirds);
          }
        } else if(leArquivoAngryBirds == "PIGS"){
          while(arqCSAngryBirds >> leArquivoAngryBirds){
            if(leArquivoAngryBirds == "{" || leArquivoAngryBirds == ","){
              continue;
            } else if(leArquivoAngryBirds == "};"){
              break;
            }
            pigs.push_back(leArquivoAngryBirds);
          }
        } else if(leArquivoAngryBirds == "BLOCKS"){
          while(arqCSAngryBirds >> leArquivoAngryBirds){
            if(leArquivoAngryBirds == "{" || leArquivoAngryBirds == ","){
              continue;
            } else if(leArquivoAngryBirds == "};"){
              break;
            }
            block.push_back(leArquivoAngryBirds);
          }
          finishedRead = true;
        }
        if(finishedRead){
          break;
        } 
      }
    }
}

void openFileWrite(const int numberXml, const Block *arrayBlocks, const int numBlocks, const double * auxXmirror){
    string xml = "testeBlockEvoluido-"; 
    int numBrids;

    //Parte do codigo que transforma a variavel numberXml(int) em uma string
    stringstream auxStringNumberXml;
    auxStringNumberXml << numberXml;
    xml += auxStringNumberXml.str();
    xml += ".xml";

    ofstream arqXml;
    arqXml.open(xml.c_str(), ios::out); //abre o arquivo para escrita com ponteiro iniciando no começo do arquivo (arquivo "*.xml")

    if(arqXml.fail()){ //verifica se a abertura foi feita corretamente, caso contrario ele apresenta uma mensagem...
        cerr << "Falha ao abrir arquivo de escrita.\n"; //de erro na tela e returna 1 finaliando o programa.
        exit(1);
    }

    arqXml << head;
    numBrids = (rand() % 5) + 1;
    arqXml << numBrids;
    arqXml << afterBirds;
    for(int i = 0; i < numBlocks; i++){
    arqXml << "      <Block type=\"" << arrayBlocks[i].getName() << "\" material=\"" << arrayBlocks[i].getMaterial() << "\" x=\"" << arrayBlocks[i].getX() << "\" y=\"" << arrayBlocks[i].getY() << "\" />\n";
    arqXml << "      <Block type=\"" << arrayBlocks[i].getName() << "\" material=\"" << arrayBlocks[i].getMaterial() << "\" x=\"" << auxXmirror[i] << "\" y=\"" << arrayBlocks[i].getY() << "\" />\n";
    }
    arqXml << finishedXml;
    arqXml.close();
}

void openFileWrite(const int numberMatrix, int **drawGrid, const int sizeXGrid, const int sizeXGridMatriz, const bool incomplete){
    string matrix = "testeBlockEvoluidoMatriz-";

    //Parte do codigo que transforma a variavel numberMatrix(int) em uma string
    stringstream auxStringMatrix;
    auxStringMatrix << numberMatrix;
    matrix += auxStringMatrix.str();
    if(incomplete){
        matrix += "NIVEL_IMCOMPLETO";
    }
    matrix += ".txt";

    ofstream arqMatrix;
    arqMatrix.open(matrix.c_str(), ios::out); //abre o arquivo para escrita com ponteiro iniciando no começo do arquivo (arquivo "*.xml")

    if(arqMatrix.fail()){ //verifica se a abertura foi feita corretamente, caso contrario ele apresenta uma mensagem...
        cerr << "Falha ao abrir arquivo de escrita.\n"; //de erro na tela e returna 1 finaliando o programa.
        exit(1);
    } else{
        for(int i = 0; i < sizeYGrid; i++){
            for(int j = 0; j < sizeXGridMatriz; j++){
                if(j == (sizeXGridMatriz - sizeXGrid)){
                    arqMatrix << "| ";
                }
                arqMatrix << drawGrid[j][i] << ' ';
            }
            arqMatrix << '\n';
        }
        arqMatrix.close();
    }
}

double round(double numberRound){
    ostringstream strs;
    strs << fixed << setprecision(PRECISION) << numberRound; //contudo aqui temos o problema de haver mais de um digito antes do ponto
    string str = strs.str();
    numberRound = atof(str.c_str());

    return numberRound;
}

double roundDown(double numberRoundDown){
    numberRoundDown *= 10;
    int aux = (int) numberRoundDown;
    numberRoundDown = (double) aux;
    numberRoundDown /= 10;

    return numberRoundDown;
}

double calculationObjectMirror(const Block & b, double positionXinicial){
    double middle = ((XMAXIMUM - positionXinicial) / 2);
    middle = positionXinicial + middle;
    middle = round(middle);

    double aux = middle - b.getX();

    return (middle + aux);
}

//função imcompleta
double changePositionObjectMirror(const Block & b, float percentagem){
    float auxPencentagem = rand() % 11; //VERIFICAR SE ESTE RAND ESTA VARIANDO O VALOR
    bool lado;
    if(auxPencentagem <= percentagem){
        //b.largerColliderX();
        lado = rand() % 2; //(0-false->esquerda ______ 1-true->direita) //VERIFICAR SE ESTE RAND ESTA VARIANDO O VALOR
    }
}

void resetMatrix(int **drawGrid, int sizeXGridMatriz){
    for(int i = 0; i < sizeYGrid; i++){
        for(int j = 0; j < sizeXGridMatriz; j++){
            if((i == (sizeYGrid - 1)) || (j == 0)){
                drawGrid[j][i] = -1;
            } else{
                drawGrid[j][i] = 0;
            }
        }
    }
}

bool checkPositionGrid(Block & b, int x, int y, int **drawGrid, int sizeXGrid, const int sizeXGridMatriz, int positionXinicial, double & xXml, double & yXml){

    int auxX = 0, auxY = 0, sizeX, sizeY;
    int auxI, auxJ;
    bool clearDraw = false;
    bool stopClear = false;
    int contDraw = 0;

    switch(b.getId()){
        case 0:
        {
            //      cout << "\n-----------------CIRCLE--------------------\n";
            if(((y - CIRCLEX) >= 0) && ((x - CIRCLEY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - CIRCLEX;
                sizeX = x - CIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((Circle[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 1;
                            contDraw++;
                        } else if((Circle[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] == 1) && (Circle[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - CIRCLEX) >= 0) && ((x + CIRCLEY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - CIRCLEX;
                sizeX = x + CIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((Circle[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 1;
                            contDraw++;
                        } else if((Circle[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] == 1) && (Circle[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (CIRCLEX / 2);
                auxJ = x - (CIRCLEY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 1:
        {
            //      cout << "\n-----------------SMALLCIRCLE--------------------\n";
            if(((y - SMALLCIRCLEX) >= 0) && ((x - SMALLCIRCLEY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - SMALLCIRCLEX;
                sizeX = x - SMALLCIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((SmallCircle[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 2;
                            contDraw++;
                        } else if((SmallCircle[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] == 2) && (SmallCircle[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - SMALLCIRCLEX) >= 0) && ((x + SMALLCIRCLEY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - SMALLCIRCLEX;
                sizeX = x + SMALLCIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((SmallCircle[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 1;
                            contDraw++;
                        } else if((SmallCircle[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] == 2) && (SmallCircle[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (SMALLCIRCLEX / 2);
                auxJ = x - (SMALLCIRCLEY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 2:
        {
            //      cout << "\n-----------------RECTBIGLYING--------------------\n";
            if(((y - RECTBIGLYINGX) >= 0) && ((x - RECTBIGLYINGY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTBIGLYINGX;
                sizeX = x - RECTBIGLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 3;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTBIGLYINGX) >= 0) && ((x + RECTBIGLYINGY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTBIGLYINGX;
                sizeX = x + RECTBIGLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 3;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTBIGLYINGX / 2);
                auxJ = x - (RECTBIGLYINGY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 3:
        {
            //      cout << "\n-----------------RECTBIGSTANDING--------------------\n";
            if(((y - RECTBIGLYINGY) >= 0) && ((x - RECTBIGLYINGX) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTBIGLYINGY;
                sizeX = x - RECTBIGLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 3;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTBIGLYINGY) >= 0) && ((x + RECTBIGLYINGX) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTBIGLYINGY;
                sizeX = x + RECTBIGLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 3;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTBIGLYINGY / 2);
                auxJ = x - (RECTBIGLYINGX / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 4:
        {
            //      cout << "\n-----------------RECTFATLYING--------------------\n";
            if(((y - RECTFATLYINGY) >= 0) && ((x - RECTFATLYINGX) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTFATLYINGY;
                sizeX = x - RECTFATLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 4;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTFATLYINGY) >= 0) && ((x + RECTFATLYINGX) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTFATLYINGY;
                sizeX = x + RECTFATLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 4;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTFATLYINGX / 2);
                auxJ = x - (RECTFATLYINGY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 5:
        {
            //      cout << "\n-----------------RECTFATSTANDING--------------------\n";
            if(((y - RECTFATLYINGX) >= 0) && ((x - RECTFATLYINGY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTFATLYINGX;
                sizeX = x - RECTFATLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 4;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTFATLYINGX) >= 0) && ((x + RECTFATLYINGY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTFATLYINGX;
                sizeX = x + RECTFATLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 4;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTFATLYINGY / 2);
                auxJ = x - (RECTFATLYINGX / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 6:
        {
            //      cout << "\n-----------------RECTMEDIUMLYING--------------------\n";
            if(((y - RECTMEDIUMLYINGX) >= 0) && ((x - RECTMEDIUMLYINGY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTMEDIUMLYINGX;
                sizeX = x - RECTMEDIUMLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 5;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTMEDIUMLYINGX) >= 0) && ((x + RECTMEDIUMLYINGY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTMEDIUMLYINGX;
                sizeX = x + RECTMEDIUMLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 5;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTMEDIUMLYINGX / 2);
                auxJ = x - (RECTMEDIUMLYINGY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 7:
        {
            //      cout << "\n-----------------RECTMEDIUMSTANDING--------------------\n";
            if(((y - RECTMEDIUMLYINGY) >= 0) && ((x - RECTMEDIUMLYINGX) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTMEDIUMLYINGY;
                sizeX = x - RECTMEDIUMLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 5;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTMEDIUMLYINGY) >= 0) && ((x + RECTMEDIUMLYINGX) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTMEDIUMLYINGY;
                sizeX = x + RECTMEDIUMLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 5;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTMEDIUMLYINGY / 2);
                auxJ = x - (RECTMEDIUMLYINGX / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
            ;
        }
        case 8:
        {
            //      cout << "\n-----------------RECTSMALLLYING--------------------\n";
            if(((y - RECTSMALLLYINGX) >= 0) && ((x - RECTSMALLLYINGY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTSMALLLYINGX;
                sizeX = x - RECTSMALLLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 6;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTSMALLLYINGX) >= 0) && ((x + RECTSMALLLYINGY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTSMALLLYINGX;
                sizeX = x + RECTSMALLLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 6;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTSMALLLYINGX / 2);
                auxJ = x - (RECTSMALLLYINGY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 9:
        {
            //      cout << "\n-----------------RECTSMALLSTANDING--------------------\n";
            if(((y - RECTSMALLLYINGY) >= 0) && ((x - RECTSMALLLYINGX) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTSMALLLYINGY;
                sizeX = x - RECTSMALLLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 6;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTSMALLLYINGY) >= 0) && ((x + RECTSMALLLYINGX) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTSMALLLYINGY;
                sizeX = x + RECTSMALLLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 6;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTSMALLLYINGY / 2);
                auxJ = x - (RECTSMALLLYINGX / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 10:
        {
            //      cout << "\n-----------------RECTTINYLYING--------------------\n";
            if(((y - RECTTINYLYINGX) >= 0) && ((x - RECTTINYLYINGY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTTINYLYINGX;
                sizeX = x - RECTTINYLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 7;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTTINYLYINGX) >= 0) && ((x + RECTTINYLYINGY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTTINYLYINGX;
                sizeX = x + RECTTINYLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 7;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTTINYLYINGX / 2);
                auxJ = x - (RECTTINYLYINGY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 11:
        {
            //      cout << "\n-----------------RECTTINYSTANDING--------------------\n";
            if(((y - RECTTINYLYINGY) >= 0) && ((x - RECTTINYLYINGX) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - RECTTINYLYINGY;
                sizeX = x - RECTTINYLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 7;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - RECTTINYLYINGY) >= 0) && ((x + RECTTINYLYINGX) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - RECTTINYLYINGY;
                sizeX = x + RECTTINYLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 7;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (RECTTINYLYINGY / 2);
                auxJ = x - (RECTTINYLYINGX / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 12:
        {
            //      cout << "\n-----------------SQUAREHOLE--------------------\n";
            if(((y - SQUAREHOLEXY) >= 0) && ((x - SQUAREHOLEXY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - SQUAREHOLEXY;
                sizeX = x - SQUAREHOLEXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 8;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - SQUAREHOLEXY) >= 0) && ((x + SQUAREHOLEXY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - SQUAREHOLEXY;
                sizeX = x + SQUAREHOLEXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 8;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (SQUAREHOLEXY / 2);
                auxJ = x - (SQUAREHOLEXY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 13:
        {
            //      cout << "\n-----------------SQUARESMALL--------------------\n";
            if(((y - SQUARESMALLXY) >= 0) && ((x - SQUARESMALLXY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - SQUARESMALLXY;
                sizeX = x - SQUARESMALLXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 9;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - SQUARESMALLXY) >= 0) && ((x + SQUARESMALLXY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - SQUARESMALLXY;
                sizeX = x + SQUARESMALLXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 9;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (SQUARESMALLXY / 2);
                auxJ = x - (SQUARESMALLXY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 14:
        {
            //      cout << "\n-----------------SQUARETINY--------------------\n";
            if(((y - SQUARETINYXY) >= 0) && ((x - SQUARETINYXY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - SQUARETINYXY;
                sizeX = x - SQUARETINYXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 1;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - SQUARETINYXY) >= 0) && ((x + SQUARETINYXY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - SQUARETINYXY;
                sizeX = x + SQUARETINYXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 1;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (SQUARETINYXY / 2);
                auxJ = x - (SQUARETINYXY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 15:
        {
            //      cout << "\n-----------------TRIANGLE--------------------\n";
            if(((y - TRIANGLEXY) >= 0) && ((x - TRIANGLEXY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - TRIANGLEXY;
                sizeX = x - TRIANGLEXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((Triangle[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 2;
                            contDraw++;
                        } else if((Triangle[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxX++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxX = 0;
                    auxY++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] == 2) && (Triangle[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxX++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxX = 0;
                        auxY++;
                    }
                }
            } else if(((y - TRIANGLEXY) >= 0) && ((x + TRIANGLEXY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - TRIANGLEXY;
                sizeX = x + TRIANGLEXY;
                auxY = TRIANGLEXY - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((Triangle[auxY][auxX] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 2;
                            contDraw++;
                        } else if((Triangle[auxY][auxX] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxX++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxX = 0;
                    auxY--;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = TRIANGLEXY - 1;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] == 2) && (Triangle[auxY][auxX] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxX++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxX = 0;
                        auxY--;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (TRIANGLEXY / 2);
                auxJ = x - (TRIANGLEXY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 16:
        {
            //      cout << "\n-----------------TRIANGLEMIRROR--------------------\n";
            if(((y - TRIANGLEXY) >= 0) && ((x - TRIANGLEXY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - TRIANGLEXY;
                sizeX = x - TRIANGLEXY;
                auxY = TRIANGLEXY - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((Triangle[auxY][auxX] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 3;
                            contDraw++;
                        } else if((Triangle[auxY][auxX] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxX++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxX = 0;
                    auxY--;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = TRIANGLEXY - 1;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] == 3) && (Triangle[auxY][auxX] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxX++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxX = 0;
                        auxY--;
                    }
                }
            } else if(((y - TRIANGLEXY) >= 0) && ((x + TRIANGLEXY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - TRIANGLEXY;
                sizeX = x + TRIANGLEXY;
                auxX = TRIANGLEXY - 1;
                auxY = TRIANGLEXY - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((TriangleMirror[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 3;
                            contDraw++;
                        } else if((TriangleMirror[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxX--;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxX = TRIANGLEXY - 1;
                    auxY--;
                }
                if(clearDraw){
                    auxX = TRIANGLEXY - 1;
                    auxY = TRIANGLEXY - 1;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] == 3) && (TriangleMirror[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxX--;
                        }
                        if(stopClear){
                            break;
                        }
                        auxX = TRIANGLEXY - 1;
                        auxY--;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (TRIANGLEXY / 2);
                auxJ = x - (TRIANGLEXY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 17:
        {
            //      cout << "\n-----------------TRIANGLEHOLE--------------------\n";
            if(((y - TRIANGLEHOLEX) >= 0) && ((x - TRIANGLEHOLEY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - TRIANGLEHOLEX;
                sizeX = x - TRIANGLEHOLEY;
                auxX = TRIANGLEHOLEX - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((TriangleHole[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 4;
                            contDraw++;
                        } else if((TriangleHole[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX--;
                }
                if(clearDraw){
                    auxX = TRIANGLEHOLEX - 1;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] == 5) && (TriangleHole[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX--;
                    }
                }
            } else if(((y - TRIANGLEHOLEX) >= 0) && ((x + TRIANGLEHOLEY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - TRIANGLEHOLEX;
                sizeX = x + TRIANGLEHOLEY;
                auxX = TRIANGLEHOLEX - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((TriangleHole[auxX][auxY] == 1) && (drawGrid[j][i] == 0)){
                            drawGrid[j][i] = 4;
                            contDraw++;
                        } else if((TriangleHole[auxX][auxY] == 1) && (drawGrid[j][i] != 0)){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX--;
                }
                if(clearDraw){
                    auxX = TRIANGLEHOLEX - 1;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] == 5) && (TriangleHole[auxX][auxY] == 1)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX--;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (TRIANGLEHOLEX / 2);
                auxJ = x - (TRIANGLEHOLEY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        case 18:
        {
            //      cout << "\n-----------------PLATAFORM--------------------\n";
            if(((y - PLATAFORMXY) >= 0) && ((x - PLATAFORMXY) >= 0) && ((drawGrid[x - 1][y] != 0) || (drawGrid[x][y + 1] != 0))){
                sizeY = y - PLATAFORMXY;
                sizeX = x - PLATAFORMXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 5;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j > sizeX; j--){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else if(((y - PLATAFORMXY) >= 0) && ((x + PLATAFORMXY) <= sizeXGridMatriz) && (drawGrid[x + 1][y] != 0)){
                sizeY = y - PLATAFORMXY;
                sizeX = x + PLATAFORMXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 0){
                            drawGrid[j][i] = 5;
                            contDraw++;
                        } else if(drawGrid[j][i] != 0){
                            clearDraw = true;
                            break;
                        }
                        auxY++;
                    }
                    if(clearDraw){
                        break;
                    }
                    auxY = 0;
                    auxX++;
                }
                if(clearDraw){
                    auxX = 0;
                    auxY = 0;
                    for(int i = y; i > sizeY; i--){
                        for(int j = x; j < sizeX; j++){
                            if((contDraw > 0) && (drawGrid[j][i] != 0)){
                                contDraw--;
                                drawGrid[j][i] = 0;
                            } else if(contDraw == 0){
                                stopClear = true;
                                break;
                            }
                            auxY++;
                        }
                        if(stopClear){
                            break;
                        }
                        auxY = 0;
                        auxX++;
                    }
                }
            } else{
                clearDraw = true;
            }
            if(clearDraw){
                return false;
            } else{
                auxI = y - (PLATAFORMXY / 2);
                auxJ = x - (PLATAFORMXY / 2);
                auxI = abs(auxI - (sizeYGrid - 1));
                yXml = auxI * DESCRETIZACAOGRID;
                yXml = YMINIMUM + yXml;
                xXml = auxJ * DESCRETIZACAOGRID;
                xXml = positionXinicial + xXml;
                return true;
            }
            break;
        }
        default:
        {
            cerr << "Objeto referenciado nao se encontra no banco de dados de objetos conhecidos pelo programa.\n";
        }
    }
}

void RetornaMatrixEstadoAnterior(int ** drawGrid, const Block & b, int x, int y, bool decision){
    int numberDrwa;
    int auxX = 0, auxY = 0, sizeX, sizeY;

    switch(b.getId()){
        case 0:
        {
            //          cout << "\n-----------------CIRCLE--------------------\n";
            if(!decision){
                sizeY = y - CIRCLEX;
                sizeX = x - CIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((Circle[auxX][auxY] == 1) && (drawGrid[j][i] == 1)){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - CIRCLEX;
                sizeX = x + CIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((Circle[auxX][auxY] == 1) && (drawGrid[j][i] == 1)){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 1:
        {
            //          cout << "\n-----------------SMALLCIRCLE--------------------\n";
            if(!decision){
                sizeY = y - SMALLCIRCLEX;
                sizeX = x - SMALLCIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((SmallCircle[auxX][auxY] == 1) && (drawGrid[j][i] == 2)){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - SMALLCIRCLEX;
                sizeX = x + SMALLCIRCLEY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((SmallCircle[auxX][auxY] == 1) && (drawGrid[j][i] == 2)){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 2:
        {
            //          cout << "\n-----------------RECTBIGLYING--------------------\n";
            if(!decision){
                sizeY = y - RECTBIGLYINGX;
                sizeX = x - RECTBIGLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 3){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTBIGLYINGX;
                sizeX = x + RECTBIGLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 3){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 3:
        {
            //          cout << "\n-----------------RECTBIGSTANDING--------------------\n";
            if(!decision){
                sizeY = y - RECTBIGLYINGY;
                sizeX = x - RECTBIGLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 3){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTBIGLYINGY;
                sizeX = x + RECTBIGLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 3){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 4:
        {
            //          cout << "\n-----------------RECTFATLYING--------------------\n";
            if(!decision){
                sizeY = y - RECTFATLYINGY;
                sizeX = x - RECTFATLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 4){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTFATLYINGY;
                sizeX = x + RECTFATLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 4){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 5:
        {
            //          cout << "\n-----------------RECTFATSTANDING--------------------\n";
            if(!decision){
                sizeY = y - RECTFATLYINGX;
                sizeX = x - RECTFATLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 4){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTFATLYINGX;
                sizeX = x + RECTFATLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 4){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 6:
        {
            //          cout << "\n-----------------RECTMEDIUMLYING--------------------\n";
            if(!decision){
                sizeY = y - RECTMEDIUMLYINGX;
                sizeX = x - RECTMEDIUMLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 5){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTMEDIUMLYINGX;
                sizeX = x + RECTMEDIUMLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 5){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 7:
        {
            //          cout << "\n-----------------RECTMEDIUMSTANDING--------------------\n";
            if(!decision){
                sizeY = y - RECTMEDIUMLYINGY;
                sizeX = x - RECTMEDIUMLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 5){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTMEDIUMLYINGY;
                sizeX = x + RECTMEDIUMLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 5){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 8:
        {
            //          cout << "\n-----------------RECTSMALLLYING--------------------\n";
            if(!decision){
                sizeY = y - RECTSMALLLYINGX;
                sizeX = x - RECTSMALLLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 6){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTSMALLLYINGX;
                sizeX = x + RECTSMALLLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 6){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 9:
        {
            //          cout << "\n-----------------RECTSMALLSTANDING--------------------\n";
            if(!decision){
                sizeY = y - RECTSMALLLYINGY;
                sizeX = x - RECTSMALLLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 6){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTSMALLLYINGY;
                sizeX = x + RECTSMALLLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 6){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 10:
        {
            //          cout << "\n-----------------RECTTINYLYING--------------------\n";
            if(!decision){
                sizeY = y - RECTTINYLYINGX;
                sizeX = x - RECTTINYLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 7){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTTINYLYINGX;
                sizeX = x + RECTTINYLYINGY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 7){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 11:
        {
            //          cout << "\n-----------------RECTTINYSTANDING--------------------\n";
            if(!decision){
                sizeY = y - RECTTINYLYINGY;
                sizeX = x - RECTTINYLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 7){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - RECTTINYLYINGY;
                sizeX = x + RECTTINYLYINGX;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 7){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 12:
        {
            //          cout << "\n-----------------SQUAREHOLE--------------------\n";
            if(!decision){
                sizeY = y - SQUAREHOLEXY;
                sizeX = x - SQUAREHOLEXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 8){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - SQUAREHOLEXY;
                sizeX = x + SQUAREHOLEXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 8){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 13:
        {
            //          cout << "\n-----------------SQUARESMALL--------------------\n";
            if(!decision){
                sizeY = y - SQUARESMALLXY;
                sizeX = x - SQUARESMALLXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 9){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - SQUARESMALLXY;
                sizeX = x + SQUARESMALLXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 9){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 14:
        {
            //          cout << "\n-----------------SQUARETINY--------------------\n";
            if(!decision){
                sizeY = y - SQUARETINYXY;
                sizeX = x - SQUARETINYXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 1){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            } else {
                sizeY = y - SQUARETINYXY;
                sizeX = x + SQUARETINYXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 1){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX++;
                }
            }
            break;
        }
        case 15:
        {
            //          cout << "\n-----------------TRIANGLE--------------------\n";
            if(!decision){
                sizeY = y - TRIANGLEXY;
                sizeX = x - TRIANGLEXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((Triangle[auxX][auxY] == 1) && (drawGrid[j][i] == 2)){
                            drawGrid[j][i] = 0;
                        }
                        auxX++;
                    }
                    auxX = 0;
                    auxY++;
                }
            } else {
                sizeY = y - TRIANGLEXY;
                sizeX = x + TRIANGLEXY;
                auxY = TRIANGLEXY - 2;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((Triangle[auxY][auxX] == 1) && (drawGrid[j][i] == 2)){
                            drawGrid[j][i] = 0;
                        }
                        auxX++;
                    }
                    auxX = 0;
                    auxY--;
                }
            }
            break;
        }
        case 16:
        {
            //          cout << "\n-----------------TRIANGLEMIRROR--------------------\n";
            if(!decision){
                sizeY = y - TRIANGLEXY;
                sizeX = x - TRIANGLEXY;
                auxY = TRIANGLEXY - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((Triangle[auxY][auxX] == 1) && (drawGrid[j][i] == 3)){
                            drawGrid[j][i] = 0;
                        }
                        auxX++;
                    }
                    auxX = 0;
                    auxY--;
                }
            } else {
                sizeY = y - TRIANGLEXY;
                sizeX = x + TRIANGLEXY;
                auxX = TRIANGLEXY - 1;
                auxY = TRIANGLEXY - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((TriangleMirror[auxX][auxY] == 1) && (drawGrid[j][i] == 3)){
                            drawGrid[j][i] = 0;
                        }
                        auxX--;
                    }
                    auxX = TRIANGLEXY - 1;
                    auxY--;
                }
            }
            break;
        }
        case 17:
        {
            //          cout << "\n-----------------TRIANGLEHOLE--------------------\n";
            if(!decision){
                sizeY = y - TRIANGLEHOLEX;
                sizeX = x - TRIANGLEHOLEY;
                auxX = TRIANGLEHOLEX - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if((TriangleHole[auxX][auxY] == 1) && (drawGrid[j][i] == 4)){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX--;
                }
            } else {
                sizeY = y - TRIANGLEHOLEX;
                sizeX = x + TRIANGLEHOLEY;
                auxX = TRIANGLEHOLEX - 1;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if((TriangleHole[auxX][auxY] == 1) && (drawGrid[j][i] == 4)){
                            drawGrid[j][i] = 0;
                        }
                        auxY++;
                    }
                    auxY = 0;
                    auxX--;
                }
            }
            break;
        }
        case 18:
        {
            //          cout << "\n-----------------PLATAFORM--------------------\n";
            if(!decision){
                sizeY = y - PLATAFORMXY;
                sizeX = x - PLATAFORMXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j > sizeX; j--){
                        if(drawGrid[j][i] == 5){
                            drawGrid[j][i] = 0;
                        }
                    }
                }
            } else {
                sizeY = y - PLATAFORMXY;
                sizeX = x + PLATAFORMXY;
                for(int i = y; i > sizeY; i--){
                    for(int j = x; j < sizeX; j++){
                        if(drawGrid[j][i] == 5){
                            drawGrid[j][i] = 0;
                        }
                    }
                }
            }
            break;
        }
        default:
        {
            cerr << "Objeto referenciado nao se encontra no banco de dados de objetos conhecidos pelo programa.\n";
        }
    }
}

void backtracking(int **drawGrid, Block * arrayBlocks, double * auxXmirror, int contBlocks, const int numBlocks, const int sizeXGrid, const int sizeXGridMatriz, const double positionXinicial){
//contNiveisCridos++;
//cout << "cont Niveis Cridos = " << contNiveisCridos << endl;
    bool walk = false;
    bool incomplete = false;
    bool colocouObjeto = false;
    double xXml, yXml;
    bool auxRetornaMatrixEstadoAnterior;
    int auxI, auxJ;

    /*int **auxDrawGrid = new int*[sizeXGrid];
    for(int i = 0; i < sizeXGrid; i++){
      auxDrawGrid[i] = new int[sizeYGrid];
    }

    for(int i = (sizeYGrid - 1); i >= 0; i--){
        for(int j = 1; j < sizeXGrid; j++){
            auxDrawGrid[j][i] = drawGrid[j][i];
        }
    }//*/

    if(contBlocks == numBlocks){
      //openFileWrite(numberXml, drawGrid, sizeXGrid, sizeXGridMatriz, incomplete);
      //openFileWrite(numberXml++, arrayBlocks, numBlocks, auxXmirror);
        contNiveisCridos++;
        finished = true;
if(contNiveisCridos > 41968){
for(int i = 0; i < sizeYGrid; i++){
    for(int j = 0; j < sizeXGridMatriz; j++){
        if(j == (sizeXGridMatriz - sizeXGrid)){
            cout << "| ";
        }
        cout << drawGrid[j][i] << ' ';
    }
    cout << '\n';
}
cout << '\n';
}//*/
    } else{
        for(int i = (sizeYGrid - 1); i >= 0; i--){
            for(int j = 20; j < sizeXGridMatriz; j++){
                if(drawGrid[j][i] != 0){
                    if(((j - 1) >= 0) && (drawGrid[j - 1][i] == 0)){
                        if(checkPositionGrid(arrayBlocks[contBlocks], j - 1, i, drawGrid, sizeXGrid, sizeXGridMatriz, positionXinicial, xXml, yXml)){
                          arrayBlocks[contBlocks].setX(xXml);
                          arrayBlocks[contBlocks].setY(yXml);
                          auxXmirror[contBlocks] = calculationObjectMirror(arrayBlocks[contBlocks], positionXinicial);
                            colocouObjeto = true;
                            auxRetornaMatrixEstadoAnterior = 0;
                            auxI = i;
                            auxJ = j - 1;
                        }
                    } else if(((i - 1) >= 0) && (drawGrid[j][i - 1] == 0)){
                        if(checkPositionGrid(arrayBlocks[contBlocks], j, (i - 1), drawGrid, sizeXGrid, sizeXGridMatriz, positionXinicial, xXml, yXml)){
                          arrayBlocks[contBlocks].setX(xXml);
                          arrayBlocks[contBlocks].setY(yXml);
                          auxXmirror[contBlocks] = calculationObjectMirror(arrayBlocks[contBlocks], positionXinicial);
                            colocouObjeto = true;
                            auxRetornaMatrixEstadoAnterior = 0;
                            auxI = i - 1;
                            auxJ = j;
                        }
                    } else if(((j + 1) < sizeXGrid) && drawGrid[j + 1][i] == 0){
                        if(checkPositionGrid(arrayBlocks[contBlocks], (j + 1), i, drawGrid, sizeXGrid, sizeXGridMatriz, positionXinicial, xXml, yXml)){
                          arrayBlocks[contBlocks].setX(xXml);
                          arrayBlocks[contBlocks].setY(yXml);
                          auxXmirror[contBlocks] = calculationObjectMirror(arrayBlocks[contBlocks], positionXinicial);
                            colocouObjeto = true;
                            auxRetornaMatrixEstadoAnterior = 1;
                            auxI = i;
                            auxJ = j + 1;
                        }
                    } else if((j == (sizeXGrid - 1)) && (i == 0) && (contBlocks < numBlocks)){
                        cout << "IMCOMPLETOOOOOOOOOOOOOOO\n";
                        finished = true;
                        incomplete = true;
                    }//*/
                }

                if(colocouObjeto){
                    colocouObjeto = false;
                    backtracking(drawGrid, arrayBlocks, auxXmirror, (contBlocks + 1), numBlocks, sizeXGrid, sizeXGridMatriz, positionXinicial);
                    /*for(int coluna = (sizeYGrid - 1); coluna >= 0; coluna--){
                        for(int linha = 1; linha < sizeXGrid; linha++){
                            drawGrid[linha][coluna] = auxDrawGrid[linha][coluna];
                        }
                    }//*/
                    RetornaMatrixEstadoAnterior(drawGrid, arrayBlocks[contBlocks], auxJ, auxI, auxRetornaMatrixEstadoAnterior);
                }
            }
        }
        /*for(int i = 0; i < sizeXGrid; i++){
          delete [] auxDrawGrid[i];
        }
        delete [] auxDrawGrid;//*/

        if(finished){
            return;
        }
    }
}