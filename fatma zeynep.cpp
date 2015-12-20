#include <iostream>
#include <stdlib.h>
# include <string.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 

//Kiþi tanýmlý olduðu ana sýnýfý
class Kisi
{

private:
Char Adi[ 20 ]; // özel deðiþkenleri
char Soyadi[ 20 ] ;
char Numarasi[ 12 ] ;

public:
void UpdateName ( char * YeniAd ); // genel yöntemleri
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
// kisinin bilgilerini dosyaya yazýyoruz
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
cout << endl << "Ana Menü dönmek için herhangi bir tuþa basýn " ;
getch ( ) ;
MainMenu ();
}



int main ( )
{
int cikis;
int son;
int i;
 Kisi Kayit[ 100 ] ;
// Kayýt yapar Boþ 
{
Kayit [ i] UpdateName ( " " ) . ;
Kayit [ i] UpdateSurname ( " " ) . ;
Kayit [ i] UpdateNumber ( " " ) . ;
}
// bos listeye ilk kayit için

ReadfromFile( Kayit ) // Kayýt dosyadan güncellenir    
if(Strcmp ( (Kayit + i ) - > GetName( ) , " " ) == 0 )
{
son = i ; // sona i sayac deðiþkenini atadýk
break;
} 

MainMenu ( ); //ekranýndaki seçenekleri göster
//cikis 1 ise bu bölgeye girer
       do { 

      char MenuNumber;
MenuNumber = cin.get ( ); // kullanýcýdan menü kaydýný al

switch( MenuNumber )
{
case 1: Listoge ( Kayit, son ); // Liste öðelerini goster
PressKey ();
break;
case 2: clrscr ( ) ;
NewEntry ( Kayit, son ); // yeni bir giriþ alýn
break;
case 3: AdAra ( Kayit, son) // bir isim ara
break;
case 4: SoyadAra ( Kayit, son ); // Soyadýna göre ara
break;
case 5 : NumaraAra ( Kayit, son) // bir numara ara
break;
case 6 : KayitDegistir ( Kayit, son) // kayýt deðiþtir deðiþtirin
break;
case 7: cout << "  deðiþiklikleri kaydetmek istiyor musunuz? ( E / H ) " ;
char ch ;
cin >> ch ;
if ( ch == ' E ' || ch == ' e ' ) // eðer kullanýcý e girerse kisi kaydedilir
SaveToFile( Kayit, son);
cikis = 0; // case 7 ile degisikliklerin kaydýnýn yapýlmasý komutu verilmiþtir
break;
default: MainMenu ( ) ;
break;
} // switch
      } while(cikis); // cikis=0 olursa do while döngüsünden çýkar


  return 0;
}


void ReadfromFile ( Kisi * record2 ) { // dosyadan verileri oku
ifstream dbFileRd ("backup.mpb",ios::binary); // dbFileRd adýnda bir nesne oluþturuldu
if(!dbFileRd ) // eðer dosya okunamýyorsa
{
 cout << " okumak için veri dosyasi acilamiyor ";
}
  for(int i=0;i<100;i++)
 dbFileRd.read((char*) (Record2+i),sizeof *Record2);
 dbFileRd.close();  //dosya kapatýldý
} //dosyadan okuma


void Listeogerecord2 bir ( Kisi * record2 , int son) // Liste öðeleri
 {
 clrscr ( ); // ekraný temizle
   for(int i=0;i<end;i++)
    {
     cout.width (3);
     cout.setf ( ios :: sag) ;
     cout << i +1 << " ) " ;
      Record2[i].DisplayRecord ();
    }
} // Liste öðeleri


void KayitDegistir( Kisi * record2 , int son) // bir kaydý deðiþtirmek için kullandýk
{
  int giris ;
  clrscr ();

   // Liste öðelerini ekranda göster  
for(int i=0;i<son;i++)
    {
     cout.width ( 3);
     cout.setf ( ios :: sag) ;
     cout << i+1 << " ) ";
     Record2[i].DisplayRecord ();
    }
  cout << " kisinin kayit bilgilerini degistirmek icin - > \n" ;
  cout << endl << "numarasini yazin ve enter a basin " ;
 
  cin >> giris;
  ModifyDbase ( record2 , giris- 1 ) //
} // kayit deðiþtirme

void NewGiris ( Kisi * record2 , int& son) // yeni giriþ için kullanýlýr 
{
son = son +1;
 ModifyDbase ( record2 , son-1 ) ;
} // NewGiris


