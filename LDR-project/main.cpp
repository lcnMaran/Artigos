/*******************************************************
 *                Leitura LDR
 * 
 * @author: Luciano Maran
 * @date:   Dezembro de 2022
 * 
********************************************************/
#include <Arduino.h>


#define bt_LDR     9
#define bt_CHUVA  10


uint8_t rtn_Sensor(); //Protótipo de função


void setup() 
{
  Serial.begin(9600);

  //Configuração pinos de entrada
  pinMode(bt_LDR,   INPUT);
  pinMode(bt_CHUVA, INPUT);
}

void loop() 
{

  switch (rtn_Sensor()){
    case 0:
    Serial.println("Sensores ativos");
    break;
    
    case 1:
    Serial.println("Sensor CHUVA: ativo");
    break;

    case 2:
    Serial.println("Sensor LDR: ativo");
    break;

    case 3:
    Serial.println("Sensores desativados");
    break;
  
    default:
    //Conselho: Sempre use default!
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