# Tema-optionala-SMP---USB-HID-Device---Media-keyboard
Tema optionala presupune realizarea unui periferic USB pentru un sistem de calcul de tip PC. Abordarea aleasa pentru implementarea tastaturii a presupus utilizarea placutei de dezvoltare Arduino Leonardo.

Componente necesare:

- Arduino Leonardo
- pushbutton (x 9)
- fire
- rezistente de 220 ohmi (x 3)
- potentiometru dual output 
- led-uri (x 3)
- breadboard
- mini breadboard

Tastele / combinatiile de taste programate in cadrul MediaKeyboard.ino sunt urmatoarele:
- playButton (D2) - porneste videoclipul / melodia
- backButton (D3) - salt la videoclipul precedent / melodia anterioara
- fwdButton (D4) - salt la videoclipul urmator / melodia urmatoare
- muteButton (D5) - opreste sonorul;
- brightUpButton (D6) - creste luminozitatea;
- brightDownButton (D7) - scade luminozitatea;
- winButton (D8) - minimizarea tuturor ferestrelor deschise (Windows + D);
- copyButton (D9) - copiere (CTRL + C)
- pasteButton (D10) - CTRL + V

Potentiometrul dual output a permis atat controlul volumului, cat si al led-urilor ce ilustreaza valoarea (variatia) acestuia in functie de maparea initiala.

Implementarea functionalitatilor specifice unei tastaturi s-a bazat pe utilizarea librariei HID-Project, care include functii suplimentare pentru replicarea comportamentului unui mouse / joystick / gamepad etc. Sistemul de operare recunoaste dispozitivul drept un periferic din clasa asociata.
