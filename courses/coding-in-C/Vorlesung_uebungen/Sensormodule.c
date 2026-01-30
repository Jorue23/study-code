#include <stdio.h>

int main() {
    unsigned char status = 0xA7;  // Binär: 1010 0111
    
    printf("Status-Byte: 0x%02X (Binär: ", status);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (status >> i) & 1);
        if (i == 4) printf(" ");
    }
    printf(")\n\n");
    
    if (status & 0x80) {  // 0x80 = 1000 0000
        printf("Fehler: JA\n");
    } else {
        printf("Fehler: NEIN\n");
    }
    
    if (status & 0x40) {  // 0x40 = 0100 0000
        printf("Uebertemperatur: JA\n");
    } else {
        printf("Uebertemperatur: NEIN\n");
    }
    
    if (status & 0x20) {  // 0x20 = 0010 0000
        printf("Unterspannung: JA\n");
    } else {
        printf("Unterspannung: NEIN\n");
    }
    
    unsigned char messwert = status & 0x0F;  // 0x0F = 0000 1111
    printf("\nMesswert (Bits 0-3): %u\n", messwert);
    
    return 0;
}