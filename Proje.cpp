//Uygulama ile �lgili Genel A��klamalar:Berkan K�M�RC�
//160757038
//Bilgisayar M�hendisli�i(��) 
//Paralel Programlama 
//BM-308-50-50
//2019 - 2020 Akademik Y�l� Bahar D�nemi
//Proje 1
//Dr.��r.�yesi Deniz DAL


//K�t�phane Denklarasyonu
#include <iostream>
#include <string>
#include <string.h>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

//Fonksiyon Protetipleri=Program�m tek bir main fonksiyonu ile �al��maktad�r

using namespace std;

//Main fonksiyonu 
int main(int argc, char* argv[]) {
	
	    srand(time(0));
	    int satirlar;//satirlar degiskeni
	    int sutunlar;//sutunlar degiskeni
	    ifstream okunacakDosya;//okunacakdosya ad�nda i�inde veri alabildi�imiz bir dosya olu�turduk ifstream ile
	    okunacakDosya.open(argv[1]);//dosyay� a�t�k;argv1 ile a�t�k ��nk� �al��t�r�rken komut sat�r�ndan girdi�imiz ilk parametre argv1 olucak  
	    okunacakDosya>>satirlar;//satirlar de�i�kenine okunacakDosya ad�ndaki dosyan�n ilk verisini kaydettik
	    okunacakDosya>>sutunlar;//sutunlar de�i�kenine okunacakDosya ad�ndaki dosyan�n ikinci verisini kaydettik
	    int geciciDegisken;//geciciDegisken ad�ndabir temperature de�i�ken tan�mlad�k s�ralama i�in kullan�caz
	    int index;//dosyaya veri yazmada ve program�n farkl� yerlerinde indis art�r�mlar� i�in bir de�i�ken tan�mlad�k
	
	    int * goruntuMatrisiPointer = new int[satirlar*sutunlar];//bir dinamik dizi tan�mlad�k pointer arac�l���yla satir ve sutun �arp�m� kadar veri tutucak.
            
    
            int atanacakIndisler;//goruntu matrisinin i�ine ataca��m�z indisler i�in bir de�i�ken tan�mlad�k
            int matrisinIndisi=0;//matris indisini 0 dan ba�latt�k
            for(int s1=0;s1<satirlar;s1++)//satirlarin hepsini dola�acak d��taki d�ng�y� tan�mlad�k
            {
    	      for(int s2=0;s2<sutunlar;s2++)//s�tunlar�n hepsini dola��cak i�teki d�ng�y� tan�mlad�k
    	      {
    	        okunacakDosya>>atanacakIndisler;//atanacak indisler de�i�kenini ald�k bunu sat�r ve s�tunun yaz�l� oldu�u sat�rdan de�ilde bir alt sat�rdan ba�lamas�
    	        //i�in yapt�k  bu her okundu�unda bir artarak devam edicek yani matristeki her eleman�n bir sa��ndaki indisi al�cak hep
    	        goruntuMatrisiPointer[matrisinIndisi]=atanacakIndisler;//o elemanlar�da matrisin 0 dan sat�r ve s�tun say�s� �arp�m�na kadar b�t�n indislerine at�cak
    	        matrisinIndisi++;//matrisin indisini 1 artt�r�yoruz her iterasyonda
	      }
	    }
	    int siralamaMatrisi[25];//s�ral�ca��m�z indis de�erlerini att���m�z dizi yani filtrede uygulamaya al�nacak indisleri bu dizide tutucaz.
           struct timeval currentTime;
	   double startTime,endTime,elapsedTime;
	
	  // Get the current time. 2nd argument NULL because we don't care about time zone
    	   gettimeofday(&currentTime, NULL); //Seconds from the epoch time
           startTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0); 		
			////S�resini �l�mek �stedi�iniz Program Burada////	


	    for(int s1=2;s1<satirlar-1;s1++)//ilk 2 sat�r� ve son 2 sat�r� alm�yacak �ekilde bir d�ng� tan�mlad�k bu d�ng� sat�rlar� dola��cak s1 i 2 den ba�latt�k
	    //ve satirlarin 1 eksi�ine kadar gittik oradada k���k e�ittir olmad��� i�in asl�nda son iki sat�r�da alm�cak 
	    //��nk� indisler 0 dan ba�lad��� i�in 0.sat�r ve 1. sat�r ilk iki sat�r oluyo yani bunlar� almam�� oluyoruz birde burda �nemli olan k�s�m �u 
	    //Bizim goruntuMatrisiPointer a att���m�z de�erler filtre uygulanacak olan matrisin yani indislerin oldu�u matrisin ilk sat�r�n� alm�yor yani
	    //sat�r say�s� ve s�tun say�s� yazan sat�r� alm�yor onun nedeni 47.kod sat�r�nda atanacakIndisler'i okumam�z bunu okudu�umuzda 33 ve 34.sat�rda
	    //sat�rlar ve s�tunlar bilgisini ald�ktan sonra ilk ald���m�z de�er matrisin ilk eleman� olucak 
	    {
	      for(int s2=2;s2<sutunlar-1;s2++)//s�tunlar� dola�mam�z i�in bir d�ng� olu�turduk bu d�ng� de ilk iki ve son iki s�tunu dahil etmicek 
	      //burda da d��taki fordaki gibi s2 yi 2 den ve s�tunlar�n 1 eksi�ine kadar g�t�r�yoruz
	      {
	      	//Filtreleme uygulamas� i�in filtre uygulanacak de�erlerin kom�u de�erlerini(yani filtre uygulanacak herbir de�er i�in 25 tane kom�u de�eri var)
	      	//siralamaMatrisi ad�nda bir tek boyutlu diziye atad�k.0 dan 24 e kadar yani toplam 24 de�er olu�cak siralamaMatrisi i�inde
	      	//Filtreyi uygulama mant���;�imdi �rnek olarak ilk g�r�nt�de ilk filtre uygulanacak de�er 87 bu de�erin yerine 87 nin kom�ular� olan t�m de�erlerin
	      	//k���kten b�y��e s�ralan�p ortancas� bulunup eklenmeli burdada bu i�lemi yap�yoruz.Fitrelenmemi� indis de�erlerinin bulundu�u goruntuMatrisPointer
	      	//dinamik dizisindeki 87 indisinin ilk kom�usu 14 yani ilk sat�rdaki ilk indis(satir ve s�tun say�lar�n�n oldu�u de�erleri goruntuMatrisiPointer
	      	//a atmad�k dikkat)bu indisden ba�lay�p 87 ninde kendisi dahil olmak �zere 25 adet indisi s�rayla siralamaMatrisinin i�ine at�caz 83.kod sat�r�ndan
	      	//107.kod sat�r�na kadar bu i�lemi yap�yoruz
	   	      //Filtreleme uygulamas� i�in filtre uygulanacak de�erlerin kom�u de�erlerini(yani filtre uygulanacak herbir de�er i�in 25 tane kom�u de�eri var)
	      	//siralamaMatrisi ad�nda bir tek boyutlu diziye atad�k.0 dan 24 e kadar yani toplam 24 de�er olu�cak siralamaMatrisi i�inde
	      	//Filtreyi uygulama mant���;�imdi �rnek olarak ilk g�r�nt�de ilk filtre uygulanacak de�er 87 bu de�erin yerine 87 nin kom�ular� olan t�m de�erlerin
	      	//k���kten b�y��e s�ralan�p ortancas� bulunup eklenmeli burdada bu i�lemi yap�yoruz.Fitrelenmemi� indis de�erlerinin bulundu�u goruntuMatrisPointer
	      	//dinamik dizisindeki 87 indisinin ilk kom�usu 14 yani ilk sat�rdaki ilk indis(satir ve s�tun say�lar�n�n oldu�u de�erleri goruntuMatrisiPointer
	      	//a atmad�k dikkat)bu indisden ba�lay�p 87 ninde kendisi dahil olmak �zere 25 adet indisi s�rayla siralamaMatrisinin i�ine at�caz 83.kod sat�r�ndan
	      	//107.kod sat�r�na kadar bu i�lemi yap�yoruz
	   	      siralamaMatrisi[0]=goruntuMatrisiPointer[(s1-2)*sutunlar+s2-2];
	   	      siralamaMatrisi[1]=goruntuMatrisiPointer[(s1-2)*sutunlar+s2-1];
	   	      siralamaMatrisi[2]=goruntuMatrisiPointer[(s1-2)*sutunlar+s2];
	   	      siralamaMatrisi[3]=goruntuMatrisiPointer[(s1-2)*sutunlar+s2+1];
	   	      siralamaMatrisi[4]=goruntuMatrisiPointer[(s1-2)*sutunlar+s2+2];
	   	      siralamaMatrisi[5]=goruntuMatrisiPointer[(s1-1)*sutunlar+s2-2];
	   	      siralamaMatrisi[6]=goruntuMatrisiPointer[(s1-1)*sutunlar+s2-1];
	   	      siralamaMatrisi[7]=goruntuMatrisiPointer[(s1-1)*sutunlar+s2];
	   	      siralamaMatrisi[8]=goruntuMatrisiPointer[(s1-1)*sutunlar+s2+1];
	   	      siralamaMatrisi[9]=goruntuMatrisiPointer[(s1-1)*sutunlar+s2+2];
	   	      siralamaMatrisi[10]=goruntuMatrisiPointer[(s1)*sutunlar+s2-2];
	   	      siralamaMatrisi[11]=goruntuMatrisiPointer[(s1)*sutunlar+s2-1];
	   	      siralamaMatrisi[12]=goruntuMatrisiPointer[(s1)*sutunlar+s2];
	   	      siralamaMatrisi[13]=goruntuMatrisiPointer[(s1)*sutunlar+s2+1];
	   	      siralamaMatrisi[14]=goruntuMatrisiPointer[(s1)*sutunlar+s2+2];
	   	      siralamaMatrisi[15]=goruntuMatrisiPointer[(s1+1)*sutunlar+s2-2];
	   	      siralamaMatrisi[16]=goruntuMatrisiPointer[(s1+1)*sutunlar+s2-1];
	   	      siralamaMatrisi[17]=goruntuMatrisiPointer[(s1+1)*sutunlar+s2];
	   	      siralamaMatrisi[18]=goruntuMatrisiPointer[(s1+1)*sutunlar+s2+1];
	   	      siralamaMatrisi[19]=goruntuMatrisiPointer[(s1+1)*sutunlar+s2+2];
	   	      siralamaMatrisi[20]=goruntuMatrisiPointer[(s1+2)*sutunlar+s2-2];
	   	      siralamaMatrisi[21]=goruntuMatrisiPointer[(s1+2)*sutunlar+s2-1];
	   	      siralamaMatrisi[22]=goruntuMatrisiPointer[(s1+2)*sutunlar+s2];
	   	      siralamaMatrisi[23]=goruntuMatrisiPointer[(s1+2)*sutunlar+s2+1];
	   	      siralamaMatrisi[24]=goruntuMatrisiPointer[(s1+2)*sutunlar+s2+2];					
	   	      //�imdi s�ralamaMatrisindeki bu 25 de�eri bubble sort algoritmas� ile k���kten b�y��e s�ral�caz
	   	      for(int i=0;i<25;i++)
	   	      {
	   	     	for(int j=i;j<25;j++)
	   	 	    {
	   	 		   if(siralamaMatrisi[i]>siralamaMatrisi[j])
	   	 		   {
	   	 		     geciciDegisken=siralamaMatrisi[i];
	   	 		     siralamaMatrisi[i]=siralamaMatrisi[j];
	   	 		     siralamaMatrisi[j]=geciciDegisken;
	   	 	       }
			   }
	   	 	
		      }
	   	 
	           goruntuMatrisiPointer[s1*sutunlar+s2]=siralamaMatrisi[12];//ortanca degeri bulup ilgili indise at�caz
	      }
	    }

