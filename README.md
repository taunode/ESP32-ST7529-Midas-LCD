# ESP32/Arduino Driver for ST7529-based LCDs
## Set up for the MIDAS MCCOG240160C6W-FPTLW LCD

### Based on the ST7529 driver by Augusto Fraga Giachero (2016). Modified, simplified and ported to ESP32/Arduino by Tim van den Boom.

> [!CAUTION]
> Work in progress

## Wiring


| **Midas Pin** | **Function** | **ESP32 Pin (e.g.)** | **Description** |
| --- | --- | --- | --- |
| **1** | `VDD` | 3.3V | VCC Logic |
| **2** | `VSS` | GND | Ground |
| **3** | `/CS` | GPIO 27 | Chip Select (Active Low) |
| **4** | `RS` `(A0)` | GPIO 26 | Register Select (Data/Command) |
| **5** | `WR` | GPIO 14 | Write Signal (Pulse Low) |
| **6** | `/RD` | 3.3V | Read Signal |
| **7** | `DB0` | GPIO 13 | Data Bits |
| **8** | `DB1` | GPIO 12 |
| **9** | `DB2` | GPIO 33 |
| **10** | `DB3` | GPIO 32 |
| **11** | `DB4` | GPIO 25 |
| **12** | `DB5` | GPIO 23 |
| **13** | `DB6` | GPIO 22 |
| **14** | `DB7` | GPIO 21 |
| **15** | `/RST` | GPIO 18 | Reset (Active Low) |
| **16** | `BLA` | 3.3V (VCC) | Backlight Anode\* |


## Usage for graphic functions


### Basic Shapes (ref to Adafruit_GFX)

|     |     |     |
| --- | --- | --- |
| **Function** | **Description** | **Parameters** |
| `drawLine` | Draw a Line| `x0, y0, x1, y1, color` |
| `drawRect` / `fillRect` | Rectangle (Outline / Filled) | `x, y, w, h, color` |
| `drawCircle` / `fillCircle` | Circle | `x, y, r, color` |
| `drawTriangle` / `fillTriangle` | Triangle | `x0, y0, x1, y1, x2, y2, color` |
| `drawRoundRect` / `fillRoundRect` | Soft-Cordnered Rectangle | `x, y, w, h, radius, color` |

### Special-Functions

- `fillScreen(color)`: Fills the screen with the given color
- `drawBitmap`: Draws a Bitmap of "raw pixels"
    - `drawBitmap(x, y, bitmapArray, w, h, color)`
