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

Potentiometrul dual output a permis atat controlul volumului, cat si al led-urilor ce ilustreaza valoarea (variatia) acestuia.

Implementarea functionalitatilor specifice unei tastaturi s-a bazat pe utilizarea librariei HID-Project, care include functii suplimentare pentru replicarea comportamentului unui mouse / joystick / gamepad etc.
