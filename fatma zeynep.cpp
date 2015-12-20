#include <iostream>
#include <stdlib.h>
# include <string.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 

//Ki�i tan�ml� oldu�u ana s�n�f�
class Kisi
{

private:
Char Adi[ 20 ]; // �zel de�i�kenleri
char Soyadi[ 20 ] ;
char Numarasi[ 12 ] ;

public:
void UpdateName ( char * YeniAd ); // genel y�ntemleri
void UpdateSurname ( char * YeniSoyad ) ;
void UpdateNumber ( char * YeniNumara ) ;
void DisplayRecord ( ) ;
char *GetName ( ) ;
char *GetSurname ( ) ;

};

void Kisi :: UpdateName ( char * YeniAd )
{
strcpy (Adi ,YeniAd ) ;
}

void Kisi :: UpdateSurname ( char * YeniSoyad )
{
strcpy ( Soyadi , YeniSoyad ) ;
}

void Kisi :: UpdateNumber ( char * YeniNumara )
{
strcpy ( Numarasi , YeniNumara );
}
// kisinin bilgilerini dosyaya yaz�yoruz
void Kisi :: DisplayRecord ( )
{
cout.width ( 12);
cout.setf ( ios :: sol) ;
cout << Adi;

cout.width ( 12);
cout.setf ( ios :: sol) ;
cout << Soyadi ;

cout.width ( 12);
cout.setf ( ios :: sol) ;
cout << Numarasi << endl ;
}

char * Kisi :: GetName ( )
{
return Adi;
}

char * Kisi :: GetSurname (void )
{
 return Soyadi;
}

char * Kisi :: GetNumber (void )
{
return Numarasi ;
}

void ReadfromFile ( Kisi * record2 ) ;
void NewEntry ( Kisi * record2 , int ve son) ;
void ModifyDbase ( Kisi * record2 , int itemNO ) ;
void MainMenu ( ) ;
void SaveToFile ( Kisi * record2 , int son) ;
void ChangeEntry ( Kisi * record2 , int son) ;
void PressKey ( ) ;
void SearchName ( Kisi * record2 , int son) ;
void SearchNumber ( Kisi * record2 , int son) ;
void ListItems ( Kisi * record2 , int son) ;

void PressKey ( )
{
cout << endl << "Ana Men� d�nmek i�in herhangi bir tu�a bas�n " ;
getch ( ) ;
MainMenu ();
}



int main ( )
{
int cikis;
int son;
int i;
�Kisi Kayit[ 100 ] ;
// Kay�t yapar Bo� 
{
Kayit [ i] UpdateName ( " " ) . ;
Kayit [ i] UpdateSurname ( " " ) . ;
Kayit [ i] UpdateNumber ( " " ) . ;
}
// bos listeye ilk kayit i�in

ReadfromFile( Kayit ) // Kay�t dosyadan g�ncellenir����
if(Strcmp ( (Kayit + i ) - > GetName( ) , " " ) == 0 )
{
son = i ; // sona i sayac de�i�kenini atad�k
break;
} 

MainMenu ( ); //ekran�ndaki se�enekleri g�ster
//cikis 1 ise bu b�lgeye girer
�������do { 

������char MenuNumber;
MenuNumber = cin.get ( ); // kullan�c�dan men� kayd�n� al

switch( MenuNumber )
{
case 1: Listoge ( Kayit, son ); // Liste ��elerini goster
PressKey ();
break;
case 2: clrscr ( ) ;
NewEntry ( Kayit, son ); // yeni bir giri� al�n
break;
case 3: AdAra ( Kayit, son) // bir isim ara
break;
case 4: SoyadAra ( Kayit, son ); // Soyad�na g�re ara
break;
case 5 : NumaraAra ( Kayit, son) // bir numara ara
break;
case 6 : KayitDegistir ( Kayit, son) // kay�t de�i�tir de�i�tirin
break;
case 7: cout << "  de�i�iklikleri kaydetmek istiyor musunuz? ( E / H ) " ;
char ch ;
cin >> ch ;
if ( ch == ' E ' || ch == ' e ' ) // e�er kullan�c� e girerse kisi kaydedilir
SaveToFile( Kayit, son);
cikis = 0; // case 7 ile degisikliklerin kayd�n�n yap�lmas� komutu verilmi�tir
break;
default: MainMenu ( ) ;
break;
} // switch
������} while(cikis); // cikis=0 olursa do while d�ng�s�nden ��kar


��return 0;
}


void ReadfromFile ( Kisi * record2 ) { // dosyadan verileri oku
ifstream dbFileRd ("backup.mpb",ios::binary); // dbFileRd ad�nda bir nesne olu�turuldu
if(!dbFileRd ) // e�er dosya okunam�yorsa
{
 cout << " okumak i�in veri dosyasi acilamiyor ";
}
� for(int i=0;i<100;i++)
�dbFileRd.read((char*) (Record2+i),sizeof *Record2);
 dbFileRd.close();  //dosya kapat�ld�
} //dosyadan okuma


void Listeogerecord2 bir ( Kisi * record2 , int son) // Liste ��eleri
�{
�clrscr ( ); // ekran� temizle
�� for(int i=0;i<end;i++)
����{
�����cout.width (3);
�����cout.setf ( ios :: sag) ;
�����cout << i +1 << " ) " ;
����� Record2[i].DisplayRecord ();
����}
} // Liste ��eleri


