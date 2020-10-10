#include <DHT.h>
#include <DHT_U.h>

#define IDEAL 35
#define TIEMPO 60000

int SENSOR = 8;
int RELE = 2;
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(RELE, OUTPUT);
}

void loop() {
  medir();
  //prender rele
  digitalWrite(RELE, LOW);
  while(TEMPERATURA < IDEAL){
    medir();
  }
  //apagar rele
  digitalWrite(RELE, HIGH);
  while(TEMPERATURA >= IDEAL) {
    medir();
  }
  digitalWrite(RELE, HIGH);
}

void medir() {
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.print(" Humedad: ");
  Serial.println(HUMEDAD);
  
  delay(TIEMPO);
}
