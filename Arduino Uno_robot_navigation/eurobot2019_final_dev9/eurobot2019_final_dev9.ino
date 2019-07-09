//Robot Development Master Thesis 
// Aurthor: Fahad Bin Emran
//Date: 09-07-2019
// Description: Classifying atoms mission of Eurobot2019 
// Starting point of the Robot is within greenium periodic table 
// This program waits for the signal coming from Pi through I2C bus communication
//According to the message value, robot makes its movement
//There are in total three algorithms in this program following six scenarios 
//Depending on the scenario we need to comment out the part and upload the code to the Arduino 


// Include the Servo library
#include <Servo.h>
#include <Wire.h>
// Declare the Servo pin
int servoPin1 = 2;
int servoPin2 = 3;
int servoPin3 = 4;
int servoPin4 = 5;
// Create a servo object
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

int i;
int err = 1;
int err1 = 1;
int err2 = 1;
int err3 = 1;

int s = 1; //loop control servo
int s1 = 1; 
int s2 = 1;
int s3 = 1;

int lg = 1;//loop control for greenium
int lg1 = 1;
int lg2 = 1;

int lr = 1;
int lgb = 1;
int lgr = 1;
int lgbr = 1;


int lb = 1;
int lk = 1;

int lre = 1;
int lrb = 1;
int ld = 1;

bool flag0 = true;
bool flag = true;
bool flag1 = true;

bool flag2 = true;
bool flag3 = true;
bool flag4 = true;

bool flag5 = true;
bool flag6 = true;
bool flag7 = true;
bool flag8 = true;

bool flag9 = true;
bool flag10 = true;
bool flag11 = true;
bool flag12 = true;


#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;


// Motor A

int enA = 6;
int in1 = 7;
int in2 = 8;

// Motor B

int in3 = 9;
int in4 = 10;
int enB = 11;

void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Servo4.attach(servoPin4);
  
  
  Serial.begin(9600); // start serial for output
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
Wire.onReceive(receiveData);
//Wire.onRequest(sendData);

Serial.println("Ready!");


  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}
void loop() {


// Algorithm 1 starts here for scenario BGR & BRG
/*
if(number == 1 && flag0 == true){ //infront is blueium

  if (lb == 1){
  step1_5();
  
  }
}
if (lb == 2){
  

  rotateleft3_90();//backward added
  
  
  }

  if(lb == 3){ 
    
    step2_5(); 
    
    
    }

if (lb == 4){
  
  //rotateright40;
  rotate_right40(); // lk added 
  
  }
if(lb == 5 && number == 2 && flag == true){ //greenium
//if (lb == ){
  
  step1_6();
  //flag = false;
}

if(lb == 6 ){
  
  rotate3_180();//forward 2 sec added
  }
if(lb == 7){
  //forwrd
  //step2;
  backward2sec2();
  
  }  
  if(lb == 8)
  {
    step2_6();
    
    }


    if (lb == 9){
      
      //rotate left 40
      rotateleft40();
      
     
      }
  //if the infront atom is redium
      //if (lb == 10 && number == 3){
    //    if (lb == 10 && number == 3 && flag5 == true){
       if (lb == 10){
        //step 1
        step1_7();
        
        }
  if (lb == 11){
    
    //right 40 
    rotateright2_40();
    
    }

    if (lb == 12){
      
      // step2 
      step2_7();
      
      }


if (lk == 2 && number == 3 && flag1 == true){ // redium is infront of blueium periodic table

//if (lk == 2){

step1_8();
//flag1 = false;
}

if (lk == 3){
  
  rotate4_180();
  
  }

  if (lk == 4) {


    step2_8();
   
    
    
    }
    if (lk == 5){
      
      
      backwardleft();
      }

     // if (lk == 6 && number == 2 && flag6 == true){ //greenium is infront of blueium periodic table

      if (lk == 6 ){
        
        step1_9();
        }

        if (lk == 7){
          
          backwardright();
          
           }

           if (lk == 8){
            
            
            step2_8();// step2_8() same
            
            }

  */

//  Algorithm 1 ends here for scenario BGR & BRG
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  Algorithm 2 starts here for scenario GBR & GRB

if (number == 2 && flag2 == true){ //infront is greenium


if (lg==1){ // infront is greenium

step1();

}
}
if (lg==2){
  if(lg1==1){
  forward2sec1();
  }
if (lg1==2){
  rotate180();
  forward2sec2();
 }

  }
if (lg==3){
    step2();
    }

if (lg==4)
{
  
  backward_right(); // backward 2 sec added 
  //delay(4000);
  }


  if (lgb == 2 && number == 1 && flag3 == true ){ // if infront is blueium
    
  if (err == 1){  
  step1_1(); //forward 2 sec added, in the middle and at the end
  }
}

if (lgb== 3){ 
 
    rotateleft90();
   
  }

  if (lgb == 4){
    step2_1();
    
    }

  if (lgb == 5){
    //rotate left 90
    rotateleft2_90();
    
    
    }
     if (lgb == 6) {
      
      forward2sec3();
      }
     
    //if (lgb == 7 && number == 3 && flag7 == true){ //infront is redium
      if (lgb == 7){
      if(err1 == 1)
      {
        step1_3();
      }
      
      }
      if (lgb == 8){

        rotateright90();
       
        }
      if (lgb == 9) {
        
        step2_2();
        
        } 
        

if (lgr == 2 && number == 3 && flag4 == true){ //if the atom is redium
    

   if(err2 == 1){ 
  step11_1(); //forward 2 sec added, in the middle and at the end
}
  }

if (lgr== 3){ 
 
    rotateleft140(); // forward move added
   
  }

  if (lr == 2){
    step2_3();
    }

  if (lr == 3){
   //back and rotate left 40
   backrotate40(); //backward added then rotate
  
 
    }

    
     //if (lr == 4 && number == 1 && flag8 == true) { // infront is blueium
      if (lr == 4){
      if (err3 == 1){
   step1_4();
      }
     }
    if (lr == 5){
     rotate2_180();
      
      }
        
      if (lr == 6){

       step2_4();
       
        }
//  Algorithm 2 ends here for scenario GBR & GRB
/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////// 


//  Algorithm 3 starts here for scenario RGB & RBG


if (number == 3 && flag9 == true){ //Redium is infront of the greenium periodic table 

if (ld == 1){
  
  step1_10();
  
  }
}
  if (ld == 2){
  
    rotateright_90();
    }

if (ld == 3){
  
  step2_9();
  //break;
  
  
  }
  
if (ld == 4){
  
  rotate_left40(); //added loop for ld and lrb

  }



if (ld == 5 && number == 2 && flag10 == true ){ // if greenium infront of redium periodic table

 
  step1_11();
  
  }

if (ld == 6){
  
  
  rotate5_180();//forward added backward added
  
  }
if (ld == 7){
  
  step2_11(); 
  
  }

if (ld == 8){
  
  rotateright3_40();
  
  
  }

if (ld == 9){
  
    step1_13(); 
  }
  if (ld == 10){
    
    
    left40();//forward added
    
    
    }
    if (ld == 11){
        step2_12(); 
      }
 

if (lrb == 2 && number == 1 && flag11 == true){ //if blueium

 step1_12();

}
if (lrb == 3){
  
  
 rotate6_180();
  
  }

  if (lrb == 4){
    
    step2_10();
    
    }

if (lrb == 5){
  
  rotateright4_40(); //backward added
  
  }

  if (lrb == 6){
    
      step1_14(); 
    
    }

    if (lrb == 7){
      
      rotate7_180();

      
      
      }
      if (lrb == 8){
        
        
         step2_13(); 
        
        }
    
//  Algorithm 3 ends here for scenario RGB & RBG
*/
}


