
// Yaðýzcem CENGÝZ
// 170757058
// Bilgisayar Mühendisliði
// 	BIM-104	Nesneye Yönelik Programlama , II. Dönem (II. yarýyýl)
// 	Proje1
//  Dr. Öðr. Üyesi Gülþah TÜMÜKLÜ ÖZYER


#include <iostream>
#include <cstdlib>
#include <stdlib.h> // rand fonksiyonu için gereken kütüphane.
#include <time.h>  // Rand fonskiyonun her seferinde farklý deðer döndürmesi için gereken kütüphane.
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
		
			// Tüm elemanlarý T olan matris oluþturma
			for(int i = 0; i < 6; i++)
			{
			for(int j = 0; j < 5; j++)
		    gameMat[i][j] = 'T';
				
			}	
	
			// Her satýr için rasgele 1 adet X (mayýn) oluþturma	
			for(int i = 0; i < 6; i++)
			{		
				randomcol = rand()%5;
				gameMat[i][randomcol] = 'X';
			}
	}

//---------------------------------------------------------------------------------------------------------------------------//

void creatingSelectMap()
	{
			// Kullanýcý seçimlerini tutacaðýmýz selectMat matrisinin tüm deðerlerini 0 (seçilmedi) olarak doldurma
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
	
			// Kullanýcýdan döngü içinde her satýr için sütun seçimi alma, ve seçilen satýr ve sütunu selectMat matrisinde 1 olarak deðiþtirme
			for(int i = 0; i < 6; i++)
			{
				cout << endl << i+1 << ". satir icin 1 - 5 arasinda bir sutun sayisi secin: ";
				cin  >> choice;
				
				if(choice == 'e' || choice == 'E' || choice == 'h' || choice == 'H')
					exit(0);
				
					
		
			if(choice >= 1 && choice <= 5) // Kullanýcýnýn girdiði deðerin 1-5 arasýnda olmasý kontrol ediliyor
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
			    	continue; // Kullanýcýnýn seçim yaptýðý konum deðeri T ise döngü devam ediyor ve yeni giriþ istiyor
			}
		 	else
				{		 
	 			cout << "\nUzgunum , mayina bastiniz. KAYBETTÝNÝZ ! \n";	
	 			printMap();
				break;	 // Kullanýcýnýn seçim yaptýðý konum deðeri T deðil ise (X) döngüden çýkýlýyor
			 
				} 	
			}
				else
				{
						cout << "\nYanlis bir rakam girdiniz. Lutfen 1 - 5 arasinda bir rakam giriniz. \n";
						i--; // Kullanýcý geçerli giriþ yapmadýysa ayný satýr için tekrar iþlem yapmak için i deðerini tekrar 1 azaltýyoruz
		 
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
