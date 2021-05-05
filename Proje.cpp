//Uygulama ile Ýlgili Genel Açýklamalar:Berkan KÖMÜRCÜ
//160757038
//Bilgisayar Mühendisliði(ÝÖ) 
//Paralel Programlama 
//BM-308-50-50
//2019 - 2020 Akademik Yýlý Bahar Dönemi
//Proje 1
//Dr.Öðr.Üyesi Deniz DAL


//Kütüphane Denklarasyonu
#include <iostream>
#include <string>
#include <string.h>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

//Fonksiyon Protetipleri=Programým tek bir main fonksiyonu ile çalýþmaktadýr

using namespace std;

//Main fonksiyonu 
int main(int argc, char* argv[]) {
	
	    srand(time(0));
	    int satirlar;//satirlar degiskeni
	    int sutunlar;//sutunlar degiskeni
	    ifstream okunacakDosya;//okunacakdosya adýnda içinde veri alabildiðimiz bir dosya oluþturduk ifstream ile
	    okunacakDosya.open(argv[1]);//dosyayý açtýk;argv1 ile açtýk çünkü çalýþtýrýrken komut satýrýndan girdiðimiz ilk parametre argv1 olucak  
	    okunacakDosya>>satirlar;//satirlar deðiþkenine okunacakDosya adýndaki dosyanýn ilk verisini kaydettik
	    okunacakDosya>>sutunlar;//sutunlar deðiþkenine okunacakDosya adýndaki dosyanýn ikinci verisini kaydettik
	    int geciciDegisken;//geciciDegisken adýndabir temperature deðiþken tanýmladýk sýralama için kullanýcaz
	    int index;//dosyaya veri yazmada ve programýn farklý yerlerinde indis artýrýmlarý için bir deðiþken tanýmladýk
	
	    int * goruntuMatrisiPointer = new int[satirlar*sutunlar];//bir dinamik dizi tanýmladýk pointer aracýlýðýyla satir ve sutun çarpýmý kadar veri tutucak.
            
    
            int atanacakIndisler;//goruntu matrisinin içine atacaðýmýz indisler için bir deðiþken tanýmladýk
            int matrisinIndisi=0;//matris indisini 0 dan baþlattýk
            for(int s1=0;s1<satirlar;s1++)//satirlarin hepsini dolaþacak dýþtaki döngüyü tanýmladýk
            {
    	      for(int s2=0;s2<sutunlar;s2++)//sütunlarýn hepsini dolaþýcak içteki döngüyü tanýmladýk
    	      {
    	        okunacakDosya>>atanacakIndisler;//atanacak indisler deðiþkenini aldýk bunu satýr ve sütunun yazýlý olduðu satýrdan deðilde bir alt satýrdan baþlamasý
    	        //için yaptýk  bu her okunduðunda bir artarak devam edicek yani matristeki her elemanýn bir saðýndaki indisi alýcak hep
    	        goruntuMatrisiPointer[matrisinIndisi]=atanacakIndisler;//o elemanlarýda matrisin 0 dan satýr ve sütun sayýsý çarpýmýna kadar bütün indislerine atýcak
    	        matrisinIndisi++;//matrisin indisini 1 arttýrýyoruz her iterasyonda
	      }
	    }
	    int siralamaMatrisi[25];//sýralýcaðýmýz indis deðerlerini attýðýmýz dizi yani filtrede uygulamaya alýnacak indisleri bu dizide tutucaz.
           struct timeval currentTime;
	   double startTime,endTime,elapsedTime;
	
	  // Get the current time. 2nd argument NULL because we don't care about time zone
    	   gettimeofday(&currentTime, NULL); //Seconds from the epoch time
           startTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0); 		
			////Süresini Ölçmek Ýstediðiniz Program Burada////	


	    for(int s1=2;s1<satirlar-1;s1++)//ilk 2 satýrý ve son 2 satýrý almýyacak þekilde bir döngü tanýmladýk bu döngü satýrlarý dolaþýcak s1 i 2 den baþlattýk
	    //ve satirlarin 1 eksiðine kadar gittik oradada küçük eþittir olmadýðý için aslýnda son iki satýrýda almýcak 
	    //çünkü indisler 0 dan baþladýðý için 0.satýr ve 1. satýr ilk iki satýr oluyo yani bunlarý almamýþ oluyoruz birde burda önemli olan kýsým þu 
	    //Bizim goruntuMatrisiPointer a attýðýmýz deðerler filtre uygulanacak olan matrisin yani indislerin olduðu matrisin ilk satýrýný almýyor yani
	    //satýr sayýsý ve sütun sayýsý yazan satýrý almýyor onun nedeni 47.kod satýrýnda atanacakIndisler'i okumamýz bunu okuduðumuzda 33 ve 34.satýrda
	    //satýrlar ve sütunlar bilgisini aldýktan sonra ilk aldýðýmýz deðer matrisin ilk elemaný olucak 
	    {
	      for(int s2=2;s2<sutunlar-1;s2++)//sütunlarý dolaþmamýz için bir döngü oluþturduk bu döngü de ilk iki ve son iki sütunu dahil etmicek 
	      //burda da dýþtaki fordaki gibi s2 yi 2 den ve sütunlarýn 1 eksiðine kadar götürüyoruz
	      {
	      	//Filtreleme uygulamasý için filtre uygulanacak deðerlerin komþu deðerlerini(yani filtre uygulanacak herbir deðer için 25 tane komþu deðeri var)
	      	//siralamaMatrisi adýnda bir tek boyutlu diziye atadýk.0 dan 24 e kadar yani toplam 24 deðer oluþcak siralamaMatrisi içinde
	      	//Filtreyi uygulama mantýðý;þimdi örnek olarak ilk görüntüde ilk filtre uygulanacak deðer 87 bu deðerin yerine 87 nin komþularý olan tüm deðerlerin
	      	//küçükten büyüðe sýralanýp ortancasý bulunup eklenmeli burdada bu iþlemi yapýyoruz.Fitrelenmemiþ indis deðerlerinin bulunduðu goruntuMatrisPointer
	      	//dinamik dizisindeki 87 indisinin ilk komþusu 14 yani ilk satýrdaki ilk indis(satir ve sütun sayýlarýnýn olduðu deðerleri goruntuMatrisiPointer
	      	//a atmadýk dikkat)bu indisden baþlayýp 87 ninde kendisi dahil olmak üzere 25 adet indisi sýrayla siralamaMatrisinin içine atýcaz 83.kod satýrýndan
	      	//107.kod satýrýna kadar bu iþlemi yapýyoruz
	   	      //Filtreleme uygulamasý için filtre uygulanacak deðerlerin komþu deðerlerini(yani filtre uygulanacak herbir deðer için 25 tane komþu deðeri var)
	      	//siralamaMatrisi adýnda bir tek boyutlu diziye atadýk.0 dan 24 e kadar yani toplam 24 deðer oluþcak siralamaMatrisi içinde
	      	//Filtreyi uygulama mantýðý;þimdi örnek olarak ilk görüntüde ilk filtre uygulanacak deðer 87 bu deðerin yerine 87 nin komþularý olan tüm deðerlerin
	      	//küçükten büyüðe sýralanýp ortancasý bulunup eklenmeli burdada bu iþlemi yapýyoruz.Fitrelenmemiþ indis deðerlerinin bulunduðu goruntuMatrisPointer
	      	//dinamik dizisindeki 87 indisinin ilk komþusu 14 yani ilk satýrdaki ilk indis(satir ve sütun sayýlarýnýn olduðu deðerleri goruntuMatrisiPointer
	      	//a atmadýk dikkat)bu indisden baþlayýp 87 ninde kendisi dahil olmak üzere 25 adet indisi sýrayla siralamaMatrisinin içine atýcaz 83.kod satýrýndan
	      	//107.kod satýrýna kadar bu iþlemi yapýyoruz
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
	   	      //þimdi sýralamaMatrisindeki bu 25 deðeri bubble sort algoritmasý ile küçükten büyüðe sýralýcaz
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
	   	 
	           goruntuMatrisiPointer[s1*sutunlar+s2]=siralamaMatrisi[12];//ortanca degeri bulup ilgili indise atýcaz
	      }
	    }

