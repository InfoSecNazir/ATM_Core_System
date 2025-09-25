#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstring>
using namespace std;

struct StCilent
{
	string Acounter_Number;
	string PinCode;
	string Name;
	string Namber_Phone;
	float Balnce;
	bool MarkForDelete = false;

};

enum EnOption {
	enQiuce_Withdrawe=1,enNormal_Withdrawe=2,
	enDepostion = 3, enCheak_Balnce = 4,
	Log_Out = 5, enExit = 6
};

const string File_Name = "Cilent.txt";
StCilent Current_Cilent;


void Show_Main_Menue();
void Login();
void Show_Qiuce_Withdrawe();
void Show_Normal_Withdrawe();
void Show_Depostion();

string Read_Name(string Massage) {
	string Name;
	cout << Massage;
	cin >> Name;
	return Name;
}
short Read_Number(string Massage) {
	short Number;
	cout << Massage;
	cin >> Number;
	return Number;

}
char Read_Char(string Massage) {
	char a;
	cout << Massage;
	cin >> ws>>a;
	return a;
}
float Read_Float(string Massage) {
	float Number;
	cout << Massage;
	cin >> Number;
	return Number;
}

vector<string>Split_string(string s1, string Sparetor = "||") {
	string Word = "";
	size_t Pos = 0;
	vector<string>Vcilent;
	while ((Pos = s1.find(Sparetor)) != string::npos) {
		Word = s1.substr(0, Pos);


		if (Word != "")Vcilent.push_back(Word);


		s1.erase(0, Pos + Sparetor.length());
	}
	if (s1 != "")Vcilent.push_back(s1);


	return Vcilent;
}

StCilent Convert_String_to_Struct(string Line, string Sparetor = "||") {
	vector<string>Vcilent = Split_string(Line, Sparetor);
	StCilent Cilent;
	Cilent.Acounter_Number = Vcilent[0];
	Cilent.PinCode = Vcilent[1];
	Cilent.Name = Vcilent[2];
	Cilent.Namber_Phone = Vcilent[3];
	Cilent.Balnce = stof(Vcilent[4]);
	return Cilent;
}


string Convert_Struct_to_String(StCilent Cilent, string Sparetor = "||") {
	string Line = "";
	Line += Cilent.Acounter_Number + Sparetor;
	Line += Cilent.PinCode + Sparetor;
	Line += Cilent.Name + Sparetor;
	Line += Cilent.Namber_Phone + Sparetor;
	Line += to_string(Cilent.Balnce);
	return Line;
}


vector<StCilent>Load_Data_From_Faile(string Fill_Name) {
	vector<StCilent>Vcilent;
	fstream MyFile;
	MyFile.open(Fill_Name, ios::in);
	if (MyFile.is_open()) {
		string Line;
		StCilent Cilent;
		while (getline(MyFile, Line)) {
			Cilent = Convert_String_to_Struct(Line);
			Vcilent.push_back(Cilent);
		}
		MyFile.close();
	}



	return Vcilent;
}



bool Fiend_Cilent(string Acounter_Number, string PinDCode, StCilent& Cilent) {
	vector<StCilent>Vcilent = Load_Data_From_Faile(File_Name);
	for (StCilent& C : Vcilent) {
		if (C.Acounter_Number == Acounter_Number && C.PinCode == PinDCode) {
			Cilent = C;
			return true;
		}
	}
	return false;
}

vector<StCilent>Save_Data_on_File(string Fill_Name, vector<StCilent>& Vcilent) {
	fstream MyFile;
	MyFile.open(Fill_Name, ios::out);
	if (MyFile.is_open()) {
		for (StCilent& C : Vcilent) {
			if (C.MarkForDelete == false) {
				MyFile << Convert_Struct_to_String(C) << endl;
			}


		}
		MyFile.close();
	}
	return Vcilent;
}

bool Depostion(float Amount, string Acounter_Number, vector<StCilent>& Vcilent) {
	char Answer = 'n';
	Answer = Read_Char("Are You Sure You Want To Transhoine Opretion (y/n)? ");
	if (tolower(Answer) == 'y') {
		for (StCilent& C : Vcilent) {
			if (C.Acounter_Number == Acounter_Number) {
				C.Balnce += Amount;
				Save_Data_on_File(File_Name, Vcilent);
				cout << "Done!!Successfuly Depostion Your New Balnce is: " << C.Balnce << endl;
				return true;

			}
			 
		}
	}
	cout << "The Opretion Has Been Cancld" << endl;
	return false;
}

short Read_Quistion() {
	short Op = 0;
	while (Op> 9 || Op< 1) {
		Op = Read_Number("Please Enter The Option Number: ");
	}
	return Op;
}

short getQuickWithDrawAmount(short QuickWithDrawOption) {
	switch (QuickWithDrawOption) {
	case 1: return  20;
	case 2: return 50;
	case 3: return 100;
	case 4: return 200;
	case 5: return 400;
	case 6: return 600;
	case 7: return 800;
	case 8: return 1000;
	default: return 0;
	}
}

void Prefrome_Quice_Withdrawe_Option(short Op) {
	if (Op == 9)return;


	short Amount = getQuickWithDrawAmount(Op);

	if (Amount > Current_Cilent.Balnce) {
		cout << "The Amount Exide your Balnce ,Make Anouther Opertion " << endl;
		cout << "Pressy Any Key To Continue..." << endl;
		system("pause>0");
		Show_Qiuce_Withdrawe();
		return;
	}
	vector<StCilent>Vcilent = Load_Data_From_Faile(File_Name);
	Depostion(Amount * -1, Current_Cilent.Acounter_Number, Vcilent);
	Current_Cilent.Balnce -= Amount;


}