void KayitDegistir( Kisi * record2 , int son) // bir kayd� de�i�tirmek i�in kulland�k
{
��int giris ;
��clrscr ();

���// Liste ��elerini ekranda g�ster  
for(int i=0;i<son;i++)
����{
�����cout.width ( 3);
�����cout.setf ( ios :: sag) ;
�����cout << i+1 << " ) ";
�����Record2[i].DisplayRecord ();
����}
 �cout << " kisinin kayit bilgilerini degistirmek icin - > \n" ;
��cout << endl << "numarasini yazin ve enter a basin " ;
�
��cin >> giris;
��ModifyDbase ( record2 , giris- 1 ) //
} // kayit de�i�tirme

void NewGiris ( Kisi * record2 , int& son) // yeni giri� i�in kullan�l�r 
{
son�= son +1;
�ModifyDbase ( record2 , son-1 ) ;
} // NewGiris


void ModifyDbase ( Kisi * record2 , int itemNO )
�{
��char buffer [ 10 ]; //giris i�in kullan�lan dizi (isim soyisim)
��char buffer2 [ 12 ];
cout << "Adi girin - > " ;
cin >> buffer ;
Record2[itemNo].UpdateSurname(buffer); //al�nan isim yazilir

cout << endl << "Soyadi girin - > " ;
cin >> buffer ;
Record2[itemNo].UpdateSurname(buffer); //alinan soyisim yaz�l�r

cout << endl << "Telefon Numarasi girin - > " ;
cin >> buffer2 ;
Record2[itemNo].UpdateNumber(buffer2); //al�nan numara yaz�l�r

cout << endl << "kay�t g�ncellemesi " << endl << endl ;
Record2[itemNo].DisplayRecord(); //g�ncellenen giri�leri y�kle

PressKey ( ); // Men�y� g�stermek i�in �a�r�ld�

�}

void SearchName ( Kisi * record2 , int son)
{
��char SearchKey [ 10 ] ;
��int NoRecord = 1 // NoRecord -> kay�t yok
��clrscr ();

��cout << " arama i�in bir ad girin - > " ;
��cin >> SearchKey ;

��� for(int i=0;i<son;i++)
	{
	    if (strcmp(SearchKey,(Record2+i)->GetName())==0)
	       {
		  (Record2+i)->DisplayRecord();
		  NoRecord=0;
	       }
	} //d�ng� i�in

( NoRecord == 1 ) //e�er herhangi bir kay�t bulunamazsa
cout << "Adi bulunamadi \ n " ;
��PressKey ( ); // Men�y� g�stermek i�in �a�r�ld�

} // isim arama

void SearchSurname ( Kisi * record2 , int son) // soyad a g�re arama
{

��char SearchKey [ 10 ] ;
��int NoRecord = 1 // hi�bir kay�t yoktur
��clrscr ();

��cout << " Aranacak Soyadi girin - > " ;
��cin >> SearchKey ;

for(int i=0;i<son;i++)
	{
	  if (strcmp(SearchKey,(Record2+i)->GetSurname())==0)
	       {
		  (Record2+i)->DisplayRecord();
		  NoRecord=0;
	       }
	}//for d�ng�s�

( NoRecord == 1 ) // e�er hi�bir kayit bulunamazsa
cout << "Soyadi bulunamadi \ n " ;

�PressKey ( ); // Men�y� g�stermek i�in �a�r�ld�
} // Soyada g�re arama yap�ld�

void SearchNumber ( Kisi * record2 , int son)
{
clrscr ();
char SearchKey [ 10 ] ;
�cout << " aranacak telefon numarasini giriniz - > " ;
���cin >> SearchKey ;
clrscr ();
� 
int NoRecord=1; 
	for(int i=0;i<son;i++)
	{
	    if (strcmp(SearchKey,(Record2+i)->GetNumber())==0) //strcmp ile kar��la�t�rma yap�l�r
	       {
		  (Record2+i)->DisplayRecord();
		  NoRecord=0; 
	       }
	}

	if (NoRecord==1)  //e�er hi�bir kay�t bulunamazsa
	   cout<<"Telefon Numarasi Bulunamadi\n";

PressKey();   //Men�y� �a��r

}

void�MenuMainMenu ( ) { //ekran men�s�
�clrscr ();
�cout << << endl; " : TelefonRehberimiz Fatma and Zeynep. . "
�cout << " ---------------------------------------- " << endl ;
�cout << " | Menu 1 | Liste T�m Kay�tlar� | " << endl ;
�cout << " -------- " << endl ;
�cout << " | Menu 2 | Yeni Kay�t Ekle | " << endl ;
�cout << " -------- " << endl ;
�cout << " | Menu 3 | Bir isim ara | " << endl ;
�cout << " -------- " << endl ;
�cout << " | Menu 4 | Bir Soyad� ara | " << endl ;
�cout << " -------- " << endl ;
�cout << " | Menu 5 | Bir Telefon Numaras� ara | " << endl ;
�cout << " -------- " << endl ;
�cout << " | Menu 6 | Bir Giri�i de�i�tir | " << endl ;
�cout << " -------- " << endl ;
�cout << " | Menu 7 |Programdan ��k�n | " << endl ;
�cout << " ---------------------------------------- " << endl ;

�cout << " Bir Menu Numaras� ( 1 ve 7 aras�nda)  girin " ;

} // MainMenu

void SaveToFile ( Kisi * record2 , int son) // dosyaya kaydeder
{
�ofstream dbFileWr ( " backup.mpb " , ios :: binary) // dosyaya yazmak i�in a��l�r
�� if(!dbFileWr)  // dosya acilmazsa
{
cout <<" yazmak i�in telefon rehberi veri dosyasi acilamiyor\n " ;
}
�� for(int j=0;j<son;j++)   //b�t�n kay�tlar dosyaya yaz�l�yor
   dbFileWr.write((char*) (Record2+j),sizeof *Record2);
   dbFileWr.close(); //dosyay� kapat
}// dosyay� kaydettik
