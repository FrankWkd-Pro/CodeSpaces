//By: FrankWKD × [将蓝]V
//This Project is Already Loaded the 'FCM' List.
//Please Not Copy and Reship.

#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

class variable_gather {
	//Variable Gather
	//Easy to find and fold. ^_^
public:
	int read_book;
	int ssize;
	int booksize;
	bool is_log = false;
	vector<string> user_data;
	struct Books {
		string name;
		string data[900010];
		int lines;
		int code;
		int pares;
		int max_p;
	} books[20];
	
};

class function_gather {
	//Function Gather
	//Easy to find and fold. ^_^
	public://Main Contents
	void FYYPlay();
	void FYYNote();
	void FYYBook();
	public://Update function and front function
	void part(string readp, int i);
	void Thanks();
	void LoadVCR();
	void declare();
//		void log_in();
//		void log_on();
	void init_data();
	void enter();
	public://'浮语云' Tools Library!
	void xor_encrypt_file(const std::string &input_filename, const std::string &output_filename, char key) ;
	void middle_output(char str[], int y);
	void definder_mode();
	void quicken_show();
	bool BackupFile(const char *srcPath, const char *dstPath) ;
	void Check_Backup();
	void gotoxy(int x, int y);//clear screen
	void ShowCursor() ;
	void HideCursor() ;
	void SetConsoleTextColor(WORD attributes) ;
	//SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
};
function_gather box;
variable_gather bag;

void function_gather::FYYPlay() {
	
}

void function_gather::Check_Backup() {
	char *aPath = "FYYCloud.cpp";
	char *bPath = "Backup.txt";
	if (box.BackupFile(aPath, bPath)) {
		std::cout << "File backed up successfully." << std::endl;
	} else {
		std::cerr << "Failed to back up file." << std::endl;
	}
	system("cls");
}

bool function_gather::BackupFile(const char *srcPath, const char *dstPath) {
	// 打开源文件
	HANDLE hSrcFile = CreateFile(srcPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hSrcFile == INVALID_HANDLE_VALUE) {
		std::cerr << "CreateFile failed (" << srcPath << ")" << std::endl;
		return false;
	}
	
	// 创建目标文件
	HANDLE hDstFile = CreateFile(dstPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hDstFile == INVALID_HANDLE_VALUE) {
		std::cerr << "CreateFile failed (" << dstPath << ")" << std::endl;
		CloseHandle(hSrcFile);
		return false;
	}
	
	// 读取源文件内容并写入目标文件
	const DWORD BUFFER_SIZE = 1024 * 1024; // 1MB buffer
	BYTE *buffer = new BYTE[BUFFER_SIZE];
	DWORD bytesRead;
	while (ReadFile(hSrcFile, buffer, BUFFER_SIZE, &bytesRead, NULL) && bytesRead > 0) {
		WriteFile(hDstFile, buffer, bytesRead, &bytesRead, NULL);
	}
	
	delete[] buffer;
	CloseHandle(hSrcFile);
	CloseHandle(hDstFile);
	
	return true;
}


void function_gather::FYYBook() {
	box.LoadVCR();
	system("cls");
	cout << ">>长安书城<<" << endl;
	system("cls");
	cout << "请输入书籍编号" << endl;
	for (int i = 1; i <= bag.booksize; i++) {
		cout << ">>Node: " << i << endl;
		cout << bag.books[i].name << endl;
	}
	
	int rread = getch() - '0';
	cout << "rread: " << rread << endl;
	for (int i = 1; i <= bag.booksize; i++) {
		cout << i << endl;
		if (rread == i) {
			bag.read_book = i;
			system("cls");
			cout << "你想阅读的书是: " << bag.books[bag.read_book].name << endl;
			cout << "请输入你想阅读的章节(MAX: " << bag.books[i].max_p << ")" << endl;
			string readp;
			cin >> readp;
			int num = atoi(readp.c_str());
			if (num > bag.books[i].max_p or num < 1) {
				cout << "404: Wrong Request." << endl;
				exit(404);
			} else {
				part(readp, i);
			}
		}
	}
	
	box.FYYBook();
}

void function_gather::part(string readp, int i) {
	for (int j = 1; j <= bag.books[i].lines; j++) {
		if (bag.books[i].data[j] == "Part" + readp) {
			for (int k = j; bag.books[i].data[k] != "#EOF"; k++) {
				cout << bag.books[i].data[k] << endl;
				++k;
				cout << bag.books[i].data[k] << endl;
				char readd = getch();
				if (readd == 'A') {
					system("cls");
					cout << "Part: " << readp << endl;
					cin >> readp;
					box.part(readp, i);
					exit(500);
				}
				if (readd == 'D') {
					system("cls");
					box.definder_mode();
				}
				if (readd == 'W')
					++k;
			}
		}
	}
}

void function_gather::FYYNote() {
	
}

