/*
-----___----------------------
|   |   |   |     |  B C D   |
|   |---|   |     |    A     |
|   |___| · |     |  H G F E |
------------------------------


*/
const byte L1 = 9;
const byte L2 = 8;
const byte L3 = 7;
const byte L4 = 6;
const byte R1 = 5;
const byte R2 = 4;
const byte R3 = 3;
const byte R4 = 2;
const byte SA = 10;
const byte SB = 11;
const byte SC = 12;
const byte SDD = 13;
const byte SEE = A0;
const byte DOT = A0;
const byte SF = A1;
const byte SG = A2;
const byte SH = A3;
int value = 0;
int var_temp = 0;
int var_hum = 0;
int dot_temppos = 0;
int dot_humpos = 0;
int delaydisplay=1000;
int loop_state;
int loop_cont;
int val_L1;
int val_L2;
int val_L3;
int val_L4;
int val_R1;
int val_R2;
int val_R3;
int val_R4;



//INICIO DE SUB-RUTINAS
void setup_config();
  // Numeros
void print_N00();
void print_N01();
void print_N02();
void print_N03();
void print_N04();
void print_N05();
void print_N06();
void print_N07();
void print_N08();
void print_N09();
void print_null();


  // Letras
void print_A();
void print_B();
void print_C();
void print_D();
void print_E();
void print_F();
void print_G();
void print_H();
void print_I();
void print_J();
//void print_K();
void print_L();
void print_LL();
//void print_M();
void print_N();
//void print_Ñ();
void print_P();
void print_Q();
void print_R();
void print_S();
void print_T();
void print_U();
//void print_V();
//void print_W();
//void print_X();
void print_Y();
void print_Z();

void contador();
void all_low();
void print_test();
void print_msg01();
void print_value();
void print_var();



//SETUP
void setup() {
  setup_config();
  delaydisplay = 1000;
  var_temp = 0;
  var_hum = 0;
  dot_temppos = 0; // Posicion de la coma decimal: 0-(SIN);1;2;3
  dot_humpos = 0;  // Posicion de la coma decimal: 0-(SIN);1;2;3
  loop_cont=0;
  loop_state=0;

  all_low();
  digitalWrite(DOT, LOW);
  
  //print_test();
  //all_low();
};

void loop() {
  val_L1=var_temp/1/1000;
  val_L2=(var_temp/1%1000)/100;
  val_L3=((var_temp/1%1000)%100)/10;
  val_L4=((var_temp/1%1000)%100)%10;
  
  val_R1=var_hum/1/1000;
  val_R2=(var_hum/1%1000)/100;
  val_R3=((var_hum/1%1000)%100)/10;
  val_R4=((var_hum/1%1000)%100)%10;

  if (loop_state==0) print_msg01();
  else if (loop_state==1){
    all_low();
    print_value();
    }
  else {
  contador();
  all_low();
  print_value();
  }
  

       

};

/////////////////////////////////////////

//SUB-RUTINAS
  //CONFIGURACION
void setup_config(){
  pinMode(L1, OUTPUT); //L1
  pinMode(L2, OUTPUT); //L2
  pinMode(L3, OUTPUT); //L3
  pinMode(L4, OUTPUT); //L4
  
  pinMode(R1, OUTPUT); //R1
  pinMode(R2, OUTPUT); //R2
  pinMode(R3, OUTPUT); //R3
  pinMode(R4, OUTPUT); //R4
  
  pinMode(SA, OUTPUT); //A
  pinMode(SB, OUTPUT); //B
  pinMode(SC, OUTPUT);//C
  pinMode(SDD, OUTPUT);//D
  pinMode(SEE, OUTPUT);//E
  pinMode(SF, OUTPUT);//F
  pinMode(SG, OUTPUT);//G
  pinMode(SH, OUTPUT);//H
}
   //APAGADO TOTAL
void all_low(){
  digitalWrite(L1, LOW);  //L1
  digitalWrite(L2, LOW);  //L1
  digitalWrite(L3, LOW);  //L1
  digitalWrite(L4, LOW);  //L1
  digitalWrite(R1, LOW);  //L1
  digitalWrite(R2, LOW);  //L1
  digitalWrite(R3, LOW);  //L1
  digitalWrite(R4, LOW);  //L1
  digitalWrite(SA, LOW);  //A
  digitalWrite(SB, LOW);  //B
  digitalWrite(SC, LOW); //C
  digitalWrite(SDD, LOW); //D
  digitalWrite(SEE, LOW); //E
  digitalWrite(SF, LOW); //F
  digitalWrite(SG, LOW); //G
  digitalWrite(SH, LOW); //H  
  }
  //CONTADOR
