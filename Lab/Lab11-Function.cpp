/*
    จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
    
    หมายเหตุ: ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
    153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
    370 = 3^3 + 7^3 + 0^3

    Test Case:
        Enter Number:
            153
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            370
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            372
    Output:
        Not Pass.
*/

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
        printf( "Pass.\n" ) ;
    } else {
        printf( "Not Pass.\n" ) ;
    }

    return 0 ;
}