#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int cmpDesc(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleets(int target, Car cars[], int n) {
    qsort(cars, n, sizeof(Car), cmpDesc);
    int fleets = 0;
    double lastTime = -1.0;
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }
    return fleets;
}

int main() {
    int n, target;
    printf("Enter target distance and number of cars: ");
    scanf("%d %d", &target, &n);

    Car *cars = (Car*)malloc(n * sizeof(Car));
    if (cars == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter positions of cars: ");
    for (int i = 0; i < n; i++) scanf("%d", &cars[i].pos);
    printf("Enter speeds of cars: ");
    for (int i = 0; i < n; i++) scanf("%d", &cars[i].speed);

    int result = carFleets(target, cars, n);
    printf("Number of car fleets: %d\n", result);

    free(cars);
    return 0;
}
