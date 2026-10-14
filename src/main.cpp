#include <Arduino.h>
#include <string.h> //* strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //* atoi

void textoChar();
void textoString();

void setup() 
{
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop() {}

void textoChar()
{
  //TODO  Laranja  =  Título de cada bloco
  //?     Azul     =  Informacões extras
  //*     Verde    =  Explicacões
  //!     Vermelho =  Avisos e outros títulos



  //!===========================
  //!===     USANDO char     ===
  //!===========================


  //TODO Texto literal
  //* Use const char quando o texto não será alterado
  //* Use char* quando não souber a quantidade de espaco que seu texto gastará
  const char cidade[] = "Sao Paulo";
  Serial.println(cidade);



  //TODO Descobrindo o tamanho do texto
  //* strlen conta quantos caracteres antes do '\0'
  //* Todo conjunto de caracteres termina com um '\0'
  //* '\0' = NULL
  //? strlen = string length
  //? string = uma classe, às vezes confundido com tipo de variável
  //? length = comprimento
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade); //? Comprimento do texto: 9



  //TODO Descobrindo o espaco que o texto utiliza
  //* Enquanto temos 9 caracteres no texto, como visto acima
  //* No espaco utilizado, vemos que ele gasta um espaco a mais do que o tanto de caracteres
  //* Esse espaco a mais é o '\0'
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaco utilizado: ");
  Serial.println(tamanhoVariavelCidade); //? Espaco utilizado: 10



  //* Quando se coloca aspas duplas o programa entende como texto
  //* E coloca o '\0' automaticamente
  //* Porém quando em aspas simples é necessário colocar um espaco a mais no vetor
  //* Especificamente para o '\0'
  //? "Aspas Duplas" = String    |    'Aspas Simples' = Caractere
  char vetorTexto[6] = {'B','r','u','n','o','\0'};
  Serial.println(vetorTexto);



  //TODO Comparar Texto
  const char* cidade1 = "Sao Caetano";
  const char* cidade2 = "Sao Caetano";
  //? strcmp = string compare
  //? compare = comparar
  if(strcmp(cidade1, cidade2) == 0)
    Serial.println("Os textos sao iguais");
  else
    Serial.println("Os textos sao diferentes");
    
  //* strcmp analisa a ordem léxica das palavras, se a primeira palavra
  //* vem antes que a segunda, o valor retornado será menos que zero, 
  //* se a primeira vem após a segunda, o retorno será maior que zero
  //* e se as duas são iguais, o valor será igual a zero


  //!===================================
  //!===  TEXTO EDITAVEL COM char[]  ===
  //!===================================


  //! Sempre considerar o '\0' quando definir o tamanho do vetor
  char nomeAluno[6] = "Brunp";
  Serial.println(nomeAluno);

  //TODO Alterando caracteres individualmente
  nomeAluno[4] = 'o';
  Serial.println(nomeAluno);



  //TODO Copiando o texto para dentro do vetor
  //! CUIDADO: o vetor precisa de espaco suficiente

  //? strcpy = string copy
  //? copy = copiar
  //* strcpy está copiando/substituindo o texto "Tadeu" para a variável "nomeAluno"
  strcpy(nomeAluno, "Tadeu");
  Serial.println(nomeAluno);

  
  //TODO Concatenando de texto ao final
  char frase[40] = "Ola ";
  //? strcat = string concatenation
  //? concatenation = concatenacão
  //* strcat está juntando as duas palavras e colocando na mesma variável
  strcat(frase, "Mundo!");
  Serial.println(frase);



  //TODO Procurando um caractere no texto
  //? strchr = string char
  //? char = caractere
  //* strchr está procurando a posicão da letra pedida, nesse caso 'M',
  //* após isso é pedido que imprima a partir dela (se encontrada),
  //* já que o strchr retorna uma posicão ao invés do caractere em si
  char* posicaoLetra = strchr(frase, 'M');

  if(posicaoLetra != NULL)
  {
    Serial.print("Letra encontrada! ");
    Serial.println(posicaoLetra);
  }
  else
    Serial.println("Letra nao encontrada");



  //TODO Convertendo texto numérico para inteiro
  char idadeTexto[] = "45"; 
  //? 52 (posicão do número 4 na tabela ASCII), 
  //? 53 (posicão do número 5 na tabela ASCII), 
  //? '\0'
  //* Então para converter para os números "corretos" faremos
  int idade = atoi(idadeTexto);
  //? atoi = ASCII to int
  Serial.println(idade);



  //TODO Montando Texto
  char buffer[100];
  char* local = "Sala de Aula";
  float temperatura = 26.4;
  int umidade = 58;

  //* snprintf = Funcão para montar um texto em um vetor de char, com tamanho definido
  //? snprintf: s = string | n = pra definir o tamanho e não haver vazamento de dados | ... printf
  //* Síntaxe: snprintf(variavelOndeSeraMontadoOTexto, TamanhoMaximoDoTexto, TextoComFormatacão, ItensDeFormato);
  //* Isso é muito útil quando depois voce quer:
  /*
   * - salvar o texto em uma variavel 
   * - mandar para o display
   * - imprimir na serial
   * enviar por MQTT (IoT)
   */


  //! CUIDADO para não usar "sprintf"  
  snprintf(buffer, sizeof(buffer), "%s | Temp.: %.1f | Umid.: %d %% \n\r", local, temperatura, umidade);
  //?                               %s = string | %f = float | %d = int | %% = % (literalmente o símbolo)
  //?                                                          %i = int

  //? \n = troca de linha (enter) | \r = volta pra "posicão 0"
  //? senão ele continuaria a escrever em outra linha, mas na mesma posicão
  //* Esses comandos também funcionam para Serial.printf

  //? O que eu quero que esse comando printe:  Sala de Aula | Temp.: 26.4 | Umid.: 58%
  Serial.print(buffer);
  Serial.printf("O tamanho do buffer é %lu \n\r", sizeof(buffer));

  /*
  TODO ESPECIFICADORES:

  ? %d ou %i   - int
  ? %u         - unsigned int
  ? %ld        - long
  ? %lu        - unsigned long
  ? %f         - float
  ? %e         - notacão científica
  ? %g         - float, formato mais curto
  ? %c         - char
  ? %s         - char* (string)
  ? %x ou %X   - hexadecimal minúsculo/maiúsculo
  ? %o         - octal
  ? %p         - ponteiro
  ? %%         - o próprio "%"



  TODO Flag, largura e precisão

  * %5d        - imprime com largura mínima de 5, alinhado a direita [    3], [  100], [10000000]
  * %-4d       - imprime com largura mínima de 4, alinhado a esquerda [3   ], [100 ], [123456]
  * %03d       - completa com zeros a esquerda [003]
  * %+d        - sempre mostra o sinal [+3], [-3]
  * %.2f       - 2 casas decimais num float
  * %4.2f      - largura mínima 4, a direita e com 2 casas decimais
  * %02X       - hexadecima com 2 dígitos [0F], [3A]
  * %#x        - imprime o prefixo "0x" [0x2a]
  * %.3s       - somente os 3 primeiros caracteres da string
  * %*d        - largura passada como argumento
  * ex:
  * int largura = 3
  * int numero = 9
  * snprintf(buffer, sizeof(buffer), "numero %*d", largura, numero)
  * Serial.print(buffer)  ->  [  9]

  ! Todos que possuem números são alteráveis, podem ser misturados e o número pode ser alterado por "*" podendo passar os parametros depois

  ! SEMPRE ESCREVER OS PARAMETROS NA ORDEM QUE VOCE OS PASSA/PEDE
  */
}