void ModifyDbase ( Kisi * record2 , int itemNO )
 {
  char buffer [ 10 ]; //giris için kullanýlan dizi (isim soyisim)
  char buffer2 [ 12 ];
cout << "Adi girin - > " ;
cin >> buffer ;
Record2[itemNo].UpdateSurname(buffer); //alýnan isim yazilir

cout << endl << "Soyadi girin - > " ;
cin >> buffer ;
Record2[itemNo].UpdateSurname(buffer); //alinan soyisim yazýlýr

cout << endl << "Telefon Numarasi girin - > " ;
cin >> buffer2 ;
Record2[itemNo].UpdateNumber(buffer2); //alýnan numara yazýlýr

cout << endl << "kayýt güncellemesi " << endl << endl ;
Record2[itemNo].DisplayRecord(); //güncellenen giriþleri yükle

PressKey ( ); // Menüyü göstermek için çaðrýldý

 }

void SearchName ( Kisi * record2 , int son)
{
  char SearchKey [ 10 ] ;
  int NoRecord = 1 // NoRecord -> kayýt yok
  clrscr ();

  cout << " arama için bir ad girin - > " ;
  cin >> SearchKey ;

    for(int i=0;i<son;i++)
	{
	    if (strcmp(SearchKey,(Record2+i)->GetName())==0)
	       {
		  (Record2+i)->DisplayRecord();
		  NoRecord=0;
	       }
	} //döngü için

( NoRecord == 1 ) //eðer herhangi bir kayýt bulunamazsa
cout << "Adi bulunamadi \ n " ;
  PressKey ( ); // Menüyü göstermek için çaðrýldý

} // isim arama

void SearchSurname ( Kisi * record2 , int son) // soyad a göre arama
{

  char SearchKey [ 10 ] ;
  int NoRecord = 1 // hiçbir kayýt yoktur
  clrscr ();

  cout << " Aranacak Soyadi girin - > " ;
  cin >> SearchKey ;

for(int i=0;i<son;i++)
	{
	  if (strcmp(SearchKey,(Record2+i)->GetSurname())==0)
	       {
		  (Record2+i)->DisplayRecord();
		  NoRecord=0;
	       }
	}//for döngüsü

( NoRecord == 1 ) // eðer hiçbir kayit bulunamazsa
cout << "Soyadi bulunamadi \ n " ;

 PressKey ( ); // Menüyü göstermek için çaðrýldý
} // Soyada göre arama yapýldý

void SearchNumber ( Kisi * record2 , int son)
{
clrscr ();
char SearchKey [ 10 ] ;
 cout << " aranacak telefon numarasini giriniz - > " ;
   cin >> SearchKey ;
clrscr ();
  
int NoRecord=1; 
	for(int i=0;i<son;i++)
	{
	    if (strcmp(SearchKey,(Record2+i)->GetNumber())==0) //strcmp ile karþýlaþtýrma yapýlýr
	       {
		  (Record2+i)->DisplayRecord();
		  NoRecord=0; 
	       }
	}

	if (NoRecord==1)  //eðer hiçbir kayýt bulunamazsa
	   cout<<"Telefon Numarasi Bulunamadi\n";

PressKey();   //Menüyü çaðýr

}

void MenuMainMenu ( ) { //ekran menüsü
 clrscr ();
 cout << << endl; " : TelefonRehberimiz Fatma and Zeynep. . "
 cout << " ---------------------------------------- " << endl ;
 cout << " | Menu 1 | Liste Tüm Kayýtlarý | " << endl ;
 cout << " -------- " << endl ;
 cout << " | Menu 2 | Yeni Kayýt Ekle | " << endl ;
 cout << " -------- " << endl ;
 cout << " | Menu 3 | Bir isim ara | " << endl ;
 cout << " -------- " << endl ;
 cout << " | Menu 4 | Bir Soyadý ara | " << endl ;
 cout << " -------- " << endl ;
 cout << " | Menu 5 | Bir Telefon Numarasý ara | " << endl ;
 cout << " -------- " << endl ;
 cout << " | Menu 6 | Bir Giriþi deðiþtir | " << endl ;
 cout << " -------- " << endl ;
 cout << " | Menu 7 |Programdan çýkýn | " << endl ;
 cout << " ---------------------------------------- " << endl ;

 cout << " Bir Menu Numarasý ( 1 ve 7 arasýnda)  girin " ;

} // MainMenu

void SaveToFile ( Kisi * record2 , int son) // dosyaya kaydeder
{
 ofstream dbFileWr ( " backup.mpb " , ios :: binary) // dosyaya yazmak için açýlýr
   if(!dbFileWr)  // dosya acilmazsa
{
cout <<" yazmak için telefon rehberi veri dosyasi acilamiyor\n " ;
}
   for(int j=0;j<son;j++)   //bütün kayýtlar dosyaya yazýlýyor
   dbFileWr.write((char*) (Record2+j),sizeof *Record2);
   dbFileWr.close(); //dosyayý kapat
}// dosyayý kaydettik
