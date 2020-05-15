#include <iostream>
#include <windows.h>
#include <cstring>
#include <stdio.h>

// �� ��������� namespace std. ������? �������� ����! - @damnvirgins (Samantha Xaris)

void Yes_No(); // ����������
void SetColor(int,int); // ������� ��������� ����� ������
void settings_logo(); // ����������
void logo(); // �������� ����
void rules(); // �������
int settings(int *,int *); // ������� ��� ��������� ����������� ��������


int main()  
{
	int x = 1; 
	int y = 100;
	int step = 0; // ���-�� �����
	int number; 
	
	std::string answer; // ���������� ��� ����� "<>="
	std::string again;  // ���������� ��� ������ �� ����������� ������� ��� ���
	
	while(true)
		{
			logo(); 
			settings(&x,&y); // ��������� �������� �� ���������
			Sleep(4000); // �������� ������
			
			while (true)
				{	
					if (x > y)               // ���� ������������ �������/�������� ������� ��������  
						{
							SetColor(4,0);
							std::cout << "\n> U wanted to cheat the machine?\n> Try again\n> And don't deceive me in the future please\n";
							SetColor(7,0);
							step=0;
							system("pause");
							system("cls");
							break;
						}
					
					step += 1; 								// ���������� ��������, + 1 ���
					number = (x+y) / 2;						// ����������� ��������
					
					system("cls");							// ������ ����� 
					logo();
					rules();
		
					std::cout << "> So. Your number -- ";
					SetColor(10,0);
					std::cout << number << "?\n";
					SetColor(14,0);
					std::cout << "Input >> ";
					std::cin >> answer;
					
					if (answer == "=")                     // ���� ������
						{
							system("cls");
							logo();
							SetColor(10,0);
							std::cout << "\n\n----------------------------------";
							std::cout << "\n> Your number -- ";  // �����
							SetColor(7,0);						 //
							std::cout << number << "\n";         // �����, ������� ���� �������
							SetColor(10,0);						 //-----------------------------
							std::cout << "> Number of steps -- "; // �����
							SetColor(7,0);						  // ���������� 
							std::cout << step << "\n";			  // �����,�� ������� ���� ������� ��������
							SetColor(10,0);
							std::cout << "----------------------------------\n";
							
							while (true) 					// ���� ��� ������������ ����
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
											step=0; // �������� ����, �.�. ������ ��� ���
											break;
										}
									else if(again == "N" || again == "n" || again == "No" || again == "no")
										{
											system("cls");
											SetColor(7,0);
											std::cout << "See u next time\n";
											system("pause");
											exit(0); // ������� �� ����.
										}
									else
										{
											continue; // ���� ���� ������� �������� ������ - ���� ����������� ��� ���
										}
								}
						}
					else if (answer == "<" || answer == ",") // ���� ���������� ����� ������
						{
							y = number - 1; 				// ��������� �����. �.�. y = 50 - 1, ������ ��� ����� number = (1+49)/2 = 25.
							continue;
						}
					else if (answer == ">" || answer == ".") // ���� ����� ������
						{
							x = number + 1; 				 // ��������� ������ �.�. x = 50+1, ������ ��� ����� number = (51+100)/2 = 75.
							continue;
						}
					else
						{
							step -=1; 					// ����� �� �������� ������ ���, ��� �� ������ �� ���������
							continue;
						}
					break; // � ���� break �� �������� ����� ����� ��� ��� ������� � ����
				}
		}
		
	return 0;
}


void Yes_No() // ������� ���������� ��� ��������
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
void SetColor(int text,int bg) // ������� ��� ������ � ������ ������ 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� ������ �� �������
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text)); // ������������� �������� ������
}
void settings_logo() // ����������
{
 SetColor(3,0);
 std::cout << "\n\t\t\t | SETTINGS |\n\n";
}
void logo() // �������� ����
{
	SetColor(14,0);
	std::cout << "\t\\ Game \'The machine guesses your number\' \\ \n";
}
void rules() // �������
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
int settings(int* a,int* b) // ������� ��� ��������� ����������� ��������, (�,b) - ������������ �������� 
{
	while (true)
	{
		std::string change; // ��� ������ �� ����������� �������� ��������
		std::string change_two; // ��� ������ �� ����������� ��������� ��������

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
		
			if (change == "Y" || change == "y" || change == "Yes" || change == "yes")  // ���� ����� ��������
				{
					while(true)
						{
							system("cls");
							logo();
							settings_logo();
							
							std::cout << "> Rules for change:"; 		  // ������� ��� ��������� ��������
							SetColor(11,0);
							std::cout << " (x < y) and (x != y)\n";	    // ��� ������ ���� ������ ������, � ����� �� �������� ��� 
							
							SetColor(14,0);
							std::cout << "\nInput x >> ";
							SetColor(7,0);
							std::cin >> *a;
							if (!std::cin)                       	// �������� �� ��� ������(int)
								{								   //
									std::cin.clear();			  // ������� ���� ������ cin
									fflush(stdin);				 // ����� ������
									continue;					// ��� ��� ���������� ��������
								}
							
							SetColor(14,0);
							std::cout << "Input y >> ";
							SetColor(7,0);
							std::cin >> *b;
							if (!std::cin)						// ���������� �������������� 
								{
									std::cin.clear();
									fflush(stdin);
									continue;
								}
							
							
							if (*a > *b || *a == *b)		// ���� ������������ �� ��������� ������� 
								{
									system("cls");
									continue;
								}
							
							else  					//	���� �� ���������� �� ��.
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
												std::cin >> change_two;  // ��������� ��������?
												
												if (change_two == "Y" || change_two == "y" || change_two == "Yes" || change_two == "yes") // �����������
													{
														return *a,*b;  // �������� ����������� � ���������� � �������� ���� ���������
													}
												else if (change_two == "N" || change_two == "n" || change_two == "No" || change_two == "no") // �� �����������
													{
														*a = 1;  // ���������� ��������� ��������� ��������
														*b = 100; // 
														system("cls");
<<<<<<< HEAD
=======
														logo();
>>>>>>> 467f82a31f46b2adf5c32d589c2ea4bba107c790
														break;
													}
												else   //  ��������� � ��.
													{
														system("cls");
														logo();
														continue;
													}
											}
								}
								break;
						}
				}
			else if (change == "N" || change == "n" || change == "No" || change == "no") // ���� �� ����� ��������
				{
					*a = 1;  	// ����������� ��������
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
					return *a,*b; // ������������ ������� � ����
				}
			else  // ���� �������� � ��
				{
					system("cls");
					logo();
					continue;	
				}
	}
}
		

