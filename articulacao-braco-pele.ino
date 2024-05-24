 #include <Servo.h>
int potenciometromodo = 1;
int potenciometro1 = 1;
int potenciometro2 = 1;
int potenciometro3 = 1;



Servo servo1, servo2, servo3, garra;

void setup()
{
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  servo1.attach(4);
  servo3.attach(7);
  servo2.attach(10);
  garra.attach(11);
  Serial.begin(9600);
}

void loop() {

  potenciometromodo = analogRead(A0);
  potenciometro1 = analogRead(A5);
  potenciometro2 = analogRead(A4);
  potenciometro3 = analogRead(A3);
  

  if (potenciometromodo < 341) {
    Serial.print("desligado");
    Serial.println(potenciometromodo);
    digitalWrite(13, LOW);

    digitalWrite(6, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);


   
  } else if (potenciometromodo < 682) {

    digitalWrite(6, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);

  digitalWrite(13, HIGH);

  if (digitalRead(12) == HIGH) {
  garra.write(0);
  Serial.print("..........garra: ");
  
  Serial.print("aberta");
    digitalWrite(6, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
  
  } else{
    Serial.print("..........garra: ");
    Serial.print("fechada");
    garra.write(40);
  }




  //..............................................................................................

  servo1.write(map(potenciometro1, 0, 1023, 0, 180));
  Serial.print("..........servo1: ");
  Serial.print(potenciometro1);
  Serial.print("_____");
  Serial.print(map(potenciometro1, 0, 1023, 0, 180));
  

 // .............................................SERVO1(gira a base)..........................................


  servo2.write(map(potenciometro2, 0, 1023, 10, 80));
  Serial.print("..........servo2: ");
  Serial.print(potenciometro2);
  Serial.print("_____");
  Serial.print(map(potenciometro2, 0, 1023, 10, 80));
  
  // .............................................SERVO2(estica o braço verticalmente)..........................................

  servo3.write(map(potenciometro3, 0, 1023, 0, 100));
  Serial.print("..........servo3: ");
  Serial.print(potenciometro3);
  Serial.print("_____");
  Serial.println(map(potenciometro3, 0, 1023, 0, 100));

  delay(500);
  
  }

     //.............................................SERVO3(estica o braço horizontalmente)..........................................


  else {
    
    digitalWrite(6, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    
    digitalWrite(13, HIGH);
    Serial.print("automático:");
    Serial.println(potenciometromodo);

    servo1.write(random(0, 180 + 1));
    delay(1000);
    servo2.write(random(10, 80 + 1));
    delay(1000);
    servo3.write(random(0, 100 + 1));
    delay(1000);
  }
  }
