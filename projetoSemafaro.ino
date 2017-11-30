int pinVermelho = 10;
int pinAmarelo = 9;
int pinVerde = 8;
int pinBotao = 7;
int pinPedestreVermelho = 3;
int pinPedestreVerde = 2;

int faseSemafaro;
int estadoBotao;
int estadoAnteriorBotao;
int tempoPisca;
int estadoPisca;

void setup() {
  // put your setup code here, to run once:

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT):
  pinMode(pinVermelho, OUTPUT):
  pinMode(pinBotao, INPUT);
  pinMode(pinPedestreVerde, OUTPUT);
  pinMode(pinPedestreVermelho, OUTPUT);

  faseSemafaro = 1;

  estadoAnteriorBotao = digitalRead(pinBotao);

  tempoPisca = 0;
  estadoPisca = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:

  estadoBotao = digitalRead(pinBotao);

  if ((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)) {

    if(faseSemafaro < 3) {
    faseSemafaro = faseSemafaro ++;
  } else {
    faseSemafaro = 1;
  }

  estadoAnteriorBotao = estadoBotao;
  
  if (faseSemafaro == 1) {   //SEMAFARO SIGA (VERDE)
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW):

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH):
  }

  if (faseSemafaro == 2) {   //SEMAFARO ATENCAO (AMARELO)
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
  }

  if (faseSemafaro == 3) {   //SEMAFARO PARE (VERMELHO)
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH):

    digitalWrite(pinPedestreVerde, HIGH);
    digitalWrite(pinPedestreVermelho, LOW);
  }

if (faseSemafaro == 4) {   //SEMAFARO PEDESTRE PISCANDO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH):

    tempoPisca = tempoPisca + 1;
    if (tempoPisca == 400) {
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    
    }

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, estadoPisca);

  delay(100);
}
