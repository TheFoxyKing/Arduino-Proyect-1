
// definicion del pines de arduino de driver L298N
int in1 = 10;  
int in2 = 9;  
int in3 = 8;
int in4 = 7;

// definicion de pines de control de velocidad de driver L298N
int EnA = 11; 
int EnB = 6;

// sensores infrarrojo  
int infraPinDerecha = 5;
int infraPinCentro = 4;
int infraPinIzquierda = 3;

// Valores de deteccion 0 - negativo 1 - positivo
int valorInfra = 0;
int valorInfral = 0;
int valorInfrall = 0;
void setup ()  {
  Serial.begin(9600);

  delay(1000);

 // entradas de sensores infra

 pinMode(infraPinDerecha, INPUT);
 pinMode(infraPinCentro, INPUT);
 pinMode(infraPinIzquierda, INPUT);
 
 // entradas ENA del driver L298N
  pinMode(EnB, OUTPUT);
  pinMode(EnA, OUTPUT);
 // entradas IN del drivers L298N
  pinMode(in1, OUTPUT);    
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

 //configuracion de velocidad (150/255)
 digitalWrite(EnA, 70);
 digitalWrite(EnB, 70);

 //configurar sentido de ruedas
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);


  
}
void loop() {
  // leemos  el valor de los sensores : 0 - fondo claro, 1 - fondo negro
  valorInfra = digitalRead(infraPinDerecha);
  valorInfral = digitalRead(infraPinCentro);
  valorInfrall = digitalRead(infraPinIzquierda);

  Serial.println(valorInfra);
  Serial.println(valorInfral);
  Serial.println(valorInfrall);

  //8 escenarios de frente
    if(valorInfra == 0 && valorInfral == 1 && valorInfrall == 0){
      //Linea negra en el centro

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

    }

    if(valorInfra == 1 && valorInfral == 1 && valorInfrall == 1){
      //meta llegada

      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

    }

    if(valorInfra == 0 && valorInfral == 0 && valorInfrall == 0){
      //nada de frente
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

    }

    if(valorInfra == 1 && valorInfral == 0 && valorInfrall == 0){
      //desvio a la derecha
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(182);

    }

    if(valorInfra == 0 && valorInfral == 0 && valorInfrall == 1){
      //desvio a la izquierda 

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(182);
    }

    if(valorInfra == 1 && valorInfral == 0 && valorInfrall == 1){
      // lA VERDAD NOSE QUE HACER AQUI
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
  
    
  }

    //if(valorInfra == 0 && valorInfral == 0 && valorInfrall == 1){
    //  digitalWrite(in1, LOW);
   //   digitalWrite(in2, LOW);
    //  digitalWrite(in3, LOW);
    //  digitalWrite(in4, LOW);
      
    
    //}

  //  if(valorInfra == 1 && valorInfral == 0 && valorInfrall == 0){
     // digitalWrite(in1, LOW);
    //  digitalWrite(in2, LOW);
    //  digitalWrite(in3, LOW);
    //  digitalWrite(in4, LOW);
    //}

    

    