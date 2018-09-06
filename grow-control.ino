#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 12 //Pin Ddigital 12
#define DHTTYPE DHT11 //Tipo de sensor "DHT11"
#define HUMPIN A0

DHT dht(DHTPIN, DHTTYPE); // Inicializamos el sensor DHT11

void setup() {
	Serial.begin(9600);
	dht.begin();
}

void loop() {
	delay(1000);//Ciclo cada medio segundo
 
	float h = dht.readHumidity(); //Porcentaje de humedad ambiental
	float t = dht.readTemperature(); //Temperatura en C
	int humedad = 1023 - analogRead(HUMPIN);
	
	if (isnan(h) || isnan(t)) {
		Serial.println("Error obteniendo los datos del sensor DHT11");
		return;
	}
	
	
	Serial.print("Humedad ambiente: ");
	Serial.print(h);
	Serial.print("%\t");
	Serial.print("Temperatura ambiente: ");
	Serial.print(t);
	Serial.print(" ºC ");
	Serial.print(" \t");
	Serial.print("Humedad suelo: ");
	//Serial.print(humedad);
	Serial.print(porcHumedad(humedad));
	Serial.print("%");
	Serial.println("");
}

int porcHumedad(int humedad){
	int salida = (humedad * 100) / 1023;
	return salida;
}
