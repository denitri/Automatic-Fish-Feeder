//library
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <virtuabotixRTC.h>
#include <Servo.h>

//byte data_suhu;

//deklarasi
virtuabotixRTC myRTC(13, 12, 11); //koneksi ke RTC
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //koneksi LCD
int lcd_key = 0;
int adc_key_in = 0;
#define kanan 0
#define atas 1
#define bawah 2
#define kiri 3
#define sec 4
#define btnNONE 5
int read_LCD_buttons()
{
adc_key_in = analogRead(0);
if (adc_key_in < 50) return kanan;
if (adc_key_in < 195) return atas;
if (adc_key_in < 380) return bawah;
if (adc_key_in < 555) return kiri;
if (adc_key_in < 790) return sec;
return btnNONE;
}

//variabel servo
//Servo myservo;
//int pos = 0;
int servoPin = A4;
int pulseTime;

//insialisasi
void setup(){
  pinMode(servoPin,OUTPUT);
  pinMode(3, OUTPUT); //Buzzer
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
  pinMode(A2, OUTPUT); //LED power
  pinMode(A3, OUTPUT); //LED alarm
  //myservo.attach(A4);
  digitalWrite(A2, HIGH); //LED power hidup  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Fish Feeder");
  lcd.setCursor(2,1);
  lcd.print("By Harbi Salim P");
  delay(2000);
  lcd.clear();
}

//variabel
int tekanbawah=0; //data tekan bawah
int tekanatas=0; //data tekan atas

//int menu_suhu=0; //menu suhu
int menu_waktu=0; //menu waktu
int menu_tanggal=0; //menu tanggal

int menu_alarm1=0; //menu alarm1
int menu_alarm2=0; //menu alarm1
int menu_alarm3=0; //menu alarm1
int menu_fish=0; //menu fish
int fish=0; //fish

//int suhu=0;//data suhu
int ikan=0;//data ikan

int set_jam=0;
int set_menit=0;

int set_hari=0;
int set_bulan=0; 
int set_tahun=2014; 

int set_jam_alarm1=0;
int set_menit_alarm1=0;
int set_jam_alarm2=0;
int set_menit_alarm2=0;
int set_jam_alarm3=0;
int set_menit_alarm3=0;

int set_fish_alarm=0;

int submenu=0;
int subsubmenu=0; 

//int set_suhu=0; 
int set_waktu=0;
int set_tanggal=0; 

int set_alarm1=0;
int set_alarm2=0;
int set_alarm3=0;

int set_fish=0; 

int persetujuan1=0; 
int persetujuan2=0;
int persetujuan3=0;
int persetujuan4=0;
int persetujuan5=0;
int persetujuan6=0;
int permintaan=0; 
int hapus_satu=0; 
int tekan=0;


