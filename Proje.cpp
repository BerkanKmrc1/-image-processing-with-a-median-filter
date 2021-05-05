

//Kütüphane Denklarasyonu
#include <iostream>
#include <string>
#include <string.h>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

//Fonksiyon Protetipleri=Programım tek bir main fonksiyonu ile çalışmaktadır

using namespace std;

//Main fonksiyonu 
int main(int argc, char* argv[]) {
	
	    srand(time(0));
	    int satirlar;//satirlar degiskeni
	    int sutunlar;//sutunlar degiskeni
	    ifstream okunacakDosya;//okunacakdosya adında içinde veri alabildiğimiz bir dosya oluşturduk ifstream ile
	    okunacakDosya.open(argv[1]);//dosyayı açtık;argv1 ile açtık çünkü çalıştırırken komut satırından girdiğimiz ilk parametre argv1 olucak  
	    okunacakDosya>>satirlar;//satirlar değişkenine okunacakDosya adındaki dosyanın ilk verisini kaydettik
	    okunacakDosya>>sutunlar;//sutunlar değişkenine okunacakDosya adındaki dosyanın ikinci verisini kaydettik
	    int geciciDegisken;//geciciDegisken adındabir temperature değişken tanımladık sıralama için kullanıcaz
	    int index;//dosyaya veri yazmada ve programın farklı yerlerinde indis artırımları için bir değişken tanımladık
	
	    int * goruntuMatrisiPointer = new int[satirlar*sutunlar];//bir dinamik dizi tanımladık pointer aracılığıyla satir ve sutun çarpımı kadar veri tutucak.
            
    
            int atanacakIndisler;//goruntu matrisinin içine atacağımız indisler için bir değişken tanımladık
            int matrisinIndisi=0;//matris indisini 0 dan başlattık
            for(int s1=0;s1<satirlar;s1++)//satirlarin hepsini dolaşacak dıştaki döngüyü tanımladık
            {
    	      for(int s2=0;s2<sutunlar;s2++)//sütunların hepsini dolaşıcak içteki döngüyü tanımladık
    	      {
    	        okunacakDosya>>atanacakIndisler;//atanacak indisler değişkenini aldık bunu satır ve sütunun yazılı olduğu satırdan değilde bir alt satırdan başlaması
    	        //için yaptık  bu her okunduğunda bir artarak devam edicek yani matristeki her elemanın bir sağındaki indisi alıcak hep
    	        goruntuMatrisiPointer[matrisinIndisi]=atanacakIndisler;//o elemanlarıda matrisin 0 dan satır ve sütun sayısı çarpımına kadar bütün indislerine atıcak
    	        matrisinIndisi++;//matrisin indisini 1 arttırıyoruz her iterasyonda
	      }
	    }
	    int siralamaMatrisi[25];//sıralıcağımız indis değerlerini attığımız dizi yani filtrede uygulamaya alınacak indisleri bu dizide tutucaz.
           struct timeval currentTime;
	   double startTime,endTime,elapsedTime;
	
	  // Get the current time. 2nd argument NULL because we don't care about time zone
    	   gettimeofday(&currentTime, NULL); //Seconds from the epoch time
           startTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0); 		
			////Süresini Ölçmek İstediğiniz Program Burada////	


	    for(int s1=2;s1<satirlar-1;s1++)//ilk 2 satırı ve son 2 satırı almıyacak şekilde bir döngü tanımladık bu döngü satırları dolaşıcak s1 i 2 den başlattık
	    //ve satirlarin 1 eksiğine kadar gittik oradada küçük eşittir olmadığı için aslında son iki satırıda almıcak 
	    //çünkü indisler 0 dan başladığı için 0.satır ve 1. satır ilk iki satır oluyo yani bunları almamış oluyoruz birde burda önemli olan kısım şu 
	    //Bizim goruntuMatrisiPointer a attığımız değerler filtre uygulanacak olan matrisin yani indislerin olduğu matrisin ilk satırını almıyor yani
	    //satır sayısı ve sütun sayısı yazan satırı almıyor onun nedeni 47.kod satırında atanacakIndisler'i okumamız bunu okuduğumuzda 33 ve 34.satırda
	    //satırlar ve sütunlar bilgisini aldıktan sonra ilk aldığımız değer matrisin ilk elemanı olucak 
	    {
	      for(int s2=2;s2<sutunlar-1;s2++)//sütunları dolaşmamız için bir döngü oluşturduk bu döngü de ilk iki ve son iki sütunu dahil etmicek 
	      //burda da dıştaki fordaki gibi s2 yi 2 den ve sütunların 1 eksiğine kadar götürüyoruz
	      {
	      	//Filtreleme uygulaması için filtre uygulanacak değerlerin komşu değerlerini(yani filtre uygulanacak herbir değer için 25 tane komşu değeri var)
	      	//siralamaMatrisi adında bir tek boyutlu diziye atadık.0 dan 24 e kadar yani toplam 24 değer oluşcak siralamaMatrisi içinde
	      	//Filtreyi uygulama mantığı;şimdi örnek olarak ilk görüntüde ilk filtre uygulanacak değer 87 bu değerin yerine 87 nin komşuları olan tüm değerlerin
	      	//küçükten büyüğe sıralanıp ortancası bulunup eklenmeli burdada bu işlemi yapıyoruz.Fitrelenmemiş indis değerlerinin bulunduğu goruntuMatrisPointer
	      	//dinamik dizisindeki 87 indisinin ilk komşusu 14 yani ilk satırdaki ilk indis(satir ve sütun sayılarının olduğu değerleri goruntuMatrisiPointer
	      	//a atmadık dikkat)bu indisden başlayıp 87 ninde kendisi dahil olmak üzere 25 adet indisi sırayla siralamaMatrisinin içine atıcaz 83.kod satırından
	      	//107.kod satırına kadar bu işlemi yapıyoruz
	   	      //Filtreleme uygulaması için filtre uygulanacak değerlerin komşu değerlerini(yani filtre uygulanacak herbir değer için 25 tane komşu değeri var)
	      	//siralamaMatrisi adında bir tek boyutlu diziye atadık.0 dan 24 e kadar yani toplam 24 değer oluşcak siralamaMatrisi içinde
	      	//Filtreyi uygulama mantığı;şimdi örnek olarak ilk görüntüde ilk filtre uygulanacak değer 87 bu değerin yerine 87 nin komşuları olan tüm değerlerin
	      	//küçükten büyüğe sıralanıp ortancası bulunup eklenmeli burdada bu işlemi yapıyoruz.Fitrelenmemiş indis değerlerinin bulunduğu goruntuMatrisPointer
	      	//dinamik dizisindeki 87 indisinin ilk komşusu 14 yani ilk satırdaki ilk indis(satir ve sütun sayılarının olduğu değerleri goruntuMatrisiPointer
	      	//a atmadık dikkat)bu indisden başlayıp 87 ninde kendisi dahil olmak üzere 25 adet indisi sırayla siralamaMatrisinin içine atıcaz 83.kod satırından
	      	//107.kod satırına kadar bu işlemi yapıyoruz
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
	   	      //şimdi sıralamaMatrisindeki bu 25 değeri bubble sort algoritması ile küçükten büyüğe sıralıcaz
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
	   	 
	           goruntuMatrisiPointer[s1*sutunlar+s2]=siralamaMatrisi[12];//ortanca degeri bulup ilgili indise atıcaz
	      }
	    }

