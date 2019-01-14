// Deze vaste waardes zullen niet veranderen
const int  irPin = 2;           // defineer de pin war de infrarood hindernis sensor op aangesloten is
const int ledPin = LED_BUILTIN; // defineer de pin war de LED op aangesloten is

// Variable die wel zullen veranderen
int Counter = 0;   // Counter = Teller | Teller voor het aantal detecties van de infrarood hindernis sensor
int State = 0;         // State = Status | Huidige status van de infrarood hindernis sensor
int lastState = 0;     // lastState = Laatste/vorige status | vorige status van de infrarood hindernis sensor


// Eenmalige code na het opstarten van de microprocessor
void setup() {
  // Stel de infrarood sensor sigaal pin in als input (ingang)
  pinMode(irPin, INPUT);
  // Stel de LED in als output (uitgang)
  pinMode(ledPin, OUTPUT);
  // Start de seriele verbinding met een snelheid van 9600
  Serial.begin(9600);
}

// Herhalende code
void loop() {
  // read the pushbutton input pin:
  State = digitalRead(irPin);

  // Vergelijk de detectiestatus (State) met de vorige detectiestatus (LastState)
  if (State != lastState) {
    // Als de status veranderd is, tel één op bij de teller (counter)
    if (State == LOW) {
      // Als de huidige status gelijk is aan LOW dan is het sigaal van HIGH naar LOW gegaan
      Counter++;
      Serial.println("Detection");
      Serial.print("number of passes: ");
      Serial.println(Counter);
    } else {
      // Als de huidige status gelijk is aan HIGH dan is het sigaal van LOW naar HIGH gegaan.
      Serial.println("Clear");
    }
    // Vertraag iets om dubbele tellingen te voorkomen
    delay(50);
  }
  // Sla de huidige status op als vorige status voor de volgende code loop
  lastState = State;


  // Zet de LED aan bij elke 10 ͤ telling
  if (Counter % 10 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
