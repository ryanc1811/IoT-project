#define button 6  // Button connected to D6
#define LED 8     // LED connected to D8
#define buzzer 3  // Buzzer connected to D3

int button_state = 0;        // Variable for reading the button state
int last_button_state = 0;   // Variable to store the previous button state
bool led_on = false;         // Variable to track the LED state (on or off)
bool buzzer_on = false;      // Variable to track the buzzer state (on or off)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the button pin as input
  pinMode(button, INPUT);

  // Set the LED and buzzer pins as outputs
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Initially turn off the LED and buzzer
  digitalWrite(LED, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // Read the current state of the button (HIGH when pressed, LOW when not)
  button_state = digitalRead(button);

  // Detect if the button has been pressed (transition from LOW to HIGH)
  if (button_state == HIGH && last_button_state == LOW) {
    // Toggle the LED and buzzer states
    led_on = !led_on;      // Toggle the LED state
    buzzer_on = !buzzer_on; // Toggle the buzzer state

    // Update the LED based on the new state
    if (led_on) {
      digitalWrite(LED, HIGH);  // Turn on the LED
      Serial.println("LED ON");
    } else {
      digitalWrite(LED, LOW);   // Turn off the LED
      Serial.println("LED OFF");
    }

    // Update the buzzer based on the new state
    if (buzzer_on) {
      digitalWrite(buzzer, HIGH);  // Turn on the buzzer
      Serial.println("Buzzer ON");
    } else {
      digitalWrite(buzzer, LOW);   // Turn off the buzzer
      Serial.println("Buzzer OFF");
    }
  }

  // Update the last button state for the next loop
  last_button_state = button_state;

  // Small delay to avoid bouncing issues
  delay(50);
}
