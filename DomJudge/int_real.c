#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int contador(const char *cont);
double string_to_double(const char *str);

int main() {
    int d;
    char m[16];
    double b;

    FILE *ent = fopen("entrada.dat", "r");
    FILE *inte = fopen("inteiros.dat", "w");
    FILE *re = fopen("reais.dat", "w");

    if (ent == NULL || inte == NULL || re == NULL) {
        printf("Não é possível abrir um dos arquivos!");
        return 1;
    }

    // Ler valores do arquivo de entrada
    while (fscanf(ent, "%d %s", &d, m) == 2) {
        int count = contador(m);

        if (count == strlen(m)) { // Se todos os caracteres são dígitos, é um número inteiro
            int num;
            if (m[0] == '-') {
                num = 1000000 - atoi(m + 1);
            } else {
                num = atoi(m);
            }
            printf("Inteiro: %d Complemento: %d\n", num, 1000000 - num);
            fprintf(inte, "%d\n", num);
        } else {
            double num = string_to_double(m);
            printf("Real: %.6lf Complemento: %.6lf\n", num, 1000000.0 - num);
            fprintf(re, "%.6lf\n", num);
        }
    }

    fclose(ent);
    fclose(inte);
    fclose(re);

    return 0;
}

int contador(const char *cont) {
    int con = 0;
    for (int i = 0; i < 16; i++) {
        if (isdigit(cont[i]) || (i == 0 && (cont[i] == '+' || cont[i] == '-'))) {
            con++;
        }
    }
    return con;
}

double string_to_double(const char *str) {
    double result = 0.0;
    double factor = 0.1;
    int point_seen = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) || (i == 0 && (str[i] == '+' || str[i] == '-'))) {
            if (point_seen) {
                result += factor * (str[i] - '0');
                factor *= 0.1;
            } else {
                result = result * 10 + (str[i] - '0');
            }
        } else if (str[i] == '.') {
            point_seen = 1;
        }
    }

    if (str[0] == '-') {
        result = 1000000.0 - result;
    }

    return result;
}
