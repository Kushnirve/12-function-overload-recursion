#include <iostream>
#include <iomanip>
#include <random>
#include <windows.h>
using namespace std;

//1.1
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
void init(int* arr, int m, int n)
{
	for (int i = 0; i < m; i++)	for (int j = 0; j < n; j++)	*((arr + i * n) + j) = rand() % 100;
}

void init(double* arr, int m, int n)
{
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) *((arr + i * n) + j) = rand() % 100 * 0.9997;
}

void init(char* arr, int m, int n)
{
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) *((arr + i * n) + j) = char('a' + rand() % ('z' - 'a'));
}

void out(int* arr, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)	cout << setw(3) << *((arr + i * n) + j);
		cout << endl;
	}
}

void out(double* arr, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)	cout << setw(8) << *((arr + i * n) + j);
		cout << endl;
	}
}

void out(char* arr, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)	cout << setw(3) << *((arr + i * n) + j);
		cout << endl;
	}
}

void min_max(int* arr, int m, int n)
{
	int min, max;
	min = *(arr); max = *(arr);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				if (min > * ((arr + i * n) + j)) min = *((arr + i * n) + j);
				if (max < *((arr + i * n) + j)) max = *((arr + i * n) + j);
			}
		}
	}
	cout << "int Min " << min << " int Max " << max << endl;
}

void min_max(double* arr, int m, int n)
{
	double min, max;
	min = *(arr); max = *(arr);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				if (min > * ((arr + i * n) + j)) min = *((arr + i * n) + j);
				if (max < *((arr + i * n) + j)) max = *((arr + i * n) + j);
			}
		}
	}
	cout << "double Min " << min << " double Max " << max << endl;
}

void min_max(char* arr, int m, int n)
{
	char min, max;
	min = *(arr); max = *(arr);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				if (min > * ((arr + i * n) + j)) min = *((arr + i * n) + j);
				if (max < *((arr + i * n) + j)) max = *((arr + i * n) + j);
			}
		}
	}
	cout << "char Min " << min << " char Max " << max << endl;
}

void row_sort(int* arr, int l, int r)
{
	int i = l, j = r;
	int temp, p;
	p = *(arr + (l + r) / 2); // центральный элемент
		// процедура разделения
	do {
		while (*(arr + i) < p) i++;
		while (*(arr + j) > p) j--;
		if (i <= j) {
			temp = *(arr + i);
			*(arr + i) = *(arr + j);
			*(arr + j) = temp;
			i++;
			j--;
		}
	} while (i <= j);
	// рекурсивные вызовы, если есть, что сортировать
	if (i < r) row_sort((int*)(arr), i, r);
	if (j > l) row_sort((int*)(arr), l, j);
}

void row_sort(double* arr, int l, int r)
{
	int i = l, j = r;
	double temp, p;
	p = *(arr + (l + r) / 2); // центральный элемент
		// процедура разделения
	do {
		while (*(arr + i) < p) i++;
		while (*(arr + j) > p) j--;
		if (i <= j) {
			temp = *(arr + i);
			*(arr + i) = *(arr + j);
			*(arr + j) = temp;
			i++;
			j--;
		}
	} while (i <= j);
	// рекурсивные вызовы, если есть, что сортировать

	if (i < r) row_sort((double*)(arr), i, r);
	if (j > l) row_sort((double*)(arr), l, j);
}

void row_sort(char* arr, int l, int r)
{
	int i = l, j = r;
	char temp, p;
	p = *(arr + (l + r) / 2); // центральный элемент
		// процедура разделения
	do {
		while (*(arr + i) < p) i++;
		while (*(arr + j) > p) j--;
		if (i <= j) {
			temp = *(arr + i);
			*(arr + i) = *(arr + j);
			*(arr + j) = temp;
			i++;
			j--;
		}
	} while (i <= j);
	// рекурсивные вызовы, если есть, что сортировать
	if (i < r) row_sort((char*)(arr), i, r);
	if (j > l) row_sort((char*)(arr), l, j);
}
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888


//1.2
int EvklidNOD(unsigned int a, unsigned int b) {
	if (a == b) return a;
	if (a > b) return EvklidNOD(b, a - b);
	return EvklidNOD(a, b - a);
}


//1.3
void BikKorova(int num[], int steps) {
	int p_num[4];
	int win = 0;
	for (int i = 0; i < 4; i++) {
		cin >> p_num[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (p_num[i] == num[i]) {
				cout << "Корова ";
				i++;
				win++;
			}
			else if (p_num[j] == num[i]) cout << "Бык  ";
		}
	}
	steps++;
	if (win == 4) {
		cout << "\nВы выиграли за " << steps << " попыток" << endl;
		exit(1);
	}
	BikKorova(num, steps);
}


