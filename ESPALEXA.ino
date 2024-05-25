#include <WiFi.h>
#include <BluetoothSerial.h>
#include <Espalexa.h>

const char* ssid = "Xiaomi 11T Pro";
const char* password = "xiaomiiinet";

BluetoothSerial SerialBT;
const int bedroomLightBulb = 15;
const int bathroomLightBulb = 16;
const int kitchenLightBulb = 17;

Espalexa espalexa;

void setBedroomLight(uint8_t brightness) {
  digitalWrite(bedroomLightBulb, brightness > 0 ? HIGH : LOW);
}

void setBathroomLight(uint8_t brightness) {
  digitalWrite(bathroomLightBulb, brightness > 0 ? HIGH : LOW);
}

void setKitchenLight(uint8_t brightness) {
  digitalWrite(kitchenLightBulb, brightness > 0 ? HIGH : LOW);
}

bool connectToWiFi() {
  WiFi.begin(ssid, password);
  unsigned long startAttemptTime = millis();

  // Attempt to connect for 10 seconds
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    delay(100);
  }

  return WiFi.status() == WL_CONNECTED;
}

void setup() {
  Serial.begin(9600);
  SerialBT.begin("Bluetooth Lightbulb System");

  pinMode(bedroomLightBulb, OUTPUT);
  digitalWrite(bedroomLightBulb, LOW); // Ensure the lightbulb is OFF at the beginning

  pinMode(bathroomLightBulb, OUTPUT);
  digitalWrite(bathroomLightBulb, LOW);

  pinMode(kitchenLightBulb, OUTPUT);
  digitalWrite(kitchenLightBulb, LOW);

  // Connect to Wi-Fi

  bool wifiConnected = connectToWiFi();
  if (wifiConnected) {
    Serial.println("Connected to Wi-Fi");
  } else {
    Serial.println("Failed to connect to Wi-Fi");
  }

  // Initialize Espalexa
  espalexa.addDevice("Bedroom Light", setBedroomLight);
  espalexa.addDevice("Bathroom Light", setBathroomLight);
  espalexa.addDevice("Kitchen Light", setKitchenLight);

  espalexa.begin();
}

void loop() {
  if (SerialBT.available()) {
    int x = SerialBT.read();
    if (x == '0') {
      digitalWrite(bedroomLightBulb, LOW);
    } else if (x == '1') {
      digitalWrite(bedroomLightBulb, HIGH);
    }
    else if (x == '2') {
      digitalWrite(bathroomLightBulb, LOW);
    }
    else if (x == '3') {
      digitalWrite(bathroomLightBulb, HIGH);
    }
    else if (x == '4') {
      digitalWrite(kitchenLightBulb, LOW);
    }
    else if (x == '5') {
      digitalWrite(kitchenLightBulb, HIGH);
    }
    else if (x == '8')
    {
      digitalWrite(bedroomLightBulb, HIGH);
      digitalWrite(kitchenLightBulb, HIGH);
      digitalWrite(bathroomLightBulb, HIGH);
    }
    else if (x == '9')
    {
      digitalWrite(bedroomLightBulb, LOW);
      digitalWrite(kitchenLightBulb, LOW);
      digitalWrite(bathroomLightBulb, LOW);
    }
    

  }
  espalexa.loop();
}