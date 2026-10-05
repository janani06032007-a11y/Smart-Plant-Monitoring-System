#define MOISTURE_PIN A0
#define LED_PIN 2
#define BUZZER_PIN 8

int moistureValue;
int moisturePercent;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {

  // Read the simulated soil moisture sensor
  moistureValue = analogRead(MOISTURE_PIN);

  // Convert sensor value to percentage
  moisturePercent = map(moistureValue, 1023, 0, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Check soil condition
  if (moisturePercent < 40) {

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("Soil Condition: DRY");
    Serial.println("Alert: Plant needs water!");

  } else {

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Soil Condition: WET");
  }

  Serial.println("--------------------");

  delay(1000);
}
