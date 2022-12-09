/* Título: Pisca Led 
Autora: Bianca Lopes dos Santos
Data: 2022
Ambiente: IAR Embeded Workbench IDE; ver.: 5.60.2
Última rev: dezembro/2022
*/

/* Elabore para o kit 1611 que faça dois leds
piscarem(P1.0 e P1.1) com temporização selecionada
pela chave conectado ao pino p1.7:
chave=0 2Hz
chave=1 10Hz
*/

//------------------------------------------------------------------------

#include "io430.h"

//--------------------Variáveis globais-----------------------------------

#define Fclk 750e3
#define DISPLAY P5OUT 

//--------------------declaração de protótipos de funções-----------------

void Delay1ms();

//--------------------funções do sistema----------------------------------

// Função com tempo de atraso variável em milisegundos com faixa de 0 a 10.000ms (escala de tempo arbitrária)
void Delayms (int Tempo)
{  
  while (Tempo)
  {
    Delay1ms();
    Tempo--;
  }  
}

// Função com tempmo de atraso fixo em 1ms ou seja 750 pulsos de clk
void Delay1ms()
{
 int Repete = 184;
 
 while (Repete)
   Repete--;
}

//--------------------MAIN------------------------------------------------

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

// CONFIGURANDO PERIFERICOS
// Configura apenas o bit utilizado no programa
// Não altere os demais bits!  
  P1SEL &= ~(BIT0+BIT1+BIT7);    // Altera apenas os bits 0, 1 e 7
  P1DIR |= (BIT0+BIT1);          // Configura P1.0 e P1.1 como saída
  P1DIR &= ~BIT7;                // Configura P1.7 como entrada

 

 //Loop principal (loop infinito)
  while(1)
  {
    
      if(P1IN & BIT7){
  P1OUT = P1OUT | (BIT0+BIT1);  // Faz o P1.0 = 1
  Delayms(50);
 
  P1OUT = P1OUT & ~(BIT0+BIT1);  // Faz P1.0 = 0
  Delayms(50);
      }
  
   
      else{
   P1OUT = P1OUT | (BIT0+BIT1);  // Faz o P1.0 = 1
  Delayms(250);
 
  P1OUT = P1OUT & ~(BIT0+BIT1);  // Faz P1.0 = 0
  Delayms(250);
  
  
      } 
   }
  
}
