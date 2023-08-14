/*Implement the start and end points of segments of length 2 to cover all the sorted points in an array,
  Time complexity: O(n)*/
  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int** pointscoversorted(int*);

int main(){
    int points[10] = {1,2,3,5,6,10,12,13,14,16};
    int i;
    int** x;
    x = pointscoversorted(points);

    // Print the segments
    for (i = 0; x[i] != NULL; i++) {
        printf("Segment %d: [%d, %d]\n", i + 1, x[i][0], x[i][1]);
        free(x[i]);                                                 // Free memory for each segment
    }
    free(x);                                                        // Free memory for the array of segments.
    return 0;
}

int** pointscoversorted(int* points){
    int n=10, left = 0, seg_size =0, seg_count =0;                  // left = index of points
    int** segments = NULL;                                          // Empty list

    while(left<n){
        int* seg_points = (int*)malloc(2 * sizeof(int));            // Pointer to memory location of 2 ints

        // [l,r] = (Xleft, Xleft+2)
        seg_points[0] = points[left];
        seg_points[1] = points[left]+2;
        
        // Segments.append((l,r))
        segments = (int**)realloc(segments, sizeof(int*)*(++seg_size));
        segments[seg_count++] = seg_points;
        left++;

        // Check if other points is covered by the segment
        while(left<n && points[left]<=seg_points[1]){
            left++;
        }
    }
    return segments;
}

