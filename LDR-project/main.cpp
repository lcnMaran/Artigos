/*******************************************************
 *                Leitura LDR
 * 
 * @author: Luciano Maran
 * @date:   Janeiro de 2023
 * 
********************************************************/
#include <Arduino.h>


#define bt_LDR      9
#define bt_CHUVA   10
#define sensor_LDR  8
#define myOutput    7


uint8_t rtn_Sensor(); //Protótipo de função


void setup() 
{
  Serial.begin(9600);

  //Configuração pinos de entrada
  pinMode(bt_LDR,     INPUT);
  pinMode(bt_CHUVA,   INPUT);
  pinMode(sensor_LDR, INPUT);

  //Configuração pino de saída
  pinMode(myOutput,   OUTPUT);

}


void loop() 
{

  switch (rtn_Sensor()){
    case 0: //Sensores ativos
    digitalRead(sensor_LDR) == 0 ? Serial.println("LDR: Noite") : Serial.println("LDR: Dia");
    break;
    
    case 1: //Sensor CHUVA: ativo
    break;

    case 2: //Sensor LDR: ativo
    if(digitalRead(sensor_LDR)) //Outra maneira de fazer verificação
    {
      digitalWrite(myOutput, LOW);
      Serial.println("LDR: Dia");
    }else
    {
      digitalWrite(myOutput, HIGH);
      Serial.println("LDR: Noite");
    }
    break;

    case 3: //Sensores desativados
    break;
  
    default: //Conselho: Sempre use default!
    break;
  }

  delay(1000); //Leitura a cada segundo
  
}


/**
 * @brief Seleção dos sensores
 * @return Decimal: 0 a 3
*/
uint8_t rtn_Sensor()
{

  uint8_t switch_state;
  return switch_state = digitalRead(bt_LDR) | (digitalRead(bt_CHUVA) << 1 );

}