void function_gather::declare() {
	system("cls");
	box.HideCursor();
	box.SetConsoleTextColor(FOREGROUND_GREEN);
	cout << "\n\n\n\n\n" << endl;
	box.middle_output("BY: FrankWKD × [将蓝]V", 0);
	box.middle_output("This Project is Already Loaded the 'FCM' List.", 1);
	box.middle_output("Please do not Copy or Reship.", 2);
	cout << endl;
	Sleep(3000);
	box.middle_output("请按任意键继续...", 3);
	if (getch() == 'F') {
		system("cls");
		cout << "Welcome!FrankWKD." << endl;
		getch();
	}
	box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	box.ShowCursor();
}

void function_gather::definder_mode() {
	system("cls");
	cout << "3 2 3" << endl;
	cout << "2 3 1" << endl;
	cout << "1 3 5" << endl;
	cout << "11 17 31" << endl;
	cout << "19 21" << endl;
	while (getch() != 'F') {
		char f;
		cin >> f;
	}
}

void local_gotoxy(HANDLE hOut, int x, int y) { //移动光标
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}

void function_gather::middle_output(char str[], int y) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y; //获取控制台屏幕缓冲区大小
	int len = strlen(str); //获取要输出的字符串的长度
	int x = dwSizeX / 2 - len / 2;
	local_gotoxy(hOutput, x, y); //移动光标
	cout << str;
}

void function_gather::LoadVCR() {
	box.HideCursor();
	system("cls");
	for (int i = 1; i <= 100; i++) {
		box.gotoxy(0, 0);
		srand(time(0));
		box.middle_output("F::Cloud", 0);
		box.middle_output("凌云阁 · 附语云", 1);
		box.SetConsoleTextColor(FOREGROUND_GREEN);
		box.middle_output("BY: FrankWKD × [将蓝]V", 2);
		box.middle_output("[转战]", 3);
		box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << endl;
		cout << "                                 Complete: " << i << "%" << endl << "        ";
		for (double j = 1; j <= 100; j += 1.5) {
			Sleep(0.1);
			if (i == 100) {
				box.SetConsoleTextColor(FOREGROUND_GREEN);
				cout << "▍";
				box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			} else if (j <= i) {
				box.SetConsoleTextColor(FOREGROUND_RED);
				cout << "▍";
				box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			} else {
				cout << "▍";
			}
		}
		cout << endl;
		
		Sleep((double)(rand() % 10 * i / 5));
		
		if (i <= 20)
			box.middle_output("Amost There...", 6);
		else if (i <= 40)
			box.middle_output("Loading Assets...", 6);
		
		else if (i <= 60)
			box.middle_output("Checking Update...", 6);
		else if (i < 100)
			box.middle_output("Parsing the Code...", 6);
	}
	cout << endl;
	box.middle_output("请按任意键继续...", 7);
	cout << endl;
	getch();
	box.ShowCursor();
	system("cls");
}

void function_gather::Thanks() {
	
	int y = 1;
	int is_show = 0;
	char read = -1;
	while (read != 'F') {
		
		if (read == 'd')
			y = (y + 1) % 6;
		if (y == 0)
			y++;
		if (read == 'S')
			is_show = (is_show + 1) % 2;
		
		system("cls");
		cout << ">>>>程序声明&特别鸣谢<<<<" << endl;
		cout << "d键控制，Shift + f退出，Shift + s查看详细内容" << endl;
		if (y == 1) {
			box.SetConsoleTextColor( FOREGROUND_GREEN );
			cout << ">>核心成员" << endl;
			if (is_show == 1) {
				cout << "BY: FrankWKD × [将蓝]V" << endl;
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-" << endl;
				cout << "FrankWKD: " << endl;
				cout << ">>>>Somewhere is sweety." << endl;
				cout << ">>>>裹着糖衣的药." << endl;
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-" << endl;
				cout << "[将蓝]V: " << endl;
				cout << ">>>>Love loves to love love." << endl;
				cout << ">>>>蓝途将晓." << endl;
			}
			box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		} else {
			cout << "核心成员" << endl;
		}
		if (y == 2) {
			box.SetConsoleTextColor( FOREGROUND_GREEN);
			cout << ">>此程序将列入<转战>计划" << endl;
			if (is_show == 1) {
				cout << "一身转战三千里，一剑曾当百万师." << endl;
				cout << "此计划为Team[WJT]的全系转型计划。" << endl;
				cout << "部分保密。" << endl;
				
			}
			box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		} else {
			cout << "此程序将列入<转战>计划" << endl;
		}
		if (y == 3) {
			box.SetConsoleTextColor( FOREGROUND_GREEN);
			cout << ">>制作团队&人员简介" << endl;
			if (is_show == 1) {
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-" << endl;
				cout << "<Team> Team[WJT] (Wang JL Team)" << endl;
				cout << ">>>1.FrankWKD(原FrankW) <Night_Live.>[Design][All]: 主队，主要策划" << endl;
				cout << ">>>2.lwj54joy <MAD>[Coder][Luogu]: 监制，码字" << endl;
				cout << ">>>3.Fyy <Flower-Dying>[Live][Unshown]: 支持，保障" << endl;
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-" << endl;
				cout << "<Team> [将蓝]M (M为更迭号码)" << endl;
				cout << ">>>Bob <Fire God.>[Design][CCW]: 方案，写文" << endl;
				cout << ">>>Tong · 将蓝 <Void>[Coder][luogu]: 码字，改Bugs" << endl;
				cout << ">>>L2y <Kill man,kill heart>[Live&Coder][Unshown]: 联系，前端设计&码字" << endl;
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-" << endl;
				cout << "外员：lbh，Jcx，Mkx部分人员参与内测" << endl;
			}
			box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		} else {
			cout << "制作人员&人员简介" << endl;
		}
		if (y == 4) {
			box.SetConsoleTextColor( FOREGROUND_GREEN);
			cout << ">>声明" << endl;
			if (is_show == 1) {
				cout << "This Project and other tools is already loaded the 'FCM' List." << endl;
				cout << "Please Not copy and reship." << endl;
				cout << "FrankWKD × [将蓝]V" << endl;
				cout << "First Version Update Time: 2024.7" << endl;
			}
			box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		} else {
			cout << ">>声明" << endl;
		}
		if (y == 5) {
			box.SetConsoleTextColor( FOREGROUND_GREEN);
			cout << ">>特别鸣谢" << endl;
			if (is_show == 1) {
				cout << "[晋江文学城][Zhihu][CSDN.blog][ccw.site][poki][MKX][Markdown][Luogu][gitblocks][GDBOnlineDebugger][DEVC++][owllook][li3zhi1yu2][kwling][turbowarp] "
				<< endl;
				cout << "FrankWKD × [将蓝]V" << endl;
			}
			box.SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		} else {
			cout << ">>特别鸣谢" << endl;
		}
		read = getch();
	}
	exit(500);
}

