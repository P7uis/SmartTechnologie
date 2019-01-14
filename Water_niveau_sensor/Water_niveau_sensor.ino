//Eenmalige code
void setup() {
  // Start de seriele verbinding met een snelheid van 9600
  Serial.begin(9600);
}
// Herhalende code
void loop() {
  int sensorValue = analogRead(A3); // lees de sensor en zet de gegevens om naar text 
  Serial.println(sensorValue);   // Stuur de data naar de seriele verbinding
  delay(100); // Wacht kort voordat de nieuwe lezing gestart word
}
