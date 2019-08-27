/*==============================================================================
* Projeto: RF 433/434Mhz Acionamento Simples
* Iniciado em:  22/08/2019
* Terminado em: 23/08/2019
* Disponibilizado por: El Cereza
* Editado e Comentado por: Gustavo Cereza
*
* Contato
* {
*   Site:      www.elcereza.wordpress.com
*   Instagram: https://www.instagram.com/ellcereza/
*   Github:    https://github.com/EllCereza
*   Facebook:  https://www.facebook.com/ellcereza/
*   Grupo AC:  https://www.facebook.com/groups/1078399229008226/?ref=group_header
* }
* 
* 
* Desenvolvido por: Suat Özgür
* 
* Contato
* {
*   Github: https://github.com/sui77
* }
* 
* Biblioteca: https://github.com/sui77/rc-switch/
==============================================================================*/

#include <RCSwitch.h>                                                         // Inclue biblioteca RCSwitch
RCSwitch mySwitch = RCSwitch();                                               // Atribue variável mySwitch o valor de RCSwitch                                     

void setup() {
  Serial.begin(9600);                                                         // Estabelece 9600 como velocidade de BaudRate
  mySwitch.enableReceive(0);                                                  // Inicializa leitura no pino digital 2
}                                                                             // Finaliza setup

void loop() {
  if (mySwitch.available()) {                                                 // Avalia se tá recebendo sinal
    Serial.print("Recebido ");                                                
    Serial.print( mySwitch.getReceivedValue() );                              // Printa o valor recebeido pelo RF
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );                          // Printa a quantidade de bit's
    Serial.print("bit ");
    Serial.print("Protocolo: ");
    Serial.println( mySwitch.getReceivedProtocol() );                         // Printa o protocolo

    if(mySwitch.getReceivedValue() == 177963301)                              // Se mySwitch receber o valor do programado, vai por a porta 13 em nível alto
    {
     digitalWrite(13,1);                                                      // Liga o LED
    } if(mySwitch.getReceivedValue() == 177963285)                            // Se mySwitch receber o outro valor programado, vai por o nível lógico baixo
    {
      digitalWrite(13,0);                                                     // Desliga o LED
    }
    mySwitch.resetAvailable();                                                // Reinicia leitura
  }
}                                                                             // Finaliza loop
