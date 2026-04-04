# ST7529 Graphics Library for ESP32 (Midas MCCOG240160)

Dieses Repository enthält einen optimierten Low-Level-Grafiktreiber für das transflektive FSTN-Display Midas MCCOG240160C6W-FPTLW (240x160 Pixel) zur Nutzung mit einem ESP32-Mikrocontroller. Der Treiber steuert den integrierten ST7529-Displaycontroller an und wurde im Rahmen einer Studienarbeit im Studiengang Elektrotechnik an der Dualen Hochschule Baden-Württemberg (DHBW) Mannheim entwickelt.

## Features

* **Adafruit GFX Kompatibilität:** Vollständige Integration in die Adafruit GFX-Bibliothek zur universellen Darstellung von Texten, Geometrien und Bitmaps.
* **Speichereffizienz:** Das Display wird im 2B3P-Modus (2 Byte für 3 Pixel) angesteuert. Dies minimiert den Overhead, da für die 32 Graustufen (5 Bit pro Pixel) kaum Bits verschwendet werden.
* **Doppelte Pufferung (Framebuffer):** Das System nutzt einen eigenen Framebuffer (38.400 Bytes) im RAM des ESP32, um Darstellungsfehler beim Bildaufbau zu vermeiden.
* **Hardware-Optimierung:** Reduktion der benötigten GPIO-Pins durch den Einsatz eines SN74HC595N Schieberegisters als Seriell-zu-Parallel-Wandler.

## Warum kein natives SPI? (Hardware-Limitierung)

Obwohl der ST7529-Controller prinzipiell serielle Protokolle (SPI) unterstützt, ist das Midas-Display werksseitig auf einen 8080-Parallelbus fest verdrahtet. Eine native SPI-Kommunikation ist ausgeschlossen, da der hierfür zuständige Konfigurations-Pin (IF2) auf dem Modul dauerhaft auf HIGH gelegt ist und nicht nach außen geführt wird. Ein Betrieb über das SPI-Protokoll ist somit ohne invasive Eingriffe in das PCB-Layout nicht möglich.

## Performance-Vergleich der Schnittstellen

Im Rahmen der Arbeit wurden drei verschiedene Ansteuerungsarten evaluiert. Das Schieberegister stellt hierbei den optimalen Kompromiss dar.

| Schnittstelle | Zeit pro Byte ($t_{Byte}$) | Bildwiederholrate | Pins am ESP32 | FPS pro Pin |
| :--- | :--- | :--- | :--- | :--- |
| **Nativer Parallelbus** | 8,2 µs | ~5 FPS | 10 | 0,5 |
| **I2C Port-Expander (MCP23017)** | 267 µs | ~0,15 FPS | 4 | 0,0375 |
| **Schieberegister (SN74HC595N)** | 18,7 µs | ~2 FPS | 5 | 0,4 |

## Hardware & Schaltpläne

Die Schaltpläne für die verschiedenen Setups befinden sich im Ordner `schematics/` (oder entsprechend verlinken):

1.  **Paralleler Betrieb:** Direkte Verbindung aller 8 Datenbits + Steuerleitungen.
2.  **MCP23017 Setup:** Ansteuerung über den I2C-Bus (SDA/SCL).
3.  **SN74HC595N Setup (Empfohlen):** Seriell-zu-Parallel-Wandlung zur Pin-Ersparnis.

### Pin-Belegung (SN74HC595N)
* **DATA (SER):** GPIO 25
* **SHIFT (SRCLK):** GPIO 32
* **STORE (RCLK):** GPIO 33
* **LCD_WR:** GPIO 14
* **LCD_RS:** GPIO 26

## Quickstart

Der Treiber überschreibt die `drawPixel()` Funktion der Adafruit GFX Library. Komplexere Formen wie Kreise oder Texte nutzen intern diese Funktion.

```cpp
#include "MyCustomDisplay.h"

// Initialisierung (Breite, Höhe)
MyCustomDisplay matrix(240, 160);

void setup() {
  initDisplay(); // Initialisierungssequenz für ST7529
}

void loop() {
  // 1. Framebuffer leeren (z.B. Weiß/Hintergrund)
  memset(framebuffer, 31, sizeof(framebuffer));

  // 2. Zeichnen
  matrix.setCursor(10, 10);
  matrix.print("System Ready");
  matrix.drawCircle(120, 80, 30, 0); // Schwarzer Kreis

  // 3. Update (Daten an Display-RAM senden)
  updateDisplay();
}```
