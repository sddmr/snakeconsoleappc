#SnakeConsoleApp (C)
Bu proje, C dilinde yazılmış konsol tabanlı bir yılan oyunudur. Kullanıcı, 'WASD' tuşları ile yılanı yönlendirir ve yılan yemi yedikçe uzar. Amaç, olabildiğince fazla yem yiyip en yüksek skora ulaşmak. Yılan duvarlara veya kendi gövdesine çarptığında oyun biter.

Temel Fonksiyonlar
setup()
Bu fonksiyon, oyunun başlangıç ayarlarını yapar. Yılanın başlangıç pozisyonu, yemin rastgele bir konuma yerleştirilmesi ve skor sıfırlanması gibi işlemler burada gerçekleştirilir.

draw()
Oyun alanını çizmek için kullanılır. Oyun sınırları, yılan ve yem her turda bu fonksiyon tarafından ekrana basılır. Sistem komutlarıyla (ANSI escape kodları) imleç ekranda taşınarak ekran sürekli tazelenmek yerine yalnızca gerekli alanlar güncellenir.

input()
Kullanıcının oyunu yönlendirmesi için gerekli girişler burada alınır. 'WASD' tuşları kullanılarak yılan yukarı, aşağı, sola ve sağa yönlendirilebilir. Ayrıca 'x' tuşu ile oyun sonlandırılabilir.

logic()
Oyun mekaniklerinin yönetildiği ana fonksiyondur. Yılanın hareketi, yemin yenmesi, yılanın duvara çarpması veya kendi gövdesine çarpması gibi durumlar bu fonksiyonda kontrol edilir. Yem yendiğinde yılan uzar ve skor artar.

main()
Oyunun ana döngüsüdür. Oyun bitene kadar draw(), input() ve logic() fonksiyonları sırayla çalıştırılır.

Ekranın Sürekli Tazelenmesi Sorunu
Konsol tabanlı oyunlarda system("cls") komutunu kullanarak ekranı her karede tamamen temizlemek yerine, daha etkili bir yöntem kullanmak gerekir. Çünkü ekranı sürekli temizlemek, görsel olarak rahatsız edici bir yanıp sönmeye neden olabilir.

Bu sorunu çözmek için:

İmleç Konumlandırma: Ekranı temizlemek yerine sadece imleci ekran üzerinde yeni pozisyona taşıyarak gerekli kısımlar güncellenir. Bu sayede yılanın hareketi daha akıcı görünür.

ANSI Escape Kodları ile İmleci Gizleme: Yılan hareket ederken imlecin ekranda görünmemesi için ANSI escape kodları kullanılarak imleç gizlenir. Oyun bittiğinde imleç tekrar görünür hale getirilir.

Öne Çıkan Teknikler
ANSI Kodları ile Ekran Kontrolü: gotoxy() fonksiyonu ile imlecin istenilen koordinata taşınması sağlanır. Böylece ekranda sadece gerekli yerler güncellenir.

Sistem Uyumluluğu: Ekranı tazelemek için kullanılan gotoxy() fonksiyonu ve ANSI escape kodları, hem Windows hem de Unix tabanlı sistemlerde uyumlu şekilde çalışır.

Nasıl Çalıştırılır?
C derleyicinizde projeyi derleyin.
Konsolda oyunu başlatın.
'WASD' tuşları ile yılanı yönlendirin.
Yılanın başını yemi yemesi için yönlendirin, her yem yediğinizde yılan uzayacaktır.
Yılanın gövdesine veya duvarlara çarpması durumunda oyun biter.
Proje Dosyaları
snake.c: Ana oyun dosyası, tüm oyunun mantığı burada kodlanmıştır.
