#include "../include/sort.hpp"

void InsertionSort(VerticeCor arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        VerticeCor key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j].cor > key.cor) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void Merge(VerticeCor arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    VerticeCor* leftArray = (VerticeCor*)malloc(n1 * sizeof(VerticeCor));
    VerticeCor* rightArray = (VerticeCor*)malloc(n2 * sizeof(VerticeCor));

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].cor <= rightArray[j].cor) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void InsertionMergeSort(VerticeCor arr[], int left, int right) {
    if (left < right) {
        if (right - left > 10) { 
            int mid = left + (right - left) / 2;
            InsertionMergeSort(arr, left, mid);
            InsertionMergeSort(arr, mid + 1, right);
            Merge(arr, left, mid, right);
        } else {
            InsertionSort(arr, left, right); 
        }
    }
}

void OrdenaInsertionMerge(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;

    int numVertices = g->V;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));

    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    InsertionMergeSort(verticesComCor, 0, numVertices - 1);
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");
    free(verticesComCor);
}

void OrdenaBoublleSort(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;
    int numVertices = g->V;
    typedef struct {
        int vertice;
        int cor;
    } VerticeCor;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));
    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = 0; j < numVertices - i - 1; j++) {
            if (verticesComCor[j].cor > verticesComCor[j + 1].cor) {
                VerticeCor temp = verticesComCor[j];
                verticesComCor[j] = verticesComCor[j + 1];
                verticesComCor[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");
    free(verticesComCor); 
}

void OrdenaSelectionSort(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;

    int numVertices = g->V;
    typedef struct {
        int vertice;
        int cor;
    } VerticeCor;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));
    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    for (int i = 0; i < numVertices - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < numVertices; j++) {
            if (verticesComCor[j].cor < verticesComCor[min_idx].cor ||
                (verticesComCor[j].cor == verticesComCor[min_idx].cor && verticesComCor[j].vertice < verticesComCor[min_idx].vertice)) {
                min_idx = j;
            }
        }
        VerticeCor temp = verticesComCor[min_idx];
        verticesComCor[min_idx] = verticesComCor[i];
        verticesComCor[i] = temp;
    }
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");
    free(verticesComCor); 
}

void OrdenaInsertionSort(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;

    int numVertices = g->V;
    typedef struct {
        int vertice;
        int cor;
    } VerticeCor;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));
    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    for (int i = 1; i < numVertices; i++) {
        VerticeCor key = verticesComCor[i];
        int j = i - 1;

        while (j >= 0 && verticesComCor[j].cor > key.cor) {
            verticesComCor[j + 1] = verticesComCor[j];
            j = j - 1;
        }
        verticesComCor[j + 1] = key;
    }
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");

    free(verticesComCor); 
}

void swap(VerticeCor* a, VerticeCor* b) {
    VerticeCor t = *a;
    *a = *b;
    *b = t;
}

int partition(VerticeCor arr[], int low, int high) {
    VerticeCor pivot = arr[high]; 
    int i = (low - 1);  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].cor < pivot.cor ||
           (arr[j].cor == pivot.cor && arr[j].vertice < pivot.vertice)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(VerticeCor arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void OrdenaQuickSort(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;
    int numVertices = g->V;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));
    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    quickSort(verticesComCor, 0, numVertices - 1);
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");
    free(verticesComCor); 
}

void merge(VerticeCor arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    VerticeCor L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].cor <= R[j].cor) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(VerticeCor arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void OrdenaMergeSort(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;
    int numVertices = g->V;
    typedef struct {
        int vertice;
        int cor;
    } VerticeCor;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));
    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    mergeSort(verticesComCor, 0, numVertices - 1);
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");
    free(verticesComCor); 
}

void heapify(VerticeCor arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && (arr[l].cor > arr[largest].cor ||
                 (arr[l].cor == arr[largest].cor && arr[l].vertice > arr[largest].vertice))) {
        largest = l;
    }
    if (r < n && (arr[r].cor > arr[largest].cor ||
                 (arr[r].cor == arr[largest].cor && arr[r].vertice > arr[largest].vertice))) {
        largest = r;
    }
    if (largest != i) {
        VerticeCor swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}

void heapSort(VerticeCor arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void OrdenaHeapSort(Grafo* g, CoresVertices* cores) {
    if (!g || !cores) return;
    int numVertices = g->V;
    typedef struct {
        int vertice;
        int cor;
    } VerticeCor;
    VerticeCor* verticesComCor = (VerticeCor*)malloc(numVertices * sizeof(VerticeCor));
    for (int i = 0; i < numVertices; ++i) {
        verticesComCor[i].vertice = i;
        verticesComCor[i].cor = ObtemCor(cores, i);
    }
    heapSort(verticesComCor, numVertices);
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", verticesComCor[i].vertice);
    }
    printf("\n");
    free(verticesComCor); 
}