#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int read_org,saver,nums/*�½�����*/,la;
string filename = "article.txt",uname = "UKE",ver = "ver.Lts.02.08.19";
//01:������Ŀ��02:��ȫ�Դ��+�������Ѻ�
string backTimeNow(){// ��ȡ��ǰʱ���  
	std::time_t currentTime = std::time(nullptr);  
	
	// ��ʱ���ת��Ϊ����ʱ��  
	std::tm* localTime = std::localtime(&currentTime);  
	
	// ��ʽ�����ں�ʱ���ַ���  
	char buffer[32];  
	std::snprintf(buffer, sizeof(buffer),  
		"%04d��-%02d��-%02d�� %02d:%02d:%02d",  
		1900 + localTime->tm_year,  
		1 + localTime->tm_mon,  
		localTime->tm_mday,  
		localTime->tm_hour,  
		localTime->tm_min,  
		localTime->tm_sec);  
	
	// �����ַ���  
	return string(buffer);  
}  
void crx_luck(){
	cout<<"������������������������������������\n";
	srand(time(0)*1000);
	la = rand()%1000+1;
	cout<<"<<"<<backTimeNow()<<">>"<<endl;
	if(la <= 100){
		cout<<"���ƣ�����ס�\n";
	}else if(la <= 300){
		cout<<"���ƣ����ס�\n";
	}else if(la <= 700){
		cout<<"���ƣ���С����\n";
	}else if(la <= 900){
		cout<<"���ƣ����м���\n";
	}else if(la <= 1000){
		cout<<"���ƣ���󼪡�\n";
	}
	cout<<"������������������������������������\n";
}

// ���½ṹ��
struct article{
	string aname,atime,creater;
	string contents[10000];//�½�����
	int lines_num;//�½������к�
}dataa[1010];//�½�

// ��ȡ��������
void getFileData() {
	cout<<"�鼮·��(����aΪĬ�����ݿ�)��"<<endl;
	cout<<"���棺������λ�ö�ȡ����Ϣ�Ḳ�����ݿ�������δ��������ݣ�"<<endl;
	string filep;
	cin>>filep;
	if(filep != "a") filename = filep;
	cout<<"���ڶ�ȡ��������..."<<endl;
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "�ļ���ʧ��!(�����ļ�Ϊ���ļ����������)" << endl;
		getch();
		return ;
	}
	string line;
	bool is = false;
	cout<<"�Ƿ���������ģʽ��(��ʱ�������ǿ��Լ���鼮����) ��a����"<<endl;
	if(getch() == 'a') is = true;
	while (getline(file, line)) {
		if(is) cout<<line<<"\n";
		if(line == "#EOF"){
			break;//Ψһֹͣ�������
		}if(line[0] == '<'){
			getline(file,line);
			dataa[++nums].aname = line;
			getline(file,line);
			dataa[nums].atime = line;
			getline(file,line);
			dataa[nums].creater = line;
		}else{
			dataa[nums].lines_num++;
			dataa[nums].contents[dataa[nums].lines_num] = line;
		}
	}
	cout<<"�鼮�����ѳɹ�����"<<endl;
	file.close();
}

// ������������
void saveFileData() {
	fstream file(filename/*,ios::app*/);
	for(int i=1;i<=nums;i++){
		file<<dataa[i].aname<<endl;
		file<<dataa[i].atime<<endl;
		file<<dataa[i].creater<<endl;
		for(int j = 1;j <= dataa[i].lines_num;j++) file<<dataa[i].contents[j]<<endl;
	}
	file<<"#EOF\n";
	cout<<"����ɹ�."<<endl;
	file.close();
}

