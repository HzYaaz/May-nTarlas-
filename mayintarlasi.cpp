
// Yağızcem CENGİZ


#include <iostream>
#include <cstdlib>
#include <stdlib.h> // rand fonksiyonu için gereken kütüphane.
#include <time.h>  // Rand fonskiyonun her seferinde farklı değer döndürmesi için gereken kütüphane.
using namespace std;

char gameMat[6][5];
char selectMat[6][5];

void printMap()
	{
		int i , j;
			for(i = 0; i < 6; i++)
			{	
				cout << "\n";
				
					for(j = 0; j < 5; j++)
		
					if(selectMat[i][j] == '0')
						 cout << "  " << gameMat[i][j];
					else
						cout << "  " << 'O';		
			}
	}
	
 void creatingMap()
   {
		int randomcol;
		srand(time(NULL));
		
			// Tüm elemanları T olan matris oluşturma
			for(int i = 0; i < 6; i++)
			{
			for(int j = 0; j < 5; j++)
		    gameMat[i][j] = 'T';
				
			}	
	
			// Her satır için rasgele 1 adet X (mayın) oluşturma	
			for(int i = 0; i < 6; i++)
			{		
				randomcol = rand()%5;
				gameMat[i][randomcol] = 'X';
			}
	}

//---------------------------------------------------------------------------------------------------------------------------//

void creatingSelectMap()
	{
			// Kullanıcı seçimlerini tutacağımız selectMat matrisinin tüm değerlerini 0 (seçilmedi) olarak doldurma
	  		for(int i = 0; i < 6; i++)
			{
	    		for(int j = 0; j < 5; j++)
	  			selectMat[i][j] = '0';
			}
	}
	
//---------------------------------------------------------------------------------------------------------------------------//
	
void afterSelect()
	{
		int i , j;
			for(i = 0; i < 6; i++)
			{	
				cout << "\n";
				
				for(j = 0; j < 5; j++)
		
				if(selectMat[i][j] == '1')
					cout << "  " <<gameMat[i][j];
				else
					cout << "  " << '*';		
			}
	}
		
//---------------------------------------------------------------------------------------------------------------------------//	
		
void Start()
	{
		
		int i, choice;
	
		creatingMap();
		creatingSelectMap();	
	
			// Kullanıcıdan döngü içinde her satır için sütun seçimi alma, ve seçilen satır ve sütunu selectMat matrisinde 1 olarak değiştirme
			for(int i = 0; i < 6; i++)
			{
				cout << endl << i+1 << ". satir icin 1 - 5 arasinda bir sutun sayisi secin: ";
				cin  >> choice;
				
				if(choice == 'e' || choice == 'E' || choice == 'h' || choice == 'H')
					exit(0);
				
					
		
			if(choice >= 1 && choice <= 5) // Kullanıcının girdiği değerin 1-5 arasında olması kontrol ediliyor
			{
			    selectMat[i][choice-1] = '1';
	   			afterSelect();
	   			
	 		if (gameMat[i][choice - 1] == 'T')
	 		{	 			
	 			if(i == 5)
	 			{
	 				cout << endl <<"\n Tebrikler oyunu KAZANDINIZ. \n";	
	 				printMap();
				}
			    	continue; // Kullanıcının seçim yaptığı konum değeri T ise döngü devam ediyor ve yeni giriş istiyor
			}
		 	else
				{		 
	 			cout << "\nUzgunum , mayina bastiniz. KAYBETTİNİZ ! \n";	
	 			printMap();
				break;	 // Kullanıcının seçim yaptığı konum değeri T değil ise (X) döngüden çıkılıyor
			 
				} 	
			}
				else
				{
						cout << "\nYanlis bir rakam girdiniz. Lutfen 1 - 5 arasinda bir rakam giriniz. \n";
						i--; // Kullanıcı geçerli giriş yapmadıysa aynı satır için tekrar işlem yapmak için i değerini tekrar 1 azaltıyoruz
		 
				}			
		   }
	}
	//---------------------------------------------------------------------------------------------------------------------------//
	
	void gameQuestion()
   {
		char answer;
		
		while(1)
		{
			cout << "\nYeniden Oynamak Ister Misiniz ? (Evet icin e/E , Hayir icin h/H giriniz): ";
			cin  >> answer;
			
			if(answer == 'e' || answer == 'E')
			{
				Start();
			}			
			else if(answer == 'h' || answer == 'H')
			{
				break;
			}
			else
			{
				cout << "\ne/E veya h/H harflerinden birini giriniz.\n";
				
			}
		}
	//---------------------------------------------------------------------------------------------------------------------------//
	
   }

int main()
{
		Start();
		gameQuestion();
	
	return 0;
}