//2.1
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
// размеры доски
int const board_size = 64;
int board_width = sqrt(board_size);
// для записи ходов
int moves[board_size];
int moves2[board_size];
// если пронумеровать доску числами, можно заметить, что разница между начальной и конечной точками
// хода коня будет давать числа, 8 вариантов хода:
int jump[8] = { 6, 10, 15, 17, -6, -10, -15, -17 };
// поиск был ли уже такой ход
bool search(int array[], int size, int key) {
	for (int i = 0; i < size; i++) if (array[i] == key) return true;
	return false;
}
// проверки возможен ли ход:
// 1. нет ли выхода за доску
// 2. был ли уже такой ход
// 3. проверка правильности прыжка, разница начала и конца не может быть больше 2 рядов
bool check(int cell, int i) {
	if ((cell + jump[i]) >= board_width + 1 && (cell + jump[i]) <= board_width * (board_width + 1) && (!search(moves, board_size, cell + jump[i])) && (abs((((cell % board_width) == 0) ? board_width : (cell % board_width)) - (((cell + jump[i]) % board_width == 0) ? board_width : (cell + jump[i]) % board_width)) <= 2)) return true;
	return false;
}
// подсчет количества возможных ходов
int warnsdorf(int cell) {
	int counter = 0;
	for (int i = 0; i < 8; i++) if (check(cell, i)) counter++;
	return counter;
}
// Правило Варнсдорфа
// Конь следует на то поле, с которого можно пойти на минимальное число ещё не пройденных полей.
// Если таких полей несколько, то можно пойти на любое из них.
int jumps(int cell) {
	int future_moves[8]; // для хранения количества будущих ходов
	int min = 7;
	int jump_type;
	for (int i = 0; i < 8; i++) {
		// находим количество будущих ходов для каждого возможного варианта хода коня
		if (check(cell, i)) future_moves[i] = warnsdorf(cell + jump[i]);
		// проверяем какой следующий ход дал минимальное число будущих ходов
		if (future_moves[i] < min && future_moves[i] > 0) {
			min = future_moves[i];
			jump_type = i;
		}
		// последний ход
		if (min == 7) for (int i = 0; i < 8; i++) if (check(cell, i)) jump_type = i;
	}
	// делаем текущий ход
	cell = cell + jump[jump_type];
	return cell;
}
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

//2.3
void TicTacToe(int field[], int counter, int sign_id) {
	int cords;
	// отрисовка
	for (int i = 0; i < 9; i++) {
		if (field[i] == 0) cout << "  |";
		if (field[i] == 10) cout << "x |";
		if (field[i] == 1) cout << "o |";
		if ((i + 1) % 3 == 0 and i != 0) cout << endl;
	}
	cin >> cords;
	system("cls");
	// определяем чей ход
	if (counter % 2 == 0) sign_id = 10; else sign_id = 1;
	if (9 >= cords - 1) { // введены правильные координаты, не больше поля
		if (field[cords - 1] == 10 or field[cords - 1] == 1) { // проверяем можно ли ходить в это поле, занято ли оно
			cout << "Неверный ход" << endl;
			TicTacToe(field, counter, sign_id);
		}
		field[cords - 1] = sign_id; // когда ход успешен, запись значка  игрока в поле
		counter++; // переключаем игрока
	}
	int wins[8][3] = { 0,1,2, 3,4,5, 6,7,8, 0,4,8, 2,4,6, 0,3,6, 1,4,7, 2,5,8 };
	int win = 0;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 3; i++) {
			win += field[wins[j][i]];
			if (win == 30) cout << " x выиграл" << endl; else if (win == 3) cout << " o выиграл" << endl;
		}
		win = 0;
	}
	TicTacToe(field, counter, sign_id);
}

