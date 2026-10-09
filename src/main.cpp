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
  //? string = tipo de variável de texto
  //? length = comprimento
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade); //* Comprimento do texto: 9



  //TODO Descobrindo o espaco que o texto utiliza
  //* Enquanto temos 9 caracteres no texto, como visto acima
  //* No espaco utilizado, vemos que ele gasta um espaco a mais do que o tanto de caracteres
  //* Esse espaco a mais é o '\0'
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaco utilizado: ");
  Serial.println(tamanhoVariavelCidade); //* Espaco utilizado: 10



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
    Serial.print("Letra encontrada na posicao ");
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

}

void textoString()
{

}