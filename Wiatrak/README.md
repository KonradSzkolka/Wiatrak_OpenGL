# Wiatrak 3D

Prosty program demonstracyjny w C++/OpenGL prezentujący model biurkowego wiatraka z teksturami i prostą animacją.

## Najważniejsze cechy
- Renderowanie sceny 3D z użyciem GLUT i OpenGL.
- Animacja łopatek oraz oscylacja głowicy.
- Teksturowana podłoga i ściana (w katalogu `textures/`).
- Sterowanie klawiaturą dla prędkości, oscylacji i świateł.

## Szybkie uruchomienie
1. Upewnij się, że masz zainstalowany FreeGLUT / GLUT oraz OpenGL.
2. Otwórz projekt w Visual Studio 2022.
3. Zbuduj projekt i uruchom.

## Sterowanie
- `0` — wyłączenie wiatraka
- `1` — niski poziom
- `2` — średni poziom
- `3` — wysoki poziom
- `o` — przełączanie oscylacji głowicy
- `4` — przełącz światło 0 (górne)
- `5` — przełącz światło 1 (okno)
- Strzałki góra/dół — zmiana kąta pochylenia wiatraka
- `Esc` — zakończ

## Struktura repozytorium (ważne pliki)
- `main.cpp` — konfiguracja GLUT, główna pętla.
- `scene.cpp/h` — rysowanie sceny.
- `animation.cpp/h` — logika animacji.
- `input.cpp/h` — obsługa klawiatury.
- `init.cpp/h` — inicjalizacja OpenGL i świateł.
- `textures.cpp/h` — ładowanie tekstur (używa `stb_image.h`).

## Wymagania
- Kompilator obsługujący C++14.
- FreeGLUT lub inna implementacja GLUT.
