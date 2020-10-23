
// Ya��zcem CENG�Z
// 170757058
// Bilgisayar M�hendisli�i
// 	BIM-104	Nesneye Y�nelik Programlama , II. D�nem (II. yar�y�l)
// 	Proje1
//  Dr. ��r. �yesi G�l�ah T�M�KL� �ZYER


#include <iostream>
#include <cstdlib>
#include <stdlib.h> // rand fonksiyonu i�in gereken k�t�phane.
#include <time.h>  // Rand fonskiyonun her seferinde farkl� de�er d�nd�rmesi i�in gereken k�t�phane.
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
		
			// T�m elemanlar� T olan matris olu�turma
			for(int i = 0; i < 6; i++)
			{
			for(int j = 0; j < 5; j++)
		    gameMat[i][j] = 'T';
				
			}	
	
			// Her sat�r i�in rasgele 1 adet X (may�n) olu�turma	
			for(int i = 0; i < 6; i++)
			{		
				randomcol = rand()%5;
				gameMat[i][randomcol] = 'X';
			}
	}

//---------------------------------------------------------------------------------------------------------------------------//

void creatingSelectMap()
	{
			// Kullan�c� se�imlerini tutaca��m�z selectMat matrisinin t�m de�erlerini 0 (se�ilmedi) olarak doldurma
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
	
			// Kullan�c�dan d�ng� i�inde her sat�r i�in s�tun se�imi alma, ve se�ilen sat�r ve s�tunu selectMat matrisinde 1 olarak de�i�tirme
			for(int i = 0; i < 6; i++)
			{
				cout << endl << i+1 << ". satir icin 1 - 5 arasinda bir sutun sayisi secin: ";
				cin  >> choice;
				
				if(choice == 'e' || choice == 'E' || choice == 'h' || choice == 'H')
					exit(0);
				
					
		
			if(choice >= 1 && choice <= 5) // Kullan�c�n�n girdi�i de�erin 1-5 aras�nda olmas� kontrol ediliyor
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
			    	continue; // Kullan�c�n�n se�im yapt��� konum de�eri T ise d�ng� devam ediyor ve yeni giri� istiyor
			}
		 	else
				{		 
	 			cout << "\nUzgunum , mayina bastiniz. KAYBETT�N�Z ! \n";	
	 			printMap();
				break;	 // Kullan�c�n�n se�im yapt��� konum de�eri T de�il ise (X) d�ng�den ��k�l�yor
			 
				} 	
			}
				else
				{
						cout << "\nYanlis bir rakam girdiniz. Lutfen 1 - 5 arasinda bir rakam giriniz. \n";
						i--; // Kullan�c� ge�erli giri� yapmad�ysa ayn� sat�r i�in tekrar i�lem yapmak i�in i de�erini tekrar 1 azalt�yoruz
		 
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
