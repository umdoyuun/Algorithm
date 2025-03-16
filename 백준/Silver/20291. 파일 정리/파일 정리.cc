#include <cstdio>
#include <cstring>
#include <cstdlib>

struct HashEntry {
    char ext[101];
    int count;
    int next;
};

HashEntry entries[50001];
int hashTable[100003];
int entryCount = 0;

int hashString(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % 100003;
}

void addExtension(char* ext) {
    int hash = hashString(ext);
    
    int idx = hashTable[hash];
    while (idx != -1) {
        if (strcmp(entries[idx].ext, ext) == 0) {
            entries[idx].count++;
            return;
        }
        idx = entries[idx].next;
    }
    
    strcpy(entries[entryCount].ext, ext);
    entries[entryCount].count = 1;
    entries[entryCount].next = hashTable[hash];
    hashTable[hash] = entryCount++;
}

int compareEntries(const void* a, const void* b) {
    return strcmp(((HashEntry*)a)->ext, ((HashEntry*)b)->ext);
}

int main() {
    memset(hashTable, -1, sizeof(hashTable));
    
    char buffer[5000100];
    char outputBuffer[5000100];
    char *pR = buffer, *pW = outputBuffer;
    
    int readSize = fread(buffer, 1, 5000000, stdin);
    buffer[readSize] = 0;
    
    int N = 0;
    while (*pR >= '0' && *pR <= '9') {
        N = N * 10 + (*pR - '0');
        pR++;
    }
    pR++;
    
    for (int i = 0; i < N; i++) {
        char filename[101];
        int fileLen = 0;
        
        while (*pR && *pR != '\n' && fileLen < 100) {
            filename[fileLen++] = *pR++;
        }
        filename[fileLen] = '\0';
        
        while (*pR && *pR != '\n') pR++;
        if (*pR == '\n') pR++;
        
        int dotPos = -1;
        for (int j = 0; j < fileLen; j++) {
            if (filename[j] == '.') dotPos = j;
        }
        
        if (dotPos != -1) {
            addExtension(filename + dotPos + 1);
        }
    }
    
    qsort(entries, entryCount, sizeof(HashEntry), compareEntries);
    
    for (int i = 0; i < entryCount; i++) {
        char* ext = entries[i].ext;
        while (*ext) *pW++ = *ext++;
        
        *pW++ = ' ';
        
        int count = entries[i].count;
        
        char countStr[10];
        int countLen = 0;
        
        if (count == 0) {
            countStr[countLen++] = '0';
        } else {
            while (count > 0) {
                countStr[countLen++] = (count % 10) + '0';
                count /= 10;
            }
        }
        
        for (int j = countLen - 1; j >= 0; j--) {
            *pW++ = countStr[j];
        }
        
        *pW++ = '\n';
    }
    
    fwrite(outputBuffer, 1, pW - outputBuffer, stdout);
    
    return 0;
}