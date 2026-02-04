#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSansBold7pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>


// 'battery-charging', 24x24px
const unsigned char epd_bitmap_battery_charging [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xff, 0xe0, 0x7f, 0xff, 0xf0, 0xc0, 0x00, 0x18, 0xc0, 0x20, 0x18, 0xc0, 0x60, 0x18, 0xc0, 0xc0, 
	0x1b, 0xc0, 0xf8, 0x1b, 0xc0, 0xf8, 0x1b, 0xc0, 0x18, 0x1b, 0xc0, 0x30, 0x18, 0xc0, 0x20, 0x18, 
	0xc0, 0x00, 0x18, 0x7f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'battery-empty', 24x24px
const unsigned char epd_bitmap_battery_empty [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xff, 0xe0, 0x7f, 0xff, 0xf0, 0xc0, 0x00, 0x18, 0xc0, 0x00, 0x18, 0xc0, 0x00, 0x18, 0xc0, 0x00, 
	0x1b, 0xc0, 0x00, 0x1b, 0xc0, 0x00, 0x1b, 0xc0, 0x00, 0x1b, 0xc0, 0x00, 0x18, 0xc0, 0x00, 0x18, 
	0xc0, 0x00, 0x18, 0x7f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'battery-full', 24x24px
const unsigned char epd_bitmap_battery_full [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xff, 0xe0, 0x7f, 0xff, 0xf0, 0xc0, 0x00, 0x18, 0xcf, 0xff, 0x98, 0xdf, 0xff, 0xd8, 0xd8, 0x00, 
	0xdb, 0xd8, 0x00, 0xdb, 0xd8, 0x00, 0xdb, 0xd8, 0x00, 0xdb, 0xdf, 0xff, 0xd8, 0xcf, 0xff, 0x98, 
	0xc0, 0x00, 0x18, 0x7f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'battery25', 24x24px
const unsigned char epd_bitmap_battery25 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xff, 0xe0, 0x7f, 0xff, 0xf0, 0xc0, 0x00, 0x18, 0xce, 0x00, 0x18, 0xdf, 0x00, 0x18, 0xdb, 0x00, 
	0x1b, 0xdb, 0x00, 0x1b, 0xdb, 0x00, 0x1b, 0xdb, 0x00, 0x1b, 0xdf, 0x00, 0x18, 0xce, 0x00, 0x18, 
	0xc0, 0x00, 0x18, 0x7f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'battery50', 24x24px
const unsigned char epd_bitmap_battery50 [] PROGMEM = {
	0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0xc0, 0x00, 0x18, 0xcf, 0xc0, 0x18, 0xdf, 0xe0, 0x19, 0xd8, 
	0x60, 0x1b, 0xd8, 0x60, 0x1b, 0xd8, 0x60, 0x1b, 0xd8, 0x60, 0x1b, 0xdf, 0xe0, 0x19, 0xcf, 0xc0, 
	0x18, 0xc0, 0x00, 0x18, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'battery75', 24x24px
const unsigned char epd_bitmap_battery75 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xff, 0xe0, 0x7f, 0xff, 0xf0, 0xc0, 0x00, 0x18, 0xcf, 0xfc, 0x18, 0xdf, 0xfe, 0x18, 0xd8, 0x06, 
	0x1b, 0xd8, 0x06, 0x1b, 0xd8, 0x06, 0x1b, 0xd8, 0x06, 0x1b, 0xdf, 0xfe, 0x18, 0xcf, 0xfc, 0x18, 
	0xc0, 0x00, 0x18, 0x7f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'gps', 24x24px
const unsigned char epd_bitmap_gps [] PROGMEM = {
	0x3c, 0x3e, 0x1e, 0x7e, 0x3f, 0x3c, 0x40, 0x21, 0x60, 0xc0, 0x21, 0x20, 0xcf, 0xbf, 0x3e, 0xc1, 
	0xbe, 0x03, 0x43, 0x20, 0x03, 0x7f, 0x20, 0x3f, 0x3c, 0x20, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'heart', 24x24px
const unsigned char epd_bitmap_heart [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x81, 0xc0, 0x0f, 0xe7, 0xf0, 0x1f, 0xff, 0xf8, 0x3f, 
	0xff, 0xfc, 0x3f, 0xff, 0xfc, 0x7f, 0xff, 0xfe, 0x7f, 0xff, 0xfe, 0x7f, 0xff, 0xfe, 0x7f, 0xff, 
	0xfe, 0x3f, 0xff, 0xfc, 0x3f, 0xff, 0xfc, 0x1f, 0xff, 0xf8, 0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 
	0x03, 0xff, 0xc0, 0x01, 0xff, 0x80, 0x00, 0xff, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3c, 0x00, 0x00, 
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const int LCD_D0 = 13; const int LCD_D1 = 12;
const int LCD_D2 = 33; const int LCD_D3 = 32;
const int LCD_D4 = 25; const int LCD_D5 = 23;
const int LCD_D6 = 22; const int LCD_D7 = 21;
const int LCD_WR = 14; const int LCD_CS = 27;
const int LCD_RS = 26; const int LCD_RST = 18;

// Puffer: 1 Byte pro Pixel (Werte 0-31)
// 240 * 160 = 38400 Bytes
uint8_t framebuffer[38400]; 

// Ein Byte-Wert wird in 8 Bit zerlegt und gleichzeitig auf den Datenbus geschrieben
void writeBus(uint8_t val) {
  digitalWrite(LCD_D0, (val & 0b00000001) >> 0 );
  digitalWrite(LCD_D1, (val & 0b00000010) >> 1 );
  digitalWrite(LCD_D2, (val & 0b00000100) >> 2 );
  digitalWrite(LCD_D3, (val & 0b00001000) >> 3 );
  digitalWrite(LCD_D4, (val & 0b00010000) >> 4 );
  digitalWrite(LCD_D5, (val & 0b00100000) >> 5 );
  digitalWrite(LCD_D6, (val & 0b01000000) >> 6 );
  digitalWrite(LCD_D7, (val & 0b10000000) >> 7 );
  
  digitalWrite(LCD_WR, LOW); // Write enable clock input pin: The data on DB0 to DB15 are latched at the rising edge of the /WR signal. [14]
  delayMicroseconds(1);      // so wird eine steigende Flanke garantiert (1 us)
  digitalWrite(LCD_WR, HIGH);
}

void writeCmd(uint8_t cmd) {
  digitalWrite(LCD_CS, LOW); // Chip enable - active LOW wenn Befehle gesendet werden sollen [14]
  digitalWrite(LCD_RS, LOW); // Wird ein Befehl geschrieben, ist RS (im Datenblatt A0) LOW [14]
  writeBus(cmd);             // das Byte wird parallel abgeschickt
  digitalWrite(LCD_CS, HIGH);
}

void writeData(uint8_t data) {
  digitalWrite(LCD_CS, LOW); 
  digitalWrite(LCD_RS, HIGH); // Werden Daten geschrieben, ist RS (im Datenblatt A0) HIGH [14]
  writeBus(data);             // das Byte wird parallel abgeschickt
  digitalWrite(LCD_CS, HIGH);
}

// --- 3. INIT (Bekannte Sequenz) ---
void initDisplay() {
    pinMode(LCD_D0, OUTPUT); pinMode(LCD_D1, OUTPUT);
    pinMode(LCD_D2, OUTPUT); pinMode(LCD_D3, OUTPUT);
    pinMode(LCD_D4, OUTPUT); pinMode(LCD_D5, OUTPUT);
    pinMode(LCD_D6, OUTPUT); pinMode(LCD_D7, OUTPUT);
    pinMode(LCD_WR, OUTPUT); pinMode(LCD_CS, OUTPUT);
    pinMode(LCD_RS, OUTPUT); pinMode(LCD_RST, OUTPUT);
    digitalWrite(LCD_CS, HIGH); // Chip enable active LOW
    digitalWrite(LCD_WR, HIGH); // Write enable input,active LOW

    digitalWrite(LCD_RST, LOW); delay(100); // Reset durchführen
    digitalWrite(LCD_RST, HIGH); delay(100);

    writeCmd(0x30); // EXT IN (also EXT=0)
    writeCmd(0x94); // Sleep Out (Befehl 8)
    writeCmd(0xd1); // Internal OSC on (Befehl 20)
    
    // ------------ Frickelige Stelle! -------------

    writeCmd(0x20); // Power Control 
    writeData(0b00001000); 
    // Es steht nirgends explizit in der Befehlstabelle, dass man zuerst nur den Booster (0x08) und erst nach einer Pause den Rest (0x0B) einschalten darf.
    // Das findet man nur ganz hinten in einem Beispiel-Flowchart auf S. 64 ("Power ON Sequence").
    delay(10);
    
    writeCmd(0x20);  // Power Control 
    writeData(0x0b); // Booster
    delay(10);

    // --------------------------------------------
    
    // Duty 160
    writeCmd(0xca); // Display Control (Befehl 6)
    writeData(0x04); 
    writeData(0x27); 
    writeData(0x00);

    writeCmd(0xbb); // COM Scan Direction (Befehl 5)
    writeData(0x01); // [0,0,1] (0->79, 159->80) (lt. Github-Code)
    
    //  Data Scan Direction (Befehl 11)
    writeCmd(0xbc); 
    writeData(0x01); // Das display ist punksymmetrisch verdrahtet, daher Spielgeung um die mittlere X-Achse (vgl. Abb 42b) 
    writeData(0x00); // PB2 is to change P1, P2, P3 arrangement of the segment output according to P1, P2, P3 arrangement on the LCD panel. This command will set the writing position of data (P1, P2, P3) on the display memory to be changed or not. [44]
    writeData(0x01); // 32 gray-scale 2Byte 3Pixel mode [44]

    // Analog Tuning (Midas Spezifisch)
    writeCmd(0x31); // erweiterter Befehlssatz (EXT = 1)
    writeCmd(0x32); // Analog Circuit Set [37]
    writeData(0x05); // Schöner Mist! Hier kann man raten, 
    writeData(0x00); // was Midas gerne hätte. Das Midas-
    writeData(0x02); // Datenblatt verschweigt das!

    writeCmd(0x30); // zurück zum normalen Befehlssatz
    writeCmd(0xaf); // ON (Befehl 1)

    // Kontrast
    writeCmd(0x81); // Increment Electronic Volume (Befehlt 24) DOPPELBYTE-BEFEEHL!
    writeData(0b101101); // LSBs 101101 (D0-D5)
    writeData(0b011); // MSBs 011
    // -> 237 / 511

    // wird verwendet statt Befehl 23 ("VOLCTRL")
    // warum auch immer????
    for(int i=0; i<34; i++) { 
      writeCmd(0xD6); // Befehl 24 "VOLUP" (EC Increase 1)
      delay(2); 
    }
    
    writeCmd(0xA6); // DISNOR = Normal (0=Weiß, 31=Schwarz), Befehl 3

    updateDisplay();
}

// Setzt Pixel im RAM. greyValue: 0 (Weiß) bis 31 (Schwarz)
void setPixel(int x, int y, uint8_t greyValue) {
    if (x < 0 || x >= 240 || y < 0 || y >= 160) return;
    
    // Sicherheit: Wert auf 5 Bit begrenzen (0-31)
    if (greyValue > 31) greyValue = 31;
    
    framebuffer[y * 240 + x] = greyValue;
}

// Schickt RAM an Display und wandelt Formate um
void updateDisplay() {
    writeCmd(0b00010101); // Bereich Spalten (Befehl 10; "Column Address Set") [41]
    writeData(0);   // von 0
    writeData(79); // Wichtig: 3 Pixel werden nacheinander gesendet! Es sind alos 240/3 = 80 Spalten = Wert 79 (Das ist nur bei Zeilen so!!)
                                                      
    writeCmd(0b01110101); // Bereich Zeilen (Befehl 9; "Line Address Set") [41]
    writeData(0); // von 0
    writeData(0x9F); // bis 160 (Zeilen sind nicht zusammengefasst)


    // Das Display geht automatisch zum nächsten Pixel über, wenn es erkannthat, dass ein güktiger Pixel gesendet wurde!
    // "the line address is incremented by 1 and the column address is returned to the start column" [44]
    // -> es wird Spaltenweise inkrementiert und beim Überlauf in die nächste Zeile gewechselt
    
    
    writeCmd(0b01011100); // RAM Write Start (Befehl 12: "Memory write") [36]
    // "the write mode is automatically cancelled if any other command is entered." [44]

    // Hier werdne ide Daten aus dem Framebuffer 3-Pixel-weise auf den Datenbus geschickt
    for (long i = 0; i < 38400; i += 3) {
        // Hole 3 Grauwerte (0-31)
        uint8_t p1 = framebuffer[i];
        uint8_t p2 = framebuffer[i+1];
        uint8_t p3 = framebuffer[i+2];


        // Ein Pixel hat 32 Graustufen -> 5 Bit
        // ein Doppelbyte hat 16 Bit
        // gemäß 2B3P, 8-bit mode [22]

        // Der Datenstrom besteht aus:
        // Byte 1: P1 [1.7-1.3] P2 [1.2-1.0]
        // Byte 2: P2 [2.7-2.6] P3 [2.4-1.0]

        // oder anders: P1 (Bits 15-11) | P2 (Bits 10-6) | Unused (Bit 5) | P3 (Bits 4-0)

        // [2.5] ist ein Don't Care
        
        // p1 hat den Wertebreich 0b00000-0b11111 und die hintersten 5 Bit im 2-Byte-Protkoll -> 16 - 5 = 11 ist absolute Wertigkeit des P1-LSB
        // p2 hat den Wertebreich 0b00000-0b11111 und die Bits 6-11 im 2-Byte-Protkoll
        // p3 hat den Wertebreich 0b00000-0b11111 und die Bits 0-5 im 2-Byte-Protkoll

        //             -> [5 Bit P1] + [5 Bit P2] + 0 + [5 Bit P3]  (MSB-LSB; man stelle sich hier die Bits als String vor, keine Stellweise Addition!!)

        uint16_t data = (p1 << 11)   | (p2 << 6)       | (p3);

        // Senden (High Byte zuerst)
        writeData(data >> 8); // sende die 8 MSB-Bit
        writeData(data & 0xFF);// sende die 8 LSB-Bit (durch Maskierung)
    }
}

// eigene Klasse, die von Adafruit_GFX erbt
class MyCustomDisplay : public Adafruit_GFX {
  public:
    // Konstruktor: Übergib die Breite und Höhe der Matrix
    MyCustomDisplay(int16_t w, int16_t h) : Adafruit_GFX(w, h) {}

    // Das ist die einzige Funktion, die zwingend implementiert werden muss
    void drawPixel(int16_t x, int16_t y, uint16_t color) override {
      setPixel(x, y, 0); 
    }
};



MyCustomDisplay matrix(240, 160);


void drawTextCentered(String text, int16_t x, int16_t y) {
  int16_t x1, y1;
  uint16_t w, h;
  
  matrix.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  
  // Berechnung der X-Position
  x = (x - w/2);
  
  // Wichtig: x1 korrigiert kleine Abweichungen im Font-Design
  matrix.setCursor(x - x1, y); 
  matrix.print(text);
}


void drawTextRight(String text, int16_t x, int16_t y) {
  int16_t x1, y1;
  uint16_t w, h;
  
  matrix.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  
  x = x - w;
  
  matrix.setCursor(x - x1, y);
  matrix.print(text);
}

void drawTextLeft(String text, int16_t x, int16_t y) {
  matrix.setCursor(x, y);
  matrix.print(text);
}



void displayParameters(String spm, String split, String chrono, String distance) {

  // Zeichnen des Rasters
  matrix.fillRect(119,20,2,160,0);
  matrix.fillRect(0,20,240,2,0);
  matrix.fillRect(0,100,240,2,0);


  matrix.drawBitmap(214, -1, epd_bitmap_battery_full, 24, 24, 0);
  matrix.drawBitmap(180, 5, epd_bitmap_gps, 24, 12, 0);
  matrix.drawBitmap(108, -1, epd_bitmap_heart, 24, 24, 0);

  matrix.setTextSize(1);
  matrix.setFont(&FreeSansBold7pt7b);
  drawTextLeft("14:45", 2, 12); // Oben links

  // Angaben
  matrix.setTextSize(2);
  matrix.setFont(&FreeSansBold18pt7b);
  drawTextCentered(spm, 60, 80); // Oben links

  matrix.setTextSize(1);
  drawTextCentered(split, 180, 65); // Oben rechts
  drawTextLeft(chrono, 2, 135); // unten links
  drawTextCentered(distance, 180, 135); // unten rechts
  
  // Untertitel
  matrix.setTextSize(1);
  matrix.setFont(&FreeSansBold7pt7b);
  drawTextRight("SPM", 117, 97); // Oben links
  drawTextLeft("SPLIT", 122, 97); // oben rechts
  drawTextRight("/500M", 238, 97);

  drawTextRight("HRS: 0", 117, 157); // unten links
  drawTextLeft("CHRONO", 2, 157);
  drawTextLeft("DISTANCE", 122, 157); // unten rechts
  drawTextRight("M", 238, 157); // unten rechts


}

String getFormattedTime() {
  unsigned long currentMillis = millis();

  // Berechnung
  unsigned long totalSeconds = currentMillis / 1000;
  unsigned long minutes = totalSeconds / 60;
  unsigned long seconds = totalSeconds % 60;
  
  // die Millisekunden der aktuellen Sekunde (0-999) 
  // und teile durch 100, um nur die erste Ziffer (0-9) zu erhalten.
  unsigned long tenths = (currentMillis % 1000) / 100;

  // Formatierung: MM:SS:z
  char buffer[10];
  sprintf(buffer, "%02lu:%02lu:%1lu", minutes, seconds, tenths);

  return String(buffer);
}


void setup() {
  initDisplay();
}

void loop() {

  // gesamtes Display leeren - hier muss in der Performance noch etwas nachgelegt werden - das ist ineffizient
  for(int i=0; i<240; i++) {
    for(int j=0; j<160; j++) {
      setPixel(i, j, 31);
    }
  }

  displayParameters("32","1:51",getFormattedTime(),"2056");

  updateDisplay();

  delay(50);
}