#include <iostream>
#include <ctime>
#include <experimental/random>
#include <vector> //CÓDIGO DE PEDRO LUCAS PONCIANO SILVA
#include <algorithm>
using namespace std;

// Função para sortear 6 números diferentes de 1 a 60
vector<int> sortearNumeros() {
    vector<int> nums;
    while (nums.size() < 6) {
        int sorteados = experimental::randint(1, 60);
        if (find(nums.begin(), nums.end(), sorteados) == nums.end()) {
            nums.push_back(sorteados);
        }
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    //adiciona as variaveis, e exibe a menssagem do jogo
    int numers_escolhidos; 
    int numero;
    char opcaoUsuario = 0;
    cout << "Bem vindo ao sorteio do MegaSenai. " << endl;

    while (opcaoUsuario != 'n') { //função para repetir o jogo, se o usuario quiser jopgar novamente 
    
    cout << "Digite 6 numeros de 1 a 60." << endl;
    cin >> numers_escolhidos;

    srand(time(nullptr));

    vector<int> numerosEscolhidos; //cria um vector para aramazenar os numeros escolhidos
    for (int i = 0; i < 6; ++i) { 
        cin >> numero;
        numerosEscolhidos.push_back(numero);
    }

    vector<int> numerosSorteados = sortearNumeros(); //cria um vector para aramazenar os numeros sorteados
    cout << "Numeros sorteados: ";
    for (auto &y : numerosSorteados) {
        cout << y << ' ';
    }
    cout << '\n';

    int acertos = 0;
    for (int i = 0; i < numerosEscolhidos.size(); ++i) {
        if (find(numerosSorteados.begin(), numerosSorteados.end(), numerosEscolhidos[i]) != numerosSorteados.end()) { //pega os numeros sorteados e os compara com os escolhidos.
            ++acertos;
        }
    }

    cout << "Numero de acertos: " << acertos << endl;// dá o valor de quantos números o usuario acertou

    cout << "Se quiser tentar novamente aperte qualquer letra, se nao aperte n ." << endl;
    cin >> opcaoUsuario;
    }

    cout << "Ogrigado por jogar!" << endl;

    return 0;
}