// ����½�
void writeFileData() {
	cout<<"���ڶ�ȡ����..."<<endl;
	getFileData();	
	cout<<"���."<<endl;
	string lcreator, ltitle, ldate;
	cout << "���봴����: ";
	cin>>dataa[++nums].creater;
	cout << "����������: ";
	cin>>dataa[nums].aname;
	cout << "����ʱ��: ";
	cin>>dataa[nums].atime;
	cout<<"�������½�����(���ö������룬�����������#EOF����)"<<endl;
	string lines_ = "";
	while(lines_ != "#EOF"){
		dataa[nums].lines_num++;
		dataa[nums].contents[dataa[nums].lines_num] = lines_;
		cin>>lines_;
	}
	cout<<"�ѱ��浽���ݿ�."<<endl;
	if(read_org == 0){
		cout<<"�Ƿ񱣴浽����? 1��2��"<<endl;
		if(getch() == '1') saveFileData();
	}else if(read_org == 1) saveFileData();
	
	cout << "�½���ӳɹ�!" << endl;
}

void newBook(){
	string name;
	cout<<"�ļ���(�Ӻ�׺)��";
	cin>>name;
	ofstream createFile(name);
	cout<<"�ѳɹ�������Ϊ ["<<name<<"] ���ļ�"<<endl;
}

void loadFile(int k){
	system("cls");
	cout<<"����a�������ģʽ������> Unlock <������ص���ǰ����\n";
	cout<<"�����������ʼ."<<endl;
	getch();
	cout<<"-------------\n";
	for(int i = 0;i <= dataa[k].lines_num;i++){
		cout<<dataa[k].contents[i]<<endl;
		if(getch() == 'a'){
			system("cls");
			cout<<"3\n1 2 3 4 5\n2 4 1 3 5\n6 4 2 5 4"<<endl;
			string k;
			cin>>k;
			while(k != "Unlock"){
				cin>>k;
			}
			for(int j = 0;j <= i;j++){ 
			//	cout<<dataa[k].contents[i]<<endl;
			}
		}
	}
	cout<<"-------------\n";
	cout<<"������ϡ���ǰ�½�Ϊ��"<<k<<"�ţ�������Ҫ�����½ڱ�ţ�Ϊ-1��ȡ��"<<endl;
	cin>>k;
	if(k > 0 and k <= nums) loadFile(k);
}

void lookBook(){
	cout<<"���ڶ�ȡ����..."<<endl;
	getFileData();
	cout<<"���."<<endl;	
	cout<<"�����������Ķ����½ڵı��"<<endl;
	for(int i = 1;i <= nums;i++) cout<<"��� ["<<i<<"] ���½� ["<<dataa[i].aname<<"] ������ ["<<dataa[i].atime<<"] ���� ["<<dataa[i].creater<<"]"<<endl;
	int k;
	cin>>k;
	if(k < 1 or k > nums) cout<<"��������!"<<endl;
	else loadFile(k);
}

void settings(){
	cout<<"�Զ����浽���ع��ܴ���";
	if(read_org == 1) cout<<"����״̬"<<endl;
	else if(read_org == 2) cout<<"�ر�״̬"<<endl;
	else cout<<"ʹ��ʱѯ��"<<endl;
	cout<<"��[1]����"<<endl;
	if(getch() == '1'){
		cout<<"����������Ҫ��Ϊ��ֵ(1/2/0)"<<endl;
		int k;
		cin>>k;
		read_org = k%3;
	}
	return ;
}

void thanks(){
	system("cls");
	cout<<"<�ѹر�Դ��>"<<endl;
	cout<<"����"<<endl;
	cout<<"�˳����������ص����ļ�ΪFrankWKDԭ��!\n�˴�ΪΨһ���ʹ����������ű𴦵������޸�!\n";
	cout<<"��ƣ�FrankWKD"<<endl;
	cout<<"������FrankWKD"<<endl;
	cout<<"�κ��˲���ʹ�ô˴��롣"<<endl;
	cout<<"ע������"<<endl;
	cout<<"�����ڱ༭Դ�ļ���ͬʱ���б����򣬳��ֵĴ�������˸Ų�����"<<endl;
	cout<<"��������������������������������������������\n����1��ת��������ҳ������2��ת�Ŷ�\n";
	char k = getch();
	if(k == '1') system("start https://www.luogu.com.cn/user/845400");
	else if(k == '2') system("start https://www.luogu.com.cn/team/80686");
	Sleep(100000);
	exit(0);
}

