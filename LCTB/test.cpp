// 0850080033_NguyenPhuongNga_08THMT

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 1
bool laNamNhuan(int nam)
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam)
{
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && laNamNhuan(nam))
    {
        return 29;
    }
    return ngayTrongThang[thang];
}

bool ngayHopLe(int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12)
    {
        return false;
    }
    if (ngay < 1 || ngay > soNgayTrongThang(thang, nam))
    {
        return false;
    }
    return true;
}

void timNgayHomSau(int &ngay, int &thang, int &nam)
{
    ngay++;
    if (ngay > soNgayTrongThang(thang, nam))
    {
        ngay = 1;
        thang++;
        if (thang > 12)
        {
            thang = 1;
            nam++;
        }
    }
}

void timNgayHomTruoc(int &ngay, int &thang, int &nam)
{
    ngay--;
    if (ngay == 0)
    {
        thang--;
        if (thang == 0)
        {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
}

// 2
double tinhTienTaxi(int soKm)
{
    double giaKmDau = 15000;
    double giaTuKm2Den5 = 13500;
    double giaTuKm6TroDi = 11000;
    double giamGiaTren120Km = 0.10;

    double tongTien = 0.0;

    if (soKm > 0)
    {
        tongTien += giaKmDau;
        soKm--;

        if (soKm > 0)
        {
            int kmDen5 = min(4, soKm);
            tongTien += kmDen5 * giaTuKm2Den5;
            soKm -= kmDen5;
        }

        if (soKm > 0)
        {
            tongTien += soKm * giaTuKm6TroDi;
        }

        if (soKm > 120)
        {
            double giamGia = tongTien * giamGiaTren120Km;
            tongTien -= giamGia;
        }
    }

    return tongTien;
}

// ===========================================================
int main()
{
    cout << "1. Tính ngày tháng năm" << endl;
    cout << "2. Tính tiền taxi" << endl;
    cout << "3. Tìm ước chung lớn nhất" << endl;
    cout << "4. Xếp số theo thứ tự tăng dần" << endl;
    cout << "5: Giải pt bậc 2 " << endl;
    cout << "Số nhập là: ";

    int n;
    cin >> n;
    switch (n)
    {
        // =========================================

    case 1:
    {
        int ngay, thang, nam;
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;

        if (ngayHopLe(ngay, thang, nam))
        {
            cout << "Ngay thang nam hop le." << endl;
            cout << "Thang " << thang << " co " << soNgayTrongThang(thang, nam) << " ngay." << endl;

            int ngayHomSau = ngay, thangHomSau = thang, namHomSau = nam;
            timNgayHomSau(ngayHomSau, thangHomSau, namHomSau);
            cout << "Ngay hom sau la: " << ngayHomSau << "/" << thangHomSau << "/" << namHomSau << endl;

            int ngayHomTruoc = ngay, thangHomTruoc = thang, namHomTruoc = nam;
            timNgayHomTruoc(ngayHomTruoc, thangHomTruoc, namHomTruoc);
            cout << "Ngay hom truoc la: " << ngayHomTruoc << "/" << thangHomTruoc << "/" << namHomTruoc << endl;
        }
        else
        {
            cout << "Ngay thang nam khong hop le." << endl;
        }
        break;
    }

    case 2:
    {
        int soKm;
        cout << "Nhap so km da di: ";
        cin >> soKm;

        if (soKm > 0)
        {
            double tienTaxi = tinhTienTaxi(soKm);
            cout << "Tien di taxi: " << tienTaxi << " dong" << endl;
        }
        else
        {
            cout << "So km khong hop le." << endl;
        }
    }

    case 3:
    {

        int a, b;

        cout << "Nhập 2 số nguyên dương a, b: ";
        cin >> a >> b;

        int ucln = 1;

        for (int i = 1; i <= min(a, b); i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                ucln = i;
            }
        }

        cout << "Ước chung lớn nhất của " << a << " và " << b << " là: " << ucln << endl;
    }
    break;

    case 4:
    {
        int a, b, c;
        cout << "Nhập a : ";
        cin >> a;
        cout << "Nhập b : ";
        cin >> b;
        cout << "Nhập c : ";
        cin >> c;
        if (a > b && a > c)
        {
            cout << a << " là số lớn nhất";
        }
        if (b > a && b > c)
        {
            cout << b << " là số lớn nhất";
        }
        if (c > b && c > a)
        {
            cout << c << " là số lớn nhất";
        }
        else
        {
            cout << "Có 2 hoặc 3 số bằng nhau";
        }
    }
    break;

    case 5:
    {
        double a, b, c;
        cout << "Nhập số a: ";
        cin >> a;
        cout << "Nhập số b: ";
        cin >> b;
        cout << "Nhập số c: ";
        cin >> c;
        if (a == 0)
        {
            if (b == 0)
            {
                if (c == 0)
                {
                    cout << "Phương trình vô số nghiệm" << endl;
                }
                else
                {
                    cout << "Phương trình vô nghiệm." << endl;
                }
            }
            else
            {
                double x = -c / b;
                cout << "Phương trình có 1 nghiệm duy nhất x = " << x << endl;
            }
        }
        else
        {
            double delta = b * b - 4 * a * c;

            if (delta > 0)
            {
                double x1 = (-b + sqrt(delta)) / (2 * a);
                double x2 = (-b - sqrt(delta)) / (2 * a);
                cout << "Phương trình có 2 nghiệm phân biệt: x1 = " << x1 << ", x2 = " << x2 << endl;
            }
            else if (delta == 0)
            {
                double x = -b / (2 * a);
                cout << "Phương trình có nghiệm kép x1 = x2 = " << x << endl;
            }
            else
            {
                cout << "Phương trình vô nghiệm." << endl;
            }
        }
    }
    break;

    default:
    {
        cout << "Không có bài chọn";
    }
    break;
    }
}
