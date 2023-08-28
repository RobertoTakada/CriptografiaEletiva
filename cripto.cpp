#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void AlgoritmoCifraColunas(int Opcao) {
    int posicaoString = 0;
    const int quantColunas = 3, quantLinhas = 11;
    string mensagem;
    char cifra3x80[quantColunas][quantLinhas];
    if (Opcao == 1) {
        cout << "Entre o texto a ser criptografado: ";
        cin >> mensagem;
        char* charArray = new char[mensagem.length() + 1];
        charArray[mensagem.length()] = '\0';
        for (int i = 0; i < mensagem.length(); i++) {
            charArray[i] = mensagem[i];
        }
        for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++)
        {
            for (int contadorColunas = 0; contadorColunas < quantColunas; contadorColunas++) {
                cifra3x80[contadorColunas][contadorLinhas] = charArray[posicaoString];
                posicaoString++;
                if (posicaoString >= mensagem.length()) {
                    break;
                }
            }

        }
        cout << "Representacao da mensagem criptografada: ";
        posicaoString = 0;
        for (int contadorColunas = 0; contadorColunas < quantColunas; contadorColunas++)
        {
            for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++) {
                cout << cifra3x80[contadorColunas][contadorLinhas];
                if (posicaoString >= mensagem.length()) {
                    break;
                }
            }
            cout << endl;
        }
        system("pause");
        cout << endl;
    }
    else {
        cout << "Entre o texto a ser descriptografada: ";
        cin >> mensagem;
        char* charArray = new char[mensagem.length() + 1];
        charArray[mensagem.length()] = '\0';
        for (int i = 0; i < mensagem.length(); i++) {
            charArray[i] = mensagem[i];
        }
        posicaoString = 0;
        int contadorColunas = 0;
        do {
            for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++) {
                cifra3x80[contadorColunas][contadorLinhas] = charArray[posicaoString];
                posicaoString++;
            }
            contadorColunas++;
        }while(contadorColunas < quantColunas);

        cout << "Mensagem descriptografada: ";

        for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++)
        {
            for (int contadorColunas = 0; contadorColunas < quantColunas; contadorColunas++) {
                cout << cifra3x80[contadorColunas][contadorLinhas];
            }
        }
        system("pause");
    }
}
void AlgoritmoTransColunas(int Opcao) {
    cout << "Entrou";
}
void Menu() {
    int loop;
    do {
        system("cls");
        cout << "Algoritmos de Criptografia --- Criptografar e Descriptografar" << endl;
        cout << "1 - Criptografar " << endl;
        cout << "2 - Descriptografar " << endl;
        cout << "3 - Criptografar " << endl;
        cout << "4 - Descriptografar " << endl;
        cout << "0 - Sair" << endl;
        cin >> loop;
        switch (loop) {
            case 1:
                AlgoritmoCifraColunas(1);
                break;
            case 2:
                AlgoritmoCifraColunas(2);
                break;
            case 3:
                AlgoritmoTransColunas(1);
                break;  
            case 4:
                AlgoritmoTransColunas(2);
                break;
            default:
                cout << "Insira uma opção válida";
                break;
        }

    } while (loop != 0);

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Menu();

    return 1;
}

