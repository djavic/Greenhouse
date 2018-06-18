/*
 * Programa de atomatizacion de un invernadero de tamaño pequeño en relacion a controlar temperatura y humedad
 * 
 * @author djavic96
 * @version 0.5
 */
#include  <LiquidCrystal.h>

// CONSTRUCTOR PARA LA PANTALLA LCD 16X2
// AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Variables umbrales

float tempUmbral = 25.0;
float humUmbral = 0;

//////////////////////

const int ledRojo = 6;
const int ledVerde = 7;

float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinTemp = 0; // Variable del pin de entrada del sensor (A0)

void setup(){

  Serial.begin(9600);//iniciamos la consola
  
  lcd.begin(16, 2);//Iniciamos la pantalla de 16x32

  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
 
  lcd.home();//Movemos el cursor al inicio
  lcd.print("Bienvenido");
  
  lcd.setCursor ( 0, 1 );//Movemos el cursor a esa posicion e imprimimos
  lcd.print("Encendiendo...");
  
  delay(1000);
  lcd.noDisplay();//Limpiamos la pantalla para comenzar el programa
  lcd.display();
 
}

void loop(){

  tempC = analogRead(pinTemp);//Leemos la entrada del sendor de temperatura

  tempC = (1.1 * tempC * 100.0)/1024.0;  //Con esta formula calculamos la temperatura en Cº

  Serial.print(tempC);//Imprimimos la temperatura en la consola
  Serial.print("\n");

   

 lcd.home();
 lcd.print("TEMPERATURA=");//Imprimos la temperatura en la pantalla
 lcd.print(tempC);

 if(tempC > tempUmbral){
  lcd.setCursor(0, 1);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
  lcd.print("VENTANA ON");

  //PONER ACCIONES PARA ABRIR VENTANA
  
 }else{
  lcd.setCursor(0, 1);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,HIGH);
  lcd.print("VENTANA OFF");

  //PONER ACCIONES PARA CERRAR VENTANA CON MOTOR
 }

 //CONDICIONES DE TEMPERATURA Y DE ENCENDIDO DE ASPERSORES

  delay(1000);//Tiempo de reposo antes de cada comprobacion

  
 
}