void loop(){
  myRTC.updateTime();
  //menu
  lcd_key = read_LCD_buttons(); // masukan tombol
    if(tekan==0){
      menu_utama();
    }
    if (lcd_key==sec){
      tekan=1;
      lcd.clear();
      lcd.begin(16, 2); 
      lcd.setCursor(0,0);
      lcd.print("******MENU******");
      submenu=1;
    }
    if(submenu==1){
      lcd_key = read_LCD_buttons(); // masukan tombol
      if(subsubmenu==0){
        //JIKA DI TEKAN BAWAH
        if (lcd_key==bawah){
          tekanatas=0;
          tekanbawah=tekanbawah+1;
          lcd.clear();
          if(tekanbawah>=7){tekanbawah=1;}
          delay(200);
        }
        if(tekanbawah==1){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("    SET TIME    ");
          //menu_suhu=0;
          menu_waktu=1;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=0;
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanbawah==2){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("    SET DATE    ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=1;
          menu_alarm1=0;
          menu_alarm2=0;
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanbawah==3){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("  SET FEEDING 1 ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=1;
          menu_alarm2=0;
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanbawah==4){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("  SET FEEDING 2 ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=1;
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanbawah==5){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("  SET FEEDING 3 ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=0;   
          menu_alarm3=1;
          menu_fish=0;
        }
       if(tekanbawah==6){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("    SET FISH    ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=0;   
          menu_alarm3=0;
          menu_fish=1;      
        }
        //JIKA DITEKAN ATAS
        if (lcd_key==atas){
          tekanbawah=0;
          tekanatas=tekanatas+1;
          lcd.clear();
          if(tekanatas>=7){tekanatas=1;}
          delay(200);
        }
        if(tekanatas==1){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("    SET TIME    ");
          //menu_suhu=0;
          menu_waktu=1;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=0;   
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanatas==6){
          lcd.setCursor(0,0);
          lcd.print("    -> Menu <-    ");
          lcd.setCursor(0,1);
          lcd.print("    SET DATE    ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=1;
          menu_alarm1=0;
          menu_alarm2=0;   
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanatas==5){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("  SET FEEDING 1 ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=1;
          menu_alarm2=0;   
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanatas==4){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("  SET FEEDING 2 ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=1;   
          menu_alarm3=0;
          menu_fish=0;
        }
        if(tekanatas==3){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("  SET FEEDING 3 ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=0;   
          menu_alarm3=1;
          menu_fish=0;
        }
        if(tekanatas==2){
          lcd.setCursor(0,0);
          lcd.print("   -> Menu <-   ");
          lcd.setCursor(0,1);
          lcd.print("    SET FISH    ");
          //menu_suhu=0;
          menu_waktu=0;
          menu_tanggal=0;
          menu_alarm1=0;
          menu_alarm2=0;   
          menu_alarm3=0;
          menu_fish=1;
        }
      }
      //set_suhu_code();
    set_fish_code();
      set_waktu_code();
      set_tanggal_code();
      set_alarm1_code();
      set_alarm2_code();
      set_alarm3_code();
      alarmkontrol();
      if (lcd_key==kanan&&permintaan==0){
        menu_utama();hapus_satu=0;
      }
    }
}

//fungtion
void menu_utama(){
  tekan=0;
  if(hapus_satu==0){ lcd.clear(); hapus_satu=1; }
  permintaan=0;
  //set_suhu=0;
  set_waktu=0;
  set_tanggal=0;
  set_alarm1=0;
  set_alarm2=0;
  set_alarm3=0;
  persetujuan1=0;
  persetujuan2=0;
  persetujuan3=0;
  persetujuan4=0;
  persetujuan5=0;
  persetujuan6=0;
  submenu=0;
  subsubmenu=0;
  tekanbawah=0;
  tekanatas=0;
   
  printdate();
  printikan();
  alarmkontrol();
}



void set_waktu_code(){
  if (lcd_key==kiri&&menu_waktu==1){
    subsubmenu=1;
    set_waktu=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Time");   
  }
  if(set_waktu==1){
    if (lcd_key==atas){
      persetujuan1=1;
      menu_waktu=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Hour");
      lcd.setCursor(0,1);
      lcd.print("Hour=");
      set_jam=set_jam+1;
      if(set_jam==24){set_jam=0;}
      lcd.setCursor(7,1);
      lcd.print(set_jam);
      delay(250);
    } 
    if (lcd_key==bawah){
    persetujuan1=1;
      menu_waktu=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Minute");
      lcd.setCursor(0,1);
      lcd.print("Minute=");
      set_menit=set_menit+1;
      if(set_menit==60){set_menit=0;}
      lcd.setCursor(10,1);
      lcd.print(set_menit);
      delay(250);
    }
    if (lcd_key==kiri&&persetujuan1==1){
      persetujuan1=0;
      menu_waktu=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Time Saved.. ");
      myRTC.setDS1302Time(00, set_menit, set_jam, myRTC.dayofweek, myRTC.dayofmonth, myRTC.month, myRTC.year); 
      delay(2000);
      menu_utama();hapus_satu=0;
    }
   
  }
 
} 

void set_tanggal_code(){
  permintaan=1;
  if (lcd_key==kiri&&menu_tanggal==1){
    subsubmenu=1;
    set_tanggal=1; 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Date");   
  }
  if(set_tanggal==1){
    if (lcd_key==atas){
      persetujuan2=1;
      menu_tanggal=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Day");
      lcd.setCursor(0,1);
      lcd.print("Day=");
      set_hari=set_hari+1;
      if(set_hari==32){set_hari=0;}
      lcd.setCursor(7,1);
      lcd.print(set_hari);
      delay(250);
    }
    if (lcd_key==bawah){
      menu_tanggal=0;
      persetujuan2=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Mounth");
      lcd.setCursor(0,1);
      lcd.print("Mounth=");
      set_bulan=set_bulan+1;
      if(set_bulan==13){set_bulan=0;}
      lcd.setCursor(10,1);
      lcd.print(set_bulan);
      delay(250);
    }
    if (lcd_key==kanan&&permintaan==1){
      menu_tanggal=0;
      persetujuan2=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Year");
      lcd.setCursor(0,1);
      lcd.print("Year=");
      set_tahun=set_tahun+1;
      if(set_tahun==2099){set_tahun=2014;}
      lcd.setCursor(10,1);
      lcd.print(set_tahun);
      delay(150);
    }
    if (lcd_key==kiri&&persetujuan2==1){
      persetujuan3=0;
      menu_tanggal=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Date Saved.. ");
      myRTC.setDS1302Time(00, myRTC.minutes, myRTC.hours, myRTC.dayofweek, set_hari, set_bulan, set_tahun);
      delay(2000);
      menu_utama();hapus_satu=0;
    }
  }
}

void set_fish_code(){
  if (lcd_key==kiri&&menu_fish==1){
    subsubmenu=1;
    set_fish=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Fish");    
  }
  if(set_fish==1){
  if (lcd_key==atas){
      persetujuan6=1;
      menu_fish=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Fish");
      lcd.setCursor(0,1);
      lcd.print("Fish=");
      fish=fish+1;
      if(fish==50){fish=0;}
      lcd.setCursor(7,1);
      lcd.print(fish);
      delay(250);
    }
  if (lcd_key==kiri&&persetujuan6==1){
    persetujuan6=0;
    menu_fish=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Fish Saved.. ");
    EEPROM.write(0, fish);
    delay(2000);
    menu_utama();hapus_satu=0;
  }  
  }
}

void set_alarm1_code(){
  if (lcd_key==kiri&&menu_alarm1==1){
    subsubmenu=1;
    set_alarm1=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Feeding");    
  }
  if(set_alarm1==1){
    if (lcd_key==atas){
      persetujuan3=1;
      menu_alarm1=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Hour");
      lcd.setCursor(0,1);
      lcd.print("Hour=");
      set_jam_alarm1=set_jam_alarm1+1;
      if(set_jam_alarm1==24){set_jam_alarm1=0;}
      lcd.setCursor(7,1);
      lcd.print(set_jam_alarm1);
      delay(250);
    }
    if (lcd_key==bawah){
    persetujuan3=1;
      menu_alarm1=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Minute");
      lcd.setCursor(0,1);
      lcd.print("Minute=");
      set_menit_alarm1=set_menit_alarm1+1;
      if(set_menit_alarm1==60){set_menit_alarm1=0;}
      lcd.setCursor(10,1);
      lcd.print(set_menit_alarm1);
      delay(250);
    }
    if (lcd_key==kiri&&persetujuan3==1){
      persetujuan3=0;
      menu_alarm1=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Alarm Saved.. ");
      EEPROM.write(1, set_menit_alarm1);
      EEPROM.write(2, set_jam_alarm1);
      delay(2000);
      menu_utama();hapus_satu=0;
    }
  }
}

void set_alarm2_code(){
  if (lcd_key==kiri&&menu_alarm2==1){
    subsubmenu=1;
    set_alarm2=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Feeding");    
  }
  if(set_alarm2==1){
    if (lcd_key==atas){
      persetujuan4=1;
      menu_alarm2=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Hour");
      lcd.setCursor(0,1);
      lcd.print("Hour=");
      set_jam_alarm2=set_jam_alarm2+1;
      if(set_jam_alarm2==24){set_jam_alarm2=0;}
      lcd.setCursor(7,1);
      lcd.print(set_jam_alarm2);
      delay(250);
    }
    if (lcd_key==bawah){
    persetujuan4=1;
      menu_alarm2=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Minute");
      lcd.setCursor(0,1);
      lcd.print("Minute=");
      set_menit_alarm2=set_menit_alarm2+1;
      if(set_menit_alarm2==60){set_menit_alarm2=0;}
      lcd.setCursor(10,1);
      lcd.print(set_menit_alarm2);
      delay(250);
    } 
    if (lcd_key==kiri&&persetujuan4==1){
      persetujuan4=0;
      menu_alarm2=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Alarm Saved.. ");
      EEPROM.write(3, set_menit_alarm2);
      EEPROM.write(4, set_jam_alarm2);
      delay(2000);
      menu_utama();hapus_satu=0;
    }
  }
}

void set_alarm3_code(){
  if (lcd_key==kiri&&menu_alarm3==1){
    subsubmenu=1;
    set_alarm3=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Feeding");    
  }
  if(set_alarm3==1){
    if (lcd_key==atas){
      persetujuan5=1;
      menu_alarm3=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Hour");
      lcd.setCursor(0,1);
      lcd.print("Hour=");
      set_jam_alarm3=set_jam_alarm3+1;
      if(set_jam_alarm3==24){set_jam_alarm3=0;}
      lcd.setCursor(7,1);
      lcd.print(set_jam_alarm3);
      delay(250);
    }
    if (lcd_key==bawah){
    persetujuan5=1;
      menu_alarm3=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Minute");
      lcd.setCursor(0,1);
      lcd.print("Minute=");
      set_menit_alarm3=set_menit_alarm3+1;
      if(set_menit_alarm3==60){set_menit_alarm3=0;}
      lcd.setCursor(10,1);
      lcd.print(set_menit_alarm3);
      delay(250);
    } 
    if (lcd_key==kiri&&persetujuan5==1){
      persetujuan5=0;
      menu_alarm3=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Alarm Saved.. ");
      EEPROM.write(5, set_menit_alarm3);
      EEPROM.write(6, set_jam_alarm3);
      delay(2000);
      menu_utama();hapus_satu=0;
    }
  }
}

void printdate(){
  myRTC.updateTime();
  //delay(700);
  // lcd.clear();
  lcd.setCursor(0,2); //|
  lcd.print(myRTC.dayofmonth); //|
  lcd.print("/"); //|
  lcd.print(myRTC.month); //|
  lcd.print("/"); //|
  lcd.print(myRTC.year); //|
  lcd.print(" ");
  myRTC.updateTime();
  lcd.setCursor(0,0);
  if(myRTC.hours<=9){
    lcd.setCursor(0,0);
    lcd.print("0");
    lcd.setCursor(1,0);
    lcd.print(myRTC.hours);
  }
    else
      lcd.print(myRTC.hours);
      lcd.print(":"); //| 
  if(myRTC.minutes<=9){
    lcd.setCursor(3,0);
    lcd.print("0");
    lcd.setCursor(4,0);
    lcd.print(myRTC.minutes);
  }
    else
      lcd.print(myRTC.minutes);
      lcd.print(":");
  if(myRTC.seconds<=9){
    lcd.setCursor(6,0);
    lcd.print("0");
    lcd.setCursor(7,0);
    lcd.print(myRTC.seconds);
  }
    else
    lcd.print(myRTC.seconds);  
  if(myRTC.seconds%2){ 
    digitalWrite(A3, HIGH);
  }
    else{digitalWrite(A3, LOW);}
}

//variabel under
int k=0;
int eeprom_alarm_menit1=0;
int eeprom_alarm_jam1=0;
int eeprom_alarm_menit2=0;
int eeprom_alarm_jam2=0;
int eeprom_alarm_menit3=0;
int eeprom_alarm_jam3=0;
int lama=0;
int eeprom_ikan=0;

void printikan (){
    eeprom_alarm_menit1=EEPROM.read(1);
    eeprom_alarm_jam1=EEPROM.read(2);
//    eeprom_alarm_menit2=EEPROM.read(2);
//    eeprom_alarm_jam2=EEPROM.read(3);
//    eeprom_alarm_menit3=EEPROM.read(4);
//    eeprom_alarm_jam3=EEPROM.read(5);

    lcd.setCursor(9,0);
    lcd.print("A:");
    lcd.setCursor(11,0);
    lcd.print(eeprom_alarm_jam1);
    lcd.print(":");
    lcd.print(eeprom_alarm_menit1);
    
    eeprom_ikan=EEPROM.read(0);
    lcd.setCursor(11,1);
    lcd.print("I:");
    lcd.setCursor(13,1);
    lcd.print(eeprom_ikan);

//    lcd.setCursor(9,1);
//    lcd.print("A:");
//    lcd.setCursor(11,1);
//    lcd.print(eeprom_alarm_jam2);
//    lcd.print(":");
//    lcd.print(eeprom_alarm_menit2);
//    delay(5000);
//    lcd.setCursor(9,1);
//    lcd.print("A:");
//    lcd.setCursor(11,1);
//    lcd.print(eeprom_alarm_jam3);
//    lcd.print(":");
//    lcd.print(eeprom_alarm_menit3);
//    delay(5000);
}

void alarmkontrol(){
 eeprom_ikan=EEPROM.read(0);
 eeprom_alarm_menit1=EEPROM.read(1);
 eeprom_alarm_jam1=EEPROM.read(2);
 eeprom_alarm_menit2=EEPROM.read(3);
 eeprom_alarm_jam2=EEPROM.read(4);
 eeprom_alarm_menit3=EEPROM.read(5);
 eeprom_alarm_jam3=EEPROM.read(6);
  if(k==0){
    if(myRTC.minutes==0&&myRTC.hours==0){
       k=1; menu_utama();hapus_satu==0;
    }
    if(myRTC.minutes!=0&&myRTC.hours!=0){ 
    if(eeprom_alarm_menit1==myRTC.minutes&&eeprom_alarm_jam1==myRTC.hours){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Feeding!");
      lcd.setCursor(0,1);
      lcd.print(myRTC.hours);
      lcd.print(":");
      lcd.print(myRTC.minutes);
      beep(1000);
      beep(50);
      beep(50);
      servo();
      if(lcd_key==kiri){ k=1; menu_utama();hapus_satu==0;}
      if(myRTC.seconds==10){ k=1; menu_utama();hapus_satu==0;}
    }
  if(eeprom_alarm_menit2==myRTC.minutes&&eeprom_alarm_jam2==myRTC.hours){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Feeding!");
      lcd.setCursor(0,1);
      lcd.print(myRTC.hours);
      lcd.print(":");
      lcd.print(myRTC.minutes);
      beep(200);
      servo();
      if(lcd_key==kiri){ k=1; menu_utama();hapus_satu==0;}
      if(myRTC.seconds==10){ k=1; menu_utama();hapus_satu==0;}
    }
  if(eeprom_alarm_menit3==myRTC.minutes&&eeprom_alarm_jam3==myRTC.hours){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Feeding!");
      lcd.setCursor(0,1);
      lcd.print(myRTC.hours);
      lcd.print(":");
      lcd.print(myRTC.minutes);
      beep(200);
    servo();
      if(lcd_key==kiri){ k=1; menu_utama();hapus_satu==0;}
      if(myRTC.seconds==10){ k=1; menu_utama();hapus_satu==0;}
    }
    }
     if(myRTC.seconds==15&&k==1){ k=0;} 
  }
}
 

void beep(unsigned char delayms){
  analogWrite(3, 20);      
  delay(delayms);          
  analogWrite(3, 0);     
  delay(delayms);    
}

void servo() {
  eeprom_ikan=EEPROM.read(0);
  int katup=0;
  //kondisi katup tergantung makanan
  if(eeprom_ikan>=1&&eeprom_ikan<=10){katup=1600;}
  if(eeprom_ikan>=10&&eeprom_ikan<=20){katup=1900;}
  if(eeprom_ikan>=20&&eeprom_ikan<=30){katup=2200;}
  if(eeprom_ikan>=30&&eeprom_ikan<=40){katup=2500;}
  if(eeprom_ikan>=40&&eeprom_ikan<=50){katup=2650;}
  for(pulseTime = 600; pulseTime <= katup; pulseTime += 50) {
    Serial.println(pulseTime);
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseTime);
    digitalWrite(servoPin, LOW);
    delay(20);
  }
  for(pulseTime = katup; pulseTime >= 600; pulseTime -= 50) {
    Serial.println(pulseTime);
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseTime);
    digitalWrite(servoPin, LOW);
    delay(20);
  }
  for(pulseTime = 0; pulseTime >= 0; pulseTime -= 50) {
    Serial.println(pulseTime);
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseTime);
    digitalWrite(servoPin, LOW);
    delay(60000);
  }
}
