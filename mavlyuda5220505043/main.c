//
//  main.c
//  mavlyuda5220505043
//
//  Created by mavlyuda almazova on 10.02.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct ların saat ve tarihini girelim
struct DateTime {
    int year, month, day, hour, minute, second;
};

// Union bu hem struct hem epoch zamanına dönüştüre bilir
union TimeUnion {
    struct DateTime dt;   // Kullanıcıya yardımcı tarih yapısı
    time_t epochTime;     // Epoch zamanı saniye belirtelim
};

// DateTime'da epoch zamanını değiştirelim
time_t convertToEpoch(struct DateTime dt) {
    struct tm timeStruct = {0};
    timeStruct.tm_year = dt.year - 1900;  // tm_year 1900'dan itibaren hesaplar
    timeStruct.tm_mon = dt.month - 1;     // tm_mon 0-11 arasındakılar
    timeStruct.tm_mday = dt.day;
    timeStruct.tm_hour = dt.hour;
    timeStruct.tm_min = dt.minute;
    timeStruct.tm_sec = dt.second;
    
    return mktime(&timeStruct);  // mktime fonksiyonu epoch zamanını döndürür
}

// İki tarihin arasındaki farkı hesaplayalım
double calculateTimeDifference(time_t t1, time_t t2) {
    return difftime(t2, t1);  // difftime girdiğimizde iki epoch zaman arasındaki farkı saniye ile gösterir
}

int main(void) {
    union TimeUnion time1, time2;
    struct DateTime input1, input2;
    double timeDifference;
    
    // Kullanıcıdan iki tarih ve saat alalım
    printf("Birinci tarih ve saati girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &input1.year, &input1.month, &input1.day,
                               &input1.hour, &input1.minute, &input1.second);
    
    printf("Ikinci tarih ve saati girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &input2.year, &input2.month, &input2.day,
                               &input2.hour, &input2.minute, &input2.second);
    
    // union kullanarak kullanıcıdan tarihleri ve epoch zamanına dönüştürme
    time1.dt = input1;
    time2.dt = input2;

    // Epoch zamanını elde ediyoruz
    time_t epochTime1 = convertToEpoch(time1.dt);
    time_t epochTime2 = convertToEpoch(time2.dt);
    
    // yazdığımız tarihler arasındaki farkları hesaplayalım
    timeDifference = calculateTimeDifference(epochTime1, epochTime2);
    
    // Epoch zamanlarını ve farkı ekrana yazdıralım 
    printf("\nBirinci tarih epoch zamanı: %ld saniye\n", epochTime1);
    printf("Ikinci tarih epoch zamanı: %ld saniye\n", epochTime2);
    printf("Iki tarih arasindaki fark: %.0f saniye\n", timeDifference);

    return 0;
}
