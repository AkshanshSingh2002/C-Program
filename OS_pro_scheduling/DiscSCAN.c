#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 8
#define DISK_SIZE 200

void SCAN(int arr[], int  
head, char* direction) {
	int seek_count = 0;
	int distance, cur_track;
	int left[SIZE], right[SIZE];
	int left_size = 0, right_size = 0;
	int seek_sequence[SIZE * 2];
	int seek_sequence_size = 0;

	// appending end values
	// which has to be visited
	// before reversing the direction
	if (strcmp(direction, "left") == 0)
		left[left_size++] = 0;
	else if (strcmp(direction, "right") == 0)
		right[right_size++] = DISK_SIZE - 1;

	for (int i = 0; i < SIZE; i++) {
		if (arr[i] < head)
			left[left_size++] = arr[i];
		if (arr[i] > head)
			right[right_size++] = arr[i];
	}

	// Sorting left and right arrays
	for (int i = 0; i < left_size - 1; i++) {
		for (int j = 0; j < left_size - i - 1; j++) {
			if (left[j] < left[j + 1]) {
				int temp = left[j];
				left[j] = left[j + 1];
				left[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < right_size - 1; i++) {
		for (int j = 0; j < right_size - i - 1; j++) {
			if (right[j] > right[j + 1]) {
				int temp = right[j];
				right[j] = right[j + 1];
				right[j + 1] = temp;
			}
		}
	}

	// run the while loop two times.
	// one by one scanning right
	// and left of the head
	int run = 2;
	while (run--) {
		if (strcmp(direction, "left") == 0) {
			for (int i = left_size - 1; i >= 0; i--) {
				cur_track = left[i];
				// appending current track to seek sequence
				seek_sequence[seek_sequence_size++] = cur_track;

				// calculate absolute distance
				distance = abs(cur_track - head);

				// increase the total count
				seek_count += distance;

				// accessed track is now the new head
				head = cur_track;
			}
			strcpy(direction, "right");
		}
		else if (strcmp(direction, "right") == 0) {
			for (int i = 0; i < right_size; i++) {
				cur_track = right[i];
				// appending current track to seek sequence
				seek_sequence[seek_sequence_size++] = cur_track;

				// calculate absolute distance
				distance = abs(cur_track - head);

				// increase the total count
				seek_count += distance;

				// accessed track is now new head
				head = cur_track;
			}
			strcpy(direction, "left");
		}
	}

	printf("Total number of seek operations = %d\n", seek_count);
	printf("Seek Sequence is\n");

	for (int i = 0; i < seek_sequence_size; i++) {
		printf("%d\n", seek_sequence[i]);
	}
}

// Driver code
int main() {

	// request array
	int arr[SIZE] = { 176, 79, 34, 60, 92, 11, 41, 114 };
	int head = 50;
	char direction[] = "left";

	SCAN(arr, head, direction);

	return 0;
}
