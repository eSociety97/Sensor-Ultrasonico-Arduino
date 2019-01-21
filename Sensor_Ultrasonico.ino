/*********************************************Capitulo 5 - Sensor Ultrasonico******************************************************
*                                                                                                                                 *
*     En este quinto capitulo aprenderemos a hacer a utilizar el sensor Ultrasonico el cual es un dispositivo capaz de            *
*  medir distancia por medio de ultrasonidos. Distancia = velocidad * tiempo. La velocidad del sonido la conocemos que es         *
*  1/29 cm/us, pero el tiempo lo conseguiremos a travez de los pines Trigger y Echo. Con tan solo 10 microsegundos en alto        *                                                                       *
*  el pin de disparo Trigger emite un sonido, Arduino almacenara el tiempo que tarde el sonido en regresar al pin Echo y asi      *                                                                       *
*  obtener la distancia de los objetos.                                                                                           *                                                                       *
*                                                                                                                                 *
*  Para lograr esto necesitaremos:                                                                                                *
*                                                                                                                                 *
*  -Placa arduino Uno                                                                                                             *
*  -1 Sensor Ultrasonico                                                                                                          *
*  -1 Buzzer o Bocina                                                                                                             *
*  -Protoboard                                                                                                                    *
*                                                                                                                                 *
*                                                                                                                                 *
*                                                                                                                                 *
*                                                                                                              Facebook: ESociety *
*                                                                                                              GitHub: eSociety97 *
*                                                                                                                                 *
*                                                         #NuncaDejenDeCrear                                                      *
***********************************************************************************************************************************/   

int Echo = 6;  //Declaramos la variable que usaremos para el pin Echo
int Trig = 7; //Declaramos la variable que usaremos para el pin Trig
int bocina = 2; //Declaramos la variable que usaremos para el buzzer
int tiempo; // Variable que almacenara el tiempo de respuesta del Echo
int distancia; //Variable que almacenara la conversion del tiempo en distancia
int potenciometro = 0; //Variable que almacenara el valor de nuestra entrada analoga

void setup(){
  Serial.begin(9600);    //Iniciamos la comunicacion Serial 
  pinMode(bocina,OUTPUT); //Declaramos como pin de salida la variable alarma
  pinMode(Echo, INPUT);  //Declaramos el pin Echo como entrada
  pinMode(Trig,OUTPUT); //Declaramos el pin Trig como salida
  }
void loop(){    
  digitalWrite(Trig,LOW);  //Mantenemos en estado bajo el Trig
  delayMicroseconds(2);    //Damos una pausa de 2 microsegundos
  digitalWrite(Trig,HIGH);  //Mandamos el estado alto de Trig 
  delayMicroseconds(10);   //Por 10 microsegundos
  digitalWrite(Trig,LOW);  //Apagamos el pin de Disparo

  tiempo = pulseIn(Echo,HIGH); //Almacenara el tiempo que tardo en pasar de estado Alto a Bajo
  distancia = (tiempo/2)/29;  //Formula para convertir el tiempo en distancia 
 
  if(distancia >= 500 || distancia <= 0){  //Comparamos si Distancia es mayor o igual a 500 o distancia es menor o igual a 0
    Serial.println("Fuera de rango");
   }//Lo cual estaria fuera de rango    
   else{ //De lo contrario
    Serial.print(distancia);  //Imprima el valor de distancia
    Serial.println(" CM");   //Concatene CM al final del valor de distancia   
    delay(500); 
    }   
  if(distancia <= 20){//Si distancia es menos o igual a 10 y distancia es mayor o igual a 2      
     alarma();
      Serial.println("Alarma");  //Imprimir un mensaje 
  }
}
//Funcion que activara el buzzer o Bocina 
void alarma(){     
  tone(2,300,300); //Mandara una frecuencia 300 con una amplitud de 300 por el pin 2
  delay(100);      //dejara un tiempo de 100 milisegundos
  tone(2,200,200); //Mandara una frecuencia de 200 con una amplitud de 200 por el pin 2 
  delay(100);    //Dejara un tiempo de 100 milisegundos
      }
