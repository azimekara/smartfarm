# Smart Farm Projesi
Smart Farm projesi 4 tasktan oluşmaktadır. Projede amaç, sensörlerden alınan verileri websitesine iletmek ve web sitesinden manuel olarak dönüt sağlamaktır. Donanımda ana kontrol kartı olarak STM32F407 kullanılmış olup ESP32 ile websitesi bağlantısı kurulmuştur. Aşağıda her task açıklanmış, websitesindeki kontrol paneli ve donanım görüntüsü eklenmiştir.

#### Websitesi Ana Ekran Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/websitesigorunumu/anaekran.png)

1-) Yağmur sensörü kullanılarak yağmur algılanacak, web sitesine uyarı gönderilecek ve ağılın üstündeki perde webden yavaş-orta-hızlı olacak şekilde manuel olarak kapatılacak.(Çatı kontrolü step motor kullanılarak yapılmıştır.)

#### -Web Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/websitesigorunumu/yagmursensorugorunumu.png)
#### -Donanım Görünümü


![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/fritzingcizimleri/rainsistemifritzing.png)


2-)Hayvanlar touch sensörü kullanılarak ağıl girişinde sayılacak ve sayı web sitesine gönderilecek. Sistemde kaydolan hayvan sayısıyla karşılaştırılacak, hayvan sayısı bilinenden azsa webden buzzer öttürülecek. Hayvan sayısı aynı ise webden kapı kapatılacak.	

#### -Web Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/websitesigorunumu/kap%C4%B1gorunumu.png)

#### -Donanım Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/fritzingcizimleri/touchsistemifritzing.PNG)


3-) Gaz sensörü kullanılarak ortamda yangın var ise algılanarak web sitesine uyarı gidecek, webden buzzer  ve  yavaş-orta-hızlı şekilde fan çalıştırılacak.			

#### -Web Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/websitesigorunumu/yang%C4%B1ngorunumu.png)

#### -Donanım Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/fritzingcizimleri/gazsistemifritzing.PNG)


4-)Mesafe sensöründen alınan veri ile olukta durumu kontrol edilecek ve web sitesinde gösterilecek. Web sitesinden %30,%60,%100 seçenekleri ile yem eklemesi yapılacak.			

#### -Web Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/websitesigorunumu/yemgorunumu.png)

#### -Donanım Görünümü

![image](https://github.com/azimekara/smartfarm-webtek-/blob/main/fritzingcizimleri/mesafesistemifritzing.PNG)