int main() {


	setlocale(0, "rus");

	//1.1
	const int m = 3, n = 5;
	int arr_i[m][n];
	double arr_d[m][n];
	char arr_c[m][n];

	init((int*)arr_i, m, n);
	init((double*)arr_d, m, n);
	init((char*)arr_c, m, n);
	out((int*)arr_i, m, n);
	out((double*)arr_d, m, n);
	out((char*)arr_c, m, n);
	min_max((int*)arr_i, m, n);
	min_max((double*)arr_d, m, n);
	min_max((char*)arr_c, m, n);
	row_sort((int*)arr_i, 0, 4);
	out((int*)arr_i, m, n);
	row_sort((double*)arr_d, 5, 9);
	out((double*)arr_d, m, n);
	row_sort((char*)arr_c, 10, 14);
	out((char*)arr_c, m, n);

	//1.2
	int a =7, b=11;
	cout << EvklidNOD(a, b);

	//1.3
	int steps = 0;
	int num[4] = { 8,9,0,1 };
	BikKorova(num, steps);


		//2.1
		//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
		int cell; cout << "Введите номер стартовой клетки 1-64: "; cin >> cell;
		// в алгоритме для удобства клетки перенумеровываются со смещением +8
		// т.е. вместо 1-64 -> 9-72
		cell = cell + 8;
		// главный цикл
		for (int i = 0; i < board_size; i++) {
			// записываем в ячейки по очереди номер клетки
			// если первый ход в клетку 64(72) то будет записано moves[0]=72
			moves[i] = cell;
			// записываем в нужную ячейку номер хода
			// если первый ход в клетку 64(72) то будет записано moves2[63]=1
			moves2[cell - 9] = i + 1;
			// передаем стартовую клетку в основную функцию
			if (i < 63) cell = jumps(cell);
			// для записи последнего хода
			if (i == 63) moves[63] = cell;
			// вывод вариант 1
			system("cls");
			for (int i = board_width + 1; i <= board_width * (board_width + 1); i++) {
				// выводим пустую ячейку
				if (!search(moves, board_size, i)) cout << "  |";
				// выводим ячейку с числом меньше 10
				else if (i < 10) cout << "\x1b[36m " << i << "\x1b[37m|";
				// выводим ячейку с числом
				else cout << "\x1b[36m" << i << "\x1b[37m|";
				// выводим конец ряда
				if (i % board_width == 0) cout << endl;
			}
			Sleep(800);
		}
		// вывод вариант 2 в виде последовательности ходов по номерам клеток
		for (int i = 0; i < board_size; i++) cout << moves[i] << "->";
		cout << endl;
		// вывод вариант 3 по ходам
		for (int j = 0; j < board_width; j++) {
			for (int i = 0; i < board_width; i++) {
				if (moves2[j * board_width + i] < 10) cout << " " << moves2[j * board_width + i] << "|";
				else cout << moves2[j * board_width + i] << "|";
			}
			cout << endl;
		}
		//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

	//2.2
		
		const int rows = 4;
		const int cols = 4;
		int arr[rows][cols];
		int x0, y0;
		int steps;
		char direction;
	
		vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
		random_device random_dev;
		mt19937       generator(random_dev());
		shuffle(vec.begin(), vec.end(), generator);
	
		string arr1[8] =
		{
	"           /$$ / $$$$$     ",
	"          | $$| $$___/     ",
	"          | $$| $$         ",
	"          | $$\\  $$$$     ",
	"          | $$    | $$     ",
	"          | $$ ___/ $$ шки ",
	"          | $$/ $$$$$  v.0.999    ",
	"          |__/|______/  \n "
		};
	
	
		for (int i = 0; i < 8; i++) {
			cout << arr1[i] << endl;
		}
		cout << "By Kushnirve 2020" << endl;
		cout << "For donats: " << endl;
	
	
		// генерация массива
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				arr[i][j] = vec[i + j * rows];
				if (vec[i + j * rows] == 0) { y0 = i; x0 = j; }
				cout << setw(3) << arr[i][j];
			}
			cout << endl;
		}
	
		while (true) {
			cout << "Братан! Правила довольно просты!" << endl;
			cout << "Гоняй нолик (влево l, вправо r, вверх u, вниз d), например 2l" << endl;
			cin >> steps >> direction;
	
			switch (direction) {
			case 'r':
				if (x0 + steps < 4) {
					for (int s = 0; s < steps; s++) {
						swap(arr[y0][x0], arr[y0][x0 + 1]);
						x0++;
					}
				}
				else cout << "Неверный ход" << endl;
				break;
			case 'l':
				if (x0 - steps >= 0) {
					for (int s = 0; s < steps; s++) {
						swap(arr[y0][x0], arr[y0][x0 - 1]);
						x0--;
					}
				}
				else cout << "Неверный ход" << endl;
				break;
			case 'u':
				if (y0 - steps >= 0) {
					for (int s = 0; s < steps; s++) {
						swap(arr[y0][x0], arr[y0 - 1][x0]);
						y0--;
					}
				}
				else cout << "Неверный ход" << endl;
				break;
			case 'd':
				if (y0 + steps < 4) {
					for (int s = 0; s < steps; s++) {
						swap(arr[y0][x0], arr[y0 + 1][x0]);
						y0++;
					}
				}
				else cout << "Неверный ход" << endl;
				break;
			}
	
			// вывод на экран
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << setw(3) << arr[i][j];
				}
				cout << endl;
			}
		}
	


	//2.3
	int counter = 2, sign_id = 10;
	int field[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	TicTacToe(field, counter, sign_id);


}
