#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

bool Verifica_Caractere(char pTentativa[], char pReal[], int caractere)
{
    if(pTentativa[caractere] == pReal[caractere]|| pTentativa[caractere] == pReal[caractere] + 32 || pTentativa[caractere] == pReal[caractere] - 32)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Existe_Caractere(char pTentativa[], char pReal[], int caractereAtual)
{
    for(int i = 0; i < 5; i++)
    {
        if(pTentativa[caractereAtual] == pReal[i] || pTentativa[caractereAtual] == pReal[i] + 32 || pTentativa[caractereAtual] == pReal[i] - 32)
        {
            return true;
        }
    }
    return false;
}

void Dica(char pTentativa[], char pReal[], int caractere)
{
    if(Verifica_Caractere(pTentativa, pReal, caractere))
    {
        cout << "[V]  ";
    }
    else if(Existe_Caractere(pTentativa, pReal, caractere))
    {
        cout << "[A]  ";
    }
    else
    {
        cout << "[C]  ";
    }
}
int main() 
{    
    char pReal[6] = "Casas";
    char pTentativa[6];
    int nRodadas;
    
    cout << "Bem-vindo ao jogo de adivinhação de palavras!" << endl;
    cout << "Digite o número de rodadas:";
    
    cin >> nRodadas;
    cin.ignore(); // Limpa o buffer de entrada para evitar problemas com getline

    cout << "Digite a palavra de 5 letras: ";// Lê a palavra digitada pelo usuário e armazena o número de rodadas

    for (int i = 0; i < nRodadas; i++)
    {
        
        cin.getline(pTentativa, 6); // Lê a tentativa do usuário
        cout << "Rodada " << (i + 1) << ": ";

        if (strlen(pTentativa) != 5) 
        {
            cout << "A palavra deve ter exatamente 5 letras. Tente novamente." << endl;
            i--; // Reduz o contador para repetir a rodada
            continue;
        }

        for (int j = 0; j < 5; j++) 
        {
            Dica(pTentativa, pReal, j);
        }
        
        cout << endl;

    }
   
    return 0;
}