void contador(){
  if (var_temp <= 6000)
    var_temp+=1;
  else
    var_temp = 0;
  if (var_hum <= 6000)
    var_hum+=1;
  else
    var_hum = 0;
}
  //TEST
void print_test(){
  digitalWrite(L1, HIGH);  //L1
  digitalWrite(L2, HIGH);  //L2
  digitalWrite(L3, HIGH);  //L3
  digitalWrite(L4, HIGH);  //L4
  digitalWrite(R1, HIGH);  //R1
  digitalWrite(R2, HIGH);  //R2
  digitalWrite(R3, HIGH);  //R3
  digitalWrite(R4, HIGH);  //R4
  print_A();
  delay(delaydisplay);
  print_B();
  delay(delaydisplay);
  print_C();
  delay(delaydisplay);
  print_D();
  delay(delaydisplay);
  print_E();
  delay(delaydisplay);
  print_F();
  delay(delaydisplay);
  print_G();
  delay(delaydisplay);
  print_H();
  delay(delaydisplay);
  print_I();
  delay(delaydisplay);
  print_J();
  delay(delaydisplay);
  print_null();
  delay(delaydisplay);
  print_L();
  delay(delaydisplay);
  print_LL();
  delay(delaydisplay);
  print_null();
  delay(delaydisplay);
  print_N();
  delay(delaydisplay);
  print_null();
  delay(delaydisplay);
  print_O();
  delay(delaydisplay);
  print_P();
  delay(delaydisplay);
  print_Q();
  delay(delaydisplay);
  print_R();
  delay(delaydisplay);
  print_S();
  delay(delaydisplay);
  print_T();
  delay(delaydisplay);
  print_U();
  delay(delaydisplay);
  print_null();
  delay(delaydisplay);
  print_null();
  delay(delaydisplay);
  print_null();
  delay(delaydisplay);
  print_Y();
  delay(delaydisplay);
  print_Z();
  delay(delaydisplay);
}
  // NUMEROS
void print_N00() {
  print_N08();
  digitalWrite(SA, LOW);  //A
}
void print_N01() {
  print_null();
  digitalWrite(SDD, HIGH); //D
  digitalWrite(SF, HIGH); //F
}
void print_N02() {
  print_N08();
  digitalWrite(SB, LOW);  //B
  digitalWrite(SF, LOW); //F
}
void print_N03() {
  print_N08();
  digitalWrite(SB, LOW);  //B
  digitalWrite(SH, LOW); //H
}
void print_N04() {
  print_N09();
  digitalWrite(SC, LOW); //C
  digitalWrite(SG, LOW); //G
}
void print_N05() {
  print_N06();
  digitalWrite(SH, LOW); //H
}
void print_N06() {
  print_N08();
  digitalWrite(SDD, LOW); //D
}
void print_N07() {
  print_N01();
  digitalWrite(SC, HIGH); //C
}
void print_N08() {
  digitalWrite(SA, HIGH);  //A
  digitalWrite(SB, HIGH);  //B
  digitalWrite(SC, HIGH); //C
  digitalWrite(SDD, HIGH); //D
  //digitalWrite(SEE, LOW); //E
  digitalWrite(SF, HIGH); //F
  digitalWrite(SG, HIGH); //G
  digitalWrite(SH, HIGH); //H
}
void print_N09() {
  print_N08();
  digitalWrite(SH, LOW); //H
}
void print_null() {
  digitalWrite(SA, LOW);  //A
  digitalWrite(SB, LOW);  //B
  digitalWrite(SC, LOW); //C
  digitalWrite(SDD, LOW); //D
  //digitalWrite(SEE, LOW); //E
  digitalWrite(SF, LOW); //F
  digitalWrite(SG, LOW); //G
  digitalWrite(SH, LOW); //H
}

  //LETRAS
void print_A(){
  print_N08();
  digitalWrite(SG, LOW); //G
  }
