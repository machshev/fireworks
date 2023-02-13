#include <RFTransmitter.h>

#define NODE_ID          1
#define OUTPUT_PIN       11

// Send on digital pin 11 and identify as node 1
RFTransmitter transmitter(OUTPUT_PIN, NODE_ID);
unsigned int transmit_num = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  const char *msg = "Hello World!";

  transmit_num++;
  Serial.println("");
  Serial.print("Sending Package: ");
  Serial.println(transmit_num);
  Serial.print("Sender: ");
  Serial.println(NODE_ID);
  Serial.print("Message: ");
  Serial.println(msg);
  transmitter.send((byte *)msg, strlen(msg) + 1);

  delay(5000);

  transmit_num++;
  Serial.println("");
  Serial.print("Resending Package: ");
  Serial.println(transmit_num);
  Serial.print("Sender: ");
  Serial.print("Message: ");
  Serial.println(msg);

  transmitter.resend((byte *)msg, strlen(msg) + 1);
}