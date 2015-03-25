#include <EEPROMex.h>
#include <EEPROMVar.h>

int eeprom_read_id();
void eeprom_write_id(char* id);
int eeprom_read_lcd();
void eeprom_write_lcd(char* text);
int eeprom_read_rfid();
void eeprom_write_rfid(int number);
void eeprom_update_rfid(int number);

char mailbox_id[] = "1";
char mailbox_lcd[] = "hei";

//------------setup----------//
void setup() {
  Serial.begin(9600); //fjerne dette
  Serial.print("Serial begins...\n"); //fjerne dette
}

void loop() {
  delay(5000);
  eeprom_write_id(mailbox_id);
  Serial.println(eeprom_read_id());
  Serial.println();  
}

//------------id_read----------//
int eeprom_read_id(){
  int addr = 100;
  char output = 0;
  EEPROM.readBlock<char>(addr, output);
  return output;
}
//------------id_write----------//
void eeprom_write_id(char* id){
  int addr = 100;
  EEPROM.writeBlock<char*>(addr, id);
}
//------------lcd_read----------//
int eeprom_read_lcd(){
  int addr = 50;
  char output;
  EEPROM.readBlock<char>(addr, output);
  return output;
}
//------------lcd_write----------//
void eeprom_write_lcd(char* text){
  int addr = 50;
  EEPROM.writeBlock<char*>(addr, text);
}
//------------rfid_read----------//
int eeprom_read_rfid(){
  int addr = 0;
  int output = 0;
  EEPROM.readBlock<char>(addr, output);
  return output;
}
//------------rfid_write----------//
void eeprom_write_rfid(int number){
  int addr = 0;
  EEPROM.writeBlock<char>(addr, number);
}
//------------rfid_update----------//
void eeprom_update_rfid(int number){
  int addr = 0;
  EEPROM.updateBlock<char>(addr, number);
}
