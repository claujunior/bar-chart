# Introduction

O projeto Bar Chart Race busca auxiliar na visualização de dados a partir da criação de uma animação de "corrida" que compara valores (sejam eles informações sobre populações, nomes, tempo de tela etc.) ao decorrer do tempo. Essas barras são separadas em diferentes categorias, a fim de facilitar na visualização do que elas representam.

# Author(s)

- Nome: Claudivan Costa de Lima Junior
- Email: claudivanjunior2002@hotmail.com
- Turma: Ciência da Computação, PROGRAMAÇÃO I - DIM0176 (2024.2)

- Nome: José Henrique Oliveira da Silva
- Email: jose.oliveira.136@ufrn.edu.br
- Turma: Ciência da Computação, PROGRAMAÇÃO I - DIM0176 (2024.2)

# Problems found or limitations

Dependendo do programa rodado e da quantidade de n_ticks o eixo x do grafico de barras começa a engolir uns numeros do proprio eixo x. 

# Grading

Item     | Valor máximo   | Valor esperado
-------- | :-----: | :-----:
Read, validate, and process command line arguments | 5 | 5
Program runs with default values, if no options are provided | 5 | 5
Read the input data file and store the information in memory    | 10 | 10
Display a summary of the data read from the input file _before_ the animation starts | 5 | 5
Display a summary of the running options (set by the user or default values) _before_ the animation starts | 5 | 5
The project contains at least two classes | 10 | 10
Create individual bar charts containing all data items for a single date | 10 | 10
Run the bar chart animation at the correct speed | 10  | 10
The bar chart anatomy is complete and correct | 30 | 30
Program handles errors properly | 10 | 10

# Compiling and Running

* ./resultado -b <valor> -f <valor> "caminho do arquivo" 
* ./resultado "caminho do arquivo" 
* ./resultado -b <valor> "caminho do arquivo"
* ./resultado -f <valor> "caminho do arquivo"
* ./resultado -f <valor> -b <valor> "caminho do arquivo"   
Tem o config.ini que muda as configurações do programa.
Se for necessário alterar alguma configuração num ficheiro .ini, deverá manter o mesmo padrão que estava anteriormente, ou seja, se for feita uma alteração na cor, é obrigatório seguir o mesmo modelo, incluindo o espaçamento correto entre o "=" e a COR como também tem que ser tudo em maiúsculo.
* DEFAULT_COLOR = Opções de cor: BLUE , GREEN , YELLOW e RED.

# References
* https://en.cppreference.com/w/cpp/memory/shared_ptr
* https://www.geeksforgeeks.org/smart-pointers-cpp/
* https://en.cppreference.com/w/c/program/EXIT_status
* https://en.cppreference.com/w/cpp/string/basic_string/stol
* https://en.cppreference.com/w/cpp/io/basic_fstream/is_open
* https://en.cppreference.com/w/cpp/string/basic_string/stof
* https://en.cppreference.com/w/cpp/string/basic_string
* https://en.cppreference.com/w/cpp/header/stdexcept