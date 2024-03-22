# Introdução

Os módulos a seguir foram desenvolvidos para resolução de atividades práticas da disciplina de Computação Gráfica, que foram:

- Atividade Prática de Transformação de Visualização.
- Atividade Prática de Desenho de Círculo através de triângulos utilizando a Estrutura de Dados "Shared Vertex".

*[Você pode encontrar o diretório do projeto hospedado originalmente no repositório "IFCE_Estudos" no GitHub.](https://github.com/1manuelc/IFCE_estudos/tree/main/S5/Computacao_Grafica/cg-atv-transf-visualizacao)*

# Para executar

Antes de tudo, você deve ter instalado em seu sistema operacional:

- Node.js (ambiente de execução para JavaScript)
- NPM (gerenciador de pacotes)

Para visualizar graficamente de forma interativa o desenho de círculo através de Shared Vertex utilizando o arquivo "demo.py", você deve instalar:

- Python
- pip (gerenciador de pacotes necessário para obter o pacote pygame e renderizar figuras graficamente)

## Comandos para execução

Primeiramente, instale as dependências necessárias através do comando npm:
`npm i` ou `npm install`

Para executar o programa principal contido em "index.mjs", você deve utilizar:

`npm run dev` ou `node index.mjs`

Para executar a visualização gráfica em Python:

`npm run demo` ou `python3 demo.py`

# Noções básicas

Os módulos contidos na pasta `./modules/` são responsáveis por representar unidades básicas na Computação Gráfica (como o Ponto em [`./modules/Point.mjs`](./modules/Point.mjs)) e Sistemas de Referência abordados em sala de Aula (como [`./modules/SRU.mjs`](./modules/SRU.mjs)).

Com suas coordenadas, atribuições, regras e transformações, a associação dos módulos pode compor estruturas de formas geométicas, transformar visualizações entre dispositivos e ensinar noções básicas de Computação Gráfica na prática.

## Aspectos técnicos

Toda representação de um elemento da <abbr title="Computação Gráfica">CG</abbr> neste projeto é feita por classes instanciáveis através de construtores que pedem argumentos necessários para a lógica de construção. Lógica esta que está incluída nos tópicos da disciplina, os conceitos são fundamentais para compreensão do código.

## Primeiros passos

- Explore de maneira rápida os módulos para entender seu funcionamento e requisitos para instanciação.
- Defina um <abbr title="Sistema de Referência do Usuário/Universo">`SRU`</abbr> (por padrão é instanciado vazio).
- Defina `Pontos` e fique á vontade para atribuir ao SRU e obter coordenadas simples e normalizadas.
- Defina um <abbr title="Sistema de Referência do Dispositivo">`SRD`</abbr> e converta Pontos para as coordenadas do dispositivo, recebendo um tipo especial de ponto sem coordenadas normalizadas, o `SRD_Point`.
- Utilize o módulo `SharedVertex.mjs` para implementar visualizações/desenhos de formas utilizando listas de **Faces** e **Vértices** de triângulos.
- Utilize declarações de polígonos no construtor de `SharedVertex.mjs` para compor polígonos conhecidos e realizar operações com métodos internos á mesma classe.