float Read_Depostion_Amount() {
	float Amount = 0;
	Amount = Read_Float("Please Enter The Amount You Want To Depostion: ");
	while(Amount <= 0) {
		cout << "The Amount Must Be Greater Than 0,Please Try Agin" << endl;
		Amount = Read_Float("Please Enter The Amount You Want To Depostion: ");
	}
	return Amount;
}

void Preform_Depostion() {
	float Amount = Read_Depostion_Amount();
	vector<StCilent>Vcilent = Load_Data_From_Faile(File_Name);
	Depostion(Amount, Current_Cilent.Acounter_Number, Vcilent);
	Current_Cilent.Balnce += Amount;


}


void Show_Depostion() {
	system("cls");
	cout << "===========================================\n";  
	cout << "\t\tDeposit Screen\n";     
	cout << "===========================================\n";
	Preform_Depostion();
}


void Show_Chake_Balnce_Screen() {
	system("cls"); 
	cout << "===========================================\n"; 
	cout << "\t\tCheck Balance Screen\n";     
	cout << "===========================================\n";
	cout << "The Current Balance is: " << Current_Cilent.Balnce << endl;


}
float Read_Withdarwe_Amount() {
	int Amount = Read_Float("Enter The Amount You Want To Withdraw of The 5 : ");

	while (Amount % 5 != 0) {
		Amount = Read_Float("Please Enter The Amount In The Multiples of 5: ");
	}
	return Amount;
}

void Perfrom_Withdrawe_Opetion() {
	int Amount = Read_Withdarwe_Amount();
	if (Amount > Current_Cilent.Balnce) {
		cout << "The Amount Exide your Balnce ,Make Anouther Opertion" << endl;
		cout << "Pressy Any Key To Continue..." << endl;
		system("pause>0");
		Show_Normal_Withdrawe(); return;

	}

	vector<StCilent>Vcilent = Load_Data_From_Faile(File_Name);
	Depostion(Amount * -1, Current_Cilent.Acounter_Number, Vcilent);
	Current_Cilent.Balnce -= Amount;




}
void Show_Normal_Withdrawe() {
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tWithdraw Screen\n";
	cout << "===========================================\n";
	Perfrom_Withdrawe_Opetion();

}

void Show_Qiuce_Withdrawe() {
	system("cls");
	cout << "\n==================================================================\n";
	cout << "\t\t\n Quick Withdrawl Amount";
	cout << "\n==================================================================\n";
	cout << "\n[1] 20$"; cout << "[2] 50$\t";
	cout << "[3] 100$\n"; cout << "[4] 200$\t";
	cout << "[5] 400$\n"; cout << "[6] 600$\t";
	cout << "[7] 800$\n"; cout << "[8] 1000$\t";
	cout << "Go back to main menu [9]\n";
	cout << "\n==================================================================\n";
	cout << "Your Balance is " << Current_Cilent.Balnce;

	Prefrome_Quice_Withdrawe_Option(Read_Quistion());
	

}


void Go_Bacek_To_Maneu() {
	cout << "Press Any Key To Go Back To Main Menu..." << endl;
	system("pause>0");
}

void Prefrom_Maneu_Option(EnOption Op) {
	switch (Op)
	{
	case enQiuce_Withdrawe:
		system("cls");
		Show_Qiuce_Withdrawe();
		Go_Bacek_To_Maneu();
		
		break;
	case enNormal_Withdrawe:
		system("cls");
		Show_Normal_Withdrawe();
		Go_Bacek_To_Maneu();
		break;
	case enDepostion:
		system("cls");
		Show_Depostion();
		Go_Bacek_To_Maneu();
		break;
	case enCheak_Balnce:
		system("cls");
		Show_Chake_Balnce_Screen();
		Go_Bacek_To_Maneu();
		break;
	case Log_Out:
		system("cls");
		Login();
		break;
	case enExit:
		exit(0);
		
		break;
	default:
		cout << "The Opretion Is Not Valid,Please Try Agin" << endl;
		break;

	}
}


void Show_Main_Menue() {
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tMain Menu\n";
	cout << "===========================================\n";
	cout << "[1] Quick Withdraw\n";
	cout << "[2] Normal Withdraw\n";
	cout << "[3] Deposit\n";
	cout << "[4] Check Balance\n";
	cout << "[5] Log Out\n";
	cout << "[6] Exit\n";
	Prefrom_Maneu_Option((EnOption)Read_Float("Please Enter The Option Number: "));
}


bool Load_CilentInfo(string Acounter_Number, string PinDCode) {
	return Fiend_Cilent(Acounter_Number, PinDCode, Current_Cilent);
}

void Login() {
	bool Login_Success = false;
	string Acounter_Number = "";
	string PinDCode = "";
	do {
		system("cls");
		cout << "===========================================\n";
		cout << "\t\tLogin Screen\n";
		cout << "===========================================\n";
		if (Login_Success) {
			cout << "Invoudle PineCode/Number_Acounter,Please Try Agine " << endl;

		}
		Acounter_Number = Read_Name("Please Enter Your Acounter Number: ");
		PinDCode = Read_Name("Please Enter Your Pin Code: ");
		Login_Success = !Load_CilentInfo(Acounter_Number, PinDCode);

	} while (Login_Success);
while(true)	Show_Main_Menue();

}

int main() {
	
		Login();
	
	return 0;
}


