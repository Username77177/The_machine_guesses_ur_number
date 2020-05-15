#include <iostream>
#include <string>
#include <unistd.h>

void Yes_No() // Обычное оформление для удобства
{ // Оформление
  const std::string yOrN = "(Y)es or (N)o";
  std::cout << yOrN << std::endl;
}
void settings_logo() // Оформление
{ // Оформление
  std::cout << "\n\t\t\t | SETTINGS |\n\n";
}
void logo() // Название игры
{
  std::cout << "\t\\ Game \'The machine guesses your number\' \\ \n";
}
void rules() // Правила
{
  std::cout << "\n\t\t \\ Rules \\";
  std::cout << "\n--------------------------------------\n";
  std::cout << "> if your number is output, input \"=\"| \n";
  std::cout << "> if your number less - input \"<\"    | \n";
  std::cout << "> if your number more - input \">\"    | \n";
  std::cout << "--------------------------------------\n\n";
}
int settings(int* a,int* b) // Функция для изменения стандартных значений, (а,b) - передаваемые значения 
{
  while (true)
  {
    std::string change; // для ответа на предложение изменить значения
    std::string change_two; // для ответа на предложение сохранить значения

    settings_logo();

    std::cout << "> Default: from number ";
    std::cout << "1";
    std::cout << " to number ";
    std::cout << "100\n";

    std::cout << "> You want to change the values? -- ";
    Yes_No();
    std::cout << "\n\nInput >> ";
    std::cin >> change;

    if (change == "Y" || change == "y" || change == "Yes" || change == "yes")  // Если решит заменить
    {
      while(true)
      {
        logo();
        settings_logo();

        std::cout << "> Rules for change:"; 		  // Правила для изменения значений
        std::cout << " (x < y) and (x != y)\n";	    // икс должен быть меньше игрека, а также не равнятся ему 

        std::cout << "\nInput x >> ";
        std::cin >> *a;
        if (!std::cin)                       	// Проверка на тип данных(int)
        {								   //
          std::cin.clear();			  // очищаем флаг ошибки cin
          fflush(stdin);				 // Сброс буфера
          continue;					// Ещё раз спрашиваем значения
        }

        std::cout << "Input y >> ";
        std::cin >> *b;
        if (!std::cin)						// Аналогично вышеописанному 
        {
          std::cin.clear();
          fflush(stdin);
          continue;
        }


        if (*a > *b || *a == *b)		// Если пользователь не соблюдает правила 
        {
          continue;
        }

        else  					//	Если со значениями всё ОК.
        {
          while (true)
          {
            logo();
            settings_logo();

            std::cout << "> Your settings: from number ";
            std::cout << *a;
            std::cout << " to number ";
            std::cout << *b << "\n";
            std::cout << "> Save your settings? -- ";
            Yes_No();
            std::cout << "\n\nInput >> ";
            std::cin >> change_two;  // Сохранить значения?

            if (change_two == "Y" || change_two == "y" || change_two == "Yes" || change_two == "yes") // Соглашается на сохранение
            {
              return *a,*b;  // Значения сохраняются и передаются в основное тело программы
            }
            else if (change_two == "N" || change_two == "n" || change_two == "No" || change_two == "no") // Не соглашается на сохранение 
            {
              *a = 1;  // Переменные принимают дефолтные значения
              *b = 100; // 
              logo();
              break;
            }
            else   //  Миссклики и тд.
            {
              logo();
              continue;
            }
          }
        }
        break;
      }
    }
    else if (change == "N" || change == "n" || change == "No" || change == "no") // Если не решит заменять
    {
      *a = 1;  	// Стандартные значения
      *b = 100;	// 

      logo();
      settings_logo();
      std::cout << "> OK\n> Default: from number ";
      std::cout << "1";
      std::cout << " to number ";
      std::cout << "100\n";
      std::cout << "> Wait a second\n";
      return *a,*b; // Возвращаются обратно в тело
    }
    else  // Если миссклик и тд
    {
      logo();
      continue;	
    }
  }
}


