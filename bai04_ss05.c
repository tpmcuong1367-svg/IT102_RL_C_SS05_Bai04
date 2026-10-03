#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define GIA_KHAM 200000
#define TOI_DA_BS 5

int stt[MAX];
char ten[MAX][30];
int tuoi[MAX];
int uuTien[MAX];
int bhyt[MAX];
int phi[MAX];
int thaiKy[MAX];
int bacSi[MAX];
int khungGio[MAX];
int n = 0;

void catDong(char s[])
{
    int len = strlen(s);
    int c;
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
}

int docSo(char loiNhac[], int thap, int cao)
{
    char dong[50];
    int so;
    while (1) {
        printf("%s", loiNhac);
        if (fgets(dong, 50, stdin) == NULL) {
            exit(0);
        }
        catDong(dong);
        if (sscanf(dong, "%d", &so) == 1 && so >= thap && so <= cao) {
            return so;
        }
        printf("Gia tri khong hop le (%d..%d).\n", thap, cao);
    }
}

void docTen(char loiNhac[], char kq[])
{
    while (1) {
        printf("%s", loiNhac);
        if (fgets(kq, 30, stdin) == NULL) {
            exit(0);
        }
        catDong(kq);
        if (strlen(kq) > 0) {
            return;
        }
        printf("Ten khong duoc de trong.\n");
    }
}

int tinhPhi(int coBhyt)
{
    if (coBhyt == 1) {
        return GIA_KHAM * 20 / 100;
    }
    return GIA_KHAM;
}

void saoChep(int dich, int nguon)
{
    strcpy(ten[dich], ten[nguon]);
    tuoi[dich] = tuoi[nguon];
    thaiKy[dich] = thaiKy[nguon];
    uuTien[dich] = uuTien[nguon];
    bhyt[dich] = bhyt[nguon];
    phi[dich] = phi[nguon];
    bacSi[dich] = bacSi[nguon];
    khungGio[dich] = khungGio[nguon];
}

void danhSoLai()
{
    for (int i = 0; i < n; i++) {
        stt[i] = i + 1;
    }
}

int demTai(int bs, int kg)
{
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (bacSi[i] == bs && khungGio[i] == kg) {
            dem++;
        }
    }
    return dem;
}

int chen(char tenMoi[], int tuoiMoi, int thaiMoi, int bhytMoi, int bs, int kg)
{
    int uu = (tuoiMoi > 70 || thaiMoi == 1);
    int vt = n;
    if (uu) {
        vt = 0;
        while (vt < n && uuTien[vt] == 1) {
            vt++;
        }
    }
    for (int i = n; i > vt; i--) {
        saoChep(i, i - 1);
    }
    strcpy(ten[vt], tenMoi);
    tuoi[vt] = tuoiMoi;
    thaiKy[vt] = thaiMoi;
    uuTien[vt] = uu;
    bhyt[vt] = bhytMoi;
    phi[vt] = tinhPhi(bhytMoi);
    bacSi[vt] = bs;
    khungGio[vt] = kg;
    n++;
    danhSoLai();
    return vt;
}

void xoa(int vt)
{
    for (int i = vt; i < n - 1; i++) {
        saoChep(i, i + 1);
    }
    n--;
    ten[n][0] = '\0';
    stt[n] = 0;
    tuoi[n] = 0;
    thaiKy[n] = 0;
    uuTien[n] = 0;
    bhyt[n] = 0;
    phi[n] = 0;
    bacSi[n] = 0;
    khungGio[n] = 0;
    danhSoLai();
}

void inDong(int i)
{
    printf("%-4d %-30s %-5d %-8s %-6s %-9d %-4d %-4d\n",
           stt[i], ten[i], tuoi[i], uuTien[i] ? "Uu tien" : "Thuong",
           bhyt[i] ? "Co" : "Khong", phi[i], bacSi[i], khungGio[i]);
}

void inTieuDe()
{
    printf("%-4s %-30s %-5s %-8s %-6s %-9s %-4s %-4s\n",
           "STT", "Ten", "Tuoi", "Loai", "BHYT", "Phi(VND)", "BS", "Gio");
}

