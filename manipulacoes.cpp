#include "manipulacoes.h"

Pilha * importar_pilha(string &texto)
{
    //(12[JBV,IOF];13[UI,AE, IH];5[HJK])
    stringstream lineStream(texto);
    vector<string> arvorinha;
    vector<string> nozinhos;
    vector<string> idade;
    vector<string> iniciais;
    string		   ini;
    int			   years;

    getline(lineStream, ini, '(');				// Recebe o que tiver antes do (
    int Teste = conv_StringToInt(ini);		// Verifica se
                /*cout << " ---- Teste 1 ---- " << endl;
                getchar();*/
    if (Teste == 0){								// existe (.

        Pilha * arv_atual = new Pilha();


        // --Como é verdade monta arvore:
        arvorinha = split(texto, ')');				//Retira da linha: )
        arvorinha = split(arvorinha[0], '(');		//Retira da linha: (
        arvorinha[0] = arvorinha[1];				//Organizando posicao
        arvorinha.pop_back();						//Remove o ultimo.

        //cout << "\nArvore: ." +arvorinha[0] << endl;
        nozinhos = split(arvorinha[0], ';');		//Divide os nos por: ;

        int i = 0;
        int qtd = 0;

        int testador = 1;

        while (qtd < nozinhos.size()){

            // -----------------------
            //Apagando dados temporarios

            i = 0;
            while (i < iniciais.size()){
                if (i == 0){
                    idade.pop_back();
                }
                years = NULL;
                ini = iniciais[i];
                ini = "";
                iniciais.pop_back();
                i++;
            }

            //Capturando IDADE e estrutura de Iniciais;
            idade = split(nozinhos[qtd], '[');	//Pega a unica idade antes do: [
            ini = idade[1];
            idade.pop_back();	//Retira o exesso que é o segundo

            iniciais = split(ini, ']');	//Pega a estrutura de iniciais antes do: ]
            ini = iniciais[0];
            iniciais.pop_back();

            //Capturando INICIAIS;
            iniciais = split(ini, ',');	//Pegando iniciais separadas por: ,

            //Adicionando a arvore.
            for (int i = 0; i < iniciais.size(); i++){
                        /*cout << " Size: " << iniciais.size() << endl;
                        cout << " ---- Sub-testador 1 " << testador << endl;
                        getchar(); */
                ini = idade[0];
                        /*cout << " ---- Sub-testador 2 " << testador << endl;
                        getchar(); */
                years = conv_StringToInt(ini);
                        /*cout << " ---- Sub-testador 3 " << testador << endl;
                        getchar(); */
                ini = iniciais[i];
                        /*cout << " ---- Sub-testador 4 " << testador << endl;
                        getchar(); */
                arv_atual->Push_back_Org(years, ini);
                        /*cout << " ---- Sub-testador 5 " << testador << endl;
                        getchar();*/
            }
                        /*cout << " ---- Testador 5 " << testador << endl;
                        getchar();
                        testador++;*/
            qtd++;
        }
        return arv_atual;
    }
    else {
        cout << "\nEstrutura fora do padrao, sem: ( ou possui espaços." << endl;
    }
    return NULL;
}

vector<string> split(string str, char delimiter)
{
    vector<string> internal;      // Create to return a list.
    stringstream lineStream(str); // Turn the string into a stream.
    string vari;                  // Variable to get string before anything.

    while (getline(lineStream, vari, delimiter)) {
        internal.push_back(vari);
    }

    return internal;
}

