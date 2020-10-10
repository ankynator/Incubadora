#include <DHT.h>
#include <DHT_U.h>

int SENSOR = 8;
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.print(" Humedad: ");
  Serial.println(HUMEDAD);
  
  delay(1000);

}
