#include <iostream>
#include <cstdlib>
#include <experimental/random>
#include <ctime>
using namespace std;

string jogador1 = " ", jogador2 = " ", jogador3 = " ", jogador4 = " ";
int total_j1 = 0, total_j2 = 0, total_j3 = 0, total_j4 = 0;
char matriz[6][6], layout[7][7];

char valores();
char criar_matriz();
char criar_layout();
int valor_achado(int x, int y);
void linhas();

void linhas() {
    cout<<"-----------------------"<<endl;
}

int valor_achado(int x, int y) {
    char possiveis_valores[10] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int valor_inteiro = 0;
    for (int v=0;v<10;v++) {
        if (matriz[x][y] == possiveis_valores[v]) {
            valor_inteiro = possiveis_valores[v] - '0';
            if (matriz[x][y] == '0') valor_inteiro = 10;
            return valor_inteiro;
        }
    }
    if (matriz[x][y] == 'O') {
        valor_inteiro = -10;
        return valor_inteiro;
    }
    else if (matriz[x][y] == '-') {
        valor_inteiro = 45;
        return valor_inteiro;
    }
    else if (matriz[x][y] == '+') {
        valor_inteiro = 43;
        return valor_inteiro;
    }
    else if (matriz[x][y] == ',') {
        valor_inteiro = 44;
        return valor_inteiro;
    }
    else return valor_inteiro;
}

char criar_layout() {
    for (int i=0;i<7;i++) {
        for (int j=0;j<7;j++) {
            if (i==0 && j==0) layout[i][j] = ' ';
            else if (i==0 && j==1) layout[i][j] = '1';
            else if (i==0 && j==2) layout[i][j] = '2';
            else if (i==0 && j==3) layout[i][j] = '3';
            else if (i==0 && j==4) layout[i][j] = '4';
            else if (i==0 && j==5) layout[i][j] = '5';
            else if (i==0 && j==6) layout[i][j] = '6';
            else if (i==1 && j==0) layout[i][j] = '1';
            else if (i==2 && j==0) layout[i][j] = '2';
            else if (i==3 && j==0) layout[i][j] = '3';
            else if (i==4 && j==0) layout[i][j] = '4';
            else if (i==5 && j==0) layout[i][j] = '5';
            else if (i==6 && j==0) layout[i][j] = '6';
            else layout[i][j] = ' ';
        }
    }
    return layout[7][7];
}

char criar_matriz() {
    int c15 = 0;
    for (int i=0;i<6;i++) {
        for (int j=0;j<6;j++) {
            matriz[i][j] = valores(); 
            if (c15 < 6) {
                if (experimental::randint(1, 9) == 1) {
                    matriz[i][j] = 'O';
                    c15++;
                }
                else if (experimental::randint(1, 9) == 2) {
                    matriz[i][j] = '-';
                    c15++;
                }
                else if (experimental::randint(1, 9) == 2) {
                    matriz[i][j] = '+';
                    c15++;
                }
                else if (experimental::randint(1, 9) == 3) {
                    matriz[i][j] = ',';
                    c15++;
                }
            }
        }
    }
    return matriz[6][6];
}

char valores() {
    char valor;
    int seed, v;
    seed = experimental::randint(1, 9999);
    srand(seed);
    int min = 48;
    int max = 57;
    v = min + rand() % (max - min + 1);
    valor = v;
    return valor;
}

