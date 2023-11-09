#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <cstring>

struct Habilidade {
    char nome[51];
    int nivel;
    float valor;
    int modificador;

    Habilidade() : nivel(0), valor(0), modificador(0) {}

    void setNome(const char* nome) {
        strncpy(this->nome, nome, sizeof(this->nome) - 1);
        this->nome[sizeof(this->nome) - 1] = '\0';
    }
};

struct GrupoHabilidades {
    char nomeGrupo[51];
    std::vector<Habilidade> habilidades;
};

void exibirFichaPersonagem(const std::vector<GrupoHabilidades>& gruposHabilidades) {
    std::cout << "Ficha de Personagem\n";
    std::cout << "-------------------\n";

    for (const auto& grupo : gruposHabilidades) {
        std::cout << "Grupo: " << grupo.nomeGrupo << std::endl;
        std::cout << "Habilidades:\n";

        for (const auto& habilidade : grupo.habilidades) {
            std::cout << "Habilidade: " << habilidade.nome << ", Nível: " << habilidade.nivel;
            std::cout << ", Valor: " << habilidade.valor << ", Modificador: " << habilidade.modificador << std::endl;
        }

        std::cout << "-------------------\n";
    }
}

int main() {
    char nome[51];
    std::cout << "Digite o nome: ";
    std::cin.getline(nome, sizeof(nome));

    std::cout << nome << std::endl;

    char apelido[51];
    std::cout << "Digite o apelido: ";
    std::cin.getline(apelido, sizeof(apelido));

    std::cout << apelido << std::endl;

    char input[51];
    std::cin >> input;

    bool apenasLetras = true;

    for (char c : input) {
        if (!std::isalpha(c)) {
            apenasLetras = false;
            break;
        }
    }

    if (!apenasLetras) {
        std::cout << "A entrada contém caracteres que não são letras." << std::endl;
        std::exit(0);
    }

    std::vector<GrupoHabilidades> gruposHabilidades;

    // Criando grupo de habilidades mágicas
    GrupoHabilidades grupoMagia;
    strncpy(grupoMagia.nomeGrupo, "Magia", sizeof(grupoMagia.nomeGrupo) - 1);
    grupoMagia.nomeGrupo[sizeof(grupoMagia.nomeGrupo) - 1] = '\0';

    Habilidade magiaElemental;
    magiaElemental.setNome("Magias Elementais");
    magiaElemental.nivel = 0;
    magiaElemental.valor = 10;
    magiaElemental.modificador = 1;
    grupoMagia.habilidades.push_back(magiaElemental);

    Habilidade invocacao;
    invocacao.setNome("Invocação");
    invocacao.nivel = 0;
    invocacao.valor = 8;
    invocacao.modificador = 0;
    grupoMagia.habilidades.push_back(invocacao);

    Habilidade transmutacao;
    transmutacao.setNome("Transmutação");
    transmutacao.nivel = 0;
    transmutacao.valor = 6;
    transmutacao.modificador = -1;
    grupoMagia.habilidades.push_back(transmutacao);

    Habilidade necromancia;
    necromancia.setNome("Necromancia");
    necromancia.nivel = 0;
    necromancia.valor = 12;
    necromancia.modificador = 2;
    grupoMagia.habilidades.push_back(necromancia);

    gruposHabilidades.push_back(grupoMagia);

    // Criando grupo de habilidades físicas
    GrupoHabilidades grupoFisico;
    strncpy(grupoFisico.nomeGrupo, "Físico", sizeof(grupoFisico.nomeGrupo) - 1);
    grupoFisico.nomeGrupo[sizeof(grupoFisico.nomeGrupo) - 1] = '\0';

    Habilidade forca;
    forca.setNome("Força");
    forca.nivel = 0;
    forca.valor = 14;
    forca.modificador = 2;
    grupoFisico.habilidades.push_back(forca);

    Habilidade velocidade;
    velocidade.setNome("Velocidade");
    velocidade.nivel = 0;
    velocidade.valor = 16;
    velocidade.modificador = 3;
    grupoFisico.habilidades.push_back(velocidade);

    Habilidade agilidade;
    agilidade.setNome("Agilidade");
    agilidade.nivel = 0;
    agilidade.valor = 12;
    agilidade.modificador = 2;
    grupoFisico.habilidades.push_back(agilidade);

    Habilidade resistencia;
    resistencia.setNome("Resistência");
    resistencia.nivel = 0;
    resistencia.valor = 18;
    resistencia.modificador = 4;
    grupoFisico.habilidades.push_back(resistencia);

    gruposHabilidades.push_back(grupoFisico);

    // Exibir a ficha de personagem inicial
    exibirFichaPersonagem(gruposHabilidades);

    // Solicitar ao usuário para escolher as habilidades e seus níveis
    std::cout << "Escolha as habilidades para o seu personagem:\n";

    for (auto& grupo : gruposHabilidades) {
        std::cout << "Grupo: " << grupo.nomeGrupo << std::endl;

        for (auto& habilidade : grupo.habilidades) {
            int nivel;
            std::string nome;

            std::cout << "Digite o nível para a habilidade " << habilidade.nome << ": ";
            std::cin >> nivel;
            habilidade.nivel = nivel;

            std::cout << "Digite o nome para a habilidade " << habilidade.nome << ": ";
            std::cin.ignore();
            std::getline(std::cin, nome);
            habilidade.setNome(nome.c_str());

            habilidade.valor = nivel * 2;
            habilidade.modificador = nivel / 2;
        }
    }

    // Exibir a ficha de personagem atualizada
    std::cout << "\nFicha de Personagem Atualizada:\n";
    exibirFichaPersonagem(gruposHabilidades);

    return 0;
}