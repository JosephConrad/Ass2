Zadanie 2: Śledzenie promieni (Rays' following)
=========

Należy napisać (oczywiście w asemblerze) program na proste śledzenie promieni używając instrukcji z rodziny SSE. Śledzenia promieni używamy do wytworzenia obrazu płaskiego na podstawie opisu obiektów znajdujących się w przestrzeni trójwymiarowej.

W naszym przypadku jedynymi obiektami będą kule. Każda kula posiada następujące atrybuty:

współrzędne środka: zakładamy, że wszystkie współrzędne są dodatnie i takie, że wszystkie punkty na powierzchniach kul mają dodatnie (lub nieujemne) współrzędne;
promień: zob. wyżej;
kolor, zapisany wewnętrznie w ulubionym formacie autora (jakieś RGB), a zewnętrznie podawany nazwą. Zakładamy, że powierzchnia kuli jest jednorodna.
Przyjmujemy, że dla promienia i współrzędnych środka wystarczą liczby rzeczywiste pojedynczej precyzji (float).
Płaszczyzna obrazu wyznaczona jest równaniem

z = 0.
Śledzenie promieni (w najprostszym przypadku) polega na wystawieniu z każdego punktu obrazu normalnej i znalezieniu przecięcia z najbliższym obiektem. Kolor znalezionego punktu przecięcia (czyli w tym przypadku jego kuli) staje się kolorem piksela na obrazie.

Program główny (napisany w C) powinien pobrać z pliku opis kul i przekazać go w jakiejś postaci procedurze w asemblerze wraz z pustą macierzą pikseli. Sygnatura procedury w asemblerze może więc być następująca

  void sztokfisz (kula_t *kule, pixel obraz[][], int szer, int wys);
Parametry szer i wys podają rozmiar tablicy obraz. Ewentualnie można dodać jeszcze parametr na liczbę kul.
Po powrocie z procedury asemblerowej program główny powinien wyświetlić policzony obraz.

Uwaga: nie wolno tworzyć obrazu metodą sortowania kul i rzutowania ich kolejno na płaszczyznę obrazu. Nie wolno korzystać z wątków itp., program ma być sekwencyjny.

Rozwiązania nie zawierające pliku Makefile nie będą sprawdzane.

Rozwiązania (program źródłowy i przykładowe pliki testowe z danymi) należy wysłać do dnia 17 grudnia (23:59) pocztą na zbyszek@mimuw.edu.pl jako pojedynczy załącznik -- archiwum o nazwie wskazującej na autora (np. ab123456-zad2.tgz), spakowane z osobnego katalogu o tej samej nazwie (ale bez tgz). Program ma działać w środowisku zainstalowanym w laboratoriach w trybie 64-bitowym.
