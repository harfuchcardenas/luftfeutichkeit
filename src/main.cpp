#include <Arduino.h>
#include <stdio.h>


// put function declarations here:
int myFunction(int, int);
int analogValue [16];
int analogPin = 34;
float mean_humidity = 0.0;
int size_a = 16;
int measurements [16];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(analogPin, INPUT); // GPIO as input
}
double mean(int sum, int size_a){
  float average = sum / size_a;
  return average;
}

void loop() {
  // put your main code here, to run repeatedly:
  int sum = 0;
  for(int i=0;i<16;i++){
    analogValue[i] = analogRead(analogPin);
      delay(50);
    sum +=analogValue[i];
  }
  double average = mean(sum, size_a);
  Serial.print("Avg:");
  Serial.println(average);
}