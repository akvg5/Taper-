/*
  SD card datalogger

  The circuit:
   analog sensors on analog ins 0, 1, and 2
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>
#define PAINEL_SOLAR = 0;
#define GAIGHER =
#define SLOSHING1 = 
#define SLOSHING2 = 
#define SLOSHING3 = 
#define SLOSHING4 = 
#define SLOSHING5 = 
#define SLOSHING6 = 
#define SLOSHING7 = 
#define SLOSHING8 = 

 
float volts = 0.0;

const int chipSelect = 4;

void setup() {
 
  //PRECISAMOS COLOCAR O REMOVE BEFORE FLIGHT 
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {

   volts = analogRead(3)*(5.0/1023.0);
  // make a string for assembling the data to log:
  String dataString = "";

  //Pino 0 é o painel solar.

  const RESISTENCIA_PAINEL = 100;

  float gaigher;
  float tensao_painel;
  float corrente_painel;
  float sloshing1 = analogRead(SLOSHING1)*(5.0/1023.0;
  float sloshing2 = analogRead(SLOSHING2)*(5.0/1023.0);
  float sloshing3 = analogRead(SLOSHING3)*(5.0/1023.0);
  float sloshing4 = analogRead(SLOSHING4)*(5.0/1023.0;
  float sloshing5 = analogRead(SLOSHING5)*(5.0/1023.0;    
  float sloshing6 = analogRead(SLOSHING6)*(5.0/1023.0;
  float sloshing7 = analogRead(SLOSHING7)*(5.0/1023.0;
  float sloshing8 = analogRead(SLOSHING8)*(5.0/1023.0;
  
  

  
  tensao_painel = analogRead(PAINEL_SOLAR);
  tensao_painel = tensao_painel*(5.0/1023.0);
  gaigher = analogRead(GAIGHER);
  
  corrente_painel = tensao_painel/RESISTENCIA_PAINEL;

  dataString += String(gaigher);
  dataString += ",";
  dataString += String(tensao_painel);
  dataString += ",";
  dataString += String(corrente_painel);
  dataString += ",";
  dataString += String(sloshing1);
  dataString += ",";
  dataString += String(sloshing2);
  dataString += ",";
  dataString += String(sloshing3);
  dataString += ",";
  dataString += String(sloshing4);
  dataString += ",";
  dataString += String(sloshing5);
  dataString += ",";
  dataString += String(sloshing6);
  dataString += ",";
  dataString += String(sloshing7);
  dataString += ",";
  dataString += String(sloshing8);


/*3

 7/2 = 3 resta 1 * 4
 3/2 = 1 resta 1 * 2
 1/2 = 0 resta 1 * 1

5/2 = 2
1resta 1*4
2/2 = 1 resta 0*2
1/2 = 0 resta 1*1

-             0*4
3/2 = 1 resta 1*2
1/2 = 0 resta 1*1

001
111
101
*/
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("carga_paga.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    
 
  }
  // if the file isn't open, pop up an error:
  else {

  }
  delay(1000);
}



int converte_pra_numero(float sloshing)
{
  //Código que converte a tensão em um núemro entre 0 e 123

  return numero;
}





  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin); 
    dataString += String(sensor);
    if (analogPin < 2) {              
      dataString += ",";
    }
  }
