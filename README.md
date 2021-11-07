# Project_Engine

# ----Do zrobienia ----#

### ENGINE ###
# Wlasna opcja na pozniej jak starczy czasu... 
- Zaimplementuj Bresenham's Algorithm
- Zaimplementuj Wu's Algorithm
# //


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

- Zaimplementowac podstawowe transfomacje (2D)
- Lista objektow na danej scenie oraz lista scen.

### GAME ###
#
 
- JSON dodac do projektu
- JSON zapis/ wcyztanie podstawowego configu/opcji
- Zaimplementowac podstawowe transfomacje (2D)
- Poruszanie się po świecie (velocity)
  + Dodac testowy obiekt/klase gracza
  + Zrobic poruszanie WASD w jednym kierunku
  + Kamera ktora porusza sie za naszym graczem
- Tilemaps
- Wstepna kolizja


- Ograniczona interakcja ze światem,
  + Kolizja postaci z mapa
- Przejście ze sceny świata do sceny walki,
  + Dodanie kilku wrogow
  + System walki 
- Podstawowe grafiki postaci i niektórych przeciwników.
- Zapisywanie swiata i wgrywanie
