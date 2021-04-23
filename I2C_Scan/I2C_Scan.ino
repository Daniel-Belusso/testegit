/*                Programa: Scan I2C Adrres
 *                Por: Daniel Vinicius Belusso
 *                Email: danielvbelusso@gmail.com
 *                Data: 22/04/2021
 */

/*Retorno de Erros Wire.endTransmisson()
 * 0: Sucesso
 * 1: Dados muito longos para o buffer
 * 2: NACK recebido na transmissão do endereço
 * 3: NACK recebido na transmissão de dados
 * 4: outro erro
 */

#include <Wire.h>

void setup() {
  
  Wire.begin();
  Serial.begin(115200);
  delay(2000);
  Serial.println("\n\nEscaniando I2C\n");

  uint8_t addres, erro;

  for(addres = 1; addres < 127; addres++)
  {
    Wire.beginTransmission(addres);
    erro = Wire.endTransmission();

    if(erro == 0)//Addres compativel
    {
      Serial.print("Dispositivo encontrado, addres: 0x");

      if(addres < 16)
      {
        Serial.print("0");//Adiciona 0 para correte sintaxe de numeros hex
      }

      Serial.println(addres, HEX);//Addres do dispositivo
    }

    if(erro = 4)//Dispositivo invalido
    {
      Serial.print("Addres invalido: 0x");
      if(addres < 16)
      {
        Serial.print("0");//Adiciona 0 para correte sintaxe de numeros hex
      }
      Serial.println(addres, HEX);//Addres do dispositivo
    }
  }
  
  Serial.println("Scan comcluido!");

}

void loop() {


}