void main_() {
	do {
		system("cls");
		cout<<"Ծ����16.6�� - BY FrankWKD"<<endl;
		cout<<ver<<endl;
		cout<<"��ӭ������"<<uname<<"!\n";
		crx_luck();
		cout << "1. ��������" << endl;
		cout << "2. ׫д����" << endl;
		cout << "3. �鿴����" << endl;
		cout << "4. �������/���¶�������" << endl;
		cout << "5.����"<<endl;
		cout<<"6.[�ؿ�] ����"<<endl;
		char k;
		k = getch();
		system("cls");
		if(k == '1'){
			newBook();
		}else if(k == '2'){
			writeFileData();
		}else if(k == '3'){
			lookBook();
		}else if(k == '4'){
			cout<<"��Ҫ��������밴[1]���������밴[2]��������ȡ��"<<endl;
			cout<<"���棺����������ζ�����ᶪʧ����δ���������! "<<endl;
			char t = getch();
			if(t == '1') saveFileData();
			else if(t == '2') getFileData();
		}else if(k == '5'){
			settings();
		}else if(k == '6'){
			thanks();
		}
		Sleep(500);
	} while (1);
}

void BackupFile(const char *srcPath, const char *dstPath) {
	// ��Դ�ļ�
	std::ifstream  src(srcPath, std::ios::binary);
	std::ofstream  dst(dstPath,   std::ios::binary);
	string line;
	while(getline(src,line)){
		dst<<encrypt(line)<<"\n";
	}
	cout<<"�ɹ������ļ�Դ�ļ�����.";
}
void Build_File_NameData(const char *a,const char* b){
	CopyFile(a , b , FALSE);
	cout<<"�汾�����ļ���¼���."<<endl;
}
/*ASCII��ת��Ϊ�����ƺ���*/string deciToBin(int deci){                                //10����ת2���ƺ���
	string hexStr(8, ' ' );
	int Value = 0,i = 0;
	for (; deci != 0; ++i, deci /= 2){
		Value = deci % 2;
		hexStr.at(i) =  Value + '0';
	}
	hexStr = hexStr.substr(0, i);
	reverse(hexStr.begin(), hexStr.end());
	if (hexStr.length() < 8){
		string add( 8 - hexStr.length(), '0');
		hexStr = add + hexStr;
	}
	return hexStr;
}
/*����*/string encrypt(const string in){                //���ܺ���
	int i = 0;                            //�ܵĿ��Ʊ���
	int k = 0;                          //24λ(4��6λ)���Ʊ���
	const int n = in.length();     //���������г���
	string subs;                        //Ҫ��Ӧ������Ӵ�
	string out;                        //�������ַ���
	string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");       //��Ӧ�ַ�
	
	while (n - i >= 24){           //���������������ֽ�
		for (k = 0; k < 4; ++k){
			subs = in.substr( i + k * 6, 6);            //ȡ��6λ
			int sum = 0,j = 0;
			for (auto & x : subs){
				sum += (x - '0') * pow(2, 5 - j);
				++j;
			}                                                                            //�õ��±�
			out +=  value.at(sum);                                          //�����Ӧ�ַ�
		}
		i += 24;                                                                    //ǰ��24λ
		if ( i % 76 == 0) cout << endl;
	}
	if ( i != n) {                                                                      //����ʣ�µĲ���24λ����{
		int charlen;                                              //ʣ�µĳ���
		if ((n - i) % 6 == 0) charlen = (n - i) / 6;
		else charlen = (n - i) / 6 + 1;
		for (k = 0; k < charlen; ++k){
			subs = in.substr( i + k * 6, i + (k + 1) * 6 - 1);            //ȡ��6λ
			int sum = 0;
			int j = 0;
			for (auto & x : subs){
				sum += (x - '0') * pow(2, 5 - j);
				++j;
			}                                                                            //�õ��±�
			out +=  value.at(sum);                                            //�����Ӧ�ַ�
		}
		if ((n - i) % 16 == 0) out += "=";
		else out += "==";
	}

	return out;
}
/*����*/string decrypt(const string in){
	string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"),out0,out1,deciToBin_6bit(int);
	for( auto x = in.cbegin(); (*x) != '=' && x != in.cend(); ++x)    //�ų��Ⱥ�
		out0 += deciToBin_6bit(value.find(*x));
	const int n = out0.length();
	for(int i = 0; i < n; i += 8){           //ÿ8λ��ȡһ��
		string subs = out0.substr(i, 8);    //��ȡ8λ
		int j = 0,sum = 0;
		for(auto &x : subs){
			sum += (x - '0') * pow(2, 7 - j);
			++j;
		}                                   //��Ȩչ�����õ�ASCII��
		out1 += static_cast<char>(sum);     //ת��Ϊ��Ӧ�ַ�
	}
	return out1;
}
void get_todo(string k){
	
}
void autoLogIn(){
	string pathL;
	cout<<"�˻���ַ��";
	cin>>pathL;
	ifstream fileL(pathL);
	string dataL[10];
	string lL;
	int i = 0;
	while(getline(fileL,lL)){
		dataL[++i] = lL;
	}
	fileL.clear();
	fileL.close();
	cout<<"���ܵ�¼��"<<endl;
	cout<<"�û���: "<<dataL[2]<<endl;
	dataL[3] = decrypt(dataL[3].substr(1));
	cout<<"���룺"<<dataL[2]<<endl;
	cout<<"������֤�뼴������ͬ��˳��򱾴�ʹ��������Ϣ."<<endl;
	srand(time(0)*100);
	string x,k = to_string(rand());
	cout<<"��������֤�� ["<<k<<"]\n";
	cin>>x;
	if(x != k){
		cout<<"��֤�����.���ܵ�¼ʧ��."<<endl;
		exit(0);
	}else{
		cout<<"��������ȷ�����ĵ�¼����..."<<endl;
		cout<<"����ܻ�ķ�һЩʱ��..."<<endl;
		uname = dataL[2];
		get_todo(uname+"todo.exe");
		cout<<"��ȷ��."<<endl;
		cout<<"���ڽ��ж�̬����..."<<endl;
		fstream writeF(pathL);
		srand(time(0)/5);
		int kkey = rand()%9+1;
		writeF <<endl<< uname <<endl<<to_string(kkey) + encrypt(dataL[2])<<endl;
		cout<<"���."<<endl;
		cout<<"�밴���������..."<<endl;
		getch();
		cout<<"������ת..."<<endl;
		writeF.close();
	}
}

