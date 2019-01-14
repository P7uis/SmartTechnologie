// Deze vaste waardes zullen niet veranderen
const int SwitchPin = 8;     //defineer de pin war de balschakelaar op aangesloten is
const int ledPin = LED_BUILTIN; //defineer de pin war de LED op aangesloten is

// Variable die wel zullen veranderen
int Counter = 0;   // Counter = Teller | Teller voor het aantal omschakelingen van de balschakelaar
int State = 0;         // State = Status | Huidige status
int lastState = 0;     // LastState = Laatste/vorige status | vorige status van de balschakelaar

// Eenmalige code na het opstarten van de microprocessor
void setup() {
  // Stel de balschakelaar in als input (ingang)
  pinMode(SwitchPin, INPUT);
  // Stel de LED in als output (uitgang)
  pinMode(ledPin, OUTPUT);
  // Start de seriele verbinding met een snelheid van 9600
  Serial.begin(9600);
}

// Herhalende code
void loop() {
  // Lees de balschakelaarpin/SwitchPin (sigaalpin van de balschakelaar)
  State = digitalRead(SwitchPin);

  // Vergelijk de detectiestatus (State) met de vorige detectiestatus (LastState)
  if (State != lastState) {
    // Als de status veranderd is, tel één op bij de teller (counter)
    if (State == LOW) {
      // Als de huidige status gelijk is aan LOW dan is het sigaal van HIGH naar LOW gegaan
      Counter++;
      Serial.print("wipbewegingen: ");
      Serial.println(Counter);
    } else {
      // Als de huidige status gelijk is aan HIGH dan is het sigaal van LOW naar HIGH gegaan.
      Counter++;
      Serial.print("wipbewegingen: ");
      Serial.println(Counter);
    }
    // Vertraag iets om dubbele tellingen te voorkomen
    delay(500);
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
