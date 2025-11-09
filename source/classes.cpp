#include "classes.hpp"

int AnimationController::b = 0; 
int AnimationController::f = 0;
std::string AnimationController::titulo {}; 
std::string AnimationController::x {}; 
std::string AnimationController::source {}; 
std::vector<std::vector<DataEntry>> AnimationController::infos {};
State AnimationController::estad = start;
int AnimationController::k = 0;
std::unordered_set<std::string> AnimationController::s;
int AnimationController::um = 0;
int AnimationController::i = 0;
std::vector<int> AnimationController::eixox {};
std::vector<charbar> AnimationController::bar {};
std::vector<std::string> v;
int tama = 0;
int nt = 0;
std::vector<int> contagem;
std::string cor;

/*!
 * Inicializa carregando configurações, dados do arquivo de configuração e os argumentos da linha de comando.
 *
 * @param argc O número de argumentos de linha de comando passados ​​para o programa.
 * @param argv Uma matriz de strings representando os argumentos de linha de comando.
 *
 * Esta função executa as seguintes etapas:
 * - Lê as configurações padrão do arquivo 'config.ini'.
 * - Analisa argumentos de linha de comando para substituir as configurações padrão.
 * - Valida a consistência dos argumentos e configurações fornecidos.
 * - Carrega dados do arquivo de banco de dados especificado.
 * - Classifica os dados por valor e extrai categorias relevantes.
 *
 * Se algum erro for encontrado (por exemplo, argumentos ausentes, caminhos de arquivo inválidos ou configurações inconsistentes), o programa sai com uma mensagem de erro.
 */
