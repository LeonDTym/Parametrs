#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>

using namespace std;

//base class
class Air_par {
public:
	virtual void pod()=0;
	
};

//sub_class
class Air_Temperature :public Air_par { 
public:
	
	
	void pod() override
	{ 
		ofstream fout("cppstudio.txt");
		
		cout << "Температура "; cin >> Temper;
		cout << Temper << endl;
		cout << "Перевести в Кельвин? " << endl;
		cout << "0 — нет\ 1 — да" << endl;
		cin >> x;
		switch (x)
		{
		case 0:
			break;

		case 1:
			Temper_K = Temper+273;
			cout << "Температура в Кельвиин " <<Temper_K<< endl;

			break;
		default:
			std::cout << "default case" << std::endl;
			break;
		}
		fout << "Температура " <<Temper<<endl ;
		fout << "Температура Кельвин " << Temper_K<<endl;
		fout.close();
	}
	
	int get_a() const
	{
		return Temper_K;
	}
	
private:double Temper,Temper_K;
	   int x;
};

//sub_class
class Air_Volume :public Air_par {
public:
	double V;

	/*friend ostream& operator<<(ostream& o, Air_Volume& x) {
		cout << "a= " << x.h << ", b= " << x.l << ", c= " << x.s;
 return o;
	}*/

	 void pod() override
	{ 
		/* ofstream ofs("text.txt", ios::binary);
		 ofs.write(reinterpret_cast<char*>(&V), sizeof(V));
		 ofs.close();
		 

		 if (!ifs) { cerr << "File not found"; return 1; }*/
		ofstream fout("cppstudio.txt",ios::app); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
		cout << "Введите стороны комнаты" << endl;
		cout << "H: "; cin >> h; 
		cout << "L: "; cin >> l;
		cout << "S: "; cin >> s;
		V = h*l*s;
		cout << "Объем комнаты V: " << V << endl; 
		fout << "Высота комнаты H:" << h << endl;
		fout << "Длина комнаты L:" << l << endl;
		fout << "Ширина комнаты S:" << s << endl;
		fout << "Объем:"<<V<<endl;
		fout.close(); // закрываем файл
		/*ifstream ifs("text.txt", ios::binary);
		ifs.read(reinterpret_cast<char*>(&V), sizeof(V));
		 ifs.close();
		 cout << "Vo1: " << V << "\n";*/
	
	/*	char buff[50]; // буфер промежуточного хранения считываемого из файла текста
		ifstream fin("cppstudio.txt"); // открыли файл для чтения

		fin >> buff; // считали первое слово из файла
		cout << buff << endl; // напечатали это слово

		fin.getline(buff, 50); // считали строку из файла
		fin.close(); // закрываем файл
		cout << buff << endl; // напечатали эту строку
*/
	}
	int get_a() const
		{
			return V;
		} 
	
			

private:double h,l,s;
};

//sub_class Volume
class Air_Mass :public Air_Volume {
public:
	
		
	void mass(const Air_Volume& V)  
	{
		ofstream fout("cppstudio.txt", ios::app);
		v = V.get_a();
		m = v * 1.29;
		cout << "Масса воздуха в комнате m: " << m << endl;
		fout << "Масса воздуха в комнате m:" << m << endl;
		fout.close(); // закрываем файл	
	}

private:double m,v;
};

//sub_class Temperature
class Air_Pressure :public Air_Temperature {
public:
	
	void pressure(const Air_Temperature& Temper_K, const Air_Volume& V)
	{
		ofstream fout("cppstudio.txt", ios::app);
		t = Temper_K.get_a();
		v= V.get_a();
		p = 29*8.314*t/v;
		cout << "Давление воздуха в комнате P: " << p << endl;
		fout << "Давление воздуха в комнате P:" << p << endl;
		fout.close(); // закрываем файл
	}

private:double v,t,p;
};

class Calculation
{
public:
	void pod(Air_par* calc)
	{
		calc->pod();
	}
	
};




/*	void SetLastName(string student_last_name)
	{
		last_name = student_last_name;
	}

	string GetLastName()
	{
		return last_name;
	}

	void SetScores(int student_scores[])
	{
		for (int i = 0; i < 5; i++)
		{
			scores[i] = student_scores[i];
		}
	}

	void CalcAverageBall()
	{
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum += scores[i];
		}
		average_ball = sum / 5.0;
	}

	float GetAverageBall()
	{
		return average_ball;
	}

private:
	int scores[5];
	float average_ball;
	
	string last_name;
};
*/

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

	Calculation calculation;
	Air_Temperature air;
	Air_Volume Vo,Vo1;
	Air_Mass Ma;
	Air_Pressure Pre;

	calculation.pod(&air);

	calculation.pod(&Vo);
	
	
	//Vo.pod();
	

	Ma.mass(Vo);
	Pre.pressure(air, Vo);


	
	


	
	/*string last_name;
	int n, a;
	int scores[5];
	//    float worst = 100, best = 0;
	cout << "Введите ср бал ";
	cin >> a;
	cout << "Введите кол-во студентов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Имя " << i + 1 << "-го" << " студента: ";
		cin >> Temper;

		cout << "Фамилия " << i + 1 << "-го" << " студента: ";
		cin >> last_name;

		for (int j = 0; j < 5; j++)
		{
			cout << j + 1 << "-ая" << " оценка: ";
			cin >> scores[j];
		}

		air.Temperature(Temper);
		 student.SetLastName(last_name);
		student.SetScores(scores);
	student.CalcAverageBall();
		//  cout << "Средний балл студента " << student.GetAverageBall() << endl;
		if (student.GetAverageBall() >= a)
			//   best = student.GetAverageBall();
			cout << " Средний балл " << student.GetAverageBall() << "; Фамилия и имя " << name << " " << last_name << ";" << endl;
		// << "Средний балл" << scores << ";" << endl;
		// if (student.GetAverageBall() < worst)
		  //   worst = student.GetAverageBall();
	}*/

	system("pause");
	return 0;
}
