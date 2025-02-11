## merhabalar👋

<!--
**5220505043/5220505043** 

# Tarih ve Saat Farkı Hesaplama

Bu program, kullanıcıdan alınan iki tarih ve saat bilgisini kullanarak, bunları Epoch zamanına (Unix timestamp) dönüştürür ve aralarındaki farkı saniye cinsinden hesaplar.

## Kullanım

1. Program çalıştırıldığında, kullanıcıdan iki tarih ve saat bilgisi istenir.
2. Girilen tarihler Epoch zamanına çevrilir.
3. İki tarih arasındaki fark saniye cinsinden hesaplanarak ekrana yazdırılır.

### Örnek Kullanım
```
Birinci tarih ve saati girin (YYYY MM DD HH MM SS): 2024 02 10 12 30 00
Ikinci tarih ve saati girin (YYYY MM DD HH MM SS): 2024 02 11 14 45 00

Birinci tarih epoch zamanı: 1707564600 saniye
Ikinci tarih epoch zamanı: 1707653100 saniye
Iki tarih arasindaki fark: 88500 saniye
```

## Derleme ve Çalıştırma

Programı derlemek için:
```
gcc -o time_diff time_diff.c
```
Çalıştırmak için:
```
./time_diff
```



