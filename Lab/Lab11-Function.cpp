#include <stdio.h>
#include <math.h>

// ฟังก์ชันสำหรับคำนวณเลขยกกำลังของแต่ละหลักและบวกกัน
int isArmstrong( int num ) {
    int sum = 0 ;
    int originalNum = num ;
    int digits = 0 ;

    // นับจำนวนหลักของตัวเลข
    while ( num != 0 ) {
        digits++ ;
        num /= 10 ;
    }

    // คำนวณเลขยกกำลังและบวกกัน
    num = originalNum ;
    while ( num != 0 ) {
        int remainder = num % 10 ;
        sum += pow( remainder, digits ) ;
        num /= 10 ;
    }

    // ตรวจสอบว่าเป็นตัวเลขอาร์มสตรองหรือไม่
    if ( sum == originalNum ) {
        return 1 ; // เป็นตัวเลขอาร์มสตรอง
    } else {
        return 0 ; // ไม่เป็นตัวเลขอาร์มสตรอง
    }
}

int main() {
    int number ;

    // รับตัวเลขจากผู้ใช้
    printf( "Enter number: " ) ;
    scanf( "%d", &number ) ;

    // เรียกใช้ฟังก์ชัน isArmstrong เพื่อตรวจสอบ
    if ( isArmstrong( number ) == 1 ) {
        printf( "Pass\n" ) ;
    } else {
        printf( "Not Pass\n" ) ;
    }

    return 0 ;
}