void textoString()
{
  //!=============================
  //!===     USANDO String     ===
  //!=============================


  String nome = "Bruno";
  String curso = "Logica de programacao";
  String mensagem = "Ola";

  //TODO Concatenando String
  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  

  //TODO Tamanho da String
  int tamanhoMensagem = mensagem.length();
  Serial.print("Tamanho da String em letras: ");
  Serial.println(tamanhoMensagem);



  //TODO Acessando um caractere em uma posicão específica
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira letra: ");
  Serial.println(primeiraLetra);

  //? Também é possível acessar com colchetes
  char segundaLetra = mensagem[1];
  Serial.print("Segunda letra: ");
  Serial.println(segundaLetra);



  //TODO Procurando um texto dentro da String
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.print("A palavra comeca na posicao: ");
  Serial.println(posicaoTextoProcurado);



  //TODO Extraindo um texto dentro da String
  int inicioNomeCurso = posicaoTextoProcurado + 9;  //?       1  2  3  4  5  6  7  8  9
  //? Posicão da palavra "curso" + 9 caracteres, sendo esses (c, u, r, s, o,  , d, e,  )
  Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1)); 
  //? -1 foi colocado para que o "." não fosse incluído junto do resto



  //TODO Substituindo um texto dentro da String
  mensagem.replace("Ola,", "Oi, tudo bom? ");
  Serial.println(mensagem);



  //TODO Convertendo tudo para maiúsculas
  mensagem.toUpperCase();
  Serial.println(mensagem);



  //TODO Convertendo tudo para minúsculas
  mensagem.toLowerCase();
  Serial.println(mensagem);



  //TODO Convertendo texto numérico para inteiro
  String textoNumero = "123";
  int numero = textoNumero.toInt();
  Serial.println(numero * 2);
  //? Adicionado o *2 para provar que se tornou um numero e agora é possível fazer cálculos



  //TODO Verificando se a String está vazia
  String textoVazio = "";
  if(textoVazio.length() == 0)
    Serial.println("O texto esta vazio");



  //TODO Convertendo String para const char*
  //? Isso é útil quando alguma biblioteca espera texto estilo C
  const char* textoComoChar = mensagem.c_str();
  Serial.println(textoComoChar);

  //! NÃO ESQUECER DE COLOCAR PARENTESES NO FIM DE TODAS AS FUNCÕES,
  //! AFINAL SÃO FUNCÕES DE UMA CLASSE (String)
}