/****************************************************************************
**					            SAKARYA ÜNİVERSİTESİ
**			           BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				           BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: Proje/Tasarım
**				ÖĞRENCİ ADI : İsmail Emir Lambacıoğlu
**				ÖĞRENCİ NUMARASI.: B191210090
**				DERS GRUBU…………: 2.Öğretim C Grubu
****************************************************************************/


#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <locale.h>
using namespace std;



int main()
{
	time_t now = time(0);
	#pragma warning(suppress : 4996)
	char* time = ctime(&now);
	system("color 60");
	setlocale(LC_ALL, "turkish");
	ofstream dosyaYaz;
	ifstream dosyaOku;
	// Kitaplar
	string	ISBN, kitapİsmi, yazarAdı, yazarSoyadı, konu, tür, sayfaSayısı;
	// Okuyucu
	string tcNo, Adı, Soyadı, üyeNo, telefon, doğumTarihi,alabileceğiKitapSayısı;
	// Odunc
	string oduncTarihi,donusTarihi;
	string istenenKitap, istenenTC, alışTarih;
	string kullanıcıAdı, şifre, kullanıcıAdıData, şifreData,secim,secimMenu;
	char cevap;

	dosyaOku.open("kullanıcılar.txt");
	getline(dosyaOku, kullanıcıAdıData);
	getline(dosyaOku, şifreData);
	dosyaOku.close();


	do { // Buradali do-while döngümüz programımıza giriş panelini çalıştırıyor.

		cout << "Kullanıcı Adını Giriniz : ";
		cin >> kullanıcıAdı;
		cout << "Şifreninizi Giriniz : ";
		cin >> şifre;

		if (kullanıcıAdı != kullanıcıAdıData || şifre != şifreData) { // Eğer kullanıcı adımız ve şifremiz doğru değil ise tekrar denememizi söyleyen döngümüz.

			cout << "Kullanıcı Adı veya Şifrenizi Yanlış Girdiniz, Lütfen Tekrar Deneyiniz!" << endl;
		}

		else { // Eğer kullanıcı adımız ve şifremiz doğru ise uygulamamıza devam edebiliyoruz.

			cout << "Giriş Başarılı, Uygulamaya Devam Edebilirsiniz." << endl << endl;

		}

			
		
	}   while (kullanıcıAdı != kullanıcıAdıData || şifre != şifreData);

	cout << time;

	system("pause");
	system("cls");
	do { // Ana menümüz için kullandığımız do-while döngüsü.
		cout << "Program Ana Menüsü " << endl << endl << "-----------------------------" << endl;
		cout << "1 - Okuyucu Kaydı " << endl;
		cout << "2 - Okuyucu Kaydı Güncelleme " << endl;
		cout << "3 - Okuyucu Silme " << endl;
		cout << "4 - Okuyucu Üzerindeki Kitaplar Listesi " << endl;
		cout << "5 - Okuyucu Kitap Ödünç Alma " << endl;
		cout << "6 - Okuyucu Kitap Geri Döndürme " << endl;
		cout << "7 - Kitap Ekleme " << endl;
		cout << "8 - Kitap Silme " << endl;
		cout << "9 - Kitap Düzeltme " << endl;
		cout << "10 - Çıkış" << endl << endl;
		
		cout << "Seçiminiz : ";
		cin >> secim;

		if (secim == "1" ) { // 1.seçeneği seçersek aşağıdaki olayların gerçekleşmesini sağlayan şartımız.
			system("cls");
			dosyaYaz.open("okuyucu.txt", ios::app);

			do {

				cout << "Okuyucu TC Numarasını Giriniz : ";
				cin >> tcNo;
				cout << "Okuyucu Adını Giriniz : ";
				cin >> Adı;
				cout << "Okuyucu Soyadını Giriniz : ";
				cin >> Soyadı;
				cout << "Okuyucunun 5 Haneli Üye Numarasını Giriniz : ";
				cin >> üyeNo;
				cout << "Okuyucu Telefon Numarasını Giriniz : ";
				cin >> telefon;
				cout << "Okuyucu Doğum Tarihi : ";
				cin >> doğumTarihi;

				dosyaYaz << ' ' << tcNo << ' ' << Adı << ' ' << Soyadı << ' ' << üyeNo << ' ' << telefon << ' ' << doğumTarihi << endl;

				cout << "\n Başka kayıt yapmak ister misiniz ? (e/h)";
				cin >> cevap;
				

			} while (cevap!='h');
			dosyaYaz.close();
			system("cls");

		}

		else if (secim == "2") { // 2.seçeneği seçersek aşağıdaki olayların gerçekleşmesini sağlayan şartımız.
			system("cls");
			do { // Okuyucu güncellemek için bilgilerin okunup tekrar düzenlenmesini sağlayan döngümüz.
				string güncelleÜye;
				cout << "Bilgilerini güncellemek istediğiniz okuyucunun 5 haneli üye numarasını giriniz : ";
				cin >> güncelleÜye;
				ifstream dosyaOku("okuyucu.txt");
				ofstream dosyaYaz("okuyucu.tmp");
				while (dosyaOku >> tcNo >> Adı >> Soyadı >> üyeNo >> telefon >> doğumTarihi) {

					if (üyeNo != güncelleÜye) {

						dosyaYaz << tcNo << ' ' << Adı << ' ' << Soyadı << ' ' << üyeNo << ' ' << telefon << ' ' << doğumTarihi << endl;

					}
					
					else if (üyeNo == güncelleÜye) {
						cout << "\n Güncel bilgileri giriniz : \n ";
						cout << "Güncel TC NO : ";
						cin >> tcNo;
						cout << "Güncel Okuyu Adı : ";
						cin >> Adı;
						cout << "Güncel Soyadı : ";
						cin >> Soyadı;
						cout << "Güncel Üye No : ";
						cin >> üyeNo;
						cout << "Güncel Telefon : ";
						cin >> telefon;
						cout << "Güncel Doğum Tarihi : ";
						cin >> doğumTarihi;

						dosyaYaz << tcNo << ' ' <<  Adı << ' ' << Soyadı << ' ' << üyeNo << ' ' << telefon << ' ' << doğumTarihi;
					}


				}
				dosyaOku.close();
				dosyaYaz.close();
				remove("okuyucu.txt");
				rename("okuyucu.tmp", "okuyucu.txt");

				cout << "Güncelleme Yapıldı" << endl;
				cout << "Güncelleme işlemine devam etmek ister misiniz ? (e/h)";
				cin >> cevap;
			} while (cevap !='h');
			
			system("cls");



		}


		else if (secim == "3") { // 3.seçeneği seçersek aşağıdaki olayların gerçekleşmesini sağlayan şartımız.
			system("cls");
			string tc;
			do {
					// Silmek istediğimiz okuyucuyu dosyamızdan okuyup silen döngümüz.
				cout << "Silmek istediğiniz okuyucunun TC No'sunu giriniz : ";
				cin >> tc;
				dosyaOku.open("okuyucu.txt");
				dosyaYaz.open("okuyucu.tmp");
				
				while (dosyaOku >> tcNo >> Adı >> Soyadı >> üyeNo >> telefon >> doğumTarihi) {

					if (tcNo != tc) {

						dosyaYaz << tcNo << ' ' << Adı << ' ' << Soyadı << ' ' << üyeNo << ' ' << telefon << ' ' << doğumTarihi << endl;
					}
					

				}
				dosyaOku.close();
				dosyaYaz.close();
				dosyaOku.open("odunc.txt");
				dosyaYaz.open("odunc.tmp");
				while (dosyaOku >> istenenKitap >> istenenTC >> alışTarih) {

					if (istenenTC != tc) {
						dosyaYaz << istenenKitap << ' ' << istenenTC << ' ' << alışTarih << endl;
					}

				}
				dosyaOku.close();
				dosyaYaz.close();
				
				remove("okuyucu.txt");
				remove("odunc.txt");

				rename("okuyucu.tmp", "okuyucu.txt");
				rename("odunc.tmp", "odunc.txt");

				cout << "Silme işlemine devam etmek ister misiniz ? (e/h) ";
				cin >> cevap;

			} while (cevap !='h');
		}

		else if (secim == "4") {
		system("cls");

		string okuTC,isbn;
		do {

			cout << "Kitaplarını görmek istediğiniz okuyucunun TC'sini giriniz : ";
			cin >> okuTC;
			dosyaOku.open("odunc.txt");

			while (dosyaOku >> istenenKitap >> istenenTC >> alışTarih) {

				if(istenenTC == okuTC) {
				
					istenenKitap = isbn;

					dosyaOku.open("kitaplar.txt");

					while (dosyaOku >> ISBN >> kitapİsmi >> yazarAdı >> yazarSoyadı >> konu >> tür >> sayfaSayısı) {


						if (ISBN == isbn) {


							cout << kitapİsmi << "  " << yazarAdı << "  " << yazarSoyadı << "  " << konu << "  " << tür << endl;
						}
					}
					



					
				}
				
			}
			dosyaOku.close();
			

			cout << "Başka Kullanıcıların Üstündeki Kitapları Görmek İster Misiniz ? (e/h)";
			cin >> cevap;


		} while (cevap != 'h');
		



		}

		else if (secim == "5") {
		system("cls");
			
		dosyaOku.open("kitaplar.txt");
		dosyaYaz.open("odunc.txt");
		
		do { // Kitapları gösteren ve ödünç almamızı sağlayan döngümüz.

			cout << "Kitaplık : \n";
			while (dosyaOku >> ISBN >> kitapİsmi >> yazarAdı >> yazarSoyadı >> konu >> tür >> sayfaSayısı) {
				cout << ISBN << " " << kitapİsmi << endl ;

			}

			cout << "Ödünç Almak İstediğiniz Kitabın ISBN Numarasını Yazınız : ";
			cin >> istenenKitap;
			cout << "TC No Giriniz : ";
			cin >> istenenTC;
			cout << "Bugün'ün Tarihini Giriniz : ";
			cin >> alışTarih;

			dosyaYaz << istenenKitap << ' ' << istenenTC << ' ' << alışTarih << endl;

			
			dosyaYaz.open("kitaplar.tmp");

			while (dosyaOku >> ISBN >> kitapİsmi >> yazarAdı >> yazarSoyadı >> konu >> tür >> sayfaSayısı) { // Ödünç Alınan Dosyayı Silip tekrar kitapları düzenleyen döngümüz ve koşulumuz.


				if (istenenKitap != ISBN) {

					dosyaYaz << ISBN << ' ' << kitapİsmi << ' ' << yazarAdı << ' ' << yazarSoyadı << ' ' << konu << ' ' << tür << ' ' << sayfaSayısı << endl;

				}
			}
			dosyaOku.close();
			dosyaYaz.close();

			remove("kitaplar.txt");
			rename("kitaplar.tmp","kitaplar.txt");


			cout << "Kitap Ödünç Almaya Devam Etmek İster Misiniz ? (e/h) ";
			cin >> cevap;


			
			system("cls");
			




		} while (cevap!='h');


		}

		else if (secim == "6") {
		system("cls");
		string oduncDondur,dondurTarih;
		
		dosyaOku.open("odunc.txt");
		dosyaYaz.open("odunc.tmp");

		do { // Alınan Kitabı Geri Döndüren Döngümüz.

			cout << "Geri döndürmek istediğiniz kitabın ISBN numarasını giriniz : ";
			cin >> oduncDondur;
			cout << "Döndürme tarihi giriniz : ";
			cin >> dondurTarih;


			while (dosyaOku >> istenenKitap >> istenenTC >> alışTarih) {

				if (oduncDondur != istenenKitap) {

					dosyaYaz << istenenKitap << ' ' << istenenTC << ' ' << alışTarih << endl;
				}

			}
			dosyaOku.close();
			dosyaYaz.close();

			remove("odunc.txt");
			rename("odunc.tmp", "odunc.txt");

			dosyaOku.open("kitaplar.txt");
			dosyaYaz.open("kitaplar.txt", ios::app);

			while (dosyaOku >> ISBN >> kitapİsmi >> yazarAdı >> yazarSoyadı >> konu >> tür >> sayfaSayısı) {

				if (oduncDondur == ISBN) {

					dosyaYaz << ISBN << ' ' << kitapİsmi << ' ' << yazarAdı << ' ' << yazarSoyadı << ' ' << konu << ' ' << tür << ' ' << sayfaSayısı << endl;
				}
			}

			dosyaOku.close();
			dosyaYaz.close();

			cout << "Geri döndürme işlemine devam etmek ister misiniz ? (e/h)";
			cin >> cevap;








		} while (cevap != 'h');
}

		else if (secim == "7") {
		system("cls");

		dosyaYaz.open("kitaplar.txt", ios::app);

		do { // Yeni Kitap Eklemek İçin kullandığımız döngümüz.


			cout << "Kitap ISBN Numarasını Giriniz : ";
			cin >> ISBN;
			cout << "Kitap Adını Giriniz : ";
			cin >> kitapİsmi;
			cout << "Yazar Adını Giriniz : ";
			cin >> yazarAdı;
			cout << "Yazar Soyadını Giriniz : ";
			cin >> yazarSoyadı;
			cout << "Kitabın Konusunu Giriniz : ";
			cin >> konu;
			cout << "Kitabın Türünü Giriniz : ";
			cin >> tür;
			cout << "Kitabın Sayfa Sayısını Giriniz : ";
			cin >> sayfaSayısı;

			dosyaYaz << ISBN << ' ' << kitapİsmi << ' ' << yazarAdı << ' ' << yazarSoyadı << ' ' << konu << ' ' << tür << ' ' << sayfaSayısı << endl;

			cout << "\n Başka kayıt yapmak ister misiniz ? (e/h)";
			cin >> cevap;






		} while (cevap != 'h');
			


		}

		else if (secim == "8") {
			
		system("cls");

		string isim;

		do { // Kitap silmekte kullandığımız döngümüz.
			cout << "Silmek istediğiniz kitabın ismini giriniz : ";
			cin >> isim;

			dosyaOku.open("kitaplar.txt");
			dosyaYaz.open("kitaplar.tmp");

			while (dosyaOku >> ISBN >> kitapİsmi >> yazarAdı >> yazarSoyadı >> konu >> tür >> sayfaSayısı) { // Kitapları okuyup içinden ismini yazdığımız kitabı silen döngümüz.


				if (kitapİsmi != isim) {

					dosyaYaz << ISBN << ' ' << kitapİsmi << ' ' << yazarAdı << ' ' << yazarSoyadı << ' ' << konu << ' ' << tür << ' ' << sayfaSayısı << endl;

				}

			}
			dosyaOku.close();
			dosyaYaz.close();

			remove("kitaplar.txt");
			rename("kitaplar.tmp", "kitaplar.txt");

			cout << "Silme işlemine devam etmek ister misiniz ? (e/h) ";
			cin >> cevap;
		} while (cevap != 'h');
		

		}

		else if (secim == "9") {
		system("cls");

		do { // Kitap düzeltmemizi sağlayan döngümüz.
			
			string güncelleKitap;
			cout << "Düzeltmek istediğiniz kitabın ISBN numarasını giriniz : ";
			cin >> güncelleKitap;

			dosyaOku.open("kitaplar.txt");
			dosyaYaz.open("kitaplar.tmp");

			while (dosyaOku >> ISBN >> kitapİsmi >> yazarAdı >> yazarSoyadı >> konu >> tür >> sayfaSayısı) { // Kitapları okuyup onları güncellememizi sağlayan döngümüz ve şartımız.


				if (ISBN != güncelleKitap) {

					dosyaYaz << ISBN << ' ' << kitapİsmi << ' ' << yazarAdı << ' ' << yazarSoyadı << ' ' << konu << ' ' << tür << ' ' << sayfaSayısı << endl;

				}

				else if (ISBN == güncelleKitap) {

					cout << "Düzeltmek istediğiniz bilgileri giriniz :  \n";
					cout << "Yeni ISBN Numarasını Giriniz : ";
					cin >> ISBN;
					cout << "Yeni Kitap İsmini Giriniz : ";
					cin >> kitapİsmi;
					cout << "Yeni Yazar Adını Giriniz : ";
					cin >> yazarAdı;
					cout << "Yeni Yazar Soyadını Giriniz : ";
					cin >> yazarSoyadı;
					cout << "Yeni Kitap Konusunu Giriniz : ";
					cin >> konu;
					cout << "Yeni Kitap Türünü Giriniz : ";
					cin >> tür;
					cout << "Yeni Sayfa Sayısını Giriniz : ";
					cin >> sayfaSayısı;

					dosyaYaz << ISBN << ' ' << kitapİsmi << ' ' << yazarAdı << ' ' << yazarSoyadı << ' ' << konu << ' ' << tür << ' ' << sayfaSayısı << endl;


				}

			}
			dosyaOku.close();
			dosyaYaz.close();
			remove("kitaplar.txt");
			rename("kitaplar.tmp", "kitaplar.txt");
			cout << "Düzeltme Yapıldı" << endl;
			cout << "Düzeltme işlemine devam etmek ister misiniz ? (e/h)";
			cin >> cevap;
	


		} while (cevap != 'h');
			
			
		}

		else if (secim == "10") {

		cout << time << endl;
		cout << "Çıkış Yapıldı.";
		}






	} while (secim != "10");
	

















}


