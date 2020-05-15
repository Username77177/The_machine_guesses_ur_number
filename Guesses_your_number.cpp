#include <iostream>
#include <windows.h>
#include <cstring>
#include <stdio.h>

// Не использую namespace std. Почему? Спросите сами! - @damnvirgins (Samantha Xaris)

void Yes_No(); // Оформление
void SetColor(int,int); // Функция настройки цвета текста
void settings_logo(); // Оформление
void logo(); // Название игры
void rules(); // правила
int settings(int *,int *); // Функция для изменения стандартных значений


int main()  
{
	int x = 1; 
	int y = 100;
	int step = 0; // Кол-во шагов
	int number; 
	
	std::string answer; // Переменная для ввода "<>="
	std::string again;  // Переменная для ответа на предложение сыграть ещё раз
	
	while(true)
		{
			logo(); 
			settings(&x,&y); // Получение значений из настройки
			Sleep(4000); // Задержка экрана
			
			while (true)
				{	
					if (x > y)               // Если пользователь нарочно/случайно обманет алгоритм  
						{
							SetColor(4,0);
							std::cout << "\n> U wanted to cheat the machine?\n> Try again\n> And don't deceive me in the future please\n";
							SetColor(7,0);
							step=0;
							system("pause");
							system("cls");
							break;
						}
					
					step += 1; 								// Начинается алгоритм, + 1 шаг
					number = (x+y) / 2;						// Вычисляется середина
					
					system("cls");							// Очищаю экран 
					logo();
					rules();
		
					std::cout << "> So. Your number -- ";
					SetColor(10,0);
					std::cout << number << "?\n";
					SetColor(14,0);
					std::cout << "Input >> ";
					std::cin >> answer;
					
					if (answer == "=")                     // Если угадал
						{
							system("cls");
							logo();
							SetColor(10,0);
							std::cout << "\n\n----------------------------------";
							std::cout << "\n> Your number -- ";  // Вывод
							SetColor(7,0);						 //
							std::cout << number << "\n";         // Числа, которое было угадано
							SetColor(10,0);						 //-----------------------------
							std::cout << "> Number of steps -- "; // Вывод
							SetColor(7,0);						  // количества 
							std::cout << step << "\n";			  // шагов,за которое было найдено значение
							SetColor(10,0);
							std::cout << "----------------------------------\n";
							
							while (true) 					// Цикл для неодократной игры
								{
									std::cout << "\n";
									SetColor(7,0);
									system("pause");
									system("cls");
									std::cout << "\t\tU wanna play again? -- ";
									Yes_No();
									SetColor(14,0);
									std::cout << "\nInput >> ";
									SetColor(7,0);
									std::cin >> again;
									
									if (again == "Y" || again == "y" || again == "Yes" || again == "yes")
										{
											system("cls");
											step=0; // Обнуляем шаги, т.к. играем ещё раз
											break;
										}
									else if(again == "N" || again == "n" || again == "No" || again == "no")
										{
											system("cls");
											SetColor(7,0);
											std::cout << "See u next time\n";
											system("pause");
											exit(0); // Выходим из игры.
										}
									else
										{
											continue; // Если были введены неверные данные - цикл прокрутится ещё раз
										}
								}
						}
					else if (answer == "<" || answer == ",") // Если загаданное число меньше
						{
							y = number - 1; 				// Двигаемся влево. т.е. y = 50 - 1, дальше уже пойдёт number = (1+49)/2 = 25.
							continue;
						}
					else if (answer == ">" || answer == ".") // Если число больше
						{
							x = number + 1; 				 // Двигаемся вправо т.е. x = 50+1, дальше уже пойдёт number = (51+100)/2 = 75.
							continue;
						}
					else
						{
							step -=1; 					// Чтобы не считался лишний шаг, ибо мы ничего не вычисляли
							continue;
						}
					break; // в этот break мы попадаем когда хотим ещё раз сыграть в игру
				}
		}
		
	return 0;
}