// Get the current time
    	gettimeofday(&currentTime, NULL); //Seconds from the epoch time
	endTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0);	
	// Calculate the elapsed time in seconds
    	elapsedTime = endTime-startTime;
	cout << "Filtre icin gecen zaman(ms): " << elapsedTime*1000<< endl;
	    	   
    	
    	
	    char ciktiDosyasi[28];//Filtrelenmiş matrisin çıktı halini char dizisi şeklinde tanımladık örn:GoruntuMatrisi1
    	    string ciktiDosyasiUzantisi= "_filtered.txt";//argümanın sonuna uzantı eklemek için değişken tanımladık
    	    for(int s1=0; s1<15; s1++)//0 dan 15 e kadar gidicek for 
	    {
	      ciktiDosyasi[s1]=argv[1][s1+22];// argümanın toplam (.txt hariç) 38 karakteri var biz sadece GoruntuMatrisi1 örneği şeklinde 15 karakterli bir değer atadık	
	    }
	    for(int s1=0; s1<14; s1++)//sonra o 15 değerli karakterin sonuna 15 ten başlayarak(15 ten alttaki forda başlıyor) (devamı altta ki açıklama satırında)
	    {
	      ciktiDosyasi[s1+15] = ciktiDosyasiUzantisi[s1];//uzantıyı atadık artık içinde GoruntuMatrisi1_filtered.txt örneği şeklinde bir değer olmuş oldu
	    } 								
		
	    ofstream yazilacakDosya;//yazilacak dosyayı çıktı dosyası olarak ayarladık
	    yazilacakDosya.open(ciktiDosyasi, ios::out);//burda char dizisini çevirme işlemi ve yazılacak dosyayı açma işlemi yapıyoruz
            //yazilacakDosya<<satirlar;
            //yazilacakDosya<<sutunlar;
	    for(int s1=0; s1<satirlar; s1++)//satırlara kadar giden bir döngü
            {
               for(int s2=0; s2<sutunlar; s2++)//sütunlara kadar giden bir döngü
	       {
		  yazilacakDosya<<goruntuMatrisiPointer[s1*sutunlar+s2]<<"\t";//yazılacak matris değerleri matrisin ilk satır ve ilk sütunundan başlıcak
                  //dikkat et matrisin satır ve sütun bilgisinin yazdığı satırı almıcak onu almak isteseydik bu satırın üstündeki 7.ve 8.sütunu
                  //satı ve sütun sayısı bilgisini yazdırdığımız kısmı açıklama satırından kaldırmamız gerekirdi
					
	       }
	           yazilacakDosya<<endl;
	    }	

	    okunacakDosya.close();//okunacak dosyayı kapattık
	    yazilacakDosya.close();//yazılacak dosyayı kapattık 
	    delete [] goruntuMatrisiPointer;//dinamnik diziyi sildik
	
	
	
	return 0;
}