void AnimationController::initialize(int argc,char **argv) {
    std::ifstream ar("source/config.ini");
    std::string asd;
    std::string poi;
    std::getline(ar,asd);
    std::getline(ar,asd);
    std::stringstream ss(asd);
    std::getline(ss,poi,'=');
    std::getline(ss,poi);
    int b1= stoi(poi);
    std::getline(ar,asd);
    std::stringstream se(asd);
    std::getline(se,poi,'=');
    std::getline(se,poi,'=');
    int bt=stoi(poi);
    std::getline(ar,asd);
     std::stringstream s1(asd);
    std::getline(s1,poi,'=');
    std::getline(s1,poi,'=');
    int f1=stoi(poi);
    std::getline(ar,asd);
     std::stringstream s2(asd);
    std::getline(s2,poi,'=');
    std::getline(s2,poi,'=');
    int ft=stoi(poi);
    std::getline(ar,asd);
     std::stringstream s3(asd);
    std::getline(s3,poi,'=');
    std::getline(s3,poi,'=');
    tama = stoi(poi);
    std::getline(ar,asd);
     std::stringstream s4(asd);
    std::getline(s4,poi,'=');
    std::getline(s4,poi,'=');
    nt = stoi(poi);
    std::getline(ar,asd);
     std::stringstream s5(asd);
    std::getline(s5,poi,'=');
    std::getline(s5,poi,'=');
    cor = poi;
     std::getline(ar,asd);
     std::stringstream s6(asd);
    std::getline(s6,poi,'=');
    std::getline(s6,poi,'=');
    int label = stoi(poi);
    std::getline(ar,asd);
     std::stringstream s7(asd);
    std::getline(s7,poi,'=');
    std::getline(s7,poi,'=');
    int vale = stoi(poi);
    std::getline(ar,asd);
     std::stringstream s8(asd);
    std::getline(s8,poi,'=');
    std::getline(s8,poi,'=');
    int date = stoi(poi);
     std::getline(ar,asd);
     std::stringstream s9(asd);
    std::getline(s9,poi,'=');
    std::getline(s9,poi,'=');
    int cate = stoi(poi);
    std::getline(ar,asd);
     std::stringstream s11(asd);
    std::getline(s11,poi,'=');
    std::getline(s11,poi,'=');
    int other = stoi(poi);
    ar.close();
    std::string cores;
    if(cor ==" BLUE"){
        cores = " BLUE";
       cor = "\033[34m";
    }
    else if(cor ==" GREEN") { cor = "\033[32m";cores =" GREEN";}
    else if(cor == " RED")   {cor = "\033[31m";cores =" RED";}
    else if(cor == " YELLOW")    {cor = "\033[33m";cores= " YELLOW";}
    
    if (argc < 2) {
        std::cerr << "[ERRO] database não especificada.\n";
        exit(EXIT_FAILURE);
        }
    else if(argc==2){
        b = b1;
        f = f1;
    }
    else if(std::string(argv[1]) =="-f" and std::string(argv[3]) == "-b"){
        f = std::stoi(argv[2]);
        b = std::stoi(argv[4]);
        if(f>ft or b>bt){
            std::cerr << "[ERRO].\n";
            exit(EXIT_FAILURE);
        }
    }
    else if(std::string(argv[1]) =="-b" and  std::string(argv[3]) == "-f"){
        b = std::stoi(argv[2]);
        f = std::stoi(argv[4]);
        if(f>ft or b>bt){
            std::cerr << "[ERRO].\n";
            exit(EXIT_FAILURE);
        }
    }
    else if(std::string(argv[1])=="-f"){
        f = std::stoi(argv[2]);
        b=b1;
        if(f>ft or b>bt){
            std::cerr << "[ERRO].\n";
            exit(EXIT_FAILURE);
        }
    }
    else if(std::string(argv[1]) == "-b"){
        b = std::stoi(argv[2]);
        f=f1;
        if(f>ft or b>bt){
            std::cerr << "[ERRO].\n";
            exit(EXIT_FAILURE);
        }
    }
    else {
        std::cerr << "[ERRO] argumento inválido ou ausente.\n";
        exit(EXIT_FAILURE);
    }
    std::string as = (argv[argc-1]);
    std::ifstream arquivo(as);
    if (!arquivo.is_open()) {
        std::cerr << "[ERRO] ao abrir o arquivo: " << as << ". \n";
        exit(EXIT_FAILURE);
    }

    std::getline(arquivo, titulo);
    std::getline(arquivo, x);
    std::getline(arquivo, source);
    std::string linha;
    std::getline(arquivo, linha);
    while(linha.empty()){
         std::getline(arquivo, linha);
    }
        
    k = stoi(linha);
    int i = 0;
    int pas = k;
    while (arquivo.peek() != EOF) {
    if (i == 0) {
    
    } else {
        std::getline(arquivo, linha);
        k = stoi(linha);
        pas = k;
    }

    infos.resize(i + 1);
    for (int j = 0; j < k; j++) {
        std::getline(arquivo, linha);

        std::stringstream ss(linha);
        std::vector<std::string> campos;
        std::string campo;

        
        while (std::getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        infos[i].resize(j + 1);

       

        
        if (date < campos.size()) {
            infos[i][j].time_stamp = campos[date];
        }

        if (label < campos.size()) {
            infos[i][j].label = campos[label];
        }

        if (other < campos.size()) {
            infos[i][j].other_related_info = campos[other];
        }

        if (vale < campos.size()) {
            infos[i][j].value = campos[vale].empty() ? 0.0 : std::stod(campos[vale]);
            if(infos[i][j].value==0 and i!=0)pas--;
        }
            
        if (cate < campos.size()) {
            infos[i][j].category = campos[cate];
            if (!infos[i][j].category.empty()) {
                s.insert(infos[i][j].category);
            }
        }
    }

    contagem.push_back(pas);
    std::getline(arquivo, linha);
    while (linha == "\n") {
        std::getline(arquivo, linha);
    }
    
    i++;
}
    
    um = i;
    std::cout << ">>> We have \"" << i  << "\" charts, each with \"" << k << "\" bars." << "\n" << "\n";
    std::cout << ">>> Animation speed is: " << f << "\n";
    std::cout << ">>> Quantity of bars: " << b << "\n";
    std::cout << ">>> Title: " << titulo << "\n";
    std::cout << ">>> Value is: " << x << "\n";
    std::cout << ">>> " << source << "\n";
    std::cout << ">>> Quantity of categories found: " << s.size() <<"\n"<<"\n";
    for (const std::string& categoria : s) {   
    std::cout << "\"" << categoria << "\"" << "  ";
        
    }
    std::cout << "\n";

    std::cout << "\nLoaded Settings:\n";
    std::cout << "Default Bars: " << b1 << "\n";
    std::cout << "Max Bars: " << bt << "\n";
    std::cout << "Default FPS: " << f1 << "\n";
    std::cout << "Max FPS: " << ft << "\n";
    std::cout << "Max Bar Length: " << tama << "\n";
    std::cout << "Number of Ticks: " << nt << "\n";
    std::cout << "Default Color: " << cores << "\n";
    std::cout << "Label Index: " << label << "\n";
    std::cout << "Value Index: " << vale << "\n";
    std::cout << "Date Index: " << date << "\n";
    std::cout << "Category Index: " << cate << "\n";
    std::cout << "Other Index: " << other << "\n";
   for (auto& linha : infos) {
        std::sort(linha.begin(), linha.end(), [](const DataEntry& a, const DataEntry& b) {
            return a.value > b.value;
        });
    }
    arquivo.close();
};

/*!
 * Processa o estado atual da animação e executa ações com base no estado.
 *
 * @param argc O número de argumentos de linha de comando passados ​​para o programa.
 * @param argv Uma matriz de strings representando os argumentos de linha de comando.
 *
 * Lida com os diferentes estados da animação:
 * - **start**: Exibe uma mensagem de boas-vindas, inicializa configurações e dados e faz transições para o estado 'Welcome'.
 * - **welcome**: Prepara a animação para começar em transição para o estado 'Racing'.
 * - **racing**: Pausa alguns frames (com base no FPS configurado) para controlar a velocidade da animação.
 */
void AnimationController::process(int argc,char **argv){
    if(estad == start) {
        std::cout << "====================================" << std::endl;
        std::cout << "Welcome to the Bar Chart Race" << std::endl;
        std::cout << "Copyright (C) 2024, Claudivan Júnior" << std::endl;
        std::cout << "====================================" << std::endl << "\n";
        std::cout << ">>> Preparing to read input file \"" << argv[argc - 1] << "\"...\n";
        std::cout <<">>> Processing data, please wait...\n";
        initialize(argc, argv);
        estad = welcome;
        return;
    }
    if(estad == welcome) {
        estad = racing;
        return;
    }
    if(estad == racing){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / f));
        return;
    }    
};