// Get the current time
    	gettimeofday(&currentTime, NULL); //Seconds from the epoch time
	endTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0);	
	// Calculate the elapsed time in seconds
    	elapsedTime = endTime-startTime;
	cout << "Filtre icin gecen zaman(ms): " << elapsedTime*1000<< endl;
	    	   
    	
    	
	    char ciktiDosyasi[28];//Filtrelenmi� matrisin ��kt� halini char dizisi �eklinde tan�mlad�k �rn:GoruntuMatrisi1
    	    string ciktiDosyasiUzantisi= "_filtered.txt";//arg�man�n sonuna uzant� eklemek i�in de�i�ken tan�mlad�k
    	    for(int s1=0; s1<15; s1++)//0 dan 15 e kadar gidicek for 
	    {
	      ciktiDosyasi[s1]=argv[1][s1+22];// arg�man�n toplam (.txt hari�) 38 karakteri var biz sadece GoruntuMatrisi1 �rne�i �eklinde 15 karakterli bir de�er atad�k	
	    }
	    for(int s1=0; s1<14; s1++)//sonra o 15 de�erli karakterin sonuna 15 ten ba�layarak(15 ten alttaki forda ba�l�yor) (devam� altta ki a��klama sat�r�nda)
	    {
	      ciktiDosyasi[s1+15] = ciktiDosyasiUzantisi[s1];//uzant�y� atad�k art�k i�inde GoruntuMatrisi1_filtered.txt �rne�i �eklinde bir de�er olmu� oldu
	    } 								
		
	    ofstream yazilacakDosya;//yazilacak dosyay� ��kt� dosyas� olarak ayarlad�k
	    yazilacakDosya.open(ciktiDosyasi, ios::out);//burda char dizisini �evirme i�lemi ve yaz�lacak dosyay� a�ma i�lemi yap�yoruz
            //yazilacakDosya<<satirlar;
            //yazilacakDosya<<sutunlar;
	    for(int s1=0; s1<satirlar; s1++)//sat�rlara kadar giden bir d�ng�
            {
               for(int s2=0; s2<sutunlar; s2++)//s�tunlara kadar giden bir d�ng�
	       {
		  yazilacakDosya<<goruntuMatrisiPointer[s1*sutunlar+s2]<<"\t";//yaz�lacak matris de�erleri matrisin ilk sat�r ve ilk s�tunundan ba�l�cak
                  //dikkat et matrisin sat�r ve s�tun bilgisinin yazd��� sat�r� alm�cak onu almak isteseydik bu sat�r�n �st�ndeki 7.ve 8.s�tunu
                  //sat� ve s�tun say�s� bilgisini yazd�rd���m�z k�sm� a��klama sat�r�ndan kald�rmam�z gerekirdi
					
	       }
	           yazilacakDosya<<endl;
	    }	

	    okunacakDosya.close();//okunacak dosyay� kapatt�k
	    yazilacakDosya.close();//yaz�lacak dosyay� kapatt�k 
	    delete [] goruntuMatrisiPointer;//dinamnik diziyi sildik
	
	
	
	return 0;
}
