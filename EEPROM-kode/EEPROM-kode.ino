#include <EEPROMex.h>
#include <EEPROMVar.h>

int eeprom_read_id();
void eeprom_write_id(int text);

int eeprom_read_lcd();
void eeprom_write_lcd(char text);

int eeprom_read_rfid();
void eeprom_write_rfid(int number);
void eeprom_update_rfid(int number);

struct info{
  int id;
  char lcd[32];
};

info mailbox = { 10, "My mailbox" };

void setup() {
  Serial.begin(9600); //fjerne dette
  Serial.print("Serial begins...\n"); //fjerne dette
}

void loop() {
  eeprom_write_id(mailbox.id);
  eeprom_write_lcd(mailbox.lcd);
  Serial.println(eeprom_read_id());
  delay(5000);
  eeprom_read_lcd();
  Serial.println(eeprom_read_lcd());
}

////////////////////////////////
int eeprom_read_id(){
  int addr = 100;
  int output = 0;
  EEPROM.readBlock<char>(addr, output);
  return output;
}

void eeprom_write_id(int text){
  int addr = 100;
  EEPROM.writeBlock<char>(addr, text);
}

int eeprom_read_lcd(){
  int addr = 50;
  char output;
  EEPROM.readBlock<char>(addr, output);
  return output;
}

void eeprom_write_lcd(char text){
  int addr = 50;
  EEPROM.writeBlock<char>(addr, text);
}

int eeprom_read_rfid(){
  int addr = 0;
  int output = 0;
  EEPROM.readBlock<char>(addr, output);
  return output;
}
void eeprom_write_rfid(int number){
  int addr = 0;
  EEPROM.writeBlock<char>(addr, number);
}

void eeprom_update_rfid(int number){
  int addr = 0;
  EEPROM.updateBlock<char>(addr, number);
}