void Regist(){
	string p,pass;
	cout<<"�����˻����ļ������ַ:";
	cin>>p;
	ofstream cre(p);
	cout<<"�û�����";
	cin>>uname;
	cout<<"���룺";
	cin>>pass;
	cre << endl<<uname<<endl<<"0"<<pass<<endl;
	cout<<"�����ɹ�!��������Ч!"<<endl;
	exit(0);
}

void login(){
	system("cls");
	cout<<"Ծ����16.6�� - BY FrankWKD"<<endl;
	cout<<ver<<endl;
	//cout<<"�뱣֤���ĵ�����Win7������ϵͳ����ʹ��WindowsAPI�ӿڣ�����˳����޷��������С�"<<endl;
	//cout<<"����ɾ���˳��������ļ����е��κ����ݣ�����Ը�!"<<endl;
	//cout<<"�������ŵ����������ʱ���뻥�����ұ�֤����ɼ������κ���Ϣ!"<<endl;
	cout<<"������������������������������������������������������������������������\n";
	cout<<"1.��¼"<<endl;
	cout<<"2.ע��"<<endl;
	char k;
	k = getch();
	if(k == '1'){
		autoLogIn();
		main_();
	}else if(k == '2'){
		Regist();
	}
	exit(0);
}

void SetConsoleTextColor(WORD attributes) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, attributes);
}
void gotoxy(int x, int y) { //clear screen
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	return ;
}
void ShowCursor() {
	CONSOLE_CURSOR_INFO cur = {1, 1};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cur = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
void local_gotoxy(HANDLE hOut, int x, int y) { //�ƶ����
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut, pos);
}
void middle_output(char str[], int y) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y; //��ȡ����̨��Ļ��������С
	int len = strlen(str); //��ȡҪ������ַ����ĳ���
	int x = dwSizeX / 2 - len / 2;
	local_gotoxy(hOutput, x, y); //�ƶ����
	cout << str;
}

