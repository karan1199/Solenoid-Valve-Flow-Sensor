int SensorPin = 2;    
volatile int count;  
double flowRate;  
int SolenoidValve = 3; 
int InterruptNo = 0; 
int PB_1 = 5;
int PB_2 = 6;
int PB_3 = 7;
int PB_4 = 8;
//NOTE : 1 pulse = 2.25 ml therefore 70/2.25 gives no of pulse counts
int PB_1_count = 31; // 70ml 
int PB_2_count = 40; // 90ml
int PB_3_count = 71; // 160ml
int PB_4_count = 88; // 200ml

void setup() {
  
  Serial.begin(9600);   
  pinMode(SensorPin, INPUT);
  pinMode(PB_1, INPUT);
  pinMode(PB_2, INPUT);
  pinMode(PB_3, INPUT);
  pinMode(PB_4, INPUT);
  pinMode(SolenoidValve,OUTPUT);          
  attachInterrupt(InterruptNo ,pulsecounter , RISING);  

}
void pulsecounter()
{
   count++;
}
void loop() 
{
 
  count = 0;      
  if (PB_1 == HIGH)
  {
     attachInterrupt(InterruptNo ,pulsecounter , RISING);
     digitalWrite(SolenoidValve,HIGH);
     while (count < PB_1_count);
     detachInterrupt(InterruptNo);
     digitalWrite(SolenoidValve,LOW);
     
  }
  if (PB_2 == HIGH)
  {
     attachInterrupt(InterruptNo ,pulsecounter , RISING);
     digitalWrite(SolenoidValve,HIGH);
     while (count < PB_2_count);
     detachInterrupt(InterruptNo);
     digitalWrite(SolenoidValve,LOW);
     
  }
  if (PB_3 == HIGH)
  {
     attachInterrupt(InterruptNo ,pulsecounter , RISING);
     digitalWrite(SolenoidValve,HIGH);
     while (count < PB_3_count);
     detachInterrupt(InterruptNo);
     digitalWrite(SolenoidValve,LOW);
     
  }
  if (PB_4 == HIGH)
  {
     attachInterrupt(InterruptNo ,pulsecounter , RISING);
     digitalWrite(SolenoidValve,HIGH);
     while (count < PB_4_count);
     detachInterrupt(InterruptNo);
     digitalWrite(SolenoidValve,LOW);
  }

}
 
