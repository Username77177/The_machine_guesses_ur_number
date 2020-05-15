#include "main_func.h"
#include <iostream>
#include <string>
#include <unistd.h>
// Не использую namespace std. Почему? Спросите сами! - @damnvirgins (Samantha
// xaris)
int main() {
  int x1 = 1;   // Начало по кд
  int x2 = 100; // Конец по кд
  int step = 0; // Кол-во шагов
  int number;

  std::string answer; // Переменная для ввода "<>="
  std::string again; // Переменная для ответа на предложение сыграть ещё раз

  while (true) {
    logo();
    settings(&x1, &x2); // Получение значений из настройки
    sleep(4); // Задержка экрана

    while (true) {
      if (x1 > x2) // Если пользователь нарочно/случайно обманет алгоритм
      {
        std::cout << "\n> U wanted to cheat the machine?\n> Try again\n> And "
                     "don't deceive me in the future please\n";
        step = 0;
        break;
      }

      step += 1; // Начинается алгоритм, + 1 шаг
      number = (x1 + x2) / 2; // Вычисляется середина

      logo();
      rules();

      std::cout << "> So. your number -- ";
      std::cout << number << "?\n";
      std::cout << "Input >> ";
      std::cin >> answer;

      if (answer == "=") // Если угадал
      {
        logo();
        std::cout << "\n\n----------------------------------";
        std::cout << "\n> your number -- "; // Вывод
        std::cout << number << "\n"; // Числа, которое было угадано
        std::cout << "> Number of steps -- "; // Вывод
        std::cout << step << "\n"; // шагов,за которое было найдено значение
        std::cout << "----------------------------------\n";

        while (true) // Цикл для неодократной игры
        {
          std::cout << "\n";
          std::cout << "\t\tU wanna play again? -- ";
          Yes_No();
          std::cout << "\nInput >> ";
          std::cin >> again;

          if (again == "y" || again == "y" || again == "yes" ||
              again == "yes") {
            step = 0; // Обнуляем шаги, т.к. играем ещё раз
            break;
          } else if (again == "N" || again == "n" || again == "No" ||
                     again == "no") {
            std::cout << "See u next time\n";
            exit(0);
          } else {
            continue; // Если были введены неверные данные - цикл прокрутится
                      // ещё раз
          }
        }
      } else if (answer == "<" || answer == ",") // Если загаданное число меньше
      {
        x2 = number - 1; // Двигаемся влево. т.е. x2 = 50 - 1, дальше уже пойдёт
                         // number = (1+49)/2 = 25.
        continue;
      } else if (answer == ">" || answer == ".") // Если число больше
      {
        x1 = number + 1; // Двигаемся вправо т.е. x1 = 50+1, дальше уже пойдёт
                         // number = (51+100)/2 = 75.
        continue;
      } else {
        step -= 1; // Чтобы не считался лишний шаг, ибо мы ничего не вычисляли
        continue;
      }
      break; // в этот break мы попадаем когда хотим ещё раз сыграть в игру
    }
  }

  return 0;
}