// callback for received data
void receiveData(int byteCount){

while(Wire.available()) {
number = Wire.read();
//delay(20000);
Serial.print("data received: ");
Serial.println(number);


 
}
}
/*
// callback for sending data
void sendData(){
Wire.write(number);
}
*/
////////##################################################################/////// 1st phase
void step1(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,90,115
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lg++;
 flag2 = false;
}
}


void step2(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 100 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lg++;

}
}


void step1_5(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lb++;
 flag0 = false;
}
}


void step2_5(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lb++;

}
}

void step1_10(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,90
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 ld++;
 lre++;
 flag9 = false;
}
}


////////##################################################################/////// 2nd phase



void step1_1(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 //forward2sec(); 
 // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (1500); //1500


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lgb++; // bluieum on hand loop control
 
  flag3 = false;
  err++;
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (2400); //2000


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
}


void step11_1(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 //forward2sec(); 
 // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (1500); //1500


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lgr++; //redium on hand loop control

 flag4 = false;
 err2++;
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (2400); //2000


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
}
void step2_1(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lgb++;

}
}
void step1_6(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lb++;
 flag = false;
}
}



void step2_6(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lb++;

}
}

void step1_8(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lk++;
 flag1 = false;
}
}


void step2_8(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lk++;

}
}

void step2_9(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 ld++;

}
}


void step1_11(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 ld++;
 flag10 = false;
}
}

void step1_13(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 ld++;
}
}

void step1_12(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lrb++;
 flag11 = false;
}
}

void step1_14(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lrb++;
}
}


void step2_10(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lrb++;

}
}

void step2_13(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(200); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(100);//100
}

 s1 = 1;
 lrb++;

}
}


void step2_11(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 ld++;

}
}

void step2_12(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 ld++;

}
}

////////##################################################################/////// 3rd phase

void step1_3(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lgb++;
 flag7 = false;
 err1++;
}
}


void step2_2(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lgb++;

}
}

void step2_3(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lr++;

}
}


void step1_4(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lr++;
 flag8 = false;
 err3++;
 
}
}

void step2_4(){

lr = 10; 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 

}
}


void step1_7(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(700);//1000
 

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);//180
  


 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lb++;
 flag5 = false;
 
}
}



