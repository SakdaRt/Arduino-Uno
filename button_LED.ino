#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define LED8 9
#define SW1 11
#define SW2 12
#define delay_LED 500
uint8_t state_ = 0;
uint32_t time_ = 0;
uint8_t LED_now[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
int8_t i = 0;
bool trigger = false;

void setup()
{
  Serial.begin(115200);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
}

void loop()
{
  if (digitalRead(SW1) == LOW) {
    state_ = 1;
    i = 0;
    time_ = 0;
    for (int x = 0; x <= 7 ; x++ ) {
      digitalWrite(LED_now[x], LOW);
    }
  }
  else if (digitalRead(SW2) == LOW) {
    state_ = 2;
    i = 7;
    time_ = 0;
    for (int x = 0; x <= 7 ; x++ ) {
      digitalWrite(LED_now[x], LOW);
    }
  }
  if (state_ == 0) {
    if (millis() - time_ > delay_LED) {
      time_ = millis();
      for (int x = 0; x <= 7 ; x++ ) {
        digitalWrite(LED_now[x], trigger);
      }
      trigger = !trigger;
    }
  }
  else if (state_ == 1) {
    if (millis() - time_ > delay_LED) {
      time_ = millis();
      for (int x = 0; x <= 7 ; x++ ) {
        digitalWrite(LED_now[x], LOW);
      }
      digitalWrite(LED_now[i], !digitalRead(LED_now[i]));
      i++;
      if (i > 7) {
        i = 0;
      }
    }
  }
  else if (state_ == 2) {
    if (millis() - time_ > delay_LED) {
      time_ = millis();
      for (int x = 0; x <= 7 ; x++ ) {
        digitalWrite(LED_now[x], LOW);
      }
      digitalWrite(LED_now[i], !digitalRead(LED_now[i]));
      i--;
      if (i < 0) {
        i = 7;
      }
    }
  }
}
