#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define safeFree(p) saferFree((void**)&(p))

void
allocateArray(int **arr, int size, int value) {
    *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        *(*arr + i) = value;
    }
}

void
saferFree(void **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}

int
add(int num1, int num2) {
    return num1 + num2;
}

int
subStract(int num1, int num2) {
    return num1 - num2;
}

typedef int (*fptr)(int, int);

fptr
whichOp(char opCode) {
    switch (opCode) {
        case '+':
            return add;
        case '-':
            return subStract;
        default:
            return NULL;
    }
}

int
evaluate(char opCode, int num1, int num2) {
    fptr operate = whichOp(opCode);
    return operate(num1, num2);
}

/**
 * buffer
 * currentPosition
 * character
 * sizeIncrement
 * @return buffer
 */
char *
getLine(void) {
    const size_t sizeIncrement = 10;
    char *buffer = (char *) malloc(sizeIncrement * sizeof(char));
    char *currentPosition = buffer;
    char character;
    size_t maxLineLength = sizeIncrement;
    size_t length = 0;

    while (1) {
        character = (char) fgetc(stdin);

        if (character == '\n') {
            break;
        }

        if (++length >= maxLineLength) {
            char *newBuffer = (char *) realloc(buffer, maxLineLength += sizeIncrement);
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }

        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}

/**
 * c Polymorphism
 * @return
 */
typedef void (*fptrSet)(void *, int);

typedef int (*fptrGet)(void *);

typedef void (*fptrShow)(void *);

typedef struct _vFunction {
    fptrSet SetX;
    fptrGet GetX;
    fptrSet SetY;
    fptrGet GetY;
    fptrShow Show;
} vFunctions;

typedef struct _shape {
    vFunctions functions;
    int x;
    int y;
} Shape;

void ShapeSetX(Shape *shape, int x) {
    shape->x = x;
}

void ShapeSetY(Shape *shape, int y) {
    shape->y = y;
}

int ShapeGetX(Shape *shape) {
    return shape->x;
}

int ShapeGetY(Shape *shape) {
    return shape->y;
}

void ShapeShow(Shape *shape) {
    printf("x: %d, y: %d\n", shape->x, shape->y);
}

Shape *getaShapeInstance(int x, int y) {
    Shape *shapeinstance = (Shape *) malloc(sizeof(Shape));
    shapeinstance->functions.GetX = (fptrGet) ShapeGetX;
    shapeinstance->functions.GetY = (fptrGet) ShapeGetY;
    shapeinstance->functions.SetX = (fptrSet) ShapeSetX;
    shapeinstance->functions.SetY = (fptrSet) ShapeSetY;
    shapeinstance->functions.Show = (fptrShow) ShapeShow;
    shapeinstance->x = x;
    shapeinstance->y = y;
    return shapeinstance;
}

int main() {
//    Shape *newShape = getaShapeInstance(100, 200);
//    newShape->functions.Show(newShape);
//    int * newArr = NULL;
//    allocateArray(&newArr, 5, 10);
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", newArr[i]);
//    }
//    printf("%d\n", evaluate('+', 1, 2));
//    printf("%d", evaluate('-', 1, 2));
//    int matrix[2][3] = {{1, 2, 3},
//                        {4, 5, 6}};
//    char *stringFromCommand = getLine();
//    printf("%s", stringFromCommand);
//    int arr[3] = {1,2,3};
//    printf("%lu", sizeof(arr)/sizeof(int));
//    int matrix[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
//    for(int i = 0; i < 2; i++){
//        for(int j = 0; j < 5; j++) {
//            printf("matrix[%d][%d], address: %p, value:%d\n", i, j, &matrix[i][j], matrix[i][j]);
//        }
//    }
//    printf("%lu", sizeof(matrix[0]));
//    int rows = 2;
//    int cols = 5;
//    int **matrix = (int **) malloc(rows * sizeof(int *));
//    for (int i = 0; i < rows; i++) {
//        *(matrix + i) = (int *) malloc(cols * sizeof(int));
//    }
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = 1;
//        }
//
//    }
//    int rr = 5;
//    int cc = 6;
//    int arr[rr][cc];
//    printf("%d", matrix[0][0]);
//    char command[6];
//    printf("Please input command:");
//    scanf("%s", command);
//    if(strcmp(command, "Quit!") != 0) {
//        printf("It's not quit!");
//    } else {
//        printf("The command is %s\n", command);
//    }
//    for(int i = 0; i < 6; i++) {
//        printf("%c", command[i]);
//    }

    float f = 0.25f;
    int *pc = (int *) &f;
    printf("%x", *pc);
//    for (int i = 0; i < 4; i++) {
//        printf("address %p, data %x\n", pc, (unsigned char) *pc++);
//    }

}
