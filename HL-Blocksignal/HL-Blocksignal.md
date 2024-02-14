# HL-Blocksignal
- Benutztes Signal: SIBA DR-Lichtsignal 1220 (?)

## Mögliche Signalbilder (nach RIL 301 (oder so))
### Hp0 (Halt erwarten)
Signalbild: 0|0
            ---
            .|0

### Hp0e (Halt erwarten mit Ersatzlampe)
Signalbild: 0|0
            ---
            0|.

### Hl1 (Fahrt mit Höchstgeschwindigkeit)
Signalbild: 0|.
            .|.

### Hl4 (Geschwindigkeit auf 100km/h verringern)
Signalbild: 0|x
            ---
            0|0

### Hl7 (Geschwindigkeit auf 40/60 km/h verringern)
Signalbild: x|0
            ---
            0|0

### Hl10 (Halt erwarten)
Signalbild: .|0
            ---
            0|0


Gespeichert werden die Signalbilder in einem 8-Bit-Integer mit folgender Aufschlüsslung:
LSB 2^0 Rot
    2^1 Grün
    2^2 Gelb
    2^3 Rot (Ersatzlampe)
    2^4 Rot (Blinkend)
    2^5 Grün (Blinkend)
    2^6 Gelb (Blinkend)
    2^7 Rot (Ersatzlampe) (Blinkend)
MSB 2^8 unused

So ergeben sich folgende Zahlen für die jeweiligen Signalbilder:
Signal aus = 0
       Hp0 = 1
       Hl1 = 2
      Hl10 = 4
      Hp0e = 8
       Hl4 = 32
       Hl7 = 64
