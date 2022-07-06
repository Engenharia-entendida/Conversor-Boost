//Conversor Boots 15V/24V/200mA
//Eng. Danuzio Alves / Engenharia entendida

#include <PWM.h>                          //Biblioteca para o pwm   
#define pwm0 10                           //Pino de saída do pwm
int32_t frequency = 40000;                //Frequência em Hertz
int Duty0 = 88;                           //Variável que armazena o valor do Duty Cycle inicial     
int FeedBack = 0;                         //Variável que armazena o valor de feedback
//===================Setup===========================================================================================================================================//
void setup() {
InitTimersSafe();                         //Configura os registadores do Atmega para uma frequência maior
SetPinFrequencySafe(pwm0, frequency);     //Configura a frequência no pino de saída
}
//===================Loop============================================================================================================================================//
void loop() { 
  FeedBack=analogRead(A5);                //FeedBack da entrada
  pwmWrite(pwm0,Duty0);                   //Envia o valor para o pino pwm
    if(FeedBack<500){                     //Valor mínimo
      Duty0=Duty0+1;                      //Incrementa o Duty
      delay(10);                          //Tempo de estabilização
      }
    else if (FeedBack>620){               //Valor máximo
      Duty0=Duty0-1;                      //decrementa o Duty
      delay(10);                          //Tempo de estabilização
      } 
}


