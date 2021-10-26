# Project_Engine

# ----Do zrobienia ----#

### ENGINE ###
# 
- Rozszerz funkcjonalność klasy PrimitiveRenderer o kolejną metodę rysującą odcinek, która będzie wykorzystywała przedstawiony w instrukcji algorytm przyrostowy Zweryfikuj poprawność działania metody dla różnych przypadków nachylenia odcinków. Porównaj uzyskane rezultaty z tymi otrzymanymi z użyciem domyślnego algorytmu wbudowanego w bibliotekę graficzną.
- Zaimplementuj NaiveApproach  --> Sprawdz poprawnosc 
  - Dodaj do klasy mozliwosc uzyskania obiektu i manipulacji nim
- Zaimplementuj Bresenham's Algorithm
- Zaimplementuj Wu's Algorithm

- Zaimplementuj klasę LineSegment reprezentującą odcinek. Końce odcinka mogą być
w niej przechowywane jako dwa obiekty typu Point2D. Klasa ta powinna posiadać
metody umożliwiające:
• odczytanie współrzędnych poszczególnych końców odcinka,
• zmodyfikowanie współrzędnych poszczególnych końców odcinka,

• narysowanie odcinka (z wyborem algorytmu rysowania: domyślny lub przyrostowy; zastosuj tu klasę PrimitiveRenderer).
- Rozszerz funkcjonalność klasy PrimitiveRenderer o metodę (lub kilka metod)
umożliwiającą narysowanie linii łamanej otwartej lub zamkniętej. Metoda ta powinna przyjmować przez parametr zbiór punktów typu Point2D lub zbiór odcinków
typu LineSegment (np. na zasadzie obiektu klasy vector).

- Zaimplementowac podstawowe transfomacje (2D)
- Lista objektow na danej scenie oraz lista scen.

- Rozszerz funkcjonalność klasy PrimitiveRenderer o kolejną metodę rysującą okrąg,
która będzie wykorzystywała przedstawiony w instrukcji algorytm rysowania okręgu.
Wykorzystaj 4-krotną lub 8-krotną symetrię. Zweryfikuj poprawność działania metody. Porównaj uzyskane rezultaty z tymi otrzymanymi z użyciem domyślnego algorytmu wbudowanego w bibliotekę graficzną

- Rozszerz funkcjonalność klasy PrimitiveRenderer o kolejną metodę rysującą elipsę
która będzie wykorzystywała przedstawiony w instrukcji algorytm rysowania elipsy.
Wykorzystaj 4-krotną lub 8-krotną symetrię. Zweryfikuj poprawność działania metody. Porównaj uzyskane rezultaty z tymi otrzymanymi z użyciem domyślnego algorytmu wbudowanego w bibliotekę graficzną.

- Rozszerz funkcjonalność klasy PrimitiveRenderer o metodę umożliwiającą narysowanie dowolnego wielokąta (łamanej zwyczajnej zamkniętej). Metoda ta powinna
przyjmować przez parametr zbiór punktów typu Point2D lub zbiór odcinków typu
LineSegment (np. na zasadzie obiektu klasy vector). Jeśli odcinki przecinają się,
metoda ta powinna przerwać swoje działanie bez rysowania czegokolwiek – mówimy
wówczas bowiem o łamanej wiązanej.

- Jeśli Twoja klasa PrimitiveRenderer nie umożliwia rysowania prymitywów wypełnionych kolorem, to rozszerz jej funkcjonalność w tym zakresie.

- Rozszerz funkcjonalność klasy PrimitiveRenderer o metody umożliwiające wypełnienie obszaru kolorem przez spójność. Jedna metoda powinna implementować
algorytm border fill, a druga flood fill. Zweryfikuj poprawność działania obu metod

- (Dla chętnych) Rozszerz funkcjonalność klasy PrimitiveRenderer o metodę umożliwiającą narysowanie dowolnego wielokąta wypełnionego kolorem. W tym celu zastosuj algorytm wypełniania obszaru kolorem z kontrolą parzystości. Zweryfikuj
poprawność działania metody.

### GAME ###
# 
- Zaimplementowac podstawowe transfomacje (2D)
- Poruszanie się po świecie,
  + Dodac testowy obiekt/klase gracza
  + Zrobic poruszanie WASD w jednym kierunku
  + Wstepna kolizja
  + Tilemap
  + Kamera ktora porusza sie za naszym graczem
  
- Ograniczona interakcja ze światem,
  + Kolizja postaci z mapa
- Przejście ze sceny świata do sceny walki,
  + Dodanie kilku wrogow
  + System walki 
- Podstawowe grafiki postaci i niektórych przeciwników.
- Zapisywanie swiata i wgrywanie
