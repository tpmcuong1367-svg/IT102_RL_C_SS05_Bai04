Module Quan ly Hang doi Kham benh (Kiosk MedCare)
Thiet ke mang song song (Parallel Arrays)
Moi benh nhan duoc luu tai cung mot chi so i trong tat ca cac mang. Chi so i o mang nay tuong ung voi chi so i o mang kia, nen moi mang giu mot truong thong tin.

Mang	Kieu	Y nghia
stt[MAX]	int	So thu tu (= chi so + 1)
ten[MAX][30]	char	Ten benh nhan
tuoi[MAX]	int	Tuoi
uuTien[MAX]	int	1 = uu tien (tuoi > 70 hoac mang thai), 0 = thuong
bhyt[MAX]	int	1 = co BHYT, 0 = khong
phi[MAX]	int	Phi kham so bo (200.000 hoac 40.000 VND)
thaiKy[MAX]	int	1 = mang thai (de tinh lai uu tien khi sua tuoi)
bacSi[MAX]	int	Ma bac si (1..5), de kiem tra toi da 5 benh nhan/bac si/khung gio
khungGio[MAX]	int	Khung gio (1..8)
Bien n la so benh nhan hien co. Chi cac phan tu tu 0 den n - 1 la hop le.

Cach xu ly
Them: benh nhan thuong xep cuoi hang. Benh nhan uu tien duoc chen sau nhom uu tien da co (dau hang), cac phan tu phia sau doi sang phai 1 o.
Huy: don cac phan tu phia sau len 1 o, giam n, xoa sach o cuoi de khong con du lieu rac.
Danh so lai: sau moi lan them/huy, stt[i] = i + 1 nen so thu tu luon lien tuc, khong bi dut.
Phi: tinh bang so nguyen, co BHYT thu 200000 * 20 / 100 = 40000.
Nhap lieu: dung fgets() cho ca so va chuoi, loai bo \n va xoa phan thua trong bo dem nen khong bi troi lenh.