void declare() {
	system("cls");
	HideCursor();
	int k = rand(),i = 0;
	while(i <= 6){
		Sleep(30*(k%10));
		srand(time(0)/k);
		k = rand();
		if(k % 7 == 0) SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		if(k % 7 == 1) SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		if(k % 7 == 2) SetConsoleTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if(k % 7 == 3) SetConsoleTextColor(FOREGROUND_BLUE);
		if(k % 7 == 4) SetConsoleTextColor(FOREGROUND_RED);
		if(k % 7 == 5) SetConsoleTextColor(FOREGROUND_GREEN);
		if(k % 7 == 6) SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		middle_output("<<-< FYY::Cloud >->>",9);
		if(i == 0) Sleep(1000);
		middle_output(">> ReadingCorner_�ö���16.6�� <<",10);
		if(i == 0) Sleep(1000);
		middle_output("[Designed BY]: FrankWKD", 12);
		middle_output("[Made BY]: FrankWKD", 13);
		if(i == 0) Sleep(2000);
		middle_output("CopyRight (C)2024, Continue Service", 14);
		cout << endl;
		if(i == 0) Sleep(1000);
		Sleep(k%100);
		SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		i++;
	}
	Sleep(3000);
	ShowCursor();

}
void LoadVCR() {
	HideCursor();
	system("cls");
	for (int i = 1; i <= 100; i++) {
		gotoxy(0, 0);
		srand(time(0));
		middle_output("FYY::Cloud", 0);
		middle_output("Ծ����16.6��", 1);
		SetConsoleTextColor(FOREGROUND_GREEN);
		middle_output("Designed BY: FrankWKD  ", 2);
		middle_output("Made BY: FrankWKD  ", 3);
		SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << endl;
		cout << "                                 Complete: " << i << "%" << endl << "        ";
		for (double j = 1; j <= 100; j += 1.5) {
			Sleep(0.1);
			if (i == 100) {
				SetConsoleTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "��";
				SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			} else if (j <= i) {
				SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "��";
				SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			} else {//��
				cout << "��";
			}
		}
		
		Sleep((double)(rand() % 10 * i / 5));
		if (i <= 20)
			middle_output("Amost There...", 7);
		else if (i <= 40)
			middle_output("Loading Assets...", 7);
		else if (i <= 60)
			middle_output("Checking Update...", 7);
		else if (i < 100)
			middle_output("Parsing the Code...", 7);
	}
	cout << endl;
	middle_output("�밴���������...", 7);
	cout << endl;
	getch();
	ShowCursor();
	system("cls");
}

int main(){
	//system("rundll32.exe user32.dll,LockWorkStation");
	string skp = "Ծ����16.6��" + ver + "_Code.exe";
	BackupFile("Ծ����16.6��_Latest.cpp",skp.c_str());
	cout<<"\nSystem: [INIT]Press [1] To Backup Running File.\nThis Operation Will Cost at Least 1,000KB\n[Now Version]: "<<ver<<endl;
	if(getch() == '1'){
		skp = "Ծ����16.6��" + ver + "_APP.exe";
		Build_File_NameData("Ծ����16.6��_Latest.exe",skp.c_str());
		system("cls");
	}
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	declare();
	LoadVCR();
	cout<<"Ծ����16.6��"<<endl;
	cout<<"By FrankWKD - "<<ver<<endl;
	login();
}

