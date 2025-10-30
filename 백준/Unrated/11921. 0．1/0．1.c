#include <stdio.h>
#define bsz 1 << 16
char RBUF[bsz];
int l = 0, r = 0;

char read() {
    if (l == r) { r = (int)fread(RBUF, 1, bsz, stdin); l = 0; }
    return RBUF[l++];
}

int readInt() {
    int ret = 0, tmp = read();
    while (tmp >= 48) { ret = ret * 10 + tmp - 48; tmp = read(); }
    return ret;
}

int main() {
    int n = readInt();
    int i = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += readInt();
    printf("%lld\n%lld\n", n, sum);
}