void step2_7(){

 
if (s1 == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(50); //200
}
 s1++;
}

else if (s1 == 2){
for ( i = 110; i <= 150 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(50);//100
}
s1++;
//Servo4.write(0);
}
else if (s1 == 3){
  
 for ( i = 100; i > 0 ; i-= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s1++;
}

else if (s1 == 4){
for ( i = 30; i >= 0 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(20); //200
}
for ( i = 150; i >= 90 ; i-= 1 ){  //150,50
  Servo1.write(i);
  delay(10);//100
}

 s1 = 1;
 lb++;

}
}


void step1_9(){

//int s = 1;  
if (s == 1){
for ( i = 10; i <= 30 ; i+= 1 ){ 
  Servo2.write(i);
  delay(20); //200
}
 s++;
}

else if (s == 2){
for ( i = 90; i <= 155 ; i+= 1 ){ //50,150
  Servo1.write(i);
  delay(10);//100
}
s++;
Servo4.write(0);
}
else if (s == 3){

 forward2sec(); 
  
 for ( i = 0; i < 100 ; i+= 1 ){ 
  Servo4.write(i);
  delay(35);//30

}
s++;
}

else if (s == 4){
for ( i = 30; i >= 15 ; i-= 1 ){ //30,10
  Servo2.write(i);
  delay(300); //200
}
for ( i = 150; i >= 105 ; i-= 1 ){ //150,50
  Servo1.write(i);
  delay(250);//100
}

 s = 1;
 lk++;
 flag6 = false;
}
}




//==========================================================
void forward()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 215);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 215);
}

void forward2sec()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 215);//200

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 215);//200

  delay (600);//600


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);


}


void forward2sec1()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 215);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 215);

  delay (3200); //2000


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  lg1++;
}


void forward2sec2()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (2100); //1500


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  lg++;
}
void forward2sec3()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (1000); //1500,1800,1200


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  lgb++;
}


void backward2sec2()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 150);

  // Turn on motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 150);

  delay (500); //300


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  lb++;
}






void right()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 215);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215);


}

void rotate180()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(2750);//2850,2650,2600,3200

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lg1++;

}



void rotate6_180()
{
 
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(2600);//2850,2650,2600,3200,2800

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lrb++;
}



void rotate7_180()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(700);

  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(2300);//2850,2500,2200,2300
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lrb++;

}


void rotate5_180()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1800);
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(2900);//2850,2650,2600,3800,2800
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  ld++;

}
void rotateleft90()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(1000);//1200

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lgb++;


}

void rotateleft40()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(680);//800,1200

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lb++;

}

void left40()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1800);//800,1200,1400
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(1400);//800,1200




 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  ld++;

}



void rotate2_180()
{
 digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(3500);//2850,2650,2600

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lr++;


}



void rotate3_180()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1500);//1000
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(2800);//2850,2650,2600,2700

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lb++;
}




void rotate4_180()
{

   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1500);//1000
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(3000);//2850,2650,2600




  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1200);//1000
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lk++;
}


void rotateleft3_90()
{
 digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(1600);//1000,1600

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);


  delay(300);//300


  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lb++; // for blueium loop control



}



void rotateright_90()
{
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1600);//1000,1600

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);


  delay(300);//300


  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  ld++;



}

void backrotate40()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(600);//1200

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);


    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 

  delay(730);//1000,700,800

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lr++;

}



void rotateleft140()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(1950);//2000,1700,1900


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(1200);//300,1200
  

  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lgr++;
  lr++;

}
void rotateleft2_90()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(1220);//1200,1500,1300

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lgb++;


}


void rotateright90()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(700);//1000

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lgb++;

}


void rotateright40()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(700);//1000

 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lb++;

}



void rotateright4_40()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(820);//1000,700


  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(300);//1000,700

  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lrb++;

}

void rotateright3_40()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(700);//700,730,680,550



   
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(900);//700
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  ld++;

}


void rotateright2_40()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(700);//1000

  

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(300);//1000

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);//180

  
  lb++;

}



void left()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 215);  
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215);

}

void stop(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  
  }

void backward() 
{
  
  stop();
  delay(1000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 215);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215);
  
 
  delay(2150);
  
  }


void backward_right()
{
  
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 analogWrite(enA, 215);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215); 
  delay(550); //600,700

   digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(800); //1400,1100,800

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(900); //600 is little less

  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

 lg++;
 lgr++;
 lgb++;
   
  }



void rotate_right40()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(820);//1200,950,700



  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(300);//1200,950
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

  lb++;// for blueium
  lk++; // for redium

}


void rotate_left40()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(925);//950,1010,930


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);

    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 220);//180

  delay(200);//950,300
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  

 lrb++;
 ld++;

}


void backwardleft(){
  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(950);//1200


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(450); //500,


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(350);//200


  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);



  
  lk++;
  }


  void backwardright(){
  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220);//180

  delay(950);//1200


  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(1000); //1400,1100,800

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  lk++;
  }
  