void tiepNhan()
{
    char tenMoi[30];
    int t, thai, b, bs, kg, vt;
    if (n >= MAX) {
        printf("Hang doi da day (%d benh nhan).\n", MAX);
        return;
    }
    docTen("Ten benh nhan: ", tenMoi);
    t = docSo("Tuoi (1..120): ", 1, 120);
    thai = docSo("Mang thai (0 = khong, 1 = co): ", 0, 1);
    b = docSo("BHYT (0 = khong, 1 = co): ", 0, 1);
    bs = docSo("Ma bac si (1..5): ", 1, 5);
    kg = docSo("Khung gio (1..8): ", 1, 8);
    if (demTai(bs, kg) >= TOI_DA_BS) {
        printf("Bac si %d khung gio %d da du %d benh nhan. Vui long chon bac si/khung gio khac.\n",
               bs, kg, TOI_DA_BS);
        return;
    }
    vt = chen(tenMoi, t, thai, b, bs, kg);
    printf("Dang ky thanh cong. STT: %d, phi kham: %d VND", stt[vt], phi[vt]);
    if (uuTien[vt] == 1) {
        printf(" (Uu tien)");
    }
    printf("\n");
}

void hienThi()
{
    if (n == 0) {
        printf("Hang doi trong.\n");
        return;
    }
    inTieuDe();
    for (int i = 0; i < n; i++) {
        inDong(i);
    }
    printf("Tong so benh nhan: %d\n", n);
}

void capNhat()
{
    int vt, chon, tuoiMoi, uuCu;
    char tenTam[30];
    int thai, b, bs, kg;
    if (n == 0) {
        printf("Hang doi trong.\n");
        return;
    }
    vt = docSo("Nhap STT can sua: ", 1, n) - 1;
    inTieuDe();
    inDong(vt);
    printf("1. Sua ten\n2. Sua tuoi\n3. Sua BHYT\n");
    chon = docSo("Chon: ", 1, 3);
    if (chon == 1) {
        docTen("Ten moi: ", ten[vt]);
    } else if (chon == 2) {
        tuoiMoi = docSo("Tuoi moi (1..120): ", 1, 120);
        uuCu = uuTien[vt];
        tuoi[vt] = tuoiMoi;
        if ((tuoiMoi > 70 || thaiKy[vt] == 1) != uuCu) {
            strcpy(tenTam, ten[vt]);
            thai = thaiKy[vt];
            b = bhyt[vt];
            bs = bacSi[vt];
            kg = khungGio[vt];
            xoa(vt);
            chen(tenTam, tuoiMoi, thai, b, bs, kg);
        }
    } else {
        bhyt[vt] = docSo("BHYT moi (0 = khong, 1 = co): ", 0, 1);
        phi[vt] = tinhPhi(bhyt[vt]);
    }
    printf("Da cap nhat.\n");
}

void huy()
{
    int vt;
    if (n == 0) {
        printf("Hang doi trong.\n");
        return;
    }
    vt = docSo("Nhap STT can huy: ", 1, n) - 1;
    xoa(vt);
    printf("Da huy. Cac STT phia sau da duoc doi len.\n");
}

void timKiem()
{
    int chon, so, dem = 0;
    char tenTim[30];
    if (n == 0) {
        printf("Hang doi trong.\n");
        return;
    }
    printf("1. Tim theo STT\n2. Tim theo ten\n");
    chon = docSo("Chon: ", 1, 2);
    if (chon == 1) {
        so = docSo("Nhap STT: ", 1, MAX);
        if (so <= n) {
            inTieuDe();
            inDong(so - 1);
            dem = 1;
        }
    } else {
        docTen("Nhap ten: ", tenTim);
        for (int i = 0; i < n; i++) {
            if (strcmp(ten[i], tenTim) == 0) {
                if (dem == 0) {
                    inTieuDe();
                }
                inDong(i);
                dem++;
            }
        }
    }
    if (dem == 0) {
        printf("Khong tim thay.\n");
    }
}

int main(void)
{
    int chon;
    do {
        printf("\n===== KIOSK DANG KY KHAM BENH =====\n");
        printf("1. Tiep nhan benh nhan\n");
        printf("2. Hien thi hang doi\n");
        printf("3. Cap nhat thong tin\n");
        printf("4. Huy so thu tu\n");
        printf("5. Tim kiem\n");
        printf("0. Thoat\n");
        chon = docSo("Chon chuc nang: ", 0, 5);
        switch (chon) {
            case 1: tiepNhan(); break;
            case 2: hienThi(); break;
            case 3: capNhat(); break;
            case 4: huy(); break;
            case 5: timKiem(); break;
        }
    } while (chon != 0);
    printf("Tam biet.\n");
    return 0;
}