void Yes_No() // Обычное оформление для удобства
{
	SetColor(7,0);
	std::cout << "(";
	SetColor(10,0);
	std::cout << "Y";
	SetColor(7,0);
	std::cout << ")es/(";
	SetColor(12,0);
	std::cout << "N";
	SetColor(7,0);
	std::cout << ")o";
}
void SetColor(int text,int bg) // Функция для работы с цветом текста 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор вывода на консоль
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text)); // Устанавливаем атрибуты текста
}
void settings_logo() // Оформление
{
 SetColor(3,0);
 std::cout << "\n\t\t\t | SETTINGS |\n\n";
}
void logo() // Название игры
{
	SetColor(14,0);
	std::cout << "\t\\ Game \'The machine guesses your number\' \\ \n";
}
void rules() // Правила
{
	SetColor(11,0);
	std::cout << "\n\t\t \\ Rules \\";
	std::cout << "\n--------------------------------------\n";
	std::cout << "> if your number is output, input \"=\"| \n";
	std::cout << "> if your number less - input \"<\"    | \n";
	std::cout << "> if your number more - input \">\"    | \n";
	std::cout << "--------------------------------------\n\n";
	SetColor(7,0);
}
int settings(int* a,int* b) // Функция для изменения стандартных значений, (а,b) - передаваемые значения 
{
	while (true)
	{
		std::string change; // для ответа на предложение изменить значения
		std::string change_two; // для ответа на предложение сохранить значения

		settings_logo();
		
		std::cout << "> Default: from number ";
		SetColor(10,0);
		std::cout << "1";
		SetColor(3,0);
		std::cout << " to number ";
		SetColor(10,0);
		std::cout << "100\n";
		SetColor(3,0);
		
		std::cout << "> You want to change the values? -- ";
		Yes_No();
		SetColor(14,0);
		std::cout << "\n\nInput >> ";
		SetColor(7,0);
		std::cin >> change;
		
			if (change == "Y" || change == "y" || change == "Yes" || change == "yes")  // Если решит заменить
				{
					while(true)
						{
							system("cls");
							logo();
							settings_logo();
							
							std::cout << "> Rules for change:"; 		  // Правила для изменения значений
							SetColor(11,0);
							std::cout << " (x < y) and (x != y)\n";	    // икс должен быть меньше игрека, а также не равнятся ему 
							
							SetColor(14,0);
							std::cout << "\nInput x >> ";
							SetColor(7,0);
							std::cin >> *a;
							if (!std::cin)                       	// Проверка на тип данных(int)
								{								   //
									std::cin.clear();			  // очищаем флаг ошибки cin
									fflush(stdin);				 // Сброс буфера
									continue;					// Ещё раз спрашиваем значения
								}
							
							SetColor(14,0);
							std::cout << "Input y >> ";
							SetColor(7,0);
							std::cin >> *b;
							if (!std::cin)						// Аналогично вышеописанному 
								{
									std::cin.clear();
									fflush(stdin);
									continue;
								}
							
							
							if (*a > *b || *a == *b)		// Если пользователь не соблюдает правила 
								{
									system("cls");
									continue;
								}
							
							else  					//	Если со значениями всё ОК.
								{
									while (true)
											{
												system("cls");
												logo();
												settings_logo();
												
												std::cout << "> Your settings: from number ";
												SetColor(10,0);
												std::cout << *a;
												SetColor(3,0);
												std::cout << " to number ";
												SetColor(10,0);
												std::cout << *b << "\n";
												SetColor(3,0);
												std::cout << "> Save your settings? -- ";
												Yes_No();
												SetColor(14,0);
												std::cout << "\n\nInput >> ";
												SetColor(7,0);
												std::cin >> change_two;  // Сохранить значения?
												
												if (change_two == "Y" || change_two == "y" || change_two == "Yes" || change_two == "yes") // Соглашается
													{
														return *a,*b;  // Значения сохраняются и передаются в основное тело программы
													}
												else if (change_two == "N" || change_two == "n" || change_two == "No" || change_two == "no") // Не соглашается
													{
														*a = 1;  // Переменные принимают дефолтные значения
														*b = 100; // 
														system("cls");
														logo();
														settings_logo();
														std::cout << "> OK\n> Default: from number ";
														SetColor(10,0);
														std::cout << "1";
														SetColor(3,0);
														std::cout << " to number ";
														SetColor(10,0);
														std::cout << "100\n";
														SetColor(3,0);
														std::cout << "> Wait a second\n";
														return *a,*b; // И передаются обратно в тело
													}
												else   //  Миссклики и тд.
													{
														system("cls");
														logo();
														continue;
													}
											}
								}		
						}
				}
			else if (change == "N" || change == "n" || change == "No" || change == "no") // Если не решит заменять
				{
					*a = 1;  	// Стандартные значения
					*b = 100;	// 
					
					system("cls");
					logo();
					settings_logo();
					std::cout << "> OK\n> Default: from number ";
					SetColor(10,0);
					std::cout << "1";
					SetColor(3,0);
					std::cout << " to number ";
					SetColor(10,0);
					std::cout << "100\n";
					SetColor(3,0);
					std::cout << "> Wait a second\n";
					return *a,*b; // Возвращаются обратно в тело
				}
			else  // Если миссклик и тд
				{
					system("cls");
					logo();
					continue;	
				}
	}
}
		