// Get the current time
    	gettimeofday(&currentTime, NULL); //Seconds from the epoch time
	endTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0);	
	// Calculate the elapsed time in seconds
    	elapsedTime = endTime-startTime;
	cout << "Filtre icin gecen zaman(ms): " << elapsedTime*1000<< endl;
	    	   
    	
    	
	    char ciktiDosyasi[28];//Filtrelenmiþ matrisin çýktý halini char dizisi þeklinde tanýmladýk örn:GoruntuMatrisi1
    	    string ciktiDosyasiUzantisi= "_filtered.txt";//argümanýn sonuna uzantý eklemek için deðiþken tanýmladýk
    	    for(int s1=0; s1<15; s1++)//0 dan 15 e kadar gidicek for 
	    {
	      ciktiDosyasi[s1]=argv[1][s1+22];// argümanýn toplam (.txt hariç) 38 karakteri var biz sadece GoruntuMatrisi1 örneði þeklinde 15 karakterli bir deðer atadýk	
	    }
	    for(int s1=0; s1<14; s1++)//sonra o 15 deðerli karakterin sonuna 15 ten baþlayarak(15 ten alttaki forda baþlýyor) (devamý altta ki açýklama satýrýnda)
	    {
	      ciktiDosyasi[s1+15] = ciktiDosyasiUzantisi[s1];//uzantýyý atadýk artýk içinde GoruntuMatrisi1_filtered.txt örneði þeklinde bir deðer olmuþ oldu
	    } 								
		
	    ofstream yazilacakDosya;//yazilacak dosyayý çýktý dosyasý olarak ayarladýk
	    yazilacakDosya.open(ciktiDosyasi, ios::out);//burda char dizisini çevirme iþlemi ve yazýlacak dosyayý açma iþlemi yapýyoruz
            //yazilacakDosya<<satirlar;
            //yazilacakDosya<<sutunlar;
	    for(int s1=0; s1<satirlar; s1++)//satýrlara kadar giden bir döngü
            {
               for(int s2=0; s2<sutunlar; s2++)//sütunlara kadar giden bir döngü
	       {
		  yazilacakDosya<<goruntuMatrisiPointer[s1*sutunlar+s2]<<"\t";//yazýlacak matris deðerleri matrisin ilk satýr ve ilk sütunundan baþlýcak
                  //dikkat et matrisin satýr ve sütun bilgisinin yazdýðý satýrý almýcak onu almak isteseydik bu satýrýn üstündeki 7.ve 8.sütunu
                  //satý ve sütun sayýsý bilgisini yazdýrdýðýmýz kýsmý açýklama satýrýndan kaldýrmamýz gerekirdi
					
	       }
	           yazilacakDosya<<endl;
	    }	

	    okunacakDosya.close();//okunacak dosyayý kapattýk
	    yazilacakDosya.close();//yazýlacak dosyayý kapattýk 
	    delete [] goruntuMatrisiPointer;//dinamnik diziyi sildik
	
	
	
	return 0;
}