int main() {
    int nmr_jogadores = 0;

    while (nmr_jogadores < 2 || nmr_jogadores > 4) {
        cout<<"Numero de jogadores (2 a 4): ";
        cin>>nmr_jogadores;
    }

    for (int i=0;i<nmr_jogadores;i++) {
        cout<<"Nome "<<i+1<<"o jogador: ";
        if (i==0) cin>>jogador1;
        else if (i==1) cin>>jogador2;
        else if (i==2) cin>>jogador3;
        else if (i==3) cin>>jogador4;
    }

    criar_matriz();
    criar_layout();

    int k=1, cont = 1, valor_bloco;
    while (cont <= 36) {
        int  x = -1, y = -1;

        linhas();
        cout<<"Rodada "<<cont<<endl;

        if (nmr_jogadores == 2) {
            if (k==1) cout<<"Vez de "<<jogador1<<endl;
            else if (k==2) {
                cout<<"Vez de "<<jogador2<<endl; 
            }
        }
        else if (nmr_jogadores == 3) {
            if (k==1) cout<<"Vez de "<<jogador1<<endl;
            else if (k==2) cout<<"Vez de "<<jogador2<<endl;
            else if (k==3) {
                cout<<"Vez de "<<jogador3<<endl; 
            }
        }
        else if (nmr_jogadores == 4) {
            if (k==1) cout<<"Vez de "<<jogador1<<endl;
            else if (k==2) cout<<"Vez de "<<jogador2<<endl;
            else if (k==3) cout<<"Vez de "<<jogador3<<endl;
            else if (k==4) {
                cout<<"Vez de "<<jogador4<<endl; 
            }
        }
        linhas();

        cout<<"Escolha um bloco"<<endl;
        for (int i=0;i<7;i++) {
            for (int j=0;j<7;j++) {
                if (i==0) {
                    cout<<layout[i][j]<<"    ";
                }
                else if (j==0) {
                    cout<<layout[i][j]<<" ";
                }
                else cout<<" ["<<layout[i][j]<<"] ";
                if (j==6) cout<<endl;
            }
        }
        cout<<endl;

        while (x < 1 || x > 6) {
            cout<<"Linha: "; cin>>x;
        }
        while (y < 1 || y > 6) {
            cout<<"Coluna: "; cin>>y;
        }
        if (layout[x][y] == 'a' || layout[x][y] == 'b' || layout[x][y] == 'c' || layout[x][y] == 'd') {
            while (layout[x][y] == 'a' || layout[x][y] == 'b' || layout[x][y] == 'c' || layout[x][y] == 'd') {
                cout<<"Escolha um lugar livre!"<<endl;
                cout<<"Linha: "; cin>>x;
                while (x < 1 || x > 6) {
                    cout<<"Linha: "; cin>>x;
                }
                cout<<"Coluna: "; cin>>y;
                while (y < 1 || y > 6) {
                    cout<<"Coluna: "; cin>>y;
                }
            }
        }
        cout<<endl;
        if (matriz[x-1][y-1] == '-' || matriz[x-1][y-1] == '+' || matriz[x-1][y-1] == ',' || matriz[x-1][y-1] == 'O' ) {
            if (matriz[x-1][y-1] == '-') layout[x][y] = '-';
            else if (matriz[x-1][y-1] == '+') layout[x][y] = '+';
            else if (matriz[x-1][y-1] == ',') layout[x][y] = ',';
            else if (matriz[x-1][y-1] == 'O') layout[x][y] = 'O';
        }
        else {
            if (k==1) layout[x][y] = 'a';
            else if (k==2) layout[x][y] = 'b';
            else if (k==3) layout[x][y] = 'c';
            else if (k==4) layout[x][y] = 'd';
        }
        

        valor_bloco = valor_achado(x-1, y-1);
        int dobra;
        if (valor_bloco > 0 && valor_bloco != 45 && valor_bloco != 43 && valor_bloco != 44 && cont != dobra) {
            cout<<"Voce achou um diamante de "<<valor_bloco<<" quilates!"<<endl;
        }
        else if (valor_bloco > 0 && valor_bloco != 45 && valor_bloco != 43 && valor_bloco != 44 && cont == dobra) {
            cout<<"Voce achou um diamante de "<<valor_bloco<<" quilates! x2"<<endl;
        }
        else if (valor_bloco < 0) {
            cout<<"Que pena! "<<valor_bloco<<" quilates."<<endl;
            if (k==1) {
                if (total_j1 + valor_bloco < 0) total_j1 = 0;
                else total_j1 += valor_bloco;
            }
            else if (k==2) {
                if (total_j2 + valor_bloco < 0) total_j2 = 0;
                else total_j2 += valor_bloco;
            }
            else if (k==3) {
                if (total_j3 + valor_bloco < 0) total_j3 = 0;
                else total_j3 += valor_bloco;
            }
            else if (k==4) {
                if (total_j4 + valor_bloco < 0) total_j4 = 0;
                else total_j4 += valor_bloco;
            }
        }
        else if (char(valor_bloco) == '-') {
            if (k==1) {
                cout<<"5 quilates descontados de cada jogador adversario"<<endl;
                total_j2 += -5;
                total_j3 += -5;
                total_j4 += -5;

            }
            else if (k==2) {
                cout<<"5 quilates descontados de cada jogador adversario"<<endl;
                total_j1 += -5;
                total_j3 += -5;
                total_j4 += -5;
            }
            else if (k==3) {
                cout<<"5 quilates descontados de cada jogador adversario"<<endl;
                total_j2 += -5;
                total_j1 += -5;
                total_j4 += -5;
            }
            else if (k==4) {
                cout<<"5 quilates descontados de cada jogador adversario"<<endl;
                total_j2 += -5;
                total_j3 += -5;
                total_j1 += -5;
            }
        }
        else if (char(valor_bloco) == '+') {
            if (k==1) {
                cout<<"3 quilates encontrados na mina abandonada."<<endl;
                total_j1 += 3;
            }
            else if (k==2) {
                cout<<"3 quilates encontrados na mina abandonada."<<endl;
                total_j2 += 3;
            }
            else if (k==3) {
                cout<<"3 quilates encontrados na mina abandonada."<<endl;
                total_j3 += 3;
            }
            else if (k==4) {
                cout<<"3 quilates encontrados na mina abandonada."<<endl;
                total_j4 += 3;
            }
        }
        else if (char(valor_bloco) == ',') {
            if (k==1) {
                cout<<"Quilates encontrados na proxima rodada serao dobrados"<<endl;
                if (nmr_jogadores == 2) dobra = cont + 2;
                else if (nmr_jogadores == 3) dobra = cont + 3;
                else if (nmr_jogadores == 4) dobra = cont + 4;
            }
            else if (k==2) {
                cout<<"Quilates encontrados na proxima rodada serao dobrados"<<endl;
                if (nmr_jogadores == 2) dobra = cont + 2;
                else if (nmr_jogadores == 3) dobra = cont + 3;
                else if (nmr_jogadores == 4) dobra = cont + 4;
            }
            else if (k==3) {
                cout<<"Quilates encontrados na proxima rodada serao dobrados"<<endl;
                if (nmr_jogadores == 3) dobra = cont + 3;
                else if (nmr_jogadores == 4) dobra = cont + 4;
            }
            else if (k==4) {
                cout<<"Quilates encontrados na proxima rodada serao dobrados"<<endl;
                dobra = cont + 4;
            }
        }
        
        cout<<endl;
        if (cont==dobra) {
            if (k==1) total_j1 += valor_bloco*2;
            else if (k==2) total_j2 += valor_bloco*2;
            else if (k==3) total_j3 += valor_bloco*2;
            else if (k==4) total_j4 += valor_bloco*2;
        }
        else if (valor_bloco != 43 && valor_bloco != 45 && valor_bloco >= 0 && valor_bloco != 44) {
            if (k==1) total_j1 += valor_bloco;
            else if (k==2) total_j2 += valor_bloco;
            else if (k==3) total_j3 += valor_bloco;
            else if (k==4) total_j4 += valor_bloco;
        }

        linhas();
        cout<<"Pontuacao "<<cont<<" rodada"<<endl;
        linhas();
        cout<<"Jogador 1: "<<total_j1<<endl;
        cout<<"Jogador 2: "<<total_j2<<endl;
        if (nmr_jogadores == 3) cout<<"Jogador 3: "<<total_j3<<endl;
        else if (nmr_jogadores == 4) {
            cout<<"Jogador 3: "<<total_j3<<endl; 
            cout<<"Jogador 4: "<<total_j4<<endl;
        }
        cout<<endl;

        if (nmr_jogadores == 2) {
            if (k==1) k++;
            else if (k==2) k=1;
        }
        else if (nmr_jogadores == 3) {
            if (k==1) k++;
            else if (k==2) k++;
            else if (k==3) k=1;
        }
        else if (nmr_jogadores == 4) {
            if (k==1) k++;
            else if (k==2) k++;
            else if (k==3) k++;
            else if (k==4) k=1;
        }
        cont++;
    }
    linhas();
    cout<<"Layout FINAL"<<endl;
    linhas();
    for (int i=0;i<7;i++) {
        for (int j=0;j<7;j++) {
            if (i==0) {
                cout<<layout[i][j]<<"    ";
            }
            else if (j==0) {
                cout<<layout[i][j]<<" ";
            }
            else cout<<" ["<<layout[i][j]<<"] ";
            if (j==6) cout<<endl;
        }
    }
    linhas();
    cout<<"Pontuacao FINAL"<<endl;
    linhas();
    cout<<"Jogador 1: "<<total_j1<<endl;
    cout<<"Jogador 2: "<<total_j2<<endl;
    if (nmr_jogadores == 3) cout<<"Jogador 3: "<<total_j3<<endl;
    else if (nmr_jogadores == 4) {
        cout<<"Jogador 3: "<<total_j3<<endl; 
        cout<<"Jogador 4: "<<total_j4<<endl;
    }
    linhas();
    if (total_j1 > total_j2 && total_j1 > total_j3 && total_j1 > total_j4) {
        cout<<jogador1<<" venceu com "<<total_j1<<" quilates"<<endl;
    }
    else if (total_j2 > total_j1 && total_j2 > total_j3 && total_j2 > total_j4) {
        cout<<jogador2<<" venceu com "<<total_j2<<" quilates"<<endl;
    }
    else if (total_j3 > total_j2 && total_j3 > total_j1 && total_j3 > total_j4) {
        cout<<jogador3<<" venceu com "<<total_j3<<" quilates"<<endl;
    }
    else if (total_j4 > total_j2 && total_j4 > total_j3 && total_j4 > total_j1) {
        cout<<jogador4<<" venceu com "<<total_j4<<" quilates"<<endl;
    }
    else if (total_j1 == total_j2) {
        cout<<jogador1<<" empatou com "<<jogador2<<"com "<<total_j1<<" quilates"<<endl;
    }
    else if (total_j1 == total_j3) {
        cout<<jogador1<<" empatou com "<<jogador3<<"com "<<total_j1<<" quilates"<<endl;
    }
    else if (total_j1 == total_j4) {
        cout<<jogador1<<" empatou com "<<jogador4<<"com "<<total_j1<<" quilates"<<endl;
    }
    else if (total_j1 == total_j4) {
        cout<<jogador1<<" empatou com "<<jogador4<<"com "<<total_j1<<" quilates"<<endl;
    }
    else if (total_j2 == total_j3) {
        cout<<jogador2<<" empatou com "<<jogador3<<"com "<<total_j2<<" quilates"<<endl;
    }
    else if (total_j2 == total_j4) {
        cout<<jogador2<<" empatou com "<<jogador4<<"com "<<total_j2<<" quilates"<<endl;
    }
    else if (total_j3 == total_j4) {
        cout<<jogador3<<" empatou com "<<jogador4<<"com "<<total_j3<<" quilates"<<endl;
    }
    linhas();

    return 0;
}