void print_B() {
  print_N08();
  digitalWrite(SC, LOW); //C
  digitalWrite(SDD, LOW); //D
}
void print_C() {
  print_N00();
  digitalWrite(SDD, LOW); //D
  digitalWrite(SF, LOW); //F
}
void print_D() {
  print_N08();
  digitalWrite(SB, LOW);  //B
  digitalWrite(SC, LOW); //C
}
void print_E() {
  print_N08();
  digitalWrite(SDD, LOW); //D
  digitalWrite(SF, LOW); //F
}
void print_F() {
  print_E();
  digitalWrite(SG, LOW); //G
}
void print_G() {
  print_N06();
  digitalWrite(SA, LOW); //A
}
void print_H(){
  print_A();
  digitalWrite(SC, LOW); //C
}
void print_I(){
  print_null();
  digitalWrite(SB, HIGH);  //B
  digitalWrite(SH, HIGH);  //H
}
void print_J(){
  print_N01();
  digitalWrite(SG, HIGH);  //G
}
void print_L(){
  print_I();
  digitalWrite(SG, HIGH);  //G
}
void print_LL(){
  print_I();
  digitalWrite(SF, HIGH);  //F
  digitalWrite(SDD, HIGH);  //D
}
void print_N(){
  print_O();
  digitalWrite(SG, LOW);  //G
}
void print_O(){
  print_N08();
  digitalWrite(SB, LOW);  //B
  digitalWrite(SC, LOW);  //C
  digitalWrite(SDD, LOW);  //D
}
void print_P(){
  print_N08();
  digitalWrite(SF, LOW);  //F
  digitalWrite(SG, LOW);  //G
}
void print_Q(){
  print_N09();
  digitalWrite(SG, LOW);  //G  
}
void print_R(){
  print_O();
  digitalWrite(SG, LOW);  //G
  digitalWrite(SF, LOW);  //F   
}
void print_S(){
  print_N05();   
}
void print_T(){
  print_I();
  digitalWrite(SA, HIGH);  //A
  digitalWrite(SG, HIGH);  //G
}
void print_U(){
  print_N08();
  digitalWrite(SA, LOW);  //A
  digitalWrite(SC, LOW);  //C
}
void print_Y(){
  print_N08();
  digitalWrite(SH, LOW);  //A
  digitalWrite(SC, LOW);  //C
}
void print_Z(){
  print_N02();
}
  //MENSAJE DE BIENVENIDA
void print_msg01(){
  if (loop_cont == 1000)loop_state=1;
  else{
  loop_cont++;
  print_H();
  digitalWrite(L1, HIGH);  //L1
  if (loop_cont<=125)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_E();
  digitalWrite(L2, HIGH);  //L2
  if (loop_cont>=126&&loop_cont<=250)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_LL();
  digitalWrite(L3, HIGH);  //L3
  if (loop_cont>=251&&loop_cont<=375)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_O();
  digitalWrite(L4, HIGH);  //L4
  if (loop_cont>=376&&loop_cont<=500)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_U();
  digitalWrite(R1, HIGH);  //R1
  if (loop_cont>=501&&loop_cont<=625)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_S();
  digitalWrite(R2, HIGH);  //R2
  if (loop_cont>=626&&loop_cont<=750)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_E();
  digitalWrite(R3, HIGH);  //R3
  if (loop_cont>=751&&loop_cont<=875)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  print_R();
  digitalWrite(R4, HIGH);  //R4
  if (loop_cont>=876)digitalWrite(DOT,HIGH);
  delayMicroseconds(delaydisplay);
  digitalWrite(DOT,LOW);
  all_low();
  }
}
void print_value(){
  value = val_L1;
  print_var();
  if (dot_temppos ==4)digitalWrite(DOT, HIGH);
  digitalWrite(L1, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_L2;
  if (dot_temppos ==3)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(L2, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_L3;
  if (dot_temppos ==2)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(L3, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_L4;
  if (dot_temppos ==1)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(L4, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_R1;
  if (dot_humpos ==4)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(R1, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_R2;
  if (dot_humpos ==3)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(R2, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_R3;
  if (dot_humpos ==2)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(R3, HIGH);  //L1
  delayMicroseconds(delaydisplay);
  all_low();
  
  value = val_R4;
  if (dot_humpos ==1)digitalWrite(DOT, HIGH);
  print_var();
  digitalWrite(R4, HIGH);  //L1
  delayMicroseconds(delaydisplay); 
  all_low();
  }
  //LOGICA PARA NUMEROS
void print_var(){
  if (value == 0)
    print_N00();
    else if(value == 1)
    print_N01();
    else if(value == 2)
    print_N02();
    else if(value == 3)
    print_N03();
    else if(value == 4)
    print_N04();
    else if(value == 5)
    print_N05();
    else if(value == 6)
    print_N06();
    else if(value == 7)
    print_N07();
    else if(value == 8)
    print_N08();
    else if(value == 9)
    print_N09();
    else
    print_E();
}
