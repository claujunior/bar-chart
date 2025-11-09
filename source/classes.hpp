/**
 * @file classes.hpp
 * @brief Declarações de classes e funções para a animação de gráficos de barras.
 */

#ifndef CLASSES_HPP
#define CLASSES_HPP


#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <set>
#include <algorithm>

/** 
 * @enum State
 * @brief Representa os diferentes estados da animação.
 */
enum State {
    start,   ///< Estado inicial.
    welcome, ///< Estado de boas-vindas.
    reading, ///< Estado de leitura de dados.
    racing,  ///< Estado da animação em andamento.
    end      ///< Estado final.
};

/**
 * @struct DataEntry
 * @brief Estrutura que contém os dados de entrada para cada barra no gráfico.
 */
struct DataEntry {
    std::string time_stamp;           ///< Timestamp associado ao dado.
    std::string label;                ///< Rótulo da barra.
    std::string other_related_info;   ///< Informações adicionais relacionadas.
    double value;                     ///< Valor associado à barra.
    std::string category;             ///< Categoria da barra.
};

/**
 * @struct charbar
 * @brief Estrutura que representa as propriedades de uma barra.
 */
struct charbar {
    int tam;            ///< Tamanho da barra.
    std::string colors; ///< Cor da barra.
};

/**
 * @class AnimationController
 * @brief Controlador principal para gerenciar a animação de gráficos de barras.
 */
class AnimationController {
public:
    /**
     * @brief Inicializa o controlador com argumentos da linha de comando.
     * @param argc Número de argumentos.
     * @param argv Lista de argumentos.
     */
    static void initialize(int argc, char **argv);

    /**
     * @brief Processa o estado atual da animação.
     * @param argc Número de argumentos.
     * @param argv Lista de argumentos.
     */
    static void process(int argc, char **argv);

    /**
     * @brief Renderiza o estado atual da animação.
     */
    static void render();

    /**
     * @brief Renderiza as barras do gráfico.
     */
    static void render_bars();

    /**
     * @brief Atualiza os dados e o estado da animação.
     */
    static void update();

    /**
     * @brief Verifica se a animação foi concluída.
     * @return true se a animação terminou; caso contrário, false.
     */
    static bool is_over();

    /**
     * @brief Configura os valores dos eixos X.
     */
    static void eixoxs();

    /**
     * @brief Configura os tamanhos e as cores das barras.
     */
    static void tamanhos();

private:
    static std::vector<charbar> bar;                ///< Vetor de barras.
    static std::vector<int> tam;                   ///< Tamanhos das barras.
    static std::vector<int> eixox;                 ///< Valores nos eixos X.
    static int i;                                  ///< Índice atual.
    static int um;                                 ///< Total de gráficos.
    static std::unordered_set<std::string> s;     ///< Conjunto de categorias.
    static int k;                                  ///< Número de barras.
    static State estad;                            ///< Estado atual.
    static std::vector<std::vector<DataEntry>> infos; ///< Dados de entrada.
    static int b;                                  ///< Número padrão de barras.
    static int f;                                  ///< FPS padrão.
    static std::string titulo;                     ///< Título do gráfico.
    static std::string x;                          ///< Descrição do valor.
    static std::string source;                     ///< Fonte dos dados.
};

#endif // CLASSES_HPP