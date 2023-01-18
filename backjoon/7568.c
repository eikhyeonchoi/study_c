#include <stdio.h>
#include <stdlib.h>

// 덩치

typedef struct _Member {
	int w;
	int h;
	int r;
}Member;

int main() {
	int N;
	scanf("%d", &N);

	Member* list = (Member*)malloc(sizeof(Member) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &(list[i].w), &(list[i].h));
		list[i].r = 1;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (list[i].w < list[j].w && list[i].h < list[j].h) {
				list[i].r++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", list[i].r);
	}

	free(list);
	return 0;
}
