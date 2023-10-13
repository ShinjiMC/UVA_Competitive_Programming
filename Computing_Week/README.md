# E. La otra parte `E_La_Otra_Parte.cpp`
- time limit per test: 1s.
- memory limit per test: 256MB
- input: standard input
- output: standard output

En la UNSA, hay X semanas en cada semestre, El curso de "Introducción al anime" tiene Y clases cada semana, Z semanas han pasado y tu has asistido a exacatamente N hasta ahora. Se necesita **at least 60%** asistencia para dar el examen.
Calcula la cantidad mínima de clases a las que debes asistir en cada una de las semanas restantes para poder participar en el examen. Como eres un procrastinador, dejas la mayoría de las clases para asistir a las siguientes semanas.
## Input
La primera línea contiene cuatro enteros $X$ ($12 \leq X \leq 14$), $Y$ ($1 \leq Y \leq 5$), $Z$ ($1 \leq Z \leq X$) y $N$ ($0 \leq N \leq Y \times Z$).
## Output
Imprima **"Yes"** si es posible dar el examen o **"No"** si no es posible. Si es posible, en la segunda linea imprima $X−Z$ números (el número de clases que tendrás que asistir en las siguientes semananas para dar el examen).
## Example
- input
    ```bash
    14 3 10 15
    ```
- output
    ```bash
    Yes
    2 3 3 3
    ``` 