# Project_Engine

# ----Do zrobienia ----#

### ENGINE ###
# Niedziela
- Zaimplementuj klasę PrimitiveRenderer, którą wyposażysz w funkcjonalność rysowania prymitywów. W tym celu wykorzystaj możliwości wybranej przez siebie  biblioteki graficznej []
- Przerobic klase na PrimitiveRenderer bez obiektu.

- Rozszerz funkcjonalność klasy PrimitiveRenderer o kolejną metodę rysującą odcinek, która będzie wykorzystywała przedstawiony w instrukcji algorytm przyrostowy Zweryfikuj poprawność działania metody dla różnych przypadków nachylenia odcinków. Porównaj uzyskane rezultaty z tymi otrzymanymi z użyciem domyślnego algorytmu wbudowanego w bibliotekę graficzną.

- Zaimplementuj klasę Point2D reprezentującą współrzędne punktu w przestrzeni 2D.
Klasa ta powinna posiadać metody umożliwiające:
• odczytanie współrzędnych punktu,
• zmodyfikowanie współrzędnych punktu,
• narysowanie punktu (zastosuj tu klasę PrimitiveRenderer).

- Zaimplementuj klasę LineSegment reprezentującą odcinek. Końce odcinka mogą być
w niej przechowywane jako dwa obiekty typu Point2D. Klasa ta powinna posiadać
metody umożliwiające:
• odczytanie współrzędnych poszczególnych końców odcinka,
• zmodyfikowanie współrzędnych poszczególnych końców odcinka,
• narysowanie odcinka (z wyborem algorytmu rysowania: domyślny lub przyrostowy; zastosuj tu klasę PrimitiveRenderer).

- Rozszerz funkcjonalność klasy PrimitiveRenderer o metodę (lub kilka metod)
umożliwiającą narysowanie linii łamanej otwartej lub zamkniętej. Metoda ta powinna przyjmować przez parametr zbiór punktów typu Point2D lub zbiór odcinków
typu LineSegment (np. na zasadzie obiektu klasy vector).

- Lista objektow na danej scenie oraz lista scen.

### GAME ###
# Sobota

- Poruszanie się po świecie,
  + Dodac testowy obiekt/klase gracza
  + Zrobic poruszanie WASD w jednym kierunku
  + Wstepna kolizja
  + Tilemap
- Ograniczona interakcja ze światem,
  + Kolizja postaci z mapa
- Przejście ze sceny świata do sceny walki,
  + Dodanie kilku wrogow
  + System walki 
- Podstawowe grafiki postaci i niektórych przeciwników.
