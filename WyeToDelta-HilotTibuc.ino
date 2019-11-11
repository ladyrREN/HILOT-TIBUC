int Vin = 5;                //mao ni ang volts 
int raw1 = 0;               //mabasa nga wrong number sa arduino
int raw2 = 0;
int raw3 = 0;

float Vout1 = 0;            // ang volts tinuod nga nabasa
float Vout2 = 0;
float Vout3 = 0;

float R0 = 180;              // known resistor
float R1 = 0;
float R2 = 0;
float R3 = 0;

float R12 = 0;              //delta2
float R13 = 0;
float R23 = 0;
float numerator;

void setup() {
Serial.begin( 9600 );
}

void loop() {
raw1 = analogRead( A0 );
raw2 = analogRead( A1 );
raw3 = analogRead( A2 );

Vout1 = ( raw1*Vin )/1024.0;
Vout2 = ( raw2*Vin )/1024.0;
Vout3 = ( raw3*Vin )/1024.0;

R1 = R0 * ( ( Vout2/Vout1 ) - 1 );
R2 = R0 * ( ( Vout3/Vout1 ) - 1 ) - R1;
R3 = R0 * ( ( Vin/Vout1 ) - 1 ) - R1 - R2;

numerator = ( R1*R2 ) + ( R1*R3 ) + ( R2*R3 );

R12 = numerator/R3;
R13 = numerator/R2;
R23 = numerator/R1;

Serial.println();
Serial.println();
Serial.println();
Serial.println();
Serial.println();

Serial.print( "R1 = " );
Serial.println( R1 );
Serial.print( "R2 = " );
Serial.println( R2 );
Serial.print( "R3 = " );
Serial.println( R3 );

Serial.println();
Serial.print( "R12 = " );
Serial.println( R12 );
Serial.print( "R13 = " );
Serial.println( R13 );
Serial.print( "R23 = " );
Serial.println( R23 );

}
