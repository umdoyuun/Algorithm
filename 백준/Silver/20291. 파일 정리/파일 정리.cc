#include <cstdio>
#include <cstring>
#include <cstdlib>

// 단순 해시맵 구현 (문자열->정수)
struct HashEntry {
    char ext[101];
    int count;
    int next;  // 충돌 해결을 위한 링크드 리스트
};

// 최대 50,000개의 파일, 각 확장자 최대 100자
HashEntry entries[50001];
int hashTable[100003];  // 소수로 선택하여 충돌 감소
int entryCount = 0;

// 간단한 해시 함수
int hashString(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    return hash % 100003;
}

// 해시맵에 확장자 추가 또는 카운트 증가
void addExtension(char* ext) {
    int hash = hashString(ext);
    
    // 해시 테이블에서 체인 검색
    int idx = hashTable[hash];
    while (idx != -1) {
        if (strcmp(entries[idx].ext, ext) == 0) {
            entries[idx].count++;
            return;
        }
        idx = entries[idx].next;
    }
    
    // 새 항목 추가
    strcpy(entries[entryCount].ext, ext);
    entries[entryCount].count = 1;
    entries[entryCount].next = hashTable[hash];
    hashTable[hash] = entryCount++;
}

// 두 확장자 비교 함수 (qsort용)
int compareEntries(const void* a, const void* b) {
    return strcmp(((HashEntry*)a)->ext, ((HashEntry*)b)->ext);
}

int main() {
    // 초기화
    memset(hashTable, -1, sizeof(hashTable));
    
    // 입출력 버퍼
    char buffer[5000100];  // 최대 50,000개 파일, 각 100자 + 여유공간
    char outputBuffer[5000100];
    char *pR = buffer, *pW = outputBuffer;
    
    // 입력 읽기
    int readSize = fread(buffer, 1, 5000000, stdin);
    buffer[readSize] = 0;
    
    // N 읽기
    int N = 0;
    while (*pR >= '0' && *pR <= '9') {
        N = N * 10 + (*pR - '0');
        pR++;
    }
    pR++; // 개행 건너뛰기
    
    // 파일명 처리
    for (int i = 0; i < N; i++) {
        char filename[101];
        int fileLen = 0;
        
        // 파일명 읽기 (최대 100자)
        while (*pR && *pR != '\n' && fileLen < 100) {
            filename[fileLen++] = *pR++;
        }
        filename[fileLen] = '\0';
        
        // 줄의 끝까지 이동 (100자 초과한 경우 처리)
        while (*pR && *pR != '\n') pR++;
        if (*pR == '\n') pR++;
        
        // 마지막 '.' 위치 찾기
        int dotPos = -1;
        for (int j = 0; j < fileLen; j++) {
            if (filename[j] == '.') dotPos = j;
        }
        
        // 확장자가 있으면 해시맵에 추가
        if (dotPos != -1) {
            addExtension(filename + dotPos + 1);
        }
    }
    
    // 결과 정렬 (사전순)
    qsort(entries, entryCount, sizeof(HashEntry), compareEntries);
    
    // 결과 출력
    for (int i = 0; i < entryCount; i++) {
        // 확장자 쓰기
        char* ext = entries[i].ext;
        while (*ext) *pW++ = *ext++;
        
        // 공백 추가
        *pW++ = ' ';
        
        // 카운트 변환 및 쓰기
        int count = entries[i].count;
        
        // 숫자를 문자열로 변환 (역순)
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
        
        // 역순으로 복사
        for (int j = countLen - 1; j >= 0; j--) {
            *pW++ = countStr[j];
        }
        
        // 개행 추가
        *pW++ = '\n';
    }
    
    // 결과 출력
    fwrite(outputBuffer, 1, pW - outputBuffer, stdout);
    
    return 0;
}