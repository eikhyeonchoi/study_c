#include <stdio.h>
#include <stdlib.h>

// 나이 순 정렬

typedef struct _People {
	int index;
	int age;
	char name[101];
}People;

int compare(const void* first, const void* second) {
	People* p1 = (People*)first;
	People* p2 = (People*)second;
	if (p1->age > p2->age) {
		return 1;
	}
	else if (p1->age < p2->age) {
		return -1;
	} else {
		if (p1->index > p2->index) {
			return 1;
		} else {
			return -1;
		}
	}

	return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	People* ps = (People*)malloc(sizeof(People) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &ps[i].age, ps[i].name);
		ps[i].index = i;
	}

	qsort(ps, n, sizeof(People), compare);
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", ps[i].age, ps[i].name);
	}

	free(ps);
	return 0;
}

// stdlib.h -> qsort
// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
// base: 배열 포인터
// ntimes: 배열의 갯수(사이즈가 아님)
// size: 배열 각 요소가 몇바이트인지
// compare: 함수 포인터
// 오름차순으로 정렬하고자 한다면 첫번째값이 두번째값보다 클 때 1 반환 같다면 0 작다면 -1;