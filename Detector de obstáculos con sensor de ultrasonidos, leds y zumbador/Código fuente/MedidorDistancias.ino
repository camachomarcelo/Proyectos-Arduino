// Proyecto "Medidor de distancias con Arduino, leds y parlante/zumbador"
// Materia: Ensamblador
// Semestre II - 2014


// Definimos los pines que vamos a usar

#define trigPin 7 //Pin al que va conectado el "Trig" del sensor de ultrasonidos
#define echoPin 6 //Pin al que va conectado el "Echo" del sensor de ultrasonidos
#define led 13 //Led 1 verde conectado al Pin 13
#define led2 12 //Led 2 Verde conectado al Pin 12
#define led3 11 //Led 3 Amarillo conectado al Pin 11
#define led4 10 //Led 4 Amarillo conectado al Pin 10
#define led5 9 //Led 5 Rojo conectado al Pin 9
#define led6 8 //Led 6 Rojo conectado al Pin 8
#define buzzer 3 // Pin del parlante

int sound = 250; // Establecemos el volumen del sonido del parlante/zumbador


void setup() {
// Inicialimos el Serial, sensor de ultrasonidos, leds y parlante (zumbador)
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Disparo de sensor del ultrasonido.
  pinMode(echoPin, INPUT); //Recepcion de sensor del ultrasonido.
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 30)  //Si la distancia es <=30 cm
    digitalWrite(led, HIGH); //se enciende el primer led (verde)
    sound = 250; //el sonido inicializa en 250
}
  else {
    digitalWrite(led,LOW);
  }
  if (distance < 25) { //Si la distancia es <25 cm
      digitalWrite(led2, HIGH); //se enciende el segundo led (verde)
      sound = 260; //el sonido aumenta en 260
}
  else {
      digitalWrite(led2, LOW); //caso contrario se apaga el led 2 (verde)
  }
  if (distance < 20) {
      digitalWrite(led3, HIGH);
      sound = 270;
} 
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 15) {
    digitalWrite(led4, HIGH);
    sound = 280;
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 10) {
    digitalWrite(led5, HIGH);
    sound = 290;
}
  else {
    digitalWrite(led5,LOW);
  }
  if (distance < 5) {
    digitalWrite(led6, HIGH);
    sound = 300;
}
  else {
    digitalWrite(led6,LOW);
  }
 
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
   
  }
  delay(500);
}