/*!
 * Atualiza o estado do controlador de animação e executa ações com base no estado atual.
 *
 * Esta função lida com os seguintes estados:
 * - **welcome**: Não realiza nenhuma ação e retorna imediatamente.
 * - **racing**: Atualiza a animação do gráfico de barras. Caso todos os gráficos tenham sido processados, muda o estado para 'end'. Caso contrário, limpa a tela, atualiza o eixo X e ajusta os tamanhos das barras.
 */
void AnimationController::update(){
    if(estad == welcome){
        return;
    }
    if(estad == racing){
        if(i==um){
            estad = end;
            return;
        }
        system("clear");
        eixoxs();
        tamanhos();
        return;
    }
};

/*!
 * Renderiza a interface com base no estado atual da animação.
 *
 * Esta função lida com os seguintes estados:
 * - **welcome**: Exibe uma mensagem inicial solicitando que o usuário pressione Enter para iniciar a animação.
 * - **end**: Exibe uma mensagem de encerramento após o término da animação.
 * - **racing**: Renderiza as barras do gráfico e avança para o próximo quadro.
 */
void AnimationController::render() {
   if(estad == welcome){
        std::string a;
        std::cout << "Press enter to begin the animation." << "\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    else if(estad == end){
        std::cout << "Hope you have enjoyed the Bar Chart Race!" << "\n";
        return;
    }
    else if(estad == racing){
        render_bars();
        i++;
        return;
    }
};

/*!
 * Verifica se a animação chegou ao fim, avaliando seu estado atual para determinar se ela está concluída.
 *
 * @return TRUE se o estado atual for 'end', indicando que a animação terminou. Caso contrário, retorna FALSE.
 */
bool AnimationController::is_over(){
    if(estad == end){
        return true;
    }
    return false;
};

/*!
 * Renderiza as barras do gráfico na animação.
 *
 * Exibe as barras do gráfico de acordo com os dados processados, mostrando os valores, categorias e a escala do eixo X.
 */
