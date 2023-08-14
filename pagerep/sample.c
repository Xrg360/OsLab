#include <stdio.h>

int main() {
    int pages[50], frames[20], page_count, frame_count, hits = 0, faults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &page_count);

    printf("Enter the reference string: ");
    for (int i = 0; i < page_count; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    for (int i = 0; i < frame_count; i++)
        frames[i] = -1;

    for (int i = 0; i < page_count; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == page) {
                found = 1;
                hits++;
                break;
            }
        }

        if (!found) {
            int min_freq = frames[0], min_index = 0;

            // Find the least frequently used page in the frames
            for (int j = 1; j < frame_count; j++) {
                if (frames[j] == -1) {
                    min_index = j;
                    break;
                }
                if (frames[j] < min_freq) {
                    min_freq = frames[j];
                    min_index = j;
                }
            }

            // Replace the least frequently used page
            frames[min_index] = page;
            faults++;
        }

        // Display the frames after each step
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("X ");
        }
        printf("\n");
    }

    printf("\nThe number of page faults is %d\n", faults);
    printf("The number of hits is %d\n", hits);
    printf("Hit ratio: %.2f\n", (float)hits / page_count);

    return 0;
}
