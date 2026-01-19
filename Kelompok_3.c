#include <stdio.h>
#include <string.h>
#include <ctype.h>

int romawi(char r) {
    if (r == 'I') return 1;
    if (r == 'V') return 5;
    if (r == 'X') return 10;
    if (r == 'L') return 50;
    if (r == 'C') return 100;
    if (r == 'D') return 500;
    if (r == 'M') return 1000;
    return 0;
}

int main() {
    char ang[20];
    int i, tot = 0, cs;

    printf("================================================\n");
    printf("\tTOLONG PILIH MENU DIBAWAH INI!!\n");
    printf("\t1. KONVERSI ROMAWI (PERULANGAN)\n");
    printf("\t2. CEK KELAYAKAN BEASISWA (KONDISI)\n");
    printf("\t3. MENGHITUNG NILAI (ARRAY)\n");
    printf("================================================\n");
    printf("\tPILIH MENU (1-3) : ");
    scanf("%d", &cs);

    switch (cs) {
        case 1:
            printf("MASUKKAN HURUF ROMAWI : ");
            scanf("%s", ang);

            for (i = 0; i < strlen(ang); i++) {
                ang[i] = toupper(ang[i]);

                if (romawi(ang[i]) < romawi(ang[i + 1])) {
                    tot -= romawi(ang[i]);
                } else {
                    tot += romawi(ang[i]);
                }
            }

            printf("KONVERSI HURUF ROMAWI %s MENJADI BILANGAN %d\n", ang, tot);
            break;

        case 2: {
            float ipk;
            int penghasilan;

            printf("MASUKKAN IPK          : ");
            scanf("%f", &ipk);
            printf("PENGHASILAN ORANG TUA : ");
            scanf("%d", &penghasilan);

            if (ipk < 0 || ipk > 4.0 || penghasilan < 0) {
                printf("DATA TIDAK VALID\n");
            } else if (ipk >= 3.5 && penghasilan <= 3000000) {
                printf("STATUS : BEASISWA PENUH\n");
            } else if (ipk >= 3.0 && penghasilan <= 5000000) {
                printf("STATUS : BEASISWA SEBAGIAN\n");
            } else {
                printf("STATUS : TIDAK LAYAK BEASISWA\n");
            }
            break;
        }

        case 3: {
            int nilai[10];
            int n, total = 0;
            float rata;

            printf("MASUKKAN JUMLAH DATA (MAX 10) : ");
            scanf("%d", &n);

            if (n <= 0 || n > 10) {
                printf("JUMLAH DATA TIDAK VALID\n");
            } else {
                for (i = 0; i < n; i++) {
                    printf("MASUKKAN NILAI KE-%d : ", i + 1);
                    scanf("%d", &nilai[i]);
                    total += nilai[i];
                }

                rata = (float) total / n;

                printf("TOTAL NILAI     : %d\n", total);
                printf("RATA-RATA NILAI : %.2f\n", rata);
            }
            break;
        }

        default:
            printf("MENU HANYA 1-3 SAJA!!");
    }

    return 0;
}