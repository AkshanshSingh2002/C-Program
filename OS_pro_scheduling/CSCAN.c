#include <stdio.h>
#include <stdlib.h>

#define size 8
#define disk_size 200

void CSCAN(int arr[], int head) {
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int left_size = 0, right_size = 0;
    int seek_sequence[size * 2];

    // appending end values
    // which has to be visited
    // before reversing the direction
    left[left_size++] = 0;
    right[right_size++] = disk_size - 1;

    // tracks on the left of the
    // head will be serviced when
    // once the head comes back
    // to the beginning (left end).
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    // sorting left and right arrays
    for (int i = 0; i < left_size - 1; i++) {
        for (int j = 0; j < left_size - i - 1; j++) {
            if (left[j] > left[j + 1]) {
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

    // first service the requests
    // on the right side of the
    // head.
    for (int i = 0; i < right_size; i++) {
        cur_track = right[i];
        // appending current track to seek sequence
        seek_sequence[i] = cur_track;

        // calculate absolute distance
        distance = abs(cur_track - head);

        // increase the total count
        seek_count += distance;

        // accessed track is now new head
        head = cur_track;
    }

    // once reached the right end
    // jump to the beginning.
    head = 0;

    // adding seek count for head returning from 199 to 0
    seek_count += (disk_size - 1);

    // Now service the requests again
    // which are left.
    for (int i = 0; i < left_size; i++) {
        cur_track = left[i];

        // appending current track to seek sequence
        seek_sequence[right_size + i] = cur_track;

        // calculate absolute distance
        distance = abs(cur_track - head);

        // increase the total count
        seek_count += distance;

        // accessed track is now the new head
        head = cur_track;
    }

    printf("Total number of seek operations = %d\n", seek_count);

    printf("Seek Sequence is\n");

    for (int i = 0; i < right_size + left_size; i++) {
        printf("%d\n", seek_sequence[i]);
    }
}

// Driver code
int main() {
    // request array
    int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;

    printf("Initial position of head: %d\n", head);
    CSCAN(arr, head);

    return 0;
}