void AnimationController::render_bars() {
     int aps;
    if(contagem[i]<b){
        aps = contagem[i];
    }
    else aps = b;
    std::cout << titulo << "\n" << "\n";
    std::cout << "Time stamp: " << infos[i][0].time_stamp << "\n" << "\n";
    for(int y = 0;y<aps;y++){
    for(int p = 0;p<bar[y].tam;p++){
    std::cout << bar[y].colors << "█"; 
    };
    std::cout << "  " << infos[i][y].label << "\033[37m" << " ["<< infos[i][y].value << "]" << "\n" << "\n";
    }
    std::vector<int> ta;
    ta.resize(b);
    std::cout << "\033[37m";
    for (int j = 0; j < nt; j++) {
        ta[j] = (eixox[j])/(infos[i][0].value) * tama;
    }

    
    int g = 0;
    for (int y = 0; y < 100; y++) {
        if (g < nt && y +1 == ta[nt - 1 - g]) {
            std::cout << "+";
            g++;
        } else if (y == 0) {
            std::cout << "+";
        } else {
            std::cout << "-";
        }
        if(ta[nt - 1 - g]==0)g++;
    }
    std::cout << "\n";
    g=0;
    for(int ja = 0;ja<100;ja++){
            if(0==ta[nt-1-g]and g==0){
                g++;
                 std::cout << "0";
            }
         else if(ja+1==ta[nt-1-g] and nt-1-g>=0){
            std::cout << eixox[nt-1-g];
            g++;
            if(eixox[nt-1-g] <=999)
            ja = ja + 2;
            else if(eixox[nt-1-g] <=9999)
            ja = ja + 3;
            else if(eixox[nt-1-g] <=99999){
            ja = ja + 4;
            }
            else if(eixox[nt-1-g] <=999999)
            ja = ja + 5;
             else if(eixox[nt-1-g] <=9999999)
             ja = ja + 6;
              else if(eixox[nt-1-g] <=99999999)
            ja = ja + 7;
             else if(eixox[nt-1-g] <=999999999)
             ja = ja + 8;
        }
        else if(ja == 0){
            std::cout << "0";
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << "\n";
    std::cout << x << "\n";
    int pl = 0;
    if(s.size()<=14){
    for (const std::string& categoria : s) {

    std::cout << v[pl] << "█:" << categoria << "  ";
    pl++;
    }
    }
    std::cout << "\n";
    std::cout << "\n";
}

/*!
 * Configura os valores do eixo X do gráfico.
 *
 * Ajusta os pontos do eixo X com base nos valores das barras visíveis no cenário atual, definindo uma escala proporcional e adequada para a exibição.
 */
void AnimationController::eixoxs(){
    eixox.resize(nt);
    int aps;
    if(contagem[i]<b){
        aps = contagem[i];
    }
    else aps = b;
    if(infos[i][0].value<1000){
        eixox[0] = (infos[i][0].value/10);
        eixox[0] = eixox[0]*10 + 10;
    }
    else if(infos[i][0].value<10000){
        eixox[0] = (infos[i][0].value/100);
        eixox[0] = eixox[0]*100 + 100;
    }
    else {
         eixox[0] = (infos[i][0].value/1000);
         eixox[0] = eixox[0]*1000 + 1000;
    }
    
    if(infos[i][aps-1].value<100){
        eixox[nt-1] = (infos[i][aps-1].value/10);
        eixox[nt-1] = eixox[nt-1]*10;
    }
    else if(infos[i][aps-1].value<1000){
        eixox[nt-1] = (infos[i][aps-1].value/100);
        eixox[nt-1]=eixox[nt-1]*100;
    }
    else{
          eixox[nt-1] = (infos[i][aps-1].value/1000);
        eixox[nt-1]=eixox[nt-1]*1000;
    }
    
    int k = (eixox[0] - eixox[nt-1])/(nt-1);
    for(int das = 1;das<nt-1;das++){
    eixox[das] = eixox[das-1] - k;
    }
};

/*!
 * Configura o tamanho e as cores das barras do gráfico.
 *
 * Define as proporções das barras e atribui cores com base em categorias, considerando os dados disponíveis no cenário atual.
 */
void AnimationController::tamanhos(){
    v.push_back("\033[31m"); // Red
    v.push_back("\033[32m"); // Green
    v.push_back("\033[33m"); // Yellow
    v.push_back("\033[34m"); // Blue
    v.push_back("\033[35m"); // Magenta
    v.push_back("\033[36m"); // Cyan
    v.push_back("\033[37m"); // White
    v.push_back("\033[91m"); // Bright Red
    v.push_back("\033[92m"); // Bright Green
    v.push_back("\033[93m"); // Bright Yellow
    v.push_back("\033[94m"); // Bright Blue
    v.push_back("\033[95m"); // Bright Magenta
    v.push_back("\033[96m"); // Bright Cyan
    v.push_back("\033[97m"); // Bright White
    int aps;
    if(contagem[i]<b){
        aps = contagem[i];
    }
    else aps = b;
    bar.resize(aps);
    if(infos[i][0].value==0){
    bar[0].tam = 0;
    }
    else bar[0].tam = tama;
    for(int j = 1;j<aps;j++){
         bar[j].tam = ((infos[i][j].value)/(infos[i][0].value))*tama;
    }
    int g = 0;
    if(s.size() <= 14){
    for(const auto& word : s){
    for(int j = 0;j<aps;j++){
         if(infos[i][j].category == word){
            bar[j].colors = v[g];
         }
    }
    g++;
    }
    }
    else{
        for(int j = 0;j<aps;j++){
            bar[j].colors = cor;
    }
    }
};