void function_gather::SetConsoleTextColor(WORD attributes) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, attributes);
}

void function_gather::gotoxy(int x, int y) { //clear screen
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	return ;
}

void function_gather::ShowCursor() {
	CONSOLE_CURSOR_INFO cur = {1, 1};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void function_gather::HideCursor() {
	CONSOLE_CURSOR_INFO cur = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void function_gather::enter() {
	box.LoadVCR();
	system("cls");
	cout << ">>F::Cloud<<" << endl;
	cout << ">>凌云阁 · 附语云<<" << endl;
	cout << "[1] 浮影·无边记" << endl;
	cout << "[2] 浮云·文学城" << endl;
	cout << "[3] 浮韵·玫娱乐" << endl;
	cout << "[4] 浮月·关于我们" << endl;
	char read = getch();
	if (read == 'A') {
		Check_Backup();
		exit(500);
	} else if (read != '1' and read != '2' and read != '3' and read != '4') {
		cout << "400: Wrong Request." << endl;
		exit(400);
	} else if (read == '1') {
		box.FYYNote();
	} else if (read == '2') {
		box.FYYBook();
	} else if (read == '3') {
		box.FYYPlay();
	} else if (read == '4') {
		Thanks();
	}
}

void function_gather::quicken_show() {
	cout << "Operating Quicken Input..." << endl;
	cin.tie(0);
	cout << "Operating Quicken Output..." << endl;
	cout.tie(0);
	cout << "Complete." << endl;
	system("cls");
}

void function_gather::xor_encrypt_file(const string &input_filename, const string &output_filename, char key) {
	
	
}
void function_gather::init_data() {
	int key = 1;
	ifstream file("Book_data.txt");//Only Read.
	cout << "Please Waiting..." << endl;
	box.Check_Backup();
	string line;
	if (!file.is_open()) {
		cout << "404: Not Found File." << endl;
		exit(404);
	}
	
	while (getline(file, line)) {
		bag.user_data.push_back(line);
		bag.ssize++;//总行数
	}
	int k = 1;
	for (int i = 0; i < bag.ssize; i++) {
		//cout << bag.user_data[i] << endl;
		if (bag.user_data[i] == "===" and i < bag.ssize) {//当读到分割行时
			bag.books[k].name = bag.user_data[i + 1];//书名设为下一行的内容
			bag.books[k].max_p = k;//更新最大章节数
			bag.books[k].code = k;//编码为k
			i += 2;
			int j;
			int z = 1;
			for ( j = i; bag.user_data[j] != "===" and j <= bag.ssize; j++) {
				bag.books[k].data[z] = bag.user_data[j];
				bag.books[k].lines = z;
				z++;
//				cout << bag.ssize << endl;//Shit!Mad!
			}
			k++;
		}
	}
	system("pause");
	system("cls");
	bag.booksize = k - 1;
	for (int i = 1; i <= k; i++) {
		cout << "Book Name: " << bag.books[i].name << endl;
		for (int j = 1; j <= bag.books[i].lines; j++) {
			cout << "----" << bag.books[i].data[j] << endl;
		}
	}
	system("pause");
	cout << "User Data File Opened Successful." << endl;
}
int main() {
	box.quicken_show();
	box.declare();
	box.init_data();
	box.enter();
	return 0;
}

