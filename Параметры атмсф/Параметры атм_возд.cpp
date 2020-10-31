#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Air_par {
public:
	 
}; //base class

class Air_Temperature :public Air_par { //sub_class
public:
	//air composition

	void Temperature(double temperature_in_room)
	{
		Temper = temperature_in_room;
	}

	double GetName()
	{
		return Temper;
	}
private:double Temper;
};


class Air_Volume :public Air_par {
public:
	//air composition

	void Volume(double h_room, double l_room, double s_room)
	{ 
		
		double V = h_room*l_room*s_room;
		cout <<"V: "<< V;
	}

	double GetName()
	{
		
		return V;
	}
private:double V;
		
};

class obiom: public Air_Volume{};








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
	
	double Temper,h,l,s; 

	Air_Temperature air;
	cout << "Температура ";
	cin >> Temper;
	air.Temperature(Temper);
	cout << Temper<<endl;

	Air_Volume Vo;
	cout << "H: "; cin >> h;
	cout << "L: "; cin >> l;
	cout << "S: "; cin >> s;
	Vo.Volume(h,l,s);
	
	
	
	
	
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
